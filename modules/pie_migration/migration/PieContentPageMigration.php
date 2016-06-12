<?php
/**
* @file
* Definition of PieContentPageMigration
*
*  Visual inspection shows Section keywords attached
*  but no files attached.
*/
class PieContentPageMigration extends DeimsContentPageMigration {

   public function __construct(array $arguments) {

    parent::__construct($arguments);

    $this->removeFieldMapping('body');

    $this->addFieldMapping('body', 'body')
      ->description('Tweak in prepareRow');


    $this->addUnmigratedSources(array(
     'upload',
     'upload:description',
     'upload:list',
     'upload:weight',
     'revision_uid',
     'revision',
     'log',
     '3',
    ));

    $this->addUnmigratedDestinations(array(
    'field_files',
    'field_files:file_class',
    'field_files:language',
    'field_files:preserve_files',
    'field_files:destination_dir',
    'field_files:destination_file',
    'field_files:file_replace',
    'field_files:source_dir',
    'field_files:urlencode',
    'field_files:description',
    'field_files:display',
    'field_images',
    'field_images:file_class',
    'field_images:language',
    'field_images:preserve_files',
    'field_images:destination_dir',
    'field_images:destination_file',
    'field_images:file_replace',
    'field_images:source_dir',
    'field_images:urlencode',
    'field_images:alt',
    'field_images:title',
    ));

  }
 
  public function prepareRow($row) {

    parent::prepareRow($row);

    // Note, change to /sites/default/files/ when production
    $row->body = str_replace("/sites/pie-lter.ecosystems.mbl.edu/files/","/pie/sites/default/files/", $row->body);

  }
  public function prepare($node, $row) {
    // Remove any empty or illegal delta field values.
    EntityHelper::removeInvalidFieldDeltas('node', $node);
    EntityHelper::removeEmptyFieldValues('node', $node);
  }

}
