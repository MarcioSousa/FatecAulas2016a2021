
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO III


ALTER TABLE sis_parametro
ADD COLUMN ind_salar	REAL,
ADD COLUMN horas_mes	REAL;


CREATE TABLE sis_ch_semanal
(
	id_carhor	SERIAL NOT NULL,
	dia_semana	CHARACTER VARYING(3),
	horastrab	REAL,
	PRIMARY KEY 	(id_carhor)
);
ALTER TABLE sis_ch_semanal
  ADD CONSTRAINT "sis_ch_semanal_evitar_repetição" UNIQUE(dia_semana);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('SEG', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('TER', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('QUA', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('QUI', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('SEX', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('SAB', 0);
INSERT INTO sis_ch_semanal (dia_semana, horastrab) VALUES ('DOM', 0);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_ct_lancfunc AS
	SELECT data_tar, nome_compl, ocupacao, codcli || ' - ' || fantasia AS cliente, 
	CASE WHEN mesini_pc <> '' THEN mesini_pc || '/' || anoini_pc 
	ELSE ''
	END AS ini,
	CASE WHEN mesfin_pc <> '' THEN mesfin_pc || '/' || anofin_pc 
	ELSE ''
	END AS fim, 
	to_char(duracao, 'HH24:MI') AS tempo
	FROM ct_tarefa t
	INNER JOIN ct_funcionario f ON f.id_funcio = t.id_funcio
	INNER JOIN sis_ct_ocupacao o ON o.id_ocupac = t.id_ocupac
	LEFT JOIN cliente c ON c.id_cliente = t.id_cliente
	LEFT JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	ORDER BY data_tar, nome_compl, ocupacao;
ALTER TABLE v_ct_lancfunc OWNER TO postgres;

