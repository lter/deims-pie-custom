<?php
/**
 * @file
 * deims_data_set.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function deims_data_set_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_set|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_set';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'data_set_services_links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'map_of_dataset_locations' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|data_set|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_set|gis_layout';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_set';
  $ds_fieldsetting->view_mode = 'gis_layout';
  $ds_fieldsetting->settings = array(
    'data_set_services_links' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'map_of_dataset_locations' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|data_set|gis_layout'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_set|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_set';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|data_set|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function deims_data_set_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_set|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_set';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'map_of_dataset_locations',
        2 => 'data_set_services_links',
        4 => 'field_related_publications',
        5 => 'field_data_sources',
        6 => 'links',
        8 => 'field_related_links',
        11 => 'group_related',
        12 => 'group_downloads',
      ),
      'header' => array(
        1 => 'group_summary',
        22 => 'field_short_name',
        24 => 'field_abstract',
        26 => 'field_doi',
        28 => 'field_data_set_id',
      ),
      'left' => array(
        3 => 'group_categories',
        7 => 'group_dates',
        9 => 'group_people',
        10 => 'field_core_areas',
        13 => 'field_keywords',
        14 => 'field_person_creator',
        15 => 'field_person_contact',
        18 => 'field_taxa_ref',
        20 => 'field_project_roles',
        29 => 'field_date_range',
        30 => 'field_publication_date',
      ),
      'footer' => array(
        16 => 'group_methodology',
        17 => 'field_purpose',
        19 => 'field_methods',
        21 => 'field_instrumentation',
        23 => 'field_maintenance',
        25 => 'field_quality_assurance',
        27 => 'field_additional_information',
      ),
    ),
    'fields' => array(
      'map_of_dataset_locations' => 'right',
      'group_summary' => 'header',
      'data_set_services_links' => 'right',
      'group_categories' => 'left',
      'field_related_publications' => 'right',
      'field_data_sources' => 'right',
      'links' => 'right',
      'group_dates' => 'left',
      'field_related_links' => 'right',
      'group_people' => 'left',
      'field_core_areas' => 'left',
      'group_related' => 'right',
      'group_downloads' => 'right',
      'field_keywords' => 'left',
      'field_person_creator' => 'left',
      'field_person_contact' => 'left',
      'group_methodology' => 'footer',
      'field_purpose' => 'footer',
      'field_taxa_ref' => 'left',
      'field_methods' => 'footer',
      'field_project_roles' => 'left',
      'field_instrumentation' => 'footer',
      'field_short_name' => 'header',
      'field_maintenance' => 'footer',
      'field_abstract' => 'header',
      'field_quality_assurance' => 'footer',
      'field_doi' => 'header',
      'field_additional_information' => 'footer',
      'field_data_set_id' => 'header',
      'field_date_range' => 'left',
      'field_publication_date' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|data_set|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_set|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_set';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_abstract',
        1 => 'field_data_set_id',
        8 => 'field_short_name',
      ),
      'right' => array(
        2 => 'field_project_roles',
        3 => 'field_related_publications',
        9 => 'field_related_links',
        10 => 'field_related_sites',
        13 => 'field_data_sources',
      ),
      'left' => array(
        4 => 'field_core_areas',
        5 => 'field_publication_date',
        6 => 'field_date_range',
        7 => 'field_keywords',
      ),
      'footer' => array(
        11 => 'field_purpose',
        12 => 'field_methods',
        14 => 'field_instrumentation',
        15 => 'field_maintenance',
        16 => 'field_quality_assurance',
        17 => 'field_additional_information',
        18 => 'field_restricted',
      ),
    ),
    'fields' => array(
      'field_abstract' => 'header',
      'field_data_set_id' => 'header',
      'field_project_roles' => 'right',
      'field_related_publications' => 'right',
      'field_core_areas' => 'left',
      'field_publication_date' => 'left',
      'field_date_range' => 'left',
      'field_keywords' => 'left',
      'field_short_name' => 'header',
      'field_related_links' => 'right',
      'field_related_sites' => 'right',
      'field_purpose' => 'footer',
      'field_methods' => 'footer',
      'field_data_sources' => 'right',
      'field_instrumentation' => 'footer',
      'field_maintenance' => 'footer',
      'field_quality_assurance' => 'footer',
      'field_additional_information' => 'footer',
      'field_restricted' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'hide_sidebars' => 1,
  );
  $export['node|data_set|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_set|gis_layout';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_set';
  $ds_layout->view_mode = 'gis_layout';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'group_summary',
        1 => 'field_short_name',
        2 => 'field_abstract',
        5 => 'field_data_sources',
        7 => 'field_doi',
        9 => 'field_data_set_id',
      ),
      'left' => array(
        3 => 'group_categories',
        4 => 'group_dates',
        6 => 'group_people',
        17 => 'field_person_creator',
        18 => 'field_station_keywords_ter',
        19 => 'field_person_contact',
        20 => 'field_gis_section_termref',
        21 => 'field_section',
        22 => 'field_publication_date',
        23 => 'field_date_range',
      ),
      'right' => array(
        8 => 'group_related',
        11 => 'map_of_dataset_locations',
        15 => 'field_related_publications',
      ),
      'footer' => array(
        10 => 'group_downloads',
        12 => 'group_methodology',
        13 => 'links',
        14 => 'data_set_services_links',
        16 => 'field_additional_information',
        24 => 'field_methods',
      ),
    ),
    'fields' => array(
      'group_summary' => 'header',
      'field_short_name' => 'header',
      'field_abstract' => 'header',
      'group_categories' => 'left',
      'group_dates' => 'left',
      'field_data_sources' => 'header',
      'group_people' => 'left',
      'field_doi' => 'header',
      'group_related' => 'right',
      'field_data_set_id' => 'header',
      'group_downloads' => 'footer',
      'map_of_dataset_locations' => 'right',
      'group_methodology' => 'footer',
      'links' => 'footer',
      'data_set_services_links' => 'footer',
      'field_related_publications' => 'right',
      'field_additional_information' => 'footer',
      'field_person_creator' => 'left',
      'field_station_keywords_ter' => 'left',
      'field_person_contact' => 'left',
      'field_gis_section_termref' => 'left',
      'field_section' => 'left',
      'field_publication_date' => 'left',
      'field_date_range' => 'left',
      'field_methods' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|data_set|gis_layout'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_set|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_set';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_doi',
        2 => 'field_data_set_id',
        3 => 'field_abstract',
        4 => 'field_publication_date',
        5 => 'field_date_range',
        6 => 'field_core_areas',
        7 => 'field_keywords',
        8 => 'field_related_sites',
        9 => 'field_data_sources',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_doi' => 'ds_content',
      'field_data_set_id' => 'ds_content',
      'field_abstract' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'field_date_range' => 'ds_content',
      'field_core_areas' => 'ds_content',
      'field_keywords' => 'ds_content',
      'field_related_sites' => 'ds_content',
      'field_data_sources' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'hide_sidebars' => 0,
  );
  $export['node|data_set|search_result'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function deims_data_set_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'gis_layout';
  $ds_view_mode->label = 'GIS Layout';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['gis_layout'] = $ds_view_mode;

  return $export;
}
