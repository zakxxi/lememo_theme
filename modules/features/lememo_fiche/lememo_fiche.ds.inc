<?php
/**
 * @file
 * lememo_fiche.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function lememo_fiche_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|fiche|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'fiche';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'contact_form' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
      ),
    ),
  );
  $export['node|fiche|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function lememo_fiche_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_form';
  $ds_field->label = 'Contact form';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'fiche|full';
  $ds_field->properties = array(
    'block' => 'lememo_fiche|contact_site',
    'block_render' => '3',
  );
  $export['contact_form'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function lememo_fiche_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|fiche|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'fiche';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_cover',
        1 => 'field_logo',
        2 => 'title',
        3 => 'field_city',
        4 => 'field_code_postal',
      ),
      'left' => array(
        5 => 'field_description_short',
        6 => 'field_pictures',
        7 => 'field_description_long',
      ),
      'right' => array(
        8 => 'contact_form',
        9 => 'field_siret',
        10 => 'field_tva',
      ),
      'footer' => array(
        11 => 'field_company',
        12 => 'field_position',
      ),
    ),
    'fields' => array(
      'field_cover' => 'header',
      'field_logo' => 'header',
      'title' => 'header',
      'field_city' => 'header',
      'field_code_postal' => 'header',
      'field_description_short' => 'left',
      'field_pictures' => 'left',
      'field_description_long' => 'left',
      'contact_form' => 'right',
      'field_siret' => 'right',
      'field_tva' => 'right',
      'field_company' => 'footer',
      'field_position' => 'footer',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|fiche|full'] = $ds_layout;

  return $export;
}
