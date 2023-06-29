/*
###############################################################################
# If you use PhysiCell in your project, please cite PhysiCell and the version #
# number, such as below:                                                      #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1].    #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# See VERSION.txt or call get_PhysiCell_version() to get the current version  #
#     x.y.z. Call display_citations() to get detailed information on all cite-#
#     able software used in your PhysiCell application.                       #
#                                                                             #
# Because PhysiCell extensively uses BioFVM, we suggest you also cite BioFVM  #
#     as below:                                                               #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1],    #
# with BioFVM [2] to solve the transport equations.                           #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# [2] A Ghaffarizadeh, SH Friedman, and P Macklin, BioFVM: an efficient para- #
#     llelized diffusive transport solver for 3-D biological simulations,     #
#     Bioinformatics 32(8): 1256-8, 2016. DOI: 10.1093/bioinformatics/btv730  #
#                                                                             #
###############################################################################
#                                                                             #
# BSD 3-Clause License (see https://opensource.org/licenses/BSD-3-Clause)     #
#                                                                             #
# Copyright (c) 2015-2018, Paul Macklin and the PhysiCell Project             #
# All rights reserved.                                                        #
#                                                                             #
# Redistribution and use in source and binary forms, with or without          #
# modification, are permitted provided that the following conditions are met: #
#                                                                             #
# 1. Redistributions of source code must retain the above copyright notice,   #
# this list of conditions and the following disclaimer.                       #
#                                                                             #
# 2. Redistributions in binary form must reproduce the above copyright        #
# notice, this list of conditions and the following disclaimer in the         #
# documentation and/or other materials provided with the distribution.        #
#                                                                             #
# 3. Neither the name of the copyright holder nor the names of its            #
# contributors may be used to endorse or promote products derived from this   #
# software without specific prior written permission.                         #
#                                                                             #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" #
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  #
# POSSIBILITY OF SUCH DAMAGE.                                                 #
#                                                                             #
###############################################################################
*/

#include "./custom.h"

// declare cell definitions here
void create_cell_types(void)
{

	SeedRandom(parameters.ints("random_seed"));

	initialize_default_cell_definition();

	/*  This parses the cell definitions in the XML config file.  */

	initialize_cell_definitions_from_pugixml();

	if (parameters.bools("update_pc_parameters_O2_based"))
	{ cell_defaults.functions.update_phenotype = tumor_cell_phenotype_with_signaling; }
	else
	{ cell_defaults.functions.update_phenotype = tnf_bm_interface_main; }

	/*  This initializes the the TNF receptor model	*/
	tnf_receptor_model_setup();
	tnf_boolean_model_interface_setup();
	submodel_registry.display(std::cout);

	// Needs to initialize one of the receptor state to the total receptor value
	cell_defaults.custom_data["unbound_external_TNFR"] = cell_defaults.custom_data["TNFR_receptors_per_cell"];
	cell_defaults.custom_data["bound_external_TNFR"] = 0;
	cell_defaults.custom_data["bound_internal_TNFR"] = 0;

	build_cell_definitions_maps();
	display_cell_definitions(std::cout);

	return;
}

void setup_microenvironment(void)
{

	initialize_microenvironment();

	return;
}

void setup_tissue(void)
{

	/*
	double cell_radius = cell_defaults.phenotype.geometry.radius; 
	double cell_spacing = 0.95 * 2.0 * cell_radius; 
	double tumor_radius = parameters.doubles("tumor_radius");
	std::vector<std::vector<double>> positions = create_cell_disc_positions(cell_radius,tumor_radius); 
	*/

	double cell_radius = cell_defaults.phenotype.geometry.radius; 
	double tumor_radius =  parameters.doubles("tumor_radius");

	std::vector<std::vector<double>> positions;
	if (default_microenvironment_options.simulate_2D == true)
		positions = create_cell_disc_positions(cell_radius,tumor_radius); 
	else
		positions = create_cell_sphere_positions(cell_radius,tumor_radius);

	// std::string csv_fname = parameters.strings("init_cells_filename");
	// std::vector<std::vector<double>> positions = read_cells_positions(csv_fname, '\t', true);

	Cell* pCell = NULL; 
	for (int i = 0; i < positions.size(); i++)
	{
		pCell = create_cell(get_cell_definition("default"));
		pCell->assign_position(positions[i]);

		// next_physiboss_run
	        MaBoSSIntracellular* physiboss = static_cast<MaBoSSIntracellular*> (pCell->phenotype.intracellular);
        	physiboss->next_physiboss_run += NormalRandom(0, 5);

		static int idx_bind_rate = pCell->custom_data.find_variable_index( "TNFR_binding_rate" );
		static float mean_bind_rate = pCell->custom_data[idx_bind_rate];
		static float std_bind_rate = parameters.doubles("TNFR_binding_rate_std");
		static float min_bind_rate = parameters.doubles("TNFR_binding_rate_min");
		static float max_bind_rate = parameters.doubles("TNFR_binding_rate_max");
		
		pCell->custom_data[idx_bind_rate] = NormalRandom(mean_bind_rate, std_bind_rate);
		if (pCell->custom_data[idx_bind_rate] < min_bind_rate)
		{ pCell->custom_data[idx_bind_rate] = min_bind_rate; }
		if (pCell->custom_data[idx_bind_rate] > max_bind_rate)
		{ pCell->custom_data[idx_bind_rate] = max_bind_rate; }

		static int idx_endo_rate = pCell->custom_data.find_variable_index( "TNFR_endocytosis_rate" );
		static float mean_endo_rate = pCell->custom_data[idx_endo_rate];
		static float std_endo_rate = parameters.doubles("TNFR_endocytosis_rate_std");
		static float min_endo_rate = parameters.doubles("TNFR_endocytosis_rate_min");
		static float max_endo_rate = parameters.doubles("TNFR_endocytosis_rate_max");
		
		pCell->custom_data[idx_endo_rate] = NormalRandom(mean_endo_rate, std_endo_rate);
		if (pCell->custom_data[idx_endo_rate] < min_endo_rate)
		{ pCell->custom_data[idx_endo_rate] = min_endo_rate; }
		if (pCell->custom_data[idx_endo_rate] > max_endo_rate)
		{ pCell->custom_data[idx_endo_rate] = max_endo_rate; }

		static int idx_recycle_rate = pCell->custom_data.find_variable_index( "TNFR_recycling_rate" ); 
		static float mean_recycle_rate = pCell->custom_data[idx_recycle_rate];
		static float std_recycle_rate = parameters.doubles("TNFR_recycling_rate_std");
		static float min_recycle_rate = parameters.doubles("TNFR_recycling_rate_min");
		static float max_recycle_rate = parameters.doubles("TNFR_recycling_rate_max");

		pCell->custom_data[idx_recycle_rate] = NormalRandom(mean_recycle_rate, std_recycle_rate);
		if (pCell->custom_data[idx_recycle_rate] < min_recycle_rate)
		{ pCell->custom_data[idx_recycle_rate] = min_recycle_rate; }
		if (pCell->custom_data[idx_recycle_rate] > max_recycle_rate)
		{ pCell->custom_data[idx_recycle_rate] = max_recycle_rate; }
		
		update_monitor_variables(pCell);
	}

	return;
}

// custom cell phenotype function to run PhysiBoSS when is needed
void tumor_cell_phenotype_with_signaling(Cell *pCell, Phenotype &phenotype, double dt)
{
	if (phenotype.death.dead == true)
	{
		pCell->functions.update_phenotype = NULL;
		return;
	}

	update_cell_and_death_parameters_O2_based(pCell, phenotype, dt);
	tnf_bm_interface_main(pCell, phenotype, dt);

}


std::vector<std::vector<double>>  read_cells_positions(std::string filename, char delimiter, bool header)
{
	// File pointer
	std::fstream fin;
	std::vector<std::vector<double>> positions;

	// Open an existing file
	fin.open(filename, std::ios::in);

	// Read the Data from the file
	// as String Vector
	std::vector<std::string> row;
	std::string line, word;

	if (header)
	{ getline(fin, line); }

	do
	{
		row.clear();

		// read an entire row and
		// store it in a string variable 'line'
		getline(fin, line);

		// used for breaking words
		std::stringstream s(line);

		while (getline(s, word, delimiter))
		{ 
			row.push_back(word); 
		}

		std::vector<double> tempPoint(3,0.0);
		tempPoint[0]= std::stof(row[0]);
		tempPoint[1]= std::stof(row[1]);
		tempPoint[2]= std::stof(row[2]);

		positions.push_back(tempPoint);
	} while (!fin.eof());

	return positions;
}



std::vector<std::vector<double>> create_cell_sphere_positions(double cell_radius, double sphere_radius)
{
	std::vector<std::vector<double>> cells;
	int xc=0,yc=0,zc=0;
	double x_spacing= cell_radius*sqrt(3);
	double y_spacing= cell_radius*2;
	double z_spacing= cell_radius*sqrt(3);
	
	std::vector<double> tempPoint(3,0.0);
	// std::vector<double> cylinder_center(3,0.0);
	
	for(double z=-sphere_radius;z<sphere_radius;z+=z_spacing, zc++)
	{
		for(double x=-sphere_radius;x<sphere_radius;x+=x_spacing, xc++)
		{
			for(double y=-sphere_radius;y<sphere_radius;y+=y_spacing, yc++)
			{
				tempPoint[0]=x + (zc%2) * 0.5 * cell_radius;
				tempPoint[1]=y + (xc%2) * cell_radius;
				tempPoint[2]=z;
				
				if(sqrt(norm_squared(tempPoint))< sphere_radius)
				{ cells.push_back(tempPoint); }
			}
			
		}
	}
	return cells;
	
}


std::vector<std::vector<double>> create_cell_disc_positions(double cell_radius, double disc_radius)
{	 
	double cell_spacing = 0.95 * 2.0 * cell_radius; 
	
	double x = 0.0; 
	double y = 0.0; 
	double x_outer = 0.0;

	std::vector<std::vector<double>> positions;
	std::vector<double> tempPoint(3,0.0);
	
	int n = 0; 
	while( y < disc_radius )
	{
		x = 0.0; 
		if( n % 2 == 1 )
		{ x = 0.5 * cell_spacing; }
		x_outer = sqrt( disc_radius*disc_radius - y*y ); 
		
		while( x < x_outer )
		{
			tempPoint[0]= x; tempPoint[1]= y;	tempPoint[2]= 0.0;
			positions.push_back(tempPoint);			
			if( fabs( y ) > 0.01 )
			{
				tempPoint[0]= x; tempPoint[1]= -y;	tempPoint[2]= 0.0;
				positions.push_back(tempPoint);
			}
			if( fabs( x ) > 0.01 )
			{ 
				tempPoint[0]= -x; tempPoint[1]= y;	tempPoint[2]= 0.0;
				positions.push_back(tempPoint);
				if( fabs( y ) > 0.01 )
				{
					tempPoint[0]= -x; tempPoint[1]= -y;	tempPoint[2]= 0.0;
					positions.push_back(tempPoint);
				}
			}
			x += cell_spacing; 
		}		
		y += cell_spacing * sqrt(3.0)/2.0; 
		n++; 
	}
	return positions;
}




void inject_density_sphere(int density_index, double concentration, double membrane_lenght)
{
	// Inject given concentration on the extremities only
	#pragma omp parallel for
	for (int n = 0; n < microenvironment.number_of_voxels(); n++)
	{
		auto current_voxel = microenvironment.voxels(n);
		std::vector<double> cent = {current_voxel.center[0], current_voxel.center[1], current_voxel.center[2]};

		if ((membrane_lenght - norm(cent)) <= 0)
			microenvironment.density_vector(n)[density_index] = concentration;
	}
}


void remove_density(int density_index)
{
	for (int n = 0; n < microenvironment.number_of_voxels(); n++)
		microenvironment.density_vector(n)[density_index] = 0;
}


std::vector<std::string> my_coloring_function(Cell *pCell)
{
	// start with live coloring
	std::vector<std::string> output = false_cell_coloring_live_dead(pCell);

	// dead cells
	if (pCell->phenotype.death.dead == false)
	{
		static int nR_EB = pCell->custom_data.find_variable_index("bound external TNFR");
		float activation_threshold = pCell->custom_data.find_variable_index("TNFR activation threshold");

		int bounded_tnf = (int)round((pCell->custom_data[nR_EB] / activation_threshold) * 255.0);
		if (bounded_tnf > 0)
		{
			char szTempString[128];
			sprintf(szTempString, "rgb(%u,%u,%u)", bounded_tnf, bounded_tnf, 255 - bounded_tnf);
			output[0].assign("black");
			output[1].assign(szTempString);
			output[2].assign("black");
			output[3].assign(szTempString);
		}
	}

	return output;
}



double total_live_cell_count()
{
        double out = 0.0;

        for( int i=0; i < (*all_cells).size() ; i++ )
        {
                if( (*all_cells)[i]->phenotype.death.dead == false && (*all_cells)[i]->type == 0 )
                { out += 1.0; }
        }

        return out;
}

double total_dead_cell_count()
{
        double out = 0.0;

        for( int i=0; i < (*all_cells).size() ; i++ )
        {
                if( (*all_cells)[i]->phenotype.death.dead == true && (*all_cells)[i]->phenotype.death.current_death_model_index == 0 )
                { out += 1.0; }
        }

        return out;
}

double total_necrosis_cell_count()
{
        double out = 0.0;

        for( int i=0; i < (*all_cells).size() ; i++ )
        {
                if( (*all_cells)[i]->phenotype.death.dead == true && (*all_cells)[i]->phenotype.death.current_death_model_index == 1 )
                { out += 1.0; }
        }

        return out;
}

