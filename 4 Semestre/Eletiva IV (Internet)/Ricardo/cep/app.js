var app = angular.module('cepApp', []);

app.controller('cepController',  function($scope, $http) {
  $scope.aguarde = false;
  
  $scope.buscaCep =  function (cep) {
                $scope.aguarde = true;
                $http({method: 'GET', url: 'https://viacep.com.br/ws/'+cep+'/json/'})           
                        .success(function (data) {
                            $scope.dados = data;                                
                    /*
                                // Armazena o Cookie
                                var cepDigitado = cep;
                                var dataExpiracao = new Date();
                                //Definimos que o cookie ficará armazenado no maximo 30 minutos
                                dataExpiracao.setMinutes(dataExpiracao.getMinutes() + 30);                                
                                $cookies.put('cepDigitado', cepDigitado, {'expires': dataExpiracao});*/
                                $scope.aguarde = false;
                            })                        
                        .error(function () {
                    alert("Nao foi possivel obter o CEP!");
                        })
            };
  
  
});
