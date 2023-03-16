
--***************************************************************************************************************************************

-- Criação das Tabelas - MIGRAÇÃO I

CREATE TABLE usuario
(
  id_usuario serial NOT NULL,
  nome CHARACTER VARYING(20) NOT NULL UNIQUE,
  senha CHARACTER VARYING(64) NOT NULL,
  operacional BOOLEAN,
  sistot BOOLEAN DEFAULT false,
  siscst BOOLEAN DEFAULT false,
  sislsr BOOLEAN DEFAULT false,
  cadtot BOOLEAN DEFAULT false,
  cadcon BOOLEAN DEFAULT false,
  cadsem BOOLEAN DEFAULT false,
  usutot BOOLEAN DEFAULT false,
  usucon BOOLEAN DEFAULT false,
  ususem BOOLEAN DEFAULT false,
  admtot BOOLEAN DEFAULT false,
  admcon BOOLEAN DEFAULT false,
  admsem BOOLEAN DEFAULT false,
  mentot BOOLEAN DEFAULT false,
  mencon BOOLEAN DEFAULT false,
  mensem BOOLEAN DEFAULT false,
  raztot BOOLEAN DEFAULT false,
  razcon BOOLEAN DEFAULT false,
  razsem BOOLEAN DEFAULT false,
  csetot BOOLEAN DEFAULT false,
  csecon BOOLEAN DEFAULT false,
  csesem BOOLEAN DEFAULT false,
  exptot BOOLEAN DEFAULT false,
  expcon BOOLEAN DEFAULT false,
  expsem BOOLEAN DEFAULT false,
  agetot BOOLEAN DEFAULT false,
  agecon BOOLEAN DEFAULT false,
  agesem BOOLEAN DEFAULT false,
  tipusu CHARACTER VARYING(8),  
  dtasen DATE,
  acesso CHARACTER VARYING(9), 
  PRIMARY KEY (id_usuario)
);
INSERT INTO usuario
(nome, senha, operacional, sistot, cadtot, usutot, admtot, mentot, raztot, csetot, exptot, agetot, tipusu, dtasen, acesso) 
VALUES 
('ADMINISTRADOR', 'Wrs+eszUJrD8+uqX0lVm0PQ+6rcLYgdEB9gI0S9wOCs=', TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, 'ADMIN', 'now', '333333333');


CREATE TABLE sis_logradouro
(
  id_sis_lograd 	serial 	NOT NULL,
  logradouro		CHARACTER VARYING(13),
  PRIMARY KEY (id_sis_lograd)
);
INSERT INTO sis_logradouro (logradouro) VALUES ('AEROPORTO');
INSERT INTO sis_logradouro (logradouro) VALUES ('ALAMEDA');
INSERT INTO sis_logradouro (logradouro) VALUES ('AVENIDA');
INSERT INTO sis_logradouro (logradouro) VALUES ('CALÇADA');
INSERT INTO sis_logradouro (logradouro) VALUES ('CHÁCARA');
INSERT INTO sis_logradouro (logradouro) VALUES ('CONDOMÍNIO');
INSERT INTO sis_logradouro (logradouro) VALUES ('CONJUNTO');
INSERT INTO sis_logradouro (logradouro) VALUES ('DISTRITO');
INSERT INTO sis_logradouro (logradouro) VALUES ('ESPLANADA');
INSERT INTO sis_logradouro (logradouro) VALUES ('ESTRADA');
INSERT INTO sis_logradouro (logradouro) VALUES ('LADEIRA');
INSERT INTO sis_logradouro (logradouro) VALUES ('LARGO');
INSERT INTO sis_logradouro (logradouro) VALUES ('PRAÇA');
INSERT INTO sis_logradouro (logradouro) VALUES ('QUADRA');
INSERT INTO sis_logradouro (logradouro) VALUES ('RECANTO');
INSERT INTO sis_logradouro (logradouro) VALUES ('RESIDENCIAL');
INSERT INTO sis_logradouro (logradouro) VALUES ('RODOVIA');
INSERT INTO sis_logradouro (logradouro) VALUES ('RUA');
INSERT INTO sis_logradouro (logradouro) VALUES ('SETOR');
INSERT INTO sis_logradouro (logradouro) VALUES ('SÍTIO');
INSERT INTO sis_logradouro (logradouro) VALUES ('TRAVESSA');
INSERT INTO sis_logradouro (logradouro) VALUES ('VEREDA');
INSERT INTO sis_logradouro (logradouro) VALUES ('VIADUTO');
INSERT INTO sis_logradouro (logradouro) VALUES ('VIELA');


CREATE TABLE sis_parametro 
(
id_sis_parametro 	serial 	NOT NULL,
min_usua 		int2 	default 6,
max_usua 		int2 	default 15,
min_senha 		int2 	default 6,
max_senha 		int2 	default 15, 
dias_senha 		int2 	default 0,
repete_senha 		BOOLEAN default true,
val_cnpjcpf_pessoa	BOOLEAN default true,
act_cnpjcpf_pes_vazio	BOOLEAN default true,
val_cnpjcpf_cli		BOOLEAN default true,
act_cnpjcpf_cli_vazio	BOOLEAN default true,
cli_com_end		BOOLEAN default true,
codcli_livre		INTEGER, 
PRIMARY KEY (id_sis_parametro)
);
INSERT INTO sis_parametro (min_usua, max_usua, min_senha, max_senha, dias_senha, repete_senha, val_cnpjcpf_pessoa, act_cnpjcpf_pes_vazio, 
			   val_cnpjcpf_cli, act_cnpjcpf_cli_vazio, cli_com_end, codcli_livre) 
			   VALUES (6, 15, 7, 12, 0, TRUE, FALSE, TRUE, TRUE, FALSE, TRUE,0);


CREATE TABLE sis_pessoa
(
  id_sis_pessoa 	serial 	NOT NULL,
  tipo 			character varying(8),
  PRIMARY KEY (id_sis_pessoa)
);
INSERT INTO sis_pessoa (tipo) VALUES ('FÍSICA');
INSERT INTO sis_pessoa (tipo) VALUES ('JURÍDICA');


CREATE TABLE sis_tipo_endereço
(
  id_sis_tip_end 	serial 	NOT NULL,
  tipo_end		CHARACTER VARYING(20),
  PRIMARY KEY (id_sis_tip_end)
);
INSERT INTO sis_tipo_endereço (tipo_end) VALUES ('PRINCIPAL');
INSERT INTO sis_tipo_endereço (tipo_end) VALUES ('CORRESPONDÊNCIA');
INSERT INTO sis_tipo_endereço (tipo_end) VALUES ('COBRANÇA');


CREATE TABLE sis_tipo_telefone
(
  id_sis_tip_tel 	serial 	NOT NULL,
  tipo_fone		CHARACTER VARYING(15),
  PRIMARY KEY (id_sis_tip_tel)
);
INSERT INTO sis_tipo_telefone (tipo_fone) VALUES ('FIXO');
INSERT INTO sis_tipo_telefone (tipo_fone) VALUES ('CELULAR');
INSERT INTO sis_tipo_telefone (tipo_fone) VALUES ('FAX');


CREATE TABLE pessoa
(
  id_pessoa 	serial NOT NULL,
  ativo		BOOLEAN, 
  codigo 	serial NOT NULL UNIQUE,
  nome 		CHARACTER VARYING(100) NOT NULL UNIQUE,
  nat_pessoa 	INTEGER REFERENCES sis_pessoa (id_sis_pessoa),
  id_cidade	INTEGER REFERENCES cidade (id_cidade),
  fantasia 	CHARACTER VARYING(60),
  cnpj_cpf 	CHARACTER VARYING(14),
  ie_rg 	CHARACTER VARYING(18),
  org_exp_rg	CHARACTER VARYING(15), 
  ccm 		CHARACTER VARYING(15),
  site 		CHARACTER VARYING(80),
  observ 	text,
  PRIMARY KEY (id_pessoa)
);


CREATE TABLE tipo_pessoa
(
  id_tpessoa		serial NOT NULL,
  tipopessoa		CHARACTER VARYING(50) NOT NULL,
  comentario 		CHARACTER VARYING(60),
  ativo			BOOLEAN,
  PRIMARY KEY (id_tpessoa)
);
ALTER TABLE tipo_pessoa
  ADD CONSTRAINT "tipo_pessoa_evitar_repetição" UNIQUE(tipopessoa);


CREATE TABLE classe_pessoa
(
  id_clapes 	serial NOT NULL,
  ativo		BOOLEAN, 
  id_pessoa	INTEGER NOT NULL REFERENCES pessoa (id_pessoa),
  id_tpessoa 	INTEGER NOT NULL REFERENCES tipo_pessoa (id_tpessoa),
  id_stpessoa 	INTEGER,
  dt_ini 	DATE,
  dt_fim	DATE,
  PRIMARY KEY (id_clapes)
);
ALTER TABLE classe_pessoa
  ADD CONSTRAINT "classe_pessoa_evitar_repetição" UNIQUE(id_pessoa, id_tpessoa);


CREATE TABLE subtipo_pessoa
(
  id_stpessoa		serial NOT NULL,
  stipopessoa		CHARACTER VARYING(30) NOT NULL,
  scomentario 		CHARACTER VARYING(60),
  sativo		BOOLEAN,
  id_tpessoa		INTEGER REFERENCES tipo_pessoa (id_tpessoa),
  PRIMARY KEY (id_stpessoa)
);
ALTER TABLE subtipo_pessoa
  ADD CONSTRAINT "subtipo_pessoa_evitar_repetição" UNIQUE(stipopessoa, id_tpessoa);


CREATE TABLE email
(
  id_email		serial NOT NULL,
  id_pessoa		INTEGER REFERENCES pessoa (id_pessoa),
  email 		CHARACTER VARYING(65) NOT NULL,
  contato		CHARACTER VARYING(30),
  departamento		CHARACTER VARYING(30),
  PRIMARY KEY (id_email)
);
ALTER TABLE email
  ADD CONSTRAINT "email_evitar_repetição" UNIQUE(id_pessoa, email, contato);


CREATE TABLE endereço
(
  id_endereço		serial NOT NULL,
  id_pessoa		INTEGER REFERENCES pessoa (id_pessoa),
  id_sis_tip_end	INTEGER REFERENCES sis_tipo_endereço (id_sis_tip_end),
  cep	 		CHARACTER VARYING(8) NOT NULL,
  id_sis_lograd		INTEGER REFERENCES sis_logradouro (id_sis_lograd),
  nome_lograd 		CHARACTER VARYING(80),
  numero		CHARACTER VARYING(10),
  complemento 		CHARACTER VARYING(60),
  bairro 		CHARACTER VARYING(50),
  id_cidade 		INTEGER REFERENCES cidade (id_cidade),
  fone			CHARACTER VARYING(18), 
  PRIMARY KEY (id_endereço)
);
ALTER TABLE "endereço"
  ADD CONSTRAINT endereço_evitar_repetição UNIQUE(id_pessoa, cep, id_sis_lograd, nome_lograd, numero, complemento, bairro, id_cidade);
ALTER TABLE "endereço"
  ADD CONSTRAINT endereço_evitar_repetição_tipo UNIQUE(id_pessoa, id_sis_tip_end);  


CREATE TABLE telefone
(
  id_telefone		serial NOT NULL,
  id_pessoa		INTEGER NOT NULL REFERENCES pessoa (id_pessoa),
  id_sis_tip_tel	INTEGER NOT NULL REFERENCES sis_tipo_telefone (id_sis_tip_tel),
  num_fone 		CHARACTER VARYING(18) NOT NULL,
  contato		CHARACTER VARYING(30),
  PRIMARY KEY (id_telefone)
);
ALTER TABLE "telefone"
  ADD CONSTRAINT telefone_evitar_repetição UNIQUE(id_pessoa, id_sis_tip_tel, num_fone, contato);


CREATE TABLE cliente
(
  id_cliente	serial NOT NULL,
  id_pessoa 	INTEGER NOT NULL UNIQUE REFERENCES pessoa (id_pessoa), 
  codcli	INTEGER NOT NULL UNIQUE,
  PRIMARY KEY 	(id_cliente)
);


CREATE TABLE p_planocontas
(
  id_plancon	serial NOT NULL,
  ctacompleta 	CHARACTER VARYING(16) NOT NULL UNIQUE, 
  ctareduzida	CHARACTER VARYING(7) NOT NULL UNIQUE,
  grau		int2,
  plan_conta	CHARACTER VARYING(40) NOT NULL,
  PRIMARY KEY 	(id_plancon)
);


CREATE TABLE p_reembolso
(
  id_reembol	serial NOT NULL,
  codigore 	INTEGER NOT NULL UNIQUE, 
  reembolso	CHARACTER VARYING(50) NOT NULL UNIQUE,
  id_histpad	INTEGER,
  PRIMARY KEY 	(id_reembol)
);


CREATE TABLE p_contacorresp
(
  id_ctacor	serial NOT NULL,
  contacorr	CHARACTER VARYING(30) NOT NULL UNIQUE,
  PRIMARY KEY 	(id_ctacor)
);


CREATE TABLE p_historicopadrao
(
  id_histpad	serial NOT NULL,
  c98CdInt 	INTEGER,
  codigohp 	INTEGER NOT NULL UNIQUE,
  hist_padrao	CHARACTER VARYING(40),
  id_reembol 	INTEGER,
  id_ctacor 	INTEGER REFERENCES p_contacorresp (id_ctacor),
  id_cdebito 	INTEGER REFERENCES p_planocontas (id_plancon),
  id_ccredito 	INTEGER REFERENCES p_planocontas (id_plancon),
  PRIMARY KEY 	(id_histpad)
);


CREATE TABLE p_serviçoextra 
(
  id_srvext	serial NOT NULL,
  codigose	INTEGER NOT NULL UNIQUE,
  servextra	CHARACTER VARYING(50) UNIQUE,
  id_histpad	INTEGER,
  valorse	REAL,
  PRIMARY KEY	(id_srvext)
);


CREATE TABLE p_reembolso_os
(
  id_rmb_os	serial NOT NULL,
  cdgre_os 	INTEGER NOT NULL UNIQUE, 
  reembol_os	CHARACTER VARYING(50) NOT NULL UNIQUE,
  id_histpad	INTEGER,
  PRIMARY KEY 	(id_rmb_os)
);


CREATE TABLE p_serviços_os
(
  id_serv_os	serial NOT NULL,
  cdgse_os	INTEGER NOT NULL UNIQUE,
  servico_os	CHARACTER VARYING(50) UNIQUE,
  vlrse_os	REAL,
  id_histpad	INTEGER,
  PRIMARY KEY	(id_serv_os)
);


CREATE TABLE zlog_migração
(
  id_log_mig	serial NOT NULL,
  erro_mig	CHARACTER VARYING(250),
  data_mig	DATE,
  prioritario	CHARACTER VARYING(3),
  PRIMARY KEY	(id_log_mig)
);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_cidest AS 
	select c.id_cidade, c.nome_cidade || ' - ' || e.uf as Cidade , nome_pais , uf, c.nome_cidade, nome_estado 
	from cidade c 
	inner join estado e on e.id_estado = c.id_estado 
	inner join pais p on p.id_pais = e.id_pais 
	order by nome_cidade, uf;
ALTER TABLE v_cidest
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_classepessoa AS 
	SELECT cp.id_clapes, cp.id_pessoa, tp.tipopessoa, stp.stipopessoa, cp.dt_ini, tp.id_tpessoa
	FROM classe_pessoa cp
	JOIN tipo_pessoa tp ON tp.id_tpessoa = cp.id_tpessoa 
	LEFT JOIN subtipo_pessoa stp ON stp.id_stpessoa = cp.id_stpessoa 
	ORDER BY tp.id_tpessoa, stp.stipopessoa;
ALTER TABLE v_classepessoa
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_endereco AS 
	select e.id_pessoa, ste.tipo_end as Tipo, 
	substring(e.cep from 1 for 2) || '.' || substring(e.cep from 3 for 3) || '-' || substring(e.cep from 6 for 3) as CEP, 
	trim(sl.logradouro) as logr, e.nome_lograd as Logradouro, e.numero as Número, e.complemento as Complemento, e.bairro as Bairro, 
	c.nome_cidade || ' - ' || es.uf as Cidade, p.nome_pais as País, e.fone as Telefone, e.id_endereço 
	from endereço e 
	inner join sis_tipo_endereço ste on ste.id_sis_tip_end = e.id_sis_tip_end 
	inner join sis_logradouro sl on sl.id_sis_lograd = e.id_sis_lograd
	inner join cidade c on c.id_cidade = e.id_cidade 
	inner join estado es on es.id_estado = c.id_estado 
	inner join pais p on es.id_pais = p.id_pais 
	order by ste.id_sis_tip_end;
ALTER TABLE v_endereco
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_historicopadrao AS 
	select hp.id_histpad, hp.c98cdint, hp.codigohp, hp.hist_padrao, rb.codigore as reembolso, 
	cc.contacorr, pc.ctareduzida as cdebito, pc1.ctareduzida as ccredito, 
	cast(hp.codigohp as character(5)) as pesqhp, cast(rb.codigore as character(5)) as pesqre, 
	left(pc.ctareduzida,5)||right(pc.ctareduzida,1) as pesqdeb,  
	left(pc1.ctareduzida,5)||right(pc1.ctareduzida,1) as pesqcred  
	from p_historicopadrao hp 
	left join p_reembolso rb on rb.id_reembol = hp.id_reembol 
	inner join p_contacorresp cc on cc.id_ctacor = hp.id_ctacor 
	inner join p_planocontas pc on pc.id_plancon = hp.id_cdebito 
	inner join p_planocontas pc1 on pc1.id_plancon = hp.id_ccredito 
	order by hp.codigohp;
ALTER TABLE v_historicopadrao
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_pessoa AS 
	SELECT p.id_pessoa, p.ativo, p.codigo, p.nome, p.nat_pessoa, sp.tipo, 
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
	p.ie_rg, p.org_exp_rg, p.ccm, p.site, p.observ
	FROM pessoa p 
	inner join sis_pessoa sp on sp.id_sis_pessoa = p.nat_pessoa
	inner join cidade c on c.id_cidade = p.id_cidade 
	inner join estado e on e.id_estado = c.id_estado 
	ORDER BY p.codigo;
ALTER TABLE v_pessoa
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_planocontas AS 
	select *, cast(grau as character(1)) as pesqgr,
	left(ctareduzida,5) || right(ctareduzida,1) as pesqct 
	from p_planocontas order by ctacompleta;
ALTER TABLE v_planocontas
  OWNER TO postgres;  


CREATE OR REPLACE VIEW v_reembolso AS 
	select rb.id_reembol, rb.codigore, rb.reembolso, hp.codigohp,
	cast(rb.codigore as character(5)) as pesqre, cast(hp.codigohp as character(5)) as pesqhp
	from p_reembolso rb left join p_historicopadrao hp on hp.id_histpad = rb.id_histpad 
	order by rb.codigore;
ALTER TABLE v_reembolso
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_reembolso_os AS 
	select rb.id_rmb_os, rb.cdgre_os, rb.reembol_os, hp.codigohp,
	cast(rb.cdgre_os as character(5)) as pesqre, cast(hp.codigohp as character(5)) as pesqhp
	from p_reembolso_os rb left join p_historicopadrao hp on hp.id_histpad = rb.id_histpad 
	order by rb.cdgre_os;
ALTER TABLE v_reembolso_os
  OWNER TO postgres;  


CREATE OR REPLACE VIEW v_serviçoextra AS 
	select se.id_srvext, se.codigose, se.servextra, hp.codigohp, se.valorse, 
	cast(se.codigose as character(5)) as pesqse, cast(hp.codigohp as character(5)) as pesqhp, 
	cast(se.valorse as character(15)) as pesqvl 
	from p_serviçoextra se left join p_historicopadrao hp on hp.id_histpad = se.id_histpad 
	order by se.codigose;
ALTER TABLE v_serviçoextra
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_serviços_os AS 
	select se.id_serv_os, se.cdgse_os, se.servico_os, hp.codigohp, se.vlrse_os, 
	cast(se.cdgse_os as character(5)) as pesqse, cast(hp.codigohp as character(5)) as pesqhp, 
	cast(se.vlrse_os as character(15)) as pesqvl 
	from p_serviços_os se left join p_historicopadrao hp on hp.id_histpad = se.id_histpad 
	order by se.cdgse_os;
ALTER TABLE v_serviços_os
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_telefone AS 
	select t.id_pessoa, st.tipo_fone, t.num_fone, t.contato, id_telefone, 
	CASE 
	WHEN SUBSTRING(t.num_fone,6,1) = ' ' THEN SUBSTRING(t.num_fone,7,4) || SUBSTRING(t.num_fone,12,4)  
	ELSE SUBSTRING(t.num_fone,6,5) || SUBSTRING(t.num_fone,12,4)  
	END as fpesq 
	from telefone t 
	inner join sis_tipo_telefone st on st.id_sis_tip_tel = t.id_sis_tip_tel 
	order by t.id_sis_tip_tel, t.num_fone, t.contato; 
ALTER TABLE v_endereco
  OWNER TO postgres;


CREATE OR REPLACE VIEW v_agenda AS 
	SELECT p.id_pessoa, p.codigo, p.nome, sp.tipo, tp.tipopessoa, stp.stipopessoa,
	CASE 
	WHEN stp.stipopessoa <> '' THEN tp.tipopessoa || ' / ' || stp.stipopessoa
	ELSE tp.tipopessoa
	END as classe
	FROM pessoa p
	JOIN sis_pessoa sp ON sp.id_sis_pessoa = p.nat_pessoa
	JOIN classe_pessoa cp ON cp.id_pessoa = p.id_pessoa
	JOIN tipo_pessoa tp ON tp.id_tpessoa = cp.id_tpessoa
	LEFT JOIN subtipo_pessoa stp ON stp.id_stpessoa = cp.id_stpessoa 
	WHERE p.ativo = true AND cp.ativo = true
	ORDER BY p.nome, tp.tipopessoa;
ALTER TABLE v_agenda
  OWNER TO postgres;


