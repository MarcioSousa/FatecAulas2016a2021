
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO V


ALTER TABLE sis_ct_categoria
ADD CONSTRAINT "sis_ct_categoria_ordem_evitar_repetição" UNIQUE(ordem);


--***************************************************************************************************************************************

-- VIEWS  --


--***************************************************************************************************************************************

-- FUNÇÕES  --


-- Retorna a hora sexagenal de hora centesimal, sem minutos e com limite de hora para 9999 - em char 
CREATE OR REPLACE FUNCTION get_horasexa3(double precision) RETURNS varchar(9) AS
	'SELECT TO_CHAR(TRUNC($1),''FM999990'')||'':''||TO_CHAR(ABS(($1-TRUNC($1)))*60,''FM00'')'
LANGUAGE 'sql';


--***************************************************************************************************************************************

-- ÍNDICES  --


