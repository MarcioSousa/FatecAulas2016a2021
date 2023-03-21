<?php
/* Implementação REST */
// Definindo as variáveis para conexão ao BD
$db_host = '127.0.0.1';
$db_name = 'restaurante';
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
        
        //Rotas do Cadastro de Produtos
        $f3->route('GET /produtos','getProdutos');
        $f3->route('GET /produtos/@id','getProdutos');
        $f3->route('DELETE /produtos/@id','apagaProduto');
        $f3->route('POST /produtos', 'salvaProduto');
        
        
        //Executando as rotas
        $f3->run();
        
        //Funções das rotas
        function inicio(){
            echo 'API REST - Projeto Restaurante';
        }
        //-----------------------------------------------
        function getProdutos($f3){
            $sql = "select codigo, nome, fabricacao, valor from produto order by codigo";
            
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
        
        function getProduto($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select codigo, nome, fabricacao, valor from produto where codigo = ?";
            
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
        
        function apagaProduto($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from produtos where codigo = ?";
            
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
            $sql_insert = "insert into produto (nome, fabricacao, valor) values (?,?,?)";
            $sql_update = "update produto set nome=?, fabricacao = ?, valor = ? where codigo = ?";
            try{
                if($obj ->id != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->nome, 2=>$obj->fabricacao, 3=>$obj->valor, 4=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->nome, 2=>$obj->fabricacao, 3=>$obj->valor)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }

