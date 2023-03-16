
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XIII


CREATE TABLE cliente_ecnpj
(
	id_clicpj	serial NOT NULL,
	id_cliente 	integer,
	tip_cdj 	character varying(10),
	rsp_cdj 	character varying(60),
	vnc_cdj 	date,
	obr_prfej 	boolean DEFAULT false,
	vnc_prfej 	date,
	obr_pcefj 	boolean DEFAULT false,
	vnc_pcefj 	date,
	obr_pdecj 	boolean DEFAULT false,
	vnc_pdecj 	date,
	sn1_cdj 	character varying(20),
	sn2_cdj 	character varying(20),
	sn3_cdj 	character varying(20),
	PRIMARY KEY (id_clicpj)
);


CREATE TABLE cliente_ecpf
(
	id_clicpf 	serial NOT NULL,
	id_cliente 	integer,
	tip_cdf 	character varying(10),
	rsp_cdf 	character varying(60),
	vnc_cdf 	date,
	obr_prfef 	boolean DEFAULT false,
	vnc_prfef 	date,
	obr_pceff 	boolean DEFAULT false,
	vnc_pceff 	date,
	obr_pdecf 	boolean DEFAULT false,
	vnc_pdecf 	date,
    	sn1_cdf 	character varying(20),
	sn2_cdf 	character varying(20),
	sn3_cdf 	character varying(20),
	PRIMARY KEY (id_clicpf)
);

--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_rel_cdig_jur AS 
	SELECT c.codcli, p.fantasia, 
        CASE WHEN c.obr_ecdj = true THEN 'SIM' ELSE 'NÃO' END AS cd, 
	cj.tip_cdj AS tip_cdg, cj.vnc_cdj AS vnc_cdg, 
        CASE WHEN cj.obr_prfej = true THEN 'SIM' ELSE 'NÃO' END AS prfj, 
	cj.vnc_prfej,
	CASE WHEN cj.obr_pcefj = true THEN 'SIM' ELSE 'NÃO' END AS pcefj, 
	cj.vnc_pcefj,
	CASE WHEN cj.obr_pdecj = true THEN 'SIM' ELSE 'NÃO' END AS pdecj, 
	cj.vnc_pdecj
	FROM cliente c
	JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	JOIN cliente_status cs ON cs.id_clista = c.id_clista
	LEFT JOIN cliente_ecnpj cj ON c.id_cliente = cj.id_cliente
	WHERE cs.status <> 'DISTRATADO'
	ORDER BY c.codcli;
ALTER TABLE v_rel_cdig_jur OWNER TO postgres;


CREATE OR REPLACE VIEW v_rel_cdig_fis AS 
	SELECT c.codcli, p.fantasia, 
        CASE WHEN c.obr_ecdf = true THEN 'SIM' ELSE 'NÃO' END AS cd, 
	cj.tip_cdf AS tip_cdg, cj.vnc_cdf AS vnc_cdg, 
        CASE WHEN cj.obr_prfef = true THEN 'SIM' ELSE 'NÃO' END AS prff, 
	cj.vnc_prfef,
	CASE WHEN cj.obr_pceff = true THEN 'SIM' ELSE 'NÃO' END AS pceff, 
	cj.vnc_pceff,
	CASE WHEN cj.obr_pdecf = true THEN 'SIM' ELSE 'NÃO' END AS pdecf, 
	cj.vnc_pdecf
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


