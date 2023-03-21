ALTER PROCEDURE InserirPedido(
	@CodigoCliente int,
	@CodigoVendedor int,
	@CodigoProduto int
)
AS
	IF NOT EXISTS(SELECT Cod_cliente FROM Cliente WHERE Cod_cliente = @CodigoCliente)
	BEGIN
		RAISERROR('CLIENTE NÃO ENCONTRADO!', 10, 1)
		RETURN
	END
	IF NOT EXISTS(SELECT Cod_vendedor FROM Vendedor WHERE Cod_vendedor = @CodigoVendedor)
	BEGIN
		RAISERROR('VENDEDOR NÃO ENCONTRADO!', 10, 1)
		RETURN
	END
	BEGIN TRANSACTION
		INSERT INTO Pedido(Prazo_entrega, Cod_cliente, Cod_vendedor) VALUES(DATEADD(DAY,15,SYSDATETIME()), @CodigoCliente, @CodigoVendedor)
		IF @@ERROR <> 0
		BEGIN
			PRINT('ERRO NA INSERÇÃO!')
			ROLLBACK TRANSACTION
			RETURN
		END
		ELSE
		BEGIN
			IF @CodigoProduto <= 10
			BEGIN
				--INSERT INTO Pedido(Prazo_entrega, Cod_cliente, Cod_vendedor) VALUES(DATEADD(DAY,15,SYSDATETIME()), @CodigoCliente, @CodigoVendedor)
				INSERT INTO Item_Pedido(Num_Pedido, Cod_produto, Quantidade) VALUES(@@IDENTITY, @CodigoProduto, 3)
				COMMIT TRANSACTION
				RETURN
			END
			ELSE
			BEGIN
				IF @CodigoProduto <= 20
				BEGIN
					--INSERT INTO Pedido(Prazo_entrega, Cod_cliente, Cod_vendedor) VALUES(DATEADD(DAY,30,SYSDATETIME()), @CodigoCliente, @CodigoVendedor)
					INSERT INTO Item_Pedido(Num_Pedido, Cod_produto, Quantidade) VALUES(@@IDENTITY, @CodigoProduto, 3)
					COMMIT TRANSACTION
				RETURN
				END
				ELSE
				BEGIN
					PRINT('DIGITE UM CÓDIGO MENOR OU IGUAL A 20!')
					COMMIT TRANSACTION
				RETURN
				END
			END
		END
		