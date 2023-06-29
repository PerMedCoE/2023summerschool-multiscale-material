#!/bin/sh

ulimit -n 5000

model=PC_20191203_rand


listout="Proliferation,Angiogenesis,Invasion,Metastasis,Migration,Glycolysis,Hypermethylation,DNA_Repair,Quiescence,Apoptosis"

sim_case=LNCAPcond_mutCNAasMutants_RNAasTrans
python3 Scripts/Simulations/MaBoSS_specific_noremove.py $model -sy Linux -p 2 "results_"$sim_case".txt" -o $listout -s $sim_case -m "Results/Profiles/PC20191203_CL_GDSC_mutCNA_prost.csv" -rb "Results/Profiles/PC20191203_CL_GDSC_RNA_norm_prost.csv" -rf 100
sim_case=LNCAPcond_RNAasTrans
python3 Scripts/Simulations/MaBoSS_specific_noremove.py $model -sy Linux -p 2 "results_"$sim_case".txt" -o $listout -s $sim_case -rb "Results/Profiles/PC20191203_CL_GDSC_RNA_norm_prost.csv" -rf 100
