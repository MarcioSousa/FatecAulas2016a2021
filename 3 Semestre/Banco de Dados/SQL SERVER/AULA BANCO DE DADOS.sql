/*MODELAGEM BÁSICA*/

TABELA CLIENTE

NOME CARACTER(30)
CPF NUMERICO(11)
EMAIL CARACTER(30)
TELEFONE CARACTER(30)
SEXO CARACTER(1)
ENDEREÇO CARACTER(100)

/*PROCESSO DE MODELAGEM*/

/*ADM DE DADOS*/
MODELAGEM CONCEITUAL - RASCUNHO
MODELAGEM LÓGICA - PROGRAMA COMO BRMODELO
/*AD OU DBA*/
MODELAGEM FÍCICA - SCRIPT DO BANCO DE DADOS

/*MODELO FÍSICO*/
/*CRIAR UM BANCO*/
CREATE DATABASE PROJETO;
/*CONECTANDO*/
USE PROJETO;
/*CRIAR TABELA*/
CREATE TABLE CLIENTE(
    NOME VARCHAR(30),
	SEXO CHAR(1),
	EMAIL VARCHAR(30),
	CPF INT(11),
	TELEFONE VARCHAR(30),
	ENDEREÇO VARCHAR(100)
);

/*VERIFICANDO AS TABELAS*/
SHOW TABLES;

/* DESCREVENDO TABELAS */
DESC CLIENTE;

/*FORMA 01 - EXCLUINDO COLUNAS */
INSERT INTO CLIENTE VALUES('JOAO','M','JOAO@GMAIL.COM',988638273,'22923110','MAIA LACERDA - ESTACIO - RIO DE JANEIRO - RJ');
INSERT INTO CLIENTE VALUES('CELIA','F','CELIA@GMAIL.COM',541521456,'25078869','RIACHUELO - CENTRO - RIO DE JANEIRO - RJ');
INSERT INTO CLIENTE VALUES('JORGE','M',NULL,885755896,'58748895','OSCAR CURY - BOM RETIRO - PATOS DE MINAS - MG');

/*FORMA 02 - COLOCANDO AS COLUNAS*/
INSERT INTO CLIENTE(NOME,SEXO,ENDEREÇO, TELEFONE, CPF) VALUES('LILIAN','F','SENADOR SOARES - TIJUCA - RIO DE JANEIRO - RJ','94778569', 887774856);

/*FORMA 03 - INSERT COMPACTO - SOMENTE MYSQL */
INSERT INTO CLIENTE VALUES('ANA','F','ANA@GLOBO.COM',85548522,'548556985','PRES ANTONIO CARLOS - CENTRO - SAO PAULO - SP'),
						  ('CARLA','F','CARLA@TERATI.COM.BR',7745858,'66587458','SAMUEL SILVA - CENTRO - BELO HORIZONTE - Mg');
						 
/*=================================================*/					  
/*=========== A009 - O COMANDO SELECT =============*/
/*=================================================*/
SELECT NOW();
SELECT 'FELIPE MAFRA';
SELECT 'BANCO DE DADOS';

/* ALIAS DE COLUNAS*/
SELECT 'FELIPE MAFRA' AS PROFESSOR;
SELECT NOME, SEXO, EMAIL FROM CLIENTE;
SELECT ENDEREÇO, SEXO, EMAIL FROM CLIENTE;

/* APENAS PARA FINS ACADEMICOS */
SELECT * FROM CLIENTE;

/*FILTRAGEM*/
SELECT NOME, SEXO FROM CLIENTE
WHERE SEXO = 'M';

SELECT NOME, ENDEREÇO FROM CLIENTE
WHERE SEXO = 'F';

SELECT NOME, SEXO FROM CLIENTE
WHERE ENDEREÇO = 'RJ';

/*UTILIZANDO O LIKE*/
SELECT NOME, SEXO FROM CLIENTE
WHERE ENDEREÇO LIKE 'RJ';

/*CARACTER CORING %*/
SELECT NOME, SEXO FROM CLIENTE
WHERE ENDEREÇO LIKE '%RJ';

SELECT NOME, SEXO, ENDEREÇO FROM CLIENTE
WHERE ENDEREÇO LIKE '%RJ';

SELECT NOME, SEXO, ENDEREÇO FROM CLIENTE
WHERE ENDEREÇO LIKE '%CENTRO%';
/*=================================================*/
/*=========== A11 - OPERADORES LÓGICOS ============*/
/*=================================================*/
/* OR - OU */
SELECT NOME, SEXO, ENDEREÇO FROM CLIENTE
WHERE 
SEXO = 'M' OR ENDEREÇO LIKE '%RJ';

SELECT NOME, SEXO, ENDEREÇO FROM CLIENTE
WHERE 
SEXO = 'F' OR ENDEREÇO LIKE '%ESTACIO';

/* AND = E */

SELECT NOME, SEXO, ENDEREÇO FROM CLIENTE
WHERE 
SEXO = 'M' AND ENDEREÇO LIKE '%RJ';

SELECT NOME, EMAIL, ENDEREÇO FROM CLIENTE
WHERE 
SEXO = 'F' AND ENDEREÇO LIKE '%ESTACIO';

/* COUNT(*), GROUP BY, PERFORMANCE COM OPERADORES LÓGICOS*/
/* CONTANDO OS REGISTROS DE UMA TABELA*/
SELECT COUNT(*) FROM CLIENTE;
SELECT COUNT(*) AS "QUANTIDADE DE REG TAB CLIENTE" FROM CLIENTE;

/*OPERADOR GROUP BY*/
SELECT SEXO, COUNT(*) AS "QUANTIDADE"
FROM CLIENTE
GROUP BY SEXO;

/* PERFORMANCE EM OPERADORES LOGICOS*/
/* 1 MILHÃO DE REGISTROS */
/* PARA CONTAR
SELECT COUNT (*) FROM CLIENTE;

SELECT SEXO, COUNT (*) FROM CLIENTE
GROUP BY SEXO;

SELECT CIDADE, COUNT (*) FROM CLIENTE
GROUP BY CIDADE;

CONDIÇÃO
SEXO = F
CIDADE = RIO DE JANEIRO

SITUAÇÃO - TRATANDO COM OU / OR
70% MULHERES = SEXO = F
30% MORA NO RIO DE JANEIRO

SELECT NOME, SEXO, ENDEREÇO
FROM CLIENTE
WHERE SEXO = 'F'
OR CIDADE = 'RIO DE JANEIRO';

SITUAÇÃO - TRATANDO COM E / AND
70% MULHERES = SEXO = F
30% MORA NO RIO DE JANEIRO

SELECT NOME,SEXO, ENDEREÇO
FROM CLIENTE
WHERE CIDADE = 'RIO DE JANEIRO'
AND SEXO = 'F';

PARA OU - PORCENTAGEM MAIOR VERDADEIRA
NA PRIMEIRA CONDIÇÃO*/

/*=================================================*/
/*======== A13 - FILTRANDO VALORES NULOS ==========*/
/*=================================================*/

SELECT NOME, SEXO, ENDEREÇO
FROM CLIENTE
WHERE EMAIL = NULL;

SELECT NOME, SEXO, ENDEREÇO
FROM CLIENTE
WHERE EMAIL IS NULL;

SELECT NOME, SEXO, ENDEREÇO
FROM CLIENTE
WHERE EMAIL IS NOT NULL;

/*=================================================*/
/* A14 - UTILIZANDO O UPDATE PARA ATUALIZAR VALORES*/
/*=================================================*/
SELECT NOME, EMAIL
FROM CLIENTE;

UPDATE CLIENTE
SET EMAIL = 'LILIAN@HOTMAIL.COM';

/*UTILIZAR O UPDATE SEMPRE ACOMPANHADO DA CLAUSURA WHERE*/
UPDATE CLIENTE
SET EMAIL = 'JOÃO@HOTMAIL.COM'
WHERE NOME = 'JOAO';

UPDATE CLIENTE
SET EMAIL = 'JORGE@HOTMAIL.COM'
WHERE NOME = 'JORGE';
UPDATE CLIENTE
SET EMAIL = 'CELIA@HOTMAIL.COM'
WHERE NOME = 'CELIA';
UPDATE CLIENTE
SET EMAIL = 'ANA@GLOBO.COM'
WHERE NOME = 'ANA';
UPDATE CLIENTE
SET EMAIL = 'CARLA@TERATI.COM.BR'
WHERE NOME = 'CARLA';
SELECT NOME, EMAIL
FROM CLIENTE;

/*=================================================*/
/* A15 - DELETANDO REGISTROS COM A CLAUSURA DELETE */
/*=================================================*/

DELETE FROM CLIENTE; -- NUNCA FAZER

SELECT COUNT(*) FROM CLIENTE;

DELETE FROM CLIENTE
WHERE NOME = 'ANA';

SELECT COUNT(*) FROM CLIENTE;
/*=================================================*/
/*======== A16 - ENTRANDO COM MAIS TELEFONES ======*/
/*=================================================*/
UPDATE CLIENTE
SET TELEFONE = '55926325'
WHERE NOME = 'JOAO';

UPDATE CLIENTE
SET TELEFONE = '55926325 - 37865434'
WHERE NOME = 'JOAO';

SELECT ENDEREÇO, COUNT(*) AS QUANTIDADE
FROM CLIENTE
GROUP BY ENDEREÇO;

/*=================================================*/
/*======== A18 -  ======*/
/*=================================================*/
INSERT INTO CLIENTE VALUES('CELIA','F','CELIA@GMAIL.COM',541521456,'725892541','RIACHUELO - CENTRO - RIO DE JANEIRO - RJ');
SELECT SEXO, COUNT(*) AS QUANTIDADE
FROM CLIENTE
GROUP BY SEXO;

/* PRIMEIRA FORMA NORMAL */
/*1 - TODO CAMPO VETORIZADO SE TORNARÁ OUTRA TABELA
[AZUL, AMARELO, VERDE, LARANJA] - ELEMENTOS DE UM MESMO TIPO(VETOR)
[KA, FIT, FIESTA, CIVIC, UNO] - VETOR DE CARROS
*/

/*2 - TODO CAMPO MULTIVALORIZADO SE TORNARÁ OUTRA TABELA.
UM CAMPO DIVISÍVEL(RECEBE MUITOS VÁLORES)
*/

/*3 - TODA TABELA NECESSITA DE PELO MENOS UM CAMPO QUE IDENTIFIQUE
TODO O REGISTRO COMO SENDO ÚNICO. É O QUE CHAMAMOS DE 
CHAVE PRIMÁRIA OU PRIMARY KEY.
TEMOS DOIS TIPOS DE CHAVE: NATURAL E ARTIFICIAL */


/*=================================================*/
/*======== A19 - CARDINALIDADE ====================*/
/*=================================================*/
 /* QUEM DEFINE A CARDINALIDADE É A REGRA DE NEGOCIOS
 
 PRIMEIRO ALGARISMO - OBRIGATORIEDADE
 0 - NÃO OBRIGATÓRIO
 1 - OBRIGATÓRIO
 
 SEGUNDO ALGARISMO - CARDINALIDADE
 0 - MÁXIMO DE UMA
 N - MAIS DE UM
 
/*=================================================*/
/*============ 20 - MODELAGEM =====================*/
/*=================================================*/
CREATE DATABASE COMERCIO;

USE COMERCIO;

CREATE TABLE CLIENTE(
	CODCLIENTE INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30) NOT NULL,
	SEXO ENUM('M','F') NOT NULL,
	EMAIL VARCHAR(50) UNIQUE,
	CPF VARCHAR(15) UNIQUE
);

CREATE TABLE ENDERECO(
	CODENDERECO INT PRIMARY KEY AUTO_INCREMENT,
	RUA VARCHAR(30) NOT NULL,
	BAIRRO VARCHAR(30) NOT NULL,
	CIDADE VARCHAR(20) NOT NULL,
	ESTADO CHAR(2) NOT NULL,
	COD_CLIENTE INT UNIQUE,
	FOREIGN KEY(COD_CLIENTE)
	REFERENCES CLIENTE(CODCLIENTE)
);

CREATE TABLE TELEFONE(
	CODTELEFONE INT PRIMARY KEY AUTO_INCREMENT,
	TIPO ENUM('COM','RES','CEL'),
	NUMERO VARCHAR(10),
	COD_CLIENTE INT,
	FOREIGN KEY(COD_CLIENTE) 
	REFERENCES CLIENTE(CODCLIENTE)
);

/*=================================================*/
/*=========== FOREIGN KEY CHAVE ESTRANGEIRA =======*/
/*=================================================*/
/*É A CHAVE PRIMARIA DE UMA TABELA, QUE VAI ATÉ OUTRA
TABELA FAZER REFERENCIA

EM RELACIONAMENTOS 1 X 1 A CHAVE ESTRANGEIRA FICA
NA TABELA MAIS FRACA.

EM RELACIONAMENTOS 1 X N, A CHAVE ESTRANGEIRA FICA
SEMPRE NA TABELA N. 
*/

/*=================================================*/
/*====================== A20 ======================*/
/*=================================================*/
INSERT INTO CLIENTE VALUES(NULL, 'JOÃO','M','JOAO@IG,COM','98547-6');
INSERT INTO CLIENTE VALUES(NULL, 'CARLOS','M','CARLOS@TERA.COM','85664-7');
INSERT INTO CLIENTE VALUES(NULL, 'ANA','F','ANA@GLOBO.COM','86664-7');
INSERT INTO CLIENTE VALUES(NULL, 'JORGE','M','JORGE@IG.COM','8857-5');
INSERT INTO CLIENTE VALUES(NULL, 'CLARA','M',NULL,'99754-7');
INSERT INTO CLIENTE VALUES(NULL, 'CELIA','F','JOAO@TERRA.COM','77558-5');

SELECT * FROM CLIENTE;

/*INSERINDO UM REGISTRO ERRADO*/
INSERT INTO CLIENTE VALUES(NULL, 'ANTONIO','M','JOAO@IG.COM');

/*CORRIGINDO*/
INSERT INTO CLIENTE VALUES(NULL, 'ANTONIO','M',NULL,'78558-6');
INSERT INTO CLIENTE VALUES(NULL, 'JOAO','M',NULL,'86695-6');
INSERT INTO CLIENTE VALUES(NULL, 'JOAO','86695-6');

/*ENDEREÇO*/
INSERT INTO ENDERECO VALUES(NULL,'RUA A','CENTRO','B. HORIZONTE','MG',4);
INSERT INTO ENDERECO VALUES(NULL,'RUA B','CENTRO','B. RIO DE JANEIRO','RJ',3);
INSERT INTO ENDERECO VALUES(NULL,'RUA C','JARDINS','SÃO PAULO','SP',1);
INSERT INTO ENDERECO VALUES(NULL,'RUA D','ESTACIO','RIO DE JANEIRO','RJ',8);
INSERT INTO ENDERECO VALUES(NULL,'RUA Z','CRUZEIRO','B. HORIZONTE','MG',2);
INSERT INTO ENDERECO VALUES(NULL,'RUA X','FLAMENGO','RIO DE JANEIRO','RJ',7);
INSERT INTO ENDERECO VALUES(NULL,'RUA G','CENTRO','RIO DE JANEIRO','MG',5);
INSERT INTO ENDERECO VALUES(NULL,'RUA T','FLAMENGO','RIO DE JANEIRO','RJ',6);
INSERT INTO ENDERECO VALUES(NULL,'RUA U','FLAMENGO','RIO DE JANEIRO','RJ',6);

/*INTEGRIDADE REFERENCIAL*/
INSERT INTO ENDERECO VALUES(NULL,'RUA U','FLAMENGO','RIO DE JANEIRO','RJ',102100);

SELECT * FROM ENDERECO;
/*TELEFONE*/
INSERT INTO TELEFONE VALUES(NULL,'CEL','9955331',1);
INSERT INTO TELEFONE VALUES(NULL,'COM','6574565',6);
INSERT INTO TELEFONE VALUES(NULL,'RES','1254252',7);
INSERT INTO TELEFONE VALUES(NULL,'CEL','8545585',1);
INSERT INTO TELEFONE VALUES(NULL,'RES','9653225',7);
INSERT INTO TELEFONE VALUES(NULL,'COM','7452112',1);
INSERT INTO TELEFONE VALUES(NULL,'COM','8545966',2);
INSERT INTO TELEFONE VALUES(NULL,'CEL','2542333',3);
INSERT INTO TELEFONE VALUES(NULL,'RES','1201022',6);
INSERT INTO TELEFONE VALUES(NULL,'RES','8754585',7);
INSERT INTO TELEFONE VALUES(NULL,'COM','9653222',7);
INSERT INTO TELEFONE VALUES(NULL,'COM','7422010',1);
INSERT INTO TELEFONE VALUES(NULL,'RES','9632533',3);
INSERT INTO TELEFONE VALUES(NULL,'CEL','9785522',6);

SELECT * FROM CLIENTE;
SELECT * FROM ENDERECO;
SELECT * FROM TELEFONE;


/*=================================================*/
/*=================== A 21 ========================*/
/*=================================================*/
/*========= SELEÇÃO, PROJEÇÃO E JUNÇÃO ============*/

/* PROJEÇÃO - TUDO QUE QUEREMOS PROJETAR NA TELA */
SELECT NOW() AS "DATA"; /* PROJEÇÃO */

SELECT NOME, NOW() AS "DATA"
FROM CLIENTE;

/*SELEÇÃO - TEORIA DOS CONJUNTOS - WHERE É A CLAUSURA DE SELEÇÃO */
SELECT NOME, SEXO
FROM CLIENTE
WHERE SEXO = 'M';

UPDATE CLIENTE
SET SEXO = 'F'
WHERE CODCLIENTE = 5;

/* PROJEÇÃO - */

/* JUNÇÃO */
/* ME MOSTRE O NOME, SEXO , BAIRRO, CIDADE, DATA*/
SELECT NOME, SEXO , BAIRRO, CIDADE, NOW() AS DATE
FROM CLIENTE, ENDERECO
WHERE CODCLIENTE = COD_CLIENTE /* NÃO FAZER DESSA FORMA */
AND BAIRRO = 'CENTRO';

/* JOIN  - JUNÇÃO */

 /*SELEÇAO*/
SELECT NOME, SEXO, BAIRRO, CIDADE /*PROJEÇÃO*/
FROM CLIENTE
INNER JOIN ENDERECO               /*JUNÇÃO*/
ON CODCLIENTE = COD_CLIENTE       /*SELEÇÃO*/
WHERE BAIRRO = 'CENTRO';

SELECT CLIENTE.NOME, CLIENTE.SEXO, 
ENDERECO.BAIRRO, ENDERECO.CIDADE , 
TELEFONE.TIPO, TELEFONE.NUMERO
FROM CLIENTE
INNER JOIN ENDERECO
ON CLIENTE.CODCLIENTE = ENDERECO.COD_CLIENTE
INNER JOIN TELEFONE
ON CLIENTE.CODCLIENTE = TELEFONE.COD_CLIENTE;

SELECT .C.NOME, C.SEXO, 
E.BAIRRO, E.CIDADE , 
T.TIPO, T.NUMERO
FROM CLIENTE C
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE;


SELECT .C.NOME, C.SEXO, 
E.BAIRRO, E.CIDADE , 
T.TIPO, T.NUMERO
FROM CLIENTE C
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
WHERE SEXO = 'M';
/*=================================================*/
/*=================== EXERCÍCIO ===================*/
/*=================================================*/
/* EXERCÍCIOS DE FIXAÇÃO.
1) CRIE UM BANCO DE DADOS CHAMADO PROJETO E CONECTE-SE AO BANCO.
2) FAÇA A SEGUINTE MODELAGEM:
    SR. JOSÉ QUER MODERNIZAR A SUA OFICINA, E POR ENQUANTO, CADASTRAR
	OS CARROS QUE ENTRAM PARA REALIZAR SERVIÇOS E OS SEUS RESPECTIVOS 
	DONOS. 
	
	SR. JOSÉ MENCIONOU QUE CADA CLIENTE POSSUI APENAS UM CARRO.
	
	UM CARRO POSSUI UMA MARCA. 
	SR. JOSÉ TAMBÉM QUER SABER AS CORES DOS CARROS PARA TER IDÉIA 
	DE QUAL TINTA COMPRAR, E INFORMA QUE UM
	CARRO PODE TER MAIS DE UMA COR. 
	SR. JOSÉ NECESSITA ARMAZENAR OS 
	TELEFONES DOS CLIENTES, MAS NÃO QUER QUE ELES SEJAM 
	OBRIGATÓRIOS.
*/
CREATE DATABASE EXPROJETO;

USE EXPROJETO;

CREATE TABLE CLIENTE(
	CODCLIENTE INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(40) NOT NULL
);
CREATE TABLE TELEFONE(
	CODTELEFONE INT PRIMARY KEY AUTO_INCREMENT,
	NUMERO VARCHAR(10) UNIQUE,
	TIPO ENUM('RES','COM','CEL') NOT NULL,
	COD_CLIENTE INT,
	FOREIGN KEY(COD_CLIENTE) 
	REFERENCES CLIENTE(CODCLIENTE)
);
CREATE TABLE CARRO(
	CODCARRO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(20) NOT NULL
);
CREATE TABLE MARCA(
	CODMARCA INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(20) NOT NULL,
	COD_CARRO INT,
	FOREIGN KEY(COD_CARRO)
	REFERENCES CARRO(CODCARRO)
);
CREATE TABLE COR(
	CODCOR INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(15) NOT NULL,
	COD_CARRO INT,
	FOREIGN KEY(COD_CARRO)
	REFERENCES CARRO(CODCARRO)
);
CREATE TABLE TELEFONE(
	CODTELEFONE INT PRIMARY KEY AUTO_INCREMENT,
	TIPO ENUM('COM','RES','CEL'),
	NUMERO VARCHAR(10),
	COD_CLIENTE INT,
	FOREIGN KEY(COD_CLIENTE) 
	REFERENCES CLIENTE(CODCLIENTE)
);

/*=================================================*/
/* A 23 - QUERIES - SELEÇÃO, PROJEÇÃO E JUNÇÃO*/
/*=================================================*/
/* PARA UMA CAMPANHA DE MARKETING, O SETOR SOLICITOU UM 
RELATÓRIO COM O NOME, EMAIL E TELEFONE CELULAR 
DOS CLIENTES QUE MORAM NO ESTADO DO RIO DE JANEIRO 
VOCÊ TERÁ QUE PASSAR A QUERY PARA GERAR O RELATÓRIO PARA 
O PROGRAMADOR*/

SELECT C.NOME, C.EMAIL, T.NUMERO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE
WHERE TIPO = 'COM' AND E.ESTADO = 'RJ';

+-------+----------------+---------+
| NOME  | EMAIL          | NUMERO  |
+-------+----------------+---------+
| CELIA | JOAO@TERRA.COM | 6574565 |
+-------+----------------+---------+

/* PARA UMA CAMPANHA DE PRODUTOS DE BELEZA, O COMERCIAL SOLICITOU 
UM RELATÓRIO COM O NOME, EMAIL E TELEFONE CELULAR 
DAS MULHERES QUE MORAM NO ESTADO DE SÃO PAULO 
VOCÊ TERÁ QUE PASSAR A QERY PARA GERAR O RELATÓRIO 
PARA O PROGRAMADOR */

SELECT C.NOME, C.EMAIL, T.NUMERO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE
WHERE SEXO = 'F' AND TIPO = 'CEL' AND ESTADO = 'SP';

SELECT C.NOME, C.EMAIL, T.NUMERO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE
WHERE SEXO = 'F' AND TIPO = 'CEL';
+-------+----------------+---------+
| NOME  | EMAIL          | NUMERO  |
+-------+----------------+---------+
| ANA   | ANA@GLOBO.COM  | 2542333 |
| CELIA | JOAO@TERRA.COM | 9785522 |
+-------+----------------+---------+

/* IFNULL*/
SELECT C.NOME, C.EMAIL, T.NUMERO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE;
+--------+-----------------+---------+
| NOME   | EMAIL           | NUMERO  |
+--------+-----------------+---------+
| JOÃO   | JOAO@IG,COM     | 9955331 |
| JOÃO   | JOAO@IG,COM     | 8545585 |
| JOÃO   | JOAO@IG,COM     | 7452112 |
| JOÃO   | JOAO@IG,COM     | 7422010 |
| CARLOS | CARLOS@TERA.COM | 8545966 |
| ANA    | ANA@GLOBO.COM   | 2542333 |
| ANA    | ANA@GLOBO.COM   | 9632533 |
| CELIA  | JOAO@TERRA.COM  | 6574565 |
| CELIA  | JOAO@TERRA.COM  | 1201022 |
| CELIA  | JOAO@TERRA.COM  | 9785522 |
+--------+-----------------+---------+

SELECT * FROM CLIENTE
+------------+--------+------+-----------------+---------+
| CODCLIENTE | NOME   | SEXO | EMAIL           | CPF     |
+------------+--------+------+-----------------+---------+
|          1 | JOÃO   | M    | JOAO@IG,COM     | 98547-6 |
|          2 | CARLOS | M    | CARLOS@TERA.COM | 85664-7 |
|          3 | ANA    | F    | ANA@GLOBO.COM   | 86664-7 |
|          4 | JORGE  | M    | JORGE@IG.COM    | 8857-5  |
|          5 | CLARA  | M    | NULL            | 99754-7 |
|          6 | CELIA  | F    | JOAO@TERRA.COM  | 77558-5 |
+------------+--------+------+-----------------+---------+

SELECT IFNULL(EMAIL,'SEM EMAIL') FROM CLIENTE;
+---------------------------+
| IFNULL(EMAIL,'SEM EMAIL') |
+---------------------------+
| SEM EMAIL                 |
| ANA@GLOBO.COM             |
| CARLOS@TERA.COM           |
| JOAO@IG,COM               |
| JOAO@TERRA.COM            |
| JORGE@IG.COM              |
+---------------------------+

SELECT CODCLIENTE, NOME, SEXO, IFNULL(EMAIL,'SEM EMAIL'), CPF FROM CLIENTE;
+------------+--------+------+---------------------------+---------+
| CODCLIENTE | NOME   | SEXO | IFNULL(EMAIL,'SEM EMAIL') | CPF     |
+------------+--------+------+---------------------------+---------+
|          1 | JOÃO   | M    | JOAO@IG,COM               | 98547-6 |
|          2 | CARLOS | M    | CARLOS@TERA.COM           | 85664-7 |
|          3 | ANA    | F    | ANA@GLOBO.COM             | 86664-7 |
|          4 | JORGE  | M    | JORGE@IG.COM              | 8857-5  |
|          5 | CLARA  | M    | SEM EMAIL                 | 99754-7 |
|          6 | CELIA  | F    | JOAO@TERRA.COM            | 77558-5 |
+------------+--------+------+---------------------------+---------+

SELECT CODCLIENTE, NOME, SEXO, IFNULL(EMAIL,'SEM EMAIL') AS EMAIL, CPF FROM CLIENTE;
+------------+--------+------+-----------------+---------+
| CODCLIENTE | NOME   | SEXO | EMAIL           | CPF     |
+------------+--------+------+-----------------+---------+
|          1 | JOÃO   | M    | JOAO@IG,COM     | 98547-6 |
|          2 | CARLOS | M    | CARLOS@TERA.COM | 85664-7 |
|          3 | ANA    | F    | ANA@GLOBO.COM   | 86664-7 |
|          4 | JORGE  | M    | JORGE@IG.COM    | 8857-5  |
|          5 | CLARA  | M    | SEM EMAIL       | 99754-7 |
|          6 | CELIA  | F    | JOAO@TERRA.COM  | 77558-5 |
+------------+--------+------+-----------------+---------+

SELECT CODCLIENTE AS COD, NOME, SEXO, IFNULL(EMAIL,'SEM EMAIL') AS EMAIL, CPF FROM CLIENTE;
+-----+--------+------+-----------------+---------+
| COD | NOME   | SEXO | EMAIL           | CPF     |
+-----+--------+------+-----------------+---------+
|   1 | JOÃO   | M    | JOAO@IG,COM     | 98547-6 |
|   2 | CARLOS | M    | CARLOS@TERA.COM | 85664-7 |
|   3 | ANA    | F    | ANA@GLOBO.COM   | 86664-7 |
|   4 | JORGE  | M    | JORGE@IG.COM    | 8857-5  |
|   5 | CLARA  | M    | SEM EMAIL       | 99754-7 |
|   6 | CELIA  | F    | JOAO@TERRA.COM  | 77558-5 |
+-----+--------+------+-----------------+---------+

/*=================================================*/
/*======== A - 24 - VIEWS OU VISÕES ===============*/
/*=================================================*/
SELECT C.NOME, 
	   C.SEXO, 
	   IFNULL(C.EMAIL,'SEM EMAIL') AS 'E-MAIL', 
	   T.TIPO, 
	   T.NUMERO, 
	   E.BAIRRO, 
	   E.CIDADE, 
	   E.ESTADO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE;

+--------+------+-----------------+------+---------+----------+-------------------+--------+
| NOME   | SEXO | E-MAIL          | TIPO | NUMERO  | BAIRRO   | CIDADE            | ESTADO |
+--------+------+-----------------+------+---------+----------+-------------------+--------+
| JOÃO   | M    | JOAO@IG,COM     | CEL  | 9955331 | JARDINS  | SÃO PAULO         | SP     |
| CELIA  | F    | JOAO@TERRA.COM  | COM  | 6574565 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM     | CEL  | 8545585 | JARDINS  | SÃO PAULO         | SP     |
| JOÃO   | M    | JOAO@IG,COM     | COM  | 7452112 | JARDINS  | SÃO PAULO         | SP     |
| CARLOS | M    | SEM EMAIL       | COM  | 8545966 | CRUZEIRO | B. HORIZONTE      | MG     |
| ANA    | F    | ANA@GLOBO.COM   | CEL  | 2542333 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | JOAO@TERRA.COM  | RES  | 1201022 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM     | COM  | 7422010 | JARDINS  | SÃO PAULO         | SP     |
| ANA    | F    | ANA@GLOBO.COM   | RES  | 9632533 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | JOAO@TERRA.COM  | CEL  | 9785522 | FLAMENGO | RIO DE JANEIRO    | RJ     |
+--------+------+-----------------+------+---------+----------+-------------------+--------+

/*CRIANDO A VIEW*/
CREATE VIEW RELATORIO AS 
SELECT C.NOME, 
	   C.SEXO, 
	   IFNULL(C.EMAIL,'SEM EMAIL') AS 'E-MAIL', 
	   T.TIPO, 
	   T.NUMERO, 
	   E.BAIRRO, 
	   E.CIDADE, 
	   E.ESTADO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE;

SELECT * FROM RELATORIO;
+--------+------+-----------------+------+---------+----------+-------------------+--------+
| NOME   | SEXO | E-MAIL          | TIPO | NUMERO  | BAIRRO   | CIDADE            | ESTADO |
+--------+------+-----------------+------+---------+----------+-------------------+--------+
| JOÃO   | M    | JOAO@IG,COM     | CEL  | 9955331 | JARDINS  | SÃO PAULO         | SP     |
| CELIA  | F    | JOAO@TERRA.COM  | COM  | 6574565 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM     | CEL  | 8545585 | JARDINS  | SÃO PAULO         | SP     |
| JOÃO   | M    | JOAO@IG,COM     | COM  | 7452112 | JARDINS  | SÃO PAULO         | SP     |
| CARLOS | M    | SEM EMAIL       | COM  | 8545966 | CRUZEIRO | B. HORIZONTE      | MG     |
| ANA    | F    | ANA@GLOBO.COM   | CEL  | 2542333 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | JOAO@TERRA.COM  | RES  | 1201022 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM     | COM  | 7422010 | JARDINS  | SÃO PAULO         | SP     |
| ANA    | F    | ANA@GLOBO.COM   | RES  | 9632533 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | JOAO@TERRA.COM  | CEL  | 9785522 | FLAMENGO | RIO DE JANEIRO    | RJ     |
+--------+------+-----------------+------+---------+----------+-------------------+--------+

SELECT * FROM RELATORIO
WHERE SEXO = 'F';
+-------+------+----------------+------+---------+----------+-------------------+--------+
| NOME  | SEXO | E-MAIL         | TIPO | NUMERO  | BAIRRO   | CIDADE            | ESTADO |
+-------+------+----------------+------+---------+----------+-------------------+--------+
| CELIA | F    | JOAO@TERRA.COM | COM  | 6574565 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| ANA   | F    | ANA@GLOBO.COM  | CEL  | 2542333 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA | F    | JOAO@TERRA.COM | RES  | 1201022 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| ANA   | F    | ANA@GLOBO.COM  | RES  | 9632533 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA | F    | JOAO@TERRA.COM | CEL  | 9785522 | FLAMENGO | RIO DE JANEIRO    | RJ     |
+-------+------+----------------+------+---------+----------+-------------------+--------+

/*EXERCÍCIO UPDATE*/
UPDATE CLIENTE
SET EMAIL = 'CELIA@HOTMAIL.COM'
WHERE NOME = 'CELIA';

SELECT * FROM CLIENTE;
+------------+--------+------+-------------------+---------+
| CODCLIENTE | NOME   | SEXO | EMAIL             | CPF     |
+------------+--------+------+-------------------+---------+
|          1 | JOÃO   | M    | JOAO@IG,COM       | 98547-6 |
|          2 | CARLOS | M    | CARLOS@TERA.COM   | 85664-7 |
|          3 | ANA    | F    | ANA@GLOBO.COM     | 86664-7 |
|          4 | JORGE  | M    | JORGE@IG.COM      | 8857-5  |
|          5 | CLARA  | M    | NULL              | 99754-7 |
|          6 | CELIA  | F    | CELIA@HOTMAIL.COM | 77558-5 |
+------------+--------+------+-------------------+---------+

SHOW TABLES;
+-------------------+
| Tables_in_projeto |
+-------------------+
| cliente           |
| endereco          |
| relatorio         |
| telefone          |
+-------------------+

/*APAGANDO UMA VIEW*/
DROP VIEW RELATORIO;
SHOW TABLES;
+-------------------+
| Tables_in_projeto |
+-------------------+
| cliente           |
| endereco          |
| telefone          |
+-------------------+

/*RECRIANDO UMA VIEW COM UM V_ PARA SABER QUE É UMA VIEW*/
CREATE VIEW V_RELATORIO AS 
SELECT C.NOME, 
	   C.SEXO, 
	   IFNULL(C.EMAIL,'SEM EMAIL') AS 'E-MAIL', 
	   T.TIPO, 
	   T.NUMERO, 
	   E.BAIRRO, 
	   E.CIDADE, 
	   E.ESTADO
FROM CLIENTE C
INNER JOIN TELEFONE T
ON C.CODCLIENTE = T.COD_CLIENTE
INNER JOIN ENDERECO E
ON C.CODCLIENTE = E.COD_CLIENTE;

+-------------------+
| Tables_in_projeto |
+-------------------+
| cliente           |
| endereco          |
| telefone          |
| v_relatorio       |
+-------------------+

SELECT NOME, SEXO, CIDADE
FROM V_RELATORIO;
+--------+------+-------------------+
| NOME   | SEXO | CIDADE            |
+--------+------+-------------------+
| JOÃO   | M    | SÃO PAULO         |
| JOÃO   | M    | SÃO PAULO         |
| JOÃO   | M    | SÃO PAULO         |
| JOÃO   | M    | SÃO PAULO         |
| CARLOS | M    | B. HORIZONTE      |
| ANA    | F    | B. RIO DE JANEIRO |
| ANA    | F    | B. RIO DE JANEIRO |
| CELIA  | F    | RIO DE JANEIRO    |
| CELIA  | F    | RIO DE JANEIRO    |
| CELIA  | F    | RIO DE JANEIRO    |
+--------+------+-------------------+

DELETE FROM V_RELATORIO
WHERE NOME = 'JOAO';
'Can not delete from join view 'projeto.v_relatorio'
/*NÃO PODE FAZER DELETE IGUAL A ESSE POIS TEM JOIN NO MEIO DE UM RELATÓRIO*/
'Can not insert into join view 'projeto.v_relatorio' without fields list''
INSERT INTO V_RELATORIO VALUES(
	'ROMARIO','M',NULL,'RES','12542154','BARRA DA TIJUCA','RIO DE JANEIRO', 'RJ');
/*NÃO DÁ PARA FAZER INSERT EM UM RELATÓRIO COM INNER JOIN*/

/*=================================================*/
/*=================== A - 25 - ORDER BY ===========*/
/*=================================================*/
SELECT NOME, SEXO, CPF, CIDADE
FROM CLIENTE
INNER JOIN ENDERECO
ON CODCLIENTE = COD_CLIENTE;
+--------+------+---------+-------------------+
| NOME   | SEXO | CPF     | CIDADE            |
+--------+------+---------+-------------------+
| JOÃO   | M    | 98547-6 | SÃO PAULO         |
| CARLOS | M    | 85664-7 | B. HORIZONTE      |
| ANA    | F    | 86664-7 | B. RIO DE JANEIRO |
| JORGE  | M    | 8857-5  | B. HORIZONTE      |
| CLARA  | M    | 99754-7 | RIO DE JANEIRO    |
| CELIA  | F    | 77558-5 | RIO DE JANEIRO    |
+--------+------+---------+-------------------+

SELECT NOME, SEXO, CPF, CIDADE
FROM CLIENTE
INNER JOIN ENDERECO
ON CODCLIENTE = COD_CLIENTE
ORDER BY NOME;
+--------+------+---------+-------------------+
| NOME   | SEXO | CPF     | CIDADE            |
+--------+------+---------+-------------------+
| ANA    | F    | 86664-7 | B. RIO DE JANEIRO |
| CARLOS | M    | 85664-7 | B. HORIZONTE      |
| CELIA  | F    | 77558-5 | RIO DE JANEIRO    |
| CLARA  | M    | 99754-7 | RIO DE JANEIRO    |
| JOÃO   | M    | 98547-6 | SÃO PAULO         |
| JORGE  | M    | 8857-5  | B. HORIZONTE      |
+--------+------+---------+-------------------+

SELECT NOME, SEXO, CPF, CIDADE
FROM CLIENTE
INNER JOIN ENDERECO
ON CODCLIENTE = COD_CLIENTE
ORDER BY NOME, CPF ASC;
+--------+------+---------+-------------------+
| NOME   | SEXO | CPF     | CIDADE            |
+--------+------+---------+-------------------+
| ANA    | F    | 86664-7 | B. RIO DE JANEIRO |
| CARLOS | M    | 85664-7 | B. HORIZONTE      |
| CELIA  | F    | 77558-5 | RIO DE JANEIRO    |
| CLARA  | M    | 99754-7 | RIO DE JANEIRO    |
| JOÃO   | M    | 98547-6 | SÃO PAULO         |
| JORGE  | M    | 8857-5  | B. HORIZONTE      |
+--------+------+---------+-------------------+
/*SE TIVESSE O MESMO NOME, IRIA ORDENAR PELO NUMERO DO CPF EM ORDER CRESCENTE
DO MENOR PARA O MAIOR*/

SELECT NOME, SEXO, CPF, CIDADE
FROM CLIENTE
INNER JOIN ENDERECO
ON CODCLIENTE = COD_CLIENTE
ORDER BY 4; /*ORDENA PELA COLUNA 4*/
+--------+------+---------+-------------------+
| NOME   | SEXO | CPF     | CIDADE            |
+--------+------+---------+-------------------+
| JORGE  | M    | 8857-5  | B. HORIZONTE      |
| CARLOS | M    | 85664-7 | B. HORIZONTE      |
| ANA    | F    | 86664-7 | B. RIO DE JANEIRO |
| CLARA  | M    | 99754-7 | RIO DE JANEIRO    |
| CELIA  | F    | 77558-5 | RIO DE JANEIRO    |
| JOÃO   | M    | 98547-6 | SÃO PAULO         |
+--------+------+---------+-------------------+

/*=================================================*/
/*====== A26 - DELIMITADOR E ESTADO DE SERVIDOR ===*/
/*=================================================*/

/*O DELIMITADOR É O ";", NÃO FINALIZA O CÓDIGO ENQUANTO NÃO TIVER O ";" NO CODIGO*/
/*SE USA O DELIMITADOR PARA PROGRAMAR*/
SELECT * FROM V_RELATORIO;
+--------+------+-------------------+------+---------+----------+-------------------+--------+
| NOME   | SEXO | E-MAIL            | TIPO | NUMERO  | BAIRRO   | CIDADE            | ESTADO |
+--------+------+-------------------+------+---------+----------+-------------------+--------+
| JOÃO   | M    | JOAO@IG,COM       | CEL  | 9955331 | JARDINS  | SÃO PAULO         | SP     |
| CELIA  | F    | CELIA@HOTMAIL.COM | COM  | 6574565 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM       | CEL  | 8545585 | JARDINS  | SÃO PAULO         | SP     |
| JOÃO   | M    | JOAO@IG,COM       | COM  | 7452112 | JARDINS  | SÃO PAULO         | SP     |
| CARLOS | M    | CARLOS@TERA.COM   | COM  | 8545966 | CRUZEIRO | B. HORIZONTE      | MG     |
| ANA    | F    | ANA@GLOBO.COM     | CEL  | 2542333 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | CELIA@HOTMAIL.COM | RES  | 1201022 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM       | COM  | 7422010 | JARDINS  | SÃO PAULO         | SP     |
| ANA    | F    | ANA@GLOBO.COM     | RES  | 9632533 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | CELIA@HOTMAIL.COM | CEL  | 9785522 | FLAMENGO | RIO DE JANEIRO    | RJ     |
+--------+------+-------------------+------+---------+----------+-------------------+--------+

DELIMITER $
SELECT * FROM V_RELATORIO;

mysql> DELIMITER $
mysql> SELECT * FROM V_RELATORIO;
    -> $
+--------+------+-------------------+------+---------+----------+-------------------+--------+
| NOME   | SEXO | E-MAIL            | TIPO | NUMERO  | BAIRRO   | CIDADE            | ESTADO |
+--------+------+-------------------+------+---------+----------+-------------------+--------+
| JOÃO   | M    | JOAO@IG,COM       | CEL  | 9955331 | JARDINS  | SÃO PAULO         | SP     |
| CELIA  | F    | CELIA@HOTMAIL.COM | COM  | 6574565 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM       | CEL  | 8545585 | JARDINS  | SÃO PAULO         | SP     |
| JOÃO   | M    | JOAO@IG,COM       | COM  | 7452112 | JARDINS  | SÃO PAULO         | SP     |
| CARLOS | M    | CARLOS@TERA.COM   | COM  | 8545966 | CRUZEIRO | B. HORIZONTE      | MG     |
| ANA    | F    | ANA@GLOBO.COM     | CEL  | 2542333 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | CELIA@HOTMAIL.COM | RES  | 1201022 | FLAMENGO | RIO DE JANEIRO    | RJ     |
| JOÃO   | M    | JOAO@IG,COM       | COM  | 7422010 | JARDINS  | SÃO PAULO         | SP     |
| ANA    | F    | ANA@GLOBO.COM     | RES  | 9632533 | CENTRO   | B. RIO DE JANEIRO | RJ     |
| CELIA  | F    | CELIA@HOTMAIL.COM | CEL  | 9785522 | FLAMENGO | RIO DE JANEIRO    | RJ     |
+--------+------+-------------------+------+---------+----------+-------------------+--------+

STATUS
C:\Program Files\MySQL\MySQL Server 5.7\bin\mysql.exe  
Ver 14.14 Distrib 5.7.19, for Win32 (AMD64)

Connection id:          3
Current database:       projeto
Current user:           root@localhost
SSL:                    Not in use
Using delimiter:        $
Server version:         5.7.19-log MySQL Community Server (GPL)
Protocol version:       10
Connection:             localhost via TCP/IP
Server characterset:    utf8
Db     characterset:    utf8
Client characterset:    utf8
Conn.  characterset:    utf8
TCP port:               3306
Uptime:                 18 hours 11 min 15 sec

Threads: 1  Questions: 35  Slow queries: 0  Opens: 111  
Flush tables: 1  Open tables: 104  Queries per second avg: 0.000


DELIMITER# /*TEM QUE POR ESPAÇO DELIMITER #*/
DELIMITER # /*NÃO COLOQUE TRALHA E PONTO E VIRGULA, SENÃO ESSE SERÁ O DELIMITADOR #;*/

/*=================================================*/
/*================ A27 - PROCEDURES ===============*/
/*=================================================*/
DELIMITER $

CREATE PROCEDURE NOME()
BEGIN
	ACAO;
END
$

SELECT 10 + 10 AS "CONTA"$
+-------+
| CONTA |
+-------+
|    20 |
+-------+

CREATE PROCEDURE CONTA()
BEGIN
	SELECT 10 + 10 AS "CONTA";
END
$

/* CHAMANDO UMA PROCEDURE */
CALL CONTA()$
+-------+
| CONTA |
+-------+
|    20 |
+-------+
DELIMITER ;
CALL CONTA();
+-------+
| CONTA |
+-------+
|    20 |
+-------+

/* PROCEDURES COM PARÂMETROS */
DROP PROCEDURE CONTA;

DELIMITER $
CREATE PROCEDURE CONTA(NUMERO1 INT, NUMERO2 INT)
BEGIN
	SELECT NUMERO1 + NUMERO2 AS "CONTA";
END
$

DELIMITER ;
CALL CONTA(100,75);
CALL CONTA(152,32);
CALL CONTA(100,236);
+-------+  
| CONTA |
+-------+
|   175 |
+-------+

+-------+
| CONTA |
+-------+
|   175 |
+-------+

+-------+
| CONTA |
+-------+
|   184 |
+-------+

+-------+
| CONTA |
+-------+
|   336 |
+-------+

/*=================================================*/
/*========== A 28 - PROCEDURES COM TABELAS ========*/
/*=================================================*/

CREATE TABLE CURSOS(
	CODCURSO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30) NOT NULL,
	HORAS INT(3) NOT NULL,
	VALOR FLOAT(10,2) NOT NULL
);

SHOW TABLES;

INSERT INTO CURSOS VALUES (NULL, 'BANCO DE DADOS FUNDAMENTAL', 25, 200.00);

SELECT * FROM CURSOS;
+----------+----------------------------+-------+--------+
| CODCURSO | NOME                       | HORAS | VALOR  |
+----------+----------------------------+-------+--------+
|        1 | BANCO DE DADOS FUNDAMENTAL |    25 | 200.00 |
+----------+----------------------------+-------+--------+

/* DELIMITADOR */

DELIMITER #

CREATE PROCEDURE CAD_CURSO(P_NOME VARCHAR(30),P_HORAS INT(3), P_PRECO FLOAT(10,2))
BEGIN
	INSERT INTO CURSOS VALUES(NULL, P_NOME, P_HORAS, P_PRECO);
END
#

DELIMITER ;
STATUS
CALL CAD_CURSO('BI SQL SERVER', 35,200.00);

SELECT * FROM CURSOS;
+----------+----------------------------+-------+--------+
| CODCURSO | NOME                       | HORAS | VALOR  |
+----------+----------------------------+-------+--------+
|        1 | BANCO DE DADOS FUNDAMENTAL |    25 | 200.00 |
|        2 | BI SQL SERVER              |    35 | 200.00 |
+----------+----------------------------+-------+--------+

DELIMITER #
CREATE PROCEDURE SEL_CURSO()
BEGIN
	SELECT CODCURSO, NOME, HORAS, VALOR
	FROM CURSOS;
END
#

DELIMITER ;

CALL SEL_CURSO();
+----------+----------------------------+-------+--------+
| CODCURSO | NOME                       | HORAS | VALOR  |
+----------+----------------------------+-------+--------+
|        1 | BANCO DE DADOS FUNDAMENTAL |    25 | 200.00 |
|        2 | BI SQL SERVER              |    35 | 200.00 |
+----------+----------------------------+-------+--------+

/*=================================================*/
/*====== A29 - FUNÇÕES DE AGREGAÇÃO NUMERICAS =====*/
/*=================================================*/

CREATE TABLE VENDEDORES(
	CODVENDEDOR INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	SEXO CHAR(1),
	JANEIRO FLOAT(10,2),
	FEVEREIRO FLOAT(10,2),
	MARCO FLOAT(10,2)
);

INSERT INTO VENDEDORES VALUES(NULL,'CARLOS','M',1512122.33,152122.54,45854.32);
INSERT INTO VENDEDORES VALUES(NULL,'MARIA','F',12251.22,4521163.66,85496.55);
INSERT INTO VENDEDORES VALUES(NULL,'ANTONIO','M',120320.66,102020.33,78454.66);
INSERT INTO VENDEDORES VALUES(NULL,'CLARA','F',45846.65,48549.66,11111.32);
INSERT INTO VENDEDORES VALUES(NULL,'ANDERSON','M',12563.32,85485.32,85459.33);
INSERT INTO VENDEDORES VALUES(NULL,'IVONE','F',12521.33,02123.65,85469.66);
INSERT INTO VENDEDORES VALUES(NULL,'JOAO','M',96856.65,521452.32,75896.66);
INSERT INTO VENDEDORES VALUES(NULL,'CÉLIA','F',48549.10,14569.00,8596532.65);

+-------------+----------+------+------------+------------+------------+
| CODVENDEDOR | NOME     | SEXO | JANEIRO    | FEVEREIRO  | MARCO      |
+-------------+----------+------+------------+------------+------------+
|           1 | CARLOS   | M    | 1512122.38 |  152122.55 |   45854.32 |
|           2 | MARIA    | F    |   12251.22 | 4521163.50 |   85496.55 |
|           3 | ANTONIO  | M    |  120320.66 |  102020.33 |   78454.66 |
|           4 | CLARA    | F    |   45846.65 |   48549.66 |   11111.32 |
|           5 | ANDERSON | M    |   12563.32 |   85485.32 |   85459.33 |
|           6 | IVONE    | F    |   12521.33 |    2123.65 |   85469.66 |
|           7 | JOAO     | M    |   96856.65 |  521452.31 |   75896.66 |
|           8 | CÉLIA    | F    |   48549.10 |   14569.00 | 8596533.00 |
+-------------+----------+------+------------+------------+------------+

/*MAX - TRÁZ O VALOR MÁXIMO DE UMA COLUNA */
SELECT MAX(FEVEREIRO) AS MAIO_FEV FROM VENDEDORES;
+------------+
| MAIO_FEV   |
+------------+
| 4521163.50 |
+------------+

/*MIN - TRÁZ O VALOR MÍNIMO DE UMA COLUNA */
SELECT MIN(FEVEREIRO) AS MENOR_FEV FROM VENDEDORES;
+-----------+
| MENOR_FEV |
+-----------+
|   2123.65 |
+-----------+

/*AVG - TRÁZ O VALOR MÉDIO DE UMA COLUNA */
SELECT AVG(FEVEREIRO) AS MEDIA_FEV FROM VENDEDORES;
+---------------+
| MEDIA_FEV     |
+---------------+
| 680935.789734 |
+---------------+

/*VÁRIAS FUNÇÕES*/
SELECT MAX(JANEIRO) AS MAX_JAN,
		MIN(JANEIRO) AS MIN_JAN,
		AVG(JANEIRO) AS MEDIA_JAN
FROM VENDEDORES;
+------------+----------+---------------+
| MAX_JAN    | MIN_JAN  | MEDIA_JAN     |
+------------+----------+---------------+
| 1512122.38 | 12251.22 | 232628.912476 |
+------------+----------+---------------+

/*TRUNCATE FUNÇÃO PARA 
RETIRAR AS CASAS DECIMAIS DE UMA CONTA NO CASO ABAIXO, DUAS CASAS DECIMAIS*/
SELECT MAX(JANEIRO) AS MAX_JAN,
		MIN(JANEIRO) AS MIN_JAN,
		TRUNCATE(AVG(JANEIRO), 2) AS MEDIA_JAN
FROM VENDEDORES;
+------------+----------+-----------+
| MAX_JAN    | MIN_JAN  | MEDIA_JAN |
+------------+----------+-----------+
| 1512122.38 | 12251.22 | 232628.91 |
+------------+----------+-----------+

/*=================================================*/
/*============ A30 - AGREGAÇÃO COM SUM ============*/
/*=================================================*/
SELECT SUM(JANEIRO) AS TOTAL_JAN
FROM VENDEDORES;
+------------+
| TOTAL_JAN  |
+------------+
| 1861031.30 |
+------------+

/*SOMOU TODO DA COLUNA DE JANEIRO*/
SELECT SUM(JANEIRO) AS TOTAL_JAN,
	SUM(FEVEREIRO) AS TOTAL_FEV,
	SUM(MARCO) AS TOTAL_MAR
FROM VENDEDORES;
+------------+------------+------------+
| TOTAL_JAN  | TOTAL_FEV  | TOTAL_MAR  |
+------------+------------+------------+
| 1861031.30 | 5447486.32 | 9064275.48 |
+------------+------------+------------+

/* VENDAS POR SEXO */
SELECT SEXO, SUM(MARCO) AS TOTAL_MARCO
FROM VENDEDORES
GROUP BY SEXO;
+------+-------------+
| SEXO | TOTAL_MARCO |
+------+-------------+
| F    |  8778610.52 |
| M    |   285664.96 |
+------+-------------+

/*=================================================*/
/* A31 - VENDEDOR QUE VENDEU MENOS EM MARÇO E O SEU NOME */
/*=================================================*/
SELECT * FROM VENDEDORES;

/*O MAIOR VALOR DE MARÇO E QUEM VENDEU*/
/*NOME DE QUEM VENDEU MAIS EM MARÇO*/
SELECT NOME, MIN(MARCO) AS V_MINIMO
FROM VENDEDORES;
+--------+----------+
| NOME   | V_MINIMO |
+--------+----------+
| CARLOS | 11111.32 |
+--------+----------+
/*ERRADOOOOO*/

SELECT NOME, MARCO FROM VENDEDORES 
WHERE MARCO = (SELECT MAX(MARCO) FROM VENDEDORES);
+--------+------------+
| NOME   | MARCO      |
+--------+------------+
| CÉLIA  | 8596533.00 |
+--------+------------+


/*O MENOR VALOR DE MARÇO E QUEM VENDEU*/
SELECT NOME, MARCO FROM VENDEDORES 
WHERE MARCO = (SELECT MIN(MARCO) FROM VENDEDORES);
+-------+----------+
| NOME  | MARCO    |
+-------+----------+
| CLARA | 11111.32 |
+-------+----------+

/* QUEM VENDEU MAIS DO QUE A MÉDIA DO MÊS DE FEVEREIRO */
SELECT NOME, FEVEREIRO FROM VENDEDORES 
WHERE FEVEREIRO > (SELECT AVG(FEVEREIRO) FROM VENDEDORES);
+-------+------------+
| NOME  | FEVEREIRO  |
+-------+------------+
| MARIA | 4521163.50 |
+-------+------------+

SELECT *  FROM VENDEDORES;
+-------------+----------+------+------------+------------+------------+
| CODVENDEDOR | NOME     | SEXO | JANEIRO    | FEVEREIRO  | MARCO      |
+-------------+----------+------+------------+------------+------------+
|           1 | CARLOS   | M    | 1512122.38 |  152122.55 |   45854.32 |
|           2 | MARIA    | F    |   12251.22 | 4521163.50 |   85496.55 |
|           3 | ANTONIO  | M    |  120320.66 |  102020.33 |   78454.66 |
|           4 | CLARA    | F    |   45846.65 |   48549.66 |   11111.32 |
|           5 | ANDERSON | M    |   12563.32 |   85485.32 |   85459.33 |
|           6 | IVONE    | F    |   12521.33 |    2123.65 |   85469.66 |
|           7 | JOAO     | M    |   96856.65 |  521452.31 |   75896.66 |
|           8 | CÉLIA    | F    |   48549.10 |   14569.00 | 8596533.00 |
+-------------+----------+------+------------+------------+------------+

SELECT NOME, MARCO FROM VENDEDORES 
WHERE MARCO > (SELECT AVG(MARCO) FROM VENDEDORES);
+--------+------------+
| NOME   | MARCO      |
+--------+------------+
| CÉLIA  | 8596533.00 |
+--------+------------+

SELECT AVG(FEVEREIRO) FROM VENDEDORES;

SELECT NOME, FEVEREIRO FROM VENDEDORES 
WHERE FEVEREIRO < (SELECT AVG(FEVEREIRO) FROM VENDEDORES);
+----------+-----------+
| NOME     | FEVEREIRO |
+----------+-----------+
| CARLOS   | 152122.55 |
| ANTONIO  | 102020.33 |
| CLARA    |  48549.66 |
| ANDERSON |  85485.32 |
| IVONE    |   2123.65 |
| JOAO     | 521452.31 |
| CÉLIA    |  14569.00 |
+----------+-----------+

/*=================================================*/
/*=========== A32 - OPERACOES EM LINHA ============*/
/*=================================================*/
SELECT * FROM VENDEDORES;

SELECT NOME,
       JANEIRO,
	   FEVEREIRO,
	   MARCO,
	   (JANEIRO + FEVEREIRO + MARCO) AS "TOTAL",
	   TRUNCATE((JANEIRO + FEVEREIRO + MARCO)/3,2) AS "MEDIA"
FROM VENDEDORES;

/*APLICANDO PORCENTAGEM*/
SELECT NOME,
       JANEIRO,
	   FEVEREIRO,
	   MARCO,
	   (JANEIRO + FEVEREIRO + MARCO) AS "TOTAL",
	   (JANEIRO + FEVEREIRO + MARCO)* 0.25 AS "DESCONTO",
	   TRUNCATE((JANEIRO + FEVEREIRO + MARCO)/3,2) AS "MEDIA"
FROM VENDEDORES;

/*=================================================*/
/*=========== A33 - ALTERANDO TABELAS =============*/
/*=================================================*/
CREATE TABLE TABELA(
	COLUNA1 VARCHAR(30),
	COLUNA2 VARCHAR(30),
	COLUNA3 VARCHAR(30)
);
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| COLUNA1 | varchar(30) | YES  |     | NULL    |       |
| COLUNA2 | varchar(30) | YES  |     | NULL    |       |
| COLUNA3 | varchar(30) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+

--NÃO FOI FEITO
CREATE TABLE TABELA(
	COLUNA1 PRIMARY KEY AUTO_INCREMENT
);


--FAZER DA FORMA ABAIXO
--ADICIONANDO UM PK
ALTER TABLE TABELA
ADD PRIMARY KEY (COLUNA1);

--ADICIONANDO COLUNA SEM POSIÇÃO, ULTIMA POSIÇÃO
ALTER TABLE TABELA
ADD COLUNA VARCHAR(30);
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| COLUNA1 | varchar(30) | NO   | PRI | NULL    |       |
| COLUNA2 | varchar(30) | YES  |     | NULL    |       |
| COLUNA3 | varchar(30) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
ALTER TABLE TABELA
ADD COLUNA100 INT;

--ADICIONANDO UMA COLUNA COM POSIÇÃO
ALTER TABLE TABELA
ADD COLUMN COLUNA4 VARCHAR(30) NOT NULL UNIQUE
AFTER COLUNA3;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| COLUNA1   | varchar(30) | NO   | PRI | NULL    |       |
| COLUNA2   | varchar(30) | YES  |     | NULL    |       |
| COLUNA3   | varchar(30) | YES  |     | NULL    |       |
| COLUNA4   | varchar(30) | NO   | UNI | NULL    |       |
| COLUNA    | varchar(30) | YES  |     | NULL    |       |
| COLUNA100 | varchar(30) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

--MODIFICANDO O TIPO DE UM CAMPO
ALTER TABLE TABELA MODIFY COLUNA2 DATE NOT NULL;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| COLUNA1   | varchar(30) | NO   | PRI | NULL    |       |
| COLUNA2   | date        | NO   |     | NULL    |       |
| COLUNA3   | varchar(30) | YES  |     | NULL    |       |
| COLUNA4   | varchar(30) | NO   | UNI | NULL    |       |
| COLUNA    | varchar(30) | YES  |     | NULL    |       |
| COLUNA100 | varchar(30) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

--RENOMEANDO O NOME DA TABELA
ALTER TABLE TABELA
RENAME PESSOA;

CREATE TABLE TIME(
	CODTIME INT PRIMARY KEY AUTO_INCREMENT,
	TIME VARCHAR(30),
	COD_PESSOA VARCHAR(30)
);

--FOREIGN KEY
ALTER TABLE TIME
ADD FOREIGN KEY(COD_PESSOA)
REFERENCES PESSOA(COLUNA1);
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| COLUNA1   | varchar(30) | NO   | PRI | NULL    |       |
| COLUNA2   | date        | NO   |     | NULL    |       |
| COLUNA3   | varchar(30) | YES  |     | NULL    |       |
| COLUNA4   | varchar(30) | NO   | UNI | NULL    |       |
| COLUNA    | varchar(30) | YES  |     | NULL    |       |
| COLUNA100 | varchar(30) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

DESC TABELA;
DESC PESSOA;
DESC TIME;

--VERIFICAR AS CHAVES
SHOW CREATE TABLE TIME;
--| TIME  | CREATE TABLE `time` (
 -- `CODTIME` int(11) NOT NULL AUTO_INCREMENT,
 -- `TIME` varchar(30) DEFAULT NULL,
 -- `COD_PESSOA` varchar(30) DEFAULT NULL,
--  PRIMARY KEY (`CODTIME`),
 -- KEY `COD_PESSOA` (`COD_PESSOA`),
 -- CONSTRAINT `time_ibfk_1` FOREIGN KEY (`COD_PESSOA`) REFERENCES `pessoa` (`COLUNA1`)
--) ENGINE=InnoDB DEFAULT CHARSET=utf8

/*=================================================*/
/*======== A34 - ORGANIZAÇÃO DE CHAVES - CONSTRAINT (REGRA) ======*/
/*=================================================*/
--INTEGRIDADE REFERENCIAL (REFERENCIA DE UMA TABELA A OUTRA, CASO NÃO TENHA
--ELE NÃO ACEITA

CREATE TABLE JOGADOR(
	CODJOGADOR INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30)
	
);
CREATE TABLE TIMES(
	CODTIME INT PRIMARY KEY AUTO_INCREMENT,
	NOMETIME VARCHAR(30),
	COD_JOGADOR INT,
	FOREIGN KEY(COD_JOGADOR)
	REFERENCES JOGADOR(CODJOGADOR)
);

INSERT INTO JOGADOR VALUES(NULL, 'GUERREIRO');
INSERT INTO TIMES VALUES(NULL, 'FLAMENGO', 1);
+------------+-----------+
| CODJOGADOR | NOME      |
+------------+-----------+
|          1 | GUERREIRO |
+------------+-----------+

+---------+----------+-------------+
| CODTIME | NOMETIME | COD_JOGADOR |
+---------+----------+-------------+
|       1 | FLAMENGO |           1 |
+---------+----------+-------------+

SHOW CREATE TABLE JOGADOR;
SHOW CREATE TABLE TIMES;

-- JOGADOR | CREATE TABLE `jogador` (
--  `CODJOGADOR` int(11) NOT NULL AUTO_INCREMENT,
--  `NOME` varchar(30) DEFAULT NULL,
--  PRIMARY KEY (`CODJOGADOR`)
--) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 |

--TIMES | CREATE TABLE `times` (
--  `CODTIME` int(11) NOT NULL AUTO_INCREMENT,
--  `NOMETIME` varchar(30) DEFAULT NULL,
--  `COD_JOGADOR` int(11) DEFAULT NULL,
--  PRIMARY KEY (`CODTIME`),
--  KEY `COD_JOGADOR` (`COD_JOGADOR`),
--  CONSTRAINT `times_ibfk_1` FOREIGN KEY (`COD_JOGADOR`) REFERENCES `jogador` (`CODJOGADOR`)
-- ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 |

--COMPLICADO, VEREMOS MAIS PRA FRENTE COMO NÃO ACONTECER ISSO:
--  CONSTRAINT `times_ibfk_1`

--PARA NÃO FICAR COMPLICADO EM MONTAR UM DICIONARIO DE DADOS
--=========================================================
--ENTÃO, SE CRIA PRIMEIRO A TABELA SEM A CHAVE ESTRANGEIRA,
--DEPOIS CRIA-SE A CHAVE ESTRANGEIRA NA TABELA.
--=========================================================
/*=================================================*/
/*=================================================*/
/* A35 - ORGANIZANDO CHAVES E AÇÕES DE CONSTRAINTS */
/*=================================================*/
SHOW TABLES;
+-------------------+
| Tables_in_projeto |
+-------------------+
| cliente           |
| cursos            |
| endereco          |
| jogador           |
| pessoa            |
| telefone          |
| time              |
| times             |
| v_relatorio       |
| vendedores        |
+-------------------+

DROP TABLE ENDERECO;
DROP TABLE TELEFONE;
DROP TABLE CLIENTE;

CREATE TABLE CLIENTE(
	CODCLIENTE INT,
	NOME VARCHAR(30) NOT NULL
);
CREATE TABLE TELEFONE(
	CODTELEFONE INT,
	TIPO CHAR(3) NOT NULL,
	NUMERO VARCHAR(10) NOT NULL,
	COD_CLIENTE INT
);

ALTER TABLE CLIENTE ADD CONSTRAINT PK_CLIENTE
PRIMARY KEY(CODCLIENTE);

ALTER TABLE TELEFONE ADD CONSTRAINT FK_CLIENTE_TELEFONE
FOREIGN KEY(COD_CLIENTE) REFERENCES CLIENTE(CODCLIENTE);

SHOW CREATE TABLE TELEFONE;
--| TELEFONE | CREATE TABLE `telefone` (
--  `CODTELEFONE` int(11) DEFAULT NULL,
--  `TIPO` char(3) NOT NULL,
--  `NUMERO` varchar(10) NOT NULL,
--  `COD_CLIENTE` int(11) DEFAULT NULL,
--  KEY `FK_CLIENTE_TELEFONE` (`COD_CLIENTE`),
--  CONSTRAINT `FK_CLIENTE_TELEFONE` FOREIGN KEY (`COD_CLIENTE`) REFERENCES `cliente` (`CODCLIENTE`)
--) ENGINE=InnoDB DEFAULT CHARSET=utf8 |


/* DICIONÁRIO DE DADOS */
-- ONDE SE GUARDA UM META DADOS
SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |  --PERTENCE AO DICIONÁRIO
| comercio           |
| exprojeto          |
| marcio_lista       |
| mysql              |  --PERTENCE AO DICIONÁRIO
| performance_schema |  --PERTENCE AO DICIONÁRIO
| projeto            |
| sakila             |
| sys                |
| world              |
+--------------------+

USE INFORMATION_SCHEMA;

STATUS
/*Connection id:          4
Current database:       information_schema
Current user:           root@localhost
SSL:                    Not in use
Using delimiter:        ;
Server version:         5.7.19-log MySQL Community Server (GPL)
Protocol version:       10
Connection:             localhost via TCP/IP
Server characterset:    utf8
Db     characterset:    utf8
Client characterset:    utf8
Conn.  characterset:    utf8
TCP port:               3306
Uptime:                 1 day 16 hours 42 min 37 sec*/

--PRECISO DE CONSTRANT
SHOW TABLES;
+---------------------------------------+
| Tables_in_information_schema          |
+---------------------------------------+
| CHARACTER_SETS                        |
| COLLATIONS                            |
| COLLATION_CHARACTER_SET_APPLICABILITY |
| COLUMNS                               |
| COLUMN_PRIVILEGES                     |
| ENGINES                               |
| EVENTS                                |
| FILES                                 |
| GLOBAL_STATUS                         |
| GLOBAL_VARIABLES                      |
| KEY_COLUMN_USAGE                      |
| OPTIMIZER_TRACE                       |
| PARAMETERS                            |
| PARTITIONS                            |
| PLUGINS                               |
| PROCESSLIST                           |
| PROFILING                             |
| REFERENTIAL_CONSTRAINTS               |
| ROUTINES                              |
| SCHEMATA                              |
| SCHEMA_PRIVILEGES                     |
| SESSION_STATUS                        |
| SESSION_VARIABLES                     |
| STATISTICS                            |
| TABLES                                |
| TABLESPACES                           |
| TABLE_CONSTRAINTS                     | --ESTÁ AQUI AS CONSTRAINTS
| TABLE_PRIVILEGES                      |
| TRIGGERS                              |
| USER_PRIVILEGES                       |
| VIEWS                                 |
| INNODB_LOCKS                          |
| INNODB_TRX                            |
| INNODB_SYS_DATAFILES                  |
| INNODB_FT_CONFIG                      |
| INNODB_SYS_VIRTUAL                    |
| INNODB_CMP                            |
| INNODB_FT_BEING_DELETED               |
| INNODB_CMP_RESET                      |
| INNODB_CMP_PER_INDEX                  |
| INNODB_CMPMEM_RESET                   |
| INNODB_FT_DELETED                     |
| INNODB_BUFFER_PAGE_LRU                |
| INNODB_LOCK_WAITS                     |
| INNODB_TEMP_TABLE_INFO                |
| INNODB_SYS_INDEXES                    |
| INNODB_SYS_TABLES                     |
| INNODB_SYS_FIELDS                     |
| INNODB_CMP_PER_INDEX_RESET            |
| INNODB_BUFFER_PAGE                    |
| INNODB_FT_DEFAULT_STOPWORD            |
| INNODB_FT_INDEX_TABLE                 |
| INNODB_FT_INDEX_CACHE                 |
| INNODB_SYS_TABLESPACES                |
| INNODB_METRICS                        |
| INNODB_SYS_FOREIGN_COLS               |
| INNODB_CMPMEM                         |
| INNODB_BUFFER_POOL_STATS              |
| INNODB_SYS_COLUMNS                    |
| INNODB_SYS_FOREIGN                    |
| INNODB_SYS_TABLESTATS                 |
+---------------------------------------+

DESC TABLE_CONSTRAINTS;
+--------------------+--------------+------+-----+---------+-------+
| Field              | Type         | Null | Key | Default | Extra |
+--------------------+--------------+------+-----+---------+-------+
| CONSTRAINT_CATALOG | varchar(512) | NO   |     |         |       |
| CONSTRAINT_SCHEMA  | varchar(64)  | NO   |     |         |       |
| CONSTRAINT_NAME    | varchar(64)  | NO   |     |         |       | -- NOME DA CONSTRAINT
| TABLE_SCHEMA       | varchar(64)  | NO   |     |         |       |
| TABLE_NAME         | varchar(64)  | NO   |     |         |       | -- NOME DA TABELA ONDE ESTÁ
| CONSTRAINT_TYPE    | varchar(64)  | NO   |     |         |       | -- TIPO DA CONSTRAINT
+--------------------+--------------+------+-----+---------+-------+

SELECT CONSTRAINT_SCHEMA AS "BANCO",
		TABLE_NAME AS "TABELA",
		CONSTRAINT_TYPE AS "TIPO"
		FROM TABLE_CONSTRAINTS;
		
+-----------+---------------------------+-------------+
| BANCO     | TABELA                    | TIPO        |
+-----------+---------------------------+-------------+
| comercio  | cliente                   | PRIMARY KEY |
| comercio  | cliente                   | UNIQUE      |
| comercio  | cliente                   | UNIQUE      |
| comercio  | endereco                  | PRIMARY KEY |
| comercio  | endereco                  | UNIQUE      |
| comercio  | endereco                  | FOREIGN KEY |
| comercio  | telefone                  | PRIMARY KEY |
| comercio  | telefone                  | FOREIGN KEY |
| exprojeto | carro                     | PRIMARY KEY |
| exprojeto | cliente                   | PRIMARY KEY |
| exprojeto | cor                       | PRIMARY KEY |
| exprojeto | cor                       | FOREIGN KEY |
| exprojeto | marca                     | PRIMARY KEY |
| exprojeto | marca                     | FOREIGN KEY |
| exprojeto | telefone                  | PRIMARY KEY |
| exprojeto | telefone                  | UNIQUE      |
| exprojeto | telefone                  | FOREIGN KEY |
| mysql     | columns_priv              | PRIMARY KEY |
| mysql     | db                        | PRIMARY KEY |
| mysql     | engine_cost               | PRIMARY KEY |
| mysql     | event                     | PRIMARY KEY |
| mysql     | func                      | PRIMARY KEY |
| mysql     | gtid_executed             | PRIMARY KEY |
| mysql     | help_category             | PRIMARY KEY |
| mysql     | help_category             | UNIQUE      |
| mysql     | help_keyword              | PRIMARY KEY |
| mysql     | help_keyword              | UNIQUE      |
| mysql     | help_relation             | PRIMARY KEY |
| mysql     | help_topic                | PRIMARY KEY |
| mysql     | help_topic                | UNIQUE      |
| mysql     | innodb_index_stats        | PRIMARY KEY |
| mysql     | innodb_table_stats        | PRIMARY KEY |
| mysql     | ndb_binlog_index          | PRIMARY KEY |
| mysql     | plugin                    | PRIMARY KEY |
| mysql     | proc                      | PRIMARY KEY |
| mysql     | procs_priv                | PRIMARY KEY |
| mysql     | proxies_priv              | PRIMARY KEY |
| mysql     | server_cost               | PRIMARY KEY |
| mysql     | servers                   | PRIMARY KEY |
| mysql     | slave_master_info         | PRIMARY KEY |
| mysql     | slave_relay_log_info      | PRIMARY KEY |
| mysql     | slave_worker_info         | PRIMARY KEY |
| mysql     | tables_priv               | PRIMARY KEY |
| mysql     | time_zone                 | PRIMARY KEY |
| mysql     | time_zone_leap_second     | PRIMARY KEY |
| mysql     | time_zone_name            | PRIMARY KEY |
| mysql     | time_zone_transition      | PRIMARY KEY |
| mysql     | time_zone_transition_type | PRIMARY KEY |
| mysql     | user                      | PRIMARY KEY |
| projeto   | cliente                   | PRIMARY KEY |
| projeto   | cursos                    | PRIMARY KEY |
| projeto   | jogador                   | PRIMARY KEY |
| projeto   | pessoa                    | PRIMARY KEY |
| projeto   | pessoa                    | UNIQUE      |
| projeto   | telefone                  | FOREIGN KEY |
| projeto   | time                      | PRIMARY KEY |
| projeto   | time                      | FOREIGN KEY |
| projeto   | times                     | PRIMARY KEY |
| projeto   | times                     | FOREIGN KEY |
| projeto   | vendedores                | PRIMARY KEY |
| sakila    | actor                     | PRIMARY KEY |
| sakila    | address                   | PRIMARY KEY |
| sakila    | address                   | FOREIGN KEY |
| sakila    | category                  | PRIMARY KEY |
| sakila    | city                      | PRIMARY KEY |
| sakila    | city                      | FOREIGN KEY |
| sakila    | country                   | PRIMARY KEY |
| sakila    | customer                  | PRIMARY KEY |
| sakila    | customer                  | FOREIGN KEY |
| sakila    | customer                  | FOREIGN KEY |
| sakila    | film                      | PRIMARY KEY |
| sakila    | film                      | FOREIGN KEY |
| sakila    | film                      | FOREIGN KEY |
| sakila    | film_actor                | PRIMARY KEY |
| sakila    | film_actor                | FOREIGN KEY |
| sakila    | film_actor                | FOREIGN KEY |
| sakila    | film_category             | PRIMARY KEY |
| sakila    | film_category             | FOREIGN KEY |
| sakila    | film_category             | FOREIGN KEY |
| sakila    | film_text                 | PRIMARY KEY |
| sakila    | inventory                 | PRIMARY KEY |
| sakila    | inventory                 | FOREIGN KEY |
| sakila    | inventory                 | FOREIGN KEY |
| sakila    | language                  | PRIMARY KEY |
| sakila    | payment                   | PRIMARY KEY |
| sakila    | payment                   | FOREIGN KEY |
| sakila    | payment                   | FOREIGN KEY |
| sakila    | payment                   | FOREIGN KEY |
| sakila    | rental                    | PRIMARY KEY |
| sakila    | rental                    | UNIQUE      |
| sakila    | rental                    | FOREIGN KEY |
| sakila    | rental                    | FOREIGN KEY |
| sakila    | rental                    | FOREIGN KEY |
| sakila    | staff                     | PRIMARY KEY |
| sakila    | staff                     | FOREIGN KEY |
| sakila    | staff                     | FOREIGN KEY |
| sakila    | store                     | PRIMARY KEY |
| sakila    | store                     | UNIQUE      |
| sakila    | store                     | FOREIGN KEY |
| sakila    | store                     | FOREIGN KEY |
| sys       | sys_config                | PRIMARY KEY |
| world     | city                      | PRIMARY KEY |
| world     | city                      | FOREIGN KEY |
| world     | country                   | PRIMARY KEY |
| world     | countrylanguage           | PRIMARY KEY |
| world     | countrylanguage           | FOREIGN KEY |
+-----------+---------------------------+-------------+

SELECT CONSTRAINT_SCHEMA AS "BANCO",
		TABLE_NAME AS "TABELA",
		CONSTRAINT_TYPE AS "TIPO"
		FROM TABLE_CONSTRAINTS
		WHERE CONSTRAINT_SCHEMA = 'COMERCIO';
+----------+----------+-------------+
| BANCO    | TABELA   | TIPO        |
+----------+----------+-------------+
| comercio | cliente  | PRIMARY KEY |
| comercio | cliente  | UNIQUE      |
| comercio | cliente  | UNIQUE      |
| comercio | endereco | PRIMARY KEY |
| comercio | endereco | UNIQUE      |
| comercio | endereco | FOREIGN KEY |
| comercio | telefone | PRIMARY KEY |
| comercio | telefone | FOREIGN KEY |
+----------+----------+-------------+


SELECT CONSTRAINT_SCHEMA AS "BANCO",
		TABLE_NAME AS "TABELA",
		CONSTRAINT_NAME AS "REGRA",
		CONSTRAINT_TYPE AS "TIPO"
		FROM TABLE_CONSTRAINTS
		WHERE CONSTRAINT_SCHEMA = 'COMERCIO';
+----------+----------+-----------------+-------------+
| BANCO    | TABELA   | REGRA           | TIPO        |
+----------+----------+-----------------+-------------+
| comercio | cliente  | PRIMARY         | PRIMARY KEY |
| comercio | cliente  | EMAIL           | UNIQUE      |
| comercio | cliente  | CPF             | UNIQUE      |
| comercio | endereco | PRIMARY         | PRIMARY KEY |
| comercio | endereco | COD_CLIENTE     | UNIQUE      |
| comercio | endereco | endereco_ibfk_1 | FOREIGN KEY |  -- NOME ESTRANHO, NÃO É BOM
| comercio | telefone | PRIMARY         | PRIMARY KEY |
| comercio | telefone | telefone_ibfk_1 | FOREIGN KEY |  -- NOME ESTRANHO DADO
+----------+----------+-----------------+-------------+  --AUTOMATICAMENTE

/*APAGANDO CONSTRAINTS*/

USE COMERCIO;

ALTER TABLE ENDERECO
DROP FOREIGN KEY endereco_ibfk_1;

ALTER TABLE ENDERECO ADD CONSTRAINT FK_CLIENTE_ENDERECO
FOREIGN KEY(COD_CLIENTE) REFERENCES CLIENTE(CODCLIENTE);
+----------+----------+---------------------+-------------+
| BANCO    | TABELA   | REGRA               | TIPO        |
+----------+----------+---------------------+-------------+
| comercio | cliente  | PRIMARY             | PRIMARY KEY |
| comercio | cliente  | EMAIL               | UNIQUE      |
| comercio | cliente  | CPF                 | UNIQUE      |
| comercio | endereco | PRIMARY             | PRIMARY KEY |
| comercio | endereco | COD_CLIENTE         | UNIQUE      |
| comercio | endereco | FK_CLIENTE_ENDERECO | FOREIGN KEY |  -- FOI TROCADO CORRETAMENTE
| comercio | telefone | PRIMARY             | PRIMARY KEY |
| comercio | telefone | telefone_ibfk_1     | FOREIGN KEY |  -- AGORA ESTE
+----------+----------+---------------------+-------------+

USE COMERCIO;

ALTER TABLE TELEFONE
DROP FOREIGN KEY telefone_ibfk_1;

ALTER TABLE TELEFONE ADD CONSTRAINT FK_CLIENTE_TELEFONE
FOREIGN KEY(COD_CLIENTE) REFERENCES CLIENTE(CODCLIENTE);

USE INFORMATION_SCHEMA;
SELECT CONSTRAINT_SCHEMA AS "BANCO",
		TABLE_NAME AS "TABELA",
		CONSTRAINT_NAME AS "REGRA",
		CONSTRAINT_TYPE AS "TIPO"
		FROM TABLE_CONSTRAINTS
		WHERE CONSTRAINT_SCHEMA = 'COMERCIO';

+----------+----------+---------------------+-------------+
| BANCO    | TABELA   | REGRA               | TIPO        |
+----------+----------+---------------------+-------------+
| comercio | cliente  | PRIMARY             | PRIMARY KEY |
| comercio | cliente  | EMAIL               | UNIQUE      |
| comercio | cliente  | CPF                 | UNIQUE      |
| comercio | endereco | PRIMARY             | PRIMARY KEY |
| comercio | endereco | COD_CLIENTE         | UNIQUE      |
| comercio | endereco | FK_CLIENTE_ENDERECO | FOREIGN KEY |
| comercio | telefone | PRIMARY             | PRIMARY KEY |
| comercio | telefone | FK_CLIENTE_TELEFONE | FOREIGN KEY |  -- TROCADO 100%
+----------+----------+---------------------+-------------+  -- SHOW


/*=================================================*/
/*============ A36 - AÇÕES DE CONSTRANTS ==========*/
/*=================================================*/





/*=================================================*/
/*========== A37 - CORREÇÃO DOS EXERCÍCIOS ========*/
/*=================================================*/
CREATE DATABASE OFICINA;
USE OFICINA;

/*RELAÇÃO ASSOSSIATIVA CHAVE PRIMÁRIA COMPOSTA*/

/*=================================================*/
/*==== A38 - CORREÇÃO DOS EXERCÍOS MODELO FISICO ==*/
/*=================================================*/
CREATE DATABASE OFICINA;
USE OFICINA;

CREATE TABLE CLIENTE(
	CODCLIENTE INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30) NOT NULL,
	SEXO ENUM('M','F') NOT NULL,
	COD_CARRO INT UNIQUE
);

CREATE TABLE TELEFONE(
	CODTELEFONE INT PRIMARY KEY AUTO_INCREMENT,
	TIPO ENUM('CEL','RES','COM') NOT NULL,
	NUMERO VARCHAR(30) NOT NULL,
	COD_CLIENTE INT
);

CREATE TABLE MARCA(
	CODMARCA INT PRIMARY KEY AUTO_INCREMENT,
	MARCA VARCHAR(30) UNIQUE
);

CREATE TABLE CARRO(
	CODCARRO INT PRIMARY KEY AUTO_INCREMENT,
	MODELO VARCHAR(30) NOT NULL,
	PLACA VARCHAR(30) NOT NULL UNIQUE,
	COD_MARCA INT
);

CREATE TABLE COR(
	CODCOR INT PRIMARY KEY AUTO_INCREMENT,
	COR VARCHAR(30) UNIQUE
);

CREATE TABLE CARRO_COR(
	COD_CARRO INT,
	COD_COR INT,
	PRIMARY KEY(COD_CARRO, COD_COR)
);

/*CONSTRAINTS*/

ALTER TABLE TELEFONE
ADD CONSTRAINT FK_TELEFONE_CLIENTE
FOREIGN KEY(COD_CLIENTE)
REFERENCES CLIENTE(CODCLIENTE);

ALTER TABLE CLIENTE
ADD CONSTRAINT FK_CLIENTE_CARRO
FOREIGN KEY(COD_CARRO)
REFERENCES CARRO(CODCARRO);

ALTER TABLE CARRO
ADD CONSTRAINT FK_CARRO_MARCA
FOREIGN KEY(COD_MARCA)
REFERENCES MARCA(CODMARCA);

ALTER TABLE CARRO_COR
ADD CONSTRAINT FK_COR
FOREIGN KEY(COD_COR)
REFERENCES COR(CODCOR);

ALTER TABLE CARRO_COR
ADD CONSTRAINT FK_CARRO
FOREIGN KEY(COD_CARRO)
REFERENCES CARRO(CODCARRO);

/* PREENCHER O BANCO COM NO MÍNIMO 10 CLIENTES */
CREATE TABLE CARRO(
	CODCARRO INT PRIMARY KEY AUTO_INCREMENT,
	MODELO VARCHAR(30) NOT NULL,
	PLACA VARCHAR(30) NOT NULL UNIQUE,
	COD_MARCA INT
);

CREATE TABLE MARCA(
	CODMARCA INT PRIMARY KEY AUTO_INCREMENT,
	MARCA VARCHAR(30) UNIQUE
);

/*CARRO*/
DESC CARRO;
INSERT INTO CARRO VALUES(NULL, 'GOL','ABC 1234',1);
INSERT INTO CARRO VALUES(NULL, 'UNO', 'ACD 1010', 2);
INSERT INTO CARRO VALUES(NULL, 'PALIO', 'ABC 2020', 2);
INSERT INTO CARRO VALUES(NULL, 'FOX', 'AAA 1010', 1);
INSERT INTO CARRO VALUES(NULL, 'SIENA', 'AXY 4526', 2);
INSERT INTO CARRO VALUES(NULL, 'CELTA', 'AMN 9090', 3);
INSERT INTO CARRO VALUES(NULL, 'VOYAGE', 'ABC 7010', 1);
INSERT INTO CARRO VALUES(NULL, 'HB20', 'PPB 7070', 1);
INSERT INTO CARRO VALUES(NULL, 'CORSA SEDAN', 'AAB 8562', 3);
INSERT INTO CARRO VALUES(NULL, 'ONIX', 'THM 7610', 3);
INSERT INTO CARRO VALUES(NULL, 'SANDERO', 'ACB 7026', 5);
INSERT INTO CARRO VALUES(NULL, 'FIESTA', 'ASD 2030', 6);
INSERT INTO CARRO VALUES(NULL, 'COBALT', 'AGH 4630', 3);
INSERT INTO CARRO VALUES(NULL, 'KA', 'ACB 1029', 6);
INSERT INTO CARRO VALUES(NULL, 'COROLLA', 'ACV 4629', 7);
INSERT INTO CARRO VALUES(NULL, 'CIVIC', 'AKL 2065', 8);
INSERT INTO CARRO VALUES(NULL, 'PUNTO', 'APR 8340', 2);
INSERT INTO CARRO VALUES(NULL, 'FIT', 'AMB 1532', 8);
INSERT INTO CARRO VALUES(NULL, 'SPIN', 'ARP 9064', 3);
INSERT INTO CARRO VALUES(NULL, 'C3', 'ALP 1021', 9);
INSERT INTO CARRO VALUES(NULL, 'CRUZE SEDAN', 'ALK 9030', 3);
INSERT INTO CARRO VALUES(NULL, 'LOGAN', 'ATP 7923', 5);
INSERT INTO CARRO VALUES(NULL, 'AGILE', 'ARP 8032', 3);
INSERT INTO CARRO VALUES(NULL, 'CITY', 'ALP 8030', 8);
INSERT INTO CARRO VALUES(NULL, 'IDEA', 'BCD 7941', 2);
INSERT INTO CARRO VALUES(NULL, 'MARCH', 'ABC 4692', 10);

/*MARCA*/
DESC MARCA;
INSERT INTO MARCA VALUES(NULL, 'VOLKSWAGEN');
INSERT INTO MARCA VALUES(NULL, 'FIAT');
INSERT INTO MARCA VALUES(NULL, 'GENERAL MOTORS');
INSERT INTO MARCA VALUES(NULL, 'HYUNDAY');
INSERT INTO MARCA VALUES(NULL, 'RENAULT');
INSERT INTO MARCA VALUES(NULL, 'FORD');
INSERT INTO MARCA VALUES(NULL, 'TOYOTA');
INSERT INTO MARCA VALUES(NULL, 'HONDA');
INSERT INTO MARCA VALUES(NULL, 'CITROEN');
INSERT INTO MARCA VALUES(NULL, 'NISSAN');

SELECT CODCARRO, MODELO, MARCA, PLACA
FROM CARRO 
INNER JOIN MARCA 
ON COD_MARCA = CODMARCA
ORDER BY CODCARRO;
+----------+-------------+----------------+----------+
| CODCARRO | MODELO      | MARCA          | PLACA    |
+----------+-------------+----------------+----------+
|        2 | GOL         | VOLKSWAGEN     | ABC 1234 |
|        3 | UNO         | FIAT           | ACD 1010 |
|        4 | PALIO       | FIAT           | ABC 2020 |
|        5 | FOX         | VOLKSWAGEN     | AAA 1010 |
|        6 | SIENA       | FIAT           | AXY 4526 |
|        7 | CELTA       | GENERAL MOTORS | AMN 9090 |
|        8 | VOYAGE      | VOLKSWAGEN     | ABC 7010 |
|        9 | HB20        | VOLKSWAGEN     | PPB 7070 |
|       10 | CORSA SEDAN | GENERAL MOTORS | AAB 8562 |
|       11 | ONIX        | GENERAL MOTORS | THM 7610 |
|       12 | SANDERO     | RENAULT        | ACB 7026 |
|       13 | FIESTA      | FORD           | ASD 2030 |
|       14 | COBALT      | GENERAL MOTORS | AGH 4630 |
|       15 | KA          | FORD           | ACB 1029 |
|       16 | COROLLA     | TOYOTA         | ACV 4629 |
|       17 | CIVIC       | HONDA          | AKL 2065 |
|       18 | PUNTO       | FIAT           | APR 8340 |
|       19 | FIT         | HONDA          | AMB 1532 |
|       20 | SPIN        | GENERAL MOTORS | ARP 9064 |
|       21 | C3          | CITROEN        | ALP 1021 |
|       22 | CRUZE SEDAN | GENERAL MOTORS | ALK 9030 |
|       23 | LOGAN       | RENAULT        | ATP 7923 |
|       24 | AGILE       | GENERAL MOTORS | ARP 8032 |
|       25 | CITY        | HONDA          | ALP 8030 |
|       26 | IDEA        | FIAT           | BCD 7941 |
|       27 | MARCH       | NISSAN         | ABC 4692 |
+----------+-------------+----------------+----------+

INSERT INTO CLIENTE VALUES(NULL, 'MARCIO','M',25);
INSERT INTO CLIENTE VALUES(NULL, 'RICARDO', 'M', 13);
INSERT INTO CLIENTE VALUES(NULL, 'ROBERTA', 'F', 22);
INSERT INTO CLIENTE VALUES(NULL, 'SILVIA', 'F', 6);
INSERT INTO CLIENTE VALUES(NULL, 'JOSÉ', 'M', 2);
INSERT INTO CLIENTE VALUES(NULL, 'CÉLIA', 'F', 11);
INSERT INTO CLIENTE VALUES(NULL, 'AMANDA', 'F', 12);
INSERT INTO CLIENTE VALUES(NULL, 'ROBERTO', 'M', 15);
INSERT INTO CLIENTE VALUES(NULL, 'ANTÔNIO', 'M', 21);
INSERT INTO CLIENTE VALUES(NULL, 'BEATRIZ', 'F', 24);
+------------+----------+------+-----------+
| CODCLIENTE | NOME     | SEXO | COD_CARRO |
+------------+----------+------+-----------+
|          1 | MARCIO   | M    |        25 |
|          2 | RICARDO  | M    |        13 |
|          3 | ROBERTA  | F    |        22 |
|          4 | SILVIA   | F    |         6 |
|          5 | JOSÉ     | M    |         2 |
|          6 | CÉLIA    | F    |        11 |
|          7 | AMANDA   | F    |        12 |
|          8 | ROBERTO  | M    |        15 |
|          9 | ANTÔNIO  | M    |        21 |
|         11 | BEATRIZ  | F    |        24 |
+------------+----------+------+-----------+

SELECT CODCLIENTE, NOME, SEXO, MODELO FROM CLIENTE
INNER JOIN CARRO
ON COD_CARRO = CODCARRO;
+------------+----------+------+-------------+
| CODCLIENTE | NOME     | SEXO | MODELO      |
+------------+----------+------+-------------+
|          1 | MARCIO   | M    | CITY        |
|          2 | RICARDO  | M    | FIESTA      |
|          3 | ROBERTA  | F    | CRUZE SEDAN |
|          4 | SILVIA   | F    | SIENA       |
|          5 | JOSÉ     | M    | GOL         |
|          6 | CÉLIA    | F    | ONIX        |
|          7 | AMANDA   | F    | SANDERO     |
|          8 | ROBERTO  | M    | KA          |
|          9 | ANTÔNIO  | M    | C3          |
|         11 | BEATRIZ  | F    | AGILE       |
+------------+----------+------+-------------+


INSERT INTO TELEFONE VALUES(NULL, 'CEL','(11)9 8236-6325',6);
INSERT INTO TELEFONE VALUES(NULL, 'RES','(11) 9622-0101',11);
INSERT INTO TELEFONE VALUES(NULL, 'CEL','(11)9 8963-2525', 8);
INSERT INTO TELEFONE VALUES(NULL, 'COM','(11) 9310-2020',9);
INSERT INTO TELEFONE VALUES(NULL, 'RES','(11) 9150-3020',9);
INSERT INTO TELEFONE VALUES(NULL, 'CEL','(11)9 8039-1256',7);
INSERT INTO TELEFONE VALUES(NULL, 'COM','(11) 40408090',2);
+-------------+------+-----------------+-------------+
| CODTELEFONE | TIPO | NUMERO          | COD_CLIENTE |
+-------------+------+-----------------+-------------+
|           1 | CEL  | (11)9 8236-6325 |           6 |
|           2 | RES  | (11) 9622-0101  |          11 |
|           3 | CEL  | (11)9 8963-2525 |           8 |
|           4 | COM  | (11) 9310-2020  |           9 |
|           5 | RES  | (11) 9150-3020  |           9 |
|           6 | CEL  | (11)9 8039-1256 |           7 |
|           7 | COM  | (11) 40408090   |           2 |
+-------------+------+-----------------+-------------+

SELECT * FROM CLIENTE 
LEFT JOIN TELEFONE
ON CODCLIENTE = COD_CLIENTE;
+------------+----------+------+-----------+-------------+------+-----------------+-------------+
| CODCLIENTE | NOME     | SEXO | COD_CARRO | CODTELEFONE | TIPO | NUMERO          | COD_CLIENTE |
+------------+----------+------+-----------+-------------+------+-----------------+-------------+
|          1 | MARCIO   | M    |        25 |        NULL | NULL | NULL            |        NULL |
|          2 | RICARDO  | M    |        13 |           7 | COM  | (11) 40408090   |           2 |
|          3 | ROBERTA  | F    |        22 |        NULL | NULL | NULL            |        NULL |
|          4 | SILVIA   | F    |         6 |        NULL | NULL | NULL            |        NULL |
|          5 | JOSÉ     | M    |         2 |        NULL | NULL | NULL            |        NULL |
|          6 | CÉLIA    | F    |        11 |           1 | CEL  | (11)9 8236-6325 |           6 |
|          7 | AMANDA   | F    |        12 |           6 | CEL  | (11)9 8039-1256 |           7 |
|          8 | ROBERTO  | M    |        15 |           3 | CEL  | (11)9 8963-2525 |           8 |
|          9 | ANTÔNIO  | M    |        21 |           4 | COM  | (11) 9310-2020  |           9 |
|          9 | ANTÔNIO  | M    |        21 |           5 | RES  | (11) 9150-3020  |           9 |
|         11 | BEATRIZ  | F    |        24 |           2 | RES  | (11) 9622-0101  |          11 |
+------------+----------+------+-----------+-------------+------+-----------------+-------------+

SELECT CODCLIENTE AS 'COD', NOME, NUMERO FROM CLIENTE 
LEFT JOIN TELEFONE
ON CODCLIENTE = COD_CLIENTE;
+-----+----------+-----------------+
| COD | NOME     | NUMERO          |
+-----+----------+-----------------+
|   1 | MARCIO   | NULL            |
|   2 | RICARDO  | (11) 40408090   |
|   3 | ROBERTA  | NULL            |
|   4 | SILVIA   | NULL            |
|   5 | JOSÉ     | NULL            |
|   6 | CÉLIA    | (11)9 8236-6325 |
|   7 | AMANDA   | (11)9 8039-1256 |
|   8 | ROBERTO  | (11)9 8963-2525 |
|   9 | ANTÔNIO  | (11) 9310-2020  |
|   9 | ANTÔNIO  | (11) 9150-3020  |
|  11 | BEATRIZ  | (11) 9622-0101  |
+-----+----------+-----------------+

INSERT INTO COR VALUES(NULL, 'AZUL');
INSERT INTO COR VALUES(NULL, 'VERMELHO');
INSERT INTO COR VALUES(NULL, 'VERDE');
INSERT INTO COR VALUES(NULL, 'CINZA');
INSERT INTO COR VALUES(NULL, 'BRANCO');
INSERT INTO COR VALUES(NULL, 'PRETO');
INSERT INTO COR VALUES(NULL, 'AMARELO');
+--------+----------+
| CODCOR | COR      |
+--------+----------+
|      7 | AMARELO  |
|      1 | AZUL     |
|      5 | BRANCO   |
|      4 | CINZA    |
|      6 | PRETO    |
|      3 | VERDE    |
|      2 | VERMELHO |
+--------+----------+

SELECT * FROM COR ORDER BY CODCOR;
+--------+----------+
| CODCOR | COR      |
+--------+----------+
|      1 | AZUL     |
|      2 | VERMELHO |
|      3 | VERDE    |
|      4 | CINZA    |
|      5 | BRANCO   |
|      6 | PRETO    |
|      7 | AMARELO  |
+--------+----------+
--7 CORES E 27 CARROS
INSERT INTO CARRO_COR VALUES(2,7);
INSERT INTO CARRO_COR VALUES(3,1);
INSERT INTO CARRO_COR VALUES(4,3);
INSERT INTO CARRO_COR VALUES(5,4);
INSERT INTO CARRO_COR VALUES(6,7);
INSERT INTO CARRO_COR VALUES(7,2);
INSERT INTO CARRO_COR VALUES(7,2);
INSERT INTO CARRO_COR VALUES(8,3);
INSERT INTO CARRO_COR VALUES(9,7);
INSERT INTO CARRO_COR VALUES(10,4);
INSERT INTO CARRO_COR VALUES(10,1);
INSERT INTO CARRO_COR VALUES(10,6);
INSERT INTO CARRO_COR VALUES(11,5);
INSERT INTO CARRO_COR VALUES(12,5);
INSERT INTO CARRO_COR VALUES(13,6);
INSERT INTO CARRO_COR VALUES(14,7);
INSERT INTO CARRO_COR VALUES(15,1);
INSERT INTO CARRO_COR VALUES(16,3);
INSERT INTO CARRO_COR VALUES(17,6);
INSERT INTO CARRO_COR VALUES(18,7);
INSERT INTO CARRO_COR VALUES(19,7);
INSERT INTO CARRO_COR VALUES(20,1);
INSERT INTO CARRO_COR VALUES(21,6);
INSERT INTO CARRO_COR VALUES(21,4);
INSERT INTO CARRO_COR VALUES(22,3);
INSERT INTO CARRO_COR VALUES(23,7);
INSERT INTO CARRO_COR VALUES(23,4);
INSERT INTO CARRO_COR VALUES(24,2);
INSERT INTO CARRO_COR VALUES(25,6);
INSERT INTO CARRO_COR VALUES(25,7);
INSERT INTO CARRO_COR VALUES(25,3);
INSERT INTO CARRO_COR VALUES(26,5);
INSERT INTO CARRO_COR VALUES(27,4);

SELECT * FROM CARRO_COR;
+-----------+---------+
| COD_CARRO | COD_COR |
+-----------+---------+
|         3 |       1 |
|        10 |       1 |
|        15 |       1 |
|        20 |       1 |
|         7 |       2 |
|        24 |       2 |
|         4 |       3 |
|         8 |       3 |
|        16 |       3 |
|        22 |       3 |
|        25 |       3 |
|         5 |       4 |
|        10 |       4 |
|        21 |       4 |
|        23 |       4 |
|        27 |       4 |
|        11 |       5 |
|        12 |       5 |
|        26 |       5 |
|        10 |       6 |
|        13 |       6 |
|        17 |       6 |
|        21 |       6 |
|        25 |       6 |
|         2 |       7 |
|         6 |       7 |
|         9 |       7 |
|        14 |       7 |
|        18 |       7 |
|        19 |       7 |
|        23 |       7 |
|        25 |       7 |
+-----------+---------+

SELECT A.MODELO, B.COD_COR
FROM CARRO A
INNER JOIN CARRO_COR B
ON A.CODCARRO = B.COD_CARRO;
+-------------+---------+
| MODELO      | COD_COR |
+-------------+---------+
| GOL         |       7 |
| UNO         |       1 |
| PALIO       |       3 |
| FOX         |       4 |
| SIENA       |       7 |
| CELTA       |       2 |
| VOYAGE      |       3 |
| HB20        |       7 |
| CORSA SEDAN |       1 |
| CORSA SEDAN |       4 |
| CORSA SEDAN |       6 |
| ONIX        |       5 |
| SANDERO     |       5 |
| FIESTA      |       6 |
| COBALT      |       7 |
| KA          |       1 |
| COROLLA     |       3 |
| CIVIC       |       6 |
| PUNTO       |       7 |
| FIT         |       7 |
| SPIN        |       1 |
| C3          |       4 |
| C3          |       6 |
| CRUZE SEDAN |       3 |
| LOGAN       |       4 |
| LOGAN       |       7 |
| AGILE       |       2 |
| CITY        |       3 |
| CITY        |       6 |
| CITY        |       7 |
| IDEA        |       5 |
| MARCH       |       4 |
+-------------+---------+

SELECT A.MODELO, C.COR
FROM CARRO A
INNER JOIN CARRO_COR B
ON A.CODCARRO = B.COD_CARRO
INNER JOIN COR C
ON B.COD_COR = C.CODCOR
ORDER BY A.CODCARRO;
+-------------+----------+
| MODELO      | COR      |
+-------------+----------+
| GOL         | AMARELO  |
| UNO         | AZUL     |
| PALIO       | VERDE    |
| FOX         | CINZA    |
| SIENA       | AMARELO  |
| CELTA       | VERMELHO |
| VOYAGE      | VERDE    |
| HB20        | AMARELO  |
| CORSA SEDAN | AZUL     |
| CORSA SEDAN | CINZA    |
| CORSA SEDAN | PRETO    |
| ONIX        | BRANCO   |
| SANDERO     | BRANCO   |
| FIESTA      | PRETO    |
| COBALT      | AMARELO  |
| KA          | AZUL     |
| COROLLA     | VERDE    |
| CIVIC       | PRETO    |
| PUNTO       | AMARELO  |
| FIT         | AMARELO  |
| SPIN        | AZUL     |
| C3          | CINZA    |
| C3          | PRETO    |
| CRUZE SEDAN | VERDE    |
| LOGAN       | AMARELO  |
| LOGAN       | CINZA    |
| AGILE       | VERMELHO |
| CITY        | VERDE    |
| CITY        | PRETO    |
| CITY        | AMARELO  |
| IDEA        | BRANCO   |
| MARCH       | CINZA    |
+-------------+----------+

/*=================================================*/
/*======== A39 - ENTENDENDO TRIGGERS ==============*/
/*=================================================*/
/*ESTRUTURA DE UMA TRIGGER*/

CREATE TRIGGER NOME
BEFORE/AFTER INSERT/UPDATE/DELETE ON TABELA
FOR EACH ROW (PARA CADA LINHA)
BEGIN --> INÍCIO

       --QUALQUER COMANDO SQL

END   --> FIM

--TRIGGER É UM GATILHO
DESC TRIGGERS;
+----------------------------+---------------+------+-----+---------+-------+
| Field                      | Type          | Null | Key | Default | Extra |
+----------------------------+---------------+------+-----+---------+-------+
| TRIGGER_CATALOG            | varchar(512)  | NO   |     |         |       |
| TRIGGER_SCHEMA             | varchar(64)   | NO   |     |         |       |
| TRIGGER_NAME               | varchar(64)   | NO   |     |         |       |
| EVENT_MANIPULATION         | varchar(6)    | NO   |     |         |       |
| EVENT_OBJECT_CATALOG       | varchar(512)  | NO   |     |         |       |
| EVENT_OBJECT_SCHEMA        | varchar(64)   | NO   |     |         |       |
| EVENT_OBJECT_TABLE         | varchar(64)   | NO   |     |         |       |
| ACTION_ORDER               | bigint(4)     | NO   |     | 0       |       |
| ACTION_CONDITION           | longtext      | YES  |     | NULL    |       |
| ACTION_STATEMENT           | longtext      | NO   |     | NULL    |       |
| ACTION_ORIENTATION         | varchar(9)    | NO   |     |         |       |
| ACTION_TIMING              | varchar(6)    | NO   |     |         |       |
| ACTION_REFERENCE_OLD_TABLE | varchar(64)   | YES  |     | NULL    |       |
| ACTION_REFERENCE_NEW_TABLE | varchar(64)   | YES  |     | NULL    |       |
| ACTION_REFERENCE_OLD_ROW   | varchar(3)    | NO   |     |         |       |
| ACTION_REFERENCE_NEW_ROW   | varchar(3)    | NO   |     |         |       |
| CREATED                    | datetime(2)   | YES  |     | NULL    |       |
| SQL_MODE                   | varchar(8192) | NO   |     |         |       |
| DEFINER                    | varchar(93)   | NO   |     |         |       |
| CHARACTER_SET_CLIENT       | varchar(32)   | NO   |     |         |       |
| COLLATION_CONNECTION       | varchar(32)   | NO   |     |         |       |
| DATABASE_COLLATION         | varchar(32)   | NO   |     |         |       |
+----------------------------+---------------+------+-----+---------+-------+


/*=================================================*/
/*============== A40 - CONTINUAÇÃO ================*/
/*=================================================*/

CREATE DATABASE AULA40;

USE AULA40;

CREATE TABLE USUARIO(
	CODUSUARIO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	LOGIN VARCHAR(30),
	SENHA VARCHAR(100)
);

ALTER TABLE BKP_USUARIO(
	CODBACKUP INT PRIMARY KEY AUTO_INCREMENT,
	CODUSUARIO INT,
	NOME VARCHAR(30),
	LOGIN VARCHAR(100)
);

/*CRIANDO A TRIGGER*/
DELIMITER $

CREATE TRIGGER BACKUP_USER
BEFORE DELETE ON USUARIO
FOR EACH ROW
BEGIN
	INSERT INTO BKP_USUARIO 
	VALUES(NULL, OLD.CODUSUARIO, OLD.NOME, OLD.LOGIN);
END
$
	
DELIMITER ;
INSERT INTO USUARIO VALUES(NULL,'ANDRADE','ANDRADE2009','HEXACAMPEAO');
SELECT * FROM USUARIO;
+------------+---------+-------------+-------------+
| CODUSUARIO | NOME    | LOGIN       | SENHA       |
+------------+---------+-------------+-------------+
|          1 | ANDRADE | ANDRADE2009 | HEXACAMPEAO |
+------------+---------+-------------+-------------+

INSERT INTO USUARIO VALUES(NULL,'AMARAUS','AMARAUS2009','JOGADOR');
+------------+---------+-------------+-------------+
| CODUSUARIO | NOME    | LOGIN       | SENHA       |
+------------+---------+-------------+-------------+
|          1 | ANDRADE | ANDRADE2009 | HEXACAMPEAO |
|          2 | AMARAUS | AMARAUS2009 | JOGADOR     |
+------------+---------+-------------+-------------+

DELETE FROM USUARIO WHERE CODUSUARIO = 1;

ALTER TABLE USUARIO CHANGE LOGIN LOGIN VARCHAR(100);

/*CONTINUAR DEPOIS*/
USE AULA40;
TABELA USUARIO






CREATE TRIGGER NOME
BEFORE/AFTER INSERT/UPDATE/DELETE ON TABELA
FOR EACH ROW (PARA CADA LINHA)
BEGIN --> INÍCIO

       --QUALQUER COMANDO SQL

END   --> FIM

/*=================================================*/
/*======== A41 - COMUNICAÇÃO ENTRE BANCOS =========*/
/*=================================================*/

CREATE DATABASE LOJA;

USE LOJA;

CREATE TABLE PRODUTO(
	CODPRODUTO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	VALOR FLOAT(10,2)
);

STATUS

CREATE DATABASE BACKUP;

USE BACKUP;

CREATE TABLE BKP_PRODUTO(
	CODBKP INT PRIMARY KEY AUTO_INCREMENT,
	CODPRODUTO INT,
	NOME VARCHAR(30),
	VALOR FLOAT(10,2)
);

USE LOJA;

STATUS

INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, 1000, 'TESTE', 0.0);

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+-------+-------+
| CODBKP | CODPRODUTO | NOME  | VALOR |
+--------+------------+-------+-------+
|      1 |       1000 | TESTE |  0.00 |
+--------+------------+-------+-------+

/*INICIO*/
DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO
BEFORE INSERT ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, NEW.CODPRODUTO, NEW.NOME, NEW.VALOR);
END
$
DELIMITER ;
/*FINAL*/

INSERT INTO PRODUTO VALUES(NULL,'LIVRO MODELAGEM', 50.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO BI', 80.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO ORACLE', 70.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO SQL SERVER', 100.00);

SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          2 | LIVRO BI         |  80.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 100.00 |
+------------+------------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+------------------+--------+
| CODBKP | CODPRODUTO | NOME             | VALOR  |
+--------+------------+------------------+--------+
|      1 |       1000 | TESTE            |   0.00 |
|      2 |          0 | LIVRO MODELAGEM  |  50.00 |
|      3 |          0 | LIVRO BI         |  80.00 |
|      4 |          0 | LIVRO ORACLE     |  70.00 |
|      5 |          0 | LIVRO SQL SERVER | 100.00 |
+--------+------------+------------------+--------+

/*INICIO*/
DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO_DEL
BEFORE DELETE ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, OLD.CODPRODUTO, OLD.NOME, OLD.VALOR);
END
$
DELIMITER ;
/*FINAL*/

DELETE FROM PRODUTO WHERE CODPRODUTO = 2;
SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 100.00 |
+------------+------------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+------------------+--------+
| CODBKP | CODPRODUTO | NOME             | VALOR  |
+--------+------------+------------------+--------+
|      1 |       1000 | TESTE            |   0.00 |
|      2 |          0 | LIVRO MODELAGEM  |  50.00 |
|      3 |          0 | LIVRO BI         |  80.00 |
|      4 |          0 | LIVRO ORACLE     |  70.00 |
|      5 |          0 | LIVRO SQL SERVER | 100.00 |
|      6 |          2 | LIVRO BI         |  80.00 |
+--------+------------+------------------+--------+

DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO
AFTER INSERT ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, NEW.CODPRODUTO, NEW.NOME, NEW.VALOR);
END
$
DELIMITER ;

INSERT INTO PRODUTO VALUES(NULL,'LIVRO C#', 100.00);

SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 100.00 |
|          5 | LIVRO C#         | 100.00 |
+------------+------------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+------------------+--------+
| CODBKP | CODPRODUTO | NOME             | VALOR  |
+--------+------------+------------------+--------+
|      1 |       1000 | TESTE            |   0.00 |
|      2 |          0 | LIVRO MODELAGEM  |  50.00 |
|      3 |          0 | LIVRO BI         |  80.00 |
|      4 |          0 | LIVRO ORACLE     |  70.00 |
|      5 |          0 | LIVRO SQL SERVER | 100.00 |
|      6 |          2 | LIVRO BI         |  80.00 |
|      7 |          0 | LIVRO C#         | 100.00 |
|      8 |          5 | LIVRO C#         | 100.00 |
+--------+------------+------------------+--------+

/*=================================================*/
/* A42 - COMPLETAR TRIGGERS E DEIXANDO DA FORMA MAIS CONCRETA*/
/*=================================================*/
ALTER TABLE BACKUP.BKP_PRODUTO
ADD EVENTO CHAR(1);

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+------------------+--------+--------+
| CODBKP | CODPRODUTO | NOME             | VALOR  | EVENTO |
+--------+------------+------------------+--------+--------+
|      1 |       1000 | TESTE            |   0.00 | NULL   |
|      2 |          0 | LIVRO MODELAGEM  |  50.00 | NULL   |
|      3 |          0 | LIVRO BI         |  80.00 | NULL   |
|      4 |          0 | LIVRO ORACLE     |  70.00 | NULL   |
|      5 |          0 | LIVRO SQL SERVER | 100.00 | NULL   |
|      6 |          2 | LIVRO BI         |  80.00 | NULL   |
|      7 |          0 | LIVRO C#         | 100.00 | NULL   |
|      8 |          5 | LIVRO C#         | 100.00 | NULL   |
+--------+------------+------------------+--------+--------+

DROP TRIGGER BACKUP_PRODUTO_DEL;

DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO_DEL
BEFORE DELETE ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, OLD.CODPRODUTO, OLD.NOME, OLD.VALOR, 'D');
END
$
DELIMITER ;

DELETE FROM PRODUTO WHERE CODPRODUTO = 4;
SELECT * FROM PRODUTO;
+------------+-----------------+--------+
| CODPRODUTO | NOME            | VALOR  |
+------------+-----------------+--------+
|          1 | LIVRO MODELAGEM |  50.00 |
|          3 | LIVRO ORACLE    |  70.00 |
|          5 | LIVRO C#        | 100.00 |
+------------+-----------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+--------+------------+------------------+--------+--------+
| CODBKP | CODPRODUTO | NOME             | VALOR  | EVENTO |
+--------+------------+------------------+--------+--------+
|      1 |       1000 | TESTE            |   0.00 | NULL   |
|      2 |          0 | LIVRO MODELAGEM  |  50.00 | NULL   |
|      3 |          0 | LIVRO BI         |  80.00 | NULL   |
|      4 |          0 | LIVRO ORACLE     |  70.00 | NULL   |
|      5 |          0 | LIVRO SQL SERVER | 100.00 | NULL   |
|      6 |          2 | LIVRO BI         |  80.00 | NULL   |
|      7 |          0 | LIVRO C#         | 100.00 | NULL   |
|      8 |          5 | LIVRO C#         | 100.00 | NULL   |
|      9 |          4 | LIVRO SQL SERVER | 100.00 | D      |
+--------+------------+------------------+--------+--------+

DROP TRIGGER BACKUP_PRODUTO_INS;

DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO_INS
AFTER INSERT ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, NEW.CODPRODUTO, NEW.NOME, NEW.VALOR, 'I');
END
$
DELIMITER ;

/*NAÕ DEU CERTO!!!!!!*/
INSERT INTO PRODUTO VALUES(NULL,'LIVRO ANDROID', 90.00);














/*=================================================*/
/*=========== A42 - TRIGGER DE AUDITORIA ==========*/
/*=================================================*/
DROP DATABASE LOJA; 
DROP DATABASE BACKUP;

CREATE DATABASE LOJA;
USE LOJA;

CREATE TABLE PRODUTO(
	CODPRODUTO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	VALOR FLOAT(10,2)
);

INSERT INTO PRODUTO VALUES(NULL,'LIVRO MODELAGEM', 50.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO BI', 80.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO ORACLE', 70.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO SQL SERVER', 100.00);
INSERT INTO PRODUTO VALUES(NULL,'LIVRO MAFRA', 120.00);

CREATE DATABASE BACKUP;

USE BACKUP;

/* QUANDO */
SELECT NOW();

/* QUEM */
SELECT CURRENT_USER();

CREATE TABLE BKP_PRODUTO(
	CODBACKUP INT PRIMARY KEY AUTO_INCREMENT,
	CODPRODUTO INT,
	NOME VARCHAR(30),
	VALOR_ORIGINAL FLOAT(10,2),
	VALOR_ALTERADO FLOAT(10,2),
	DATA DATETIME,
	USUARIO VARCHAR(30),
	EVENTO CHAR(1)
);

SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          2 | LIVRO BI         |  80.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 100.00 |
|          5 | LIVRO MAFRA      | 120.00 |
+------------+------------------+--------+

DELIMITER $
CREATE TRIGGER AUDIT_PROD
AFTER UPDATE ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, OLD.CODPRODUTO, OLD.NOME, OLD.VALOR, NEW.VALOR, NOW(),CURRENT_USER(),'U');
END
$
DELIMITER ;

UPDATE PRODUTO SET VALOR = 110.00
WHERE CODPRODUTO = 4;

SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          2 | LIVRO BI         |  80.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 110.00 |
|          5 | LIVRO MAFRA      | 120.00 |
+------------+------------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
| CODBACKUP | CODPRODUTO | NOME             | VALOR_ORIGINAL | VALOR_ALTERADO | DATA                | USUARIO        | EVENTO |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
|         1 |          4 | LIVRO SQL SERVER |         100.00 |         110.00 | 2017-09-07 14:38:35 | root@localhost | U      |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+



SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          2 | LIVRO BI         |  95.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 110.00 |
|          5 | LIVRO MAFRA      | 120.00 |
+------------+------------------+--------+


UPDATE PRODUTO SET VALOR = 95.00
WHERE CODPRODUTO = 2;
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
| CODBACKUP | CODPRODUTO | NOME             | VALOR_ORIGINAL | VALOR_ALTERADO | DATA                | USUARIO        | EVENTO |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
|         1 |          4 | LIVRO SQL SERVER |         100.00 |         110.00 | 2017-09-07 14:38:35 | root@localhost | U      |
|         2 |          2 | LIVRO BI         |          80.00 |          95.00 | 2017-09-07 18:05:03 | root@localhost | U      |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
/*INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, OLD.CODPRODUTO, OLD.NOME, OLD.VALOR, NEW.VALOR, NOW(),CURRENT_USER(),'U');*/

/* INSERÇÃO USANDO TRIGGER */
DROP TRIGGER INSERIR_PROD;

DELIMITER $
CREATE TRIGGER INSERIR_PROD
AFTER INSERT ON PRODUTO
FOR EACH ROW
BEGIN

	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, NEW.CODPRODUTO, NEW.NOME, NEW.VALOR, 0.00, NOW(),CURRENT_USER(),'I');
END
$
DELIMITER ;

INSERT INTO PRODUTO VALUES(NULL,'LIVRO ENGENHARIA', 170.00);

SELECT * FROM PRODUTO;
+------------+------------------+--------+
| CODPRODUTO | NOME             | VALOR  |
+------------+------------------+--------+
|          1 | LIVRO MODELAGEM  |  50.00 |
|          2 | LIVRO BI         |  95.00 |
|          3 | LIVRO ORACLE     |  70.00 |
|          4 | LIVRO SQL SERVER | 110.00 |
|          5 | LIVRO MAFRA      | 120.00 |
|          6 | LIVRO ANDROID    |  90.00 |
|          7 | LIVRO eNGENHARIA | 170.00 |
+------------+------------------+--------+

SELECT * FROM BACKUP.BKP_PRODUTO;
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
| CODBACKUP | CODPRODUTO | NOME             | VALOR_ORIGINAL | VALOR_ALTERADO | DATA                | USUARIO        | EVENTO |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
|         1 |          4 | LIVRO SQL SERVER |         100.00 |         110.00 | 2017-09-07 14:38:35 | root@localhost | U      |
|         2 |          2 | LIVRO BI         |          80.00 |          95.00 | 2017-09-07 18:05:03 | root@localhost | U      |
|         3 |          6 | LIVRO ANDROID    |          90.00 |          90.00 | 2017-09-07 18:44:09 | root@localhost | I      |
|         4 |          7 | LIVRO eNGENHARIA |         170.00 |           0.00 | 2017-09-07 18:48:46 | root@localhost | I      |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+


DELIMITER $
CREATE TRIGGER BACKUP_PRODUTO_DEL
BEFORE DELETE ON PRODUTO
FOR EACH ROW
BEGIN
	INSERT INTO BACKUP.BKP_PRODUTO VALUES(NULL, OLD.CODPRODUTO, OLD.NOME, OLD.VALOR, 0.00, NOW(), CURRENT_USER(), 'D');
END
$
DELIMITER ;

DELETE FROM PRODUTO WHERE CODPRODUTO = 5;

SELECT * FROM BACKUP.BKP_PRODUTO;
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
| CODBACKUP | CODPRODUTO | NOME             | VALOR_ORIGINAL | VALOR_ALTERADO | DATA                | USUARIO        | EVENTO |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
|         1 |          4 | LIVRO SQL SERVER |         100.00 |         110.00 | 2017-09-07 14:38:35 | root@localhost | U      |
|         2 |          2 | LIVRO BI         |          80.00 |          95.00 | 2017-09-07 18:05:03 | root@localhost | U      |
|         3 |          6 | LIVRO ANDROID    |          90.00 |          90.00 | 2017-09-07 18:44:09 | root@localhost | I      |
|         4 |          7 | LIVRO eNGENHARIA |         170.00 |           0.00 | 2017-09-07 18:48:46 | root@localhost | I      |
|         5 |          5 | LIVRO MAFRA      |         120.00 |           0.00 | 2017-09-07 18:55:05 | root@localhost | D      |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+

UPDATE PRODUTO SET NOME = 'LIVRO ENGENHARIA'
WHERE CODPRODUTO = 7;
SELECT * FROM PRODUTO;
SELECT * FROM BACKUP.BKP_PRODUTO;
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
| CODBACKUP | CODPRODUTO | NOME             | VALOR_ORIGINAL | VALOR_ALTERADO | DATA                | USUARIO        | EVENTO |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+
|         1 |          4 | LIVRO SQL SERVER |         100.00 |         110.00 | 2017-09-07 14:38:35 | root@localhost | U      |
|         2 |          2 | LIVRO BI         |          80.00 |          95.00 | 2017-09-07 18:05:03 | root@localhost | U      |
|         3 |          6 | LIVRO ANDROID    |          90.00 |          90.00 | 2017-09-07 18:44:09 | root@localhost | I      |
|         4 |          7 | LIVRO eNGENHARIA |         170.00 |           0.00 | 2017-09-07 18:48:46 | root@localhost | I      |
|         5 |          5 | LIVRO MAFRA      |         120.00 |           0.00 | 2017-09-07 18:55:05 | root@localhost | D      |
|         6 |          7 | LIVRO eNGENHARIA |         170.00 |         170.00 | 2017-09-07 18:56:45 | root@localhost | U      |
+-----------+------------+------------------+----------------+----------------+---------------------+----------------+--------+


USE LOJA;
SELECT * FROM PRODUTO;
SELECT * FROM BACKUP.BKP_PRODUTO;
/*=================================================*/
/*=========== A44 - AUTORELACIONAMENTO ============*/
/*=================================================*/

CREATE DATABASE AULA44;
USE AULA44;


CREATE TABLE CURSOS(
	CODCURSO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	HORAS INT,
	VALOR FLOAT(10,2),
	COD_PREREQ INT
);

ALTER TABLE CURSOS ADD CONSTRAINT FK_PREREQ
FOREIGN KEY(COD_PREREQ) REFERENCES CURSOS(CODCURSO);

INSERT INTO CURSOS VALUES(NULL, 'BD RELACIONAL',20, 400.00, NULL);
INSERT INTO CURSOS VALUES(NULL, 'BUSINESS INTELIGENCE',40, 800.00, 1);
INSERT INTO CURSOS VALUES(NULL, 'RELATORIOS AVANÇADOS',20, 600.00, 2);
INSERT INTO CURSOS VALUES(NULL, 'LOGICA DE PROGRAMAÇÃO',30, 300.00, NULL);
INSERT INTO CURSOS VALUES(NULL, 'RUBY',20, 500.00, 4);


SELECT * FROM CURSOS;
+----------+-------------------------+-------+--------+------------+
| CODCURSO | NOME                    | HORAS | VALOR  | COD_PREREQ |
+----------+-------------------------+-------+--------+------------+
|        1 | BD RELACIONAL           |    20 | 400.00 |       NULL |
|        2 | BUSINESS INTELIGENCE    |    40 | 800.00 |          1 |
|        3 | RELATORIOS AVANÇADOS    |    20 | 600.00 |          2 |
|        4 | LOGICA DE PROGRAMAÇÃO   |    30 | 300.00 |       NULL |
|        5 | RUBY                    |    20 | 500.00 |          4 |
+----------+-------------------------+-------+--------+------------+


SELECT NOME, VALOR, HORAS, IFNULL(COD_PREREQ, "SEM REQ") REQUISITO FROM CURSOS;
+-------------------------+--------+-------+-----------+
| NOME                    | VALOR  | HORAS | REQUISITO |
+-------------------------+--------+-------+-----------+
| BD RELACIONAL           | 400.00 |    20 | SEM REQ   |
| BUSINESS INTELIGENCE    | 800.00 |    40 | 1         |
| RELATORIOS AVANÇADOS    | 600.00 |    20 | 2         |
| LOGICA DE PROGRAMAÇÃO   | 300.00 |    30 | SEM REQ   |
| RUBY                    | 500.00 |    20 | 4         |
+-------------------------+--------+-------+-----------+

/* NOME, VALOR, HORAS E O NOME DO PREREQUISITO DO CURSO */
SELECT A.CODCURSO, A.NOME AS CURSO, A.VALOR, A.HORAS, IFNULL(A.COD_PREREQ, "------") REQUISITO, IFNULL(B.NOME, "------") AS CURSO
FROM CURSOS A LEFT JOIN CURSOS B
ON A.CODCURSO = B.COD_PREREQ;
+----------+-------------------------+--------+-------+-----------+-----------------------+
| CODCURSO | CURSO                   | VALOR  | HORAS | REQUISITO | CURSO                 |
+----------+-------------------------+--------+-------+-----------+-----------------------+
|        1 | BD RELACIONAL           | 400.00 |    20 | ------    | BUSINESS INTELIGENCE  |
|        2 | BUSINESS INTELIGENCE    | 800.00 |    40 | 1         | RELATORIOS AVANÇADOS  |
|        4 | LOGICA DE PROGRAMAÇÃO   | 300.00 |    30 | ------    | RUBY                  |
|        3 | RELATORIOS AVANÇADOS    | 600.00 |    20 | 2         | ------                |
|        5 | RUBY                    | 500.00 |    20 | 4         | ------                |
+----------+-------------------------+--------+-------+-----------+-----------------------+


/*=================================================*/
/*======== A45 - CURSORES ======*/
/*=================================================*/

CREATE DATABASE CURSORES;
USE CURSORES;
CREATE TABLE VENDEDORES(
	CODVENDEDOR INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(50),
	JAN INT,
	FEV INT,
	MAR INT
);

INSERT INTO VENDEDORES VALUES(NULL, 'MAFRA', 25633,12563,56325);
INSERT INTO VENDEDORES VALUES(NULL, 'CLARA', 45212,71114,85232);
INSERT INTO VENDEDORES VALUES(NULL, 'JOAO', 25633,89552,02320);
INSERT INTO VENDEDORES VALUES(NULL, 'LILIAN', 45265,84454,95632);
INSERT INTO VENDEDORES VALUES(NULL, 'GLORIA', 745852,20211,52141);

SELECT * FROM VENDEDORES;
+-------------+--------+--------+-------+-------+
| CODVENDEDOR | NOME   | JAN    | FEV   | MAR   |
+-------------+--------+--------+-------+-------+
|           1 | MAFRA  |  25633 | 12563 | 56325 |
|           2 | CLARA  |  45212 | 71114 | 85232 |
|           3 | JOAO   |  25633 | 89552 |  2320 |
|           4 | LILIAN |  45265 | 84454 | 95632 |
|           5 | GLORIA | 745852 | 20211 | 52141 |
+-------------+--------+--------+-------+-------+

SELECT NOME, (JAN+FEV+MAR) AS TOTAL FROM VENDEDORES;
+--------+--------+
| NOME   | TOTAL  |
+--------+--------+
| MAFRA  |  94521 |
| CLARA  | 201558 |
| JOAO   | 117505 |
| LILIAN | 225351 |
| GLORIA | 818204 |
+--------+--------+

SELECT NOME, (JAN+FEV+MAR) AS TOTAL, (JAN+FEV+MAR)/3 AS MEDIA FROM VENDEDORES;
+--------+--------+-------------+
| NOME   | TOTAL  | MEDIA       |
+--------+--------+-------------+
| MAFRA  |  94521 |  31507.0000 |
| CLARA  | 201558 |  67186.0000 |
| JOAO   | 117505 |  39168.3333 |
| LILIAN | 225351 |  75117.0000 |
| GLORIA | 818204 | 272734.6667 |
+--------+--------+-------------+

CREATE TABLE VEND_TOTAL(
	CODVENDEDOR INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(50),
	JAN INT,
	FEV INT,
	MAR INT,
	TOTAL INT,
	MEDIA INT
);

/*=================================================*/
/*============ A45 - CURSORES PARTE 2 =============*/
/*=================================================*/
--DECLARAÇÃO DE UMA VARIÁVEL EM UMA PROCEDURE SE INICIA COM DECLARE
--MANIPULAÇÃO CONTÍNUA (CONTINUE HANDLER)

DELIMITER $
CREATE PROCEDURE INSEREDADOS()
BEGIN
	DECLARE FIM INT DEFAULT 0;
	DECLARE VAR1, VAR2, VAR3, VTOTAL, VMEDIA INT;
	DECLARE VNOME VARCHAR(50);
	
	DECLARE REG CURSOR FOR(
		SELECT NOME, JAN, FEV, MAR FROM VENDEDORES
	);
	
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET FIM = 1;
	
	OPEN REG;
	
	REPEAT
		FETCH REG INTO VNOME, VAR1, VAR2, VAR3;
		
		IF NOT FIM THEN
			SET VTOTAL = VAR1 + VAR2 + VAR3;
			SET VMEDIA = VTOTAL / 3;
			
			INSERT INTO VEND_TOTAL VALUES(NULL, VNOME, VAR1, VAR2, VAR3, VTOTAL, VMEDIA);
		END IF;
	UNTIL FIM END REPEAT;
	
	CLOSE REG;
	
END
$
DELIMITER ;

SELECT * FROM VENDEDORES;
+-------------+--------+--------+-------+-------+
| CODVENDEDOR | NOME   | JAN    | FEV   | MAR   |
+-------------+--------+--------+-------+-------+
|           1 | MAFRA  |  25633 | 12563 | 56325 |
|           2 | CLARA  |  45212 | 71114 | 85232 |
|           3 | JOAO   |  25633 | 89552 |  2320 |
|           4 | LILIAN |  45265 | 84454 | 95632 |
|           5 | GLORIA | 745852 | 20211 | 52141 |
+-------------+--------+--------+-------+-------+
SELECT * FROM VEND_TOTAL;
--NÃO RETORNA NADA PORQUE ESTÁ NO CURSOR SÓ USAR CURSOR
CALL INSEREDADOS();

SELECT * FROM VEND_TOTAL;
+-------------+--------+--------+-------+-------+--------+--------+
| CODVENDEDOR | NOME   | JAN    | FEV   | MAR   | TOTAL  | MEDIA  |
+-------------+--------+--------+-------+-------+--------+--------+
|           1 | MAFRA  |  25633 | 12563 | 56325 |  94521 |  31507 |
|           2 | CLARA  |  45212 | 71114 | 85232 | 201558 |  67186 |
|           3 | JOAO   |  25633 | 89552 |  2320 | 117505 |  39168 |
|           4 | LILIAN |  45265 | 84454 | 95632 | 225351 |  75117 |
|           5 | GLORIA | 745852 | 20211 | 52141 | 818204 | 272735 |
+-------------+--------+--------+-------+-------+--------+--------+


/*=================================================*/
/*=========== A47 - 2ª E 3ª FORMAS NORMAIS ========*/
/*=================================================*/
--PRIMEIRA FN
--ATOMICIDADE - UM CAMPO NÃO PODE SER DIVISÍVEL (MULTIVALORADO)
--UM CAMPO NÃO PODE SER VETORIZADO(VARIOS VALORES EM UM SÓ CAMPO)
--PK CHAVE PRIMÁRIA 

--SEGUNDA FN (SÃO FEITAS NAS CHAVES PRIMARIAS COMPOSTAS)
--OS CAMPOS NÃO CHAVE TEM QUE DEPENDER DA TOTALIDADE DAS CHAVES

--TERCEIRA FN (DEPENDENCIA TRANSITIVA)
--CAMPOS NÃO CHAVE QUE DEPENDENTES DE OUTROS CAMPOS NÃO CHAVE VIRAM OUTRA TABELA
--E A CHAVE ESTRANGEIRA FICA NA TABELA CRIADA

CREATE DATABASE CONSULTORIO;

USE CONSULTORIO;

CREATE TABLE PACIENTE(
	CODPACIENTE INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	SEXO CHAR(1),
	EMAIL VARCHAR(30),
	NASCIMENTO DATE
);

CREATE TABLE MEDICO(
	CODMEDICO INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	SEXO CHAR(1),
	ESPECIALIDADE VARCHAR(30),
	FUNCIONARIO ENUM('S','N')
);

CREATE TABLE HOSPITAL(
	CODHOSPITAL INT PRIMARY KEY AUTO_INCREMENT,
	NOME VARCHAR(30),
	BAIRRO VARCHAR(30),
	CIDADE VARCHAR(30),
	ESTADO CHAR(2)
);

CREATE TABLE CONSULTA(
	CODCONSULTA INT PRIMARY KEY AUTO_INCREMENT,
	COD_PACIENTE INT,
	COD_MEDICO INT,
	COD_HOSPITAL INT,
	DATA DATETIME,
	DIAGNOSTICO VARCHAR(50)
);

CREATE TABLE INTERNACAO(
	CODINTERNACAO INT PRIMARY KEY AUTO_INCREMENT,
	ENTRADA DATETIME,
	QUARTO INT,
	SAIDA INT,
	OBSERVACAO VARCHAR(50),
	COD_CONSULTA INT UNIQUE
);

/*CRIANDO AS CONSTRAINTS - CORREÇÃO COD DO OBJ (PK, FK) _ TABELA PERTENCENTE _ TABELA DE ONDE VEM*/
ALTER TABLE CONSULTA
ADD CONSTRAINT FK_CONSULTA_PACIENTE
FOREIGN KEY(COD_PACIENTE)
REFERENCES PACIENTE(CODPACIENTE);

ALTER TABLE CONSULTA
ADD CONSTRAINT FK_CONSULTA_MEDICO
FOREIGN KEY(COD_MEDICO)
REFERENCES MEDICO(CODMEDICO);

ALTER TABLE CONSULTA
ADD CONSTRAINT FK_CONSULTA_HOSPITAL
FOREIGN KEY(COD_HOSPITAL)
REFERENCES HOSPITAL(CODHOSPITAL);

ALTER TABLE INTERNACAO
ADD CONSTRAINT FK_INTERNACAO_CONSULTA
FOREIGN KEY(COD_CONSULTA)
REFERENCES CONSULTA(CODCONSULTA);

SHOW TABLES;
+-----------------------+
| Tables_in_consultorio |
+-----------------------+
| consulta              |
| hospital              |
| internacao            |
| medico                |
| paciente              |
+-----------------------+

SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| aula40             |
| aula44             |
| backup             |
| comercio           |
| consultorio        |
| cursores           |
| exprojeto          |
| loja               |
| marcio_lista       |
| mysql              |
| oficina            |
| performance_schema |
| projeto            |
| sakila             |
| sys                |
| world              |
+--------------------+

USE INFORMATION_SCHEMA;
DESC TABLE_CONSTRAINTS;
+--------------------+--------------+------+-----+---------+-------+
| Field              | Type         | Null | Key | Default | Extra |
+--------------------+--------------+------+-----+---------+-------+
| CONSTRAINT_CATALOG | varchar(512) | NO   |     |         |       |
| CONSTRAINT_SCHEMA  | varchar(64)  | NO   |     |         |       |
| CONSTRAINT_NAME    | varchar(64)  | NO   |     |         |       |
| TABLE_SCHEMA       | varchar(64)  | NO   |     |         |       |
| TABLE_NAME         | varchar(64)  | NO   |     |         |       |
| CONSTRAINT_TYPE    | varchar(64)  | NO   |     |         |       |
+--------------------+--------------+------+-----+---------+-------+

SELECT * FROM TABLE_CONSTRAINTS;
+--------------------+-------------------+---------------------------+--------------+---------------------------+-----------------+
| CONSTRAINT_CATALOG | CONSTRAINT_SCHEMA | CONSTRAINT_NAME           | TABLE_SCHEMA | TABLE_NAME                | CONSTRAINT_TYPE |
+--------------------+-------------------+---------------------------+--------------+---------------------------+-----------------+
| def                | aula40            | PRIMARY                   | aula40       | bkp_usuario               | PRIMARY KEY     |
| def                | aula40            | PRIMARY                   | aula40       | usuario                   | PRIMARY KEY     |
| def                | aula44            | PRIMARY                   | aula44       | cursos                    | PRIMARY KEY     |
| def                | aula44            | FK_PREREQ                 | aula44       | cursos                    | FOREIGN KEY     |
| def                | backup            | PRIMARY                   | backup       | bkp_produto               | PRIMARY KEY     |
| def                | comercio          | PRIMARY                   | comercio     | cliente                   | PRIMARY KEY     |
| def                | comercio          | EMAIL                     | comercio     | cliente                   | UNIQUE          |
| def                | comercio          | CPF                       | comercio     | cliente                   | UNIQUE          |
| def                | comercio          | PRIMARY                   | comercio     | endereco                  | PRIMARY KEY     |
| def                | comercio          | COD_CLIENTE               | comercio     | endereco                  | UNIQUE          |
| def                | comercio          | FK_CLIENTE_ENDERECO       | comercio     | endereco                  | FOREIGN KEY     |
| def                | comercio          | PRIMARY                   | comercio     | telefone                  | PRIMARY KEY     |
| def                | comercio          | FK_CLIENTE_TELEFONE       | comercio     | telefone                  | FOREIGN KEY     |
| def                | consultorio       | PRIMARY                   | consultorio  | consulta                  | PRIMARY KEY     |
| def                | consultorio       | FK_CONSULTA_HOSPITAL      | consultorio  | consulta                  | FOREIGN KEY     |
| def                | consultorio       | FK_CONSULTA_MEDICO        | consultorio  | consulta                  | FOREIGN KEY     |
| def                | consultorio       | FK_CONSULTA_PACIENTE      | consultorio  | consulta                  | FOREIGN KEY     |
| def                | consultorio       | PRIMARY                   | consultorio  | hospital                  | PRIMARY KEY     |
| def                | consultorio       | PRIMARY                   | consultorio  | internacao                | PRIMARY KEY     |
| def                | consultorio       | COD_CONSULTA              | consultorio  | internacao                | UNIQUE          |
| def                | consultorio       | FK_INTERNACAO_CONSULTA    | consultorio  | internacao                | FOREIGN KEY     |
| def                | consultorio       | PRIMARY                   | consultorio  | medico                    | PRIMARY KEY     |
| def                | consultorio       | PRIMARY                   | consultorio  | paciente                  | PRIMARY KEY     |
| def                | cursores          | PRIMARY                   | cursores     | vend_total                | PRIMARY KEY     |
| def                | cursores          | PRIMARY                   | cursores     | vendedores                | PRIMARY KEY     |
| def                | exprojeto         | PRIMARY                   | exprojeto    | carro                     | PRIMARY KEY     |
| def                | exprojeto         | PRIMARY                   | exprojeto    | cliente                   | PRIMARY KEY     |
| def                | exprojeto         | PRIMARY                   | exprojeto    | cor                       | PRIMARY KEY     |
| def                | exprojeto         | cor_ibfk_1                | exprojeto    | cor                       | FOREIGN KEY     |
| def                | exprojeto         | PRIMARY                   | exprojeto    | marca                     | PRIMARY KEY     |
| def                | exprojeto         | marca_ibfk_1              | exprojeto    | marca                     | FOREIGN KEY     |
| def                | exprojeto         | PRIMARY                   | exprojeto    | telefone                  | PRIMARY KEY     |
| def                | exprojeto         | NUMERO                    | exprojeto    | telefone                  | UNIQUE          |
| def                | exprojeto         | telefone_ibfk_1           | exprojeto    | telefone                  | FOREIGN KEY     |
| def                | loja              | PRIMARY                   | loja         | produto                   | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | columns_priv              | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | db                        | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | engine_cost               | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | event                     | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | func                      | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | gtid_executed             | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | help_category             | PRIMARY KEY     |
| def                | mysql             | name                      | mysql        | help_category             | UNIQUE          |
| def                | mysql             | PRIMARY                   | mysql        | help_keyword              | PRIMARY KEY     |
| def                | mysql             | name                      | mysql        | help_keyword              | UNIQUE          |
| def                | mysql             | PRIMARY                   | mysql        | help_relation             | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | help_topic                | PRIMARY KEY     |
| def                | mysql             | name                      | mysql        | help_topic                | UNIQUE          |
| def                | mysql             | PRIMARY                   | mysql        | innodb_index_stats        | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | innodb_table_stats        | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | ndb_binlog_index          | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | plugin                    | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | proc                      | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | procs_priv                | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | proxies_priv              | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | server_cost               | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | servers                   | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | slave_master_info         | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | slave_relay_log_info      | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | slave_worker_info         | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | tables_priv               | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | time_zone                 | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | time_zone_leap_second     | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | time_zone_name            | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | time_zone_transition      | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | time_zone_transition_type | PRIMARY KEY     |
| def                | mysql             | PRIMARY                   | mysql        | user                      | PRIMARY KEY     |
| def                | oficina           | PRIMARY                   | oficina      | carro                     | PRIMARY KEY     |
| def                | oficina           | PLACA                     | oficina      | carro                     | UNIQUE          |
| def                | oficina           | FK_CARRO_MARCA            | oficina      | carro                     | FOREIGN KEY     |
| def                | oficina           | PRIMARY                   | oficina      | carro_cor                 | PRIMARY KEY     |
| def                | oficina           | FK_CARRO                  | oficina      | carro_cor                 | FOREIGN KEY     |
| def                | oficina           | FK_COR                    | oficina      | carro_cor                 | FOREIGN KEY     |
| def                | oficina           | PRIMARY                   | oficina      | cliente                   | PRIMARY KEY     |
| def                | oficina           | COD_CARRO                 | oficina      | cliente                   | UNIQUE          |
| def                | oficina           | FK_CLIENTE_CARRO          | oficina      | cliente                   | FOREIGN KEY     |
| def                | oficina           | PRIMARY                   | oficina      | cor                       | PRIMARY KEY     |
| def                | oficina           | COR                       | oficina      | cor                       | UNIQUE          |
| def                | oficina           | PRIMARY                   | oficina      | marca                     | PRIMARY KEY     |
| def                | oficina           | MARCA                     | oficina      | marca                     | UNIQUE          |
| def                | oficina           | PRIMARY                   | oficina      | telefone                  | PRIMARY KEY     |
| def                | oficina           | FK_TELEFONE_CLIENTE       | oficina      | telefone                  | FOREIGN KEY     |
| def                | projeto           | PRIMARY                   | projeto      | cliente                   | PRIMARY KEY     |
| def                | projeto           | PRIMARY                   | projeto      | cursos                    | PRIMARY KEY     |
| def                | projeto           | PRIMARY                   | projeto      | jogador                   | PRIMARY KEY     |
| def                | projeto           | PRIMARY                   | projeto      | pessoa                    | PRIMARY KEY     |
| def                | projeto           | COLUNA4                   | projeto      | pessoa                    | UNIQUE          |
| def                | projeto           | FK_CLIENTE_TELEFONE       | projeto      | telefone                  | FOREIGN KEY     |
| def                | projeto           | PRIMARY                   | projeto      | time                      | PRIMARY KEY     |
| def                | projeto           | time_ibfk_1               | projeto      | time                      | FOREIGN KEY     |
| def                | projeto           | PRIMARY                   | projeto      | times                     | PRIMARY KEY     |
| def                | projeto           | times_ibfk_1              | projeto      | times                     | FOREIGN KEY     |
| def                | projeto           | PRIMARY                   | projeto      | vendedores                | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | actor                     | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | address                   | PRIMARY KEY     |
| def                | sakila            | fk_address_city           | sakila       | address                   | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | category                  | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | city                      | PRIMARY KEY     |
| def                | sakila            | fk_city_country           | sakila       | city                      | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | country                   | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | customer                  | PRIMARY KEY     |
| def                | sakila            | fk_customer_address       | sakila       | customer                  | FOREIGN KEY     |
| def                | sakila            | fk_customer_store         | sakila       | customer                  | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | film                      | PRIMARY KEY     |
| def                | sakila            | fk_film_language          | sakila       | film                      | FOREIGN KEY     |
| def                | sakila            | fk_film_language_original | sakila       | film                      | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | film_actor                | PRIMARY KEY     |
| def                | sakila            | fk_film_actor_actor       | sakila       | film_actor                | FOREIGN KEY     |
| def                | sakila            | fk_film_actor_film        | sakila       | film_actor                | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | film_category             | PRIMARY KEY     |
| def                | sakila            | fk_film_category_category | sakila       | film_category             | FOREIGN KEY     |
| def                | sakila            | fk_film_category_film     | sakila       | film_category             | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | film_text                 | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | inventory                 | PRIMARY KEY     |
| def                | sakila            | fk_inventory_film         | sakila       | inventory                 | FOREIGN KEY     |
| def                | sakila            | fk_inventory_store        | sakila       | inventory                 | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | language                  | PRIMARY KEY     |
| def                | sakila            | PRIMARY                   | sakila       | payment                   | PRIMARY KEY     |
| def                | sakila            | fk_payment_customer       | sakila       | payment                   | FOREIGN KEY     |
| def                | sakila            | fk_payment_rental         | sakila       | payment                   | FOREIGN KEY     |
| def                | sakila            | fk_payment_staff          | sakila       | payment                   | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | rental                    | PRIMARY KEY     |
| def                | sakila            | rental_date               | sakila       | rental                    | UNIQUE          |
| def                | sakila            | fk_rental_customer        | sakila       | rental                    | FOREIGN KEY     |
| def                | sakila            | fk_rental_inventory       | sakila       | rental                    | FOREIGN KEY     |
| def                | sakila            | fk_rental_staff           | sakila       | rental                    | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | staff                     | PRIMARY KEY     |
| def                | sakila            | fk_staff_address          | sakila       | staff                     | FOREIGN KEY     |
| def                | sakila            | fk_staff_store            | sakila       | staff                     | FOREIGN KEY     |
| def                | sakila            | PRIMARY                   | sakila       | store                     | PRIMARY KEY     |
| def                | sakila            | idx_unique_manager        | sakila       | store                     | UNIQUE          |
| def                | sakila            | fk_store_address          | sakila       | store                     | FOREIGN KEY     |
| def                | sakila            | fk_store_staff            | sakila       | store                     | FOREIGN KEY     |
| def                | sys               | PRIMARY                   | sys          | sys_config                | PRIMARY KEY     |
| def                | world             | PRIMARY                   | world        | city                      | PRIMARY KEY     |
| def                | world             | city_ibfk_1               | world        | city                      | FOREIGN KEY     |
| def                | world             | PRIMARY                   | world        | country                   | PRIMARY KEY     |
| def                | world             | PRIMARY                   | world        | countrylanguage           | PRIMARY KEY     |
| def                | world             | countryLanguage_ibfk_1    | world        | countrylanguage           | FOREIGN KEY     |
+--------------------+-------------------+---------------------------+--------------+---------------------------+-----------------+
