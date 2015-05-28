(function ($) {  
  Drupal.behaviors.lememo_theme = {
    attach: function (context, settings) {

     // All our js code here

    // Open the gallery
		$('.openclearing').on('click', function(e) {
		    e.preventDefault();
		    $('[data-clearing] li img').eq($(this).data('thumb-index')).trigger('click');
		});

		// Sticky contact form
    $(".field-name-contact-form").sticky({topSpacing:100});



     // end our js code
     
   }
 };})(jQuery);