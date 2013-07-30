<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php //dsm($fields); ?>
<div class="views-hparticle-imagebg"><?php print $fields['field_page_image_in_hp']->content; ?></div>

<?php
$output = '';
$conbody = '';
$conbody .= '
  <div class="views-hparticle-block">' . '
    <div class="views-hparticle-blocktitle"><div class="views-hparticle-blocktitlebg"></div><div class="t1">' . t("Latest Article") . '</div></div>' . '
    <div class="views-hparticle-title-body">' . '
      <div class="views-hparticle-title">' . strip_tags($fields['title']->content) . '</div>' . '
      <div class="views-hparticle-body">' . strip_tags($fields['body']->content) . '</div>' . '
    </div>' . '
  </div>';

$output .= l($conbody,'node/'.strip_tags($fields['nid']->content),array('html'=>TRUE));
print $output;
?>