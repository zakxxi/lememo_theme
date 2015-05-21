<?php
/**
 * @file
 * lememo_fiche.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function lememo_fiche_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer 1 menu',
    'description' => 'Menu contenant les liens de pieds de page de niveau 1',
  );
  // Exported menu: menu-footer-2.
  $menus['menu-footer-2'] = array(
    'menu_name' => 'menu-footer-2',
    'title' => 'Footer 2 menu',
    'description' => 'Menu contenant les liens de pieds de page de niveau 2',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer 1 menu');
  t('Footer 2 menu');
  t('Main menu');
  t('Menu contenant les liens de pieds de page de niveau 1');
  t('Menu contenant les liens de pieds de page de niveau 2');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
