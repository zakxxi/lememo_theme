(function ($) {  
  Drupal.behaviors.lememo_theme = {
    attach: function (context, settings) {

    // All our js code here

    // Open the gallery
		$('.openclearing').on('click', function(e) {
		    e.preventDefault();
		    $('[data-clearing] li img').eq($(this).data('thumb-index')).trigger('click');
		});

    // Re-open the contact form if error
    if('#email-mail-popin > .error') {
        $('#email-mail-popin').foundation('reveal', 'open');
    }


    // Détecte la taille d'écran
    if (window.matchMedia("(min-width: 641px)").matches) {
      /* La largeur minimum de l'affichage est 600 px inclus */
          // Sticky contact form
        $(".field-name-contact-form").sticky({topSpacing:100});
    }

    // Smooth scroll
      $('.scrollto').click( function() { // Au clic sur un élément
        var page = $(this).attr('href'); // Page cible
        var speed = 900; // Durée de l'animation (en ms)
        $('html, body').animate( { scrollTop: $(page).offset().top }, speed ); // Go
        return false;
      });

     // end our js code
   }
 };})(jQuery);