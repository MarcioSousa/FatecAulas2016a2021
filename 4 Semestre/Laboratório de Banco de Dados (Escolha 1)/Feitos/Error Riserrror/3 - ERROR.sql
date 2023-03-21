CREATE PROCEDURE AlteraCodigoRegiaoDepartamento
	@codigoDepartamento INT,
	@NomeRegiao VARCHAR(30)
AS
	BEGIN TRANSACTION
	SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = @NomeRegiao
	IF @@ROWCOUNT > 1
	BEGIN
		PRINT ('ESSA REGI�O EST� DUPLICADA NA TABELA!')
		ROLLBACK TRANSACTION
		RETURN
	END
	ELSE
	BEGIN
		IF NOT EXISTS(SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = @NomeRegiao)
		BEGIN
			PRINT ('NOME DA REGI�O N�O EXISTE NA TABELA!')
			ROLLBACK TRANSACTION
			RETURN
		END
		ELSE
		BEGIN
			INSERT INTO Departamento (Cod_regiao) VALUES ((SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = @NomeRegiao))
			IF @@ERROR <> 0
			BEGIN
				PRINT ('ALGUM ERRO OCORREU')
				ROLLBACK TRANSACTION
				RETURN
			END
			ELSE
			BEGIN
				PRINT ('INSERIDO COM SUCESSO')
				COMMIT TRANSACTION
				RETURN
			END
		END
	END
	
	--BEGIN TRANSACTION
	--	SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = @NomeRegiao
	--	IF @@ROWCOUNT = 0
	--		BEGIN
	--			PRINT('N�O H� REGI�O COM ESSE NOME!')
	--			ROLLBACK TRANSACTION
	--			RETURN
	--		END
	--	ELSE
	--		IF @@ROWCOUNT > 1
	--			BEGIN
	--				PRINT('O NOME DA REGI�O EST� DUPLICADA!')
	--				ROLLBACK TRANSACTION
	--				RETURN
	--			END
	--		ELSE
	--			IF @@ERROR <> 0
	--				BEGIN
	--					PRINT('ALGUM ERRO OCORREU!')
	--					ROLLBACK TRANSACTION
	--					RETURN
	--				END
	--			ELSE
	--				BEGIN
	--					UPDATE Departamento SET Cod_regiao = (SELECT Cod_regiao FROM Regiao WHERE Nome_regiao = @NomeRegiao) WHERE Cod_depto = @codigoDepartamento
	--					COMMIT TRANSACTION
	--					RETURN
	--				END