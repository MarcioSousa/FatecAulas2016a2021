DROP TABLE dados;
CREATE TABLE dados
(
  id_dados	serial NOT NULL,
  data_ev	DATE,
  hora_ev	TIME,
  pressao	NUMERIC(6,2),
  tempera	NUMERIC(5,1),
  umidade	NUMERIC(5,1),
  PRIMARY KEY	(id_dados)
);
