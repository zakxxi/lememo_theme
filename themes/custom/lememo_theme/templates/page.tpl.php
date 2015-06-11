  <div class="row" id="top">
            <div class="columns medium-9 logo-block">
				<?php if ($logo): ?>
                	<img src="<?php print $logo ?>"/>
                <?php endif; ?>

                <span>vous présente</span> 

            </div>
            <div class="columns medium-3">
                <a href="<?php print theme_get_setting('lememo_theme_backlink')?>" target="_blank" class="button expand secondary">Accès à l’annuaire</a> 
            </div>
        </div>
    <?php print $messages ?>
    <?php print render($page['content']); ?>
<div class="footer">
            <div class="row">
	                <div class="columns medium-2"> 
                        <div class = "footer_logo">
                            <?php if ($logo): ?>
                                <img src="<?php print $logo ?>"/>
                            <?php endif; ?>
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

 <?php print theme_get_setting('lememo_theme_addthis_js')?>