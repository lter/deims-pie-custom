<?php
/**
 * @file
 * Definition of PieContentDataFileMigration.
 */

class PieContentDataFileMigration extends DeimsContentDataFileMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);


    $this->addUnmigratedSources(array(
      'log',
      'revision',
      'revision_uid',
      'field_data_file:list',
      'field_data_file_data',
      '3',
      '6',
      'field_datafile_dataset_ref',
    ));

    $this->addUnmigratedDestinations(array(
      'field_date_range:timezone',
      'field_date_range:rrule',
    ));


    $this->removeFieldMapping('field_methods');
    $this->addFieldMapping('field_methods','field_methods')
      ->description('Luq. methods handled in prepareRow');

  }
  public function prepareRow($row) {

    parent::prepareRow($row);
    // Concatenate Methods-description and methods-sampling in LUQ

   if (!empty($row->field_sampling_description[0]['value'])) {
     $row->field_methods = $row->field_methods_description . ' <p /> Sampling Description:<p/>'.$row->field_sampling_description;
   }else{
     $row->field_methods = $row->field_methods_description;
   }

    switch ($row->field_quote_character) {
      case 'double quote':
        $row->field_quote_character = '"';
        break;
      case 'single quote':
        $row->field_quote_character = "'";
        break;
    }

  }
}

