<?php
/**
 * @file
 * lememo_fiche.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function lememo_fiche_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_annuaire:http://www.lememo.com/Annuaire
  $menu_links['main-menu_annuaire:http://www.lememo.com/Annuaire'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.lememo.com/Annuaire',
    'router_path' => '',
    'link_title' => 'Annuaire',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_annuaire:http://www.lememo.com/Annuaire',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-2_faq:http://www.lememo.com/Faq
  $menu_links['menu-footer-2_faq:http://www.lememo.com/Faq'] = array(
    'menu_name' => 'menu-footer-2',
    'link_path' => 'http://www.lememo.com/Faq',
    'router_path' => '',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-2_faq:http://www.lememo.com/Faq',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-2_mentions-lgales:http://www.lememo.com/MentionsLegales
  $menu_links['menu-footer-2_mentions-lgales:http://www.lememo.com/MentionsLegales'] = array(
    'menu_name' => 'menu-footer-2',
    'link_path' => 'http://www.lememo.com/MentionsLegales',
    'router_path' => '',
    'link_title' => 'Mentions légales',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-2_mentions-lgales:http://www.lememo.com/MentionsLegales',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_conditions-gnrales-de-services--ventes:http://www.lememo.com/Cgv
  $menu_links['menu-footer_conditions-gnrales-de-services--ventes:http://www.lememo.com/Cgv'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'http://www.lememo.com/Cgv',
    'router_path' => '',
    'link_title' => 'Conditions générales de Services / Ventes',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_conditions-gnrales-de-services--ventes:http://www.lememo.com/Cgv',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_qui-sommes-nous-:http://www.lememo.com/CharteQualite
  $menu_links['menu-footer_qui-sommes-nous-:http://www.lememo.com/CharteQualite'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'http://www.lememo.com/CharteQualite',
    'router_path' => '',
    'link_title' => 'Qui sommes-nous ?',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_qui-sommes-nous-:http://www.lememo.com/CharteQualite',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-footer-3_crdits:http://www.lememo.com/Credits?lieuSite=internet&siteId=1
  $menu_links['menu-menu-footer-3_crdits:http://www.lememo.com/Credits?lieuSite=internet&siteId=1'] = array(
    'menu_name' => 'menu-menu-footer-3',
    'link_path' => 'http://www.lememo.com/Credits?lieuSite=internet&siteId=1',
    'router_path' => '',
    'link_title' => 'Crédits',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-footer-3_crdits:http://www.lememo.com/Credits?lieuSite=internet&siteId=1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-footer-3_mentions-lgales:http://www.lememo.com/MentionsLegales
  $menu_links['menu-menu-footer-3_mentions-lgales:http://www.lememo.com/MentionsLegales'] = array(
    'menu_name' => 'menu-menu-footer-3',
    'link_path' => 'http://www.lememo.com/MentionsLegales',
    'router_path' => '',
    'link_title' => 'Mentions légales',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-footer-3_mentions-lgales:http://www.lememo.com/MentionsLegales',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Annuaire');
  t('Conditions générales de Services / Ventes');
  t('Crédits');
  t('FAQ');
  t('Mentions légales');
  t('Qui sommes-nous ?');


  return $menu_links;
}
