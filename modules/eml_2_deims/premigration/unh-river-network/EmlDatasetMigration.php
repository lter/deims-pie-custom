<?php

/**
 * @file
 * Definition of DeimsContentDataSetMigration.
 */

class EmlDatasetMigration extends XMLMigration {
  protected $dependencies = array('EmlDataFile'); 

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('EML migration of the main data set body');

    // all fields that come from EML an map to the Person Content Type
    $fields = array(
        'alternateIdentifier' => t('The dataset abbreviation, a short name'),
        'title' => t('The dataset title'),
        'abstract' => t('The dataset abstract'),
        'purpose' => t('The dataset purpose'),
        'methods' => t('The dataset methods'),
        'additionalInfo' =>('The dataset additional information'),
        'instrumentation' =>('The dataset instrumentation'),
        'qualityControl' =>('The dataset quality assurance'),
        'geoRef' => ('A geographical reference'),
        'temporal' => ('The time when the data set was collected'),
        'creatorRef' => ('A dataset pi or owner(s) reference'),
        'contactRef' => ('A dataset contact reference'),
        'metadataProviderRef' => ('A dataset metadata provider reference'),
        'publisherRef' => ('A dataset publisher reference'),
        'pubdate' => t('The dataset publication date'),
        'beginDate' => t('The dataset start date'),
        'endDate' => t ('The last date of the dataset record'),
       'language' => t('The dataset language'),
   //    'associatedparties' => t('The dataset associated roles'),
        'keywordRef' => t('The keywords tagging this dataset'),
        'customKeywordRef' => t('The pi-assigned keywords tagging this dataset'),
        'coreArea' => t('A core area term. Extends EML'),
        'maintenance' => t('The dataset maintenance'),
        'dataRasterRef' => t('The data sources associated with this dataset'),
        'datasetid' => t('The dataset id'),
        'revisionid' => t('The dataset EML revision id'),
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
///CHANGE EDIT EML FILE HERE  or use sh script..
//////////////////////////////////////////////////////
    // This can also be an URL instead of a local file path.
    $xml_folder = DRUPAL_ROOT . '/' .
    drupal_get_path('module', 'eml_2_deims') . '/xml/unh-river-network/';
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
      ->xpath('dataset/abstract/section/para');

    $this->addFieldMapping('field_section:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_section')->defaultValue('River Network');
    //@todo  here again, it is a complex element
    // This content type does not have a body field.

    $this->addFieldMapping('field_data_set_id', 'datasetid')
       ->description('dataset id may come from packageId in prepareRow');

    $this->addFieldMapping('field_eml_revision_id','revisionid')
       ->description('Extract revision in prepareRow');

    // this is not part of EML -- Added to make the migration effective
    $this->addFieldMapping('field_core_areas', 'coreArea')
       ->xpath('dataset/coreArea');

    $this->addFieldMapping('field_core_areas:ignore_case')->defaultValue(TRUE);

    //$this->addFieldMapping('field_keywords', '9');

    $this->addFieldMapping('field_station_keywords_ref:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_station_keywords_ref', 'customKeywordRef')
       ->description('Tweak in prepareRow');

    $this->addFieldMapping('field_station_keywords_ref:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_section:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_section')->defaultValue('Belowground');

    $this->addFieldMapping('field_purpose', 'purpose')
        ->xpath('dataset/purpose/section/para/literalLayout');

      //@todo another text type for parsing
    $this->addFieldMapping('field_additional_information', 'additionalInfo')
        ->xpath('dataset/additionalInfo/para/literalLayout');

    $this->addFieldMapping('field_maintenance', 'maintenance')
        ->xpath('dataset/maintenance/description/section/para/literalLayout');
      //@todo another text type for parsing

    $this->addFieldMapping('field_data_sources', 'dataRasterRef')
      ->description('In preparerow');

    $this->addFieldMapping('field_methods', 'methods')
        ->description('in prepareRow');
//        ->xpath('dataset/methods/methodStep/description');

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
        ->defaultValue(2226);

    $this->addFieldMapping('field_person_metadata_provider', 'metadataProviderRef')
        ->defaultValue(2226);

    $this->addFieldMapping('field_person_publisher', 'publisherRef')
        ->defaultValue(2226);

    $this->addFieldMapping('uid')->defaultValue(1);

//    $this->addUnmigratedSources(array(
//      'associatedparties', // Handled in prepare()
//    ));

    $this->addUnmigratedDestinations(array(
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
      'created',
      'changed',
      'status',    //   Published
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

    //dataset shortname
    if(!isset($row->xml->dataset->alternateIdentifier)){
        $row->xml->dataset->alternateIdentifier = 'No short name assigned';
    }
 
    //pubdate
    if (preg_match('/(\d+)/',$row->xml->dataset->pubDate, $found)){
     $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-01-01 00:00:00"));
     $row->xml->dataset->pubDate = $mydate;
    }

    // begin date
    if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate = $mydate;
    } else if ( preg_match('/(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-01-01 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->beginDate->calendarDate = $mydate;
    }

    // end date
    if ( preg_match('/(\d+)-(\d+)-(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-$found[2]-$found[3] 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate = $mydate;
    } else if ( preg_match('/(\d+)/',$row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate, $found)){
      $mydate = date('Y-m-d H:i:s',strtotime("$found[1]-12-31 00:00:00"));
      $row->xml->dataset->coverage->temporalCoverage->rangeOfDates->endDate->calendarDate = $mydate;
    }

    //  creator last name
    $surnameid = $this->getPerson($row);
    $row->xml->dataset->creator->individualName->surName = $surnameid;

    //  Datasource
    $row->dataRasterRef = $this->getDataSource($row);

    // pi-assigned keywords in <keywordSet> construct
    $row->customKeywordRef = $this->getKeywords($row);

    // EML Methods:
    $methods_values = '';
    foreach($row->xml->dataset->methods->methodStep->description->para->ulink as $parael){
       $methods_values .= 'For additional methods and metadata, see: '. (string)$parael;  
    }
    $row->methods = $methods_values;
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
//        watchdog('EML2DEIMS:', "Ds-Person query matches: $nid");
      }else{
        $strquery = print_r($query);
//        watchdog('EML2DEIMS:', "Ds-Person query yield no matches $strquery ");
      }
    }
    return $nid;
  }

  public function getDataSource($row) {

    $field_values = array();

    foreach($row->xml->dataset->spatialRaster as $xmldatasource) {
      $source_id  = $xmldatasource->physical->objectName;
      $field_values[] = $this->handleSourceMigration('EmlDataFile', $source_id);
    }
    return $field_values;

  }
  public function getKeywords($row) {

    $field_values = array();

    foreach($row->xml->dataset->keywordSet->keyword as $xmlkeyword) {
      $keym = (string)$xmlkeyword;
      $keys = $pieces = explode(" ", $keym);
      foreach ($keys as $keywd) {
        if ($value = $this->handleSourceMigration('EmlKeywords', $keywd) ) {
          $field_values[] = $value;
        }
      }
    }
    return $field_values;
  }
}
