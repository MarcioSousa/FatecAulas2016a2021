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
    
}]);



