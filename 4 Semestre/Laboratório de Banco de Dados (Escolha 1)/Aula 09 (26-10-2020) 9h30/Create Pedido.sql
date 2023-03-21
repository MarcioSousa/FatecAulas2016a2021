create table cliente (
Cod_cliente int 
CONSTRAINT PK_CODCLIENTE Primary Key,
Nome_cliente varchar(50) not null,
Endereco varchar (50),
Cidade varchar(20),
Cep char(8),
UF char(2),
CPF_CGC char(14),
IE char(12))


create table vendedor (
cod_vendedor int,
nome_vendedor varchar (50) not null,
faixa_comissao char(1),
salario_fixo money,
CONSTRAINT PK_VENDEDOR PRIMARY KEY (COD_VENDEDOR))

create table pedido (
Num_pedido int,
data_compra datetime,
data_entrega datetime,
cod_cliente int not null,
cod_vendedor int not null ,
 FOREIGN KEY (COD_CLIENTE) REFERENCES CLIENTE (COD_CLIENTE),

CONSTRAINT FK_VENDEDOR FOREIGN KEY(COD_VENDEDOR) REFERENCES VENDEDOR,

CONSTRAINT PK_PEDIDO PRIMARY KEY (NUM_PEDIDO)
)

create table produto (
cod_produto int
CONSTRAINT PK_CODPRODUTO Primary Key,
descricao varchar(20),
Unidade char(2),
Valor_unitario money)


create table item_pedido (
num_pedido int references pedido,
cod_produto int references produto,
quantidade int
CONSTRAINT PK_PEDIDOPRODUTO primary key (num_pedido, cod_produto) )


