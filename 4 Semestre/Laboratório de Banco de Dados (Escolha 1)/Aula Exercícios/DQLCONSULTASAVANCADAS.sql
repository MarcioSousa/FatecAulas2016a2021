/*========== 04 - CONSULTAS AVANÇADAS =============*/
/*01*/
SELECT V.Cod_vendedor, V.Nome_vendedor FROM PEDIDO P INNER JOIN CLIENTE C ON P.Cod_cliente = C.Cod_cliente
INNER JOIN VENDEDOR V ON V.Cod_vendedor = P.Cod_vendedor WHERE  P.Cod_cliente = 10
GO

/*02*/
SELECT I.Num_pedido, P.Prazo_entrega, I.Quantidade, E.Descricao FROM ITEM_PEDIDO I INNER JOIN PEDIDO P ON I.Num_pedido = P.Num_pedido
INNER JOIN PRODUTO E ON E.Cod_produto = I.Cod_produto WHERE I.Cod_produto = 100
GO

