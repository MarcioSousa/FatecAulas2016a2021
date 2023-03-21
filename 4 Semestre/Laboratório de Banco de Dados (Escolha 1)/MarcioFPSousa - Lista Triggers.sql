USE LBD_09
/*
1. Escreva uma trigger que, ao inserir um novo cliente, verifique se o 
estado que est� sendo inserido para esse cliente � igual a RJ ou ES. 
Se for, exibir uma mensagem de erro utilizando raiserror e retroceder 
a transa��o. Se n�o for, exibir a mensagem �Estado permitido� e efetivar a transa��o.
*/
CREATE TRIGGER Verifica_UF
ON cliente
FOR INSERT
AS
	IF EXISTS (SELECT UF FROM INSERTED WHERE UF IN ('RJ','ES'))
		BEGIN
			RAISERROR ('Inser��o de registro cancelada', 10, 1)
			ROLLBACK TRANSACTION
		END
		ELSE
		BEGIN
			PRINT('Estado permitido')
			COMMIT TRANSACTION
		END


/*2. Criar a tabela TLogProduto:
CREATE TABLE TLOGPRODUTO
(
USUARIO VARCHAR(30),
DTALTERACAO DATETIME,
NOMEPRODUTO VARCHAR(20)
)
Escreva uma trigger que, ao cadastrar um produto, atualize a tabela TLogProduto com o usu�rio corrente (CURRENT_USER) que est� executando a trans��o,
a data atual do sistema (GETDATE()) e o nome do produto que est� sendo inserido.
Ap�s a inser��o na tabela TLogProduto, verificar o valor de @@ERROR. Se for diferente de zero, exibir uma mensagem de erro utilizando raiserror e
retroceder a transa��o; se for igual a zero, efetivar a transa��o.
*/
CREATE TRIGGER LogProdutos
ON produto
FOR INSERT
AS
INSERT INTO TLOGPRODUTO VALUES (CURRENT_USER, GETDATE(), (SELECT descricao FROM INSERTED))
IF @@ERROR = 0
	BEGIN
		Print('Produto inserido!')
		COMMIT TRANSACTION
	END
ELSE
	BEGIN
		RAISERROR ('Erro na inser��o!', 10, 1)
		ROLLBACK TRANSACTION
	END


/*
3. Escreva um trigger que, ao cadastrar um item pedido, atualize a tabela de produtos a seguinte forma:
Se qtd_Estoque (tab. produto) >= a qtdePedida( tab inserted)
Ent�o atualizar:
qtde estoque (tab. produto) = qtde estoque(tab. produto) - qtde pedida(tab inserted)
Caso contr�rio
� Utilizar raiserror para emitir mensagem: �ESTOQUE INSUFICIENTE�, incluindo tamb�m na mensagem o c�digo do produto que est� em falta.
� Retroceder a transa��o
*/
ALTER TABLE produto
ADD qtd_Estoque INT

--ATUALIZA ESTOQUE
UPDATE produto SET qtd_Estoque = 100 WHERE cod_produto > 0

CREATE TRIGGER Atualiza_Estoque
ON item_pedido
FOR INSERT
AS
	DECLARE @estoque AS INT
	SELECT @estoque = qtd_Estoque FROM produto WHERE cod_produto = (SELECT cod_produto FROM INSERTED)

	DECLARE @codprod AS INT
	SELECT @codprod = cod_produto FROM INSERTED

IF (SELECT quantidade FROM INSERTED) > @estoque
	BEGIN
		RAISERROR('ESTOQUE INSUFICIENTE', 10, 1)
		PRINT('Estoque insuficiente para o produto ' + CONVERT(VARCHAR(10), @codprod))
		ROLLBACK TRANSACTION
	END
ELSE
	BEGIN
		UPDATE produto
		SET qtd_Estoque = @estoque - (SELECT quantidade FROM INSERTED) WHERE cod_produto = (SELECT cod_produto FROM INSERTED)
		COMMIT TRANSACTION
	END

/*
4. Escreva um trigger que, ao ser inclu�do um pedido na tabela 
Pedido verifique se a data de entrega est� programada para domingo ( IF datepart(dw,dataentrega) = 1).
Neste caso alterar a data de entrega para a segunda_feira pr�xima.
*/
CREATE TRIGGER Verifica_Data
ON pedido
FOR INSERT
AS

	IF datepart(dw,(SELECT data_entrega FROM INSERTED)) = 1
		BEGIN
		UPDATE pedido
		SET data_entrega = (data_entrega + 1) WHERE Num_pedido = (SELECT Num_pedido FROM INSERTED)
		END

		INSERT INTO pedido VALUES (0021,'07/05/05','12/06/20',0018,0017);
		DELETE FROM pedido WHERE Num_pedido = 21
		
/*
5 - Escreva um trigger que, ao ser inserido um cliente, verifique se o campo CPF est� nulo. Se estiver emita mensagem de erro utilizando raiserror,
incluindo tamb�m na mensagem o c�digo do cliente, e retroceda a transa��o. Caso contr�rio efetive a transa��o.
*/
CREATE TRIGGER Verifica_CPF
ON cliente
FOR INSERT
AS

DECLARE @codigo as INT
SELECT @codigo = (SELECT Cod_cliente FROM INSERTED)

IF (SELECT CPF_CGC FROM INSERTED) = ''
	BEGIN
		RAISERROR('Informe o CPF!', 10, 1)
		PRINT('Falta informar o CPF do cliente ' + CONVERT(VARCHAR(10), @codigo))
		ROLLBACK TRANSACTION
	END
ELSE
	BEGIN
		COMMIT TRANSACTION
	END

	INSERT INTO cliente VALUES (0021,'Vanderlei Lu�s Silva','Rua Brasil, 75','S�o Paulo',11245788,'SP','123','6549874988');
	DELETE FROM cliente WHERE Cod_cliente = 21


/*
6 - Escreva um trigger que, ao ser inserido um vendedor, verifique se o sal�rio � maior que $400.00.
Se n�o for emitir mensagem de erro utilizando raiserror, incluindo tamb�m na mensagem o c�digo do vendedor e, retroceder a transa��o. 
Caso contr�rio efetive a transa��o.
*/
CREATE TRIGGER Verifica_Salario
ON vendedor
FOR INSERT
AS

DECLARE @codigo as INT
SELECT @codigo = (SELECT cod_vendedor FROM INSERTED)

IF (SELECT salario_fixo FROM INSERTED) <= 400
	BEGIN
		RAISERROR('Salario inv�lido!', 10, 1)
		PRINT('C�digo do vendedor com sal�rio inv�lido: ' + CONVERT(VARCHAR(10), @codigo))
		ROLLBACK TRANSACTION
	END
ELSE
	BEGIN
		COMMIT TRANSACTION
	END

	INSERT INTO vendedor values (0021,'Kevin Costner','B', 500);
	DELETE FROM vendedor where cod_vendedor = 21
