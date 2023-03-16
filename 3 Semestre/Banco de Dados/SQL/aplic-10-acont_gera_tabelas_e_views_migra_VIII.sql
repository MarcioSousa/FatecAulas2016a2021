
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO VIII


DROP TABLE zz3_temp CASCADE;
DROP TABLE zz3_temp_2 CASCADE;


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_ct_saldohora;
CREATE OR REPLACE VIEW v_ct_saldohora AS 
	SELECT t.data_tar, 
        CASE date_part('dow'::text, t.data_tar)
            WHEN 0 THEN 'DOM'::text
            WHEN 1 THEN 'SEG'::text
            WHEN 2 THEN 'TER'::text
            WHEN 3 THEN 'QUA'::text
            WHEN 4 THEN 'QUI'::text
            WHEN 5 THEN 'SEX'::text
            WHEN 6 THEN 'SAB'::text
            ELSE NULL::text
        END AS dia_sem, 
	f.nome_compl, 
        CASE
            WHEN (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN (( SELECT sis_ch_semanal.horastrab
               FROM sis_ch_semanal
              WHERE sis_ch_semanal.dia_semana::text = 
                    CASE date_part('dow'::text, t.data_tar)
                        WHEN 0 THEN 'DOM'::text
                        WHEN 1 THEN 'SEG'::text
                        WHEN 2 THEN 'TER'::text
                        WHEN 3 THEN 'QUA'::text
                        WHEN 4 THEN 'QUI'::text
                        WHEN 5 THEN 'SEX'::text
                        WHEN 6 THEN 'SAB'::text
                        ELSE NULL::text
                    END)) * 60::double precision
            ELSE (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) * 60::double precision
        END AS esperado, 
        CASE
            WHEN (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN 
            CASE date_part('dow'::text, t.data_tar)
                WHEN 0 THEN 'HORA EXTRA'::text
                WHEN 1 THEN 'DIA NORMAL'::text
                WHEN 2 THEN 'DIA NORMAL'::text
                WHEN 3 THEN 'DIA NORMAL'::text
                WHEN 4 THEN 'DIA NORMAL'::text
                WHEN 5 THEN 'DIA NORMAL'::text
                WHEN 6 THEN 'HORA EXTRA'::text
                ELSE NULL::text
            END::character varying
            ELSE ( SELECT v_feriado.tipo_fer
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)
        END AS tipo, 
	sum(date_part('hour'::text, t.duracao) * 60::double precision + date_part('minute'::text, t.duracao)) AS realizado, 
        CASE
            WHEN (sum(date_part('hour'::text, t.duracao) * 60::double precision + date_part('minute'::text, t.duracao)) - 
            CASE
                WHEN (( SELECT v_feriado.hora
                   FROM v_feriado
                  WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN (( SELECT sis_ch_semanal.horastrab
                   FROM sis_ch_semanal
                  WHERE sis_ch_semanal.dia_semana::text = 
                        CASE date_part('dow'::text, t.data_tar)
                            WHEN 0 THEN 'DOM'::text
                            WHEN 1 THEN 'SEG'::text
                            WHEN 2 THEN 'TER'::text
                            WHEN 3 THEN 'QUA'::text
                            WHEN 4 THEN 'QUI'::text
                            WHEN 5 THEN 'SEX'::text
                            WHEN 6 THEN 'SAB'::text
                            ELSE NULL::text
                        END)) * 60::double precision
                ELSE (( SELECT v_feriado.hora
                   FROM v_feriado
                  WHERE v_feriado.dia_data = t.data_tar)) * 60::double precision
            END) >= 0::double precision THEN 'Carga ok'::text
            ELSE 'Verificar Carga'::text
        END AS carga, 
	(trunc((sum(date_part('hour'::text, t.duracao) * 60::double precision + date_part('minute'::text, t.duracao)) - 
        CASE
            WHEN (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN (( SELECT sis_ch_semanal.horastrab
               FROM sis_ch_semanal
              WHERE sis_ch_semanal.dia_semana::text = 
                    CASE date_part('dow'::text, t.data_tar)
                        WHEN 0 THEN 'DOM'::text
                        WHEN 1 THEN 'SEG'::text
                        WHEN 2 THEN 'TER'::text
                        WHEN 3 THEN 'QUA'::text
                        WHEN 4 THEN 'QUI'::text
                        WHEN 5 THEN 'SEX'::text
                        WHEN 6 THEN 'SAB'::text
                        ELSE NULL::text
                    END)) * 60::double precision
            ELSE (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) * 60::double precision
        END) / 60::double precision) || ':'::text) || to_char(abs(((sum(date_part('hour'::text, t.duracao) * 60::double precision + date_part('minute'::text, t.duracao)) - 
        CASE
            WHEN (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN (( SELECT sis_ch_semanal.horastrab
               FROM sis_ch_semanal
              WHERE sis_ch_semanal.dia_semana::text = 
                    CASE date_part('dow'::text, t.data_tar)
                        WHEN 0 THEN 'DOM'::text
                        WHEN 1 THEN 'SEG'::text
                        WHEN 2 THEN 'TER'::text
                        WHEN 3 THEN 'QUA'::text
                        WHEN 4 THEN 'QUI'::text
                        WHEN 5 THEN 'SEX'::text
                        WHEN 6 THEN 'SAB'::text
                        ELSE NULL::text
                    END)) * 60::double precision
            ELSE (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) * 60::double precision
        END) / 60::double precision - trunc((sum(date_part('hour'::text, t.duracao) * 60::double precision + date_part('minute'::text, t.duracao)) - 
        CASE
            WHEN (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) IS NULL THEN (( SELECT sis_ch_semanal.horastrab
               FROM sis_ch_semanal
              WHERE sis_ch_semanal.dia_semana::text = 
                    CASE date_part('dow'::text, t.data_tar)
                        WHEN 0 THEN 'DOM'::text
                        WHEN 1 THEN 'SEG'::text
                        WHEN 2 THEN 'TER'::text
                        WHEN 3 THEN 'QUA'::text
                        WHEN 4 THEN 'QUI'::text
                        WHEN 5 THEN 'SEX'::text
                        WHEN 6 THEN 'SAB'::text
                        ELSE NULL::text
                    END)) * 60::double precision
            ELSE (( SELECT v_feriado.hora
               FROM v_feriado
              WHERE v_feriado.dia_data = t.data_tar)) * 60::double precision
        END) / 60::double precision)) * 60::double precision), 'FM00'::text) AS saldo
	FROM ct_tarefa t
	JOIN ct_funcionario f ON f.id_funcio = t.id_funcio
	JOIN sis_ct_ocupacao o ON o.id_ocupac = t.id_ocupac
	GROUP BY t.data_tar, f.nome_compl
	ORDER BY f.nome_compl, t.data_tar;
ALTER TABLE v_ct_saldohora OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


