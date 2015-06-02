<!-- PAGE HEADER-->
  <div class="row" id="top">
            <div class="columns medium-9 logo-block">
				<!-- LOADING LOGO-->
				<?php if ($logo): ?>
                	<img src="<?php print $logo ?>"/>
                <?php endif; ?>

                <span>vous présente</span> 

            </div>
            <div class="columns medium-3">
            	<!-- LOADING BACKLINK-->
                <a href="<?php print theme_get_setting('lememo_theme_backlink')?>" target="_blank" class="button expand secondary">Accès à l’annuaire</a> 
            </div>
        </div>
    <?php print $messages ?>
    <?php print render($page['content']); ?>
<!-- PAGE FOOTER-->
<div class="footer">
            <div class="row">
	                <div class="columns medium-2"> 
                        <div class = "footer_logo">
                            <?php if ($logo): ?>
                                <img src="<?php print $logo ?>"/>
                            <?php endif; ?>
                            <p>Annuaires profesionnels</p>

    	               </div>
                    </div>

            	<?php if ($page['footer_center']): ?>
	                <div class="columns medium-3 medium-offset-1"> 
					<?php print render($page['footer_center']); ?>
	                </div>
                <?php endif; ?>

            	<?php if ($page['footer_right']): ?>                
	                <div class="columns medium-2 medium-offset-1"> 
					<?php print render($page['footer_right']); ?>
	                </div>
                <?php endif; ?>

                    <div class="columns medium-3"> 
                    <a href="<?php print theme_get_setting('lememo_theme_backlink')?>" target="_blank" class="button expand secondary">Accès à l’annuaire</a> 
                    </div>
            </div>

              
        </div>

             	<?php if ($page['footer_bottom']): ?>
                <div class="footer_bottom">
                    <div class="row">               
    	                <div class="small-12"> 
    					<?php print render($page['footer_bottom']); ?>
    	                </div>
                    </div>
                </div>
                <?php endif; ?>	                


 <!-- ADDTHIS SCRIPTS -->

 <?php print theme_get_setting('lememo_theme_addthis_js')?>

<!-- END OF ADDTHIS SCRIPTS -->