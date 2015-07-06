<?php
/**
 * @file
 * lememo_fiche.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function lememo_fiche_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'lememo_theme' => array(
        'region' => 'footer_center',
        'status' => 1,
        'theme' => 'lememo_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-2',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'lememo_theme' => array(
        'region' => 'footer_right',
        'status' => 1,
        'theme' => 'lememo_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-menu-footer-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-menu-footer-3',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'lememo_theme' => array(
        'region' => 'footer_bottom',
        'status' => 1,
        'theme' => 'lememo_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
