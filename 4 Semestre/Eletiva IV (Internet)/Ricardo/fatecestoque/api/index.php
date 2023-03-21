<?php

/* Projeto REST em PHP
  Data: 23/08
  Autor: Fatec Itu
  Tecnologia: Fat Free e PHP
 */

//definindo as variaveis para a conexão ao SGBD
$db_host = '127.0.0.1';
$db_name = 'estoque';
$db_user = 'root';
$db_password = '';
//carregando o FAT Free
$f3 = require('lib/base.php');
//atribuimos que estamos no modo desenvolvimento
$f3->set('DEBUG', 1); /* em producao, 0 */
//conectando ao MySQL
$f3->set('DB', $db = new DB\SQL(
        "mysql:host=$db_host;port=3306;
      dbname=$db_name", $db_user, $db_password, array(\PDO::ATTR_ERRMODE =>
    \PDO::ERRMODE_EXCEPTION)));
// Definindo as rotas do nosso web service
$f3->route('GET /', 'inicio');

function inicio() {
    echo "API REST - Projeto Estoque Fatec";
}

// REST dos Grupos
$f3->route('GET /grupos', 'getGrupos');
$f3->route('GET /grupos/@id', 'getGrupo');
$f3->route('DELETE /grupos/@id', 'apagaGrupo');
$f3->route('POST /grupos', 'salvaGrupo');

$f3->route('GET /grupos/relacionado/@id',
                                     'getGrupoRelacionado');

$f3->run(); //cria as rotas na navegação

function getGrupos($f3) {
    $sql = "select id, nome from grupos";
    try {
        $f3->set('dados', $f3->get('DB')->exec($sql));
//pegaremos o select e retornaremos o JSON
        echo json_encode($f3->get('dados'));
    } catch (PDOException $e) {
        //se deu algum erro retornamos o 
        //codigo 500 e a mensagem de erro
        http_response_code(500);
        die($e->getMessage());
    }
}

function getGrupo($f3) {
    $id = $f3->get('PARAMS.id');
    $sql = "select id, nome from grupos where id = ?";
    try {
        $f3->set('dados', $f3->get('DB')->exec($sql, array(1 => $id)));
        echo json_encode($f3->get('dados'));
    } catch (PDOException $e) {
        http_response_code(500);
        die($e->getMessage());
    }
}

function apagaGrupo($f3) {
    $id = $f3->get('PARAMS.id');
    $sql = "delete from grupos where id=?";
    try {
        $f3->set('dados', $f3->get('DB')->
                        exec($sql, $id));
//se apagou, retorna o nr registros removidos
        echo json_encode($f3->get('dados'));
    } catch (PDOException $e) {
        http_response_code(500);
        die($e->getMessage());
    }
}

function salvaGrupo($f3) {
    //obtendo os dados enviados
    $json = file_get_contents('php://input', true);
    //armazenamos o conteudo em um objeto
    $obj = json_decode($json);
    $sql_insert = "insert into grupos(nome) values (?)";
    $sql_update = "update grupos set nome = ? where id =?";
    try {
        if ($obj->id != 0) { //fazemos o update
            $f3->set('dados', $f3->get('DB')->exec(
                            $sql_update, array(1 => $obj->nome,
                        2 => $obj->id)));
        } else {
            $f3->set('dados', $f3->get('DB')->exec(
                            $sql_insert, array(1 => $obj->nome)));
        }
    echo json_encode($f3->get('dados'));
    } catch (PDOException $e) {
        http_response_code(500);
        die($e->getMessage());
    }
}

function getGrupoRelacionado($f3){
    $id = $f3->get('PARAMS.id');
    $sql = "select * from produtos where id_grupo = ?";
    try{
        $f3->get('DB')->exec($sql, array(1=> $id));
        echo $f3->get('DB')->count();
    } catch (PDOException $e) {
        http_response_code(500);
        die($e->getMessage());
    }
} 


?>














