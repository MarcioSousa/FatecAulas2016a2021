/* Controle de Emprestimos */
var app = angular.module('meusEmprestimos', []);

app.controller('emprestimosController', ['$scope', function($scope){
        //Obtendo os dados salvors no navegador
        $scope.dadosSalvos = localStorage.getItem('emprestimos');
        
        //Atribuindo os dados salvos ao array de emprestimos
        $scope.emprestimos = ($scope.dadosSalvos!== null)? JSON.parse($scope.dadosSalvos): [];
        
        //Função para salvar um novo empréstimo
        $scope.adicionaEmprestimo = function(emprestimo){
            //adicionando o elemento recebido no final do array
            $scope.emprestimos.push(emprestimo);
            localStorage.setItem('emprestimos', angular.toJson($scope.emprestimos));
            //limpando array
            $scope.emprestimo = {};
        };
}]);