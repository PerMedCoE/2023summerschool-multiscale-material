/* 
   MaBoSS (Markov Boolean Stochastic Simulator)
   Copyright (C) 2011 Institut Curie, 26 rue d'Ulm, Paris, France
   
   MaBoSS is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   MaBoSS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA 
*/

/*
   Module:
     BooleanNetwork.cc

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
     updated October 2014
*/

#include "BooleanNetwork.h"
#include "BooleanGrammar.h"
#include "RunConfig.h"
#include <iostream>

Network* Network::instance;
SymbolTable* SymbolTable::instance;
extern FILE* CTBNDLin;
extern int CTBNDLparse();

std::vector<IStateGroup*>* IStateGroup::istate_group_list = new std::vector<IStateGroup*>();
const bool backward_istate = getenv("MABOSS_BACKWARD_ISTATE") != NULL;

Node::Node(const std::string& label, const std::string& description, NodeIndex index) : label(label), description(description), istate_set(false), is_internal(false), is_reference(false), referenceState(false), logicalInputExpr(NULL), rateUpExpr(NULL), rateDownExpr(NULL), index(index)
{
#if !defined(USE_BITSET) && !defined(USE_BOOST_BITSET)
  node_bit = NetworkState::nodeBit(index);
#endif
}

bool Node::isInputNode() const
{
  return getLogicalInputExpression() == NULL && getRateUpExpression() == NULL && getRateDownExpression() == NULL;
}

int Network::parse(const char* file)
{
  if (NULL != file) {
    CTBNDLin = fopen(file, "r");
    if (CTBNDLin == NULL) {
      throw BNException("network parsing: cannot open file:" + std::string(file) + " for reading");
    }
  }

  set_current_network(this);
  int r = CTBNDLparse();
  set_current_network(NULL);
  if (r) {
    return 1;
  }
  compile();
  return 0;
}

void SymbolTable::display(std::ostream& os, bool check) const
{
  MAP<std::string, Symbol*>::const_iterator begin = symb_map.begin();
  MAP<std::string, Symbol*>::const_iterator end = symb_map.end();

  while (begin != end) {
    double value = getSymbolValue((*begin).second, check);
    os << (*begin).first << " = " << value << ";\n";
    ++begin;
  }
}

void Network::updateRandomGenerator(RunConfig* runconfig)
{
  delete random_generator;
  random_generator = runconfig->getRandomGeneratorFactory()->generateRandomGenerator(runconfig->getSeedPseudoRandom());
}

void Network::compile()
{
  MAP<std::string, Node*>::iterator begin = node_map.begin();
  MAP<std::string, Node*>::iterator end = node_map.end();

#if 0
  // checks for cycles
  // actually, not really pertinent...
  while (begin != end) {
    Node* node = (*begin).second;
    if (!node->isInputNode()) {
      if (node->getLogicalInputExpr()->getRateUpExpression()->hasCycle(node)) {
	//std::cerr << "cycle detected for node " << node->getLabel() << '\n';
      }
    }
    ++begin;
  }
#endif

  // looks for input and non input nodes
  begin = node_map.begin();
  while (begin != end) {
    Node* node = (*begin).second;
    if (!NodeDecl::isNodeDefined(node->getLabel())) {
      throw BNException("node " + node->getLabel() + " used but not defined"); 
    }
    ++begin;
  }

  begin = node_map.begin();
  nodes.resize(node_map.size());
  while (begin != end) {
    Node* node = (*begin).second;
    if (node->isInputNode()) {
      input_nodes.push_back(node);
    } else {
      non_input_nodes.push_back(node);
    }
    //nodes.push_back(node);
    nodes[node->getIndex()] = node;
    ++begin;
  }
}

Node* Network::defineNode(const std::string& label, const std::string& description)
{
  if (NodeDecl::isNodeDefined(label)) {
    throw BNException("node " + label + " already defined");
  }
  Node* node = new Node(label, description, last_index++); // node factory
  NodeDecl::defineNode(label);
  node_map[label] = node;
  return node;
}

Node* Network::getNode(const std::string& label)
{
  if (node_map.find(label) == node_map.end()) {
    throw BNException("network: node " + label + " not defined");
  }
  return node_map[label];
}

void Network::initStates(NetworkState& initial_state)
{
  if (backward_istate) {
    std::vector<Node*>::const_iterator begin = nodes.begin();
    std::vector<Node*>::const_iterator end = nodes.end();
  
    while (begin != end) {
      Node* node = *begin;
      initial_state.setNodeState(node, node->getIState(this));
      ++begin;
    }
  } else {
    IStateGroup::initStates(this, initial_state);
  }
}

void Network::display(std::ostream& os) const
{
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  for (unsigned int nn = 0; begin != end; ++nn) {
    Node* node = *begin;
    if (0 != nn) {
      os << '\n';
    }
    node->display(os);
    ++begin;
  }
}

double Node::getRateUp(const NetworkState& network_state) const
{
  if (getRateUpExpression() == NULL) {
    if (NULL != getLogicalInputExpression()) {
      double d = getLogicalInputExpression()->eval(this, network_state);
      return (0.0 != d) ? 1.0 : 0.0;
    }
    return 0.0;
  }
  return getRateUpExpression()->eval(this, network_state);
}

double Node::getRateDown(const NetworkState& network_state) const
{
  if (getRateDownExpression() == NULL) {
    if (NULL != getLogicalInputExpression()) {
      double d = getLogicalInputExpression()->eval(this, network_state);
      return (0.0 != d) ? 0.0 : 1.0;
    }
    return 0.0;
  }
  return getRateDownExpression()->eval(this, network_state);
}

NodeState Node::getNodeState(const NetworkState& network_state) const
{
  return network_state.getNodeState(this);
}

void Node::setNodeState(NetworkState& network_state, NodeState state)
{
  network_state.setNodeState(this, state);
}

bool Node::computeNodeState(NetworkState& network_state, NodeState& node_state) const
{
  return network_state.computeNodeState(this, node_state);
}

NodeState Node::getIState(const Network* network) const
{
  if (!istate_set) {
#if 1
    double rand = network->getRandomGenerator()->generate();
    istate = rand > 0.5; // >= 0.5 ?
#else
    istate = (network->getRandomGenerator()->generateUInt32() % 2) == 0;
#endif
  }
  return istate;
}

void Node::display(std::ostream& os) const
{
  os << "node " << label << " {\n";
  if (description.length() > 0) {
    os << "  description = \"" << description << "\";\n";
  }
  if (NULL != logicalInputExpr) {
    os << "  logic = ";
    logicalInputExpr->display(os);
    os << ";\n";
  }
  if (NULL != rateUpExpr) {
    os << "  rate_up = ";
    rateUpExpr->display(os);
    os << ";\n";
  }
  if (NULL != rateDownExpr) {
    os << "  rate_down = ";
    rateDownExpr->display(os);
    os << ";\n";
  }

  if (attr_expr_map.size() || attr_str_map.size()) {
    os << "\n  // extra attributes\n";
    MAP<std::string, const Expression*>::const_iterator attr_expr_begin = attr_expr_map.begin();
    MAP<std::string, const Expression*>::const_iterator attr_expr_end = attr_expr_map.end();
    while (attr_expr_begin != attr_expr_end) {
      os << "  " << (*attr_expr_begin).first << " = ";
      (*attr_expr_begin).second->display(os);
      os << ";\n";
      ++attr_expr_begin;
    }

    MAP<std::string, std::string>::const_iterator attr_str_begin = attr_str_map.begin();
    MAP<std::string, std::string>::const_iterator attr_str_end = attr_str_map.end();
    while (attr_str_begin != attr_str_end) {
      os << "  " << (*attr_str_begin).first << " = \"" << (*attr_str_begin).second << "\";\n";
      ++attr_str_begin;
    }
  }
  os << "}\n";
}

bool NetworkState::computeNodeState(const Node* node, NodeState& node_state)
{
  const Expression* expr = node->getLogicalInputExpression();
  if (NULL != expr) {
    double d = expr->eval(node, *this);
    node_state = d != 0.;
    setNodeState(node, node_state);
    return true;
  }
  return false;
}

#define HAMMING_METHOD2

unsigned int NetworkState::hamming(Network* network, NetworkState_Impl state2) const
{
  unsigned int hd = 0;
#ifdef HAMMING_METHOD1
  // faster way
  unsigned long s = (state ^ (state2 & state));
  unsigned int node_count = network->getNodes().size();
  for (unsigned int nn = 0; nn < node_count; ++nn) {
    if ((1ULL << nn) & s) {
      hd++;
    }
  }
  return hd;
#endif

#ifdef HAMMING_METHOD2
  NetworkState network_state2(state2);
  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  while (begin != end) {
    Node* node = *begin;
    if (node->isReference()) {
      NodeState node_state1 = getNodeState(node);
      NodeState node_state2 = network_state2.getNodeState(node);
      hd += 1 - (node_state1 == node_state2);
    }
    ++begin;
  }

  return hd;
#endif
}

void Network::displayHeader(std::ostream& os) const
{
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  for (int nn = 0; begin != end; ++nn) {
    Node* node = *begin;
    os << (nn > 0 ? "\t" : "") << node->getLabel();
    ++begin;
  }
  os << '\n';
}


void NetworkState::display(std::ostream& os, Network* network) const
{
  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  for (int nn = 0; begin != end; ++nn) {
    Node* node = *begin;
    os << (nn > 0 ? "\t" : "") << getNodeState(node);
    ++begin;
  }
  os << '\n';
}

void NetworkState::displayOneLine(std::ostream& os, Network* network, const std::string& sep) const
{
#if defined(USE_BITSET) || defined(USE_BOOST_BITSET)
  if (state.none()) {
    os << "<nil>";
    return;
  }
#else
  if (!state) {
    os << "<nil>";
    return;
  }
#endif

  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator begin = nodes.begin();
  std::vector<Node*>::const_iterator end = nodes.end();

  bool displayed = false;
  while (begin != end) {
    Node* node = *begin;
    if (getNodeState(node)) {
      if (displayed) {
	os << sep;
      } else {
	displayed = true;
      }
      os << node->getLabel();
    }
    ++begin;
  }
}

std::ostream& operator<<(std::ostream& os, const BNException& e)
{
  os << "BooleanNetwork exception: " << e.getMessage() << '\n';
  return os;
}

void IStateGroup::checkAndComplete(Network* network)
{
  std::map<std::string, bool> node_label_map;
  std::vector<IStateGroup*>::iterator begin = istate_group_list->begin();
  std::vector<IStateGroup*>::iterator end = istate_group_list->end();
  while (begin != end) {
    IStateGroup* istate_group = *begin;
    std::vector<const Node*>* nodes = istate_group->getNodes();

    std::vector<const Node*>::iterator bb = nodes->begin();
    std::vector<const Node*>::iterator ee = nodes->end();
    while (bb != ee) {
      const Node* node = *bb;
      if (node_label_map.find(node->getLabel()) != node_label_map.end()) {
	throw BNException("duplicate node istate declaration: " + node->getLabel());
      }
      node_label_map[node->getLabel()] = true;
      ++bb;
    }

    ++begin;
  }

  const std::vector<Node*>& nodes = network->getNodes();
  std::vector<Node*>::const_iterator bb = nodes.begin();
  std::vector<Node*>::const_iterator ee = nodes.end();
  while (bb != ee) {
    const Node* node = *bb;
    if (node_label_map.find(node->getLabel()) == node_label_map.end()) {
      new IStateGroup(node);
    }
    ++bb;
  }

  // now complete missing nodes
}

void IStateGroup::initStates(Network* network, NetworkState& initial_state)
{
  std::vector<IStateGroup*>::iterator istate_group_iter = istate_group_list->begin();
  std::vector<IStateGroup*>::iterator istate_group_end = istate_group_list->end();
  while (istate_group_iter != istate_group_end) {
    IStateGroup* istate_group = *istate_group_iter;
    std::vector<const Node*>* nodes = istate_group->getNodes();
    //size_t node_size = nodes->size();
    std::vector<ProbaIState*>* proba_istates = istate_group->getProbaIStates();

    if (proba_istates->size() == 1) {
      ProbaIState* proba_istate = (*proba_istates)[0];
      //double proba_value = proba_istate->getProbaValue();
      std::vector<double>* state_value_list = proba_istate->getStateValueList();
      std::vector<double>::const_iterator state_value_iter = state_value_list->begin();
      std::vector<double>::const_iterator state_value_end = state_value_list->end();
      size_t nn = 0;
      while (state_value_iter != state_value_end) {
	const Node* node = (*nodes)[nn++];
	initial_state.setNodeState(node, (*state_value_iter) != 0. ? true : false);
	++state_value_iter;
      }
    } else {
      double rand = network->getRandomGenerator()->generate();
      assert(rand >= 0. && rand <= 1.);
      std::vector<ProbaIState*>::iterator proba_istate_iter = proba_istates->begin();
      std::vector<ProbaIState*>::iterator proba_istate_end = proba_istates->end();
      size_t proba_istate_size = proba_istates->size();
      double proba_sum = 0;
      for (size_t jj = 0; proba_istate_iter != proba_istate_end; ++jj) {
	ProbaIState* proba_istate = *proba_istate_iter;
	proba_sum += proba_istate->getProbaValue();
	//std::cerr << "rand: " << rand << " " << proba_sum << '\n';
	if (rand < proba_sum || jj == proba_istate_size - 1) {
	  std::vector<double>* state_value_list = proba_istate->getStateValueList();
	  std::vector<double>::iterator state_value_iter = state_value_list->begin();
	  std::vector<double>::iterator state_value_end = state_value_list->end();
	  size_t nn = 0;
	  //std::cerr << "state #" << jj << " choosen\n";
	  while (state_value_iter != state_value_end) {
	    const Node* node = (*nodes)[nn++];
	    initial_state.setNodeState(node, (*state_value_iter) != 0. ? true : false);
	    ++state_value_iter;
	  }
	  break;
	}
	++proba_istate_iter;
      }
    }
    ++istate_group_iter;
  }
}

void IStateGroup::display(Network* network, std::ostream& os)
{
  std::vector<IStateGroup*>::iterator begin = istate_group_list->begin();
  std::vector<IStateGroup*>::iterator end = istate_group_list->end();
  while (begin != end) {
    IStateGroup* istate_group = *begin;
    std::vector<const Node*>* nodes = istate_group->getNodes();
    std::vector<ProbaIState*>* proba_istates = istate_group->getProbaIStates();

    std::vector<const Node*>::iterator bb = nodes->begin();
    std::vector<const Node*>::iterator ee = nodes->end();
    if (nodes->size() == 1 && proba_istates->size() == 1) {
      std::vector<double>* state_value_list = (*proba_istates)[0]->getStateValueList();
      os << (*bb)->getLabel() << ".istate = " << ((*state_value_list)[0] != 0. ? "1" : "0") << ";\n";
      ++begin;
      continue;
    }
    os << '[';
    for (unsigned int nn = 0; bb != ee; ++nn) {
      const Node* node = *bb;
      os << (nn > 0 ? ", " : "") << node->getLabel();
      ++bb;
    }
    os << "].istate = ";

    std::vector<ProbaIState*>::iterator proba_istate_iter = proba_istates->begin();
    std::vector<ProbaIState*>::iterator proba_istate_end = proba_istates->end();
    for (size_t jj = 0; proba_istate_iter != proba_istate_end; ++jj) {
      ProbaIState* proba_istate = *proba_istate_iter;
      os << (jj > 0 ? ", " : "") << proba_istate->getProbaValue() << " [";
      std::vector<double>* state_value_list = proba_istate->getStateValueList();
      std::vector<double>::iterator state_value_iter = state_value_list->begin();
      std::vector<double>::iterator state_value_end = state_value_list->end();
      for (size_t ii = 0; state_value_iter != state_value_end; ++ii) {
	os << (ii > 0 ? ", " : "") << *state_value_iter;
	++state_value_iter;
      }
      os << "]";
      ++proba_istate_iter;
    }

    os << ";";
    /*
    if (istate_group->isRandom()) {
      os << " // <=> " << (*nodes->begin())->getLabel() << ".istate = -1";
    }
    */
    os << '\n';
    ++begin;
  }
}

Node::~Node()
{
  delete logicalInputExpr;
  delete rateUpExpr;
  delete rateDownExpr;

  MAP<std::string, const Expression*>::const_iterator attr_expr_begin = attr_expr_map.begin();
  MAP<std::string, const Expression*>::const_iterator attr_expr_end = attr_expr_map.end();
  while (attr_expr_begin != attr_expr_end) {
    //delete (*attr_expr_begin).second;
  }
}

Network::Network(const Network& network)
{
  random_generator = NULL;
  *this = network;
}

Network& Network::operator=(const Network& network)
{
  delete random_generator;
  random_generator = NULL;
  node_map = network.node_map;
  last_index = network.last_index;
  input_nodes = network.input_nodes;
  non_input_nodes = network.non_input_nodes;
  nodes = network.nodes;
  return *this;
}

Network::~Network()
{
  delete random_generator;
  /*
  for (MAP<std::string, Node*>::iterator iter = node_map.begin(); iter != node_map.end(); ++iter) {
    delete (*iter).second;
  }
  */
}

void SymbolTable::reset()
{
  symb_map.clear();
  symb_value.clear();
  symb_def.clear();
  symb_dont_set.clear();
  last_symb_idx = 0;
}

