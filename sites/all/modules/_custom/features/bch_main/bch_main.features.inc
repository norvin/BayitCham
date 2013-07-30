<?php
/**
 * @file
 * bch_main.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bch_main_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bch_main_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function bch_main_fontyourface_features_default_font() {
  return array(
    'EFTAsaf normal normal' => array(
      'name' => 'EFTAsaf normal normal',
      'enabled' => 1,
      'url' => 'http://localhost/#adaee58a9d957cf9548418715eda1c15',
      'provider' => 'local_fonts',
      'css_selector' => '<none>',
      'css_family' => 'EFTAsaf',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:70:"public://fontyourface/local_fonts/EFTAsaf-normal-normal/stylesheet.css";s:8:"font_uri";a:1:{s:8:"truetype";s:68:"public://fontyourface/local_fonts/EFTAsaf-normal-normal/EFT_Asaf.ttf";}}',
    ),
    'EFTAsafBold normal bold' => array(
      'name' => 'EFTAsafBold normal bold',
      'enabled' => 1,
      'url' => 'http://localhost/#f4ea9e1e226a5271fa7975590f512250',
      'provider' => 'local_fonts',
      'css_selector' => '<none>',
      'css_family' => 'EFTAsafBold',
      'css_style' => 'normal',
      'css_weight' => 'bold',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:72:"public://fontyourface/local_fonts/EFTAsafBold-normal-bold/stylesheet.css";s:8:"font_uri";a:1:{s:8:"truetype";s:75:"public://fontyourface/local_fonts/EFTAsafBold-normal-bold/EFT_Asaf Bold.ttf";}}',
    ),
  );
}

/**
 * Implements hook_image_default_styles().
 */
function bch_main_image_default_styles() {
  $styles = array();

  // Exported image style: bch_menu_icon.
  $styles['bch_menu_icon'] = array(
    'name' => 'bch_menu_icon',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 20,
          'height' => 20,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: contact_us_imagestyle.
  $styles['contact_us_imagestyle'] = array(
    'name' => 'contact_us_imagestyle',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 307,
          'height' => 262,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: footergalleryimg.
  $styles['footergalleryimg'] = array(
    'name' => 'footergalleryimg',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 101,
          'height' => 68,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hp_page_img.
  $styles['hp_page_img'] = array(
    'name' => 'hp_page_img',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 304,
          'height' => 402,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hp_slideshow.
  $styles['hp_slideshow'] = array(
    'name' => 'hp_slideshow',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1660,
          'height' => 574,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hp_store_img.
  $styles['hp_store_img'] = array(
    'name' => 'hp_store_img',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 158,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: md_slider_1_thumb.
  $styles['md_slider_1_thumb'] = array(
    'name' => 'md_slider_1_thumb',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function bch_main_node_info() {
  $items = array(
    'branch' => array(
      'name' => t('Branch'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Branch Name'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
