<?php

/**
 * @file
 * Definition of GisEmlKeywordsMigration.
 * For now, this will assume that you
 * created one ginormous xml file with all your
 * GIS-EML keywords
 */

class GisEmlKeywordsMigration extends Migration {
  protected $dependencies = array();
  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $options = array(); 
    $options['header_rows'] = 0; 
    $options['delimiter'] = ","; 

    $columns = array(
      0 => array('keyword', 'The Keyword Name'),
   );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'giseml_2_deims') . '/xml/';
    $csv_file = $xml_folder . 'gisemlKeywords.txt';

    $this->source = new MigrateSourceCSV($csv_file, $columns, $options);

    $this->description = t('GIS EML migration of the keywords');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'keyword' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'the unique keywords found in all my site EMLs',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->destination = new MigrateDestinationTerm('gis_keywords');

    $this->addFieldMapping('name', 'keyword')
     ->description('Optionally, tweak in prepareRow');

  }

  public function prepareRow($row) {

  //  do things here for terms that are misspelled or synonyms, if you wish.
  }

}
