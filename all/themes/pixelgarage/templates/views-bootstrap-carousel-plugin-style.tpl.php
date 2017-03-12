<?php
$prev_img_url = file_create_url(drupal_get_path('theme', 'pixelgarage') . '/images/pfeil_links.svg');
$next_img_url = file_create_url(drupal_get_path('theme', 'pixelgarage') . '/images/pfeil_rechts.svg');
?>

<div id="views-bootstrap-carousel-<?php print $id ?>" class="carousel-fade <?php print $classes ?>" <?php print $attributes ?>>
  <?php if ($indicators): ?>
    <!-- Carousel indicators -->
    <ol class="carousel-indicators">
      <?php foreach ($rows as $key => $value): ?>
        <li data-target="#views-bootstrap-carousel-<?php print $id ?>" data-slide-to="<?php print $key ?>" class="<?php if ($key === 0) print 'active' ?>"></li>
      <?php endforeach ?>
    </ol>
  <?php endif ?>

  <!-- Carousel items -->
  <div class="carousel-inner">
    <?php foreach ($rows as $key => $row): ?>
      <div class="item <?php if ($key === 0) print 'active' ?>">
        <?php print $row ?>
      </div>
    <?php endforeach ?>
  </div>

  <?php if ($navigation): ?>
    <!-- Carousel navigation -->
    <a class="carousel-control left" href="#views-bootstrap-carousel-<?php print $id ?>" data-slide="prev">
      <img src="<?php print $prev_img_url ?>" class="left"/>
      <span class="sr-only">Previous</span>
    </a>
    <a class="carousel-control right" href="#views-bootstrap-carousel-<?php print $id ?>" data-slide="next">
      <img src="<?php print $next_img_url ?>" class="right"/>
      <span class="sr-only">Next</span>
    </a>
  <?php endif ?>
</div>
