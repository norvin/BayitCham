<?php
drupal_add_js(drupal_get_path('theme', 'bayitcham') .'/js/jquery.selectbox/js/jquery.selectbox-0.2.min.js');
drupal_add_css(drupal_get_path('theme', 'bayitcham') .'/js/jquery.selectbox/css/jquery.selectbox.css');
?>
<script type="text/javascript">
  (function($) {
    $(document).ready(function() {
      // JQuery Selectbox
      $("#edit-submitted-payment-option").selectbox();
    });
  })(jQuery);
</script>
<?
/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 */
//dsm($form);
?>
<?php if($form['details']['nid']['#value'] == 18) { ?>
<?php
  drupal_set_title("");
  //drupal_set_title(t($form['#node']->title));
?>
<div class="bch-order-form-wrapper">
  <?php if (isset($_GET['prodname'])) : ?>
    <div class="order-details"><?php print "<strong>" . t("Order details") . "</strong> | " . $_GET['prodname'] . " |"; ?></div>
  <?php endif; ?>
  
  <div class="order-details-form">
    <div class="odr-col first">
      <?php 
        $form['submitted']['amount']['#title'] = t($form['submitted']['amount']['#title']);
        print drupal_render($form['submitted']['amount']); 
      ?>
      <?php 
        $form['submitted']['payment_option']['#title'] = t($form['submitted']['payment_option']['#title']);
        print drupal_render($form['submitted']['payment_option']); 
      ?>
    </div>
    <div class="odr-col middle">
      <?php 
        $form['submitted']['first_name']['#title'] = t($form['submitted']['first_name']['#title']);
        print drupal_render($form['submitted']['first_name']); 
      ?>
      <?php 
        $form['submitted']['last_name']['#title'] = t($form['submitted']['last_name']['#title']);
        print drupal_render($form['submitted']['last_name']); 
      ?>
      <?php 
        $form['submitted']['address']['#title'] = t($form['submitted']['address']['#title']);
        print drupal_render($form['submitted']['address']); 
      ?>
    </div>
    <div class="odr-col last">
      <?php 
        $form['submitted']['phone']['#title'] = t($form['submitted']['phone']['#title']);
        print drupal_render($form['submitted']['phone']); 
      ?>
      <?php 
        $form['submitted']['email']['#title'] = t($form['submitted']['email']['#title']);
        print drupal_render($form['submitted']['email']); 
      ?>
      <?php 
        $form['submitted']['city']['#title'] = t($form['submitted']['city']['#title']);
        print drupal_render($form['submitted']['city']); 
      ?>
    </div>
  </div>
  
  <div class="order-send-flow">
    <div class="odr-icons"></div>
    <div class="order-send-button">
      <?php
        $form['actions']['submit']['#value'] = t('Send >');
        print drupal_render($form['actions']['submit']); 
      ?>
    </div>
  </div>

  <?php
    // Print out the main part of the form.
    // Feel free to break this up and move the pieces within the array.
    //print drupal_render($form['submitted']);

    // Always print out the entire $form. This renders the remaining pieces of the
    // form that haven't yet been rendered above.
    print drupal_render_children($form);
  ?>
</div>
<div class="bch-order-comment"><?php print t("* In order to order another item, please fill another form."); ?></div>

<?php } 