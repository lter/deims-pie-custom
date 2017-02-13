<?php
/**
 * @file
 * pie_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pie_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Estuary Water Column';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_coordinates';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'title_1';
  $handler->display->display_options['style_options']['map'] = 'google-satellite';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_sites_target_id']['id'] = 'field_related_sites_target_id';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['table'] = 'field_data_field_related_sites';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['field'] = 'field_related_sites_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_coordinates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<p/><br/>

Description: [field_description] <p/>

<p>Dataset :<a href="/node/[nid]"> [title_1]</a> </p>';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Locations';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_coordinates';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'title_1';
  $handler->display->display_options['style_options']['view_mode'] = 'teaser';
  $handler->display->display_options['style_options']['map'] = 'google-satellite';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['id'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['field'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_coordinates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coordinates']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'centroid',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_wrapper_type'] = 'div';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_related_sites_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<p/><br/>

Description: [field_description] <p/>

<p>Dataset :<a href="/node/[nid]"> [title_1]</a> </p>';
  $handler->display->display_options['fields']['title_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  $handler->display->display_options['path'] = 'all-locations';

  /* Display: Watersheds */
  $handler = $view->new_display('page', 'Watersheds', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Watersheds';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    768 => '768',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'watershed-map';

  /* Display: Estuary Water Column */
  $handler = $view->new_display('page', 'Estuary Water Column', 'page_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    770 => '770',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'estuary-water-column-map';

  /* Display: All Locations */
  $handler = $view->new_display('page', 'All Locations', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Locations';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_sites_target_id']['id'] = 'field_related_sites_target_id';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['table'] = 'field_data_field_related_sites';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['field'] = 'field_related_sites_target_id';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Research Site';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_related_sites_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
    'research_site' => 'research_site',
  );
  $handler->display->display_options['path'] = 'locations-map';

  /* Display: Benthic Processes */
  $handler = $view->new_display('page', 'Benthic Processes', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Benthic Processes';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['id'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['field'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    771 => '771',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'benthic-map';

  /* Display: Consumers */
  $handler = $view->new_display('page', 'Consumers', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Consumers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    883 => '883',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'consumers-map';

  /* Display: Marsh */
  $handler = $view->new_display('page', 'Marsh', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Marsh';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    769 => '769',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'marsh-map';

  /* Display: Long Term Experiments */
  $handler = $view->new_display('page', 'Long Term Experiments', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Long Term Experiments';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    773 => '773',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'long-term-experiments-map';

  /* Display: Short Term Projects */
  $handler = $view->new_display('page', 'Short Term Projects', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Short Term Projects';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    774 => '774',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'short-term-projects-map';

  /* Display: Climate */
  $handler = $view->new_display('page', 'Climate', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Climate';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    776 => '776',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'climate-map';

  /* Display: Estuarine Physics */
  $handler = $view->new_display('page', 'Estuarine Physics', 'page_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Estuarine Physics';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    777 => '777',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'estuarine-physics-map';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Locations';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_coordinates' => 'field_coordinates',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_coordinates' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Location Title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['relationship'] = 'field_related_sites_target_id';
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  $handler->display->display_options['path'] = 'all-locations-as-list';

  /* Display: datasets-with-locations */
  $handler = $view->new_display('page', 'datasets-with-locations', 'page_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Test Locations through Dataset Query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_coordinates';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['map'] = 'google-satellite';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['relationship'] = 'field_related_sites_target_id';
  $handler->display->display_options['fields']['field_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_coordinates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
    'research_site' => 'research_site',
  );
  $handler->display->display_options['path'] = 'all-locations-upsidedown';
  $export['all_locations'] = $view;

  $view = new view();
  $view->name = 'biblio_authors_to_people';
  $view->description = 'Views for showing and administrating relationships between biblio authors and the people content type.';
  $view->tag = 'default';
  $view->base_table = 'biblio_contributor_data';
  $view->human_name = 'Biblio Authors to People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Biblio Authors to People';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
    'name' => 'name',
    'prefix' => 'name',
    'suffix' => 'name',
    'field_name' => 'field_name',
    'field_email' => 'field_email',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'prefix' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'suffix' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_associated_biblio_author_node']['id'] = 'reverse_field_associated_biblio_author_node';
  $handler->display->display_options['relationships']['reverse_field_associated_biblio_author_node']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['relationships']['reverse_field_associated_biblio_author_node']['field'] = 'reverse_field_associated_biblio_author_node';
  /* Field: Biblio: Author id */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  /* Field: Biblio: Author full name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Biblio: Author preix */
  $handler->display->display_options['fields']['prefix']['id'] = 'prefix';
  $handler->display->display_options['fields']['prefix']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['fields']['prefix']['field'] = 'prefix';
  $handler->display->display_options['fields']['prefix']['label'] = '';
  $handler->display->display_options['fields']['prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['prefix']['hide_empty'] = TRUE;
  /* Field: Biblio: Author suffix */
  $handler->display->display_options['fields']['suffix']['id'] = 'suffix';
  $handler->display->display_options['fields']['suffix']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['fields']['suffix']['field'] = 'suffix';
  $handler->display->display_options['fields']['suffix']['label'] = '';
  $handler->display->display_options['fields']['suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['suffix']['hide_alter_empty'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['relationship'] = 'reverse_field_associated_biblio_author_node';
  $handler->display->display_options['fields']['field_name']['label'] = 'Person Name';
  $handler->display->display_options['fields']['field_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_name']['settings'] = array(
    'format' => 'default',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['relationship'] = 'reverse_field_associated_biblio_author_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_associated_biblio_author_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_person_title']['id'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['table'] = 'field_data_field_person_title';
  $handler->display->display_options['fields']['field_person_title']['field'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['relationship'] = 'reverse_field_associated_biblio_author_node';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'biblio-authors-to-people';
  $export['biblio_authors_to_people'] = $view;

  $view = new view();
  $view->name = 'bulk_data_set_updates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bulk Data Set Updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bulk Data Set Updates: Keywords';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_core_areas' => 'field_core_areas',
    'field_station_keywords_ter' => 'field_station_keywords_ter',
    'title_1' => 'title_1',
    'field_short_name' => 'field_short_name',
  );
  $handler->display->display_options['style_options']['default'] = 'title_1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_core_areas' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_station_keywords_ter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_short_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_data_sources_target_id']['id'] = 'field_data_sources_target_id';
  $handler->display->display_options['relationships']['field_data_sources_target_id']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['relationships']['field_data_sources_target_id']['field'] = 'field_data_sources_target_id';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'data_set::field_core_areas' => 'data_set::field_core_areas',
          'data_set::field_station_keywords_ter' => 'data_set::field_station_keywords_ter',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Data';
  /* Field: Content: Short name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );

  /* Display: Core Areas + PIE Res. Areas */
  $handler = $view->new_display('page', 'Core Areas + PIE Res. Areas', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bulk Data Set Updates: Core and PIE Research Area Keywords';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'data_set::field_core_areas' => 'data_set::field_core_areas',
          'data_set::field_station_keywords_ter' => 'data_set::field_station_keywords_ter',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Data';
  /* Field: Content: Short name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['path'] = 'admin/bulk-data-set-update-core-and-research-areas';

  /* Display: Keywords */
  $handler = $view->new_display('page', 'Keywords', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'data_set::field_keywords' => 'data_set::field_keywords',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Data';
  /* Field: Content: Short name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['path'] = 'admin/bulk-data-set-keyword-updates';

  /* Display: Research site */
  $handler = $view->new_display('page', 'Research site', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bulk Data Set Updates: Research site';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'data_set::field_related_sites' => 'data_set::field_related_sites',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Data';
  /* Field: Content: Related sites */
  $handler->display->display_options['fields']['field_related_sites']['id'] = 'field_related_sites';
  $handler->display->display_options['fields']['field_related_sites']['table'] = 'field_data_field_related_sites';
  $handler->display->display_options['fields']['field_related_sites']['field'] = 'field_related_sites';
  $handler->display->display_options['fields']['field_related_sites']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_related_sites']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'admin/bulk-data-set-research-site-updates';
  $export['bulk_data_set_updates'] = $view;

  $view = new view();
  $view->name = 'bulk_research_area_updates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bulk Research Area Updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bulk Data Set Updates: Keywords';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_core_areas' => 'field_core_areas',
    'field_station_keywords_ter' => 'field_station_keywords_ter',
    'title_1' => 'title_1',
    'field_short_name' => 'field_short_name',
  );
  $handler->display->display_options['style_options']['default'] = 'title_1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_core_areas' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_station_keywords_ter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_short_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'data_set::field_core_areas' => 'data_set::field_core_areas',
          'data_set::field_station_keywords_ter' => 'data_set::field_station_keywords_ter',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_station_keywords_termref']['id'] = 'field_station_keywords_termref';
  $handler->display->display_options['fields']['field_station_keywords_termref']['table'] = 'field_data_field_station_keywords_termref';
  $handler->display->display_options['fields']['field_station_keywords_termref']['field'] = 'field_station_keywords_termref';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );

  /* Display: Research site and areas */
  $handler = $view->new_display('page', 'Research site and areas', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bulk Data Set Updates: Research site';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'research_site::field_core_areas' => 'research_site::field_core_areas',
          'research_site::field_station_keywords_ter' => 'research_site::field_station_keywords_ter',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_site' => 'research_site',
  );
  $handler->display->display_options['path'] = 'admin/bulk-research-site-areas-updates';
  $export['bulk_research_area_updates'] = $view;

  $view = new view();
  $view->name = 'data_set_services_icon_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data Set Services Icon Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Set Services Icon Block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/%1/eml"><img src="/profiles/deims/modules/custom/eml/eml.png" /></a>
<a href="/node/%1/bdp"><img src="/profiles/deims/modules/custom/bdp/bdp.png" /></a>
<a href="/node/%1/iso"><img src="/profiles/deims/modules/custom/iso/iso.gif" /></a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['data_set_services_icon_block'] = $view;

  $view = new view();
  $view->name = 'data_sets_by_research_areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data Sets By Research Areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Sets By Research Areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_data_source_file' => 'field_data_source_file',
    'title' => 'title',
    'field_person_creator' => 'field_person_creator',
    'field_date_range' => 'field_date_range',
    'field_core_areas' => 'field_core_areas',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_data_source_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_person_creator' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_range' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_areas' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['elements'] = array(
    'search_box' => 1,
    'table_info' => 1,
    'save_state' => 0,
    'table_tools' => 0,
  );
  $handler->display->display_options['style_options']['layout'] = array(
    'autowidth' => 0,
    'themeroller' => 0,
    'sdom' => '',
  );
  $handler->display->display_options['style_options']['pages'] = array(
    'pagination_style' => '0',
    'length_change' => 0,
    'display_length' => '100',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_data_sources_target_id']['id'] = 'field_data_sources_target_id';
  $handler->display->display_options['relationships']['field_data_sources_target_id']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['relationships']['field_data_sources_target_id']['field'] = 'field_data_sources_target_id';
  /* Field: Content: File upload */
  $handler->display->display_options['fields']['field_data_source_file']['id'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['table'] = 'field_data_field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['field'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['label'] = 'Data';
  $handler->display->display_options['fields']['field_data_source_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_data_source_file']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_data_source_file']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Owner/Creator */
  $handler->display->display_options['fields']['field_person_creator']['id'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['table'] = 'field_data_field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['field'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['label'] = 'Principal Investigator';
  $handler->display->display_options['fields']['field_person_creator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_creator']['delta_offset'] = '0';
  /* Field: Content: Date Range */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['settings'] = array(
    'format_type' => 'eml_yeardate',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['label'] = '';
  $handler->display->display_options['fields']['field_station_keywords_ter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_station_keywords_ter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_station_keywords_ter']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = '';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'page');
  $handler->display->display_options['path'] = 'data-sets-by-research-areas';

  /* Display: Watershed */
  $handler = $view->new_display('page', 'Watershed', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Watershed';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: File upload */
  $handler->display->display_options['fields']['field_data_source_file']['id'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['table'] = 'field_data_field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['field'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['field_data_source_file']['label'] = 'Data';
  $handler->display->display_options['fields']['field_data_source_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_data_source_file']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_data_source_file']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Owner/Creator */
  $handler->display->display_options['fields']['field_person_creator']['id'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['table'] = 'field_data_field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['field'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['label'] = 'Principal Investigator';
  $handler->display->display_options['fields']['field_person_creator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_creator']['delta_offset'] = '0';
  /* Field: Content: Date Range */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['settings'] = array(
    'format_type' => 'eml_yeardate',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '768',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'data/watersheds';

  /* Display: Estuarine Physics */
  $handler = $view->new_display('page', 'Estuarine Physics', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Estuarine Physics';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: File upload */
  $handler->display->display_options['fields']['field_data_source_file']['id'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['table'] = 'field_data_field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['field'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['field_data_source_file']['label'] = 'Data';
  $handler->display->display_options['fields']['field_data_source_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_data_source_file']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_data_source_file']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Owner/Creator */
  $handler->display->display_options['fields']['field_person_creator']['id'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['table'] = 'field_data_field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['field'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['label'] = 'Principal Investigator';
  $handler->display->display_options['fields']['field_person_creator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_creator']['delta_offset'] = '0';
  /* Field: Content: Date Range */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['settings'] = array(
    'format_type' => 'eml_yeardate',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '777',
    1 => '770',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'data/estuary-physics';

  /* Display: Marsh */
  $handler = $view->new_display('page', 'Marsh', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Marsh';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: File upload */
  $handler->display->display_options['fields']['field_data_source_file']['id'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['table'] = 'field_data_field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['field'] = 'field_data_source_file';
  $handler->display->display_options['fields']['field_data_source_file']['relationship'] = 'field_data_sources_target_id';
  $handler->display->display_options['fields']['field_data_source_file']['label'] = 'Data';
  $handler->display->display_options['fields']['field_data_source_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_data_source_file']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_data_source_file']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Owner/Creator */
  $handler->display->display_options['fields']['field_person_creator']['id'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['table'] = 'field_data_field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['field'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['label'] = 'Principal Investigator';
  $handler->display->display_options['fields']['field_person_creator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_creator']['delta_offset'] = '0';
  /* Field: Content: Date Range */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['settings'] = array(
    'format_type' => 'eml_yeardate',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Core Areas */
  $handler->display->display_options['fields']['field_core_areas']['id'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['table'] = 'field_data_field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['field'] = 'field_core_areas';
  $handler->display->display_options['fields']['field_core_areas']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_areas']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '769',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'station_keywords';
  $handler->display->display_options['path'] = 'data/marsh';
  $export['data_sets_by_research_areas'] = $view;

  $view = new view();
  $view->name = 'dataset_packageid';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'dataset-packageId';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dataset-packageId';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_data_set_id' => 'field_data_set_id',
    'field_eml_revision_id' => 'field_eml_revision_id',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_data_set_id';
  $handler->display->display_options['style_options']['info'] = array(
    'field_data_set_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_eml_revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Field: Content: Data set ID */
  $handler->display->display_options['fields']['field_data_set_id']['id'] = 'field_data_set_id';
  $handler->display->display_options['fields']['field_data_set_id']['table'] = 'field_data_field_data_set_id';
  $handler->display->display_options['fields']['field_data_set_id']['field'] = 'field_data_set_id';
  $handler->display->display_options['fields']['field_data_set_id']['type'] = 'text_plain';
  /* Field: Content: EML revision ID */
  $handler->display->display_options['fields']['field_eml_revision_id']['id'] = 'field_eml_revision_id';
  $handler->display->display_options['fields']['field_eml_revision_id']['table'] = 'field_data_field_eml_revision_id';
  $handler->display->display_options['fields']['field_eml_revision_id']['field'] = 'field_eml_revision_id';
  $handler->display->display_options['fields']['field_eml_revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '55';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Short name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_person_contact']['id'] = 'field_person_contact';
  $handler->display->display_options['fields']['field_person_contact']['table'] = 'field_data_field_person_contact';
  $handler->display->display_options['fields']['field_person_contact']['field'] = 'field_person_contact';
  $handler->display->display_options['fields']['field_person_contact']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_contact']['delta_offset'] = '0';
  /* Field: Content: Data sources */
  $handler->display->display_options['fields']['field_data_sources']['id'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['table'] = 'field_data_field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['field'] = 'field_data_sources';
  $handler->display->display_options['fields']['field_data_sources']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_data_sources']['delta_offset'] = '0';
  /* Field: Content: Date Range */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Owner/Creator */
  $handler->display->display_options['fields']['field_person_creator']['id'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['table'] = 'field_data_field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['field'] = 'field_person_creator';
  $handler->display->display_options['fields']['field_person_creator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_person_creator']['delta_offset'] = '0';
  /* Field: Content: Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataset-packageid';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'dataset-packageid-csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['dataset_packageid'] = $view;

  $view = new view();
  $view->name = 'datasets_for_given_location';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Datasets for given location';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Datasets for given location';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['id'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_related_sites_node']['field'] = 'reverse_field_related_sites_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_related_sites_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['datasets_for_given_location'] = $view;

  $view = new view();
  $view->name = 'directory';
  $view->description = 'Listing of all people associated with the LTER.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Investigators';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['cache']['results_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['keys'] = array(
    'node' => array(
      'person' => 'person',
      'article' => 0,
      'page' => 0,
      'biblio' => 0,
      'data_set' => 0,
      'data_source' => 0,
      'image_gallery' => 0,
      'organization' => 0,
      'project' => 0,
      'research_site' => 0,
    ),
    'node_only' => array(
      'node_changed' => 'node_changed',
    ),
  );
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_images' => 'field_images',
    'title' => 'title',
    'field_person_role' => 'field_person_role',
    'field_email' => 'field_email',
    'field_organization' => 'field_organization',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_images' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => 'priority-low',
    ),
    'field_person_role' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => 'priority-low',
    ),
    'field_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => 'priority-medium',
    ),
    'field_organization' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_person_role']['id'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['fields']['field_person_role']['field'] = 'field_person_role';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'invisimail_js_entities';
  $handler->display->display_options['fields']['field_email']['settings'] = array(
    'chunk' => 0,
    'link' => 1,
  );
  /* Sort criterion: Content: Name (field_name:given) */
  $handler->display->display_options['sorts']['field_name_given']['id'] = 'field_name_given';
  $handler->display->display_options['sorts']['field_name_given']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_given']['field'] = 'field_name_given';
  $handler->display->display_options['sorts']['field_name_given']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_name_given']['expose']['label'] = 'First Name';
  /* Sort criterion: Content: Name (field_name:family) */
  $handler->display->display_options['sorts']['field_name_family']['id'] = 'field_name_family';
  $handler->display->display_options['sorts']['field_name_family']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_family']['field'] = 'field_name_family';
  $handler->display->display_options['sorts']['field_name_family']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_name_family']['expose']['label'] = 'Last Name';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Lead PIs */
  $handler = $view->new_display('page', 'Lead PIs', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Principal Investigators';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_person_role']['id'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['fields']['field_person_role']['field'] = 'field_person_role';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
    'COPI' => 'COPI',
    'PI' => 'PI',
  );
  $handler->display->display_options['path'] = 'principal-investigators';

  /* Display: Researchers */
  $handler = $view->new_display('page', 'Researchers', 'people_researchers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Researchers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
    'COPI' => 'COPI',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'people/researchers';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Researchers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Investigators */
  $handler = $view->new_display('page', 'Investigators', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Investigators';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'FA' => 'FA',
  );
  $handler->display->display_options['path'] = 'investigators';

  /* Display: Post-docs */
  $handler = $view->new_display('page', 'Post-docs', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Post Docs';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'PDA' => 'PDA',
  );
  $handler->display->display_options['path'] = 'post-docs';

  /* Display: Grads */
  $handler = $view->new_display('page', 'Grads', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Graduate Students';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'GS' => 'GS',
  );
  $handler->display->display_options['path'] = 'graduate-students';

  /* Display: undergrads */
  $handler = $view->new_display('page', 'undergrads', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduates';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['path'] = 'undergraduates';

  /* Display: tech-staff */
  $handler = $view->new_display('page', 'tech-staff', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Technical and Professional Staff';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'OS' => 'OS',
    'SC' => 'SC',
    'DA' => 'DA',
  );
  $handler->display->display_options['path'] = 'technical-and-staff';

  /* Display: All People - stack blocks below  */
  $handler = $view->new_display('page', 'All People - stack blocks below ', 'page_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Plum Island Ecosystems LTER Personnel';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['cache']['results_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['keys'] = array(
    'node' => array(
      'person' => 'person',
      'article' => 0,
      'page' => 0,
      'biblio' => 0,
      'data_set' => 0,
      'data_source' => 0,
      'image_gallery' => 0,
      'organization' => 0,
      'project' => 0,
      'research_site' => 0,
    ),
    'node_only' => array(
      'node_changed' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Browse here the personnel directory, grouped by roles in the PIE LTER program. For individual groups, please use the submenu links.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'plum-island-ecosystems-lter-personnel';

  /* Display: Block Investigators */
  $handler = $view->new_display('block', 'Block Investigators', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'FA' => 'FA',
  );
  $handler->display->display_options['block_description'] = 'Directory Investigators';

  /* Display: Block GS */
  $handler = $view->new_display('block', 'Block GS', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Graduate Students';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'invisimail_js_entities';
  $handler->display->display_options['fields']['field_email']['settings'] = array(
    'chunk' => 0,
    'link' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'GS' => 'GS',
  );
  $handler->display->display_options['block_description'] = 'Directory Grad Students';

  /* Display: Block US */
  $handler = $view->new_display('block', 'Block US', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Students';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'invisimail_js_entities';
  $handler->display->display_options['fields']['field_email']['settings'] = array(
    'chunk' => 0,
    'link' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['block_description'] = 'Directory undergrad Students';

  /* Display: Block TPS */
  $handler = $view->new_display('block', 'Block TPS', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Technical and Professional Staff';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'invisimail_js_entities';
  $handler->display->display_options['fields']['field_email']['settings'] = array(
    'chunk' => 0,
    'link' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'OP' => 'OP',
    'SC' => 'SC',
    'DA' => 'DA',
  );
  $handler->display->display_options['block_description'] = 'Directory tech-profs staff';

  /* Display: Grouped By Role */
  $handler = $view->new_display('page', 'Grouped By Role', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_person_role',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_images' => 'field_images',
    'title' => 'title',
    'field_person_role' => 'field_person_role',
    'field_email' => 'field_email',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_images' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_person_role' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => 'priority-low',
    ),
    'field_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => 'priority-medium',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_person_role']['id'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['fields']['field_person_role']['field'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['label'] = '';
  $handler->display->display_options['fields']['field_person_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Address - Postal code */
  $handler->display->display_options['sorts']['field_address_postal_code']['id'] = 'field_address_postal_code';
  $handler->display->display_options['sorts']['field_address_postal_code']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_postal_code']['field'] = 'field_address_postal_code';
  $handler->display->display_options['sorts']['field_address_postal_code']['order'] = 'DESC';
  /* Sort criterion: Content: Name (field_name:family) */
  $handler->display->display_options['sorts']['field_name_family']['id'] = 'field_name_family';
  $handler->display->display_options['sorts']['field_name_family']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_family']['field'] = 'field_name_family';
  $handler->display->display_options['sorts']['field_name_family']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_name_family']['expose']['label'] = 'Last Name';
  /* Sort criterion: Content: Name (field_name:given) */
  $handler->display->display_options['sorts']['field_name_given']['id'] = 'field_name_given';
  $handler->display->display_options['sorts']['field_name_given']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_given']['field'] = 'field_name_given';
  $handler->display->display_options['sorts']['field_name_given']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_name_given']['expose']['label'] = 'First Name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'person-roles';

  /* Display: Attach-INV */
  $handler = $view->new_display('attachment', 'Attach-INV', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'FA' => 'FA',
  );
  $handler->display->display_options['displays'] = array(
    'page_10' => 'page_10',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'people_researchers' => 0,
    'page_4' => 0,
    'page_3' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_2' => 0,
    'page_7' => 0,
    'page_8' => 0,
    'page_9' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attach-TPS */
  $handler = $view->new_display('attachment', 'Attach-TPS', 'attachment_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Technical and Professional Staff';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'OS' => 'OS',
    'SC' => 'SC',
    'DA' => 'DA',
  );
  $handler->display->display_options['displays'] = array(
    'page_10' => 'page_10',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'people_researchers' => 0,
    'page_4' => 0,
    'page_3' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_2' => 0,
    'page_7' => 0,
    'page_8' => 0,
    'page_9' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attach-US */
  $handler = $view->new_display('attachment', 'Attach-US', 'attachment_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Students';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['displays'] = array(
    'page_10' => 'page_10',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'people_researchers' => 0,
    'page_4' => 0,
    'page_3' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_2' => 0,
    'page_7' => 0,
    'page_8' => 0,
    'page_9' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attach-GS */
  $handler = $view->new_display('attachment', 'Attach-GS', 'attachment_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Graduate Students';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'GS' => 'GS',
  );
  $handler->display->display_options['displays'] = array(
    'page_10' => 'page_10',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'people_researchers' => 0,
    'page_4' => 0,
    'page_3' => 0,
    'page_5' => 0,
    'page_6' => 0,
    'page_2' => 0,
    'page_7' => 0,
    'page_8' => 0,
    'page_9' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: All Attached */
  $handler = $view->new_display('page', 'All Attached', 'page_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Primary Investigators';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
    'COPI' => 'COPI',
    'PI' => 'PI',
  );
  $handler->display->display_options['path'] = 'mcmurdo-lter-directory';

  /* Display: Block PD */
  $handler = $view->new_display('block', 'Block PD', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Post Doctoral Associates';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'PDA' => 'PDA',
  );
  $handler->display->display_options['block_description'] = 'Directory Post Docs';

  /* Display: Block PIs */
  $handler = $view->new_display('block', 'Block PIs', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Principal Investigators';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'COPI' => 'COPI',
  );
  $handler->display->display_options['block_description'] = 'Directory Principal Investigators';

  /* Display: Block Lead PI */
  $handler = $view->new_display('block', 'Block Lead PI', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Lead Principal Investigator';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
  );
  $handler->display->display_options['block_description'] = 'Directory Lead Principal Investigators';

  /* Display: People for blocks */
  $handler = $view->new_display('page', 'People for blocks', 'page_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Principal Investigators';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'views_content_cache';
  $handler->display->display_options['cache']['results_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_min_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_max_lifespan'] = '518400';
  $handler->display->display_options['cache']['keys'] = array(
    'node' => array(
      'person' => 'person',
      'article' => 0,
      'page' => 0,
      'biblio' => 0,
      'data_set' => 0,
      'data_source' => 0,
      'image_gallery' => 0,
      'organization' => 0,
      'project' => 0,
      'research_site' => 0,
    ),
    'node_only' => array(
      'node_changed' => 0,
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: List in Directory (field_list_in_directory) */
  $handler->display->display_options['filters']['field_list_in_directory_value']['id'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['table'] = 'field_data_field_list_in_directory';
  $handler->display->display_options['filters']['field_list_in_directory_value']['field'] = 'field_list_in_directory_value';
  $handler->display->display_options['filters']['field_list_in_directory_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name']['expose']['operator_id'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_name']['expose']['operator'] = 'field_name_op';
  $handler->display->display_options['filters']['field_name']['expose']['identifier'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_value']['id'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_value']['field'] = 'field_person_role_value';
  $handler->display->display_options['filters']['field_person_role_value']['value'] = array(
    'LPI' => 'LPI',
    'COPI' => 'COPI',
    'PI' => 'PI',
  );
  $handler->display->display_options['path'] = 'pie-lter-personnel-legacy';
  $export['directory'] = $view;

  $view = new view();
  $view->name = 'entity_reference_selection_project_role';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_project_role';
  $view->human_name = 'Entity reference selection: project role';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Project role: Person */
  $handler->display->display_options['fields']['field_related_person']['id'] = 'field_related_person';
  $handler->display->display_options['fields']['field_related_person']['table'] = 'field_data_field_related_person';
  $handler->display->display_options['fields']['field_related_person']['field'] = 'field_related_person';
  $handler->display->display_options['fields']['field_related_person']['label'] = '';
  $handler->display->display_options['fields']['field_related_person']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_person']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_person']['settings'] = array(
    'link' => 0,
  );
  /* Field: Project role: Role */
  $handler->display->display_options['fields']['field_project_role']['id'] = 'field_project_role';
  $handler->display->display_options['fields']['field_project_role']['table'] = 'field_data_field_project_role';
  $handler->display->display_options['fields']['field_project_role']['field'] = 'field_project_role';
  $handler->display->display_options['fields']['field_project_role']['label'] = '';
  $handler->display->display_options['fields']['field_project_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_role']['element_default_classes'] = FALSE;
  /* Sort criterion: Project role: Person (field_related_person) */
  $handler->display->display_options['sorts']['field_related_person_target_id']['id'] = 'field_related_person_target_id';
  $handler->display->display_options['sorts']['field_related_person_target_id']['table'] = 'field_data_field_related_person';
  $handler->display->display_options['sorts']['field_related_person_target_id']['field'] = 'field_related_person_target_id';
  /* Sort criterion: Project role: Role (field_project_role) */
  $handler->display->display_options['sorts']['field_project_role_value']['id'] = 'field_project_role_value';
  $handler->display->display_options['sorts']['field_project_role_value']['table'] = 'field_data_field_project_role';
  $handler->display->display_options['sorts']['field_project_role_value']['field'] = 'field_project_role_value';

  /* Display: Project roles */
  $handler = $view->new_display('entityreference', 'Project roles', 'entityreference_default');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_related_person' => 'field_related_person',
    'field_project_role' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Default project roles */
  $handler = $view->new_display('entityreference', 'Default project roles', 'entityreference_default_values');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_related_person' => 'field_related_person',
    'field_project_role' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_default_value']['id'] = 'field_default_value';
  $handler->display->display_options['filters']['field_default_value']['table'] = 'field_data_field_default';
  $handler->display->display_options['filters']['field_default_value']['field'] = 'field_default_value';
  $handler->display->display_options['filters']['field_default_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_default_value']['value'] = array(
    0 => '0',
  );
  $export['entity_reference_selection_project_role'] = $view;

  $view = new view();
  $view->name = 'gis_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GIS Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'GIS Data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    786 => '786',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;

  /* Display: GIS Master Page */
  $handler = $view->new_display('page', 'GIS Master Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_station_keywords_ter',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_station_keywords_ter' => 'field_station_keywords_ter',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_station_keywords_ter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Explanation of GIS';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: PIE Research Areas */
  $handler->display->display_options['fields']['field_station_keywords_ter']['id'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['table'] = 'field_data_field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['field'] = 'field_station_keywords_ter';
  $handler->display->display_options['fields']['field_station_keywords_ter']['label'] = '';
  $handler->display->display_options['fields']['field_station_keywords_ter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_station_keywords_ter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_station_keywords_ter']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    786 => '786',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-data';

  /* Display: GIS Census Data */
  $handler = $view->new_display('page', 'GIS Census Data', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Census Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    790 => '790',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-census-data';

  /* Display: GIS Land Cover */
  $handler = $view->new_display('page', 'GIS Land Cover', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Land Cover Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    793 => '793',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-land-cover-data';

  /* Display: GIS Parcels */
  $handler = $view->new_display('page', 'GIS Parcels', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Parcels Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    791 => '791',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-parcels-data';

  /* Display: GIS Zoning */
  $handler = $view->new_display('page', 'GIS Zoning', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Zoning Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    792 => '792',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-zoning-data';

  /* Display: GIS Boundaries */
  $handler = $view->new_display('page', 'GIS Boundaries', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Boundaries Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    789 => '789',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-boundaries-data';

  /* Display: GIS Elev-Bathym */
  $handler = $view->new_display('page', 'GIS Elev-Bathym', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Elevation and Bathymetry Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    788 => '788',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-elevation-bathymetry-data';

  /* Display: GIS Land Use */
  $handler = $view->new_display('page', 'GIS Land Use', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'GIS Land Use Data';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data_set' => 'data_set',
  );
  /* Filter criterion: Content: Section (field_section) */
  $handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['filters']['field_section_tid']['value'] = array(
    787 => '787',
  );
  $handler->display->display_options['filters']['field_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
  $handler->display->display_options['filters']['field_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'gis-land-use-data';
  $export['gis_data'] = $view;

  $view = new view();
  $view->name = 'map_of_dataset_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Map of Dataset Locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map of Dataset Locations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_coordinates';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'title';
  $handler->display->display_options['style_options']['map'] = 'google-satellite';
  $handler->display->display_options['style_options']['height'] = '480';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '6';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_sites_target_id']['id'] = 'field_related_sites_target_id';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['table'] = 'field_data_field_related_sites';
  $handler->display->display_options['relationships']['field_related_sites_target_id']['field'] = 'field_related_sites_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_sites_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['relationship'] = 'field_related_sites_target_id';
  $handler->display->display_options['fields']['field_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_coordinates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'full',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['map_of_dataset_locations'] = $view;

  $view = new view();
  $view->name = 'slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_images' => 0,
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_images' => 0,
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'flexslider_full',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div id="transparency"></div><div id="homeslidecontent"><h2>[title]</h2></div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'banner' => 'banner',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: new slide Block */
  $handler = $view->new_display('block', 'new slide Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'banner_500w',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_related_links']['id'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['table'] = 'field_data_field_related_links';
  $handler->display->display_options['fields']['field_related_links']['field'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['label'] = '';
  $handler->display->display_options['fields']['field_related_links']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_links']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_related_links']['alter']['text'] = '<a href=[field_related_links-url]>[title]</a>';
  $handler->display->display_options['fields']['field_related_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_related_links']['type'] = 'link_url';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div id="transparency"></div><div id="homeslidecontent"><h2>[field_related_links] </h2><p>[body-summary] </p></div>';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $export['slideshow'] = $view;

  return $export;
}
