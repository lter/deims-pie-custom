<?php

/**
 * @file
 * Definition of GisEmlFileMigration.
 * Assumes that all the data zip files are in destination /files/gis/
 */

class GisEmlFileMigration extends XMLMigration {
  protected $dependencies = array();
  public function __construct(array $arguments) {

    parent::__construct($arguments);
    $this->description = t('GIS EML migration of the raster data files');

    // all fields that come from GIS EML an map to the Person Content Type
    $fields = array(
      'sourceid' => t('local location of the data file')
    );

    // The source ID here is the one retrieved from the XML listing file,
    // index.xml, whose element root is docid.  it is
    // used to identify the specific item's file (anole, el verde, etc)
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'the GIS Raster EML title',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

//  This can also be an URL instead of a local file path.
    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'giseml_2_deims') . '/xml/raster/';

///////////////////////////////
///  EDIT CHANGE GIS EML FILE HERE
////////////////////////////////
    $items_url = $xml_folder . 'oldemlfilename.xml';

    $item_xpath = '/eml:eml/dataset/spatialRaster';     // relative to document
    $item_ID_xpath = 'physical/objectName';             // relative to item_xpath

    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

// Save to the default file scheme.
    $this->addFieldMapping('destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://');

    $this->addFieldMapping('destination_file', 'destination_file');
    $this->addFieldMapping('value', 'file_uri');

    $this->addFieldMapping('uid')->defaultValue('1');

    $this->addUnmigratedDestinations(array(
       'timestamp',
       'path',
       'preserve_files',
       'file_replace',
       'source_dir',	
       'urlencode',
    ));
  }

  public function prepareRow($row) {

    $filen = (string) $row->xml->physical->objectName;
    $row->file_uri = $base_path . 'sites/default/files/gis/' . $filen;
    $row->destination_file = $filen ;

  }
}
