<?php

/**
 * @file
 * Migrate module for the DEIMS GIS EML XML Migration.
 */

/**
 * Implements hook_migrate_api().
 */
function giseml_2_deims_migrate_api() {
  $info = array(
    'api' => 2,
    'groups' => array(
      GIS_EML_MIGRATION_GROUP => array(
        'title' => t('GIS EML 2.1.0 migration'),
      ),
    ),
    'migrations' => array(
      'GisEmlFile' => array(
         'class_name' => 'GisEmlFileMigration',
      ),
      'GisEmlKeywords' => array(
         'class_name' => 'GisEmlKeywordsMigration',
      ),
      'GisEmlDataFile' => array(
         'class_name' => 'GisEmlDataFileMigration',
      ),
      'GisEmlDataSet' => array(
       'class_name' => 'GisEmlDatasetMigration',
      ),
    ),
  );

  foreach ($info['migrations'] as &$migration) {
    $migration['group_name'] = GIS_EML_MIGRATION_GROUP;
  }

  // Allow other modules to alter our migration classes.
  $overrides = module_invoke_all('giseml_2_deims_migration_overrides');
  foreach ($overrides as $machine_name => $override) {
    if (isset($info['migrations'][$machine_name])) {
      $info['migrations'][$machine_name] = $override + $info['migrations'][$machine_name];
    }
  }
  return $info;
}
