<?php

/**
 * @file
 * Definition of GisEmlDataFileMigration.
 */

class GisEmlDataFileMigration extends XMLMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $fields = array(
       'titlesrcname' => t('The title in GIS Raster archive'),
       'objectfilename' => t('The archive file name in GIS Raster EML'),
       'description' => t('Description of the data zip archive'),
    );
    // The source ID here is the one retrieved from each data item in the XML file, and
    // used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
       array(
        'objectName' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'PackageId',
         )
       ),
       MigrateDestinationRole::getKeySchema()
    );

    // This can also be an URL instead of a local file path.
    $xml_folder = DRUPAL_ROOT . '/' .
    drupal_get_path('module', 'giseml_2_deims') . '/xml/raster/';
    $items_url = $xml_folder . 'oldemlfilename.xml';

    // the xpath
    $item_xpath = '/eml:eml/dataset/spatialRaster';  // relative to document

    $item_ID_xpath = 'physical/objectName';          // relative to item_xpath

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('data_source');

    $this->addFieldMapping('title', 'datasrcname')
      ->xpath('entityName');

    $this->addFieldMapping('field_description', 'description')
      ->xpath('entityDescription');

    $this->addFieldMapping('field_description:format')->defaultValue('full_html');

    $this->addFieldMapping('field_data_source_file', 'objectfilename')
      ->xpath('physical/objectName')
      ->sourceMigration('GisEmlFile');

    $this->addFieldMapping('field_data_source_file:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_source_file:file_class')->defaultValue('MigrateFileFid');

    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedDestinations(array(
      'path',    	//      Path alias
      'comment',	//      Whether comments may be posted to the node
      'pathauto',
      'created',       //	Created timestamp
      'changed',       //	Modified timestamp
      'status',	       //       Published
      'promote',       //       Promoted to front page
      'sticky',	       //       Sticky at top of lists
      'revision',      //       Create new revision
      'log',	       //       Revision Log message
      'language',      //       Language (fr, en, ...)
      'tnid',          //	The translation set id for this node
      'translate',     //	A boolean indicating whether this translation page needs to be updated
      'revision_uid',  //	Modified (uid)
      'is_new', 
      'field_data_source_file:language',
      'field_data_source_file:description',
      'field_data_source_file:display',
      'field_instrumentation:language',
      'field_quality_assurance:language',
      'field_variables',
      'field_variables:name',
      'field_variables:type',
      'field_variables:definition',
      'field_variables:data',
      'field_variables:missing_values',
      'field_csv_quote_character',
      'field_csv_field_delimiter',
      'field_csv_record_delimiter',
      'field_csv_quote_character:language',
      'field_csv_field_delimiter:language',
      'field_csv_record_delimiter:language',
      'field_description:language',
      'field_date_range',
      'field_date_range:to',
      'field_date_range:timezone',
      'field_date_range:rrule',
      'field_instrumentation:format',
      'field_methods:format',
      'field_quality_assurance:format',
    ));
  }


  public function prepare($node, $row) {

    // Remove any empty or illegal delta field values.
    EntityHelper::removeInvalidFieldDeltas('node', $node);
    EntityHelper::removeEmptyFieldValues('node', $node);

  }

}
