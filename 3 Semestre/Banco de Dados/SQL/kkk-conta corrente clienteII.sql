/*select histor, datage, auxiliar, debito, credito, 
case when tipog1 = 'B' then saldo else null end as saldof,
case when tipog1 = 'B' then case when saldo > 0 then 'D' else case when saldo = 0 then '' else 'C' end end else null end as dc, 
client, codcli, cont, dtorig
from 
(select *, sum(soma) over (order by cont) as saldo
from 
(select row_number() OVER (PARTITION by 0) as cont,  
*
from 
(select histor, datage, 
case when tipog1 ='A' then valorx * -1 else null end as auxiliar, 
case when tipog1 ='B' and valorx < 0 then valorx * -1 else null end as debito, 
case when tipog1 ='B' and valorx > 0 then valorx else null end as credito, 
case when tipog1 ='B' then valorx * -1 else 0 end as soma,
tipog1, client, codcli, dtorig
from adm_cccliente ac
inner join cliente c on c.id_cliente = ac.client
where codcli = 9
order by date_part('year',dtorig), mesdat, tipog1, tipog2) 
foo)
fuu)
fii
where 
--dtorig >= '2014-09-01' and 
dtorig <= '2014-09-30'
--inner join cliente c on c.id_cliente = fii.client

select histor, datage, 
case when tipog1 ='A' then valorx * -1 else null end as auxiliar, 
case when tipog1 ='B' and valorx < 0 then valorx * -1 else null end as debito, 
case when tipog1 ='B' and valorx > 0 then valorx else null end as credito, 
case when tipog1 ='B' then valorx * -1 else 0 end as soma,
tipog1, client, codcli, dtorig, row_number() OVER (PARTITION by 0) as cont
from adm_cccliente ac
inner join cliente c on c.id_cliente = ac.client
where codcli = 8 and dtorig >= '2014-09-03' and dtorig <= '2014-09-30'
order by date_part('year',dtorig), mesdat, tipog1, tipog2
*/
SELECT SUM(valorx) FROM adm_cccliente
WHERE client = 8 AND dtorig <= '2014-09-02' AND tipog1 = 'B';

