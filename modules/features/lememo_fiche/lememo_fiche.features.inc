<?php
/**
 * @file
 * lememo_fiche.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lememo_fiche_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
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
          'width' => 2000,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_thumb1.
  $styles['gallery_thumb1'] = array(
    'label' => 'gallery_thumb1',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 315,
          'height' => 210,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_thumb2.
  $styles['gallery_thumb2'] = array(
    'label' => 'gallery_thumb2',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 205,
          'height' => 135,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: logo.
  $styles['logo'] = array(
    'label' => 'logo',
    'effects' => array(),
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
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
