<?php
/**
 * @file
 * bch_main.box.inc
 */

/**
 * Implements hook_default_box().
 */
function bch_main_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'bch_newsletter';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'BCH Newsletter';
  $box->options = array(
    'body' => array(
      'value' => '<?php
global $language;
$action = \'http://app.wgnmailer.net/t/psu/e912b7ee1b0f44aea8e98bc0238762fe\'; //default action in hebrew
if(!empty($language->language)){
  if($language->language == \'en\'){
    $action = \'http://app.wgnmailer.net/t/psu/ccd7dbc137594f09b2b9b1ae868814e4\';
  }
}
?>

<form action="<?php print $action;?>" id="stayuptodate" method="post"><div class="bch-newsletter-fields"><div class="bch-newsletter-register"><?php print t("Register our newsletter"); ?></div><div class="bch-newsletter-fields-wrapper"><input id="email" name="email" type="text" onblur="if (this.value == \'\') {this.value = \'<?php print t(\'Insert your email\'); ?>\';}" onfocus="if (this.value == \'<?php print t(\'Insert your email\'); ?>\') {this.value = \'\';}" placeholder="<?php print t(\'Insert your email\'); ?>" value="<?php print t(\'Insert your email\'); ?>"/><input id="sub-but" type="submit" value="<?php print t(\'Send\').\' >\'; ?>" /></div></div></form>


',
      'format' => 'php_code',
    ),
    'additional_classes' => '',
  );
  $export['bch_newsletter'] = $box;

  return $export;
}
