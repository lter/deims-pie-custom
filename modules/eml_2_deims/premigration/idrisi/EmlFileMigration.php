<?php

/**
 * @file
 * Definition of EmlFileMigration.
 * For now, this will assume that you
 * downloaded all the datasource files in
 * destination.
 */

class EmlFileMigration extends XMLMigration {
  protected $dependencies = array();
  public function __construct(array $arguments) {

    parent::__construct($arguments);
    $this->description = t('EML migration of the data files');

    // all fields that come from EML an map to the Person Content Type
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
          'description' => 'the EML title',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

//  This can also be an URL instead of a local file path.
    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'eml_2_deims') . '/xml/idrisi/';

///////////////////////////////
///  EDIT CHANGE EML FILE HERE
////////////////////////////////
    $items_url = $xml_folder . 'oldemlfilename.xml';
//  the xpath

    $item_xpath = '/eml:eml/dataset/spatialRaster';      // relative to document
    $item_ID_xpath = 'physical/objectName';                   // relative to item_xpath

    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

// Save to the default file scheme.
    $this->addFieldMapping('destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://');
    // Use the full file path in the file name so that we retain the directory
    // structure.
    $this->addFieldMapping('destination_file', 'destination_file');
    // Set the value to the file name, including path.
    $this->addFieldMapping('value', 'file_uri');

    $this->addFieldMapping('uid')->defaultValue('1');

    $this->addUnmigratedDestinations(array(
       'timestamp',       //	UNIX timestamp for the date the file was added
       'path',            //	Path alias
       'preserve_files',	 //      Option: Boolean indicating whether files should be preserved or deleted on rollback
       'file_replace',    //      Option: Value of $replace in that file function. Defaults to FILE_EXISTS_RENAME.
       'source_dir', 	 //      Subfield: Path to source file.
       'urlencode',
    ));
  }

  public function prepareRow($row) {

    $filen = (string) $row->xml->physical->objectName ;
    $row->file_uri = $base_path . 'sites/default/imports/idrisi/' . $filen . '.csv';
    $row->destination_file = $filen . '.csv';

  }
}
