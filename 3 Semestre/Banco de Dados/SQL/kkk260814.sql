/*
select (select id_bancor FROM adm_banco WHERE registro = 34044), 
(select id_histpad from p_historicopadrao where codigohp = (select cod_hp FROM p_hp_para_baixa WHERE tipo_baixa = 2 AND mensa_os = 'M' AND id_ctaban = 1)),
id_cli, 'documento', substring('Tipodebaixa Num doc xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx/ REC FAT Nº' || nmnota || ' ' || fantas from 1 for 80), recebi, cntdet, ultdet 
from ab4_temp26082014180645 order by id_tmp002
*/


/*
select row_number() OVER (PARTITION by 0) as contador, cntdet, id_tmp002 from ab4_temp26082014170443
order by id_tmp002



select row_number() OVER (PARTITION by 0) as contador, cod_cli, nome from 
clientes
*/

select '15/12/2014' as dtapag, fatura as id_fatura, liqrec, descon, jurosx, totrec, acordo, vorigi, recebi, liqrec - recebi as saldox, 
* from ab4_temp27082014140008 order by id_tmp002