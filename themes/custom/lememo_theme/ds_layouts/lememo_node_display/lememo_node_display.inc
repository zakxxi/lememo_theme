<?php

/**
 * @file
 * Display Suite Lememo node display configuration.
 */

function ds_lememo_node_display() {
  return array(
    'label' => t('Lememo node display'),
    'regions' => array(
      'top' => t('Top'),
      'header_society_left' => t('Header Bloc Info Left'),
      'header_society_right' => t('Header Bloc Info Right'),
      'header_addthis' => t('Header Add This'),
      'header_resume' => t('Header Resume'),
      'left' => t('Left'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
    // Uncomment if you want to include a CSS file for this layout (lememo_node_display.css)
    'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (lememo_node_display.png)
    // 'image' => TRUE,
  );
}
