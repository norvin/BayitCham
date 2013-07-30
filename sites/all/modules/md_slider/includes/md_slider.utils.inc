<?php
  /**
   * @file: md_slider.utils.inc
   * User: Duy
   * Date: 2/5/13
   * Time: 6:11 PM
   */

  /**
   * Get video data
   */
  function get_video_data($type, $fid)
  {
    switch ($type) {
      case 'youtube':
        $output['type'] = 'youtube';
        $url = "http://gdata.youtube.com/feeds/api/videos/{$fid}?v=2&alt=jsonc";
        $data = drupal_http_request($url);
        if ($data->code == '200') {
          $output['data'] = json_decode($data->data);
        }
        break;

      case 'vimeo':
        $output['type'] = 'vimeo';
        $url = "http://vimeo.com/api/v2/video/{$fid}.php";
        $data = drupal_http_request($url);
        if ($data->code == '200') {
          $info = unserialize($data->data);
          $output['data'] = (object)$info[0];
        }
        break;
    }

    return $output;
  }

  /**
   * Convert hex to rgb value
   */
  function hex_to_rgb($hex)
  {
    $hex = str_replace("#", "", $hex);

    if (strlen($hex) == 3) {
      $r = hexdec(substr($hex, 0, 1) . substr($hex, 0, 1));
      $g = hexdec(substr($hex, 1, 1) . substr($hex, 1, 1));
      $b = hexdec(substr($hex, 2, 1) . substr($hex, 2, 1));
    } else {
      $r = hexdec(substr($hex, 0, 2));
      $g = hexdec(substr($hex, 2, 2));
      $b = hexdec(substr($hex, 4, 2));
    }
    return array($r, $g, $b);
  }

  /**
   * Analyse google link to get font information
   */
  function md_slider_process_google_web_font($fonts)
  {
    preg_match('/([^\?]+)(\?family=)?([^&\']+)/i', $fonts, $matches);
    $gfonts = explode("|", $matches[3]);

    for ($i = 0; $i < count($gfonts); $i++) {
      $gfontsdetail = explode(":", $gfonts[$i]);
      $gfontname = str_replace("+", " ", $gfontsdetail['0']);
      $gfontweigth = "";
      if (array_key_exists('1', $gfontsdetail)) {
        $gfontweigth = $gfontsdetail['1'];
      }
      $fontvars[] = array(
        'CSS' =>$gfontname,
        'Weight' => $gfontweigth,
      );
    }

    return $fontvars;
  }
