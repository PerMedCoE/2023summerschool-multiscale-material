#!/usr/bin/env bash

projectname="epithelial_cell_2"
# projectname="macrophage"

cd ./"MaBoSS analysis"

echo "1, run MaBoSS instance"
if [ -d "$projectname" ]
then
  echo "WARNING: removing existing MaBoSS folder"
 rm -r $projectname
fi

cp ../data/{"$projectname".bnd,"$projectname".cfg} ./

sed "s/projectname/"$projectname"/g" run_MaBoSS_Unix_Stew.sh >run_MaBoSS_Unix_Stew_post.sh
chmod 755 run_MaBoSS_Unix_Stew_post.sh
./run_MaBoSS_Unix_Stew_post.sh

echo "2, Predict genetic interactions of the model"
if [ -d "$projectname"_epistasis ]
then
  echo "WARNING: removing existing epistasis folder"
 rm -r "$projectname"_epistasis
fi
sed "s/projectname/"$projectname"/g" 1\-4_epistasis_Stew.sh > 1\-4_epistasis_Stew_post.sh
sed -i "s/ -single / -single -onlyko /g" 1\-4_epistasis_Stew_post.sh
chmod 755 1\-4_epistasis_Stew_post.sh
./1-4_epistasis_Stew_post.sh

echo "3, Analyse genetic interactions of the model"
sed "s/projectname/"$projectname"/g" Analyses_of_genetic_interactions_Stew_workflow.R > Analyses_of_genetic_interactions_Stew_workflow_post.R
chmod 755 Analyses_of_genetic_interactions_Stew_workflow_post.R
Rscript Analyses_of_genetic_interactions_Stew_workflow_post.R

cp ./ko_file.txt ../data/
cd ../