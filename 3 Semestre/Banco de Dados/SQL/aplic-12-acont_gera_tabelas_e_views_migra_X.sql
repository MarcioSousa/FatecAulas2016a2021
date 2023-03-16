
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO X


CREATE TABLE cliente_ocupacao
(
  id_cliocp 	serial NOT NULL,
  id_cliente 	integer,
  id_ocupac 	integer,
  PRIMARY KEY 	(id_cliocp)
);
ALTER TABLE cliente_ocupacao
  ADD CONSTRAINT "cliente_ocupacao_evitar_repetição" UNIQUE(id_cliente, id_ocupac);


ALTER TABLE cliente 
ADD COLUMN obr_ecdj 	BOOLEAN DEFAULT true,
ADD COLUMN obr_neg	CHARACTER VARYING(160), 
ADD COLUMN obr_ecdf	BOOLEAN DEFAULT false;


CREATE TABLE cliente_ecnpj
(
  id_clicpj 	serial NOT NULL,
  id_cliente 	integer,
  tip_cdj 	character varying(10),
  rsp_cdj 	character varying(60),
  vnc_cdj 	date,
  vnc_prc 	date,
  sn1_cdj 	character varying(20),
  sn2_cdj 	character varying(20),
  sn3_cdj 	character varying(20),
  PRIMARY KEY 	(id_clicpj)
);


CREATE TABLE cliente_ecpf
(
  id_clicpf 	serial NOT NULL,
  id_cliente 	integer,
  tip_cdf 	character varying(10),
  rsp_cdf 	character varying(60),
  vnc_cdf 	date,
  vnc_prc 	date,
  sn1_cdf 	character varying(20),
  sn2_cdf 	character varying(20),
  sn3_cdf 	character varying(20),
  PRIMARY KEY 	(id_clicpf)
);


--***************************************************************************************************************************************

-- VIEWS  --


DROP VIEW v_funcionario;
CREATE OR REPLACE VIEW v_funcionario AS 
 SELECT cf.id_funcio, u.nome, cf.nome_compl, sd.departamento, sc.cargo, 
    cf.dt_admiss, cf.dt_demiss, cf.salario, cf.id_usuario
   FROM ct_funcionario cf
   JOIN usuario u ON u.id_usuario = cf.id_usuario
   JOIN sis_departamento sd ON sd.id_depart = cf.id_depart
   JOIN sis_cargo sc ON sc.id_cargoc = cf.id_cargoc
  ORDER BY u.nome;
ALTER TABLE v_funcionario OWNER TO postgres;


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
    cl.mens_atual - cl.desc_mens AS liq_mens, cl.obr_ecdj, cl.obr_neg, cl.obr_ecdf
   FROM pessoa p
   JOIN sis_pessoa sp ON sp.id_sis_pessoa = p.nat_pessoa
   JOIN cidade c ON c.id_cidade = p.id_cidade
   JOIN estado e ON e.id_estado = c.id_estado
   JOIN cliente cl ON cl.id_pessoa = p.id_pessoa
   JOIN cliente_status st ON st.id_clista = cl.id_clista
   LEFT JOIN unid_mon_brasil umb ON umb.id_unimon = cl.id_unimon
   LEFT JOIN unid_mon_brasil umb1 ON umb1.id_unimon = cl.iduni_min
   LEFT JOIN unid_mon_brasil umb2 ON umb2.id_unimon = cl.iduni_mat
  ORDER BY cl.codcli;
ALTER TABLE v_cliente OWNER TO postgres;

  
--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


