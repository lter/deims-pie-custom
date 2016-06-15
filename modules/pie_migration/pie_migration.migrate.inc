<?php
/**
 * @file 
 * Migrate module integration for the Plum Island Ecosystem DEIMS.
 *
 */
/**
 * Implements hook_migrate_api().
 */
function pie_migration_migrate_api() {
  $info = array(
    'api' => 2,
    'migrations' => array(
      'PieContentBanner' => array(
        'class_name' => 'PieContentBannerMigration',
      ),
      'PieTaxonomyPubsSourceVocabulary' => array(
        'class_name' => 'DrupalTerm6Migration',
        'description' => "Taxonomy migration for the 'Publication Source Vocabulary' vocabulary.",
        'source_connection' => 'drupal6',
        'source_version' => 6,
        'source_vocabulary' => '1',
        'destination_vocabulary' => 'pubs_source_vocab',
      ),
      'PieTaxonomyPIEResearchAreasVocabulary' => array(
        'class_name' => 'DrupalTerm6Migration',
        'description' => "Taxonomy migration for the 'PIE Research Areas' vocabulary.",
        'source_connection' => 'drupal6',
        'source_version' => 6,
        'source_vocabulary' => '6',
        'destination_vocabulary' => 'station_keywords',
      ),
      'PieTaxonomyImageGalleriesVocabulary' => array(
        'class_name' => 'DrupalTerm6Migration',
        'description' => "Taxonomy migration for the 'Image Galleries' vocabulary.",
        'source_connection' => 'drupal6',
        'source_version' => 6,
        'source_vocabulary' => '4',
        'destination_vocabulary' => 'tags',
      ),
    ),
  );
  foreach ($info['migrations'] as &$migration) {
    $migration['group_name'] = DEIMS_D6_MIGRATION_GROUP;
  }
  return $info;
}
/**
 * Implements hook_deims_migration_overrides().
 */
function pie_migration_deims_migration_overrides() {
  return array(
    'DeimsFile' => array('class_name' => 'PieFileMigration'),
    'DeimsContentDataSet' => array('class_name' => 'PieContentDataSetMigration'),
    'DeimsContentOrganization' => array('class_name' => 'PieContentOrganizationMigration'),
    'DeimsContentPerson' => array('class_name' => 'PieContentPersonMigration'),
    'DeimsContentPage' => array('class_name' => 'PieContentPageMigration'),
    'DeimsContentResearchSite' => array('class_name' => 'PieContentResearchSiteMigration'),
    'DeimsContentDataFile' => array('class_name' => 'PieContentDataFileMigration'),
  );
}
