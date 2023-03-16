create database MED_PAC

use MED_PAC

create table MEDICO 
(CRM          Int PRIMARY KEY identity, 
RGMedico      Int not null,   
NmMedico      varchar(50) not null,
Idade         int not null,
Especialidade varchar(30) not null, 
NrAmbu        int);

create table Pacientes(
RGPaciente int primary key identity,
NmPaciente varchar(50) not null,
Idade int not null,
Cidade varchar(30) not null,
Doenca varchar(30) not null);

create table Ambulatorio(
NrAmbul int primary key identity,
NrAndar int not null,
Capacidade varchar(20) check(Capacidade > 0 ) not null);

