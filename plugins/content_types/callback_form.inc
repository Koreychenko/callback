<?php
 $plugin = array(
  'single' => TRUE,
  'title' => t('Callback Form'),
  'description' => t('Show a callback form with some text above and left.'),
  'category' => t('Sasta'),
  'edit form' => 'callback_callback_form_edit_form',
  'render callback' => 'callback_callback_form_render',
  'admin info' => 'callback_callback_form_admin_info',
  'defaults' => array(
    'top_text' => '',
    'left_text' => '',
  )
 );

function callback_callback_form_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $conf['top_text'] . ' ' . $conf['top_text'];
    return $block;
  }
}

function callback_callback_form_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['top_text'] = array(
    '#title' => t('Top callback form text'),
    '#description' => t('Allow to add HTML tags'),
    '#type' => 'textfield',
    '#default_value' => $conf['top_text'],
    '#required' => FALSE,
  );

   $form['left_text'] = array(
    '#title' => t('Left callback form text'),
    '#description' => t('Allow to add HTML tags'),
    '#type' => 'textfield',
    '#default_value' => $conf['left_text'],
    '#required' => FALSE,
  );

   return $form;
}


function callback_callback_form_edit_form_submit($form, $form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function callback_callback_form_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';
  $block->content = '';

  drupal_add_css(drupal_get_path('module','callback') . '/css/callback_form.css');

  $form = drupal_get_form('callback_form_small');

  $block->content .= theme('callback_form_mini',array('top_text' => $conf['top_text'], 'left_text' => $conf['left_text'], 'form' => drupal_render($form)));

  return $block;
}
