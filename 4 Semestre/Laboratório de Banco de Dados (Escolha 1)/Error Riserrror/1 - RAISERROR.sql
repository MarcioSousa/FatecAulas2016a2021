ALTER PROCEDURE calcularTotalVendas(
	@CodigoVendedor int
)
AS
	IF NOT EXISTS(SELECT Cod_vendedor FROM vendedor WHERE Cod_vendedor = @CodigoVendedor)
		BEGIN
			RAISERROR('VENDEDOR NÃO ENCONTRADO!', 10, 1)
			RETURN 
		END
	ELSE
		IF NOT EXISTS(SELECT Cod_vendedor FROM Pedido WHERE Cod_vendedor = @CodigoVendedor)
			BEGIN
				RAISERROR('O VENDEDOR NÃO TEM PEDIDOS!', 10, 1)
				RETURN
			END
		ELSE
			IF (SELECT SUM(Salario_fixo) FROM Vendedor) < 100000
				BEGIN
					UPDATE Vendedor SET Porc_Comissao = 10 WHERE Cod_vendedor = @CodigoVendedor
					SELECT * FROM Vendedor
					RETURN
				END
			ELSE
				IF (SELECT SUM(Salario_fixo) FROM Vendedor) <= 1000000
					BEGIN
						UPDATE Vendedor SET Porc_Comissao = 15 WHERE Cod_vendedor = @CodigoVendedor
						SELECT * FROM Vendedor
						RETURN
					END
				ELSE
					BEGIN
						UPDATE Vendedor SET Porc_Comissao = 20 WHERE Cod_vendedor = @CodigoVendedor
						SELECT * FROM Vendedor
						RETURN
					END