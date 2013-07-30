<?php

/**
 * @file media_wgnmedia/includes/themes/media-wgnmedia-video.tpl.php
 *
 * Template file for theme('media_wgnmedia_video').
 *
 * Variables available:
 *  $uri - The uri to the WGNMedia video, such as WGNMedia://ID/11043.
 *  $video_id - The unique identifier of the WGNMedia video.
 *
 * Note that we set the width & height of the outer wrapper manually so that
 * the JS will respect that when resizing later.
 */
?>
<div class="media-wgnmedia-outer-wrapper" id="media-wgnmedia-<?php print $video_id; ?>">
  <div class="media-wgnmedia-preview-wrapper" id="<?php print $wrapper_id; ?>">
    <?php print $output; ?>
  </div>
</div>
