<?php
/**
 * @file
 * lememo_fiche.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function lememo_fiche_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_fiche_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_fiche_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'contact_site_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['contact_site_form'] = $captcha;

  return $export;
}
