CREATE procedure InserirItemPedido (
    @numPedido int,
    @codProduto int,
    @qtde int
)
as
BEGIN
	DECLARE @codigoCliente int
	SET @codigoCliente = (SELECT Valor_unitario FROM Produto WHERE Cod_produto = @codProduto)
	
	INSERT INTO Item_Pedido(Num_Pedido,Cod_produto,Quantidade) VALUES (
		@numPedido, @codProduto,@qtde
	)
	
	return;
END