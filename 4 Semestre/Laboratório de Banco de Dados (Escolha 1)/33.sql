CREATE PROCEDURE Altera_Autor
@COD_AUTOR INT
AS
IF NOT EXISTS (SELECT * FROM Autores WHERE CodAutor=@COD_AUTOR)
	BEGIN
		PRINT ('AUTOR INVÁLIDO')
		RETURN
	END
	ELSE
		SELECT A.CodAutor as Codautor, A.NomeAutor as Nome, Titulo from Autores AS A 
		JOIN AutorLivro as L ON A.CodAutor = L.CodAutor
		JOIN Livros as Li ON L.CodLivro = Li.CodLivro where A.CodAutor = @COD_AUTOR

		UPDATE Livros set Preco = Preco * 1.1
		FROM Livros as L
		JOIN AutorLivro as al ON L.CodLivro = al.CodLivro
		JOIN Autores as A on al.CodAutor = A.CodAutor
		where A.CodAutor = @COD_AUTOR

		SELECT A.CodAutor as Codautor, A.NomeAutor as Nome, preco as Preco_Atualizado, Titulo from Autores AS A 
		JOIN AutorLivro as L ON A.CodAutor = L.CodAutor
		JOIN Livros as Li ON L.CodLivro = Li.CodLivro where A.CodAutor = @COD_AUTOR