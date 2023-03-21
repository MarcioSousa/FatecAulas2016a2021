/*Marcio Francisco Pereira de Sousa*/
CREATE TRIGGER INSERIRALTERAR
    ON Livros
    AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    SET NOCOUNT ON;

    IF NOT EXISTS(SELECT * FROM DELETED)
		-- INSERIR
		INSERT INTO TABMSG1 (Datalog, Mensagem)  
		SELECT TOP 1 GETDATE() as INSERIRALTERAR, ('Codigo: ' + cast(l.CodLivro as varchar) + '- Titulo: ' + l.Titulo + '- Assunto ' + a.Descricao)  as Mensagem
		FROM Livros l INNER JOIN Assuntos a on l.CodAssunto = a .CodAssunto ORDER BY CodLivro DESC 
	ELSE
		-- ALTERAR
		INSERT INTO TABMSG1 (Datalog, Mensagem)  
		SELECT TOP 1 GETDATE() as INSERIRALTERAR, 
		('Titulo: ' + l.Titulo + '- Assunto ' + a.Descricao + '- Preço Antigo: ' + cast(d.Preco as varchar) + '- Preço novo: ' + cast(l.Preco as varchar))  as Mensagem
		FROM Livros l INNER JOIN Assuntos a on l.CodAssunto = a .CodAssunto INNER JOIN deleted D on d.CodLivro = l.CodLivro ORDER BY l.CodLivro DESC 
END;