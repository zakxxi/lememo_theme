<?php

/**
 * @file
 * Display Suite Lememo Comments Display configuration.
 */

function ds_lememo_comments_display() {
  return array(
    'label' => t('Lememo Comments Display'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right'),
    ),
    // Uncomment if you want to include a CSS file for this layout (lememo_comments_display.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (lememo_comments_display.png)
    // 'image' => TRUE,
  );
}
