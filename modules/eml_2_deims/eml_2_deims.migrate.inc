<?php

/**
 * @file
 * Migrate module integration with the DEIMS D6 Migration module.
 */

/**
 * Implements hook_migrate_api().
 */
function eml_2_deims_migrate_api() {
  $info = array(
    'api' => 2,
    'groups' => array(
      EML_MIGRATION_GROUP => array(
        'title' => t('EML 2.1.0 migration'),
      ),
    ),
    'migrations' => array(
      'EmlFile' => array(
         'class_name' => 'EmlFileMigration',
      ),
      'EmlKeywords' => array(
         'class_name' => 'EmlKeywordsMigration',
      ),
      'EmlDataFile' => array(
         'class_name' => 'EmlDataFileMigration',
      ),
      'EmlDataSet' => array(
       'class_name' => 'EmlDatasetMigration',
      ),
    ),
  );

  foreach ($info['migrations'] as &$migration) {
    $migration['group_name'] = EML_MIGRATION_GROUP;
  }

  // Allow other modules to alter our migration classes.
  $overrides = module_invoke_all('eml_migration_overrides');
  foreach ($overrides as $machine_name => $override) {
    if (isset($info['migrations'][$machine_name])) {
      $info['migrations'][$machine_name] = $override + $info['migrations'][$machine_name];
    }
  }
  return $info;
}
