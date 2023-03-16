
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XV


CREATE TABLE cliente_enquad_orgao
(
	id_clenqo	SERIAL NOT NULL,
	enq_orgao	CHARACTER VARYING(10) UNIQUE, 
	PRIMARY KEY 	(id_clenqo)
);


ALTER TABLE cliente ADD COLUMN id_clenqo INTEGER;


ALTER TABLE cliente 
ADD COLUMN dt_as_dist	DATE, 
ADD COLUMN dt_rg_dist	DATE,
ADD COLUMN nm_rg_dist	CHARACTER VARYING(30);


ALTER TABLE cliente ADD COLUMN id_admnso INTEGER;


ALTER TABLE cliente 
ADD COLUMN or_classe	CHARACTER VARYING(100), 
ADD COLUMN nm_classe	CHARACTER VARYING(30);


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_cliente;
CREATE OR REPLACE VIEW v_cliente AS 
	SELECT p.id_pessoa, p.ativo, p.codigo, cl.codcli, p.nome, p.nat_pessoa, 
	sp.tipo, p.id_cidade, 
	(c.nome_cidade::text || ' - '::text) || e.uf::text AS cidade, p.fantasia, 
	p.cnpj_cpf, 
	CASE
	WHEN p.cnpj_cpf::text <> ''::text THEN 
	CASE
	WHEN p.nat_pessoa = 1 THEN ((((("substring"(p.cnpj_cpf::text, 1, 3) || '.'::text) || "substring"(p.cnpj_cpf::text, 4, 3)) || '.'::text) || "substring"(p.cnpj_cpf::text, 7, 3)) || '-'::text) || "substring"(p.cnpj_cpf::text, 10, 2)
	WHEN p.nat_pessoa = 2 THEN ((((((("substring"(p.cnpj_cpf::text, 1, 2) || '.'::text) || "substring"(p.cnpj_cpf::text, 3, 3)) || '.'::text) || "substring"(p.cnpj_cpf::text, 6, 3)) || '/'::text) || "substring"(p.cnpj_cpf::text, 9, 4)) || '-'::text) || "substring"(p.cnpj_cpf::text, 13, 2)
	ELSE NULL::text
	END
	ELSE NULL::text
	END AS cpf_cnpj, 
	p.ie_rg, p.org_exp_rg, p.ccm, st.status, cl.forma, cl.simples, 
	cl.data_distr, cl.codcli::character(6) AS pesqcli, cl.orgao, cl.dt_assin, 
	cl.dt_regis, cl.num_regis, cl.id_cliente, umb.unimon, cl.cap_ini, 
	cl.dt_as_cap, cl.dt_rg_cap, cl.obj_social, cl.ger_social, cl.prolabore, 
	cl.dist_lucro, cl.n_contrat, cl.dt_contrat, umb1.unimon AS unimin, 
	cl.mens_inic, umb2.unimon AS unimat, cl.mens_atual, cl.desc_mens, 
	cl.s_contabil, cl.s_livcaixa, cl.s_fiscal, cl.s_rh, cl.s_arqescr, 
	cl.s_visprof, cl.s_remmboy, cl.s_rememail, cl.s_remsite, cl.dt_encerr, 
	cl.mens_atual - cl.desc_mens AS liq_mens, cl.obr_ecdj, cl.obr_neg, 
	cl.obr_ecdf, ceo.enq_orgao, cl.dt_as_dist, cl.dt_rg_dist, cl.nm_rg_dist, 
	p1.nome as admnso, cl.or_classe, cl.nm_classe
	FROM pessoa p
	JOIN sis_pessoa sp ON sp.id_sis_pessoa = p.nat_pessoa
	JOIN cidade c ON c.id_cidade = p.id_cidade
	JOIN estado e ON e.id_estado = c.id_estado
	JOIN cliente cl ON cl.id_pessoa = p.id_pessoa
	JOIN cliente_status st ON st.id_clista = cl.id_clista
	LEFT JOIN unid_mon_brasil umb ON umb.id_unimon = cl.id_unimon
	LEFT JOIN unid_mon_brasil umb1 ON umb1.id_unimon = cl.iduni_min
	LEFT JOIN unid_mon_brasil umb2 ON umb2.id_unimon = cl.iduni_mat
	LEFT JOIN cliente_enquad_orgao ceo ON ceo.id_clenqo = cl.id_clenqo
	LEFT JOIN pessoa p1 ON p1.id_pessoa = cl.id_admnso
	ORDER BY cl.codcli;
ALTER TABLE v_cliente OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


