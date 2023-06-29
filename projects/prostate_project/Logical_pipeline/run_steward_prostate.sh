#!/usr/bin/env bash
# script built for the automatic stewardship of project names in the pipeline

# State your project name inside the quote:
projectname="PC_20191203_rand_LNCAPcond_RNAasTrans_0"

echo "compile MaBoSS"
cd ./lib/MaBoSS-env-2.0/engine/src/
make MAXNODES=200 install
cp ../pub/* ../../../
cd ../../../../

echo "run MaBoSS instance"
cp ./"$projectname".bnd ./"1_run_maboss"
cp ./"$projectname".cfg ./"1_run_maboss"

cd ./"1_run_maboss"
rm -rf projectname
./PlMaBoSS_2.0.pl $projectname.bnd $projectname.cfg

cp $projectname/"$projectname".bnd ../"2_mutants"/
cp $projectname/"$projectname".cfg ../"2_mutants"/

echo "Predict genetic interactions of the model"
cd ../"2_mutants"/
sed "s/projectname/"$projectname"/g" 1\-4_epistasis_Stew_prostate.sh > 1\-4_epistasis_Stew_prostate_post.sh
chmod 755 1\-4_epistasis_Stew_prostate_post.sh
./1-4_epistasis_Stew_prostate_post.sh
cp "$projectname"_epistasis/"$projectname"_norm.xls ../

echo "Analyse genetic interactions of the model"
sed "s/projectname/"$projectname"/g" Analyses_of_genetic_interactions_Stew.R > Analyses_of_genetic_interactions_Stew_post.R
chmod 755 Analyses_of_genetic_interactions_Stew_post.R
Rscript Analyses_of_genetic_interactions_Stew_post.R
mv Rplots.pdf Analyses_of_genetic_interactions_plots.pdf


