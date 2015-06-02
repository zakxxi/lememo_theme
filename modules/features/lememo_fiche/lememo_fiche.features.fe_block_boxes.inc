<?php
/**
 * @file
 * lememo_fiche.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function lememo_fiche_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'copyright';
  $fe_block_boxes->format = 'plain_text';
  $fe_block_boxes->machine_name = 'copyright';
  $fe_block_boxes->body = '© LeMemo 2015';

  $export['copyright'] = $fe_block_boxes;

  return $export;
}
