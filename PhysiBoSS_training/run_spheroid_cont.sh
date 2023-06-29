#!/bin/bash
#SBATCH --job-name="sphcont"
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=6
#SBATCH -t 00:07:00
#SBATCH -o %j.out
#SBATCH -e %j.err
##SBATCH --exclusive
#SBATCH --reservation=PerMedCoE22

./spheroid_TNF_model.exe ./config/PhysiCell_settings_3D_drug_cont_004.xml >out_spheroid_TNF_cont.txt
