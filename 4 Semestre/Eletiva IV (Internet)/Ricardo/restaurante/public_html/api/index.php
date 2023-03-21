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
        $f3->route('GET /produtos/@id','getProduto');
        $f3->route('DELETE /produtos/@id','apagaProduto');
        $f3->route('POST /produtos', 'salvaProduto');
        
        //Rotas do Cadastro de Serviços
        $f3->route('GET /servicos','getServicos');
        $f3->route('GET /servicos/@id','getServico');
        $f3->route('DELETE /servicos/@id','apagaServico');
        $f3->route('POST /servicos', 'salvaServico');
        
        //Rotas do Cadastro de Movimento
        $f3->route('GET /movimentos','getMovimentos');
        $f3->route('GET /movimentos/entrada','getMovimentosEntrada');
        $f3->route('GET /movimentos/saida','getMovimentosSaida');
        $f3->route('GET /movimentos/@id','getMovimento');
        $f3->route('DELETE /movimentos/@id','apagaMovimento');
        $f3->route('POST /movimentos', 'salvaMovimento');
        
        //Rotas do Cadastro de Pedidos
        $f3->route('GET /pedidos','getPedidos');
        $f3->route('GET /pedidos/@id','getPedido');
        $f3->route('DELETE /pedidos/@id','apagaPedido');
        $f3->route('POST /pedidos', 'salvaPedido');
        
        //Rotas do Cadastro de Pedido/Produto
        $f3->route('GET /pedidosprodutos','getPedidosProdutos');
        $f3->route('GET /pedidosprodutos/@id','getPedidoProduto');
        $f3->route('DELETE /pedidosprodutos/@id','apagaPedidoProduto');
        $f3->route('POST /pedidosprodutos', 'salvaPedidoProduto');
        
        //Rotas do Cadastro de Pedido/Serviço
        $f3->route('GET /pedidosservicos','getPedidosServicos');
        $f3->route('GET /pedidosservicos/@id','getPedidoServico');
        $f3->route('DELETE /pedidosservicos/@id','apagaPedidoServico');
        $f3->route('POST /pedidosservicos', 'salvaPedidoServico');
        
        //Rotas do Cadastro de Caixa
        $f3->route('GET /caixas','getCaixas');
        $f3->route('GET /caixas/@id','getCaixa');
        $f3->route('DELETE /caixas/@id','apagaCaixa');
        $f3->route('POST /caixas', 'salvaCaixa');
        
        //Rotas do Pedidos de Produtos e Serviços
        $f3->route('GET /pedidosprodutosservicos','getPedidosProdutosServicos');
        $f3->route('GET /pedidosprodutosservicos/@id','getPedidoProdutoServico');
        
        //Executando as rotas
        $f3->run();
        
        function inicio(){
            echo 'API REST - Projeto Restaurante';
        } 
        
        //--------- Funções de Produto ------------------
        function getProdutos($f3){
            $sql = "select codigo, nome, fabricacao, valor from produto order by codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
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
            $sql = "delete from produto where codigo = ?";
            
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
                if($obj ->codigo != 0){
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
        
        //--------- Funções de Serviço ------------------
        function getServicos($f3){
            $sql = "select codigo, nome, valor from servico order by codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getServico($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select codigo, nome, valor from servico where codigo = ?";
            
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
        function apagaServico($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from servico where codigo = ?";
            
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
        function salvaServico($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into servico (nome, valor) values (?,?)";
            $sql_update = "update servico set nome=?, valor = ? where codigo = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->nome, 2=>$obj->valor, 3=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->nome, 2=>$obj->valor)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        //--------- Funções de Movimento ------------------
        function getMovimentos($f3){
            $sql = "select M.codigo AS 'codMov', P.nome, M.dataVencimento, M.dataEntrada, M.valorTotal, M.dataSaida, M.qtde from movimento M inner join produto P ON  M.cod_produto = P.codigo order by M.codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getMovimentosEntrada($f3){
            $sql = "select M.codigo AS 'codMov', P.nome, M.dataVencimento, M.dataEntrada, M.valorTotal, M.qtde from movimento M inner join produto P ON  M.cod_produto = P.codigo WHERE M.dataSaida IS NULL order by M.codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getMovimentosSaida($f3){
            $sql = "select M.codigo AS 'codMov', P.nome, M.dataVencimento, M.dataSaida, M.valorTotal, M.qtde from movimento M inner join produto P ON  M.cod_produto = P.codigo WHERE M.dataEntrada IS NULL order by M.codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getMovimento($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select M.codigo AS 'codMov', P.nome, M.dataVencimento, M.dataEntrada, M.valorTotal, M.dataSaida from movimento M inner join produto P ON  M.cod_produto = P.codigo where M.codigo = ?";
            
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
        function apagaMovimento($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from movimento where codigo = ?";
            
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
        function salvaMovimento($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into movimento (cod_produto, dataVencimento, dataEntrada, valorTotal, dataSaida, qtde) values (?,?,?,?,?,?)";
            $sql_update = "update movimento set cod_produto =?, dataVencimento=?, dataEntrada=?, valorTotal=?, dataSaida=?, qtde=? where codigo = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_produto, 2=>$obj->dataVencimento, 3=>$obj->dataEntrada, 4=>$obj->valorTotal, 5=>$obj->dataSaida, 6=>$obj->qtde, 7=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_produto, 2=>$obj->dataVencimento, 3=>$obj->dataEntrada, 4=>$obj->valorTotal, 5=>$obj->dataSaida, 6=>$obj->qtde)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        //--------- Funções de Pedido ------------------
        function getPedidos($f3){
            $sql = "select codigo AS 'codPed', livre, valorPago, numeroMesa from pedido order by codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getPedido($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select codigo AS 'codPed', livre, valorPago, numeroMesa from pedido where codigo = ?";
            
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
        function apagaPedido($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from pedido where codigo = ?";
            
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
        function salvaPedido($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into pedido (livre, valorPago, numeroMesa) values (?,?,?)";
            $sql_update = "update pedido set livre=?, valorPago = ?, numeroMesa = ? where codigo = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->livre, 2=>$obj->valorPago, 3=>$obj->numeroMesa, 4=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->livre, 2=>$obj->valorPago, 3=>$obj->numeroMesa)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        
        //--------- Funções de Pedido / Produto ------------------
        function getPedidosProdutos($f3){
            $sql = "SELECT P.codigo AS 'CodPed', C.nome, B.qtde, C.valor AS 'Vl Unid', P.valorPago, P.numeroMesa, P.livre FROM pedido P INNER JOIN pedido_produto B ON B.cod_pedido = P.codigo INNER JOIN produto C ON C.codigo = B.cod_produto order by cod_pedido";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getPedidoProduto($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "SELECT P.codigo AS 'CodPed', C.nome, B.qtde, C.valor AS 'Vl Unid', P.valorPago, P.numeroMesa, P.livre FROM pedido P INNER JOIN pedido_produto B ON B.cod_pedido = P.codigo INNER JOIN produto C ON C.codigo = B.cod_produto where cod_pedido = ?";
            
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
        function apagaPedidoProduto($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from pedido_produto where cod_pedido = ?";
            
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
        function salvaPedidoProduto($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into pedido_produto (cod_pedido, cod_produto, qtde) values (?,?,?)";
            $sql_update = "update pedido_produto set cod_pedido=?, cod_produto = ?, qtde = ? where cod_pedido = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_pedido, 2=>$obj->cod_produto, 3=>$obj->qtde, 4=>$obj->cod_pedido)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_pedido, 2=>$obj->cod_produto, 3=>$obj->qtde)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        //--------- Funções de Pedido / Serviço ------------------
        function getPedidosServicos($f3){
            $sql = "SELECT P.codigo AS 'CodPed', C.nome, B.qtde, C.valor AS 'Vl Unid', P.valorPago, P.numeroMesa, P.livre FROM pedido P INNER JOIN pedido_servico B ON B.cod_pedido = P.codigo INNER JOIN servico C ON C.codigo = B.cod_servico order by cod_pedido";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getPedidoServico($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "SELECT P.codigo AS 'CodPed', C.nome, B.qtde, C.valor AS 'Vl Unid', P.valorPago, P.numeroMesa, P.livre FROM pedido P INNER JOIN pedido_servico B ON B.cod_pedido = P.codigo INNER JOIN servico C ON C.codigo = B.cod_servico where cod_pedido = ?";
            
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
        function apagaPedidoServico($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from pedido_servico where cod_pedido = ?";
            
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
        function salvaPedidoServico($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into pedido_servico (cod_pedido, cod_servico, qtde) values (?,?,?)";
            $sql_update = "update pedido_servico set cod_pedido=?, cod_servico = ?, qtde = ? where cod_pedido = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_pedido, 2=>$obj->cod_servico, 3=>$obj->qtde, 4=>$obj->cod_pedido)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_pedido, 2=>$obj->cod_servico, 3=>$obj->qtde)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        //--------- Funções de Caixa ------------------
        function getCaixas($f3){
            $sql = "select codigo AS 'CodCai', cod_pedido, valorPago, tipoPag, troco, datapagam from caixa order by codigo";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getCaixa($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "select codigo AS 'CodCai', cod_pedido, valorPago, tipoPag, troco, datapagam from caixa where codigo = ?";
            
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
        function apagaCaixa($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "delete from caixa where codigo = ?";
            
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
        function salvaCaixa($f3){
            //obtendo os dados JSON recebidos via POST
            $json = file_get_contents('php://input', true);
            
            //armazenando o conteúdo JSON em um array
            $obj = json_decode($json);
            /*teste
            echo "<pre>";
            var_dump($obj);
            echo "</pre>";*/
            $sql_insert = "insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (?,?,?,?,?)";
            $sql_update = "update caixa set cod_pedido=?, valorPago = ?, tipoPag = ?, troco = ?, datapagam = ? where codigo = ?";
            try{
                if($obj ->codigo != 0){
                    //se 0 faresmo insert
                    $f3->set('dados', $f3->get('DB')->exec($sql_update, array(1=>$obj->cod_pedido, 2=>$obj->valorPago, 3=>$obj->tipoPag, 4=>$obj->troco, 5=>$obj->datapagam, 6=>$obj->codigo)));
                }else{
                    $f3->set('dados', $f3->get('DB')->exec($sql_insert, array(1=>$obj->cod_pedido, 2=>$obj->valorPago, 3=>$obj->tipoPag, 4=>$obj->troco, 5=>$obj->datapagam)));
                }
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        
        //---- Funções de Pedidos de Produtos e Serviços --------
        function getPedidosProdutosServicos($f3){
            $sql = "SELECT A.cod_pedido, P.nome, A.qtde, C.numeroMesa, C.livre FROM pedido_produto A INNER JOIN produto P ON P.codigo = A.cod_produto INNER JOIN pedido C ON C.codigo = A.cod_pedido UNION SELECT B.cod_pedido, S.nome, B.qtde, D.numeroMesa, D.livre FROM pedido_servico B INNER JOIN servico S ON S.codigo = B.cod_servico INNER JOIN pedido D ON D.codigo = B.cod_pedido";
            try {
                $f3->set('dados', $f3->get('DB')->exec($sql));
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                http_response_code(500);
                die($ex->getMessage());
            }
        }
        function getPedidoProdutoServico($f3){
            //obtendo o parâmetro
            $id= $f3->get('PARAMS.id');
            $sql = "SELECT A.cod_pedido, P.nome, A.qtde, C.numeroMesa, C.livre FROM pedido_produto A "
                    . "INNER JOIN produto P ON P.codigo = A.cod_produto "
                    . "INNER JOIN pedido C ON C.codigo = A.cod_pedido "
                    . "WHERE A.cod_pedido = ? "
                    . "UNION "
                    . "SELECT B.cod_pedido, S.nome, B.qtde, D.numeroMesa, D.livre FROM pedido_servico B "
                    . "INNER JOIN servico S ON S.codigo = B.cod_servico "
                    . "INNER JOIN pedido D ON D.codigo = B.cod_pedido "
                    . "WHERE B.cod_pedido = ?";
            //Aqui tenho 2 interrogação, e agora?????
            try{
                $f3->set('dados', $f3->get('DB') ->exec($sql, array(1 =>$id, 2 =>$id)));
                //Pegaremos o resultado do select e convertemos em JSON
                echo json_encode($f3->get('dados'));
            } catch (Exception $ex) {
                //se ocorrer algum erro, retornamos o erro 500
                http_response_code(500);
                die($ex->getMessage());
            }   
        }