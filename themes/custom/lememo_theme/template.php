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
 * Add foundation JS
 */
$options = array('scope' => 'footer'  );
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/foundation.min.js', $options);
$foundation='jQuery(document).foundation();';
$options['type']='inline';
drupal_add_js($foundation, $options);

?>