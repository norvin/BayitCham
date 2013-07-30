<?php

/**

 */
/**
 * Displays a gallery node as a teaser.
 *
 * The Galleries page displays a grid of gallery teasers. Each gallery teaser is
 * themed as a node using node.tpl.php or one if its overrides. Where that
 * template file calls @code render($content) @endcode, the output of this
 * function is returned.
 */
function media_gallery_wgnmedia_media_gallery_teaser($variables) {
  drupal_add_css(drupal_get_path('module', 'media_gallery_wgnmedia') . '/css/media_gallery_wgnmedia.css');
  $element = $variables['element'];
  $node = $element['#node'];
  
  $imgs = array();
  $cnti = (isset($node->media_gallery_media_original['und']))? count($node->media_gallery_media_original['und']) : 0;
  if($cnti > 0){
    $dpath = variable_get('default_media_wgnmedia_image_thumb', '');
    $i=0;
    while($i<4){
      $style_name = ($i==0) ? 'media_gallery_collection_item_large' : 'media_gallery_collection_item_small';
      if($i<$cnti){
        $j = file_load($node->media_gallery_media_original['und'][$i]['fid']);
        if($j->type=='video'){
          $scheme = file_uri_scheme($j->uri);
          $origfilename = substr($j->uri,strrpos($j->uri,'/')+1);
          $p = 'public://media-'.$scheme.'/'.$origfilename.'.jpg';
          $imgs[] = '<div class="video-player-sign"></div><div class="video-player-sign-hover"></div>'.theme('image_style', array('style_name' => $style_name, 'path' => $p,'attributes' => array('class' => 'mg-collection-item-vid')));
          //$imgs[] = l($img,'node/'.$gallerynid,array('html'=>true));
        }
        elseif($j->type=='image'){
          $imgs[] = theme('image_style', array('style_name' => $style_name, 'path' => $j->uri,'attributes' => array('class' => 'mg-collection-item-img')));
          //$imgs[] = l($img,'node/'.$gallerynid,array('html'=>true));
        }
      }
      else{
        $imgs[] = theme('image_style', array('style_name' => $style_name, 'path' => $dpath,'attributes' => array('class' => 'mg-collection-item-img')));
      }
      $i++;
    }
  }
  
  $link_vars = array();
  //$link_vars['image'] = $image;
  $link_vars['image'] = $imgs;
  $uri = entity_uri('node', $node);
  $link_vars['link_path'] = $uri['path'];
  $link_vars['classes'] = array('media-gallery-thumb mg-ezra-collection');
  $link_vars['ntitle'] = $node->title;
  $link_vars['ncreated'] = $node->created;
  $link_vars['nchanged'] = $node->changed;
  $link_vars['media_count'] = media_gallery_get_media_type_count($node, 'media_gallery_media_original');
  
  $result = db_query("SELECT totalcount FROM {node_counter} WHERE nid = :nid",array(':nid'=>$node->nid));
  $link_vars['view_counter'] = ($result->rowCount() > 0) ? $result->fetchColumn(0) : 0;
  
  $output = '<div class="media-collection-item-wrapper">' . media_gallery_wgnmedia_media_gallery_collection_item($link_vars) . '</div>';

  // Set the variables to theme the meta data if there is a term on the node
  if (isset($node->term)) {
    $term = $node->term;
    $meta_vars = array();
    $meta_vars['location'] = $term->media_gallery_image_info_where[LANGUAGE_NONE][0]['value'];
    $meta_vars['title'] = $node->title;
    $meta_vars['link_path'] = $link_vars['link_path'];
    // Organize the file count by type. We only expect images and videos for
    // now, so we put those first and group the others together into a general
    // category at the end.
    $type_count = media_gallery_get_media_type_count($node, 'media_gallery_media_original');
    $description = array();
    if (isset($type_count['image'])) {
      $count = $type_count['image'];
      $description[] = format_plural($count, '<span>@num image</span>', '<span>@num images</span>', array('@num' => $count));
      unset($type_count['image']);
    }
    if (isset($type_count['video'])) {
      $count = $type_count['video'];
      $description[] = format_plural($count, '<span>@num video</span>', '<span>@num videos</span>', array('@num' => $count));
      unset($type_count['video']);
    }
    if (!empty($type_count)) {
      $count = array_sum($type_count);
      $description[] = format_plural($count, '<span>@num other item</span>', '<span>@num other items</span>', array('@num' => $count));
    }
    $meta_vars['description'] = implode(', ', $description);

    // Add the meta information
    //$output .= theme('media_gallery_meta', $meta_vars);
  }

  return $output;
}

/**
 * Theme the thumbnail link for a media gallery item
 *
 * @param string $image
 *   Which meta data fields to display
 * @param string $link_path
 *   The location to place the meta data on the media item
 * @param string $classes
 *   An array of classes to attach to the link.
 *
 */
function media_gallery_wgnmedia_media_gallery_collection_item($variables) {
  $img = $variables['image'];
  $link_path = $variables['link_path'];
  $attributes = array();
  if (!empty($variables['classes'])) {
    $attributes['class'] = $variables['classes'];
  }
  /*if (!empty($variables['title'])) {
    // I'm fairly sure I don't like this solution.  But as Alex mentions in
    // theme_media_gallery_file_field_inline() the File Styles module isn't allowing
    // us access to the render array pre-rendering, so I'm doing a str_replace()
    // here specifically to address the title and alt for thumbnails.  This had
    // to be further modified to remove and then add the title and alt attributes
    // video thumbnails had no title and alt attributes so the string replace was
    // not triggering for them.
    $new_image = str_replace(array('title=""', 'alt=""'), array('', ''), $image);
    $image = str_replace('/>', ' title="'.$variables['title'].'" alt="'.$variables['title'].'" />', $new_image);;
  }*/
  $image = '';
  if (count($img) > 0) {
    $image .= '<div class="mgc-large">'.$img[0].'</div>';
    $image .= '<div class="mgc-smalls">';
    for($i=1; $i<=3; $i++) {
      switch($i) {
        case 1:
          $order = 'first';
          break;
        case 2:
          $order = 'middle';
          break;
        case 3:
          $order = 'last';
          break;
      }
      $image .= (isset($img[$i]))? '<div class="mgc-s1 '.$order.'">'.$img[$i].'</div>' : '<div class="mgc-s1 '.$order.'"></div>';
    }
    $image .= '</div>';
  }
  //$simage = $variables

  // Add sliding door top div and wrappers
  $item = '<img class="stack-image innergallery" src="' . base_path() . MY_MODULE_PATH . '/css/images/gallery-bg-hover.png" /><div class="media-gallery-item"><div class="top"><div class="top-inset-1"><div class="top-inset-2"></div></div></div><div class="gallery-thumb-outer"><div class="gallery-thumb-inner">';
  // Node details
  $item .= '<div class="node-details"><div class="nd-title">'.t($variables['ntitle']).'</div><div class="nd-updatedate">'.format_date($variables['nchanged'],'custom','D, F d, Y').'</div></div>';
  // Gallery views count and total media count
  $item .= '<div class="gallery-counters"><div class="items-counter">'.$variables['media_count']['image'].'<br />' . t('Pictures') . '</div><div class="views-counter">'.$variables['view_counter'].'<br />' . t('Views') . '</div></div>';
  // Create a link around the image
  $item .= '<div class="galleryimages">';
  $item .= empty($variables['no_link']) ? l($image, $link_path, array('html' => TRUE, 'attributes' => $attributes)) : $image;
  $item .= '</div>';
  // Add sliding door bottom div and close wrappers
  $item .= '</div></div><div class="bottom"><div class="bottom-inset-1"><div class="bottom-inset-2"></div></div></div></div>';
  return $item;
}

/**
 * Template preprocess function for displaying a media item (entity) as a
 * thumbnail on the gallery page.
 */
function media_gallery_wgnmedia_preprocess_media_gallery_media_item_thumbnail(&$variables) {
  $element = $variables['element'];

  // Attach the colorbox javascript if the format calls for it.
  $format = $element['#media_gallery_entity']->media_gallery_format[LANGUAGE_NONE][0]['value'];
  $lightbox = is_numeric(strpos($format, 'lightbox')) ? TRUE : FALSE;
  if ($lightbox) {
    $element['file']['#attached']['js'][] = drupal_get_path('module', 'media_gallery') . '/colorbox-display.js';
    $element['file']['#attached']['library'][] = array('media_gallery', 'colorbox');
  }

  // Get the rendered file without annoying DIV wrappers.
  $element['file'] = array('#theme' => 'media_gallery_file_field_inline', '0' => $element['file']);
  $image = drupal_render($element['file']);

  $gallery_id = $element['#media_gallery_entity']->nid;
  $media_id = $element['#file']->fid;

  // Add a class that is a more targeted version of what template_preprocess()
  // automatically adds for this theme hook, to enable per-type (e.g., video vs.
  // image) styling.
  $variables['classes_array'][] = drupal_html_class('media_gallery_media_item_thumbnail_' . $element['#file']->type);

  // Add a class for the wrapper.
  $variables['classes_array'][] = 'media-gallery-item-wrapper';

  // Create an array of variables to be added to the main thumbnail link.
  $link_vars = array();
  $link_vars['image'] = $image;
  $link_vars['link_path'] = "media-gallery/detail/$gallery_id/$media_id";
  $link_vars['classes'] = $lightbox ? array('media-gallery-thumb', 'cbEnabled') : array('media-gallery-thumb');
  $link_vars['title'] = $element['#bundle'] == 'image' ? t('View larger image') : t('Watch video');
  // Add the image as a link to the detailed view
  $variables['media_gallery_item'] = theme('media_gallery_item', $link_vars);

  // Set the variables to theme the metadata.
  $meta_vars = array();
  $meta_vars['location'] = $element['#media_gallery_entity']->media_gallery_image_info_where[LANGUAGE_NONE][0]['value'];
  $meta_vars['title'] = isset($element['media_title']) ? $element['media_title'][0]['#markup'] : '';
  $meta_vars['link_path'] = $link_vars['link_path'];

  // Theme the metadata.
  $variables['media_gallery_meta'] = ''; // do not display the metadata when hovering the media item
}

/**
 * WGNMedia Override
 * Theme the thumbnail link for a media gallery item
 *
 * @param string $image
 *   Which meta data fields to display
 * @param string $link_path
 *   The location to place the meta data on the media item
 * @param string $classes
 *   An array of classes to attach to the link.
 *
 */
function media_gallery_wgnmedia_media_gallery_item($variables) {
  drupal_add_css(drupal_get_path('module', 'media_gallery_wgnmedia') . '/css/media_gallery_wgnmedia.css');
  $image = $variables['image'];
  $link_path = $variables['link_path'];
  $attributes = array();
  if (!empty($variables['classes'])) {
    $attributes['class'] = $variables['classes'];
  }
  if (!empty($variables['title'])) {
    // I'm fairly sure I don't like this solution.  But as Alex mentions in
    // theme_media_gallery_file_field_inline() the File Styles module isn't allowing
    // us access to the render array pre-rendering, so I'm doing a str_replace()
    // here specifically to address the title and alt for thumbnails.  This had
    // to be further modified to remove and then add the title and alt attributes
    // video thumbnails had no title and alt attributes so the string replace was
    // not triggering for them.
    $new_image = str_replace(array('title=""', 'alt=""'), array('', ''), $image);
    $image = str_replace('/>', ' title="'.$variables['title'].'" alt="'.$variables['title'].'" />', $new_image);;
  }
    
  $mediatypeinfo = '';
  $vidplaysign = '';
    if(stripos($variables['title'],'video') !== FALSE){
    $vidplaysign = '<div class="video-player-sign"></div><div class="video-player-sign-hover"></div>';
      $mediatypeinfo = '<div class="media-item-type-info"><div class="mediatype-vid-hover"></div><div class="mediatype-vid-icon"></div></div>';
    }
    else{
      $mediatypeinfo = '<div class="media-item-type-info"><div class="mediatype-img-hover"></div><div class="mediatype-img-icon"></div></div>';
    }
    
  
  // Add sliding door top div and wrappers
  $item = '<img class="stack-image innergallery" src="' . base_path() . MY_MODULE_PATH . '/css/images/gallery-bg-hover.png" /><div class="media-gallery-item"><div class="top"><div class="top-inset-1"><div class="top-inset-2"></div></div></div><div class="gallery-thumb-outer"><div class="gallery-thumb-inner">';
  // Create a link around the image
  $item .= empty($variables['no_link']) ? l($vidplaysign.$image.$mediatypeinfo, $link_path, array('html' => TRUE, 'attributes' => $attributes)) : $image;
  // Add sliding door bottom div and close wrappers
  $item .= '</div></div><div class="bottom"><div class="bottom-inset-1"><div class="bottom-inset-2"></div></div></div></div>';
  return $item;
}


