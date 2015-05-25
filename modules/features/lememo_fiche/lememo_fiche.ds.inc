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
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
      ),
    ),
    'comments' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_cover_image' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_btn_coord' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_share_this' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_legals' => array(
      'weight' => '23',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_block_coord' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_description_long' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'h2',
        ),
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
  $ds_layout->layout = 'lememo_node_display';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'lememo_fiche_cover_image',
      ),
      'header_society_left' => array(
        1 => 'field_logo',
      ),
      'header_society_right' => array(
        2 => 'lememo_fiche_btn_coord',
        3 => 'field_vote',
        4 => 'title',
        5 => 'field_city',
      ),
      'header_sharethis' => array(
        6 => 'lememo_fiche_share_this',
      ),
      'header_resume' => array(
        7 => 'field_description_short',
      ),
      'left' => array(
        8 => 'field_pictures',
        9 => 'field_description_long',
        10 => 'comments',
      ),
      'right' => array(
        11 => 'contact_form',
        14 => 'lememo_fiche_legals',
      ),
      'bottom' => array(
        12 => 'field_position',
        13 => 'lememo_fiche_block_coord',
      ),
    ),
    'fields' => array(
      'lememo_fiche_cover_image' => 'top',
      'field_logo' => 'header_society_left',
      'lememo_fiche_btn_coord' => 'header_society_right',
      'field_vote' => 'header_society_right',
      'title' => 'header_society_right',
      'field_city' => 'header_society_right',
      'lememo_fiche_share_this' => 'header_sharethis',
      'field_description_short' => 'header_resume',
      'field_pictures' => 'left',
      'field_description_long' => 'left',
      'comments' => 'left',
      'contact_form' => 'right',
      'field_position' => 'bottom',
      'lememo_fiche_block_coord' => 'bottom',
      'lememo_fiche_legals' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'header_society_left' => 'div',
      'header_society_right' => 'div',
      'header_sharethis' => 'div',
      'header_resume' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
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
