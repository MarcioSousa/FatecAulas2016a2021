ALTER TABLE Cliente ALTER COLUMN Endereco varchar(30)
GO

ALTER TABLE Item_Pedido ADD Pco_Unit numeric(4,2)
GO

UPDATE Cliente SET Cep = '18035-400' WHERE Cidade = 'Sorocaba'
GO

UPDATE Pedido SET Prazo_entrega = Prazo_entrega + 10 WHERE Cod_cliente = 20
GO

UPDATE Produto SET Valor_unitario = Valor_unitario + (Valor_unitario * 0.1) WHERE Unidade = 'Kg'
GO

--   Este procedimento abaixo (DELETE) não tem como ser finalizado, pois 
--ele está conectado com outra chave de outra tabela, tendo problemas futuros.
--Uma outra forma seria criar um campo para indicar qual produto mostrar, sem deletá-lo
DELETE FROM Produto WHERE Unidade = 'Cx' AND Valor_unitario < 50
GO