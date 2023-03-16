
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XVII

--=======================================================================================================================================
--
--
--*********************************    PRESTAR ATENÇÃO    *********************************
--
-- alterar descricao para character varying(50) em sis_orgreg e sis_orgcla
-- antes de tudo, verificar se a migração para sis_orgreg já foi feita
-- rodar primeiro
ALTER TABLE cliente ADD COLUMN id_orgreg INTEGER REFERENCES sis_orgreg (id_orgreg);
ALTER TABLE cliente ADD COLUMN id_orgcla INTEGER REFERENCES sis_orgcla (id_orgcla);
--rodar segundo
UPDATE cliente SET id_orgreg = (SELECT id_orgreg FROM sis_orgreg WHERE descricao = orgao);
--rodar terceiro
UPDATE cliente SET id_orgreg = (SELECT id_orgreg FROM sis_orgreg WHERE descricao = '') WHERE id_orgreg ISNULL;
--rodar quarto
ALTER TABLE cliente 
ADD COLUMN dtregcla 	DATE,
ADD COLUMN dtcancla	DATE;
--rodar quinto - view v_cliente
--rodar sexto
ALTER TABLE cliente DROP COLUMN orgao;
ALTER TABLE cliente DROP COLUMN or_classe;
--
--*****************************************************************************************
--
--
--=======================================================================================================================================


CREATE TABLE cliente_cnae 
(
	id_clcnae	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_cnae		INTEGER REFERENCES sis_cnae (id_cnae),
	principal	BOOLEAN DEFAULT false,
	dt_inclus	DATE,
	dt_exclus	DATE,
	PRIMARY KEY 	(id_clcnae)
);
ALTER TABLE cliente_cnae ADD CONSTRAINT "cliente_cnae_evitar_repetição" UNIQUE(id_cliente, id_cnae, dt_inclus);


CREATE TABLE cliente_ftribut 
(
	id_ftribt	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_rtribf	INTEGER REFERENCES sis_regtribfed (id_rtribf),
	id_subnv1	INTEGER,
	id_subnv2	INTEGER,
	dt_inclus	DATE,
	dt_exclus	DATE,
	PRIMARY KEY 	(id_ftribt)
);
ALTER TABLE cliente_ftribut ADD CONSTRAINT "cliente_ftribut_evitar_repetição" UNIQUE(id_cliente, id_rtribf, dt_inclus);


CREATE TABLE cliente_obraces
(
	id_cliobr	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_obrace	INTEGER REFERENCES sis_obr_aces (id_obrace),
	dt_inclus	DATE,
	dt_exclus	DATE,
	PRIMARY KEY 	(id_cliobr)
);
ALTER TABLE cliente_obraces ADD CONSTRAINT "cliente_obraces_evitar_repetição" UNIQUE(id_cliente, id_obrace, dt_inclus);


DROP TABLE cliente_imposto CASCADE;
DROP TABLE cliente_hist_imposto CASCADE;


CREATE TABLE cliente_fimptrib
(
	id_cliimp	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_impost	INTEGER REFERENCES sis_imposto (id_impost),
	dt_inclus	DATE,
	dt_exclus	DATE,
	PRIMARY KEY 	(id_cliimp)
);
ALTER TABLE cliente_fimptrib ADD CONSTRAINT "cliente_fimptrib_evitar_repetição" UNIQUE(id_cliente, id_impost, dt_inclus);


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
	cl.data_distr, cl.codcli::character(6) AS pesqcli, 
	oreg.descricao as orgao, 
	cl.dt_assin, 
	cl.dt_regis, cl.num_regis, cl.id_cliente, umb.unimon, cl.cap_ini, 
	cl.dt_as_cap, cl.dt_rg_cap, cl.obj_social, cl.ger_social, cl.prolabore, 
	cl.dist_lucro, cl.n_contrat, cl.dt_contrat, umb1.unimon AS unimin, 
	cl.mens_inic, umb2.unimon AS unimat, cl.mens_atual, cl.desc_mens, 
	cl.s_contabil, cl.s_livcaixa, cl.s_fiscal, cl.s_rh, cl.s_arqescr, 
	cl.s_visprof, cl.s_remmboy, cl.s_rememail, cl.s_remsite, cl.dt_encerr, 
	cl.mens_atual - cl.desc_mens AS liq_mens, cl.obr_ecdj, cl.obr_neg, 
	cl.obr_ecdf, ceo.enq_orgao, cl.dt_as_dist, cl.dt_rg_dist, cl.nm_rg_dist, 
	p1.nome AS admnso, orcl.descricao as or_classe, cl.nm_classe, cl.dtregcla, 
	cl.dtcancla 
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
	LEFT JOIN sis_orgreg oreg ON oreg.id_orgreg = cl.id_orgreg
	LEFT JOIN sis_orgcla orcl ON orcl.id_orgcla = cl.id_orgcla
	ORDER BY cl.codcli;
ALTER TABLE v_cliente OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


