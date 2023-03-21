-- AULAS DE SQL - MODELO CLIENTE-PEDIDO-PRODUTO
-----------------------------------------------
---------- REALIZANDO CONSULTAS ---------------
-----------------------------------------------
-- 01 -------------------------------------------
SELECT Num_pedido, Prazo_entrega FROM Pedido
GO
-- 02 -------------------------------------------
SELECT Descricao, Valor_unitario FROM Produto
GO
-- 03 -------------------------------------------
SELECT Nome_cliente, Endereco FROM Cliente
GO
-- 04 -------------------------------------------
SELECT Nome_vendedor FROM Vendedor
GO
-- 05 -------------------------------------------
SELECT * FROM Cliente
GO
-- 06 -------------------------------------------
SELECT * FROM Produto
GO
-- 07 -------------------------------------------
SELECT Nome_vendedor AS 'nome' FROM Vendedor
GO
-- 08 -------------------------------------------
SELECT Valor_unitario,  Valor_unitario + (Valor_unitario * 0.1) AS ' + 10%' FROM Produto
GO
-- 09 -------------------------------------------
SELECT Salario_fixo, Salario_fixo +(Salario_fixo * 0.05) FROM Vendedor
GO
-- 10 -------------------------------------------
SELECT Nome_cliente FROM Cliente
WHERE Cidade = 'Sorocaba'
GO
-- 11 -------------------------------------------
SELECT * FROM Vendedor
WHERE Salario_fixo < 400
GO
-- 12 -------------------------------------------
SELECT Cod_produto, Descricao FROM Produto
WHERE Unidade = 'Kg'
GO
-- 13 -------------------------------------------
SELECT Num_pedido, Prazo_entrega FROM Pedido
WHERE Prazo_entrega BETWEEN '01-05-1998' AND '01-06-1998'
GO
-- 14 -------------------------------------------
SELECT Num_pedido, Prazo_entrega FROM Pedido
WHERE YEAR(Prazo_entrega) = 2004
GO
-- 15 -------------------------------------------
SELECT * FROM Produto
WHERE Valor_unitario BETWEEN 101 AND 199
GO
-- 16 -------------------------------------------
SELECT * FROM Item_Pedido
WHERE Quantidade BETWEEN 1001 AND 1499
GO
-- 17 -------------------------------------------
SELECT Nome_vendedor FROM Vendedor
WHERE Nome_vendedor LIKE 'José%'
GO
-- 18 -------------------------------------------
SELECT Nome_cliente FROM Cliente 
WHERE Nome_cliente LIKE '%Silva'
GO
-- 19 -------------------------------------------
SELECT Descricao, Cod_produto FROM Produto
WHERE Descricao LIKE '%ac%'
GO
-- 20 -------------------------------------------
SELECT Nome_cliente FROM Cliente
WHERE Endereco like ''
GO
-- 21 -------------------------------------------
SELECT DISTINCT Cidade FROM Cliente
GO
-- 22 -------------------------------------------
SELECT * FROM Cliente
ORDER BY Nome_cliente
GO
-- 23 -------------------------------------------
SELECT * FROM Cliente
ORDER BY Cidade DESC
GO
-- 24 -------------------------------------------
SELECT * FROM Cliente
ORDER BY Cidade, Nome_cliente
GO
-- 25 -------------------------------------------
SELECT * FROM Produto
WHERE Unidade = 'Kg'
ORDER BY Descricao
GO

-------------------------------------------------
--------- CONSULTAS USANDO FUNÇÕES --------------
-------------------------------------------------
-- 01 -------------------------------------------
SELECT MAX(Quantidade) FROM Item_Pedido
GO
-- 02 -------------------------------------------
SELECT MIN(Valor_unitario) FROM Produto
GO
-- 03 -------------------------------------------
SELECT SUM(Salario_fixo) FROM Vendedor
GO
-- 04 -------------------------------------------
SELECT COUNT(Unidade) FROM Produto
WHERE Unidade = 'Lt'
GO
-- 05 -------------------------------------------
SELECT COUNT(*) AS 'Qtde', Cidade FROM Cliente
GROUP BY Cidade
GO
-- 06 -------------------------------------------
SELECT COUNT(Cod_vendedor) AS 'QTDE' FROM Pedido
GROUP BY Cod_vendedor
GO
-- 07 -------------------------------------------
SELECT MAX(Valor_unitario) AS 'Maior Valor', MIN(Valor_unitario) AS 'Menor Valor' FROM Produto
-- 08 -------------------------------------------
--Listar o numero de clientes, agrupados por cidade para todas as cidades que aparecem mais de 4 vezes 
--na tabela de clientes
SELECT COUNT(*) AS 'QtdeClientes' FROM Cliente
WHERE Cidade > 1
GROUP BY Cidade
GO
--??????????????????????????????????





