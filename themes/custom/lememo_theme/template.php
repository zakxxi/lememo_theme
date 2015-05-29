<?php
/**
 * Remove the comment filters' tips
 */
function lememo_theme_filter_tips($tips, $long = FALSE, $extra = '') {
  return '';
}
/**
 * Remove the comment filter's more information tips link
 */
function lememo_theme_filter_tips_more_info () {
  return '';
}

/**
 * Remove the comment reply link
 */
function lememo_theme_preprocess_comment(&$variables) {
  unset($variables['content']['links']['comment']['#links']['comment-reply']);
}

/**
 * Custom the mail contact form to open in popup
 */
function lememo_theme_preprocess_field(&$variables) {
	//dpm($variables);
if (($variables['element']['#theme'] == "field") && ($variables['element']['#field_name'] == "field_mail")) {
// Add some attributes
 $variables['attributes_array']['id'] = 'email-mail-popin';
 $variables['attributes_array']['data-reveal']='';
 $variables['attributes_array']['aria-hidden']='true';
 $variables['attributes_array']['role']='dialog';

 // Add some classes
 $variables['classes_array'][] = 'reveal-modal small';
 }
}

/**
 * Add foundation JS
 */
$options = array('scope' => 'footer'  );
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/foundation.min.js', $options);
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/foundation.clearing.js', $options);
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/foundation.reveal.js', $options);
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/jquery.sticky.js', $options);
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/scripts.js', $options);

$foundation='jQuery(document).foundation();';
$options['type']='inline';
drupal_add_js($foundation, $options);

