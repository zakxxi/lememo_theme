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

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'menfin' => 'menfin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'menfin' => 'menfin',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'menfin' => 'menfin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'menfin' => 'menfin',
    ),
    'module' => 'fivestar',
  );

  return $permissions;
}
