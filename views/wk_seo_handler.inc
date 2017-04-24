<?php

/**
 * @file
 */

/**
 * View handler class wk_seo_handler_rating.
 */
class wk_seo_handler_rating extends views_handler_field {

  /**
   * @inheritdoc
   */
  public function query() {
    $this->ensure_my_table();
  }

  /**
   * Renders the field handler.
   */
  public function render($values) {
    $output = '';

    if (user_access('use yoast seo')) {
      // Add our own CSS.
      drupal_add_css(drupal_get_path('module', 'wk_seo') . '/css/wk_seo.css');

      // Check if entity has SEO availability otherwise show a message.
      if (wk_seo_entity_supports_wk_seo('node', strtolower($values->node_type))) {
        // Score will be either 0 or a higher int. 0 is default.
        $score = wk_seo_get_score($values->nid);
        // Class will represent classname for current score. Like poor or bad
        // it's used for theming purposes.
        $class = wk_seo_score_rating($score);

        // Add Yoast score to the overview.
        $output = '';
      }
      else {
        $output = '';
      }
    }

    return $output;
  }

}
