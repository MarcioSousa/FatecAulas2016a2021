
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XVIII


--***************************************************************************************************************************************

-- VIEWS  --


--***************************************************************************************************************************************

-- FUNÇÕES  --


-- retorna a qtdade de emails para uma determinada pessoa
CREATE FUNCTION get_emails(integer) RETURNS bigint AS
	'SELECT COUNT(id_email) as nEma FROM email WHERE id_pessoa = $1'
LANGUAGE 'sql';


-- retorna a qtdade de fones para uma determinada pessoa
CREATE FUNCTION get_fones(integer) RETURNS bigint AS
	'SELECT COUNT(id_telefone) as nFon FROM telefone WHERE id_pessoa = $1'
LANGUAGE 'sql';


--***************************************************************************************************************************************

-- ÍNDICES  --


