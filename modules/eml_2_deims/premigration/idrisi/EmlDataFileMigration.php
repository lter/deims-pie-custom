<?php

/**
 * @file
 * Definition of EmlDataFileMigration.
 */

class EmlDataFileMigration extends XMLMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $fields = array(
       'datasrcname' => t('The table name in EML'),
       'description' => t('Description of the data source in EML'),
       'methods' => t('Place the variables in ds-level methods'), 
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
    drupal_get_path('module', 'eml_2_deims') . '/xml/idrisi/';
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
      ->description('Concatenate in prepareRow()');

    $this->addFieldMapping('field_description:format')->defaultValue('full_html');

    $this->addFieldMapping('field_methods', 'methods')
      ->description('Concatenate in prepareRow()');

    $this->addFieldMapping('field_methods:format')->defaultValue('full_html');

    $this->addFieldMapping('field_data_source_file', 'datasrcname')
      ->xpath('physical/objectName')
      ->sourceMigration('EmlFile');

    $this->addFieldMapping('field_data_source_file:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_source_file:file_class')->defaultValue('MigrateFileFid');

      //@toDo   Treat this in prepare, since it could be a mix and mash of singleDates
      // and range of dates. also, something is up w/ end date.

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

  public function prepareRow($row) {

    parent::prepareRow($row);

       $description = (string) $row->xml->entityDescription;

       $description_value = array();

       $sr_horizsys = $row->xml->spatialReference->horizCoordSysDef->attributes();
       $sr_horizsys_name = $sr_horizsys['name'];

       $description .= 'Horizontal Coordinate System Name:' . $sr_horizsys_name . '<p/>';

       $geog = $row->xml->spatialReference->horizCoordSysDef->projCoordSys->geogCoordSys;
       
       $datum = $geog->datum->attributes();
       $datum_name = 'Datum: ' . $datum['name'] . '<br/>';
       $description .= $datum_name;

       $sphere = $geog->spheroid->attributes();
       $sphere_name = 'Reference Ellipsoid: Name: ' . $sphere['name'] . ' Semi Axis: ' . $sphere['semiAxisMajor'] . '<br/>'>
       $description .= $sphere_name;       

       $prime_meridian = $geog->primeMeridian->attributes();
       $prime_meridian_name = 'Meridian: ' . $prime_meridian['name'] . '<br/>';
       $description .= $prime_meridian_name;

       $proj = $row->xml->spatialReference->horizCoordSysDef->projCoordSys->projection->attributes();
       $projection_name = 'Projection Name : ' . $proj['name'] . '<br/>';
       $description .= $projection_name;

       $number_bands = 'Number of bands : ' . $row->xml->numberOfBands . '<br/>';
       $description .= $number_bands;

       $raster_orig = 'Raster Origin : ' . $row->xml->rasterOrigin . '<br/>';
       $description .= $raster_orig;

       $rrows =  'Rows : ' . $row->xml->rows . '<br/>';
       $description .= $rrows;

       $rcols =  'Columns : ' . $row->xml->columns . '<br/>';
       $description .= $rcols;

       $cellgeom = 'Cell Geometry :' . $row->xml->cellGeometry . '<br/>'; 
       $description .= $cellgeom;

       $description_value[] = $description;

       $row->description = $description_value;  

       $variables = array();
       $variables = $this->get_variables($row);

       $row->methods = $variables;
  }

  public function prepare($node, $row) {
    // Fetch and prepare the variables field.

    // Remove any empty or illegal delta field values.
    EntityHelper::removeInvalidFieldDeltas('node', $node);
    EntityHelper::removeEmptyFieldValues('node', $node);

  }

  public function get_variables($row) {
    // We already have the array of referenced variable nodes in this row variable.
    // First filter out any NULL or empty values before proceeding.
    $field_values = array();

    $attribute_list = $row->xml->attributeList;//->children();

    foreach ($attribute_list as $variables) {
       foreach ($variables as $variable){
          $value = array();
          // The label value is not required, but node title is.
          if(isset($variable->attributeLabel)){
             $value_string = ' Label : ' . (string) $variable->attributeLabel . '<br/>';
          }
          $value_string .= ' Name : ' . (string) $variable->attributeName . '<br/>';
          $value_string .= ' Definition : ' . (string) $variable->attributeDefinition . '<br/>';

          if (isset($variable->measurementScale->ratio->numericDomain->numberType) ){
            // even numberType is used to determine is a "physical" type, it is not used in DEIMS
            // $number_type = (string) $variable->measurementScale->ratio->numericDomain->numberType;
            $stunit = (string) $variable->measurementScale->ratio->unit->standardUnit;
            $customunit = (string) $variable->measurementScale->ratio->unit->customUnit;
            if (strlen($stunit)>0){
                $value_string .= ' Unit : ' . $stunit . '<br/>';
            }else{
                $value_string .= ' Unit : ' . $customunit . '<br/>';
            }
          } elseif (isset($variable->measurementScale->nominal->nonNumericDomain->enumeratedDomain->codeDefinition->definition)){
            // Extract the code-definition pairs from the simpleXmlObject into assoc. array
            $codex = $variable->measurementScale->nominal->nonNumericDomain->enumeratedDomain;
            foreach ($codex as $codedefinitions){
              foreach  ($codedefinitions as $codedefpair){
                $code =  (string) $codedefpair->code;
                $defi = (string) $codedefpair->definition;
                $value_string .= ' Code Defintion pair : ' . $code . ' ' . $defi . '<br/>';
              }
            }
          }
          else {
            $value_string .= ' Defintion : ' . (string) $variable->measurementScale->nominal->nonNumericDomain->textDefinition->definition . '<br/>';
          }
       }
    }

    $field_values[] = $value_string;

    return $field_values;
  }
}
