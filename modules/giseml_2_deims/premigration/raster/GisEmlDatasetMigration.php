<?php

/**
 * @file
 * Definition of GisEmlDatasetMigration.
 */

class GisEmlDatasetMigration extends XMLMigration {
  protected $dependencies = array('GisEmlDataFile'); 

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('GIS Raster EML migration of dataset metadata');

    // all fields that come from GISEML an map to the Person Content Type
    $fields = array(
        'alternateIdentifier' => t('The dataset abbreviation, a short name'),
        'title' => t('The dataset title'),
        'abstract' => t('The dataset abstract'),
        'methods' => t('The dataset methods'),
        'additionalInfo' => t('The dataset additional information'),
        'instrumentation' => t('The dataset instrumentation'),
        'qualityControl' => t('The dataset quality assurance'),
        'geoRef' => t('A geographical reference'),
        'temporal' => t('The time when the data set was collected'),
        'creatorRef' => t('A dataset pi or owner(s) reference'),
        'contactRef' => t('A dataset contact reference'),
        'metadataProviderRef' => t('A dataset metadata provider reference'),
        'publisherRef' => t('A dataset publisher reference'),
        'pubdate' => t('The dataset publication date'),
        'beginDate' => t('The dataset start date'),
        'endDate' => t('The last date of the dataset record'),
        'locationsitenid' => t('The nid for the location site'),
        'language' => t('The dataset language'),
   //    'associatedparties' => t('The dataset associated roles'),
        'customKeywordRef' => t('The pie XML assigned keywords tagging this dataset to GIS Keyw'),
        'sectionKeywordRef' => t('The GIS specific subsection keywords tagging this dataset to Section'),
        'gisKeywordRef' => t('One of four GIS section keywords tagging this dataset to PIE Res. Areas voc - aka stat key'),
        'maintenance' => t('The dataset maintenance'),
        'dataRasterRef' => t('The data sources associated with this dataset'),
        'datasetid' => t('The dataset id'),
        'revisionid' => t('The dataset GIS Raster EML revision id'),
    );

    // The source ID here is the one retrieved from the XML listing file,
    // index.xml, whose element root is docid.  it is
    // used to identify the specific item's file (anole, el verde, etc)
    $this->map = new MigrateSQLMap($this->machineName,
       array(
         'sourceid' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
            'description' => 'PackageId',
         )
      ),
      MigrateDestinationNode::getKeySchema()
    );

/////////////////////////////////////////////////////
///CHANGE EDIT GIS EML FILE HERE  or use sh script..
//////////////////////////////////////////////////////
    // This can also be an URL instead of a local file path.
    $xml_folder = DRUPAL_ROOT . '/' .
    drupal_get_path('module', 'giseml_2_deims') . '/xml/raster/';
    $items_url = $xml_folder . 'oldemlfilename.xml';

    // the xpath
    $item_xpath = '/eml:eml';  // relative to document
    $item_ID_xpath = '@packageId';          // relative to item_xpath

    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);
    $this->destination = new MigrateDestinationNode('data_set');

    $this->addFieldMapping('title','title')
      ->xpath('dataset/title');

    $this->addFieldMapping('field_short_name', 'alternateIdentifier')
       ->xpath('dataset/alternateIdentifier');

    $this->addFieldMapping('field_abstract','abstract')
      ->xpath('dataset/abstract/para');
    $this->addFieldMapping('field_abstract:format')->defaultValue('full_html');

    //@todo  here again, it is a complex element
    // This content type does not have a body field.

    $this->addFieldMapping('field_data_set_id', 'datasetid')
       ->description('dataset id may come from packageId in prepareRow');

    $this->addFieldMapping('field_eml_revision_id','revisionid')
       ->description('Extract revision in prepareRow');

//  'sectionKeywordRef' => t('The GIS specific subsection keywords tagging this dataset to Section'),

    $this->addFieldMapping('field_section:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_section','sectionKeywordRef')
      ->description('In preparerow');

//  'gisKeywordRef' => t('One of four GIS section keywords tagging this dataset to PIE Res. Areas voc - aka stat key'),

    $this->addFieldMapping('field_station_keywords_ter', 'gisKeywordRef')
      ->description('Tweak in prepareRow');
    $this->addFieldMapping('field_station_keywords_ter:ignore_case')->defaultValue(TRUE);

//  'customKeywordRef' => t('The pie XML assigned keywords tagging this dataset to GIS Keyw'),

    $this->addFieldMapping('field_gis_section_termref:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_gis_section_termref:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_gis_section_termref','customKeywordRef')
      ->description('explode XML in preparerow');

      //@todo another text type for parsing
    $this->addFieldMapping('field_additional_information', 'additionalInfo')
        ->xpath('dataset/additionalInfo/para/literalLayout');
    $this->addFieldMapping('field_additional_information:format')->defaultValue('full_html');

    $this->addFieldMapping('field_maintenance', 'maintenance')
        ->xpath('dataset/maintenance/description/section/para/literalLayout');
      //@todo another text type for parsing

    $this->addFieldMapping('field_data_sources', 'dataRasterRef')
      ->xpath('dataset/spatialRaster/entityName')
      ->description('In preparerow');

    $this->addFieldMapping('field_methods:format')->defaultValue('full_html');
    $this->addFieldMapping('field_methods', 'methods')
        ->description('in prepareRow');

      //@todo another text type for parsing
    $this->addFieldMapping('field_instrumentation', 'instrumentation')
        ->xpath('dataset/methods/methodStep/instrumentation');

    $this->addFieldMapping('field_quality_assurance', 'qualityControl')
        ->xpath('dataset/methods/qualityControl/description/para/literalLayout');

      //@todo dates may come in other flavors, such as singleDateTime, repeated
    $this->addFieldMapping('field_date_range', 'beginDate')
       ->xpath('dataset/coverage/temporalCoverage/rangeOfDates/beginDate/calendarDate')
       ->description('date str to time in prepareRow');

    $this->addFieldMapping('field_date_range:to', 'endDate')
       ->xpath('dataset/coverage/temporalCoverage/rangeOfDates/endDate/calendarDate')
       ->description('date str to time in prepareRow');

    $this->addFieldMapping('field_publication_date', 'pubdate')
       ->xpath('dataset/pubDate')
       ->description('date str to time in prepareRow');

    $this->addFieldMapping('field_person_creator', 'creatorRef')
       ->xpath('dataset/creator/individualName/surName')
       ->description('lookup creator in prepareRow');

    $this->addFieldMapping('field_person_contact', 'contactRef')
       ->xpath('dataset/contact/individualName/surName')
       ->description('lookup contact in prepareRow');

    $this->addFieldMapping('field_person_metadata_provider', 'metadataProviderRef')
        ->defaultValue(3413);   // set to PIE Org

    $this->addFieldMapping('field_person_publisher', 'publisherRef')
        ->defaultValue(3413);

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('field_related_sites','locationsitenid')
      ->description('in preparerow()');

//    $this->addUnmigratedSources(array(
//      'associatedparties', // Handled in prepare()
//    ));

    $this->addUnmigratedDestinations(array(
      'field_core_areas',
      'field_core_areas:source_type',
      'field_core_areas:create_term',
      'field_core_areas:ignore_case',
      'field_data_set_id:language',
      'field_abstract:language',
      'field_short_name:language',
      'field_purpose:language',
      'field_additional_information:language',
      'field_related_links:language',
      'field_maintenance:language',
      'field_methods:language',
      'field_instrumentation:language',
      'field_quality_assurance:language',
      'field_doi',
      'field_doi:language',
      'field_eml_hash',
      'field_eml_hash:language',
      'field_eml_link',
      'field_eml_valid',
      'field_date_range:timezone', //	Timezone
      'field_date_range:rrule',
      'field_instrumentation:format',
      'field_keywords',
      'field_keywords:source_type',
      'field_keywords:create_term',
      'field_keywords:ignore_case',
      'field_maintenance:format',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_purpose',
      'field_purpose:format',
      'field_quality_assurance:format',
      'field_related_links',
      'field_related_links:title',
      'field_related_links:attributes',
      'field_taxa_ref',
      'field_section:source_type',
      'field_section:create_term',
      'field_gis_section_termref:create_term',
      'field_station_keywords_ter:create_term',
      'path',
      'pathauto',
      'comment',
      'created',
      'changed',
      'promote',   //   Promoted to front page
      'sticky',    //   Sticky at top of lists
      'revision',  //   Create new revision
      'log',       //   Revision Log message
      'language',  //   Language (fr, en, ...)
      'tnid',      //   The translation set id for this node
      'translate', //   A boolean indicating whether this translation page needs to be updated
      'revision_uid',
    ));
  }

  public function prepareRow($row) {
    parent::prepareRow($row);

    //dataset id
    $pa = $row->xml->attributes();
    $val=$pa['packageId'];
    list($scope, $identifier, $revision)= explode('.', $val, 3);
    $row->datasetid = $identifier;
    $row->revisionid= $revision;

    // pie-assigned keywords in GIS EML <keywordSet> construct
    $row->customKeywordRef = $this->getKeywords($row);

    if ($identifier <= 268){
      $row->gisKeywordRef = 'Ipswich Watershed';
      if ($identifier <= 254){
        $row->sectionKeywordRef = 'Elevation and Bathymetry';
      }elseif ($identifer <=261 ){
        $row->sectionKeywordRef = 'Land Use';
      }elseif ($identifer <= 262 ){
        $row->sectionKeywordRef = 'Elevation and Bathymetry';
      }elseif ($identifer <= 268){
        $row->sectionKeywordRef = 'Boundaries';
      }
      $row->locationsitenid = 5559; // Ipswich watershed 
    } elseif ( $identifier <= 285){
      $row->gisKeywordRef = 'Ipswich and Parker Watershed';
      if ($identifier <= 280){
        $row->sectionKeywordRef = 'Land Use';
      } else {
        $row->sectionKeywordRef = 'Boundaries';  
      }
      $row->locationsitenid = 5558; // The whole PIE 
    } elseif ( $identifier <= 290){
      $row->gisKeywordRef = 'River Network';
      $row->locationsitenid = 5560; // Ipswich and Parker watersheds 
    } elseif ( $identifier <= 500){
      $row->gisKeywordRef = 'Land Cover';
      $row->locationsitenid = 5558; // Whole PIE
      if ( $identifier <= 342){
        $row->sectionKeywordRef = 'Towns';  
      } elseif ( $identifier <= 477){
        $row->sectionKeywordRef = 'Boundaries';  
      } elseif ( $identifier <= 479){
        $row->sectionKeywordRef = 'Land Use';  
      } elseif ( $identifier <= 480){
        $row->sectionKeywordRef = 'Zoning';  
      } elseif ( $identifier <= 483){
        $row->sectionKeywordRef = 'Census';  
      } elseif ( $identifier <= 484){
        $row->sectionKeywordRef = 'Parcels';  
      }
    }

    //dataset shortname
    if(!isset($row->xml->dataset->alternateIdentifier)){
        $row->xml->dataset->alternateIdentifier = 'No short name assigned';
    }
 
    //pubdate
    if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->pubDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->xml->dataset->pubDate = $mydate;
    } else if (preg_match('/(\d+)/',$row->xml->dataset->pubDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-01-01 00:00:00"));
      $row->xml->dataset->pubDate = $mydate;
    }

    // begin date
    if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate, $found)){
      $mybdate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->beginDate = $mybdate;
    } else if ( preg_match('/(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate, $found)){
      $mybdate = date('Y-m-d H:i:s',strtotime("$found[1]-01-01 00:00:00"));
      $row->beginDate = $mybdate;
    } else if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->coverage->temporalCoverage->singleDateTime->calendarDate, $found)){
      $mybdate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->beginDate = $mybdate;
    } else if ( preg_match('/(\d+)/',$row->xml->dataset->coverage->temporalCoverage->singleDateTime->calendarDate, $found)){
      $mybdate = date('Y-m-d H:i:s',strtotime("$found[1]-01-01 00:00:00"));
//      $row->xml->dataset->coverage->temporalCoverage->bdate = $mybdate;
      $row->beginDate = $mybdate;
    }

    // end date
    if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate = $mydate;
    } else if ( preg_match('/(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-12-31 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate = $mydate;
    } else {
//      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate = $mybdate;
       $row->endDate = $mybdate;
    }

    //  creator last name
    $surnameid = $this->getPerson($row);
    $row->xml->dataset->creator->individualName->surName = $surnameid;

    //  contact last name
    $surnameid = $this->getContactPerson($row);
    $row->xml->dataset->contact->individualName->surName = $surnameid;

    //  raster entity name
    $rasternameid = $this->getRasterSource($row);
    $row->xml->dataset->spatialRaster->entityName = $rasternameid;

    // GIS EML Methods:
    $methods_values = '';
    if(isset($row->xml->dataset->methods->methodStep->description->para)){
      foreach($row->xml->dataset->methods->methodStep->description->para as $parael){
        $methods_values .= (string)$parael. '<p/>';  
      }
    }
    if (isset($row->xml->dataset->spatialRaster)){
      $gis = $row->xml->dataset->spatialRaster;
    }else if(isset($row->xml->dataset->spatialVector)){
      $gis = $row->xml->dataset->spatialVector;
    }else{
       $row->methods = $methods_values;
       return;
    }

    // gis related metadata
    $description = '<h3> Information relevant to the GIS data encoding </h3>';
    $description .= (string) $gis->entityDescription;

    if ( isset($gis->spatialReference->horizCoordSysDef) ){
      $sr_horizsys = $gis->spatialReference->horizCoordSysDef->attributes();
      $sr_horizsys_name = $sr_horizsys['name'];
      $description .= 'Horizontal Coordinate System Name:' . $sr_horizsys_name . '<p/>';
    }

    if ( isset($gis->spatialReference->horizCoordSysDef->projCoordSys->geogCoordSys) ){
      $geog = $gis->spatialReference->horizCoordSysDef->projCoordSys->geogCoordSys;
      $datum = $geog->datum->attributes();
      if (isset ($datum['name'])){
       $description .= 'Datum: ' . $datum['name'] . '<br/>';
      }
      $sphere = $geog->spheroid->attributes();
      if (isset ($sphere['name'])){
        $description .= 'Reference Ellipsoid: Name: ' . $sphere['name'] . ' Semi Axis: ' . $sphere['semiAxisMajor'] . '<br/>';
      }
      $prime_meridian = $geog->primeMeridian->attributes();
      if (isset ($prime_meridian['name'])){
        $description .= 'Meridian: ' . $prime_meridian['name'] . '<br/>';
      }
    }
    $proj = $gis->spatialReference->horizCoordSysDef->projCoordSys->projection->attributes();
    $description .= 'Projection Name : ' . $proj['name'] . '<br/>';
    if (isset ($gis->numberOfBands)){
      $description .= 'Number of bands : ' . $gis->numberOfBands . '<br/>';
    }
    if (isset ($gis->rasterOrigin)){
      $description .= 'Raster Origin : ' . $gis->rasterOrigin . '<br/>';
    }
    if (isset ($gis->rows)){
      $description .=  'Rows : ' . $gis->rows . '<br/>';
    }
    if (isset ($gis->columns)){
      $description .=  'Columns : ' . $gis->columns . '<br/>';
    }
    if (isset ($gis->cellGeometry)){
      $description .= 'Cell Geometry :' . $gis->cellGeometry . '<br/>'; 
    }

    if(isset($row->xml->dataset->spatialRaster->methods->methodStep->description->para)){
      foreach($row->xml->dataset->spatialRaster->methods->methodStep->description->para as $parael){
         $methods_values .= (string)$parael. '<p/>';  
      }
    } 

    $methods_values .= $description;

    $row->methods = $methods_values;
  }

  public function prepare($node, $row) {

    // Remove any empty or illegal delta field values.
    EntityHelper::removeInvalidFieldDeltas('node', $node);
    EntityHelper::removeEmptyFieldValues('node', $node);
  }
  public function getPerson($row) {

    // query database here, match with $row element, return nid for this person, otherwise false.

    // Search for an already migrated person entity with the same title
    // (title is "givenName" "surName")

    if (!empty($row->xml->dataset->creator->individualName->surName)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'person');
      $query->propertyCondition('title', $row->xml->dataset->creator->individualName->surName, 'CONTAINS');
      $results = $query->execute();
      if (!empty($results['node'])) {
        $nid = reset($results['node'])->nid;
//        watchdog('GISEML2DEIMS:', "Ds-Person query matches: $nid");
      }else{
        $strquery = print_r($query);
//        watchdog('GISEML2DEIMS:', "Ds-Person query yield no matches $strquery ");
      }
    }
    return $nid;
  }

  public function getContactPerson($row) {

    if (!empty($row->xml->dataset->contact->individualName->surName)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'person');
      $query->propertyCondition('title', $row->xml->dataset->contact->individualName->surName, 'CONTAINS');
      $results = $query->execute();
      if (!empty($results['node'])) {
        $nid = reset($results['node'])->nid;
      }
    } else {
      $nid = 4382; // 4382 is the inform. mangr at dev
    }
    return $nid;
  }

  public function getDataSource($row) {

    $field_values = array();

    foreach($row->xml->dataset->spatialRaster as $xmldatasource) {
      $source_id  = $xmldatasource->entityName;
      print_r('SourceID:'); 
      print_r($source_id);
      if ($value = $this->handleSourceMigration('GisEmlDataFile', $source_id)){
        $field_values[] = $value;
      }else{
        print_r('No FV: ');
        print_r($this->handleSourceMigration('GisEmlDataFile', $source_id));
      }
    }
    return $field_values;

  }
  public function getKeywords($row) {

    $field_values = array();

    foreach($row->xml->dataset->keywordSet->keyword as $xmlkeyword) {
      $keym = (string)$xmlkeyword;
      $keys = explode(" ", $keym);
      foreach ($keys as $keywd) {
        if ($value = $this->handleSourceMigration('GisEmlKeywords', $keywd) ) {
          $field_values[] = $value;
        }
      }
    }
    return $field_values;
  }

  public function getRasterSource($row) {

    if (!empty($row->xml->dataset->spatialRaster->entityName)) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'data_source');
      $query->propertyCondition('title', $row->xml->dataset->spatialRaster->entityName, 'CONTAINS');
      $results = $query->execute();
      if (!empty($results['node'])) {
        $nid = reset($results['node'])->nid;
//        watchdog('GISEML2DEIMS:', "Dset-Dsource query matches: $nid");
      }else{
        $strquery = print_r($query);
//        watchdog('GISEML2DEIMS:', "Dset-Dsource query yield no matches $strquery ");
      }
    }
    return $nid;

  }

}
