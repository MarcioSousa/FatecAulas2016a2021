
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO V


CREATE TABLE sis_ch_tipoferiado
(
	id_tipfer	SERIAL NOT NULL,
	tipo_fer	CHARACTER VARYING(15) NOT NULL UNIQUE,
	hora		REAL,
	PRIMARY KEY 	(id_tipfer)
);
INSERT INTO sis_ch_tipoferiado (tipo_fer, hora) VALUES ('FERIADO', 0);
INSERT INTO sis_ch_tipoferiado (tipo_fer, hora) VALUES ('PONTE', 0);
INSERT INTO sis_ch_tipoferiado (tipo_fer, hora) VALUES ('8-COMPENSAÇÃO', 8);
INSERT INTO sis_ch_tipoferiado (tipo_fer, hora) VALUES ('9-COMPENSAÇÃO', 9);


CREATE TABLE sis_ch_feriado
(
	id_feriad	SERIAL NOT NULL,
	dia_data	DATE UNIQUE,
	tipo_ocor	INTEGER REFERENCES sis_ch_tipoferiado (id_tipfer),
	coment		CHARACTER VARYING(30),
	PRIMARY KEY 	(id_feriad)
);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_ct_saldohora AS
	SELECT data_tar, 
	CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM' 
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END AS dia_sem,
	nome_compl, 
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	(SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM'
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END )*60 
	ELSE (SELECT hora FROM v_feriado WHERE dia_data = data_tar)*60
	END AS esperado,  
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'HORA EXTRA' 
	WHEN 1 THEN 'DIA NORMAL'
	WHEN 2 THEN 'DIA NORMAL'
	WHEN 3 THEN 'DIA NORMAL'
	WHEN 4 THEN 'DIA NORMAL'
	WHEN 5 THEN 'DIA NORMAL'
	WHEN 6 THEN 'HORA EXTRA'
	END 
	ELSE (SELECT tipo_fer FROM v_feriado WHERE dia_data = data_tar) END AS tipo, 
	SUM(EXTRACT(HOUR FROM duracao)*60 + EXTRACT(MINUTE FROM duracao)) AS realizado,
	CASE WHEN SUM(EXTRACT(HOUR FROM duracao)*60 + EXTRACT(MINUTE FROM duracao)) - 
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	(SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM'
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END )*60 
	ELSE (SELECT hora FROM v_feriado WHERE dia_data = data_tar)*60
	END >= 0 THEN 'Carga ok' ELSE 'Verificar Carga' END AS carga,
	TRUNC((SUM(EXTRACT(HOUR FROM duracao)*60 + EXTRACT(MINUTE FROM duracao)) - 
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	(SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM'
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END )*60 
	ELSE (SELECT hora FROM v_feriado WHERE dia_data = data_tar)*60
	END)/60) || ':' ||	
	TO_CHAR(ABS((((SUM(EXTRACT(HOUR FROM duracao)*60 + EXTRACT(MINUTE FROM duracao)) - 
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	(SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM'
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END )*60 
	ELSE (SELECT hora FROM v_feriado WHERE dia_data = data_tar)*60
	END)/60) - 
	TRUNC((SUM(EXTRACT(HOUR FROM duracao)*60 + EXTRACT(MINUTE FROM duracao)) - 
	CASE WHEN (SELECT hora FROM v_feriado WHERE dia_data = data_tar) IS NULL THEN 
	(SELECT horastrab FROM sis_ch_semanal WHERE dia_semana = CASE EXTRACT(DOW FROM data_tar)
	WHEN 0 THEN 'DOM'
	WHEN 1 THEN 'SEG'
	WHEN 2 THEN 'TER'
	WHEN 3 THEN 'QUA'
	WHEN 4 THEN 'QUI'
	WHEN 5 THEN 'SEX'
	WHEN 6 THEN 'SAB'
	END )*60 
	ELSE (SELECT hora FROM v_feriado WHERE dia_data = data_tar)*60
	END)/60))*60),'FM00') AS saldo  
	FROM ct_tarefa t
	INNER JOIN ct_funcionario f on f.id_funcio = t.id_funcio 
	INNER JOIN sis_ct_ocupacao o on o.id_ocupac = t.id_ocupac 
	WHERE o.ocupacao <> 'ALMOÇO' 
	GROUP BY data_tar, nome_compl
	ORDER BY nome_compl, data_tar;
ALTER TABLE v_ct_saldohora OWNER TO postgres;


CREATE OR REPLACE VIEW v_feriado AS
	SELECT id_feriad, dia_data, tipo_fer, hora, coment, to_char(dia_data,'DDMMYYYY') as pesqdt
	FROM sis_ch_feriado f 
	INNER JOIN sis_ch_tipoferiado t ON t.id_tipfer = f.tipo_ocor 
	ORDER BY dia_data DESC;
ALTER TABLE v_feriado OWNER TO postgres; 


