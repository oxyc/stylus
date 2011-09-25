<?php

function stylus_settings($form, &$form_state) {
  //sites/all/themes/base/stylesheets/stylus
  ///home/oxy/node_modules/nib/lib/nib

  $form['#tree'] = TRUE;
  $form['stylus_binary'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Stylus binary configurations'),
  );

  $stylus_binary = variable_get('stylus_binary', array());

  $form['stylus_binary']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to the stylus binary'),
    '#description' => t('An absolute path to where the stylus binary is located'),
    '#default_value' => (!empty($stylus_binary['path']))
      ? $stylus_binary['path']
      : 'stylus'
  );

  $form['stylus_binary']['nib'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to nib'),
    '#description' => t('Abslute path to the <a href="@nib-url">nib module</a> if wanted.', array('@nib-url' => 'https://github.com/visionmedia/nib')),
    '#default_value' => (!empty($stylus_binary['nib']))
      ? $stylus_binary['nib']
      : ''
  );
  $form['stylus_css_dir'] = array(
    '#type' => 'textfield',
    '#title' => 'Themes CSS output directory',
    '#description' => 'A directory path relative to the base path where to output CSS files. If no path is chosen, output will be in the same directory as stylus files.',
    '#default_value' => variable_get('stylus_css_dir', '')
  );
  $form['stylus_devel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stylus developer mode'),
    '#description' => t('Enable the developer mode which means you have access to the stylus binary and are able to generate css files.'),
    '#default_value' => variable_get('stylus_devel', FALSE),
  );
  $form['stylus_force'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force compilation'),
    '#description' => t('Essentially the same as developer mode but this will compile all files every request, regardless of any change done to the stylus file. (Useful if @import is used.'),
    '#default_value' => variable_get('stylus_force', TRUE),
  );

  return system_settings_form($form);
}

