ALTER PROCEDURE InserirItemPedido(
	@CodigoPedido int,
	@CodigoProduto int,
	@Quantidade int
)
AS
	IF NOT EXISTS(SELECT Num_pedido FROM Pedido WHERE Num_pedido = @CodigoPedido)
	BEGIN
		RAISERROR('PEDIDO NÃO ENCONTRADO!', 10, 1)
		RETURN
	END
	ELSE
	BEGIN
		IF NOT EXISTS(SELECT Cod_produto FROM Produto WHERE Cod_produto = @CodigoProduto)
		BEGIN
			RAISERROR('PRODUTO NÃO ENCONTRADO!', 10, 1)
			RETURN
		END
		ELSE
		BEGIN
			IF(@Quantidade <=0)
			BEGIN
				RAISERROR('DIGITE UMA QUANTIDADE MAIOR DO QUE ZERO!', 10, 1)
				RETURN
			END
			ELSE
			BEGIN
				IF ((SELECT Qtde_Estoque FROM Produto WHERE Cod_produto = @CodigoProduto) < @Quantidade)
				BEGIN
					RAISERROR('QUANTIDADE DE PRODUTO INSUFICIENTE NO ESTOQUE!', 10, 1)
					RETURN
				END
				ELSE
				BEGIN
					IF NOT EXISTS(SELECT Num_Pedido FROM Item_Pedido WHERE Num_Pedido = @CodigoPedido AND Cod_produto = @CodigoProduto)
					BEGIN
						INSERT INTO Item_Pedido(Num_Pedido, Cod_produto, Quantidade) VALUES (@CodigoPedido, @CodigoProduto, @Quantidade)
						UPDATE Produto SET Qtde_Estoque = Qtde_Estoque - @Quantidade WHERE Cod_produto = @CodigoProduto
						PRINT ('NOVO ITEM DE PEDIDO INSERIDO COM SUCESSO!')
						RETURN
					END
					ELSE
					BEGIN
						UPDATE Produto SET Qtde_Estoque = (SELECT Quantidade FROM Item_Pedido WHERE Cod_produto = @CodigoProduto AND Num_Pedido = @CodigoPedido + (SELECT Qtde_Estoque FROM Produto WHERE Cod_produto = @CodigoProduto) - (@Quantidade)) WHERE Cod_produto = @CodigoProduto
						UPDATE Item_Pedido SET Quantidade = @Quantidade WHERE Cod_produto = @CodigoProduto AND Num_Pedido = @CodigoPedido
						PRINT ('ITEM DE PEDIDO ATUALIZADO COM SUCESSO!')
						RETURN
					END
				END
			END
		END
	END