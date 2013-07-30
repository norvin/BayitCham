<?php
/**
 * @file
 * bch_main.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function bch_main_locale_default_languages() {
  $languages = array();

  // Exported language: he.
  $languages['he'] = array(
    'language' => 'he',
    'name' => 'Hebrew',
    'native' => 'עברית',
    'direction' => 1,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'he',
    'weight' => 0,
  );
  return $languages;
}
