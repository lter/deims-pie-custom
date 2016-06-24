<?php
/**
* @file
* Definition of PieContentBannerMigration
*
*/
class PieContentBannerMigration extends DrupalNode6Migration {

  public function __construct(array $arguments) {
    $arguments += array(
      'description' => '',
      'source_connection' => 'drupal6',
      'source_version' => 6,
      'source_type' => 'banner',
      'destination_type' => 'banner',
      'user_migration' => 'DeimsUser',
    );

    parent::__construct($arguments);

    $this->addUnmigratedDestinations(array(
     'field_images:language',
     'field_images:alt',
     'field_images:title',
    ));
    $this->addUnmigratedSources(array(
     'revision_uid',
     'revision',
     'log',
     'field_image:list',
     'field_image:description',
     'upload',
     'upload:description',
     'upload:list',
     'upload:weight',
    ));

    $this->addFieldMapping('field_images','field_image')
      ->sourceMigration('DeimsFile');
    $this->addFieldMapping('field_images:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_images:preserve_files')->defaultValue(TRUE);
  }
  public function prepare($node, $row) {
    // Remove any empty or illegal delta field values.
    EntityHelper::removeInvalidFieldDeltas('node', $node);
    EntityHelper::removeEmptyFieldValues('node', $node);
  }
 
}
