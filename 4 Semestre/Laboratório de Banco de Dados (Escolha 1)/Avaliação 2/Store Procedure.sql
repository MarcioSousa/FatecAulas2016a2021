CREATE PROCEDURE manutencaoPreventiva(
	@codigoVeiculo int
)
AS
BEGIN
	IF EXISTS(SELECT COUNT(*) FROM Veiculos v INNER JOIN Locacoes l ON v.IdVeiculo = l.IdVeiculo WHERE l.IdVeiculo = @codigoVeiculo AND MONTH(l.DataLoc) = 11 AND YEAR(l.DataLoc) = 2017)
	BEGIN
		IF((SELECT COUNT(*) FROM Veiculos v INNER JOIN Locacoes l ON v.IdVeiculo = l.IdVeiculo WHERE l.IdVeiculo = @codigoVeiculo AND MONTH(l.DataLoc) = 11 AND YEAR(l.DataLoc) = 2017) > 3) 
		BEGIN
			PRINT('Veículo deverá passar por manutenção preventiva.');
		END
	END
	IF NOT EXISTS(SELECT COUNT(*) FROM Veiculos v INNER JOIN Locacoes l ON v.IdVeiculo = l.IdVeiculo WHERE l.IdVeiculo = @codigoVeiculo AND MONTH(l.DataLoc) = 11 AND YEAR(l.DataLoc) = 2017)
	BEGIN
		PRINT('Veículo está ok!');
	END
	ELSE
	BEGIN
		RAISERROR('Veículo não existe ou houve um erro ao fazer a análise.',10,1)
	END
END