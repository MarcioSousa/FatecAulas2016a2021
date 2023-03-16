
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO II


CREATE TABLE unid_mon_brasil
(
	id_unimon	SERIAL NOT NULL,
	unimon		CHARACTER VARYING(5), 
	nommon		CHARACTER VARYING(15), 
	PRIMARY KEY 	(id_unimon)
);
INSERT INTO unid_mon_brasil (unimon, nommon) VALUES ('CR$','CRUZEIRO');
INSERT INTO unid_mon_brasil (unimon, nommon) VALUES ('CZ$','CRUZADO');
INSERT INTO unid_mon_brasil (unimon, nommon) VALUES ('NCR$','CRUZEIRO NOVO');
INSERT INTO unid_mon_brasil (unimon, nommon) VALUES ('NCZ$','CRUZADO NOVO');
INSERT INTO unid_mon_brasil (unimon, nommon) VALUES ('R$','REAL');


CREATE TABLE cliente_status
(
	id_clista	SERIAL NOT NULL,
	status		CHARACTER VARYING(12), 
	PRIMARY KEY 	(id_clista)
);
INSERT INTO cliente_status (status) VALUES ('ATIVO');
INSERT INTO cliente_status (status) VALUES ('SUSPENSO');
INSERT INTO cliente_status (status) VALUES ('DISTRATADO');
INSERT INTO cliente_status (status) VALUES ('MANUTENÇÃO');
INSERT INTO cliente_status (status) VALUES ('ENCERRAMENTO');
INSERT INTO cliente_status (status) VALUES ('ENCERRADA');


ALTER TABLE cliente 
ADD COLUMN id_clista	INTEGER DEFAULT 1 REFERENCES cliente_status (id_clista),
ADD COLUMN forma	BOOLEAN DEFAULT false, 
ADD COLUMN simples	BOOLEAN DEFAULT false,
ADD COLUMN data_distr	DATE,
ADD COLUMN orgao	CHARACTER VARYING(100),
ADD COLUMN dt_assin	DATE,
ADD COLUMN dt_regis	DATE,
ADD COLUMN num_regis	CHARACTER VARYING(30),
ADD COLUMN id_unimon	INTEGER REFERENCES unid_mon_brasil (id_unimon),
ADD COLUMN cap_ini	REAL,
ADD COLUMN dt_as_cap	DATE,
ADD COLUMN dt_rg_cap	DATE,
ADD COLUMN obj_social	TEXT,
ADD COLUMN ger_social	TEXT,
ADD COLUMN prolabore	TEXT,
ADD COLUMN dist_lucro	TEXT;


CREATE TABLE cliente_alt_contrato
(
	id_cliaco	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	dt_ass_ac	DATE,
	dt_reg_ac	DATE,
	num_reg_ac	CHARACTER VARYING(30), 
	PRIMARY KEY 	(id_cliaco)
);
ALTER TABLE cliente_alt_contrato
  ADD CONSTRAINT "cliente_alt_contrato_evitar_repetição" UNIQUE(id_cliente, dt_ass_ac, dt_reg_ac, num_reg_ac);


CREATE TABLE cliente_alt_capit_social
(
	id_cliacs	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_unimon	INTEGER REFERENCES unid_mon_brasil (id_unimon),
	aum_capit	REAL,
	moeda		REAL,
	res_correc	REAL,
	res_lucro	REAL,
	res_depos	REAL,
	cap_atual	REAL,
	dt_ass_acs	DATE,
	dt_reg_acs	DATE,
	PRIMARY KEY 	(id_cliacs)
);
ALTER TABLE cliente_alt_capit_social
  ADD CONSTRAINT "cliente_alt_capit_social_evitar_repetição" UNIQUE(id_cliente, id_unimon, aum_capit, moeda, res_correc, res_lucro, res_depos, cap_atual, dt_ass_acs, dt_reg_acs);


INSERT INTO tipo_pessoa (tipopessoa) VALUES ('SÓCIO');


CREATE TABLE sis_estado_civil
(
	id_estciv	SERIAL NOT NULL,
	est_civil	CHARACTER VARYING(22), 
	PRIMARY KEY 	(id_estciv)
);
ALTER TABLE sis_estado_civil
  ADD CONSTRAINT "sis_estado_civil_evitar_repetição" UNIQUE(est_civil);
INSERT INTO sis_estado_civil (est_civil) VALUES ('SOLTEIRO');
INSERT INTO sis_estado_civil (est_civil) VALUES ('CASADO');
INSERT INTO sis_estado_civil (est_civil) VALUES ('SEPARADO JUDICIALMENTE');
INSERT INTO sis_estado_civil (est_civil) VALUES ('DIVORCIADO');
INSERT INTO sis_estado_civil (est_civil) VALUES ('VIÚVO');


CREATE TABLE sis_nacionalidade
(
	id_nacion	SERIAL NOT NULL,
	nacionalid	CHARACTER VARYING(20), 
	PRIMARY KEY 	(id_nacion)
);
ALTER TABLE sis_nacionalidade
  ADD CONSTRAINT "sis_nacionalidade_evitar_repetição" UNIQUE(nacionalid);

  
CREATE TABLE cliente_socio 
(
	id_clisoc	SERIAL NOT NULL,
	id_cliente 	INTEGER REFERENCES cliente (id_cliente),
	id_pessoa	INTEGER REFERENCES pessoa (id_pessoa),
	n_tit_eleit	CHARACTER VARYING(20),
	zona_t_eleit	CHARACTER VARYING(6),
	org_nirc	CHARACTER VARYING(50),
	num_nirc	CHARACTER VARYING(15),
	data_nirc	DATE,
	org_classe	CHARACTER VARYING(20),
	num_classe	CHARACTER VARYING(20),
	dt_nascim	DATE,
	id_estciv	INTEGER,
	id_nacion	INTEGER REFERENCES sis_nacionalidade (id_nacion),
	id_cidade	INTEGER,
	filiacao	CHARACTER VARYING(120),
	dt_admiss	DATE,
	num_regist	CHARACTER VARYING(20),
	dt_regist	DATE,
	soc_gerent	BOOLEAN DEFAULT FALSE,
	resp_fiscal	BOOLEAN DEFAULT FALSE,
	prolabore	BOOLEAN DEFAULT FALSE,
	val_prolab	REAL,
	carne_inss	BOOLEAN DEFAULT FALSE,
	num_inss	CHARACTER VARYING(20),
	faixa_inss	CHARACTER VARYING(15),
	dt_alt_faixa	DATE,
	part_percent	REAL,
	part_quotas	REAL,
	part_valor	REAL,
	PRIMARY KEY 	(id_clisoc)
);
ALTER TABLE cliente_socio
  ADD CONSTRAINT "cliente_socio_evitar_repetição" UNIQUE(id_cliente, id_pessoa);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_cliente AS 
	SELECT p.id_pessoa, p.ativo, p.codigo, cl.codcli, p.nome, p.nat_pessoa, sp.tipo, 
	p.id_cidade, c.nome_cidade || ' - ' || e.uf as cidade, p.fantasia, p.cnpj_cpf, 
	CASE 
	WHEN p.cnpj_cpf <> '' THEN 
		CASE 
		WHEN p.nat_pessoa = 1 THEN SUBSTRING(p.cnpj_cpf FROM 1 FOR 3) || '.' || SUBSTRING(p.cnpj_cpf FROM 4 FOR 3)
				|| '.' || SUBSTRING(p.cnpj_cpf FROM 7 FOR 3) || '-' || SUBSTRING(p.cnpj_cpf FROM 10 FOR 2)
		WHEN p.nat_pessoa = 2 THEN SUBSTRING(p.cnpj_cpf FROM 1 FOR 2) || '.' || SUBSTRING(p.cnpj_cpf FROM 3 FOR 3)
				|| '.' || SUBSTRING(p.cnpj_cpf FROM 6 FOR 3) || '/' || SUBSTRING(p.cnpj_cpf FROM 9 FOR 4)
				|| '-' || SUBSTRING(p.cnpj_cpf FROM 13 FOR 2)
		END 
	END as cpf_cnpj,
	p.ie_rg, p.org_exp_rg, p.ccm, st.status, cl.forma, cl.simples, cl.data_distr, 
	cast(cl.codcli as character(6)) as pesqcli, cl.orgao, cl.dt_assin, cl.dt_regis, cl.num_regis, cl.id_cliente, 
	umb.unimon, cl.cap_ini, cl.dt_as_cap, cl.dt_rg_cap, cl.obj_social, cl.ger_social, cl.prolabore, cl.dist_lucro
	FROM pessoa p 
	INNER JOIN sis_pessoa sp ON sp.id_sis_pessoa = p.nat_pessoa
	INNER JOIN cidade c ON c.id_cidade = p.id_cidade 
	INNER JOIN estado e ON e.id_estado = c.id_estado 
	INNER JOIN cliente cl ON cl.id_pessoa = p.id_pessoa
	INNER JOIN cliente_status st ON st.id_clista = cl.id_clista
	LEFT JOIN unid_mon_brasil umb ON umb.id_unimon = cl.id_unimon
	ORDER BY cl.codcli;
ALTER TABLE v_cliente
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_alter_capital_social AS 
	SELECT ccs.id_cliente, umb.unimon, ccs.aum_capit, ccs.moeda, 
	ccs.res_correc, ccs.res_lucro, ccs.res_depos, ccs.cap_atual, 
	ccs.dt_ass_acs, ccs.dt_reg_acs, ccs.id_cliacs 
	FROM cliente_alt_capit_social ccs 
	INNER JOIN unid_mon_brasil umb ON umb.id_unimon = ccs.id_unimon
	ORDER BY ccs.dt_ass_acs;
ALTER TABLE v_alter_capital_social
  OWNER TO postgres;  


CREATE OR REPLACE VIEW v_quadro_social AS 
	SELECT p.nome, cs.part_quotas, 
	cs.part_valor, cs.part_percent, id_cliente 
	FROM cliente_socio cs 
	INNER JOIN pessoa p ON p.id_pessoa = cs.id_pessoa
	ORDER BY id_cliente, p.nome; 
ALTER TABLE v_quadro_social
  OWNER TO postgres;   


CREATE OR REPLACE VIEW v_socios AS 
	SELECT cs.id_clisoc, cs.id_cliente, cs.id_pessoa, vp.nome, cs.part_quotas, cs.part_valor, cs.part_percent, 
	vp.tipo, vp.cpf_cnpj, vp.ie_rg, vp.org_exp_rg, cs.n_tit_eleit, zona_t_eleit, vp.ccm, cs.org_classe, cs.num_classe, 
	cs.dt_nascim, sec.est_civil, vp.fantasia, sn.nacionalid, c.nome_cidade || ' - ' || e.uf as nome_cidade, cs.org_nirc, cs.filiacao, cs.num_nirc, 
	cs.data_nirc, cs.dt_admiss, cs.num_regist, cs.dt_regist, cs.soc_gerent, cs.resp_fiscal, cs.prolabore, 
	cs.val_prolab, cs.carne_inss, cs.num_inss, cs.faixa_inss, cs.dt_alt_faixa   
	FROM cliente_socio cs 
	INNER JOIN v_pessoa vp ON vp.id_pessoa = cs.id_pessoa 
	LEFT JOIN sis_estado_civil sec ON sec.id_estciv = cs.id_estciv 
	LEFT JOIN sis_nacionalidade sn ON sn.id_nacion = cs.id_nacion 
	LEFT JOIN cidade c ON c.id_cidade = cs.id_cidade 
	LEFT JOIN estado e ON e.id_estado = c.id_estado 
	ORDER BY cs.id_cliente, vp.nome; 
ALTER TABLE v_socios 
  OWNER TO postgres; 