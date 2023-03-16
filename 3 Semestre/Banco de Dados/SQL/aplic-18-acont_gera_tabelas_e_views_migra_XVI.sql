
--***************************************************************************************************************************************

-- Criação e/ou alteração das Tabelas - MIGRAÇÃO XVI


CREATE TABLE sis_cnae
(
	id_cnae		SERIAL NOT NULL,
	n_cnae		CHARACTER VARYING(9) UNIQUE,
	desc_cnae	CHARACTER VARYING(170) UNIQUE, 
	PRIMARY KEY 	(id_cnae)
);


CREATE TABLE sis_regtribfed
(
	id_rtribf	SERIAL NOT NULL,
	desc_rtribf	CHARACTER VARYING(20) UNIQUE,
	subnivel1	BOOLEAN DEFAULT FALSE,
	nome_subn1	CHARACTER VARYING(25),
	subnivel2	BOOLEAN DEFAULT FALSE,
	nome_subn2	CHARACTER VARYING(25),
	PRIMARY KEY	(id_rtribf)
);


CREATE TABLE sis_rtribfsub
(
	id_rtfsub	SERIAL NOT NULL,
	id_rtribf	INTEGER REFERENCES sis_regtribfed (id_rtribf), 
	subnivel	INT2,
	descricao	CHARACTER VARYING(20),
	PRIMARY KEY	(id_rtfsub)
);


CREATE TABLE sis_obr_aces
(
	id_obrace	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(40) UNIQUE,
	PRIMARY KEY	(id_obrace)
);


CREATE TABLE sis_raicms
(
	id_raicms	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_raicms)
);


CREATE TABLE sis_tiponf
(
	id_tiponf	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_tiponf)
);


CREATE TABLE sis_rapiss
(
	id_rapiss	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_rapiss)
);


CREATE TABLE sis_tipdocfis
(
	id_tdocfi	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_tdocfi)
);


CREATE TABLE sis_rafolh
(
	id_rafolh	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_rafolh)
);


CREATE TABLE sis_rainss
(
	id_rainss	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_rainss)
);


CREATE TABLE sis_natjur
(
	id_natjur	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_natjur)
);


CREATE TABLE sis_orgreg
(
	id_orgreg	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(30) UNIQUE,
	PRIMARY KEY	(id_orgreg)
);


CREATE TABLE sis_orgcla
(
	id_orgcla	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(20) UNIQUE,
	PRIMARY KEY	(id_orgcla)
);


CREATE TABLE sis_servic
(
	id_servic	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_servic)
);


CREATE TABLE sis_tipsen
(
	id_tipsen	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(25) UNIQUE,
	PRIMARY KEY	(id_tipsen)
);


CREATE TABLE sis_sinpat
(
	id_sinpat	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(150) UNIQUE,
	PRIMARY KEY	(id_sinpat)
);


CREATE TABLE sis_sinemp
(
	id_sinemp	SERIAL NOT NULL,
	descricao	CHARACTER VARYING(150) UNIQUE,
	PRIMARY KEY	(id_sinemp)
);


CREATE TABLE sis_codser
(
	id_codser	SERIAL NOT NULL,
	n_codser	CHARACTER VARYING(10) UNIQUE,
	desc_codser	CHARACTER VARYING(170) UNIQUE, 
	PRIMARY KEY 	(id_codser)
);


CREATE TABLE sis_codest
(
	id_codest	SERIAL NOT NULL,
	n_codest	CHARACTER VARYING(10) UNIQUE,
	desc_codest	CHARACTER VARYING(170) UNIQUE, 
	PRIMARY KEY 	(id_codest)
);


CREATE TABLE sis_codanu
(
	id_codanu	SERIAL NOT NULL,
	n_codanu	CHARACTER VARYING(10) UNIQUE,
	desc_codanu	CHARACTER VARYING(170) UNIQUE, 
	PRIMARY KEY 	(id_codanu)
);


--***************************************************************************************************************************************

-- VIEWS  --


CREATE OR REPLACE VIEW v_cnae AS 
	SELECT *, SUBSTRING(n_cnae,1,4)||SUBSTRING(n_cnae,6,1)||SUBSTRING(n_cnae,8,2) as pesqcn FROM sis_cnae ORDER BY n_cnae;
ALTER TABLE v_cnae OWNER TO postgres;


--***************************************************************************************************************************************

-- FUNÇÕES  --


--***************************************************************************************************************************************

-- ÍNDICES  --


