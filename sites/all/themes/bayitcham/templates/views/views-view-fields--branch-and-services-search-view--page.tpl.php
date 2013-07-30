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

<div class="search-result-details">
  <div class="details-first-column">
    <div class="search-result-title"><?php print strip_tags($fields['title']->content); ?></div>
    <div class="details-first-column-others">
      <div class="dfc dfco-street"><?php print strip_tags($fields['field_street']->content); ?></div>
      <div class="dfc dfco-city"><?php print strip_tags($fields['field_branch_city']->content); ?></div>
      <div class="dfc dfco-phone"><?php print strip_tags($fields['field_phone']->content); ?></div>
      <div class="dfc dfco-email"><?php print $fields['field_branch_email']->content; ?></div>
    </div>
  </div>
  <div class="details-second-column">
    <?php //services ?>
    <?php
      $output = '';
      $servicestids = explode(',',strip_tags($fields['field_branch_services']->content));
      $servicestidsflip = array_flip($servicestids);
      $vocabname = taxonomy_vocabulary_get_names();
      if(isset($vocabname['services']->vid)){
        $ttree = taxonomy_get_tree($vocabname['services']->vid);
        //dsm($ttree);
        $servicesterms = array();
        foreach($ttree as $value){
          if (array_key_exists($value->tid, $servicestidsflip)) {
            $keyexists = 1;
          }
          else{
            $keyexists = 0;
          }
          $servicesterms[] = array('tid'=>$value->tid,'name'=>t($value->name),'is_available'=>$keyexists);
        }
        
        $output .= '<div class="search-results-services">';
        $output .= '<ul>';
        foreach($servicesterms as $value){
          $output .= '<li class="' . (($value['is_available'] == 1) ? 'avail' : 'not-avail') . '">'.$value['name'].'</li>';
        }
        $output .= '</ul>';
        $output .= '</div>';
        print $output;
      }
    ?>
  </div>
</div>

