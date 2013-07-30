<?php

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetWGNMediaHandler extends MediaInternetBaseHandler {
  public function parse($embedCode) {
    $patterns = array(
      '@vod\.wgnmedia\.com/VOD/vod\.php[#\?].*?ID=([^"\& ]+)@i',
    );
    foreach ($patterns as $pattern) {
      preg_match($pattern, $embedCode, $matches);
      if (isset($matches[1]) && $this->valid_id($matches[1])) {
        return file_stream_wrapper_uri_normalize('wgnmedia://ID/' . $matches[1]);
      }
    }
  }

  public function valid_id($id) {
    $url = 'http://vod.wgnmedia.com/VOD/vod.php?ID='. $id;
    $response = drupal_http_request($url);
    if (($response->code != 200) || (stripos($response->data,'MEDIA NOT FOUND'))) {
      throw new MediaInternetValidationException(t('The WGNMedia video ID is invalid or the video was deleted.'));
    }
    return TRUE;
  }

  public function claim($embedCode) {
    if ($this->parse($embedCode)) {
      return TRUE;
    }
  }
  
  public function save() {
    $file = $this->getFileObject();
    // If a user enters a duplicate WGNMedia URL, the object will be saved again.
    // Set the timestamp to the current time, so that the media item shows up
    // at the top of the media library, where they would expect to see it.
    $file_obj->timestamp = REQUEST_TIME;
    file_save($file);
    return $file;
  }

  public function getFileObject() {
    $uri = $this->parse($this->embedCode);
    $file = file_uri_to_object($uri, TRUE);
    return $file;
  }
  
}
