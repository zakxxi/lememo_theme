<?php
function lememo_theme_form_system_theme_settings_alter(&$form, $form_state) {
  $form['lememo_theme_backlink'] = array(
    '#type'          => 'textfield',
    '#title'         => t('URL Retour annuaire'),
    '#default_value' => theme_get_setting('lememo_theme_backlink'),
    '#description'   => t("Entre l'URL du bouton [RETOUR ANNUAIRE]"),
  );
}
?>