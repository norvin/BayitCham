<?php

/**
 *  @file
 *  Create a WGNMedia Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $wgnmedia = new ResourceWGNMediaStreamWrapper('wgnmedia://?ID=[video-id]');
 */
class MediaWGNMediaStreamWrapper extends MediaReadOnlyStreamWrapper {
  protected $base_url = 'http://vod.wgnmedia.com/VOD/vod.php';

  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/wgnmedia';
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    return 'http://vod.wgnmedia.com/VOD/tn.php?ID='. check_plain($parts['ID']);
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    
    $url = 'http://vod.wgnmedia.com/VOD/tn.php?ID='. check_plain($parts['ID']);
    $response = drupal_http_request($url);
    if ($response->data == 'Error.') {
      return variable_get('default_media_wgnmedia_image_thumb', '');
    }
    else{
      $local_path = 'public://media-wgnmedia/' . check_plain($parts['ID']) . '.jpg';
      if (!file_exists($local_path)) {
        $dirname = drupal_dirname($local_path);
        file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
        //@copy($this->getOriginalThumbnailPath(), $local_path);
        // http://stackoverflow.com/a/724397
        $content = file_get_contents($this->getOriginalThumbnailPath());
        file_put_contents($local_path, $content);
      }
    
      return $local_path;
    }
  }
}
