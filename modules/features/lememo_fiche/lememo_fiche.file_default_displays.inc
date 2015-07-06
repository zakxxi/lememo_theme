<?php
/**
 * @file
 * lememo_fiche.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function lememo_fiche_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_dailymotion_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '480',
    'autoplay' => 0,
    'iframe' => 1,
  );
  $export['video__default__media_dailymotion_video'] = $file_display;

  return $export;
}
