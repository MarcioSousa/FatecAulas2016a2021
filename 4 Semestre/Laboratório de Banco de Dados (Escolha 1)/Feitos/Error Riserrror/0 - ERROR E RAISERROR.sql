CREATE DATABASE ExCidade

USE ExCidade

CREATE TABLE Regiao (
Cod_regiao INT IDENTITY PRIMARY KEY,
Nome_regiao VARCHAR(15)
)
 
CREATE TABLE Departamento(
Cod_depto INT IDENTITY PRIMARY KEY,
Nome_depto VARCHAR(30),
Cod_regiao INT 
)

ALTER TABLE Departamento ADD CONSTRAINT fk_regiao
FOREIGN KEY(Cod_regiao) REFERENCES Regiao(Cod_regiao);
GO

----RAISERROR-----
ALTER TABLE Produto ADD Qtde_Estoque int
ALTER TABLE Vendedor ADD Porc_Comissao decimal