/*
01 - Escreva uma trigger que, ao inserir um novo cliente, verifique se o estado 
que est� sendo inserido para esse cliente � igual a RJ ou ES.
Se for, exibir uma mensagem de erro utilizando raiserror e retroceder a transa��o.
Se n�o for, exibir a mensagem �Estado permitido� e efetivar a transa��o.
*/

CREATE TRIGGER VerificarInsercao
ON cliente
FOR insert
AS
BEGIN
	declare @estado varchar
	set @estado = cliente.estado

	if @estado = 'RJ' OR @estado = 'ES'
	BEGIN
		raiserror('N�o � permitido inserir estado RJ ou ES',10,1)
	END
	ELSE
		PRINT('Estado Permitido')
		INSERT INTO cliente VALUES(...,@estado,...)
END

/*
02 - Criar a tabela TLogProduto:
CREATE TABLE TLOGPRODUTO
(
USUARIO VARCHAR(30),
DTALTERACAO DATETIME,
NOMEPRODUTO VARCHAR(20)
)
Escreva uma trigger que, ao cadastrar um produto, atualize a 
tabela TLogProduto com o usu�rio corrente (CURRENT_USER) que 
est� executando a trans��o, a data atual do sistema (GETDATE()) e o 
nome do produto que est� sendo inserido.
Ap�s a inser��o na tabela TLogProduto, verificar o valor de @@ERROR. 
Se for diferente de zero, exibir uma mensagem de erro utilizando 
raiserror e retroceder a transa��o; se for igual a zero, efetivar a transa��o.
*/
CREATE TRIGGER AtualizaTabela
ON TLOGPRODUTO
FOR insert
AS
BEGIN
	declare @estado varchar
	set @estado = cliente.estado

	if @estado = 'RJ' OR @estado = 'ES'
	BEGIN
		raiserror('N�o � permitido inserir estado RJ ou ES',10,1)
	END
	ELSE
		PRINT('Estado Permitido')
		INSERT INTO cliente VALUES(...,@estado,...)
END