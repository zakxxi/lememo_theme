<?php
/**
 * @file
 * lememo_fiche.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function lememo_fiche_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  return $permissions;
}
