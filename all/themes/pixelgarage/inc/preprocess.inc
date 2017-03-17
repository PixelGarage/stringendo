<?php
/**
 * Created by PhpStorm.
 * User: ralph
 * Date: 06.02.15
 * Time: 17:23
 */

/**
 * Preprocess variables for the html template.
 */
function pixelgarage_preprocess_html(&$vars) {
  // make sure jQuery UI and effects is loaded for anonymous users
  drupal_add_library('system', 'ui');
  //drupal_add_library('system', 'effects');

}

/**
 * Override or insert variables for the page templates.
 */
function pixelgarage_preprocess_page(&$vars) {
  // hide titles on login forms
  pg_login_preprocess_page($vars);

  // svg logo
  $vars['logo'] = str_replace(array('.jpg', '.png'), '.svg', $vars['logo']);

  //
  // add background circles and points
  $vars['points'] = _position_points();
  if ($vars['is_front']) {
    $vars['circles'] = _position_circles();
  }
}

function _position_points() {
  $points = array();
  $num_points = 20;
  $path = drupal_get_path('theme', 'pixelgarage') . '/images/kreis_weiss.png';
  $img_url = file_create_url($path);
  $img = "<img src='{$img_url}' class='bg-point' style='position: absolute; left:@x; top:@y;'/>";

  for ($idx = 0; $idx < $num_points; $idx++) {
    $x = mt_rand(0, 100);
    $y = mt_rand(0, 100);
    $str = str_replace('@x', $x . '%', $img);
    $points[] = str_replace('@y', $y . '%', $str);
  }
  return $points;
}

function _position_circles() {
  static $circles = array();
  if (empty($circles)) {
    // get the circle images
    $path = drupal_get_path('theme', 'pixelgarage') . '/images/kreis_verlauf_';
    for($idx = 1; $idx <= 6; $idx++) {
      $file = $path . $idx . '.png';
      $img_url = file_create_url($file);
      $circles[$idx] = "<img src='{$img_url}' class='bg-circle bg-circle-{$idx}' style='position: absolute; left:@x; top:@y;'/>";
    }
  }
  foreach ($circles as $idx => $circle) {
    $x = mt_rand(0, 100);
    $y = mt_rand(0, 100);
    $str = str_replace('@x', $x . '%', $circles[$idx]);
    $circles[$idx] = str_replace('@y', $y . '%', $str);
  }
  return $circles;
}

/* =============================================================================
 *      Artists Masonry
 * ========================================================================== */
/**
 * Adapts the proximity view, so that always two randomly chosen circles are visible
 * in the masonry.
 */
function pixelgarage_preprocess_views_view_proximity (&$vars) {
  $view = $vars['view'];
  if ($view->name != 'artists') return;

  // add testimonials for the social masonry
  $count = count($view->result);
  $vars['circles'] = _random_circles($count);
}

function _random_circles($count) {
  static $circles = array();
  if (empty($circles)) {
    // get the circle images
    $path = drupal_get_path('theme', 'pixelgarage') . '/images/kreis_verlauf_';
    for($idx = 1; $idx <= 6; $idx++) {
      $file = $path . $idx . '.png';
      $img_url = file_create_url($file);
      $circles[$idx] = "<img src='{$img_url}' class='image-circle image-circle-{$idx}'/>";
    }
  }

  // return a random testimonial list
  $keys = array_rand($circles, 2);
  if ($count > 6) {
    $i1 = mt_rand(0, 4);
    $i2 = mt_rand(4, $count);
    return array(
      $i1 => array($keys[0] => $circles[$keys[0]]),
      $i2 => array($keys[1] => $circles[$keys[1]]),
    );
  }
  else {
    $i1 = mt_rand(0, $count);
    return array(
      $i1 => array($keys[0] => $circles[$keys[0]]),
    );
  }
}



