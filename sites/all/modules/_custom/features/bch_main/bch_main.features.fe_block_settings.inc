<?php
/**
 * @file
 * bch_main.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function bch_main_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bch_blocks-contact_us_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'contact_us_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bch_blocks-donate_button'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'donate_button',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -26,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['bch_blocks-flags_link'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'flags_link',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -24,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bch_blocks-footer_credits'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'footer_credits',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bch_blocks-footer_icons'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'footer_icons',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -26,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bch_blocks-hp_icons_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hp_icons_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bch_blocks-page_footer_gallery'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'page_footer_gallery',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bch_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -27,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-bch_newsletter'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'bch_newsletter',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['md_slider-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'md_slider',
    'node_types' => array(),
    'pages' => '<?php
global $language;
if($laguage->language == \'he\'){
  return TRUE;
}
else{ return FALSE; }
?>',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => -18,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['md_slider-4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 4,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'md_slider',
    'node_types' => array(),
    'pages' => '<?php
global $language;
if($laguage->language == \'en\'){
  return TRUE;
}
else{ return FALSE; }
?>',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -28,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-secondary-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-secondary-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => -27,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['nice_menus-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'nice_menus',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'header2',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -15,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['nice_menus-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'nice_menus',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -28,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'bayitcham',
        'weight' => -25,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-views_for_hp_news-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'views_for_hp_news-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => -26,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-views_for_hp_niche_store-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'views_for_hp_niche_store-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-views_for_hp_page-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'views_for_hp_page-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bayitcham' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bayitcham',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
