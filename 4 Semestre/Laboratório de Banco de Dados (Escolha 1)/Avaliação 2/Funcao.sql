CREATE FUNCTION qtdeLocacoes(
	@codigoCliente int
)
AS
BEGIN
	IF((SELECT COUNT(*) FROM Clientes c INNER JOIN Locacoes l ON c.IdVeiculo = l.IdCliente WHERE c.IdVeiculo = @codigoCliente) > 5)
	BEGIN
		PRINT('Cliente Preferencial.');
	END
	ELSE IF((SELECT COUNT(*) FROM Clientes c INNER JOIN Locacoes l ON c.IdVeiculo = l.IdCliente WHERE c.IdVeiculo = @codigoCliente) > 0)
	BEGIN
		PRINT('Cliente Normal.');
	END
	ELSE
	BEGIN
		PRINT('Cliente Inativo.');
	END
END