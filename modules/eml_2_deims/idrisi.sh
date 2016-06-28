#!/bin/bash 

## GoaL: 
# We have three migration classes (EMLFile, EMLDataFile and EMLDataSet). Each class is in a php file that contains 
# the name of eml to import. 
#
# We want to iterate the import process for each EML - we need to change this filename (the name of eml to import 
# in those class files) and run a command to import the eml into DEIMS.

# The ./xml/ sub-directories contains the eml files. 

# Process
# 1) We read the name of all eml files. We loop to change the class files and run each EML migration

# 2) Loop:

# 	2.1) Change the name of eml in the class files ( emlfilename ) by the name of eml file (once per iteration)

# 	2.2) Run the command drush ... to import the eml into DEIMS

# 	2.3) Save the name of eml that had been processed into a .txt file (only for checking purposes)



#General path 
mydir="/home/isangil/www/pie7/www/sites/default/modules/eml_2_deims/xml/idrisi"

# Get the names of XML files from the subfolder (streams, met, glaciers, lakes, models, soils)
xml_files="${mydir}/*.xml"

# File to save the name of the eml that has been processed
touch eml_processed.txt

# Loop to change the name of eml filename within Class (modules to import EML)
for f in $xml_files

 do 

  # Eml file name with extension (.xml)
  xml_file_name=${f##*/} 

  # Eml file name
  eml_file_name=${xml_file_name%.xml}


  # EMLFile Class 
  # Replace the name of eml in the class file 'EMLFile' by the eml file name extracted from directory 
  sed -e "s/oldemlfilename/$eml_file_name/" ./premigration/idrisi/EmlFileMigration.php 1> ./migration/EmlFileMigration.php

  # EmlDataFile Class 
  # Replace the name of eml in the class file 'EMLDataFile.php' by the eml file name extracted from directory 
  sed -e "s/oldemlfilename/$eml_file_name/" ./premigration/idrisi/EmlDataFileMigration.php 1> ./migration/EmlDataFileMigration.php

  # EmlDataSet Class 
  # Replace the name of eml in the class file 'EMLDataSet' by the eml file name extracted from directory 
  sed -e "s/oldemlfilename/$eml_file_name/" ./premigration/idrisi/EmlDatasetMigration.php 1> ./migration/EmlDatasetMigration.php

  # flush the registry, and re-register new classes.

  drush cc registry;
  drush migrate-register;

  # run the migrations / ejecuta el script 
  # ejecuta el script (run the migration)

  drush mi EmlFile;
  drush mi EmlDataFile;
  drush mi EmlDataSet;

  # When the name of eml has been inserted into the three Classes files, a text entry is included into a .txt file
  echo "$eml_file_name.xml has been processed" >> eml_processed.txt 

done


