
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XXI

--***************************************************************************************************************************************
--***************************************************************************************************************************************
--***************************************************************************************************************************************
--***************************************************************************************************************************************

--       antes de executar, deletar visão v_cliente. Após execução, rodar v_cliente.
--       antes de executar, deletar visão v_cli_mensalidade. Após execução, rodar v_cli_mensalidade.

--***************************************************************************************************************************************
--***************************************************************************************************************************************
--***************************************************************************************************************************************
--***************************************************************************************************************************************

--DROP TABLE p_serviços_os_ant;
CREATE TABLE p_serviços_os_ant
(
  id_serv_os	serial NOT NULL,
  cdgse_os	INTEGER NOT NULL UNIQUE,
  servico_os	CHARACTER VARYING(50) UNIQUE,
  vlrse_os	REAL,
  id_histpad	INTEGER,
  PRIMARY KEY	(id_serv_os)
);
INSERT INTO p_serviços_os_ant (cdgse_os, servico_os, vlrse_os, id_histpad)
SELECT cdgse_os, servico_os, vlrse_os, id_histpad FROM p_serviços_os ORDER BY id_serv_os;


--DROP TABLE p_reembolso_os_ant;
CREATE TABLE p_reembolso_os_ant
(
  id_rmb_os 	serial NOT NULL,
  cdgre_os 	INTEGER NOT NULL UNIQUE,
  reembol_os 	CHARACTER VARYING(50) NOT NULL,
  id_histpad 	INTEGER,
  origem 	CHARACTER VARYING(2),
  PRIMARY KEY (id_rmb_os)
);
INSERT INTO p_reembolso_os_ant (cdgre_os, reembol_os, id_histpad, origem) 
SELECT DISTINCT ON (creemb) creemb, reembolso, id_hispad, origem FROM 
(SELECT pr.cdgre_os AS creemb, pr.reembol_os AS reembolso, pr.id_histpad AS id_hispad, 'OS' AS origem FROM p_reembolso_os pr
UNION
SELECT re.codigore AS creemb, re.reembolso AS reembolso, re.id_histpad AS id_hispad, 'ME' AS origem FROM p_reembolso re
ORDER BY creemb, origem DESC) AS reembolso_ant;
INSERT INTO p_reembolso_os_ant (cdgre_os, reembol_os) VALUES (9999, 'REEMBOLSO NÃO ENCONTRADO');


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


CREATE TABLE p_ctabancaria 
(
	id_ctaban	SERIAL NOT NULL UNIQUE,
	banco		CHARACTER VARYING(25),
	nconta		CHARACTER VARYING(25),
	dt_abert	DATE,
	sd_inic		NUMERIC(15,2),
	n_cheque	INTEGER,
	pl_conta	CHARACTER VARYING(16),
	PRIMARY KEY 	(id_ctaban)
);
ALTER TABLE p_ctabancaria ADD CONSTRAINT "p_ctabancaria_evitar_repetição" UNIQUE(banco, nconta);


CREATE TABLE exp_cad_os 
(
	id_cadtos	SERIAL NOT NULL UNIQUE,
	num_os		CHARACTER VARYING(7),
	id_pessoa	INTEGER REFERENCES pessoa (id_pessoa),
	dat_inic	DATE,
	dat_term	DATE,
	faturado	BOOLEAN DEFAULT FALSE,
	dat_cadast	DATE,
	fantasia	CHARACTER VARYING(60),
	impresso	BOOLEAN DEFAULT FALSE,
	c41cdint	INTEGER, 
	PRIMARY KEY	(id_cadtos)
);
ALTER TABLE exp_cad_os ADD CONSTRAINT "exp_cad_os_evitar_repetição" UNIQUE(num_os);


--DROP TABLE exp_creceber;
CREATE TABLE exp_creceber 
(
	id_excrec	SERIAL NOT NULL UNIQUE,
	tipoconta	INT2, --0(serviços extras)  1(reembolso)  2(pagto por conta)  3(desconto)
	id_cadtos	INTEGER REFERENCES exp_cad_os (id_cadtos), --UF(link com a tabela ordem de serviço)
	id_srvree	INTEGER, --código do serviço / reembolso
	datalan		DATE,
	id_histpad	INTEGER,
	historico	CHARACTER VARYING(80),
	valor_lan	NUMERIC(15,2),
	id_detban	INTEGER, --(link com a tabela adm_bancodet)
	c42cdint	INTEGER,
	c42codig	INTEGER,
	PRIMARY KEY 	(id_excrec)
);
ALTER TABLE exp_creceber ADD CONSTRAINT "exp_creceber_evitar_repetição" UNIQUE(tipoconta, id_cadtos, id_srvree, datalan, id_histpad, historico, valor_lan);


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


DROP TABLE pessoa_nao_migrada_tmp;
CREATE TABLE pessoa_nao_migrada_tmp
(
	id_penami	SERIAL NOT NULL UNIQUE,
	id_cliente	INTEGER,
	origem		CHARACTER VARYING(1),
	razao		CHARACTER VARYING(100),
	fantasia	CHARACTER VARYING(60),
	data_ger	DATE,
	hora_ger	TIME,
	documento	CHARACTER VARYING(50),
	PRIMARY KEY(id_penami)
);


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


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_os AS 
	SELECT num_os, 
	SUBSTRING(num_os FROM 1 FOR POSITION ('/' IN num_os)-1)
	||SUBSTRING(num_os FROM POSITION ('/' IN num_os)+1) AS pesqos
	FROM exp_cad_os
	WHERE faturado = false
	ORDER BY num_os;
ALTER TABLE v_os OWNER TO postgres;
  

CREATE OR REPLACE VIEW aux_conv_adm_creceber AS
	SELECT id_detban, registro, valor_det, bd.historico, c.codcli, e.num_os FROM adm_bancodet bd
	INNER JOIN adm_banco b ON b.id_bancor = bd.id_bancor
	LEFT JOIN exp_cad_os e ON e.id_cadtos = bd.id_cadtos
	LEFT JOIN cliente c ON c.id_cliente = bd.id_cliente;
ALTER TABLE aux_conv_adm_creceber OWNER TO postgres;


DROP VIEW v_cli_mensalidade;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--retorna a soma de serviço extra para determinado cliente (mensalista)
--DROP FUNCTION get_serv_extra(integer);
CREATE FUNCTION get_serv_extra(integer) RETURNS numeric(14,2) AS
	'SELECT SUM(valor_lan) as v_sextra FROM adm_creceber 
	WHERE faturado = false AND tipoconta = 0 AND id_cadtos IS NULL AND 
	id_srvree IS NOT NULL AND id_cliente = $1 GROUP BY id_cliente'
LANGUAGE 'sql';


--retorna a soma de reembolsos para determinado cliente (mensalista)
--DROP FUNCTION get_reembolso(integer);
CREATE FUNCTION get_reembolso(integer) RETURNS numeric(14,2) AS
	'SELECT SUM(valor_lan) as v_reemb FROM adm_creceber ac 
	INNER JOIN p_reembolso pr ON pr.id_reembol = ac.id_srvree
	WHERE faturado = false AND tipoconta = 1 AND id_cadtos IS NULL AND 
	id_srvree IS NOT NULL AND id_cliente = $1 AND pr.codigore <> 999 
	GROUP BY id_cliente'
LANGUAGE 'sql';


--retorna a soma de pagamento por conta para determinado cliente (mensalista)
--DROP FUNCTION get_pg_conta(integer);
CREATE FUNCTION get_pg_conta(integer) RETURNS numeric(14,2) AS
	'SELECT SUM(valor_lan) as v_pgct FROM adm_creceber ac 
	INNER JOIN p_reembolso pr ON pr.id_reembol = ac.id_srvree
	WHERE faturado = false AND tipoconta = 1 AND id_cadtos IS NULL AND 
	id_srvree IS NOT NULL AND id_cliente = $1 AND pr.codigore = 999 
	GROUP BY id_cliente'
LANGUAGE 'sql';


--retorna o numero de nota na geração de faturas para cliente (mensalista)
CREATE OR REPLACE FUNCTION get_num_nota(boolean) RETURNS character varying(10) AS $$
DECLARE
	num_nota integer;
	retorno character varying(9);
	ano character(2);
BEGIN
	SELECT INTO ano TO_CHAR(CURRENT_TIMESTAMP,'yy');
	IF $1 = TRUE THEN
		SELECT INTO num_nota num_nota_n FROM sis_parametro WHERE id_sis_parametro = 1;
		UPDATE sis_parametro SET num_nota_n = num_nota + 1 WHERE id_sis_parametro = 1;
		retorno := TO_CHAR(num_nota, 'FM000000') || '/' || ano;
	END IF;
	IF $1 = FALSE THEN
		SELECT INTO num_nota num_nota_s FROM sis_parametro WHERE id_sis_parametro = 1;
		UPDATE sis_parametro SET num_nota_s = num_nota + 1 WHERE id_sis_parametro = 1;
		retorno := TO_CHAR(num_nota, 'FM000000') || '/' || ano;
	END IF;
	RETURN retorno;
END;
$$
LANGUAGE plpgsql;


CREATE or replace FUNCTION get_val_extenso_real(num numeric(20,2)) returns text
as $$
-- num -> numero a ser convertido em extenso
begin
  return get_val_extenso(num,'REAL','REAIS') ;  
end ;
$$ LANGUAGE plpgsql IMMUTABLE RETURNS NULL ON NULL INPUT ;


CREATE or replace FUNCTION get_val_extenso(num numeric(20,2), moeda text, moedas text) returns text as $$
-- num -> numero a ser convertido em extenso
-- moeda -> nome da moeda no singular
-- moedas -> nome da moeda no plural
declare
w_int char(21) ;
x integer ;
v integer ;
w_ret text ;
w_ext text ;
w_apoio text ;
m_cen text[] :=
array['QUATRILHÃO','QUATRILHÕES','TRILHÃO','TRILHÕES','BILHÃO','BILHÕES','MILHÃO','MILHÕES','MIL','MIL'] ;
begin
  w_ret := '' ;
  w_int := to_char(num * 100 , 'fm000000000000000000 00') ;
  for x in 1..5 loop
      v := cast(substr(w_int,(x-1)*3 + 1,3) as integer) ;    
      if v > 0 then
         if v > 1 then
            w_ext := m_cen[(x-1)*2+2] ;
           else
            w_ext := m_cen[(x-1)*2+1] ;
         end if ;   
         w_ret := w_ret || get_val_extenso_blk(substr(w_int,(x-1)*3 + 1,3)) || ' ' || w_ext ||', ' ;
      end if ;  
  end loop ;
  v := cast(substr(w_int,16,3) as integer) ;    
  if v > 0 then
     if v > 1 then
        w_ext := moedas ;
       else
        if w_ret = '' then 
           w_ext := moeda ;
          else
           w_ext := moedas ;
        end if ;   
     end if ; 
     w_apoio := get_val_extenso_blk(substr(w_int,16,3)) || ' ' || w_ext ;
     if w_ret = '' then 
        w_ret := w_apoio ;
       else 
        if v > 100 then 
           if w_ret = '' then 
              w_ret := w_apoio ;
             else
              w_ret := w_ret || w_apoio ;
           end if ;   
          else
           w_ret := btrim(w_ret,', ') || ' E ' || w_apoio ;
        end if ;   
     end if ;   
    else 
     if w_ret <> '' then  
        if substr(w_int,13,6) = '000000' then 
           w_ret := btrim(w_ret,', ') || ' DE ' || moedas ;
          else 
           w_ret := btrim(w_ret,', ') || ' ' || moedas ;
        end if ;    
     end if ;  
  end if ;    
  v := cast(substr(w_int,20,2) as integer) ;    
  if v > 0 then
     if v > 1 then
        w_ext := 'CENTAVOS' ;
       else
        w_ext := 'CENTAVO' ;
     end if ;   
     w_apoio := get_val_extenso_blk('0'||substr(w_int,20,2)) || ' ' || w_ext ;
     if w_ret = '' then 
        w_ret := w_apoio ;
       else 
        w_ret := w_ret || ' E ' || w_apoio ;
     end if ;   
  end if ;    
  return w_ret ;  
end ;
$$ LANGUAGE plpgsql IMMUTABLE RETURNS NULL ON NULL INPUT ;


CREATE or replace FUNCTION get_val_extenso_blk(num char(3)) returns text as $$
declare
w_cen integer ;
w_dez integer ;
w_dez2 integer ;
w_uni integer ;
w_tcen text ;
w_tdez text ;
w_tuni text ;
w_ext text ;
m_cen text[] :=
array['','CENTO','DUZENTOS','TREZENTOS','QUATROCENTOS','QUINHENTOS','SEISCENTOS','SETECENTOS','OITOCENTOS','NOVECENTOS'];
m_dez text[] :=
array['','DEZ','VINTE','TRINTA','QUARENTA','CINQUENTA','SESSENTA','SETENTA','OITENTA','NOVENTA'] ;
m_uni text[] :=
array['','UM','DOIS','TRÊS','QUATRO','CINCO','SEIS','SETE','OITO','NOVE','DEZ','ONZE','DOZE','TREZE','QUATORZE','QUINZE','DEZESSEIS','DEZESSETE','DEZOITO','DEZENOVE'] ;
begin
  w_cen := cast(substr(num,1,1) as integer) ;
  w_dez := cast(substr(num,2,1) as integer) ;
  w_dez2 := cast(substr(num,2,2) as integer) ;
  w_uni := cast(substr(num,3,1) as integer) ;
  if w_cen = 1 and w_dez2 = 0 then
     w_tcen := 'CEM' ;
     w_tdez := '' ;
     w_tuni := '' ;
    else
     if w_dez2 < 20 then 
        w_tcen := m_cen[w_cen + 1] ;
        w_tdez := m_uni[w_dez2 + 1] ; 
        w_tuni := '' ;
       else
        w_tcen := m_cen[w_cen + 1] ;
        w_tdez := m_dez[w_dez + 1] ; 
        w_tuni := m_uni[w_uni + 1] ;
     end if ;    
  end if ; 
  w_ext := w_tcen ;
  if w_tdez <> '' then  
     if w_ext = '' then 
        w_ext := w_tdez ;
       else
        w_ext := w_ext || ' E ' || w_tdez ;
     end if ;      
  end if ;   
  if w_tuni <> '' then  
     if w_ext = '' then 
        w_ext := w_tuni ;
       else
        w_ext := w_ext || ' E ' || w_tuni ;
     end if ;
  end if ;
  return w_ext ;  
end ;
$$ LANGUAGE plpgsql IMMUTABLE RETURNS NULL ON NULL INPUT ;


--retorna id_fatura para determinado cliente (mensalista) e data de geração
--DROP FUNCTION get_idfatura(integer, data);
CREATE FUNCTION get_idfatura(integer, date) RETURNS integer AS
	'SELECT id_fatura FROM adm_fatura
	WHERE dtager = $2 and id_cliente = $1'
LANGUAGE 'sql';


--***************************************************************************************************************************************


-- ÍNDICES  --


