<?php
  /**
   * @file: front_layers_render.tpl.php
   * User: Duy
   * Date: 1/29/13
   * Time: 3:57 PM
   */
?>
<div class="<?php print $class;?>" <?php print $data;?><?php print ($layer->styles != '') ? " style='{$layer->styles}'" : ''?>>
  <?php if ($layer->type == 'text'): ?>
    <p><?php print $layer->title; ?></p>
  <?php elseif ($layer->type == 'image'): ?>
    <img src="<?php print $layer->url;?>"/>
  <?php
elseif ($layer->type == 'video'): ?>
    <a title="<?php print $layer->title; ?>" class="md-video" href="#" videoid="<?php print $layer->fileid;?>">
        <img src="<?php print $layer->thumb;?>" />
        <span class="md-playbtn"></span>
    </a>
  <?php endif; ?>
</div>
