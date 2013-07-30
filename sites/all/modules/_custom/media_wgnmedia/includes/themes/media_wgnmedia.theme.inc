<?php

/**
 * @file media_wgnmedia/includes/themes/media_wgnmedia.theme.inc
 *
 * Theme and preprocess functions for Media: WGNMedia.
 */

/**
 * Preprocess function for theme('media_wgnmedia_video').
 */
function media_wgnmedia_preprocess_media_wgnmedia_video(&$variables) {
  // Build the URL for display.
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $parts = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parts['ID']);
  $variables['query'] = array();

  // @see http://code.google.com/apis/youtube/player_parameters.html
  foreach (array('width', 'height', 'autoplay', 'fullscreen', 'wmode', 'livestream') as $option) {
    // Set the option, either from the options array, or from the default value.
    $variables[$option] = isset($variables[$option]) ? $variables[$option] : (isset($variables['options'][$option]) ? $variables['options'][$option] : variable_get('media_wgnmedia_'.$option));
  }

  $variables['wrapper_id'] = 'media_wgnmedia_' . $variables['video_id'] . '_' . $variables['id'];
  // $variables['query'] = array('ID'=>$variables['video_id'],'CS'=>'31');
  // $variables['url'] = url('http://vod.wgnmedia.com/VOD/vod.php', array('query' => $variables['query'], 'external' => TRUE, 'https' => TRUE));
  
  $settings = array(
    'media_wgnmedia' => array(
      $variables['wrapper_id'] => array(
        'width' => $variables['width'],
        'height' => $variables['height'],
        'video_id' => $variables['video_id'],
        'fullscreen' => $variables['fullscreen'],
        'id' => $variables['wrapper_id'] .'_iframe',
      ),
    ),
  );
  drupal_add_js($settings, 'setting');
  
  // For users with JavaScript, these object and embed tags will be replaced
  // by an iframe, so that we can support users without Flash.
  $variables['output'] = <<<OUTPUT
    <iframe class="wgn-video-player" src="http://vod.wgnmedia.com/VOD/vod.php?ID={$variables['video_id']}&amp;CS=32" mce_src="http://vod.wgnmedia.com/VOD/vod.php?ID={$variables['video_id']}&amp;CS=32" scrolling="no" frameborder="0" height="394px" width="700px">
      <p>' . t('Your browser does not support iframes.') . '</p>
    </iframe>
OUTPUT;
}

function theme_media_wgnmedia_field_formatter_styles($variables) {
  $element = $variables['element'];
  $style = $variables['style'];
  $variables['file'] = $element['#item'];
  $variables['uri'] = $variables['file']['uri'];
  $variables['style_name'] = $style['name'];
  return theme('media_wgnmedia_embed', $variables);
}

/**
 * Preview for Styles UI.
 */
function theme_media_wgnmedia_preview_style($variables) {
  $variables['uri'] = media_wgnmedia_variable_get('preview_uri');
  $variables['field_type'] = 'file';
  $variables['object'] = file_uri_to_object($variables['uri']);

  return theme('styles', $variables);
}

/**
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_wgnmedia_styles($variables) {
  $style = $variables['style'];
  $variables['file'] = $variables['object'];
  $variables['uri'] = $variables['object']->uri;
  $variables['style_name'] = $style['name'];
  return theme('media_wgnmedia_embed', $variables);
}

/**
 * @todo: get this working
 *
 * This code is for embedding videos in WYSIYWG areas, not currently working.
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_wgnmedia_embed($variables) {
  $preset_name = $variables['preset_name'];
  $preset = styles_containers_available_styles('file', 'media_wgnmedia', $preset_name);
  $output = '';
  if (!empty($preset)) {
    // Build the URL for display.
    $uri = $variables['uri'];
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $parts = $wrapper->get_parameters();

    $fullscreen_value = $autoplay = 'false';
    $in_browser = $thumbnail = FALSE;

    foreach ($preset['effects'] as $effect) {
      switch ($effect['name']) {
        case 'autoplay':
          $autoplay = $effect['data']['autoplay'] ? 'true' : 'false';
          break;
        case 'resize':
          $width = $effect['data']['width'];
          $height = $effect['data']['height'];
          break;
        case 'fullscreen':
          $fullscreen_value = $effect['data']['fullscreen'] ? 'true' : 'false';
          break;
        case 'thumbnail':
          $thumbnail = $effect['data']['thumbnail'];
      }
    }
    if (isset($variables['object']->override)) {
      $override = $variables['object']->override;
      if (isset($override['width'])) {
        $width = $override['width'];
      }
      if (isset($override['height'])) {
        $height = $override['height'];
      }
      if (isset($override['wysiwyg'])) {
        $thumbnail = TRUE;
      }
      if (isset($override['browser']) && $override['browser']) {
        $in_browser = TRUE;
        $thumbnail = TRUE;
      }
    }
    $width = isset($width) ? $width : media_wgnmedia_variable_get('width');
    $height = isset($height) ? $height : media_wgnmedia_variable_get('height');
    $video_id = check_plain($parts['v']);
    if ($thumbnail) {
      // @todo Clean this up.
      $image_variables = array(
        'path' => $wrapper->getOriginalThumbnailPath(),
        'alt' => $variables['alt'],
        'title' => $variables['title'],
        'getsize' => FALSE,
      );
      if (isset($preset['image_style'])) {
        $image_variables['path'] = $wrapper->getLocalThumbnailPath();
        $image_variables['style_name'] = $preset['image_style'];
        $output = theme('image_style', $image_variables);
      }
      else {
        // We need to add this style attribute here so that it doesn't get lost
        // If you resize a video in a node, save it, edit it, but don't adjust
        // the sizing of the video while editing, the size will revert to the
        // default.  Adding the specific size here retains the original resizing
        $WYSIWYG = isset($variables['object']->override['style']) ? $variables['object']->override['style'] : '';
        $image_variables['attributes'] = array('width' => $width, 'height' => $height, 'style' => $WYSIWYG);
        $output = theme('image', $image_variables);
      }
      if ($in_browser) {
        // Add an overlay that says 'WGNMedia' to media library browser thumbnails.
        $output .= '<span />';
      }
    }
    else {
      $output = theme('media_wgnmedia_video', array('uri' => $uri, 'width' => $width, 'height' => $height, 'autoplay' => ($autoplay == 'true' ? TRUE : NULL), 'fullscreen' => ($fullscreen_value == 'true' ? TRUE : NULL)));
    }
  }
  
  return $output;
}