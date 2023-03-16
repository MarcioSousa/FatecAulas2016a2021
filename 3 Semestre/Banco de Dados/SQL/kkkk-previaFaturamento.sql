-- MENSALIDADES
select c.id_cliente, c.codcli, p.nome, 
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END AS mensa, 
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END AS desco, 
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END AS sextra, 
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END AS reemb,
0.00 as irrf,
0.00 as cofins,
0.00 as csll,
0.00 as pis,
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END - 
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END + 
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END + 
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END 
as totnota,
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END AS pgconta,
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END - 
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END + 
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END + 
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END - 
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END
as liquido
from cliente c
inner join pessoa p on p.id_pessoa = c.id_pessoa
--where c.id_clista = 1
order by c.codcli

-- SERVIÇOS EXTRAS
--select id_cliente, sum(valor_lan) from adm_creceber
--where faturado = false AND tipoconta = 0 AND id_cadtos is null
--group by id_cliente
--order by id_cliente

-- REEMBOLSOS
--select id_cliente, sum(valor_lan) from adm_creceber
--where faturado = false AND tipoconta = 1 AND id_cadtos is null
--group by id_cliente
--order by id_cliente


--select id_cliente, sum(valor_lan) from adm_creceber ac
--inner join p_reembolso pr on pr.id_reembol = ac.id_srvree
--where tipoconta = 1 and faturado = false and pr.codigore <> 999  AND id_cadtos is null
--group by id_cliente
--order by id_cliente