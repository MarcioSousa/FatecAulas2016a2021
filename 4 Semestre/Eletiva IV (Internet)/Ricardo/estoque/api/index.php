<?php
/* Implementação REST */
// Definindo as variáveis para conexão ao BD
$db_host = '127.0.0.1';
$db_name = 'estoque';
$db_user = 'root';
$db_password = '';

//Carregando a lib Fat Free
$f3 = require('lib/base.php');
//atribuímos que estamos no modo desenvolvimento;
//o modo produção é 0
$f3->set('DEBUG',1);
//Conectando ao Mysql
$f3->set('DB', $db = new DB\SQL(
        "mysql:host=$db_host;port=3306;dbname=$db_name",
        $db_user, $db_password,
        array(\PDO::ATTR_ERRMODE => \PDO::ERRMODE_EXCEPTION)));
        
        //Definição das Rotas REST da nossa aplicação
        $f3->route('GET /','inicio');
        
        //Rotas do Cadastro de Grupos
        $f3->route('GET /grupos','getGrupos');
        $f3->route('GET /grupos/@id','getGrupo');
        $f3->route('DELETE /grupos/@id','apagaGrupo');
        $f3->route('POST /grupos', 'salvaGrupo');
        
        //Rotas do Cadastro de Produtos
        $f3->route('GET /produtos','getProdutos');
        $f3->route('GET /produtos/@id','getProduto');
        $f3->route('DELETE /produtos/@id','apagaProduto');
        $f3->route('POST /produtos', 'salvaProduto');
        
        //Rotas do Cadastro de Usuários
        $f3->route('GET /usuarios/login/@login/@senha','getLogin');
        $f3->route('GET /usuarios/@id','getUsuario');
        $f3->route('DELETE /usuarios/@id','apagaUsuario');
        $f3->route('POST /usuarios', 'salvaUsuario');
        
        //Rotas do Cadastro de Entrada de Produtos
        $f3->route('GET /entradas','getEntradas');
        $f3->route('GET /entradas/@id','getEntrada');
        $f3->route('DELETE /entradas/@id','apagaEntrada');
        $f3->route('POST /entradas', 'salvaEntrada');
        
        //Rotas do Cadastro de Saida de Produtos
        $f3->route('GET /saidas','getsaidas');
        $f3->route('GET /saidas/@id','getSaida');
        $f3->route('DELETE /saidas/@id','apagaSaida');
        $f3->route('POST /saidas', 'salvaSaida');
        
        
        //Executando as rotas
        $f3->run();
        
        //Funções das rotas
        function inicio(){
            echo 'API REST - Projeto Estoque';
        }
        //-----------------------------------------------
        function getGrupos($f3){
            $sql = "select id, nome, situacao, dataCriacao from grupos order by id";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function getGrupo($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select id, nome, situacao, dataCriacao from grupos where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, array(1 => $id)));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function apagaGrupo($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from grupos where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, $id));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function salvaGrupo($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into grupos (nome, situacao) values (?,?)";
            $sql_update = "update grupos set nome=?, situacao = ? where id = ?";
            try{
                if($obj ->id != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->nome, 2=>$obj->situacao, 3=>$obj->id)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->nome, 2=>$obj->situacao)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        //------------------------------------------------
        function getProdutos($f3){
            $sql = "select p.id, p.codigobarra, p.nome, preco, DATE_FORMAT(validade, '%y-%m-%dT%10:00:00Z') as validade, p.situacao, foto, id_grupo, g.nome as grupo from grupos g INNER JOIN produtos p on p.id_grupo = g.id";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        function getProduto($f3){
            $id = $f3->get('PARAMS.id');
            $sql = "select p.id, p.codigobarra, p.nome, preco, DATE_FORMAT(validade, '%y-%m-%dT%10:00:00Z') as validade, p.situacao, foto, id_grupo, g.nome as grupo from grupos g INNER JOIN produtos p on p.id_grupo = g.id WHERE p.id = ?";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql, array(1=>$id)));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        function apagaProduto($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from produtos where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, $id));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function salvaProduto($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into produtos (codigobarra, nome, preco, validade, situacao, foto, id_grupo) values (?,?,?,?,?,?,?)";
            $sql_update = "update grupos set codigobarra=?, nome=?, preco=?, validade=?, situacao=?, foto=?, id_grupo=? where id = ?";
            try{
                if($obj ->id != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->codigobarra, 2=>$obj->nome, 3=>$obj->preco, 4=>$obj->validade, 5=>$obj->situacao, 6=>$obj->foto, 7=>$obj->id_grupo, 8=>$obj->id)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->codigobarra, 2=>$obj->nome, 3=>$obj->preco, 4=>$obj->validade, 5=>$obj->situacao, 6=>$obj->foto, 7=>$obj->id_grupo)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        //------------------------------------------------
        function getLogin($f3){
            $loginValido = false;
            $login = $f3->get('PARAMS.login');
            $senha = $f3->get('PARAMS.senha');
            $sql = "select * from usuarios where login =? and AES_ENCRYPT(?,'fatec') = senha";
            //iremos contar o número de registros do select
            $f3->set('dados', count($f3->get('DB')->exec($sql, array(1=> $login, 2=> $senha))));
            //se o número for igual a 1, usuário é válido!
            if($f3->get('dados')==1){
                $loginValido=true;
            }
            echo json_encode($loginValido);
        }
        
        function getUsuario($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select id, nome, situacao, dataCriacao from grupos where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, array(1 => $id)));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        //------------------------------------------------
        function getEntradas($f3){
            $sql = "select id, cod_produto, vencimento, dataEnt, valorTotal, qtde from entrada order by id";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }  
        }
        
        function getEntrada($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select id, cod_produto, vencimento, dataEnt, valorTotal, qtde from entrada where codigo = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, array(1 => $id)));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function apagaEntrada($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from entrada where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, $id));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function salvaEntrada($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into entrada (cod_produto, vencimento, dataEnt, valorTotal, qtde) values (?,?,?,?,?)";
            $sql_update = "update grupos set cod_produto=?, vencimento = ?, dataEnt = ?, valorTotal = ?, qtde = ? where id = ?";
            try{
                if($obj ->id != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_produto, 2=>$obj->vencimento, 3=>$obj->dataEnt, 4=>$obj->valorTotal, 5=>$obj->valorTotal, 6=>$obj->qtde, 7=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_produto, 2=>$obj->vencimento, 3=>$obj->dataEnt, 4=>$obj->valorTotal, 5=>$obj->valorTotal, 6=>$obj->qtde)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        //------------------------------------------------
        function getSaidas($f3){
            $sql = "select id, cod_produto, dataSaida, qtde from saida order by id";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }  
        }
        
        function getSaida($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select id, cod_produto, dataSaida, qtde from saida where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, array(1 => $id)));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function apagaSaida($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from saida where id = ?";
            
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, $id));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }
        
        function salvaSaida($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into saida (cod_produto, dataSaida, qtde) values (?,?,?)";
            $sql_update = "update grupos set cod_produto=?, dataSaida = ?, qtde = ? where id = ?";
            try{
                if($obj ->id != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_produto, 2=>$obj->dataSaida, 3=>$obj->qtde, 4=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_produto, 2=>$obj->dataSaida, 3=>$obj->qtde)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        