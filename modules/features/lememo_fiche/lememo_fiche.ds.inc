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
  $ds_fieldsetting->id = 'comment|comment_node_fiche|full';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_fiche';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['comment|comment_node_fiche|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|fiche|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'fiche';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'vote_bis' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:26:"fivestar_formatter_default";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:4:{s:6:"widget";a:1:{s:15:"fivestar_widget";s:7:"default";}s:5:"style";s:7:"average";s:4:"text";s:7:"average";s:6:"expose";i:1;}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:1;s:19:"override_title_text";s:18:"Attribuer une note";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:15:"node:field_vote";}',
        'load_terms' => 0,
        'ft' => array(),
      ),
    ),
    'contact_form' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
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
      'weight' => '11',
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
    'lememo_fiche_add_this' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_legals' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_block_coord' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'lememo_fiche_block_gallery' => array(
      'weight' => '9',
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
    'field_mail' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
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

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vote_bis';
  $ds_field->label = 'vote-bis';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['vote_bis'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function lememo_fiche_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_fiche|full';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_fiche';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'lememo_comments_display';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'author',
      ),
      'right' => array(
        1 => 'comment_body',
      ),
    ),
    'fields' => array(
      'author' => 'left',
      'comment_body' => 'right',
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
  );
  $export['comment|comment_node_fiche|full'] = $ds_layout;

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
        6 => 'field_phone_1',
      ),
      'header_addthis' => array(
        7 => 'lememo_fiche_add_this',
      ),
      'header_resume' => array(
        8 => 'field_description_short',
      ),
      'left' => array(
        9 => 'lememo_fiche_block_gallery',
        10 => 'field_description_long',
        11 => 'comments',
        12 => 'vote_bis',
      ),
      'right' => array(
        13 => 'contact_form',
        14 => 'lememo_fiche_legals',
        15 => 'field_mail',
      ),
      'bottom' => array(
        16 => 'field_position',
        17 => 'lememo_fiche_block_coord',
      ),
    ),
    'fields' => array(
      'lememo_fiche_cover_image' => 'top',
      'field_logo' => 'header_society_left',
      'lememo_fiche_btn_coord' => 'header_society_right',
      'field_vote' => 'header_society_right',
      'title' => 'header_society_right',
      'field_city' => 'header_society_right',
      'field_phone_1' => 'header_society_right',
      'lememo_fiche_add_this' => 'header_addthis',
      'field_description_short' => 'header_resume',
      'lememo_fiche_block_gallery' => 'left',
      'field_description_long' => 'left',
      'comments' => 'left',
      'vote_bis' => 'left',
      'contact_form' => 'right',
      'lememo_fiche_legals' => 'right',
      'field_mail' => 'right',
      'field_position' => 'bottom',
      'lememo_fiche_block_coord' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'header_society_left' => 'div',
      'header_society_right' => 'div',
      'header_addthis' => 'div',
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
