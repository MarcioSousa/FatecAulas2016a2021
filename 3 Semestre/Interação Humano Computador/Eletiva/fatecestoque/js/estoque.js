/* 
 * Projeto Estoque em AngularJS
 */
var app = angular.module('estoqueApp',[]);

app.controller('estoqueController',function($scope, $http){
    //definindo a Url Base da nossa API
    var urlBase ='http://localhost/fatecestoque/api';
    //Funções relacionadas ao cadastro de grupos
    function getGrupos(){
      $http.get(urlBase+"/grupos").success(function (data){
                    $scope.grupos = data;
                    console.log("Dados obtidos do banco!");
        }).error(function(){
            console.log("Erro ao obter os dados!");
            $scope.grupos = [];
        });
    };
    $scope.carregaGrupos = function(){
        getGrupos();
    };
    
    $scope.salvaGrupo = function(grupo){
        if(grupo.id === undefined){
            grupo.id=0;
        }
        $http.post(urlBase+"/grupos", grupo).
                success(function(data){
                    if (data !=0){
            alert("Registro salvo com sucesso!");
            getGrupos(); //recarregamos os dados
            $scope.grupo = {}; //limpamos o array
                    }
                }).
            error(function(error){
            alert("Ocorreu um  erro ao salvar!");
            console.log("Erro ao salvar:"+error)    
                    });
        };                 
function apagaGrupo(codigo){
    //inicialmente verificamos se está relacionado ao produto
    $http.get(urlBase+"/grupos/relacionado/"+codigo).
            success(function (data){
                if (data != 0){ //existem registros!
                    BootstrapDialog.alert({
                        title:'Atenção!',
                        message: 
'O grupo NÃO PODE ser apagado, pois está vinculado em '+data+
' produto(s)!',
closable: true,
type: BootstrapDialog.TYPE_DANGER,
buttonLabel: 'Fechar'
                    });
                } else {//iremos apagar!
$http.delete(urlBase+"/grupos/"+codigo).success(
        function (data){
            if (data == 1){
                BootstrapDialog.alert({
title: 'Tudo OK', message: 'Grupo removido com sucesso!',
type: BootstrapDialog.TYPE_SUCCESS, closable:true,
buttonLabel: 'OK'}); 
getGrupos(); // atualizamos os dados                          
            }
        }) ;                   
                }
     
    });
}

$scope.confirmaExclusaoGrupo = function(grupo){
    var dialog = new BootstrapDialog.show({
      title: 'Confirmação da exclusão',
      message: 'Confirma a exclusão do grupo '+grupo.nome+'?',
      buttons: [{label: 'Não', cssClass: 'btn-info',
                action: function(){
                    dialog.close();
                }
            },{
                label: 'Sim', cssClass: 'btn-danger',
                action: function(){
                    apagaGrupo(grupo.id);
                    dialog.close();
                }
            }]      
    });
};

$scope.obtemGrupoPeloId = function (grupo){
    $http.get(urlBase+"/grupos/"+grupo.id).success(
            function(data){
                $scope.grupo = data[0];
            }).error(function() {
                console.log("erro ao obter o grupo");
            });
};

}); //fecha controller 


