#!/bin/env bash

module purge
module load intel jemalloc openmp gcc bison/3.7.6 flex/2.6.4

export LD_PRELOAD=`jemalloc-config --libdir`/libjemalloc.so.`jemalloc-config --revision` $binary

./heterogeneity_jm.exe ./config/PhysiCell_settings_XX.xml >out_heterogeneityXX_jm.txt
./heterogeneity_jm.exe ./config/PhysiCell_settings_YY.xml >out_heterogeneityYY_jm.txt
./heterogeneity_jm.exe ./config/PhysiCell_settings_ZZ.xml >out_heterogeneityZZ_jm.txt
