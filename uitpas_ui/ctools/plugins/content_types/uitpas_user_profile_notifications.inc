<?php

/**
 * @file
 * Plugin to provide a content type for uitpas user profile notifications.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Uitpas: user profile notifications'),
  'description' => t('Uitpas: user profile notifications.'),
  'category' => t('Uitpas'),
  'required context' => new ctools_context_required(t('Uitpas user'), 'uitpas_user'),
);

function uitpas_ui_uitpas_user_profile_notifications_content_type_edit_form($form, &$form_state) {
  return $form;
}

function uitpas_ui_uitpas_user_profile_notifications_content_type_render($subtype, $conf, $args, $context) {
  $cf_user = $context->data->user;
  if ($cf_user) {
    $cf = DrupalCultureFeed::getConsumerInstance();
    $block = new stdClass();
    $block->title = "";
    $block->content = theme('uitpas_ui_user_profile_notifications', array('cf_user' => $cf_user));
    return $block;
  }
}