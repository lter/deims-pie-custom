<?php

/**
 * @file
 * Definition of PieContentDataSetMigration.
 */

class PieContentDataSetMigration extends DeimsContentDataSetMigration {

   public function __construct(array $arguments) {

   parent::__construct($arguments);

    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'upload',
      'upload:description',
      'upload:list',
      'upload:weight',
    ));
    $this->addUnmigratedDestinations(array(
      'field_keywords:create_term',
      'field_keywords:ignore_case',
      'field_core_areas:create_term',
      'field_core_areas:ignore_case',
      'field_taxa_ref',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_date_range:timezone',
      'field_date_range:rrule',
    ));

    $this->addFieldMapping('field_core_areas', '3')
      ->sourceMigration('DeimsTaxonomyCoreAreas');
    $this->addFieldMapping('field_core_areas:source_type')
      ->defaultValue('tid');

    $this->addFieldMapping('field_keywords', '5')
      ->sourceMigration('DeimsTaxonomyLTERControlled');
    $this->addFieldMapping('field_keywords:source_type')
      ->defaultValue('tid');

    $this->addFieldMapping('field_station_keywords_termref', '6')
      ->sourceMigration('PieTaxonomyProjectVocabulary');
    $this->addFieldMapping('field_station_keywords_termref:source_type')
      ->defaultValue('tid');


   }

}
