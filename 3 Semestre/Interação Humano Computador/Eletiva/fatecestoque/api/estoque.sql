drop database estoque;

create database estoque;
use estoque;

create table grupos(
id int not null auto_increment primary key,
nome varchar(50) not null);

insert into grupos (nome) values ('Limpeza');
insert into grupos (nome) values ('Bebidas');

select * from grupos;

create table produtos(
id int not null auto_increment primary key,
codigobarra char(15) null,
nome varchar(50) not null,
preco decimal(10,2) not null,
validade date null,
status boolean not null default true,
id_grupo int not null,
         foreign key(id_grupo) references grupos(id)
);
/* inserindo registros */
insert into produtos (nome, preco, id_grupo) values
('Detergente Neutro',1.29,1);





















