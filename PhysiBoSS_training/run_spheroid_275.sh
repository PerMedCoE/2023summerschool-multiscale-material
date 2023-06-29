#!/bin/bash
#SBATCH --job-name="sph275"
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=6
#SBATCH -t 00:05:00
#SBATCH -o %j.out
#SBATCH -e %j.err
##SBATCH --exclusive
##SBATCH --reservation=PerMedCoE22
#SBATCH --qos=debug

./spheroid_TNF_model.exe ./config/PhysiCell_settings_3D_drug_275_004.xml >out_spheroid_TNF_275.txt
