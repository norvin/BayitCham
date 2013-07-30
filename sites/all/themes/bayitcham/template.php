<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * bayitcham theme.
 */

// http://drupal.org/node/154137
function bayitcham_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#default_value'] = t('Search...'); // Set a default value for the textfield

    // Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = '".t('Search...')."';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == '".t('Search...')."') {this.value = '';}";
    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='".t('Search...')."'){ alert('".t('Please enter a search')."'); return false; }";

    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Search...');
  }
  
  if ($form_id == 'views_exposed_form') {
    /*$form['tid']['#default_value'] = t('Choose a city'); // Set a default value for the textfield
    $form['tid_1']['#default_value'] = t('Choose a service');

    // Add extra attributes to the text box
    $form['tid']['#attributes']['onblur'] = "if (this.value == '') {this.value = '".t('Choose a city')."';}";
    $form['tid']['#attributes']['onfocus'] = "if (this.value == '".t('Choose a city')."') {this.value = '';}";
    $form['tid_1']['#attributes']['onblur'] = "if (this.value == '') {this.value = '".t('Choose a service')."';}";
    $form['tid_1']['#attributes']['onfocus'] = "if (this.value == '".t('Choose a service')."') {this.value = '';}";
    
    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.tid.value=='".t('Choose a city')."'){ alert('".t('Please type and choose a city')."'); return false; } if(this.tid_1.value=='".t('Choose a service')."'){ alert('".t('Please type and choose a service')."'); return false; }";*/

    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['tid']['#attributes']['placeholder'] = t('Choose a city');
    $form['tid_1']['#attributes']['placeholder'] = t('Choose a service');
  }
}

/**
 * Preprocess variables for the html template.
 */

function bayitcham_preprocess_html(&$vars) {
  global $theme_key;
  
  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

  $vars['classes_array'][] = browser_detect();
  $vars['classes_array'][] = os_detect();
}

function browser_detect() {
  $browsers = "mozilla msie gecko firefox ";
  $browsers .= "konqueror safari netscape navigator ";
  $browsers .= "opera mosaic lynx amaya omniweb chrome";

  $browsers = explode(" ", $browsers);

  // initialize the $globals variable
  $GLOBALS["ver"] = (empty($GLOBALS["ver"]) ? "" : $GLOBALS["ver"]);
  $GLOBALS["nav"] = (empty($GLOBALS["nav"]) ? "" : $GLOBALS["nav"]);
  
  $nua = strToLower( $_SERVER['HTTP_USER_AGENT']);

  $l = strlen($nua);
  for ($i=0; $i<count($browsers); $i++){
    $browser = $browsers[$i];
    $n = stristr($nua, $browser);
    if(strlen($n)>0){
      $GLOBALS["ver"] = "";
      $GLOBALS["nav"] = $browser;
      $j=strpos($nua, $GLOBALS["nav"])+$n+strlen($GLOBALS["nav"])+1;
      for (; $j<=$l; $j++){
        $s = substr ($nua, $j, 1);
        if(is_numeric($GLOBALS["ver"].$s) )
        $GLOBALS["ver"] .= $s;
        else
        break;
      }
    }
  }

  $my_browser = ($GLOBALS["nav"] . " " . $GLOBALS["ver"]);

  switch ($my_browser) {
  case "msie 6.0":
    $my_browser = "ie ie6 ie6-earlier ie7-earlier ie8-earlier";
    break;
  case "msie 7.0":
    $my_browser = "ie ie7 ie7-earlier ie8-earlier";
    break;
  case "msie 8.0":
    $my_browser = "ie ie8 ie8-earlier";
    break;
  case "msie 9.0":
    $my_browser = "ie ie9";
    break;
  }

  return $my_browser;
}

/* http://www.killersites.com/community/index.php?/topic/2562-php-to-detect-browser-and-operating-system/ */
function os_detect() {
  $myos = '';
  $ua = $_SERVER["HTTP_USER_AGENT"];
  // ---- Desktop ----

  // Linux
  $linux = strpos($ua, 'Linux') ? true : false;

  // Macintosh
  $mac = strpos($ua, 'Macintosh') ? true : false;

  // Windows
  $win = strpos($ua, 'Windows') ? true : false;
  
  if ($ua) {
    if ($linux) { // Linux Desktop
      $myos = 'linux';
    }
    if ($mac) { // Macintosh Desktop
      $myos = 'macintosh';
    }
    if ($win) { // Windows Desktop
      $myos = 'windows';
    }
  }
  
  return $myos;
}

/**
 * Override the theme_menu_link
 * Returns HTML for a menu link and submenu.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @ingroup themeable
 */
function bayitcham_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  if(strtolower($element['#title']) == strtolower('Search')){ // edit the text of the search button in the mega menu
    $element['#title'] = t('Search') . '<div style="font-size:14px;margin-top: -5px;">' . t('Service / branch') . '</div>';
    $element['#localized_options']['html'] = TRUE;
  }
  
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
   
  if($element['#original_link']['menu_name'] == 'main-menu'){
    $element['#localized_options']['attributes']['class'][] = 'menuopacityhover';
    if($element['#href'] <> '<block>'){
      $output .= l($element['#title'], $element['#href'], $element['#localized_options']);
    }
    //dsm($element);
  }
  
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}