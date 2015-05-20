<?php

/**
 * Add foundation JS
 */
$options = array('scope' => 'footer'  );
drupal_add_js(drupal_get_path('theme', 'lememo_theme') . '/js/foundation.min.js', $options);
$foundation='jQuery(document).foundation();';
$options['type']='inline';
drupal_add_js($foundation, $options);