<?php
/**
 * @file
 * deims_person.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function deims_person_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'field_images',
      ),
      'left' => array(
        1 => 'field_name',
        2 => 'field_person_title',
        3 => 'field_person_role',
        4 => 'field_organization',
        5 => 'field_address',
        6 => 'field_email',
        7 => 'field_phone',
        8 => 'field_fax',
        9 => 'field_associated_biblio_author',
      ),
    ),
    'fields' => array(
      'field_images' => 'right',
      'field_name' => 'left',
      'field_person_title' => 'left',
      'field_person_role' => 'left',
      'field_organization' => 'left',
      'field_address' => 'left',
      'field_email' => 'left',
      'field_phone' => 'left',
      'field_fax' => 'left',
      'field_associated_biblio_author' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|person|full'] = $ds_layout;

  return $export;
}
