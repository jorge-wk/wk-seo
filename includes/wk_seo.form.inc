<?php

/**
 * Adds extra settings to the node content type edit page.
 *
 * @param array $form
 *   Node settings form.
 */
function _wk_seo_process_node_settings_form($form, &$form_state) {

  // Do not process node form if it do not contain node type.
  if (isset($form['type'])) {
    $form['yoast_seo'] = array(
      // '#type' => 'fieldset',
      // '#title' => t('Real-time SEO for Drupal settings'),
      // '#collapsible' => TRUE,
      // '#collapsed' => TRUE,
      // '#group' => 'additional_settings',
      '#prefix' => '<div id="ax">',
      '#suffix' => '</div>',
    );
  }
}
