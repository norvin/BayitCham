<?php
  /**
   * @file: theme.front.inc
   * User: Duy
   * Date: 1/29/13
   * Time: 4:18 PM
   */
  function template_preprocess_md_slider_render(&$variables) {
    $data_properties = array();
    $options = array();
    $slider = $variables['slider'];
    $variables['slides'] = MDSlide::get_by_slider_id($slider->slid);
    $settings = $slider->settings;

    # Create options for slider
    $options['fullwidth'] = (boolean)$settings['full_width'];
    $options['transitions'] = $settings['animation'];
    $options['transitionsSpeed'] = $settings['transtime'];
    $options['width'] = $settings['width'];
    $options['height'] = $settings['height'];
    $options['enableDrag'] = (boolean)$settings['touch_swipe'];
    $options['responsive'] = (boolean)$settings['responsive'];
    $options['showLoading'] = ($settings['loadingbar'] != 'none') ? TRUE : FALSE;
    $options['loadingPosition'] = $settings['bar_position'];
    $options['showArrow'] = (boolean)$settings['show_next_prev_button'];
    $options['showBullet'] = (boolean)$settings['show_bullet'];
    $options['posBullet'] = $settings['bullet_position'];
    $options['showThumb'] = (boolean)$settings['show_thumbnail'];
    $options['posThumb'] = $settings['thumbnail_position'];
    $options['slideShowDelay'] = $settings['delay'];
    $options['slideShow'] = (boolean)$settings['auto_play'];
    $options['styleBorder'] = $settings['border_style'];
    $options['styleShadow'] = $settings['dropshadow_style'];

    drupal_add_js(array("md_slider_options_{$slider->slid}" => $options), 'setting');

    # Add google fonts
    $google_fonts = $settings['dmf_google'];
    if ($google_fonts != '' && !$settings['enable_font_css']) {
      drupal_add_css($google_fonts, array('type' => 'external'));
    }

    # Add data-thumb-width & data-thumb-height
    $data_properties[] = "data-thumb-width='{$settings['thumb_width']}'";
    $data_properties[] = "data-thumb-height='{$settings['thumb_height']}'";
    $variables['data_properties'] = implode(' ', $data_properties);
  }

  function template_preprocess_front_slide_render(&$variables) {
    $slider_settings = $variables['slider_settings'];
    $slide = $variables['slide'];
    $data_properties = array();
    $data_properties[] = "data-timeout='{$slide->settings['timelinewidth']}00'";

    $variables['background_style'] = "";
    if ($slide->settings['background_image'] != -1) {
      # Load background image
      $background = file_load($slide->settings['background_image']);
      $create_bg_imgs = $variables['slider_settings']['create_bg_imgstyle'];
      if ($create_bg_imgs) {
        $variables['background_url'] = image_style_url('md_slider_' . $slide->slid . '_bg', $background->uri);
      } else {
        $variables['background_url'] = file_create_url($background->uri);
      }

      # Load thumbnail image
      if ($slide->settings['custom_thumbnail'] != -1) {
        $thumb = file_load($slide->settings['custom_thumbnail']);
      }
      else {
        $thumb = $background;
      }
      $thumb_url = image_style_url('md_slider_' . $slide->slid . '_thumb', $thumb->uri);
    }
    else {
      $variables['background_style'] = ' style="width: auto; height: auto; max-width: none"';
      $variables['background_url'] = file_create_url("public://md_slider_def_bg.jpg");
      if ($slide->settings['custom_thumbnail'] != -1) {
        $thumb = file_load($slide->settings['custom_thumbnail']);
        $thumb_url = image_style_url('md_slider_' . $slide->slid . '_thumb', $thumb->uri);
      }
      else {
        $thumb_url = image_style_url('md_slider_' . $slide->slid . '_thumb', "public://md_slider_def_bg.jpg");
      }
    }
    $data_properties[] = "data-thumb='{$thumb_url}'";

    $variables['data_properties'] = implode(' ', $data_properties);
    $variables['elements_height'] = $variables['slider_settings']['height'];
  }

  function template_preprocess_front_layers_render(&$variables)
  {
    $layer = $variables['layer'];

    # Create css inline style for layer
    $layer['styles'] = process_layer_style((object)$layer);

    # Get image url for image layer
    if ($layer['type'] == 'image') {
      $layer['file_url'] = '';
      if (isset($layer['fileid'])) {
        $image = file_load($layer['fileid']);
        $layer['url'] = file_create_url($image->uri);
      }
    }

    $variables['data'] = process_element_data($layer);
    $variables['layer'] = (object)$layer;

    $class = array('md-object');
    if (isset($layer['style']) && $layer['style'] != 'none') {
      $class[] = $layer['style'];
    }
    $variables['class'] = implode(' ', $class);
  }

  /**
   * Process data for elements
   */
  function process_element_data($element)
  {
    $type = $element['type'];
    $element_full = array_merge(MDCommon::$default_layers[$type], $element);
    $element_full['starttime'] = $element_full['starttime'];
    $element_full['stoptime'] = $element_full['stoptime'];

    $output = array();
    $output[] = "data-x='{$element_full['left']}'";
    $output[] = "data-y='{$element_full['top']}'";
    $output[] = "data-width='{$element_full['width']}'";
    $output[] = "data-height='{$element_full['height']}'";
    $output[] = "data-start='{$element_full['starttime']}'";
    $output[] = "data-stop='{$element_full['stoptime']}'";
    if ($element_full['startani'] != 'none' && $element_full['startani'] != '') {
      $output[] = "data-easein='{$element_full['startani']}'";
    }
    if ($element_full['stopani'] != 'none' && $element_full['stopani'] != '') {
      $output[] = "data-easeout='{$element_full['stopani']}'";
    }

    if (isset($element['paddingtop']) && $element['paddingtop'] > 0) {
      $output[] = "data-padding-top='{$element_full['paddingtop']}'";
    }

    if (isset($element['paddingbottom']) && $element['paddingbottom'] > 0) {
      $output[] = "data-padding-bottom='{$element['paddingbottom']}'";
    }

    if (isset($element['paddingleft']) && $element['paddingleft'] > 0) {
      $output[] = "data-padding-left='{$element['paddingleft']}'";
    }

    if (isset($element['paddingright']) && $element['paddingright'] > 0) {
      $output[] = "data-padding-right='{$element['paddingright']}'";
    }

    return implode(' ', $output);
  }

  /**
   * Process style for layer
   */
  function process_layer_style($layer)
  {
    $output = array();
    if (isset($layer->backgroundcolor)) {
      if (isset($layer->backgroundtransparent)) {
        $rgb = hex_to_rgb($layer->backgroundcolor);
        $alpha = $layer->backgroundtransparent / 100;
        $output[] = "background: rgb({$rgb[0]}, {$rgb[1]}, {$rgb[2]});background: rgba({$rgb[0]}, {$rgb[1]}, {$rgb[2]}, {$alpha});";
      } else {
        if (is_string($layer->backgroundcolor)) {
          $output[] = "background: #{$layer->backgroundcolor};";
        }
        else {
          $output[] = "background: #000;";
        }
      }
    }

    if (isset($layer->opacity)) {
      $opacity = $layer->opacity / 100;
      $data = "opacity: {$opacity};";
      $data .= '-ms-filter:"progid:DXImageTransform.Microsoft.Alpha(Opacity=' . $layer->opacity . ')";';
      $data .= "filter: alpha(opacity={$layer->opacity});";
      $output[] = $data;
    }

    # Process style for layer border
    if (isset($layer->borderposition) && isset($layer->borderwidth) && $layer->borderposition > 0 && $layer->borderwidth > 0) {
      $color = (isset($layer->bordercolor)) ? $layer->bordercolor : "000";
      $border_style = (isset($layer->borderstyle)) ? $layer->borderstyle : "solid";

      # Process border layer position
      $positions = process_layer_border_position($layer->borderposition);
      if (count($positions) == 4) {
        $output[] = "border: {$layer->borderwidth}px {$border_style} #{$color};";
      }
      else {
        foreach ($positions as $position) {
          $output[] = "border-{$position}: {$layer->borderwidth}px {$border_style} #{$color};";
        }
      }
    }

    if (isset($layer->bordertopleftradius) && $layer->bordertopleftradius > 0) {
      $output[] = "-webkit-border-top-left-radius: {$layer->bordertopleftradius}px; -moz-border-radius-topleft: {$layer->bordertopleftradius}px; border-top-left-radius: {$layer->bordertopleftradius}px;";
    }

    if (isset($layer->bordertoprightradius) && $layer->bordertoprightradius > 0) {
      $output[] = "-webkit-border-top-right-radius: {$layer->bordertoprightradius}px; -moz-border-radius-topright: {$layer->bordertoprightradius}px; border-top-right-radius: {$layer->bordertoprightradius}px;";
    }

    if (isset($layer->borderbottomleftradius) && $layer->borderbottomleftradius > 0) {
      $output[] = "-webkit-border-bottom-left-radius: {$layer->borderbottomleftradius}px; -moz-border-radius-bottomleft: {$layer->borderbottomleftradius}px; border-bottom-left-radius: {$layer->borderbottomleftradius}px;";
    }

    if (isset($layer->borderbottomrightradius) && $layer->borderbottomrightradius > 0) {
      $output[] = "-webkit-border-bottom-right-radius: {$layer->borderbottomrightradius}px; -moz-border-radius-bottomright: {$layer->borderbottomrightradius}px; border-bottom-right-radius: {$layer->borderbottomrightradius}px;";
    }

    # Process styles for text layer
    if ($layer->type == 'text') {
      if (isset($layer->color)) {
        $output[] = "color: #{$layer->color};";
      }

      if (isset($layer->bordercolor)) {
        $output[] = "border-color: #{$layer->bordercolor};";
      }

      if (isset($layer->textalign)) {
        $output[] = "text-align: {$layer->textalign};";
      }

      if (isset($layer->fontsize)) {
        $fontsize = $layer->fontsize / 12;
        $output[] = "font-size: {$fontsize}em;";
      }

      if (isset($layer->fontweight)) {
        $output[] = "font-weight: {$layer->fontweight};";
      }

      if (isset($layer->fontfamily)) {
        $output[] = "font-family: {$layer->fontfamily};";
      }

      if (isset($layer->fontstyle)) {
        $output[] = "font-style: {$layer->fontstyle};";
      }

      if (isset($layer->textdecoration)) {
        $output[] = "text-decoration: {$layer->textdecoration};";
      }

      if (isset($layer->texttransform)) {
        $output[] = "text-transform: {$layer->texttransform};";
      }
    }

    return implode(' ', $output);
  }

/**
 * Process border layer position
 */
function process_layer_border_position($border_position) {
  $border_pos = array();

  if ($border_position & 1)
    $border_pos[] = "top";

  if ($border_position & 2)
    $border_pos[] = "right";

  if ($border_position & 4)
    $border_pos[] = "bottom";

  if ($border_position & 8)
    $border_pos[] = "left";

  return $border_pos;
}

