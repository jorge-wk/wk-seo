

(function($){
  $(function(){

    // $('.wk-seo-social-form').addClass('active');
    doPreview();
    $('.yoast-seo-wk-seo-wrap').addClass('active');

    $('.wk-seo-tab-link').click(function(e){
      e.preventDefault();
      var clicked = $(this).attr('href');
      $('.wk-seo-tab-link').removeClass('active');
      $(clicked).addClass('active');
      if (clicked == '#wk-seo-social') {
        $('.wk-seo-social-form').addClass('active');
        $('.yoast-seo-wk-seo-wrap').removeClass('active');
      }
      else {
        $('.yoast-seo-wk-seo-wrap').addClass('active');
        $('.wk-seo-social-form').removeClass('active');
      }

    });


    $('.wk-seo-social-og-image input[type="submit"]').triggerHandler('imageSaveAction');
    // Unbind to trigger post and refresh with newly uploaded image
    $('.wk-seo-social-og-image input[type="submit"]').unbind().bind('imageSaveAction', function(event, data) {
       doPreview();
    });

    // Fix preview
    var strokes = 0;
    $('.wk-seo-social-form input,.wk-seo-social-form textarea').keyup(function(){
      doPreview();
    });

    function doPreview(){
      $('.wk-seo-social-preview-title').html($('.wk-seo-social-og-title').val());
      $('.wk-seo-social-preview-description').html($('.wk-seo-social-og-description').val());
      $('.wk-seo-social-preview-site-url').html($('.wk-seo-social-og-url').val());
      var image = $('.wk-seo-social-og-image a').attr('href');
      if (typeof image !== 'undefined' && image !== null) {
        $('.wk-seo-social-preview-image-wrap').css('background-image','url('+image+')');
      }
    }


  });

})(jQuery);
