<?php
/**
 * Created by PhpStorm.
 * User: jorge
 * Date: 17/01/17
 * Time: 11:59
 */

/**
 * Form builder
 */
function wk_seo_admin_settings() {
    global $base_url;
    $allowed_extensions = 'jpg jpeg gif png';
    $form = array();
    // $form['og']['title'] = array(
    //     '#type' => 'textfield',
    //     '#title' => t('OG Title'),
    //     '#description' => t('Enter the default OG title if none is set on the current page.'),
    //     '#default_value' => variable_get('wk_seo_og_title',''),
    //     '#size' => 40,
    // );
    $form['og']['image'] = array(
        '#type' => 'managed_file',
        '#title' => t('OG image'),
        '#description' => t('You need to set the global <pre>[site:og_image]</pre> image token in metatags config.'),
        '#default_value' => variable_get('wk_seo_og_image', ''),
        '#upload_location' => 'public://',
        '#upload_validators' => array(
            'file_validate_extensions' => array($allowed_extensions)
        ),
    );

    $form['og']['wk_seo_links'] = array(
      '#title' => t('Useful links'),
      '#markup' => '<div class="wk-seo-social-wrap"><h3>Useful links e.g. Metatags config page and Google Tag manager</h3><ul><li><a href="'.$base_url.'/admin/config/search/metatags/config/global">Go to Global metatag settings</a></li><li><a href="'.$base_url.'/admin/config/system/google_tag">Go to Google tag manager</a></li></ul></div>'
    );
    // $form['wk_gt'] = google_tag_settings_form();

    $form['#submit'][] = 'wk_seo_settings_submit';

    return system_settings_form($form);
}

/**
 * Submit function for wk_seo_settings form.
 */
function wk_seo_settings_submit($form, &$form_state)
{

    global $conf;

    drupal_flush_all_caches();


  if ($form_state['values']['title'] !== '') {
    variable_set('wk_seo_og_title', $form_state['values']['title']);
  }

    // saving image
    $has_value = FALSE;
    if ($form_state['values']['image'] > 0) {
        $f = $form_state['values']['image'];
        // Load the file via file.fid
        $file = file_load($f);
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'wk_seo', 'variable:wk_seo_og_image', 1, 1);
        variable_set('wk_seo_og_image', $form_state['values']['image']);
        //      $has_value = TRUE;
    } else {
        // Load the file via file.fid.
        $file = file_load(variable_get('wk_seo_og_image', ''));

        if (isset($file->fid) && $file->fid) {
            // Delete the file and the usage record
            file_delete($file, TRUE);
        }
        variable_set('wk_seo_og_image', '');
    }

}
