
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XIV


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_rel_cdig_jur;
CREATE OR REPLACE VIEW v_rel_cdig_jur AS 
	SELECT c.codcli, p.fantasia, 
        CASE WHEN c.obr_ecdj = true THEN 'SIM' ELSE 'NÃO' END AS cd, 
	cj.tip_cdj AS tip_cdg, cj.vnc_cdj AS vnc_cdg, 
        CASE WHEN cj.obr_prfej = true THEN 'SIM' ELSE 'NÃO' END AS prfe, 
	cj.vnc_prfej AS vnc_prfe,
	CASE WHEN cj.obr_pcefj = true THEN 'SIM' ELSE 'NÃO' END AS pcef, 
	cj.vnc_pcefj AS vnc_pcef,
	CASE WHEN cj.obr_pdecj = true THEN 'SIM' ELSE 'NÃO' END AS pdec, 
	cj.vnc_pdecj AS vnc_pdec
	FROM cliente c
	JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	JOIN cliente_status cs ON cs.id_clista = c.id_clista
	LEFT JOIN cliente_ecnpj cj ON c.id_cliente = cj.id_cliente
	WHERE cs.status <> 'DISTRATADO'
	ORDER BY c.codcli;
ALTER TABLE v_rel_cdig_jur OWNER TO postgres;


DROP VIEW v_rel_cdig_fis;
CREATE OR REPLACE VIEW v_rel_cdig_fis AS 
	SELECT c.codcli, p.fantasia, 
        CASE WHEN c.obr_ecdf = true THEN 'SIM' ELSE 'NÃO' END AS cd, 
	cj.tip_cdf AS tip_cdg, cj.vnc_cdf AS vnc_cdg, 
        CASE WHEN cj.obr_prfef = true THEN 'SIM' ELSE 'NÃO' END AS prfe, 
	cj.vnc_prfef AS vnc_prfe,
	CASE WHEN cj.obr_pceff = true THEN 'SIM' ELSE 'NÃO' END AS pcef, 
	cj.vnc_pceff AS vnc_pcef,
	CASE WHEN cj.obr_pdecf = true THEN 'SIM' ELSE 'NÃO' END AS pdec, 
	cj.vnc_pdecf AS vnc_pdec
	FROM cliente c
	JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	JOIN cliente_status cs ON cs.id_clista = c.id_clista
	LEFT JOIN cliente_ecpf cj ON c.id_cliente = cj.id_cliente
	WHERE cs.status <> 'DISTRATADO'
	ORDER BY c.codcli;
ALTER TABLE v_rel_cdig_fis OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


