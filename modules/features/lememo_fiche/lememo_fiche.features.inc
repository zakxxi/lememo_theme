<?php
/**
 * @file
 * lememo_fiche.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lememo_fiche_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function lememo_fiche_image_default_styles() {
  $styles = array();

  // Exported image style: cover.
  $styles['cover'] = array(
    'label' => 'cover',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 335,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: logo.
  $styles['logo'] = array(
    'label' => 'logo',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function lememo_fiche_node_info() {
  $items = array(
    'fiche' => array(
      'name' => t('Fiche'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
