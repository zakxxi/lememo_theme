<?php
/**
 * @file
 * Display Suite Lememo node display template.
 */

?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $top_wrapper; ?> class="<?php print $top_classes; ?>">
      <?php print $top; ?>
    </<?php print $top_wrapper; ?>>

    <div class ="row">

      <div class ="societe-block-info">

        <<?php print $header_society_top_wrapper; ?> class="columns small-8 small-centered medium-4 medium-offset-4 large-3 <?php print $header_society_top_classes; ?>">
          <?php print $header_society_top; ?>
        </<?php print $header_society_top_wrapper; ?>>

        <<?php print $header_society_left_wrapper; ?> class="no-padding columns small-5 medium-3 medium-offset-1 <?php print $header_society_left_classes; ?>">
          <?php print $header_society_left; ?>
        </<?php print $header_society_left_wrapper; ?>>

        <<?php print $header_society_right_wrapper; ?> class="columns small-7 medium-4 end <?php print $header_society_right_classes; ?>">
          <?php print $header_society_right; ?>
        </<?php print $header_society_right_wrapper; ?>>    
      </div>
    

    <<?php print $header_addthis_wrapper; ?> class="add-this-block columns medium-4 right <?php print $header_addthis_classes; ?>">
        <?php print $header_addthis; ?>
    </<?php print $header_addthis_wrapper; ?>>

    </div>

<div class = "resume-block">
    <<?php print $header_resume_wrapper; ?> class="row <?php print $header_resume_classes; ?>">
      <div class ="columns medium-7 medium-offset-1">
        <?php print $header_resume; ?>
      </div>

    </<?php print $header_resume_wrapper; ?>>

</div>
    <div class = "row">

      <<?php print $left_wrapper; ?> class="columns medium-8 <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>

      <<?php print $right_wrapper; ?> class="columns medium-4 <?php print $right_classes; ?>">
        <?php print $right; ?>
      </<?php print $right_wrapper; ?>>

    </div>

    <<?php print $bottom_wrapper; ?> class="fiche-bottom<?php print $bottom_classes; ?>">
      <?php print $bottom; ?>
    </<?php print $bottom_wrapper; ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
