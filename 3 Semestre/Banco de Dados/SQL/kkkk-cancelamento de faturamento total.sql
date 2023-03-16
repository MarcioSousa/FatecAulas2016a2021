select * from adm_fatura order by id_fatura desc;

select * from adm_fatura where dtager = '2014-08-28' order by id_fatura;

select * from adm_fatur_exec where datagera = '2014-08-28';

select * from adm_creceber where id_fatura >= 10523;

select * from adm_cccliente where regger >= 10523;

update adm_creceber set faturado = false, id_fatura = null where id_fatura>= 7;
delete from adm_fatur_exec where datagera = '2014-09-02';
delete from adm_fatura where dtager = '2014-09-02';
delete from adm_cccliente where regger >= 7;
