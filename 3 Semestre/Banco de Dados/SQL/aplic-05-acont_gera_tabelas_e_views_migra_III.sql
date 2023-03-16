
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO III


INSERT INTO subtipo_pessoa (stipopessoa, sativo,id_tpessoa) VALUES ('EX-SÓCIO', TRUE, (SELECT id_tpessoa FROM tipo_pessoa WHERE tipopessoa = 'DIVERSOS'));
INSERT INTO subtipo_pessoa (stipopessoa, sativo,id_tpessoa) VALUES ('EX-REPRESENTANTE', TRUE, (SELECT id_tpessoa FROM tipo_pessoa WHERE tipopessoa = 'DIVERSOS'));


INSERT INTO tipo_pessoa (tipopessoa, ativo) VALUES ('REPRESENTANTE LEGAL',FALSE);


CREATE TABLE pessoa_replegal 
(
	id_preplg	SERIAL NOT NULL,
	id_pessoa	INTEGER REFERENCES pessoa (id_pessoa),
	n_tit_eleit	CHARACTER VARYING(20),
	zona_t_eleit	CHARACTER VARYING(6),
	org_classe	CHARACTER VARYING(20),
	num_classe	CHARACTER VARYING(20),
	dt_nascim	DATE,
	id_estciv	INTEGER,
	id_nacion	INTEGER REFERENCES sis_nacionalidade (id_nacion),
	id_cidade	INTEGER,
	filiacao	CHARACTER VARYING(120),
	PRIMARY KEY 	(id_preplg)
);
ALTER TABLE pessoa_replegal
  ADD CONSTRAINT "pessoa_replegal_evitar_repetição" UNIQUE(id_pessoa);
  

CREATE TABLE cliente_soc_replegal
(
	id_clirep	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_clisoc	INTEGER REFERENCES cliente_socio (id_clisoc),
	id_pessoa	INTEGER REFERENCES pessoa (id_pessoa),
	PRIMARY KEY 	(id_clirep)
);
ALTER TABLE cliente_soc_replegal
  ADD CONSTRAINT "cliente_soc_replegal_evitar_repetição" UNIQUE(id_cliente, id_clisoc, id_pessoa);

  
CREATE TABLE sis_periodicidade
(
	id_period	SERIAL NOT NULL,
	periodic	CHARACTER VARYING(20),
	formula		CHARACTER VARYING(30),
	PRIMARY KEY 	(id_period)
);
ALTER TABLE sis_periodicidade
  ADD CONSTRAINT "sis_periodicidade_evitar_repetição" UNIQUE(periodic);
--INSERT INTO sis_periodicidade (periodic, formula) VALUES ('QUINZENAL','');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('MENSAL','DATEADD;M;1');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('BIMESTRAL','DATEADD;M;2');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('TRIMESTRAL','DATEADD;M;3');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('SEMESTRAL','DATEADD;M;6');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('ANUAL','DATEADD;YYYY;1');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('VARIÁVEL','VAZIO');
INSERT INTO sis_periodicidade (periodic, formula) VALUES ('UDM','UDM');
--INSERT INTO sis_periodicidade (periodic, formula) VALUES ('MENSAL');


CREATE TABLE sis_imposto 
(
	id_impost	SERIAL NOT NULL,
	origem		CHARACTER (1),
	imposto		CHARACTER VARYING(50),
	periodic	INTEGER REFERENCES sis_periodicidade (id_period),
	dtvenc		CHARACTER VARYING(2),
	observ		TEXT,
	PRIMARY KEY 	(id_impost)
);
ALTER TABLE sis_imposto
  ADD CONSTRAINT "sis_imposto_evitar_repetição" UNIQUE(origem,imposto);


ALTER TABLE cliente 
ADD COLUMN n_contrat	CHARACTER VARYING(15),
ADD COLUMN dt_contrat	DATE, 
ADD COLUMN iduni_min	INTEGER REFERENCES unid_mon_brasil (id_unimon),
ADD COLUMN mens_inic	REAL,
ADD COLUMN iduni_mat	INTEGER REFERENCES unid_mon_brasil (id_unimon),
ADD COLUMN mens_atual	REAL,
ADD COLUMN desc_mens	REAL,
ADD COLUMN s_contabil	BOOLEAN DEFAULT false,
ADD COLUMN s_livcaixa	BOOLEAN DEFAULT false,
ADD COLUMN s_fiscal	BOOLEAN DEFAULT false,
ADD COLUMN s_rh		BOOLEAN DEFAULT false,
ADD COLUMN s_arqescr	BOOLEAN DEFAULT false,
ADD COLUMN s_visprof	BOOLEAN DEFAULT false,
ADD COLUMN s_remmboy	BOOLEAN DEFAULT false,
ADD COLUMN s_rememail	BOOLEAN DEFAULT false,
ADD COLUMN s_remsite	BOOLEAN DEFAULT false,
ADD COLUMN dt_encerr	DATE;


CREATE TABLE cliente_alt_mensalidade 
(
	id_climen	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	dt_ini_val	DATE,
	dt_fim_val	DATE,
	id_unimon	INTEGER REFERENCES unid_mon_brasil (id_unimon),
	valor		REAL,
	PRIMARY KEY 	(id_climen)
);
ALTER TABLE cliente_alt_mensalidade
  ADD CONSTRAINT "cliente_alt_mensalidade_evitar_repetição" UNIQUE(id_cliente, dt_ini_val, dt_fim_val);


CREATE TABLE cliente_imposto 
(
	id_cliimp	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_impost	INTEGER REFERENCES sis_imposto (id_impost),
	prox_dt_ven	DATE,
	ult_valor	REAL,
	validacao	BOOLEAN DEFAULT false,
	PRIMARY KEY 	(id_cliimp)
);
ALTER TABLE cliente_imposto
  ADD CONSTRAINT "cliente_imposto_evitar_repetição" UNIQUE(id_cliente, id_impost, prox_dt_ven);


CREATE TABLE cliente_hist_imposto 
(
	id_clihim	SERIAL NOT NULL,
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_impost	INTEGER REFERENCES sis_imposto (id_impost),
	dt_vencido	DATE,
	valor		REAL,
	PRIMARY KEY 	(id_clihim)
);


CREATE TABLE sis_departamento 
(
	id_depart	SERIAL NOT NULL,
	departamento	CHARACTER VARYING(20),
	ap_depto	CHARACTER VARYING(1),
PRIMARY KEY 	(id_depart)
);
ALTER TABLE sis_departamento
  ADD CONSTRAINT "sis_departamento_evitar_repetição" UNIQUE(departamento, ap_depto);


CREATE TABLE sis_cargo 
(
	id_cargoc	SERIAL NOT NULL,
	cargo		CHARACTER VARYING(20),
	PRIMARY KEY 	(id_cargoc)
);
ALTER TABLE sis_cargo
  ADD CONSTRAINT "sis_cargo_evitar_repetição" UNIQUE(cargo);


CREATE TABLE ct_funcionario 
(
	id_funcio	SERIAL NOT NULL,
	id_usuario	INTEGER REFERENCES usuario (id_usuario),
	nome_compl	CHARACTER VARYING(60),
	id_depart	INTEGER REFERENCES sis_departamento (id_depart),
	id_cargoc	INTEGER REFERENCES sis_cargo (id_cargoc),
	dt_admiss	DATE,
	dt_demiss	DATE,
	salario		REAL,
	PRIMARY KEY 	(id_funcio)
);
ALTER TABLE ct_funcionario
  ADD CONSTRAINT "ct_funcionario_evitar_repetição" UNIQUE(id_usuario, nome_compl, id_depart, id_cargoc);


CREATE TABLE sis_ct_categoria 
(
	id_catego	SERIAL NOT NULL,
	categoria	CHARACTER VARYING(25),
	PRIMARY KEY 	(id_catego)
);
ALTER TABLE sis_ct_categoria
  ADD CONSTRAINT "sis_ct_categoria_evitar_repetição" UNIQUE(categoria);


CREATE TABLE sis_ct_ocupacao 
(
	id_ocupac	SERIAL NOT NULL,
	ocupacao	CHARACTER VARYING(35),
	cliente		BOOLEAN DEFAULT false,
	periodo		BOOLEAN DEFAULT false,
	id_catego	INTEGER REFERENCES sis_ct_categoria (id_catego),
	PRIMARY KEY 	(id_ocupac)
);
ALTER TABLE sis_ct_ocupacao
  ADD CONSTRAINT "sis_ct_ocupacao_evitar_repetição" UNIQUE(ocupacao);


CREATE TABLE ct_tarefa 
(
	id_tarefa	SERIAL NOT NULL,
	id_funcio	INTEGER REFERENCES ct_funcionario (id_funcio),
	id_ocupac	INTEGER REFERENCES sis_ct_ocupacao (id_ocupac),
	id_cliente	INTEGER,
	mesini_pc	CHARACTER VARYING(3),
	anoini_pc	CHARACTER VARYING(2),
	mesfin_pc	CHARACTER VARYING(3),
	anofin_pc	CHARACTER VARYING(2),
	data_tar	DATE,
	hr_inic		TIME,
	duracao		TIME,
	PRIMARY KEY 	(id_tarefa)
);
ALTER TABLE ct_tarefa
  ADD CONSTRAINT "ct_tarefa_evitar_repetição" UNIQUE(id_funcio, id_ocupac, data_tar, hr_inic, duracao);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_repr_legal AS 
	SELECT csr.id_clirep, csr.id_cliente, csr.id_clisoc, csr.id_pessoa, vp.nome, 
	vp.tipo, vp.cpf_cnpj, vp.ie_rg, vp.org_exp_rg, pr.n_tit_eleit, 
	pr.zona_t_eleit, pr.org_classe, pr.num_classe, pr.dt_nascim, 
	sec.est_civil, sn.nacionalid, vc.cidade, pr.filiacao, pr.id_preplg 
	FROM cliente_soc_replegal csr 
	INNER JOIN v_pessoa vp ON vp.id_pessoa = csr.id_pessoa
	INNER JOIN pessoa_replegal pr ON pr.id_pessoa = csr.id_pessoa
	LEFT JOIN sis_estado_civil sec ON sec.id_estciv = pr.id_estciv
	LEFT JOIN sis_nacionalidade sn ON sn.id_nacion = pr.id_nacion
	LEFT JOIN v_cidest vc ON vc.id_cidade = pr.id_cidade
	ORDER BY nome;
ALTER TABLE v_repr_legal
  OWNER TO postgres; 	


CREATE OR REPLACE VIEW v_imposto AS 
	SELECT si.id_impost, si.origem, si.imposto, sp.periodic, si.dtvenc, si.observ 
	FROM sis_imposto si 
	INNER JOIN sis_periodicidade sp ON sp.id_period = si.periodic 
	ORDER BY si.imposto;
ALTER TABLE v_imposto
  OWNER TO postgres; 	


DROP VIEW v_cliente CASCADE;
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
	umb.unimon, cl.cap_ini, cl.dt_as_cap, cl.dt_rg_cap, cl.obj_social, cl.ger_social, cl.prolabore, cl.dist_lucro, 
	cl.n_contrat, cl.dt_contrat, umb1.unimon as unimin, cl.mens_inic, umb2.unimon as unimat, cl.mens_atual, cl.desc_mens, 
	cl.s_contabil, cl.s_livcaixa, cl.s_fiscal, cl.s_rh, cl.s_arqescr, cl.s_visprof, cl.s_remmboy, cl.s_rememail, 
	cl.s_remsite, cl.dt_encerr, cl.mens_atual - cl.desc_mens as liq_mens  
	FROM pessoa p 
	INNER JOIN sis_pessoa sp ON sp.id_sis_pessoa = p.nat_pessoa
	INNER JOIN cidade c ON c.id_cidade = p.id_cidade 
	INNER JOIN estado e ON e.id_estado = c.id_estado 
	INNER JOIN cliente cl ON cl.id_pessoa = p.id_pessoa
	INNER JOIN cliente_status st ON st.id_clista = cl.id_clista
	LEFT JOIN unid_mon_brasil umb ON umb.id_unimon = cl.id_unimon
	LEFT JOIN unid_mon_brasil umb1 ON umb1.id_unimon = cl.iduni_min
	LEFT JOIN unid_mon_brasil umb2 ON umb2.id_unimon = cl.iduni_mat
	ORDER BY cl.codcli;
ALTER TABLE v_cliente
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_cli_mensalidade AS 
	SELECT id_climen, id_cliente, dt_ini_val, dt_fim_val, 
	unimon || ' ' || TO_CHAR(valor,'FM99999999999990D00') AS mensa 
	FROM cliente_alt_mensalidade cam
	INNER JOIN unid_mon_brasil umb ON umb.id_unimon = cam.id_unimon
	ORDER BY dt_ini_val DESC;
ALTER TABLE v_cli_mensalidade 
  OWNER TO postgres;	


CREATE OR REPLACE VIEW v_cli_imposto AS 
	SELECT ci.id_cliimp, ci.id_cliente, ci.id_impost, si.imposto, 
	ci.prox_dt_ven, ci.ult_valor, si.origem, si.dtvenc, sp.periodic,
	ci.validacao 
	FROM cliente_imposto ci
	INNER JOIN sis_imposto si ON si.id_impost = ci.id_impost 
	INNER JOIN sis_periodicidade sp ON sp.id_period = si.periodic
	ORDER BY ci.prox_dt_ven, si.imposto;
ALTER TABLE v_cli_imposto 
  OWNER TO postgres;	


CREATE OR REPLACE VIEW v_funcionario AS 
	SELECT cf.id_funcio, u.nome, cf.nome_compl, sd.departamento, 
	sc.cargo, cf.dt_admiss, cf.dt_demiss, cf.salario 
	FROM ct_funcionario cf
	INNER JOIN usuario u ON u.id_usuario = cf.id_usuario
	INNER JOIN sis_departamento sd ON sd.id_depart = cf.id_depart
	INNER JOIN sis_cargo sc ON sc.id_cargoc = cf.id_cargoc
	ORDER BY u.nome;
ALTER TABLE v_funcionario 
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_ocupacao AS 
	SELECT id_ocupac, ocupacao, cliente, periodo, categoria 
	FROM sis_ct_ocupacao o 
	INNER JOIN sis_ct_categoria c ON c.id_catego = o.id_catego
	ORDER BY ocupacao;
ALTER TABLE v_ocupacao
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_quadrotarefa AS
	SELECT id_tarefa, id_funcio, data_tar, hr_inic, duracao, hr_inic::interval + duracao::interval as hr_fin, ocupacao, fantasia, 
	CASE WHEN mesini_pc <> '' THEN '(' || mesini_pc || anoini_pc || '-' || mesfin_pc || anofin_pc || ')' 
	ELSE ''
	END AS periodo, to_char(hr_inic,'hh24:mi') || ' - ' || to_char(hr_inic::interval + duracao::interval, 'hh24:mi') AS tempo 
	FROM ct_tarefa t
	INNER JOIN sis_ct_ocupacao o ON o.id_ocupac = t.id_ocupac
	LEFT JOIN cliente c ON c.id_cliente = t.id_cliente 
	LEFT JOIN pessoa p ON p.id_pessoa = c.id_pessoa
	ORDER BY data_tar, hr_inic;
ALTER TABLE v_quadrotarefa
  OWNER TO postgres;

