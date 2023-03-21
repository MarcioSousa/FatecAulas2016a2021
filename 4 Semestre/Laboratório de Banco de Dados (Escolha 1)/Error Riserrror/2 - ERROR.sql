CREATE PROCEDURE NovoDepartamento 
	@NomeDepar VARCHAR(30)
AS
BEGIN TRANSACTION
	INSERT INTO Departamento(Nome_depto) VALUES(@NomeDepar)
	IF @@ERROR <> 0
		BEGIN
			PRINT('erro')
			ROLLBACK TRANSACTION
			RETURN
		END
		ELSE
		BEGIN
			PRINT('Registrado')
			COMMIT TRANSACTION
			RETURN
		END