/**]
 * Script do projeto Estoque
 * Author:  Aluno - Marcio Sousa
 * Created: 21/03/2018
 */
 drop database estoque;
 create database estoque;
 use estoque;

create table grupos(
    id int not null auto_increment primary key,
    nome varchar(50) not null,
    dataCriacao datetime not null default current_timestamp,
    situacao boolean not null default true
);

insert into grupos (nome) values ('Limpeza');
insert into grupos (nome) values ('Bebidas');
create table produtos(
    id int not null auto_increment primary key,
    codigobarra char(15) null,
    nome varchar(50) not null,
    preco decimal(10,2) not null,
    validade date null,
    situacao boolean not null default true,
    foto longtext null,
    id_grupo int not null,
    foreign key(id_grupo) references grupos(id)
);

insert into produtos (nome, preco, id_grupo)
values('Vaja Multiuso',7.90,1);
insert into produtos (nome, preco, id_grupo)
values('Detergente Ypê',1.90,2);