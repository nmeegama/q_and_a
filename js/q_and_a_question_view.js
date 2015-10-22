/**
 * Created by nmeegama on 10/22/15.
 */
(function ($) {
    /**
     * Load remote content after the main page loaded.
     */
    Drupal.behaviors.q_and_a = {
        attach: function(context, settings) {
            function handle_votes(action){
                $.post( '/q_and_a/question/'+Drupal.settings.q_and_a.qid+'/stats/vote', { action: action},function( data ) {
                    $('#q_votes span').html(data);
                });
            }
            $( "#q_views" ).load( '/q_and_a/question/'+Drupal.settings.q_and_a.qid+'/stats/view', function( response, status, xhr ) {});

            $('#q_votes #vote-plus').click(function(){
                handle_votes('plus')
            });
            $('#q_votes #vote-minus').click(function(){
                handle_votes('minus');
            });
        }
    };
})(jQuery);