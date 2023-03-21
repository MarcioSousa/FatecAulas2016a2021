/*1*/ 
SELECT  Titulo FROM Livros WHERE Preco = (SELECT MAX(Preco) FROM Livros)
GO

/*2*/
UPDATE Livros SET Preco = (SELECT L.Preco FROM Assuntos A INNER JOIN Livros L ON A.CodAssunto = L.CodAssunto WHERE A.Descricao = 'BANCO DE DADOS')*1.1 WHERE CodAssunto = (SELECT L.CodAssunto FROM Assuntos A INNER JOIN Livros L ON A.CodAssunto = L.CodAssunto WHERE A.Descricao = 'BANCO DE DADOS')
GO

/*3*/
declare
	@nomeAutor varchar(30),
	@qtdLivros int

begin
	select @nomeAutor = 'FERNANDO E. F. SIQUEIRA'
	select @qtdLivros = count(*)
	from AutorLivro al inner join Autores au on al.CodAutor=au.CodAutor
	where al.CodAutor = 
	(
		select CodAutor
		from Autores
		where Autores.NomeAutor=@nomeAutor
	)

	print 'O autor ' + @nomeAutor + ' escreveu ' + cast(@qtdLivros as varchar)
	+ ' livros'
end

/*4*/
SELECT L.Titulo FROM Assuntos A INNER JOIN Livros L ON A.CodAssunto = L.CodAssunto INNER JOIN AutorLivro P ON P.CodLivro = L.CodLivro INNER JOIN Autores C ON C.CodAutor = P.CodAutor WHERE A.Descricao = 'ANALISE DE SISTEMAS' AND C.NomeAutor = 'JOÃO CABRAL DE MELO NETO' AND DataEdicao BETWEEN '01-01-2012' AND '31-12-2012'
GO

/*5*/
create view NOME_DA_VIEW as 
select Autores.NomeAutor from 
Autores inner join AutorLivro on AutorLivro.CodAutor = Autores.CodAutor
where Autores.CodAutor in (select CodAutor from AutorLivro group by CodAutor having COUNT(CodLivro)>2)
Group by Autores.NomeAutor

/*6*/
SELECT S.Descricao FROM Assuntos S LEFT JOIN Livros L ON L.CodAssunto = S.CodAssunto WHERE L.CodAssunto IS NULL
GO

/*7*/
SELECT Titulo, Editora, DataEdicao FROM Livros WHERE Preco < (SELECT AVG(Preco) FROM Livros)
GO

/*8*/
UPDATE Assuntos SET DescontoProm = DescontoProm + 0.15 WHERE CodAssunto IN (SELECT A.CodAssunto FROM Assuntos A INNER JOIN Livros L ON A.CodAssunto = L.CodAssunto WHERE L.Editora = 'MAKRON BOOKS')
GO
