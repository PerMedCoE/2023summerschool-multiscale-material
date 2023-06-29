#include "./boolean_model_interface.h"

/**
 *	\boolean network interface 
 *	\brief custom module for prostate example
 * 
 *	\details Modules needed for the prostate example. This custom module can be used to study the inhibition of prostate cell lines.
 *
 *	\date 19/06/2022
 *	\author Arnau Montagud and Annika Meert, BSC-CNS, with code previously developed by Gerard Pradas and Miguel Ponce de Leon, BSC-CNS
*/

void update_custom_variables( Cell* pCell )
{
	// first density is oxygen - shouldn't be changed: index from 1
	for (int i = 0; i < microenvironment.number_of_densities(); i++) 
	{
		std::string drug_name = microenvironment.density_names[i];
		if (drug_name != "oxygen") 
		{
			int drug_index = microenvironment.find_density_index(drug_name);
			int index_drug_conc = pCell->custom_data.find_variable_index(drug_name + "_concentration");
			int index_drug_node = pCell->custom_data.find_variable_index(drug_name + "_node");
			string drug_target = get_value(drug_targets, drug_name);
			pCell->custom_data.variables.at(index_drug_conc).value = pCell->nearest_density_vector()[drug_index];
			// pCell->custom_data.variables.at(index_drug_node).value = pCell->phenotype.intracellular.get_node_value("anti_" + drug_target);
		    pCell->custom_data.variables.at(index_drug_node).value = pCell->phenotype.intracellular->get_boolean_variable_value( "anti_" + drug_target );
		}
	}
}

void set_boolean_node (Cell* pCell, std::string drug_name, int drug_index, double threshold) 
{
	if (drug_index != -1)
		{
			std::string drug_target = get_value(drug_targets, drug_name);
			std::string node_name = "anti_" + drug_target;
			// get internalized substrate concentration
    		double drug_conc = pCell->nearest_density_vector()[drug_index];
			double cell_viability = get_cell_viability_for_drug_conc(drug_conc, parameters.strings("cell_line"), drug_name);
			double cell_inhibition = 1 - cell_viability;
			double random_num = (double) rand()/RAND_MAX;
			if (random_num <= cell_inhibition) 
			{
				pCell->phenotype.intracellular->set_boolean_variable_value(node_name, 1);
			}
			else 
			{
				pCell->phenotype.intracellular->set_boolean_variable_value(node_name, 0);
			}
			
		}
}

void set_input_nodes(Cell* pCell) 
{
	if (PhysiCell::parameters.ints("simulation_mode") == 0)
	{	
		// single inhibition - just one drug is present 

		std::string drug_name = microenvironment.density_names[1];
		int drug_index = microenvironment.find_density_index(drug_name);
		int drug_threshold = PhysiCell::parameters.doubles( "threshold_" + drug_name);

		if (pCell->type_name == drug_name + "_sensitive")
		{
			// cell is sensitive to the drug -> set boolean node
			set_boolean_node(pCell, drug_name, drug_index, drug_threshold);
		}
	}
	else if (PhysiCell::parameters.ints("simulation_mode") == 1)
	{	
		// double inhibition - two drugs are present - we have 4 cell strains 

		std::string drug1_name = microenvironment.density_names[1];
		int drug1_index = microenvironment.find_density_index(drug1_name);
		int drug1_threshold = PhysiCell::parameters.doubles( "threshold_" + drug1_name);

		std::string drug2_name = microenvironment.density_names[2];
		int drug2_index = microenvironment.find_density_index(drug2_name);
		int drug2_threshold = PhysiCell::parameters.doubles( "threshold_" + drug2_name);
	
		if (pCell->type_name == drug1_name + "_sensitive")
		{	
			// cell is sensitive to both drugs
			set_boolean_node(pCell, drug1_name, drug1_index, drug1_threshold);
			set_boolean_node(pCell, drug2_name, drug2_index, drug2_threshold);
		}
		else if (pCell->type_name == drug2_name + "_resistant")
		{
			// cell is only sensitive to the first drug
			set_boolean_node(pCell, drug1_name, drug1_index, drug1_threshold);
		}
		else if (pCell->type_name == drug2_name +  "_sensitive")
		{
			// cell is only sensitive to the second drug
			set_boolean_node(pCell, drug2_name, drug2_index, drug2_threshold);
		}

		// else: cell is sensitive to no drug --> no boolean node is set
	}
}

void from_nodes_to_cell(Cell* pCell, Phenotype& phenotype, double dt)
{
    // Getting the state of the boolean model readouts (Readout can be in the XML)
    bool apoptosis_val = pCell->phenotype.intracellular->get_boolean_variable_value( "Apoptosis" );
    bool EMT = pCell->phenotype.intracellular->get_boolean_variable_value( "EMT" );
    bool Proliferation =pCell->phenotype.intracellular->get_boolean_variable_value( "Proliferation" );
    bool Migration = pCell->phenotype.intracellular->get_boolean_variable_value( "Migration" );
    bool Invasion = pCell->phenotype.intracellular->get_boolean_variable_value( "Invasion" );

	// Prostate live model
	// map apoptosis, proliferation and invasion values to agent-based model

	if( pCell->phenotype.cycle.model().code == PhysiCell_constants::live_cells_cycle_model )
	{
		int start_phase_index = phenotype.cycle.model().find_phase_index( PhysiCell_constants::live );
		int end_phase_index = phenotype.cycle.model().find_phase_index( PhysiCell_constants::live );
		int apoptosis_index = phenotype.death.find_death_model_index( PhysiCell_constants::apoptosis_death_model );
		
		// Update Apoptosis 
		if( apoptosis_val )
		{
			// simple implementation, just lead immediately to death
			// pCell->start_death(apoptosis_index);

			// increase death rate whenever the node is ON 
			pCell->phenotype.death.rates[apoptosis_index] = PhysiCell::parameters.doubles("apoptosis_rate_multiplier") * pCell->phenotype.death.rates[apoptosis_index];
		}

		// Update Adhesion
		if( EMT )
		{
			// reduce cell-cell adhesion 
			// pCell->evolve_coef_sigmoid( 
			// 	pCell->boolean_network.get_node_value("EMT"), phenotype.mechanics.cell_cell_adhesion_strength, dt 
			// );
			//phenotype.mechanics.cell_cell_adhesion_strength = PhysiCell::parameters.doubles("homotypic_adhesion_max") * theta 
		}

		// Update pReference_live_phenotype for proliferation node 
		if ( Proliferation ) 
		{
			// multiplier implementation
			//pCell->parameters.pReference_live_phenotype->cycle.data.transition_rate(start_phase_index,end_phase_index) *= 2.5;
			//std::cout << "Rate up! " << std::endl;

			//switch implementation
			double high_transition_rate = PhysiCell::parameters.doubles("base_transition_rate") * PhysiCell::parameters.doubles("transition_rate_multiplier");
			pCell->parameters.pReference_live_phenotype->cycle.data.transition_rate(start_phase_index,end_phase_index) = high_transition_rate;
		}
		else 
		{
			//multiplier implementation 
			//pCell->parameters.pReference_live_phenotype->cycle.data.transition_rate(start_phase_index,end_phase_index) *= 0.4;
			//std::cout << "Rate down! " << std::endl;

			//switch implementation 
			pCell->parameters.pReference_live_phenotype->cycle.data.transition_rate(start_phase_index,end_phase_index) = PhysiCell::parameters.doubles("base_transition_rate");
		}

		// Update Migration
		if( Migration )
		{
			pCell->phenotype.motility.is_motile = true;
		 	pCell->phenotype.motility.migration_speed = PhysiCell::parameters.doubles("migration_speed");
			pCell->phenotype.motility.migration_bias = PhysiCell::parameters.doubles("migration_bias");
			pCell->phenotype.motility.persistence_time = PhysiCell::parameters.doubles("persistence");

			// pCell->evolve_coef(pCell->boolean_network.get_node_value("Migration"),	phenotype.motility.migration_speed, dt 
			// );
			// pCell->phenotype.motility.migration_speed = PhysiCell::parameters.doubles("max_motility_speed") * migration_coeff
		}
		else 
		{
			pCell->phenotype.motility.is_motile = false;
		}

		// Update Invasion
		if( Invasion )
		{
			// nothing happens for now 
		}
	}

	pCell->set_internal_uptake_constants(dt);
}


void boolean_model_interface_main (Cell* pCell, Phenotype& phenotype, double dt){

	if( phenotype.death.dead == true )
	{
		pCell->functions.update_phenotype = NULL;
		return;
	}

    // static int index_next_physiboss_run = pCell->custom_data.find_variable_index("next_physiboss_run");
	// if (PhysiCell_globals.current_time >= pCell->custom_data.variables.at(index_next_physiboss_run).value)
	// {
	// 	set_input_nodes(pCell);

	// 	pCell->boolean_network.run_maboss();
	// 	// Get noisy step size
	// 	double next_run_in = pCell->boolean_network.get_time_to_update();
	// 	pCell->custom_data.variables.at(index_next_physiboss_run).value = PhysiCell_globals.current_time + next_run_in;
	
	// 	update_custom_variables(pCell);

	// 	from_nodes_to_cell(pCell, phenotype, dt);
	// }

	if ( pCell->phenotype.intracellular->need_update() )
    {
        // First we update the Boolean Model inputs
        // update_boolean_model_inputs(pCell, phenotype, dt );
    	set_input_nodes(pCell);

        // Run maboss to update the boolean state of the cell
        pCell->phenotype.intracellular->update();

        // MaBoSSIntracellular* physiboss = static_cast<MaBoSSIntracellular*> (pCell->phenotype.intracellular);
		//next_physiboss_run
        // physiboss->next_physiboss_run += NormalRandom(0, 5);

		// update the cell fate based on the boolean outputs
        // update_cell_from_boolean_model(pCell, phenotype, dt);
        update_custom_variables(pCell);
		from_nodes_to_cell(pCell, phenotype, dt);

        // Get track of some boolean node values for debugging
        // update_monitor_variables(pCell);
    }

}