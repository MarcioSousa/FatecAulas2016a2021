--========== Executar em separado ==========
CREATE DATABASE acont_db_port
  WITH ENCODING='WIN1252'
       OWNER=postgres
       TEMPLATE=template0
       LC_COLLATE='Portuguese_Brazil.1252'
       LC_CTYPE='Portuguese_Brazil.1252'
       CONNECTION LIMIT=-1
       TABLESPACE=pg_default;
--========== Executar em separado ==========       
