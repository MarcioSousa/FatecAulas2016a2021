/*Marcio Francisco Pereira de Sousa*/
CREATE PROCEDURE FazerCalculo @codigo INT
AS
BEGIN
IF EXISTS (SELECT * FROM Autores WHERE CodAutor = @codigo)
	BEGIN
	
	DECLARE @codLivros AS INT
	SELECT @codLivros = Livros.CodLivro FROM Livros, Autores, AutorLivro WHERE YEAR(DataEdicao) < 2010 AND Autores.CodAutor = @codigo AND AutorLivro.CodAutor = Autores.CodAutor AND AutorLivro.CodLivro = Livros.CodLivro

	SELECT Autores.CodAutor, Autores.NomeAutor, Livros.Titulo, Livros.Preco
	FROM Autores, Livros, AutorLivro
	WHERE Autores.CodAutor = @codigo AND AutorLivro.CodAutor = Autores.CodAutor AND AutorLivro.CodLivro = Livros.CodLivro

	UPDATE Livros
	SET Preco = Preco*1.1
	WHERE CodLivro = @codLivros

	SELECT Autores.CodAutor, Autores.NomeAutor, Livros.Titulo, Livros.Preco
	FROM Autores, Livros, AutorLivro
	WHERE Autores.CodAutor = @codigo AND AutorLivro.CodAutor = Autores.CodAutor AND AutorLivro.CodLivro = Livros.CodLivro

	END
	ELSE
	BEGIN
		PRINT('Autor inválido')
	END
END