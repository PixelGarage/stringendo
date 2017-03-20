<?php
/**
 * @file
 * Bootstrap 12 template for Display Suite.
 */

$add_link = false;
if (!empty($field_link) && !empty($field_link[0]['url'])) {
  $link = $field_link[0]['url'];
  $play_button_url = file_create_url(drupal_get_path('theme', 'pixelgarage') . '/images/play_button.png');
  $add_link = true;
}
?>


<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <div class="row">
    <<?php print $central_wrapper; ?> class="col-sm-12 <?php print $central_classes; ?>">
      <?php if ($add_link): ?>
        <a href="<?php print $link; ?>" target="_blank">
          <?php print render($content['field_image']); ?>
          <div class="video-play-button"><img src="<?php print $play_button_url; ?>"></div>
        </a>
      <?php else: ?>
        <?php print render($content['field_image']); ?>
      <?php endif; ?>
    </<?php print $central_wrapper; ?>>
  </div>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
