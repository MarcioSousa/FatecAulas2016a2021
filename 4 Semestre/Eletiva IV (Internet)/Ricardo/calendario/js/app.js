angular.module('mwl.calendar.docs', ['mwl.calendar', 'ngAnimate', 'ui.bootstrap', 'colorpicker.module']);
angular
  .module('mwl.calendar.docs') //you will need to declare your module with the dependencies ['mwl.calendar', 'ui.bootstrap', 'ngAnimate']
  .controller('calendarioController', function(moment, alert, calendarConfig) { 
    
	var calendario = this;    
    calendario.calendarView = 'day';
    calendario.viewDate = new Date();
    var actions = [{
      label: '<i class=\'glyphicon glyphicon-pencil\'></i>',
      onClick: function(args) {
        alert.show('Editou', args.calendarEvent);
      }
    }, {
      label: '<i class=\'glyphicon glyphicon-remove\'></i>',
      onClick: function(args) {
        alert.show('Apagou', args.calendarEvent);
      }
    }];
    calendario.eventos = [
      {
        title: 'Arraia da Fatec',
        color: calendarConfig.colorTypes.warning,
        startsAt: moment().startOf('week').subtract(2, 'days').add(8, 'hours').toDate(),
        endsAt: moment().startOf('week').add(1, 'week').add(9, 'hours').toDate(),
        draggable: true,
        resizable: true,
        actions: actions
      }, {
        title: 'Prova do Levi',
        color: calendarConfig.colorTypes.info,
        startsAt: moment().subtract(1, 'day').toDate(),
        endsAt: moment().add(5, 'days').toDate(),
        draggable: true,
        resizable: true,
        actions: actions
      }, {
        title: 'Outro Evento',
        color: calendarConfig.colorTypes.important,
        startsAt: moment().startOf('day').add(7, 'hours').toDate(),
        endsAt: moment().startOf('day').add(19, 'hours').toDate(),
        recursOn: 'year',
        draggable: true,
        resizable: true,
        actions: actions
      }
    ];

    calendario.cellIsOpen = true;

    calendario.addEvent = function() {
      calendario.eventos.push({
        title: 'Novo Evento',
        startsAt: moment().startOf('day').toDate(),
        endsAt: moment().endOf('day').toDate(),
        color: calendarConfig.colorTypes.important,
        draggable: true,
        resizable: true
      });
    };

    calendario.eventClicked = function(event) {
      alert.show('Clicou', event);
    };

    calendario.eventEdited = function(event) {
      alert.show('Editou', event);
    };

    calendario.eventDeleted = function(event) {
      alert.show('Apagado', event);
    };

    calendario.eventTimesChanged = function(event) {
      alert.show('Alterou o horário', event);
    };

    calendario.toggle = function($event, field, event) {
      $event.preventDefault();
      $event.stopPropagation();
      event[field] = !event[field];
    };

    calendario.timespanClicked = function(date, cell) {

      if (calendario.calendarView === 'month') {
        if ((calendario.cellIsOpen && moment(date).startOf('day').isSame(moment(calendario.viewDate).startOf('day'))) || cell.eventos.length === 0 || !cell.inMonth) {
          calendario.cellIsOpen = false;
        } else {
          calendario.cellIsOpen = true;
          calendario.viewDate = date;
        }
      } else if (calendario.calendarView === 'year') {
        if ((calendario.cellIsOpen && moment(date).startOf('month').isSame(moment(calendario.viewDate).startOf('month'))) || cell.eventos.length === 0) {
          calendario.cellIsOpen = false;
        } else {
          calendario.cellIsOpen = true;
          calendario.viewDate = date;
        }
      }

    };

  });
