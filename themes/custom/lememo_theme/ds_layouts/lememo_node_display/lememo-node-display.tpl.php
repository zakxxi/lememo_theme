<?php
/**
 * @file
 * Display Suite Lememo node display template.
 */

?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $top_wrapper; ?> class="<?php print $top_classes; ?>">
      <?php print $top; ?>
    </<?php print $top_wrapper; ?>>

    <div class ="societe-block-info row">

      <<?php print $header_society_left_wrapper; ?> class="columns small-6 <?php print $header_society_left_classes; ?>">
        <?php print $header_society_left; ?>
      </<?php print $header_society_left_wrapper; ?>>

      <<?php print $header_society_right_wrapper; ?> class="columns small-6 <?php print $header_society_right_classes; ?>">
        <?php print $header_society_right; ?>
      </<?php print $header_society_right_wrapper; ?>>    

    </div>

    <<?php print $header_sharethis_wrapper; ?> class="row <?php print $header_sharethis_classes; ?>">
      <?php print $header_sharethis; ?>
    </<?php print $header_sharethis_wrapper; ?>>

    <<?php print $header_resume_wrapper; ?> class="row <?php print $header_resume_classes; ?>">
      <?php print $header_resume; ?>
    </<?php print $header_resume_wrapper; ?>>

    <div class = "row">

      <<?php print $left_wrapper; ?> class="columns medium-8 <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>

      <<?php print $right_wrapper; ?> class="columns medium-4 <?php print $right_classes; ?>">
        <?php print $right; ?>
      </<?php print $right_wrapper; ?>>

    </div>

    <<?php print $bottom_wrapper; ?> class="<?php print $bottom_classes; ?>">
      <?php print $bottom; ?>
    </<?php print $bottom_wrapper; ?>>

</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
