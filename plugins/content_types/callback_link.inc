<?php
 $plugin = array(
  'single' => TRUE,
  'title' => t('Callback Link'),
  'description' => t('Show a callback link'),
  'category' => t('Sasta'),
  'edit form' => 'callback_callback_link_edit_form',
  'render callback' => 'callback_callback_link_render',
  'admin info' => 'callback_callback_link_admin_info',
  'defaults' => array(
    'link_text' => '',
    'link_classes' => '',
  )
 );

function callback_callback_link_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $conf['link_text'] . ' ' . $conf['link_classes'];
    return $block;
  }
}

function callback_callback_link_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['link_text'] = array(
    '#title' => t('Callback Link Text'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_text'],
    '#required' => FALSE,
  );

  $form['link_classes'] = array(
    '#title' => t('Callback Link Classes'),
    '#description' => t('Add classes separates by spaces'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_classes'],
    '#required' => FALSE,
  );

   return $form;
}


function callback_callback_link_edit_form_submit($form, $form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function callback_callback_link_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';
  $block->content = _callback_make_link($conf['link_text'], $conf['link_classes']);

  return $block;
}
