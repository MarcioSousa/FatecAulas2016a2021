
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO V


ALTER TABLE sis_ct_categoria 
ADD COLUMN ordem	INT2;


--CREATE TABLE sis_ch_feriado
--(
--	id_feriad	SERIAL NOT NULL,
--	dia_data	DATE UNIQUE,
--	tipo_ocor	INTEGER REFERENCES sis_ch_tipoferiado (id_tipfer),
--	coment		CHARACTER VARYING(30),
--	PRIMARY KEY 	(id_feriad)
--);



--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_carga_semanal AS
	SELECT CASE WHEN dia_semana = 'SAB' 
	THEN 'SÁB' 
	ELSE dia_semana END AS diasem, 
	horastrab 
	FROM sis_ch_semanal 
	ORDER BY id_carhor;
ALTER TABLE v_carga_semanal OWNER TO postgres; 


--***************************************************************************************************************************************

-- FUNÇÕES  --


-- Retorna a carga horária do dia (data)
CREATE FUNCTION get_cargahora(date) RETURNS real AS
	'SELECT CASE WHEN (SELECT hora FROM sis_ct_feriado f INNER JOIN sis_ct_tipoferiado t ON t.id_tipfer = f.tipo_ocor WHERE dia_data = $1) IS NULL 
	THEN (SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM $1)
	WHEN 0 THEN ''DOM''
	WHEN 1 THEN ''SEG''
	WHEN 2 THEN ''TER''
	WHEN 3 THEN ''QUA''
	WHEN 4 THEN ''QUI''
	WHEN 5 THEN ''SEX''
	WHEN 6 THEN ''SAB''
	END) 
	ELSE (SELECT hora FROM sis_ct_feriado f 
	INNER JOIN sis_ct_tipoferiado t ON t.id_tipfer = f.tipo_ocor WHERE dia_data = $1)
	END AS cdia'
LANGUAGE 'sql';


-- Retorna a hora centesimal de hora sexagenal
CREATE FUNCTION get_horacent(time) RETURNS double precision AS
	'SELECT EXTRACT(HOUR FROM $1) + EXTRACT(MINUTE FROM $1)/60'
LANGUAGE 'sql';


-- Retorna a hora centesimal de hora sexagenal
CREATE FUNCTION get_horacent2(interval) RETURNS double precision AS
	'SELECT EXTRACT(HOUR FROM $1) + EXTRACT(MINUTE FROM $1)/60'
LANGUAGE 'sql';


-- Retorna a hora sexagenal de hora centesimal no formato hh:mm:ss
CREATE OR REPLACE FUNCTION get_horasexa(double precision) RETURNS interval AS
	'SELECT CAST(TO_CHAR(TRUNC($1),''FM00'')||'':''||TO_CHAR(($1-TRUNC($1))*60,''FM00'')||'':00'' AS interval)'
LANGUAGE 'sql';


-- Retorna a hora sexagenal de hora centesimal, sem minutos e com limite de hora para 9999 - em char 
CREATE OR REPLACE FUNCTION get_horasexa2(double precision) RETURNS varchar(7) AS
	'SELECT TO_CHAR(TRUNC($1),''FM9990'')||'':''||TO_CHAR(ABS(($1-TRUNC($1)))*60,''FM00'')'
LANGUAGE 'sql';


-- Retorna a hora centesimal(real) de hora em string
CREATE FUNCTION get_horacent3(CHAR) RETURNS double precision AS
	'SELECT CASE WHEN $1 IS NULL 
	THEN 0
	ELSE EXTRACT(HOUR FROM CAST($1||'':00'' AS INTERVAL)) + EXTRACT(MINUTE FROM CAST($1||'':00'' AS INTERVAL))/60
	END AS chora'
LANGUAGE 'sql';


--***************************************************************************************************************************************

-- ÍNDICES  --



CREATE UNIQUE INDEX indsis_ct_categoria_id_catego ON sis_ct_categoria USING btree (id_catego);
CREATE        INDEX indsis_ct_categoria_categoria ON sis_ct_categoria USING btree (categoria);

CREATE UNIQUE INDEX indsis_ct_ocupacao_id_ocupac  ON sis_ct_ocupacao  USING btree (id_ocupac);
CREATE UNIQUE INDEX indsis_ct_ocupacao_ocupacao   ON sis_ct_ocupacao  USING btree (ocupacao);
CREATE INDEX        indsis_ct_ocupacao_id_catego  ON sis_ct_ocupacao  USING btree (id_catego);

CREATE UNIQUE INDEX indct_tarefa_id_tarefa        ON ct_tarefa        USING btree (id_tarefa);
CREATE        INDEX indct_tarefa_id_funcio        ON ct_tarefa        USING btree (id_funcio);
CREATE        INDEX indct_tarefa_id_ocupac        ON ct_tarefa        USING btree (id_ocupac);

CREATE UNIQUE INDEX indct_funcionario_id_funcio   ON ct_funcionario   USING btree (id_funcio);
CREATE UNIQUE INDEX indct_funcionario_nome_compl  ON ct_funcionario   USING btree (nome_compl);





