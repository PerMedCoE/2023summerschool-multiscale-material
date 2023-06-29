#!/bin/bash
#SBATCH --job-name="het3Djm"
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=6
#SBATCH -t 00:05:00
#SBATCH -o %j.out
#SBATCH -e %j.err
##SBATCH --exclusive
#SBATCH --reservation=NotOnlyFLOPs23-day5
##SBATCH --qos=debug

module purge
module load intel jemalloc openmp gcc bison/3.7.6 flex/2.6.4

export LD_PRELOAD=`jemalloc-config --libdir`/libjemalloc.so.`jemalloc-config --revision` $binary

./heterogeneity_jm.exe >out_heterogeneity3D_jm.txt
