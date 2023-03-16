
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO IX


ALTER TABLE sis_ct_ocupacao
ADD COLUMN t_vinculo	INT2;
UPDATE sis_ct_ocupacao SET t_vinculo = 4;


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_ocupacao;
CREATE OR REPLACE VIEW v_ocupacao AS 
  SELECT o.id_ocupac, o.ocupacao, o.cliente, o.periodo, c.categoria, o.t_vinculo
   FROM sis_ct_ocupacao o
   JOIN sis_ct_categoria c ON c.id_catego = o.id_catego
   ORDER BY o.ocupacao;
ALTER TABLE v_ocupacao OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


