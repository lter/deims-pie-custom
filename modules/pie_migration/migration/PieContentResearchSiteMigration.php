<?php

/**
 * @file
 * Definition of PieContentResearchSiteMigration. This extends the base class
 * for the DEIMS Research Site migration, allowing us to accomodate smaller 
 * customization details.
 */

class PieContentResearchSiteMigration extends DeimsContentResearchSiteMigration {
  public function __construct(array $arguments) {
     parent::__construct($arguments);

//   the photos use a different field
     $this->removeFieldMapping('field_images');
     $this->addFieldMapping('field_images','field_research_site_image')
       ->sourceMigration('DeimsFile');

    $this->addFieldMapping('field_core_areas','3')
      ->sourceMigration('PieTaxonomyCoreAreasVocabulary');
    $this->addFieldMapping('field_core_areas:source_type')
      ->defaultValue('tid');

    $this->addUnmigratedSources(array(
       'revision',
       'log',
       'revision_uid',
       'field_east_bounding_coordinate',
       'field_north_bounding_coordinate',
       'field_south_bounding_coordinate',
       'field_west_bounding_coordinate',
       'upload',
       'upload:description',
       'upload:list',
       'upload:weight',
       'field_research_site_image:list',
    ));

    $this->addUnmigratedDestinations(array(
       'field_core_areas:create_term',
       'field_core_areas:ignore_case',
       'field_images:alt',
       'field_images:title',
    ));
      
  }
  public function prepareRow($row) {
    parent::prepareRow($row);
  }
}
