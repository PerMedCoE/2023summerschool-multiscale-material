#!/usr/bin/env bash
java -Xmx6000M -cp './BiNoM.jar' fr.curie.BiNoM.pathways.MaBoSS.MaBoSSConfigurationFile -single -c ./projectname.cfg -b ./projectname.bnd
cp ./projectname.bnd ./projectname_mutants/
cd projectname_mutants/ 
# sed -i 's:../MaBoSS:../../MaBoSS:' run.sh
chmod 755 run.sh
echo "running MaBoSS instances"
./run.sh
cd ..
java -Xmx6000M -cp './BiNoM.jar:./VDAOEngine.jar' fr.curie.BiNoM.pathways.MaBoSS.MaBoSSProbTrajFile -maketable -folder projectname_mutants/ -prefix projectname -out projectname.xls
java -Xmx6000M -cp './BiNoM.jar:./VDAOEngine.jar'  fr.curie.BiNoM.pathways.MaBoSS.MaBoSSProbTrajFile -normtable -table projectname.xls 
mkdir "projectname_epistasis"
mv projectname_m* projectname_n* ./projectname_epistasis/
mv projectname.xls ./projectname_epistasis/
mv projectname.xls.dat ./projectname_epistasis/
# cp projectname_epistasis/projectname_norm.xls ./
