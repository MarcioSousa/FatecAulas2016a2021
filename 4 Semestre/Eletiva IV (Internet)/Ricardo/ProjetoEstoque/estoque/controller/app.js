/*
 * Criamos o nosso modulo
 * Observe que estamos carregando os seguintes modulos externos:
 * angularUtils.directives.dirPagination: paginacao dos dados
 * ngRoute: controle de rotas
 * ngMessages: mensagens personalizadas nos formulários
 * ngCookies: leitura e gravação de Cookies
 * ngMask: criação de máscaras de entrada de dados
 * naif.base64: converte o upload do arquivo na base64
 * ngSanitize: remove código malicioso do HTML
 * ui-select: permite filtrar os dados no combo
 **/
var app = angular.module('estoqueApp', ['angularUtils.directives.dirPagination', 'ngRoute', 'ngMessages', 'ngCookies', 'ngMask', 'naif.base64', 'ngSanitize', 'ui.select'])
//Definindo as rotas da aplicação
        .config(['$routeProvider', function($routeProvider){
                $routeProvider
                .when('/login', {
                    templateUrl: 'views/login.html'
                })
                .when('/menu', {
                    templateUrl: 'views/menu.html',
                    auth: function (usuarioLogado){
                        return usuarioLogado;
                    }
                })
                .otherwise({
                    redirectTo: '/login'
                });
}])
//Verifica se o usuário está logado a cada mudança de rota
    .run(function($rootScope, $location, $cookies){
   $rootScope.$on('$routeChangeStart', 
              function(ev, next, curr){
                  if(next.$$route) {
                  var user = $cookies.get('usuarioLogado');
                  var auth = next.$$route.auth;
                  if(auth && !auth(user)){
                      $location.path('/');
                  console.info('Usuário não está logado');
                  }
                  }
            
        });
});
        
app.controller('estoqueController',
        function ($scope, $http, $window, $rootScope, Configuracoes, $cookies) {
            /*
             * 
             * RESTFUL SERVICES
             * 
             **********************************************************/
            var urlBase = 'http://localhost/estoque/api';
            /*********************************************************
             *              
             */
            /*========================================================
             * USUARIOS
             ========================================================*/
$scope.logout = function (){
    //remove os cookies
    $cookies.remove('nomeUsuarioLogado');
    $cookies.remove('usuarioLogado');
    Configuracoes.nomeUsuario = '';
}
// Configurações do app
$scope.Configuracoes = Configuracoes;
$scope.Configuracoes.nomeUsuario = 
        $cookies.get('nomeUsuarioLogado');


$scope.validaLogin = function(login){
    //validando o usuario
$http.get(urlBase +"/login/"+login.usuario+"/"+login.senha)
        .success(function (data) {
            if(data == 'true'){//o usuário existe?
            
        var urlInicial = 
        "http://"+$window.location.host+"/estoque/#/menu";
        $window.location.href = urlInicial;
        $window.location; //direcionamos para o menu
        //armazenamos o cookie
        var nomeUsuario = login.usuario.toUpperCase();
        Configuracoes.nomeUsuario = nomeUsuario;
        var dataExpiracao = new Date();
        //definimos que o usuário ficará logado por 1 hora
     dataExpiracao.setMinutes(dataExpiracao.getMinutes()+60);
     $cookies.put('nomeUsuarioLogado', nomeUsuario, 
     {'expires': dataExpiracao});
     $cookies.put('usuarioLogado', 'true',
     {'expires': dataExpiracao});
     //utilizaremos no controle de rotas
     $rootScope.usuarioLogado = true;
            } else {
                BootstrapDialog.alert({
                    title: 'ATENÇÃO!',
message: 'O usuário ou a senha informados são inválidos!',
type: BootstrapDialog.TYPE_WARNING,
closable: true,
buttonLabel: 'Fechar'});
$scope.login = {}; //limpamos o que foi digitado
$rootScope.usuarioLogado = false;
                }
            }).error(function () {
                console.log('Erro ao validar o usuario!');
                alert('Verifique se o servidor está ok!');
});
};            

            /*========================================================
             * GRUPOS
             ========================================================*/
            $scope.grupo = {status: true}; //inicializamos o grupo com valor default true no status
            //Limpa o status touched dos campos do formulario
            $scope.limpaGrupo = function (nomeForm) {
                nomeForm.descricao.$touched = false;
            };
            //limpa o array do Grupo (utilizado quando o usuario cancela a inclusao ou edicao)
            $scope.limpaArrayGrupo = function () {
                $scope.grupo = {status: true};
            };
            // Carregando os grupos no array
            $scope.carregaGrupos = function () {
                getGrupos(); // Carrega todos os grupos    
            };
            // Carrega os dados do grupo pelo Id para a edição
            $scope.obtemGrupoPeloId = function (grupo) {
                $http.get(urlBase + "/grupos/" + grupo.id)
                        .success(function (data) {
                            $scope.grupo = data[0];
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do grupo');
                            $scope.grupo = "ERRO ao efetuar o SELECT!";
                        });
            };
            // Exibe caixa de diálogo para a exclusão
            $scope.confirmaExclusaoGrupo = function (grupo) {
                $scope.requisicaoServidor = {aguarde: true};
                var dialog = new BootstrapDialog.show({
                    title: 'Confirmação da Exclusão',
                    message: 'Atenção! Confirma a exclusão do grupo <strong>' + grupo.nome + '</strong>?<br> Esta operação não poderá ser desfeita!',
                    buttons: [{
                            icon: 'glyphicon glyphicon-ban-circle',
                            label: '(N)ão',
                            cssClass: 'btn-info',
                            hotkey: 78, // Código da tecla para o N (ASCII=78)
                            action: function () {
                                dialog.close();
                            }
                        }, {
                            icon: 'glyphicon glyphicon-ok-circle',
                            label: '(S)im',
                            cssClass: 'btn-danger',
                            hotkey: 83, // Código da tecla para o S (ASCII=83)
                            action: function () {
                                apagaGrupo(grupo.id);
                                dialog.close();
                            }
                        }
                    ]
                });
                $scope.requisicaoServidor = {aguarde: false};
            };
            // Função para salvar (insert ou update) os dados do grupo
            $scope.salvaGrupo = function (grupo) {
                $scope.requisicaoServidor = {aguarde: true};
                if (grupo.id === undefined) {
                    grupo.id = 0;
                }
                //inicialmente chamamos o verbo get/descricao para verificar se a descricao já existe no SGBD
                $http.get(urlBase + "/grupos/nome/" + grupo.nome + "/" + grupo.id).success(function (data) {
                    if (data != 0) { //Se o array retornou algo, é que existem registros
                        BootstrapDialog.alert({
                            title: 'ATENÇÃO!',
                            message: 'A descrição do grupo <strong>' + grupo.nome + '</strong> já existe no banco de dados!<br>Altere a descrição e tente salvar novamente.',
                            type: BootstrapDialog.TYPE_WARNING, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false          
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                        });
                    } else {//se a descrição está ok, iremos persistir o dado
                        $http.post(urlBase + "/grupos", grupo).success(function (data) {
                            console.info(JSON.stringify("Grupo salvo com sucesso!: " + data));
                            getGrupos();
                        }).error(function (error) {
                            console.error(JSON.stringify("Erro ao incluir o grupo: " + error));
                            BootstrapDialog.alert({
                                title: 'ATENÇÃO!',
                                message: 'Erro ao salvar o grupo:' + error,
                                type: BootstrapDialog.TYPE_DANGER, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                                closable: true, // <-- Valor default é false          
                                buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                            });
                        });
                        $scope.grupo = {status: true};
                        BootstrapDialog.alert({
                            title: 'Processo efetuado com sucesso!',
                            message: 'O registro foi armazenado com sucesso no banco de dados.',
                            type: BootstrapDialog.TYPE_SUCCESS, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'                                
                        });
                    }
                });
                $scope.requisicaoServidor = {aguarde: false};
            };
            function getGrupos() {
                $http.get(urlBase + "/grupos")
                        .success(function (data) {
                            $scope.grupos = data;
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do grupo');
                            $scope.grupos = "ERRO ao efetuar o SELECT!";
                        });
            }
            ;
            function apagaGrupo(codigo) {
                //inicialmente chamamos o verbo get/relacionado para verificar se o registro está vinculado com outra tabela
                $http.get(urlBase + "/grupos/relacionado/" + codigo).success(function (data) {
                    if (data != 0) { //Se o array retornou diferente de zero, é que existem registros
                        BootstrapDialog.alert({
                            title: 'ATENÇÃO!',
                            message: 'O grupo infelizmente NÃO PODE ser excluído, pois está vinculado a ' + data + ' produto(s)!',
                            type: BootstrapDialog.TYPE_WARNING, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false          
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                        });
                    } else { //caso contrario, providenciamos a exclusão.
                        $http.delete(urlBase + "/grupos/" + codigo).success(function (data) {
                            if (data != 1) {
                                BootstrapDialog.alert({
                                    title: 'ATENÇÃO!',
                                    message: 'Erro ao APAGAR o grupo:' + data,
                                    type: BootstrapDialog.TYPE_DANGER, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                                    closable: true, // <-- Valor default é false          
                                    buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                                });
                            } else {
                                console.info("Grupo ID " + codigo + " removido com sucesso!");
                                BootstrapDialog.alert({
                                    title: 'Exclusão efetuada com sucesso!',
                                    message: 'O registro foi excluído com sucesso do banco de dados.',
                                    type: BootstrapDialog.TYPE_SUCCESS, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                                    closable: true, // <-- Valor default é false
                                    buttonLabel: 'Fechar' // <-- Valor default é 'OK'                                
                                });
                            }
                            ;
                            getGrupos();
                        });
                    }
                });
            }
            ;
            /*========================================================
             * FIM das Funções relacionados aos GRUPOS
             ========================================================*/

            /*========================================================
             * PRODUTOS
             ========================================================*/
            $scope.produto = {status: true};
            // Carregando os produtos no array
            //Limpa o status touched dos campos do formulario
            $scope.limpaProduto = function (nomeForm) {
                nomeForm.nome.$touched = false;
                nomeForm.preco.$touched = false;
                nomeForm.foto.$touched = false;
                nomeForm.codigobarra.$touched = false;
                nomeForm.grupo.$touched = false;
            };
            //limpa o array do Produto (utilizado quando o usuario cancela a inclusao ou edicao)
            $scope.limpaArrayProduto = function () {
                $scope.produto = {status: true};
            };
            $scope.limpaFotoProduto = function (foto) {
                foto = {
                    base64: '',
                    filename: '',
                    filesize: '',
                    filetype: ''
                };
                //limpar o arquivo selecionado no input type="file"
                var control = $("#fotoproduto");
                control.replaceWith(control = control.clone(true));
            };
            $scope.carregaProdutos = function () {
                getProdutos(); // Carrega todos os produtos    
            };
            //Carrega os dados para exibir no grafico
            $scope.carregaGraficoProdutos = function () {
                getGraficoProdutos(); // Carrega todos os dados do grafico    
            };
            // Carrega os dados do produto pelo Id para a edição
            $scope.obtemProdutoPeloId = function (produto) {
                $http.get(urlBase + "/produtos/" + produto.id)
                        .success(function (data) {
                            $scope.produto = data[0];
                            $scope.produto.validade = new Date(data[0].validade);
                            $scope.produto.grupo = {id: data[0].id_grupo};
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do produto');
                            $scope.produto = "ERRO ao efetuar o SELECT!";
                        });
            };
            // Exibe caixa de diálogo para a exclusão
            $scope.confirmaExclusaoProduto = function (produto) {
                $scope.requisicaoServidor = {aguarde: true};
                var dialog = new BootstrapDialog.show({
                    title: 'Confirmação da Exclusão',
                    message: 'Atenção! Confirma a exclusão do produto ' + produto.nome + '? Esta operação não poderá ser desfeita!',
                    buttons: [{
                            icon: 'glyphicon glyphicon-ban-circle',
                            label: '(N)ão',
                            cssClass: 'btn-info',
                            hotkey: 78, // Código da tecla para o N (ASCII=78)
                            action: function () {
                                dialog.close();
                            }
                        }, {
                            icon: 'glyphicon glyphicon-ok-circle',
                            label: '(S)im',
                            cssClass: 'btn-danger',
                            hotkey: 83, // Código da tecla para o S (ASCII=83)
                            action: function () {
                                apagaProduto(produto.id);
                                dialog.close();
                            }
                        }
                    ]
                });
                $scope.requisicaoServidor = {aguarde: false};
            };
            // Função para salvar (insert ou update) os dados do produto
            $scope.salvaProduto = function (produto) {
                produto.validade = new Date(produto.validade).toISOString().slice(0, 10);
                $scope.requisicaoServidor = {aguarde: true};
                if (produto.id === undefined) {
                    produto.id = 0;
                }
                //inicialmente chamamos o verbo get/descricao para verificar se a descricao já existe no SGBD
                $http.get(urlBase + "/produtos/nome/" + produto.nome + "/" + produto.id).success(function (data) {
                    if (data != 0) { //Se o array retornou algo, é que existem registros
                        BootstrapDialog.alert({
                            title: 'ATENÇÃO!',
                            message: 'A descrição do produto <strong>' + produto.nome + '</strong> já existe no banco de dados!<br>Altere a descrição e tente salvar novamente.',
                            type: BootstrapDialog.TYPE_WARNING, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false          
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                        });
                    } else {//se a descrição está ok, iremos persistir o dado
                        $http.post(urlBase + "/produtos", produto).success(function (data) {
                            console.info(JSON.stringify("Produto salvo com sucesso!: " + data));
                            getProdutos();
                        }).error(function (error) {
                            console.error(JSON.stringify("Erro ao incluir o produto: " + error));
                            BootstrapDialog.alert({
                                title: 'ATENÇÃO!',
                                message: 'Erro ao salvar o produto:' + error,
                                type: BootstrapDialog.TYPE_DANGER, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                                closable: true, // <-- Valor default é false          
                                buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                            });
                        });
                        $scope.produto = {status: true};
                        BootstrapDialog.alert({
                            title: 'Processo efetuado com sucesso!',
                            message: 'O registro foi armazenado com sucesso no banco de dados.',
                            type: BootstrapDialog.TYPE_SUCCESS, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'                                
                        });
                    }
                });
                $scope.requisicaoServidor = {aguarde: false};
            };
            function getProdutos() {
                $http.get(urlBase + "/produtos")
                        .success(function (data) {
                            $scope.produtos = data;
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do produto');
                            $scope.produtos = "ERRO ao efetuar o SELECT!";
                        });
            }
            ;
            function getGraficoProdutos() {
                $http.get(urlBase + "/grupos/graficos")
                        .success(function (data) {
                            $scope.graficoProdutos = data;
                            var descricaoGrafico = new Array();
                            var dadosGrafico = new Array();
                            angular.forEach($scope.graficoProdutos, function (valor, chave) {
                                descricaoGrafico.push(valor['nome']);
                                dadosGrafico.push(valor['qtde']);
                            });
                            $scope.descricaoGrafico = descricaoGrafico.join(',').replace(/,/g, '|').split().toString();
                            $scope.dadosGrafico = dadosGrafico.toString();
                        })



                        .error(function () {
                            console.log('Erro ao obter os dados do produto');
                            $scope.graficoProdutos = "ERRO ao efetuar o SELECT!";
                        });
            }
            ;
            function apagaProduto(codigo) {
                //providenciamos a exclusão.
                $http.delete(urlBase + "/produtos/" + codigo).success(function (data) {
                    if (data !== 1) {
                        BootstrapDialog.alert({
                            title: 'ATENÇÃO!',
                            message: 'Erro ao APAGAR o produto:' + data,
                            type: BootstrapDialog.TYPE_DANGER, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false          
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                        });
                    } else {
                        console.info("Produto ID " + codigo + " removido com sucesso!");
                        BootstrapDialog.alert({
                            title: 'Exclusão efetuada com sucesso!',
                            message: 'O registro foi excluído com sucesso do banco de dados.',
                            type: BootstrapDialog.TYPE_SUCCESS, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                            closable: true, // <-- Valor default é false
                            buttonLabel: 'Fechar' // <-- Valor default é 'OK'                                
                        });
                    }
                    ;
                    getProdutos();
                });
            }
            ;
            /*========================================================
             * FIM das Funções relacionados aos PRODUTOS
             ========================================================*/

            /*========================================================
             * USUARIOS
             ========================================================*/
            $scope.limpaFoto = function (foto) {
                foto = {
                    base64: '',
                    filename: '',
                    filesize: '',
                    filetype: ''
                };
                //limpar o arquivo selecionado no input type="file"
                var control = $("#fotousuario");
                control.replaceWith(control = control.clone(true));
            };
            $scope.usuario = {status: true, tipo: 'administrador'};
            //Limpa o status touched dos campos do formulario
            $scope.limpaUsuario = function (nomeForm) {
                nomeForm.login.$touched = false;
                nomeForm.nome.$touched = false;
                nomeForm.senha.$touched = false;
                nomeForm.foto.$touched = false;
                nomeForm.confirmacao = '';
            };
            //limpa o array do Usuario (utilizado quando o usuario cancela a inclusao ou edicao)
            $scope.limpaArrayUsuario = function () {
                $scope.usuario = {status: true, tipo: 'administrador'};
            };
            // Carregando os usuarios no array
            $scope.carregaUsuarios = function () {
                getUsuarios(); // Carrega todos os usuarios   

            };
            function getUsuarios() {
                $http.get(urlBase + "/usuarios")
                        .success(function (data) {
                            $scope.usuarios = data;
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do usuario');
                            $scope.usuarios = "ERRO ao efetuar o SELECT!";
                        });
            }
            ;
// Função para salvar os dados do usuario
            $scope.salvaUsuario = function (usuario) {
                $scope.requisicaoServidor = {aguarde: true};
                if (usuario.id === undefined) {
                    usuario.id = 0;
                }
                $http.post(urlBase + "/usuarios", usuario).success(function (data) {
                    console.info(JSON.stringify("Usuário salvo com sucesso!: " + data));
                    getUsuarios();
                }).error(function (error) {
                    console.error(JSON.stringify("Erro ao incluir o usuário: " + error));
                    BootstrapDialog.alert({
                        title: 'ATENÇÃO!',
                        message: 'Erro ao salvar o usuário:' + error,
                        type: BootstrapDialog.TYPE_DANGER, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                        closable: true, // <-- Valor default é false          
                        buttonLabel: 'Fechar' // <-- Valor default é 'OK'
                    });
                });
                BootstrapDialog.alert({
                    title: 'Processo efetuado com sucesso!',
                    message: 'O registro foi armazenado com sucesso no banco de dados.',
                    type: BootstrapDialog.TYPE_SUCCESS, // <-- valor default é BootstrapDialog.TYPE_PRIMARY
                    closable: true, // <-- Valor default é false
                    buttonLabel: 'Fechar' // <-- Valor default é 'OK'                                
                });
                $scope.requisicaoServidor = {aguarde: false};
            };
            /*========================================================
             * FIM das Funções relacionados aos USUARIOS
             ========================================================*/

            /*========================================================
             * CLIENTES
             ========================================================*/

            // Carregando os clientes no array
            $scope.carregaClientes = function () {
                getClientes(); // Carrega todos os pedidos    
            };
            function getClientes() {
                $http.get(urlBase + "/clientes")
                        .success(function (data) {
                            $scope.clientes = data;
                        })
                        .error(function () {
                            console.log('Erro ao obter os dados do cliente');
                        });
            }
            ;
            /*========================================================
             * FIM das Funções relacionados aos CLIENTES
             ========================================================*/



        });
app.controller('horaController', function ($scope, $interval) {
    var tick = function () {
        $scope.clock = Date.now();
    };
    tick();
    $interval(tick, 1000);
});
/* 
 * FILTRO PERSONALIZADO PARA EXIBIR OS DADOS FORMATADOS NA TABELA
 */

//Ao inves de exibir True ou False, exibe Sim ou Não

app.filter('simNao', function () {
    return function (input) {
        return input ? 'Sim' : 'Não';
    };
});

/*
 * FABRICA DE CONFIGURACOES (SIMILAR A VARIAVEL GLOBAL) 
 */

app.factory('Configuracoes', function () {
    return {nomeUsuario: ''};
});
/*
 * DIRETIVAS (POSSIBILITA CRIAR NOVAS TAGS NO HTML)
 */

//utilizado para converter um valor string em numerico
app.directive('campoPreco', function () {
    return {
        require: 'ngModel',
        link: function (scope, element, attrs, ngModel) {
            ngModel.$parsers.push(function (value) {
                return '' + value;
            });
            ngModel.$formatters.push(function (value) {
                return parseFloat(value);
            });
        }
    };
});


