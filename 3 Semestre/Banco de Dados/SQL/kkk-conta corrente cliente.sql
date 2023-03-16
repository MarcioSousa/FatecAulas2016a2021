/*
select 'TRUE' as eveger, get_idfatura(id_cliente, '2014-08-26') as regger, id_cliente as client, datalan as datage, 
historico as histor, 
CASE WHEN tipoconta = 0 THEN valor_lan * -1 ELSE CASE WHEN tipoconta = 1 THEN case when codigore = 999 then valor_lan else valor_lan * -1 end END END as valorx,
'A' as tipog1, 
CASE WHEN tipoconta = 0 THEN 'B' ELSE 
CASE WHEN tipoconta = 1 THEN 
 case when codigore = 999 then 'D' else 'C' end
END 
END as tipog2, date_part('month', datalan) as mesdat, current_timestamp as dtorig
from adm_creceber a
left join p_reembolso r on r.id_reembol = a.id_srvree
where faturado = true and id_cliente =3 and c92os is null and id_srvree is not null

select 'TRUE' as eveger, id_fatura as regger, id_cliente as client, dtager as datage, 'HONORÁRIOS DO MÊS ' || trim(leading from to_char(date_part('month', dtager), '00')) || ' - ' || numnota as histor, 
0 as hstprd, mensalid - desconto as valorx, 'A' as tipog1, 'A' as tipog2, date_part('month', dtager) as mesdat  
from adm_fatura
where dtager = '2014-07-30'

select 'TRUE' as eveger, id_fatura as regger, id_cliente as client, dtager as datage, 'TOTAL DA FATURA DO MÊS ' || trim(leading from to_char(date_part('month', dtager), '00')) || ' - ' || numnota as histor, 
0 as hstprd, valliquido * -1 as valorx, 'B' as tipog1, 'M' as tipog2, date_part('month', dtager) as mesdat  
from adm_fatura
where dtager = '2014-07-30'
*/

select 'FALSE' as eveger, 
fatura as regger, 
id_cli as client, 
'databaixa' as datage,
'JUROS REF. FATURA DO MÊS ' || trim(leading from to_char(date_part('month', dtafat), '00')) || '/' || trim(leading from to_char(date_part('year', dtafat), '0000')) || ' - ' || nmnota as histor,
0 as hstpdr, 
jurosx * -1 as valorx,
'B' as tipog1,
'J' as tipog2,
'mes de databaixa' as mesdat,
'databaixa' as dtorig,
'timestamp' as identif, * 
from ab4_temp28082014175947
where jurosx > 0
order by cntdet