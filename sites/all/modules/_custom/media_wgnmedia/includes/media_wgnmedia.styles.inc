<?php

/**
 * @file media_wgnmedia/includes/media_wgnmedia.styles.inc
 * Styles definitions for Media: WGNMedia.
 */

/**
 * Implementation of Styles module hook_styles_register().
 */
function media_wgnmedia_styles_register() {
  return array(
    'MediaWGNMediaStyles' => array(
      'field_types' => 'file',
      'name' => t('MediaWGNMedia'),
      'description' => t('Media WGNMedia styles.'),
      'path' => drupal_get_path('module', 'media_wgnmedia') .'/includes',
      'file' => 'media_wgnmedia.styles.inc',
    ),
  );
}

/**
 *  Implements hook_styles_containers(). (Deprecated in version 2)
 */
function media_wgnmedia_styles_containers() {
  return array(
    'file' => array(
      'containers' => array(
        'media_wgnmedia' => array(
          'label' => t('WGNMedia Styles'),
          'data' => array(
            'streams' => array(
              'wgnmedia',
            ),
            'mimetypes' => array(
              'video/wgnmedia',
            ),
          ),
          'weight' => 0,
          'filter callback' => 'media_wgnmedia_formatter_filter',
          'themes' => array(
            'field_formatter_styles' => 'media_wgnmedia_field_formatter_styles',
            'styles' => 'media_wgnmedia_styles',
            'preview' => 'media_wgnmedia_preview_style',
          ),
          'description' => t('WGNMedia Styles will display embedded WGNMedia videos and thumbnails to your choosing, such as by resizing, setting colors, and autoplay. You can !manage.', array('!manage' => l(t('manage your WGNMedia styles here'), 'admin/config/media/media-wgnmedia-styles'))),
        ),
      ),
    ),
  );
}

function media_wgnmedia_formatter_filter($variables) {
  if (isset($variables['object'])) {
    $object = isset($variables['object']->file) ? $variables['object']->file : $variables['object'];
    return (file_uri_scheme($object->uri) == 'wgnmedia') && ($object->filemime == 'video/wgnmedia');
  }
}

/**
 * Implementation of the File Styles module's hook_file_styles_filter().
 */
function media_wgnmedia_file_styles_filter($object) {
  $file = isset($object->file) ? $object->file : $object;
  if ((file_uri_scheme($file->uri) == 'wgnmedia') && ($file->filemime == 'video/wgnmedia')) {
    return 'media_wgnmedia';
  }
}

/**
 *  Implements hook_styles_styles().
 */
function media_wgnmedia_styles_styles() {
  $styles = array(
    'file' => array(
      'containers' => array(
        'media_wgnmedia' => array(
          'styles' => array(
            'wgnmedia_thumbnail' => array(
              'name' => 'wgnmedia_thumbnail',
              'effects' => array(
                array('label' => t('Thumbnail'), 'name' => 'thumbnail', 'data' => array('thumbnail' => 1)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 100, 'height' => 75)),
              ),
            ),
            'wgnmedia_preview' => array(
              'name' => 'wgnmedia_preview',
              'effects' => array(
                array('label' => t('Autoplay'), 'name' => 'autoplay', 'data' => array('autoplay' => 0)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 220, 'height' => 165)),
              ),
            ),
            'wgnmedia_full' => array(
              'name' => 'wgnmedia_full',
              'effects' => array(
                array('label' => t('Autoplay'), 'name' => 'autoplay', 'data' => array('autoplay' => 0)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 640, 'height' => 480)),
                array('label' => t('Full screen'), 'name' => 'fullscreen', 'data' => array('fullscreen' => 1)),
              ),
            ),
          ),
        ),
      ),
    ),
  );

  // Allow any image style to be applied to the thumbnail.
  foreach (image_styles() as $style_name => $image_style) {
    $styles['file']['containers']['media_wgnmedia']['styles']['wgnmedia_thumbnail_' . $style_name] = array(
      'name' => 'wgnmedia_thumbnail_' . $style_name,
      'image_style' => $style_name,
      'effects' => array(
        array('label' => t('Thumbnail'), 'name' => 'thumbnail', 'data' => array('thumbnail' => 1)),
      ),
    );
  }

  return $styles;
}

/**
 *  Implements hook_styles_presets().
 */
function media_wgnmedia_styles_presets() {
  $presets = array(
    'file' => array(
      'square_thumbnail' => array(
        'media_wgnmedia' => array(
          'wgnmedia_thumbnail_square_thumbnail',
        ),
      ),
      'thumbnail' => array(
        'media_wgnmedia' => array(
          'wgnmedia_thumbnail',
        ),
      ),
      'small' => array(
        'media_wgnmedia' => array(
          'wgnmedia_preview',
        ),
      ),
      'large' => array(
        'media_wgnmedia' => array(
          'wgnmedia_full',
        ),
      ),
      'original' => array(
        'media_wgnmedia' => array(
          'wgnmedia_full',
        ),
      ),
    ),
  );
  return $presets;
}

/**
 * Implementation of Styles module hook_styles_default_containers().
 */
function media_wgnmedia_styles_default_containers() {
  // We append WGNMedia to the file containers.
  return array(
    'file' => array(
      'containers' => array(
        'media_wgnmedia' => array(
          'class' => 'MediaWGNMediaStyles',
          'name' => 'media_wgnmedia',
          'label' => t('WGNMedia'),
          'preview' => 'media_wgnmedia_preview_style',
        ),
      ),
    ),
  );
}


/**
 * Implementation of Styles module hook_styles_default_presets().
 */
function media_wgnmedia_styles_default_presets() {
  $presets = array(
    'file' => array(
      'containers' => array(
        'media_wgnmedia' => array(
          'default preset' => 'unlinked_thumbnail',
          'styles' => array(
            'original' => array(
              'default preset' => 'video',
            ),
            'thumbnail' => array(
              'default preset' => 'linked_thumbnail',
            ),
            'square_thumbnail' => array(
              'default preset' => 'linked_square_thumbnail',
            ),
            'medium' => array(
              'default preset' => 'linked_medium',
            ),
            'large' => array(
              'default preset' => 'large_video',
            ),
          ),
          'presets' => array(
            'video' => array(
              array(
                'name' => 'video',
                'settings' => array(),
              ),
            ),
            'large_video' => array(
              array(
                'name' => 'resize',
                'settings' => array(
                  'width' => 640,
                  'height' => 390,
                ),
              ),
              array(
                'name' => 'video',
                'settings' => array(),
              ),
            ),
          ),
        ),
      ),
    ),
  );
  // Allow any image style to be applied to the thumbnail.
  foreach (image_styles() as $style_name => $image_style) {
    $presets['file']['containers']['media_wgnmedia']['presets']['linked_' . $style_name] = array(
      array(
        'name' => 'linkToMedia',
        'settings' => array(),
      ),
      array(
        'name' => 'imageStyle',
        'settings' => array(
          'image_style' => $style_name,
        ),
      ),
      array(
        'name' => 'thumbnail',
        'settings' => array(),
      ),
    );
    $presets['file']['containers']['media_wgnmedia']['presets']['unlinked_' . $style_name] = $presets['file']['containers']['media_wgnmedia']['presets']['linked_' . $style_name];
    array_shift($presets['file']['containers']['media_wgnmedia']['presets']['unlinked_' . $style_name]);
    foreach ($image_style['effects'] as $effect) {
      if (in_array($effect['name'], array('image_scale', 'image_scale_and_crop', 'image_resize', 'image_crop'))) {
        $presets['file']['containers']['media_wgnmedia']['presets']['video_' . $style_name] = array(
          array(
            'name' => 'resize',
            'settings' => $effect['data'],
          ),
          array(
            'name' => 'video',
            'settings' => array(),
          ),
        );
      }
    }
  }
  return $presets;
}
