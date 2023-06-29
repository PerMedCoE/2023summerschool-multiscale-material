#!/bin/bash
#SBATCH --job-name="cv141"
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=6
#SBATCH -t 00:08:00
#SBATCH -o %j.out
#SBATCH -e %j.err
##SBATCH --exclusive
##SBATCH --qos=debug


./COVID19 ./config/PhysiCell_settings_C141.xml > out_covid_c141.txt