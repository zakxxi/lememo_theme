<?php
function lememo_theme_form_system_theme_settings_alter(&$form, $form_state) {
  $form['lememo_theme_backlink'] = array(
    '#type'          => 'textfield',
    '#title'         => t('URL Retour annuaire'),
    '#default_value' => theme_get_setting('lememo_theme_backlink'),
    '#description'   => t("Entrer l'URL du bouton [RETOUR ANNUAIRE]"),
  );

    $form['lememo_theme_sharethis_js'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Sharethis JS'),
    '#default_value' => theme_get_setting('lememo_theme_sharethis_js'),
    '#description'   => t("Coller le code Javascript fourni par Sharethis"),
  );
}
