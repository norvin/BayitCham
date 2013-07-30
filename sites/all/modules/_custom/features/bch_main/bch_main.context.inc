<?php
/**
 * @file
 * bch_main.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bch_main_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_page_view';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['basic_page_view'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact_us_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bch_blocks-contact_us_block' => array(
          'module' => 'bch_blocks',
          'delta' => 'contact_us_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['contact_us_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'custom_bch_front_page';
  $context->description = 'Custom BCH Front Page';
  $context->tag = '';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'he' => 'he',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'md_slider-1' => array(
          'module' => 'md_slider',
          'delta' => '1',
          'region' => 'hp_slider',
          'weight' => '-30',
        ),
        'bch_blocks-hp_icons_block' => array(
          'module' => 'bch_blocks',
          'delta' => 'hp_icons_block',
          'region' => 'hp_slider',
          'weight' => '-28',
        ),
        'views-views_for_hp_news-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_news-block',
          'region' => 'hp_maincontent',
          'weight' => '-10',
        ),
        'views-views_for_hp_page-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_page-block',
          'region' => 'hp_maincontent',
          'weight' => '-9',
        ),
        'views-views_for_hp_niche_store-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_niche_store-block',
          'region' => 'hp_maincontent',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom BCH Front Page');
  $export['custom_bch_front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'custom_bch_front_page_en';
  $context->description = 'Custom BCH Front Page for English';
  $context->tag = '';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'en' => 'en',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'md_slider-4' => array(
          'module' => 'md_slider',
          'delta' => '4',
          'region' => 'hp_slider',
          'weight' => '-10',
        ),
        'bch_blocks-hp_icons_block' => array(
          'module' => 'bch_blocks',
          'delta' => 'hp_icons_block',
          'region' => 'hp_slider',
          'weight' => '-9',
        ),
        'views-views_for_hp_news-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_news-block',
          'region' => 'hp_maincontent',
          'weight' => '-10',
        ),
        'views-views_for_hp_page-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_page-block',
          'region' => 'hp_maincontent',
          'weight' => '-9',
        ),
        'views-views_for_hp_niche_store-block' => array(
          'module' => 'views',
          'delta' => 'views_for_hp_niche_store-block',
          'region' => 'hp_maincontent',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom BCH Front Page for English');
  $export['custom_bch_front_page_en'] = $context;

  return $export;
}
