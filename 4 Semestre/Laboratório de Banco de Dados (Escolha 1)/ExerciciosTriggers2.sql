/*
01 - Escreva uma trigger que, ao inserir um novo cliente, verifique se o estado 
que está sendo inserido para esse cliente é igual a RJ ou ES.
Se for, exibir uma mensagem de erro utilizando raiserror e retroceder a transação.
Se não for, exibir a mensagem ‘Estado permitido’ e efetivar a transação.
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
		raiserror('Não é permitido inserir estado RJ ou ES',10,1)
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
tabela TLogProduto com o usuário corrente (CURRENT_USER) que 
está executando a transção, a data atual do sistema (GETDATE()) e o 
nome do produto que está sendo inserido.
Após a inserção na tabela TLogProduto, verificar o valor de @@ERROR. 
Se for diferente de zero, exibir uma mensagem de erro utilizando 
raiserror e retroceder a transação; se for igual a zero, efetivar a transação.
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
		raiserror('Não é permitido inserir estado RJ ou ES',10,1)
	END
	ELSE
		PRINT('Estado Permitido')
		INSERT INTO cliente VALUES(...,@estado,...)
END