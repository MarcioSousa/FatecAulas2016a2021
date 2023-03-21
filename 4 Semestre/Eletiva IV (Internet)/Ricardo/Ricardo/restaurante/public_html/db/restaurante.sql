/**
 * Author:  Marcio Sousa
 * Created: 05/04/2018
 */

drop database restaurante;
create database restaurante;
use restaurante;

create table produto(
    codigo int not null auto_increment primary key,
    nome varchar(30) not null,
    fabricacao varchar(30) not null,
    valor decimal(10,2) not null
);

create table movimento (
    codigo int not null auto_increment primary key,
    cod_produto int not null,
    dataVencimento datetime null,
    dataEntrada datetime null,
    dataSaida datetime null,
    valorTotal decimal(10,2) null,
    qtde int not null
);

ALTER TABLE movimento ADD CONSTRAINT fk_produtoMovimento FOREIGN KEY(cod_produto) REFERENCES produto(codigo);

create table servico(
    codigo int not null auto_increment primary key,
    nome varchar(30) not null,
    valor decimal(10,2) not null
);

create table pedido(
    codigo int not null auto_increment primary key,
    livre boolean not null,
    valorPago decimal(10,2) not null,
    numeroMesa int not null
);

create table pedido_servico(
    cod_pedido int not null,
    cod_servico int not null,
    qtde int not null
);

ALTER TABLE pedido_servico ADD CONSTRAINT fk_pedidoS FOREIGN KEY(cod_pedido) REFERENCES pedido(codigo);
ALTER TABLE pedido_servico ADD CONSTRAINT fk_pedidoServico FOREIGN KEY(cod_servico) REFERENCES servico(codigo);

create table pedido_produto(
    cod_pedido int not null,
    cod_produto int not null,
    qtde int not null
);

ALTER TABLE pedido_produto ADD CONSTRAINT fk_pedidoP FOREIGN KEY(cod_pedido) REFERENCES pedido(codigo);
ALTER TABLE pedido_produto ADD CONSTRAINT fk_pedidoProduto FOREIGN KEY(cod_produto) REFERENCES produto(codigo);

create table caixa(
    codigo int not null auto_increment primary key,
    cod_pedido int not null,
    valorPago decimal(10,2) not null,
    tipoPag varchar(15) not null,
    troco decimal(10,2) not null,
    datapagam datetime not null
);

ALTER TABLE caixa ADD CONSTRAINT fk_pedidoCaixa FOREIGN KEY(cod_pedido) REFERENCES pedido(codigo);

----------------------------------------------------
insert into produto (nome, fabricacao, valor) values ('Coca Cola 2 litros','Industria de Bebidas', 8.00);
insert into produto (nome, fabricacao, valor) values ('Coca Cola lata','Industria de Bebidas', 4.50);
insert into produto (nome, fabricacao, valor) values ('Fanta Lata','Industria de Bebidas', 4.60);
insert into produto (nome, fabricacao, valor) values ('Suco de Morango','Pizzaria Rei', 6.80);
insert into produto (nome, fabricacao, valor) values ('Suco de Laranja','Pizzaria Rei', 5.00);

insert into movimento (cod_produto, dataVencimento, dataEntrada, dataSaida, valorTotal, qtde) values ('2','2018/12/10','2018/03/15', NULL, 120.00, 10);
insert into movimento (cod_produto, dataVencimento, dataEntrada, dataSaida, valorTotal, qtde) values ('3','2018/09/10','2018/04/15', NULL, 80.00, 9);
insert into movimento (cod_produto, dataVencimento, dataEntrada, dataSaida, valorTotal, qtde) values ('2', NULL, NULL, '2018/05/16', NULL, 8);
insert into movimento (cod_produto, dataVencimento, dataEntrada, dataSaida, valorTotal, qtde) values ('5','2018/07/08','2018/05/05', NULL, 78.00, 15);
insert into movimento (cod_produto, dataVencimento, dataEntrada, dataSaida, valorTotal, qtde) values ('5', NULL, NULL, '2018/06/16', NULL, 10);

insert into servico (nome, valor) values ('Pizza de Calabresa', 21.00);
insert into servico (nome, valor) values ('Pizza de Mussarela', 20.50);
insert into servico (nome, valor) values ('Pizza Parmegiana', 22.30);
insert into servico (nome, valor) values ('Pizza Doce', 18.00);
insert into servico (nome, valor) values ('Pizza Americana', 26.50);

insert into pedido (livre, valorPago, numeroMesa) values (true, 60.00, 2);
insert into pedido (livre, valorPago, numeroMesa) values (true, 52.30, 10);
insert into pedido (livre, valorPago, numeroMesa) values (true, 31.20, 5);
insert into pedido (livre, valorPago, numeroMesa) values (true, 44.50, 7);
insert into pedido (livre, valorPago, numeroMesa) values (true, 19.20, 14);

insert into pedido_produto (cod_pedido, cod_produto, qtde) values (1, 2, 3);
insert into pedido_produto (cod_pedido, cod_produto, qtde) values (1, 1, 1);
insert into pedido_produto (cod_pedido, cod_produto, qtde) values (2, 4, 2);
insert into pedido_produto (cod_pedido, cod_produto, qtde) values (3, 5, 1);
insert into pedido_produto (cod_pedido, cod_produto, qtde) values (4, 4, 1);


insert into pedido_servico (cod_pedido, cod_servico, qtde) values (1, 3, 1);
insert into pedido_servico (cod_pedido, cod_servico, qtde) values (3, 4, 2);
insert into pedido_servico (cod_pedido, cod_servico, qtde) values (2, 1, 3);
insert into pedido_servico (cod_pedido, cod_servico, qtde) values (4, 2, 2);
insert into pedido_servico (cod_pedido, cod_servico, qtde) values (5, 3, 1);

insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (3, 19.30, 'crédito', 2.00, '2018/03/19');
insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (5, 28.30, 'débito', 9.00, '2018/03/20');
insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (4, 33.60, 'dinheiro', 1.00, '2018/03/18');
insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (2, 17.30, 'dinheiro', 0.60, '2018/03/17');
insert into caixa (cod_pedido, valorPago, tipoPag, troco, datapagam) values (1, 49.90, 'débito', 0.90, '2018/04/19');