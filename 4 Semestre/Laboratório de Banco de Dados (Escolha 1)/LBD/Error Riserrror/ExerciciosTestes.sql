--EXEC NovaRegiao 'Itu'
--EXEC NovaRegiao 'Sorocaba'
--EXEC NovaRegiao 'Campinas'
--EXEC NovaRegiao 'Indaiatuba'
--EXEC NovaRegiao 'Jundiaí'
--EXEC NovaRegiao 'Piracicaba'
--EXEC NovaRegiao 'São Paulo'
--EXEC NovaRegiao 'Salto'
--EXEC NovaRegiao 'Cabreuva'
--EXEC NovaRegiao 'Campo Limpo'
--EXEC NovaRegiao 'Araçoiaba'

EXEC AlteraCodigoRegiaoDepartamento 1, 'Itu'

EXEC AlteraCodigoRegiaoDepartamento 1, 'Sorocaba'

SELECT * FROM Regiao
SELECT * FROM Departamento


--EXEC NovoDepartamento 'Cozinha'
--EXEC NovoDepartamento 'Balcao'
--SELECT * FROM Item_Pedido
--SELECT * FROM Pedido
--SELECT * FROM Produto

--EXEC InserirItemPedido 22, 1, 3
--SELECT * FROM Produto
--UPDATE Produto SET Qtde_Estoque = Qtde_Estoque - 2 WHERE Cod_produto = 1

--SELECT SUM(Quantidade) as 'SOMA' FROM Item_Pedido WHERE Cod_produto = 3
----SELECT * FROM Regiao
----SELECT * FROM Departamento
----UPDATE Departamento SET Cod_regiao = NULL
----EXEC AlteraCodigoRegiaodoDepartamento 3, 'Itu'
----EXEC AlteraCodigoRegiaodoDepartamento 3, 'Itu'

----UPDATE Departamento SET Cod_regiao = NULL WHERE Cod_depto = 2

----SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = 'rsrs'

----UPDATE Departamento SET Cod_regiao = (SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = 'Sorocaba') WHERE Cod_depto = 4
----UPDATE Departamento SET Cod_regiao = (SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = 'rsrsrs') WHERE Cod_depto = 7
----UPDATE Departamento SET Cod_regiao = (SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = 'Itu') WHERE Cod_depto = 3

----UPDATE Departamento SET Cod_regiao = 3 WHERE Cod_depto = 2

----SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = 'Sorocaba'

--SELECT * FROM Cliente
--SELECT * FROM Pedido
--SELECT * FROM Item_Pedido
--SELECT * FROM Vendedor
--SELECT * FROM Produto


























----SELECT Cod_cliente FROM Cliente WHERE Cod_cliente = 1
----SELECT Cod_vendedor FROM Vendedor WHERE Cod_vendedor = 1

----EXEC InserirPedido 1, 3, 3




----SELECT * FROM Pedido
----SELECT * FROM Item_Pedido
----SELECT * FROM Produto
----SELECT * FROM Cliente


----INSERT INTO Pedido(Prazo_entrega, Cod_cliente, Cod_vendedor) VALUES(DATEADD(DAY,15,SYSDATETIME()), 2, 4)




----DELETE FROM Pedido
----DELETE FROM Item_Pedido


----SELECT * FROM Cliente C 
----INNER JOIN Pedido P ON C.Cod_cliente = P.Cod_cliente
----INNER JOIN Vendedor V ON V.Cod_vendedor = P.Cod_vendedor
----INNER JOIN Item_Pedido I ON I.Num_Pedido = P.Num_pedido

----SELECT * FROM Pedido P INNER JOIN Item_Pedido I ON P.Num_pedido = I.Num_Pedido

----DELETE FROM Regiao
----DELETE FROM Departamento


----USE AdventureWorks2012;  
----GO  
----UPDATE HumanResources.Employee   
----SET JobTitle = N'Executive'  
--WHERE NationalIDNumber = 123456789  
--IF @@ROWCOUNT = 0  
--PRINT 'Warning: No rows were updated';  
--GO  

--EXEC calcularTotalVendas 5

--SELECT * FROM Vendedor

--SELECT * FROM Pedido

--SELECT SUM(Salario_fixo) FROM Vendedor


--UPDATE Vendedor SET Porc_Comissao = 10 WHERE Cod_vendedor = 1

--UPDATE Vendedor SET Salario_fixo = Salario_fixo / 100

----TABELA CLIENTE PEDIDO PRODUTO (PEDIDO)
--ALTER TABLE Produto ADD Qtde_Estoque int
--ALTER TABLE Vendedor ADD Porc_Comissao decimal