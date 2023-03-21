CREATE DATABASE PEDIDO;
GO

USE PEDIDO;
GO

CREATE TABLE Cliente(
	Cod_cliente numeric(5) primary key,
	Nome_cliente varchar(30),
	Endereco varchar(25),
	Cidade varchar(20),
	Cep varchar(10),
	uf varchar(2)
);
GO 

CREATE TABLE Produto(
	Cod_produto int primary key,
	Descricao varchar(20),
	Unidade varchar(2),
	Valor_unitario numeric(6,2)
);
GO

CREATE TABLE Vendedor(
	Cod_vendedor numeric(3) primary key,
	Nome_vendedor varchar(30),
	Faixa_comissao numeric(4,2),
	Salario_fixo numeric(7,2)
);
GO

CREATE TABLE Pedido(
	Num_pedido numeric(3) Primary key identity,
	Prazo_entrega datetime,
	Cod_cliente numeric(5) REFERENCES Cliente(Cod_cliente),
	Cod_vendedor numeric(3) REFERENCES Vendedor(Cod_vendedor)
);
GO

CREATE TABLE Item_Pedido(
	Num_Pedido numeric(3) REFERENCES Pedido(Num_pedido),
	Cod_produto int REFERENCES Produto(Cod_produto),
	Quantidade numeric(5),
	PRIMARY KEY (Num_Pedido, Cod_produto)
);