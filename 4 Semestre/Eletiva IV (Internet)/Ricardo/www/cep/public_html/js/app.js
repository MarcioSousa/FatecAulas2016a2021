/* 
* Projeto Cep
 */
//criando o modulo
var app = angular.module('cepApp',[]);

//criando o controller
app.controller('cepController', function($scope, $http){
    $scope.aguarde = false;
    
    $scope.buscaCep = function(cep){
        $scope.aguarde = true;
        $http({method: 'GET', 
               url:'http://viacep.com.br/ws/'+cep+'/json/'
        }).success(function (data){
                $scope.dados = data;
                $scope.aguarde = false;
        }).error(function(){
                alert("Não foi possível obter o CEP!");
        });
    };
});

//Novo Controle
app.controller('horaController', function($scope, $interval){
    var tick = function(){
        $scope.relogio = Date.now();
    };
    tick();
    $interval(tick, 1000); //tempo em ms - milisegundos
});