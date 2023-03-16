
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XI


ALTER TABLE sis_ct_ocupacao
ADD COLUMN id_depart 	INTEGER;


ALTER TABLE cliente_ecnpj
ADD COLUMN obr_pro 	BOOLEAN DEFAULT FALSE;


ALTER TABLE cliente_ecpf 
ADD COLUMN obr_pro 	BOOLEAN DEFAULT FALSE;


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_ocupacao;
CREATE OR REPLACE VIEW v_ocupacao AS 
	SELECT o.id_ocupac, o.ocupacao, o.cliente, o.periodo, c.categoria, o.t_vinculo, 
	CASE WHEN d.departamento ISNULL
	THEN 'TODOS'
	ELSE d.departamento
	END AS departamento,
	CASE WHEN d.ap_depto ISNULL
	THEN 'T'
	ELSE d.ap_depto
	END AS ap_depto
	FROM sis_ct_ocupacao o
	JOIN sis_ct_categoria c ON c.id_catego = o.id_catego
	LEFT JOIN sis_departamento d ON d.id_depart = o.id_depart
	ORDER BY o.ocupacao;
ALTER TABLE v_ocupacao OWNER TO postgres;


CREATE OR REPLACE VIEW v_rel_cdig_jur AS 
	SELECT c.codcli, p.fantasia, 
	CASE WHEN c.obr_ecdj = TRUE
	THEN 'SIM'
	ELSE 'NÃO'
	END AS cd, 
	cj.tip_cdj, cj.vnc_cdj, 
	CASE WHEN cj.obr_pro = TRUE
	THEN 'SIM'
	ELSE 'NÃO'
	END AS proc, 
	cj.vnc_prc FROM cliente c 
	INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	INNER JOIN cliente_status cs ON cs.id_clista = c.id_clista
	LEFT JOIN cliente_ecnpj cj on c.id_cliente = cj.id_cliente
	WHERE cs.status <> 'DISTRATADO'
	ORDER BY c.codcli;
ALTER TABLE v_rel_cdig_jur OWNER TO postgres;

    
--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


