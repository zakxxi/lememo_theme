<?php

/**
 * @file
 * Contains the invocation of hook_migrate_api. This file is automatically
 * loaded.
 */

/**
 * implements hook_migrate_api().
 */
function lememo_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'Import' => array(
        'title' => t('Import data from JSON files'),
      ),
    ),
    'migrations' => array(
      'lememo_businesscard_inital' => array(
        'class_name' => 'lememoBusinesscardInitialMigration',
        'group_name' => 'Import',
        'reference_file' => 'init.json'
      ),
      'lememo_businesscard_nightly' => array(
        'class_name' => 'lememoBusinesscardNightlyMigration',
        'group_name' => 'Import',
        'reference_file' => 'nightly.json'
      ),
    ),
  );
  return $api;
}
