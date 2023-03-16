Create database BD_FUNC

use BD_FUNC

create table Cargos
	    (CdCargo char(05) PRIMARY KEY,
		NmCargo varchar(50) NOT NULL,
		VrSalario Numeric(6,2) CHECK(VrSalario > 0) );

create table Deptos
	   (CdDepto char(03) PRIMARY KEY,
		NmDepto varchar(50) NOT NULL,
		Ramal Numeric(6) );


create table Funcionarios
	(NrMatric int PRIMARY KEY IDENTITY,
		NmFunc varchar(50) NOT NULL,
		Sobrenome varchar(100) NOT NULL,
		Sexo Char(01) check (Sexo IN ('F', 'M')),
		DtAdm Datetime,
		CdDepto Char(03) NOT NULL References Deptos,
		CodCargo Char(05) References Cargos,
		UNIQUE (NmFunc, Sobrenome));

Alter table Funcionarios ADD Telefone varchar(20) NULL  --Adicionar coluna telefone--
Alter table Funcionarios ALTER COLUMN Telefone varchar(25) NULL  --Alterar coluna telefone--
Alter table Funcionarios DROP COLUMN Telefone;  --excluir coluna telefone--



select * from Deptos   

Insert into Deptos values ('D01','ADMINISTRATIVO',100);
Insert into Deptos values ('D02','COMERCIAL',120);
Insert into Deptos values ('D03','INFORMATICA',130);

SELECT * FROM DEPTOS;

insert into Cargos values ('C10','GERENTE',8500);
insert into Cargos values ('C11','DIRETOR DE VENDAS',7000);
insert into Cargos values ('C12','ANALISTA DE SISTEMAS',5250);

select * from Cargos;


INSERT INTO Funcionarios values ('JOAO','NOGUEIRA','M','05-12-2001','D03','C12');
INSERT INTO Funcionarios VALUES ('JOAO','SAMPAIO','M','02-10-2003','D01','C10');
INSERT INTO Funcionarios values ('MARIA','SOARES','F','13-02-2000','D02','C11');
INSERT INTO Funcionarios VALUES('ROBERTO','PEREIRA','M','22-05-2009','D01','C10');
INSERT INTO Funcionarios VALUES('RUTE','SOUZA','F','30-04-1999','D01','C10');
INSERT INTO Funcionarios VALUES('REGINA','SIMOES','F','01-12-2007','D03','C12');
INSERT INTO Funcionarios VALUES('ALVARO','SAMPAIO','M','13-11-1998','D03','C12');



UPDATE CARGOS SET
 VrSalario =VrSalario * 1.10
 where CdCargo = 'C10';

 UPDATE Funcionarios set
 CodCargo = 'C1',CdDepto = 'D10'
 where NrMatric=1;

 --DELETE FROM Funcionario

 select * from Funcionarios
