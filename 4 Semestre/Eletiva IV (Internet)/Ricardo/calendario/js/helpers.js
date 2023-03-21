angular
  .module('mwl.calendar.docs')
  .factory('alert', function($uibModal) {

    function show(action, evento) {
      return $uibModal.open({
        templateUrl: 'conteudoModal.html',
        controller: function() {
          var calendario = this;
          calendario.action = action;
          calendario.evento = evento;
        },
        controllerAs: 'calendario'
      });
    }

    return {
      show: show
    };

  });
