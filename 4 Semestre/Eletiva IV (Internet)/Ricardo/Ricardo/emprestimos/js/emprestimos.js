var app = angular.module ("meusEmprestimos", []);

app.controller('EmprestimoController', ['$scope', 
    function($scope) {
        // Carrega os dados salvos
$scope.dadosSalvos = localStorage.getItem('emprestimos');
	$scope.emprestimos = ($scope.dadosSalvos!==null) ? JSON.parse($scope.dadosSalvos) : [];
	
	
	// Inclui o Emprestimo
    $scope.adicionaEmprestimo = function(emprestimo) {
			$scope.emprestimos.push(emprestimo);
            localStorage.setItem('emprestimos', angular.toJson($scope.emprestimos));
            $scope.emprestimo = {};
		};
        // Contar Empréstimos a Baixar
    $scope.baixar = function(){
        var contador = 0;
        angular.forEach($scope.emprestimos, function(emprestimo){
            contador += emprestimo.finalizado ? 1 : 0;
        });
        return contador;
    };
        //Baixa Empréstimos Encerrados
    $scope.baixaEncerrado = function(){
        //copiando o array de registros para um array temporário
        var tempEmprestimos = $scope.emprestimos;
        //inicializando o array vazio
        $scope.emprestimos = [];
        //Percorrendo todos os registros e adicionando apeas os não finalizados
        angular.forEach(tempEmprestimos, function(emprestimo){
            if(!emprestimo.finalizado) //note a negação!
                $scope.emprestimos.push(emprestimo);
        });
        //Salvando o Array
        localStorage.setItem('emprestimos', angular.toJson($scope.emprestimos));
    };
}]);



