<?php
/**
 * @file
 * lememo_fiche.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function lememo_fiche_user_default_roles() {
  $roles = array();

  // Exported role: menfin.
  $roles['menfin'] = array(
    'name' => 'menfin',
    'weight' => 2,
  );

  return $roles;
}
