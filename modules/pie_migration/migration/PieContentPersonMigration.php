<?php
/**
 * @file
 * Definition of PieContentPersonMigration.
 */

class PieContentPersonMigration extends DeimsContentPersonMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // field_person_pubs and two other do not exist
    $this->removeFieldMapping(NULL, 'field_person_pubs');
    $this->removeFieldMapping(NULL, 'field_person_fullname');
    $this->removeFieldMapping(NULL, 'field_person_list');

    $this->addUnmigratedSources(array(
      'field_person_lastfirstname',
      'revision',
      'log',
      'revision_uid',
      'upload',
      'upload:description',
      'upload:list',
      'upload:weight',
    ));

   $this->addUnmigratedDestinations(array(
     'field_associated_biblio_author',
     'field_list_in_directory',
     'field_url',
     'field_url:title',
     'field_url:attributes',
   ));


  }

  public function prepareRow($row) {
    // Fix empty email values used on pie.
    switch ($row->field_person_email) {
      case 'unknown@ualaska.edu':
      case 'none@ualaska.edu':
        $row->field_person_email = NULL;
    }

    // Fix country values used on pie.
    switch ($row->field_person_country) {
      case 'Dublin':
        $row->field_person_city = 'Dublin';
        $row->field_person_country = 'Ireland';
        break;
      case 'Cumbria':
        $row->field_person_state = 'Cumbria';
        $row->field_person_country = 'United Kingdom';
        break;
    }

    parent::prepareRow($row);
  }

  public function getOrganization($node, $row) {
    $field_values = array();

    // Search for an already migrated organization entity with the same title
    // and link value.
    if (!empty($row->{'field_person_organization:title'})) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'organization');
      $query->propertyCondition('title', $row->{'field_person_organization:title'});
      $results = $query->execute();
      if (!empty($results['node'])) {
        $field_values[] = array('target_id' => reset($results['node'])->nid);
      }
    }

    return $field_values;
  }
}
