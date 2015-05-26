(function ($) {  
  Drupal.behaviors.lememo_theme = {
    attach: function (context, settings) {

     // All our js code here
		$('.openclearing').on('click', function(e) {
		    e.preventDefault();
		    $('[data-clearing] li img').eq($(this).data('thumb-index')).trigger('click');
		});
     // end our js code
     
   }
 };})(jQuery);