<?php
/**
 * @file
 * wgnmedia_gallery_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wgnmedia_gallery_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function wgnmedia_gallery_feature_image_default_styles() {
  $styles = array();

  // Exported image style: img_w120.
  $styles['img_w120'] = array(
    'name' => 'img_w120',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '120',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: media_gallery_collection_item_large.
  $styles['media_gallery_collection_item_large'] = array(
    'name' => 'media_gallery_collection_item_large',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '321',
          'height' => '196',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: media_gallery_collection_item_small.
  $styles['media_gallery_collection_item_small'] = array(
    'name' => 'media_gallery_collection_item_small',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '107',
          'height' => '68',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
