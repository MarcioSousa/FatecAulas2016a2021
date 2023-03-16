
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XXI


--DROP TABLE adm_creceber;
CREATE TABLE adm_creceber 
(
	id_creceb	SERIAL NOT NULL UNIQUE,
	tipoconta	INT2, --0(serviço extra)  1(reembolso)
	id_cliente	INTEGER REFERENCES cliente (id_cliente),
	id_cadtos	INTEGER, --UF(link com a tabela ordem de serviço)
	id_srvree	INTEGER,
	datalan		DATE,
	id_histpad	INTEGER,
	historico	CHARACTER VARYING(80),
	valor_lan	NUMERIC(15,2),
	faturado	BOOLEAN,
	id_detban	INTEGER, --UF(link com a tabela detbanco)
	id_fatura	INTEGER, --UF(link com a tabela de faturamento)
	c92cdint	INTEGER,
	c92os		CHARACTER VARYING(7),
	PRIMARY KEY 	(id_creceb)
);
ALTER TABLE adm_creceber ADD CONSTRAINT "adm_creceber_evitar_repetição" UNIQUE(tipoconta, id_cliente, id_cadtos, id_srvree, datalan, id_histpad, historico, valor_lan, c92cdint);


--DROP TABLE adm_banco CASCADE;
CREATE TABLE adm_banco
(
	id_bancor	SERIAL NOT NULL UNIQUE,
	registro	INTEGER,
	tipo_lan	SMALLINT, --  1-Cheque  /  2-Deposito  /  3-Aviso de Credito  /  4-Aviso de Debito
	id_ctaban	INTEGER REFERENCES p_ctabancaria (id_ctaban),
	historico	CHARACTER VARYING(30),
	documento	CHARACTER VARYING(12),
	data_lan	DATE,
	valor_lan	NUMERIC(15,2),
	nominal_a	CHARACTER VARYING(120),
	solicitante	CHARACTER VARYING(20),
	impresso 	BOOLEAN DEFAULT FALSE,
	selecao_imp 	BOOLEAN DEFAULT FALSE,
	cheque_imp	BOOLEAN DEFAULT FALSE,
	val_extenso 	CHARACTER VARYING(200),
	tot_detalhe	SMALLINT,
	c90cdint	INTEGER, 
	PRIMARY KEY(id_bancor)
);
ALTER TABLE adm_banco ADD CONSTRAINT "adm_banco_evitar_repetição" UNIQUE(registro);


--DROP TABLE adm_bancodet;
CREATE TABLE adm_bancodet
(
	id_detban	SERIAL NOT NULL UNIQUE,
	id_bancor	INTEGER REFERENCES adm_banco (id_bancor),
	id_histpad	INTEGER REFERENCES p_historicopadrao (id_histpad),
	id_cliente	INTEGER,
	id_cadtos	INTEGER,
	documento	CHARACTER VARYING(12),
	historico	CHARACTER VARYING(80),
	id_reembol	INTEGER,
	valor_det	NUMERIC(15,2),
	conta_det	SMALLINT,
	ultimo_det	BOOLEAN DEFAULT FALSE,
	faturado 	BOOLEAN DEFAULT FALSE,
	id_fatura	INTEGER, --UF(link com a tabela de faturamento)
	id_ccusto	INTEGER, --UF(link com a tabela de centro de custo)
	c91cdint	INTEGER,
	PRIMARY KEY(id_detban)
);
ALTER TABLE adm_bancodet ADD CONSTRAINT "adm_bancodet_evitar_repetição" UNIQUE(id_bancor, id_histpad, id_cliente, id_cadtos, documento, historico, id_reembol, valor_det, conta_det);


ALTER TABLE sis_parametro ADD num_reg_banco INTEGER;
ALTER TABLE sis_parametro ADD num_nota_s INTEGER;
ALTER TABLE sis_parametro ADD num_nota_n INTEGER;
UPDATE sis_parametro SET num_nota_s = 10, num_nota_n = 100 WHERE id_sis_parametro = 1;


--DROP TABLE adm_fatur_exec;
CREATE TABLE adm_fatur_exec
(
	id_fatexc	SERIAL NOT NULL UNIQUE,
	mesfatura	INT2,
	anofatura	INT2,
	datagera	DATE,
	operfatura	INTEGER,
	integral	BOOLEAN DEFAULT FALSE,
	totmensa_s	NUMERIC(14,2),
	totdesco_s	NUMERIC(14,2),
	totsextr_s	NUMERIC(14,2),
	totreemb_s	NUMERIC(14,2),
	totpgcon_s	NUMERIC(14,2),
	totirrf_s	NUMERIC(14,2),
	totcofin_s	NUMERIC(14,2),
	totcsll_s	NUMERIC(14,2),
	totpis_s	NUMERIC(14,2),
	totmensa_n	NUMERIC(14,2),
	totdesco_n	NUMERIC(14,2),
	totsextr_n	NUMERIC(14,2),
	totreemb_n	NUMERIC(14,2),
	totpgcon_n	NUMERIC(14,2),
	totirrf_n	NUMERIC(14,2),
	totcofin_n	NUMERIC(14,2),
	totcsll_n	NUMERIC(14,2),
	totpis_n	NUMERIC(14,2),
	nclien_s	INTEGER,
	nclien_n	INTEGER,
	PRIMARY KEY(id_fatexc)
);
ALTER TABLE adm_fatur_exec ADD identif TIMESTAMP;
INSERT INTO adm_fatur_exec (mesfatura, anofatura, datagera, integral) VALUES (1,2014,'2014-01-20', TRUE);
INSERT INTO adm_fatur_exec (mesfatura, anofatura, datagera, integral) VALUES (2,2014,'2014-02-20', TRUE);


ALTER TABLE cliente ALTER mens_atual TYPE NUMERIC(14,2);
ALTER TABLE cliente ALTER desc_mens TYPE NUMERIC(14,2);


--DROP TABLE adm_fatura;
CREATE TABLE adm_fatura
(
	id_fatura	SERIAL NOT NULL UNIQUE,
	dtager		DATE,
        id_cliente	INTEGER REFERENCES cliente (id_cliente),
        mensalid	NUMERIC(14,2),
        desconto	NUMERIC(14,2),
        sextra		NUMERIC(14,2),
        reembolso	NUMERIC(14,2),
        pgconta		NUMERIC(14,2),
        impresso	BOOLEAN DEFAULT FALSE,
        selecion	BOOLEAN DEFAULT FALSE,
        liquidado	BOOLEAN DEFAULT FALSE,
	datvenc		DATE,
        numnota		CHARACTER VARYING(10),
        irrf            NUMERIC(14,2),
        fatextra        BOOLEAN DEFAULT FALSE,
        valliquido	NUMERIC(14,2),
        boleto          BOOLEAN DEFAULT FALSE,
        darf            BOOLEAN DEFAULT FALSE,
        recibo          BOOLEAN DEFAULT FALSE,
        valextenso      CHARACTER VARYING(200),
        cofins		NUMERIC(14,2),
        csll		NUMERIC(14,2),
        pis		NUMERIC(14,2),
        darf1           BOOLEAN DEFAULT FALSE,
        datemis         DATE,
        liqoriginal	NUMERIC(14,2),
        c94cdint	INTEGER,
        PRIMARY KEY(id_fatura)
);
ALTER TABLE adm_fatura ADD CONSTRAINT "adm_fatura_evitar_repetição" UNIQUE(dtager, id_cliente, datvenc);        
ALTER TABLE adm_fatura ADD COLUMN desc_neg NUMERIC(14,2) DEFAULT 0;
ALTER TABLE adm_fatura ADD identif TIMESTAMP;
ALTER TABLE adm_fatura ADD saldox NUMERIC(14,2);
ALTER TABLE adm_fatura ADD npgpar INTEGER;


ALTER TABLE cliente_alt_mensalidade ALTER valor TYPE NUMERIC(14,2);
ALTER TABLE cliente_alt_mensalidade ADD desco NUMERIC(14,2);
ALTER TABLE cliente_alt_mensalidade ADD id_usuario INTEGER;
ALTER TABLE cliente_alt_mensalidade DROP CONSTRAINT "cliente_alt_mensalidade_evitar_repetição";
ALTER TABLE cliente_alt_mensalidade ADD CONSTRAINT "cliente_alt_mensalidade_evitar_repetição" UNIQUE (id_cliente, dt_ini_val, dt_fim_val, valor, desco)
UPDATE cliente_alt_mensalidade SET desco = 0, id_usuario = 0;


ALTER TABLE sis_parametro ADD su_cad INTEGER REFERENCES usuario (id_usuario);
ALTER TABLE sis_parametro ADD su_adm INTEGER REFERENCES usuario (id_usuario);
ALTER TABLE sis_parametro ADD su_cse INTEGER REFERENCES usuario (id_usuario);
ALTER TABLE sis_parametro ADD su_exp INTEGER REFERENCES usuario (id_usuario);


--DROP TABLE adm_fatbaixa;
CREATE TABLE adm_fatbaixa
(
	id_fatbai	SERIAL NOT NULL UNIQUE,
	dtapag		DATE,
        id_fatura	INTEGER REFERENCES adm_fatura (id_fatura),
        liqrec		NUMERIC(14,2),
        descon		NUMERIC(14,2),
        jurosx		NUMERIC(14,2),
        totrec		NUMERIC(14,2),
        acordo		NUMERIC(14,2),
        recebi		NUMERIC(14,2),
        vorigi		NUMERIC(14,2),
        saldox		NUMERIC(14,2),
	id_detban	INTEGER,
        id_chepre	INTEGER,
        c94cdintb	INTEGER,
        identif		TIMESTAMP,
        PRIMARY KEY(id_fatbai)
);
ALTER TABLE adm_fatbaixa ADD CONSTRAINT "adm_fatbaixa_evitar_repetição" UNIQUE (dtapag, id_fatura, identif)


--DROP TABLE p_hp_para_baixa;
CREATE TABLE p_hp_para_baixa
(
	id_hpbaix 	SERIAL NOT NULL UNIQUE,
	cod_hp 		INTEGER,
	tipo_baixa 	SMALLINT,
	mensa_os 	CHARACTER VARYING(1),
	id_ctaban 	INTEGER,
	primary key(id_hpbaix)
);
ALTER TABLE p_hp_para_baixa ADD CONSTRAINT "p_hp_para_baixa_evitar_repetição" UNIQUE(cod_hp, tipo_baixa, mensa_os, id_ctaban);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (202, 2, 'O', 1);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (204, 4, 'O', 1);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (200, 2, 'M', 1);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (203, 4, 'M', 1);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (602, 2, 'O', 2);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (604, 4, 'O', 2);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (600, 2, 'M', 2);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (603, 4, 'M', 2);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (902, 2, 'O', 0);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (904, 4, 'O', 0);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (900, 2, 'M', 0);
INSERT INTO p_hp_para_baixa (cod_hp, tipo_baixa, mensa_os, id_ctaban) VALUES (903, 4, 'M', 0);


--DROP TABLE adm_cccliente;
CREATE TABLE adm_cccliente
(
	id_ccclie	SERIAL NOT NULL UNIQUE,
	eveger		BOOLEAN,
        regger		INTEGER,
        client		INTEGER,
        datage		DATE,
        histor		CHARACTER VARYING(80),
        hstpdr		INTEGER,
        valorx		NUMERIC(14,2),
        tipog1		CHARACTER VARYING(1),
        tipog2		CHARACTER VARYING(1),
        mesdat		NUMERIC(2),
	dtorig		DATE,
        identif		TIMESTAMP,
        PRIMARY KEY(id_ccclie)
);
--ALTER TABLE adm_cccliente DROP CONSTRAINT "adm_cccliente_evitar_repetição";
ALTER TABLE adm_cccliente ADD CONSTRAINT "adm_cccliente_evitar_repetição" UNIQUE (eveger, regger, client, histor, hstpdr, valorx, identif);


--DROP TABLE adm_logbaixa;
CREATE TABLE adm_logbaixa
(
	id_logbai	SERIAL NOT NULL UNIQUE,
	dtabai		DATE,
        valbai		NUMERIC(14,2),
        tipbai		CHARACTER VARYING(25),
        idbanc		INTEGER,
        idcheq		INTEGER,
        identif		TIMESTAMP,
        PRIMARY KEY(id_logbai)
);
ALTER TABLE adm_logbaixa ADD CONSTRAINT "adm_logbaixa_evitar_repetição" UNIQUE (dtabai, valbai, idbanc, idcheq, identif);


--DROP TABLE adm_logbaixadet;
CREATE TABLE adm_logbaixadet
(
	id_logbdt	SERIAL NOT NULL UNIQUE,
	id_logbai	INTEGER REFERENCES adm_logbaixa (id_logbai),
	id_fatura	INTEGER REFERENCES adm_fatura (id_fatura),
        id_fatbai	INTEGER REFERENCES adm_fatbaixa (id_fatbai),
        PRIMARY KEY(id_logbdt)
);


--	===================================   CHEQUE PRÉ   ====================================
--DROP TABLE adm_chepre_baixa CASCADE;
CREATE TABLE adm_chepre_baixa
(
	id_chebai	SERIAL NOT NULL UNIQUE,
	ncheqs		INTEGER,
	valorb		NUMERIC(14,2),
	identif		TIMESTAMP,
        PRIMARY KEY(id_chebai)
);


--DROP TABLE adm_chepre_fatbaixa CASCADE;
CREATE TABLE adm_chepre_fatbaixa
(
	id_chefat	SERIAL NOT NULL UNIQUE,
	id_chebai	INTEGER REFERENCES adm_chepre_baixa (id_chebai),
	id_fatbai	INTEGER,
	identif		TIMESTAMP,
        PRIMARY KEY(id_chefat)
);
ALTER TABLE adm_chepre_fatbaixa ADD CONSTRAINT "adm_chepre_fatbaixa_evitar_repetição" UNIQUE (id_chebai, id_fatbai);


--DROP TABLE adm_chepre_det CASCADE;
CREATE TABLE adm_chepre_det
(
	id_chedet	SERIAL NOT NULL UNIQUE,
	id_chebai	INTEGER REFERENCES adm_chepre_baixa (id_chebai),
	nbanco		CHARACTER VARYING(5),
	nchequ		CHARACTER VARYING(10),
	histor		CHARACTER VARYING(80),
	dtlanc		DATE,
	dtdepo		DATE,
	valorc		NUMERIC(14,2),
	deposi		BOOLEAN DEFAULT FALSE,
	id_ctaban	INTEGER REFERENCES p_ctabancaria (id_ctaban),
	observ		TEXT,
	identif		TIMESTAMP,
        PRIMARY KEY(id_chedet)
);
ALTER TABLE adm_chepre_det ADD CONSTRAINT "adm_chepre_det_evitar_repetição" UNIQUE (id_chebai, nbanco, nchequ, valorc);


--	===================================   CHEQUE PRÉ   ====================================


