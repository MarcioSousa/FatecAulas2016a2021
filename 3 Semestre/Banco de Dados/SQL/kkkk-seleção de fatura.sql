/*
SELECT c.id_cliente, c.codcli, p.nome,
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END AS mensa,
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END AS desco,
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END AS sextra,
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END AS reemb,
0.00 AS irrf,
0.00 AS cofins,
0.00 AS csll,
0.00 AS pis,
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END -
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END +
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END +
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END
AS totnota,
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0.00 ELSE get_pg_conta(c.id_cliente) END AS pgconta,
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END -
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END +
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END +
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END -
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END
AS liquido, char_length(p.fantasia), 

SELECT 
to_char(c.codcli, '9999') || ' - ' || SUBSTRING(p.fantasia FROM 1 FOR 26) || repeat(' ', 26 - char_length(p.fantasia)) || '- R$ ' ||
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END -
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END +
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END +
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END -
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END AS selecao
FROM cliente c
INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
WHERE NOT (CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END = 0 AND 
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END = 0 AND
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END = 0 AND
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END = 0 AND
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END = 0)
ORDER BY c.codcli;
*/
SELECT 
to_char(c.codcli, '9999') || ' - ' || p.fantasia || ' (R$ ' ||
CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END -
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END +
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END +
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END -
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END || ')' AS selecao,
f.mger
FROM cliente c
INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
LEFT JOIN 
(SELECT dtager, id_cliente, DATE_PART('month', dtager) AS mger, 
DATE_PART('year', dtager) AS ager, extract(month from now()) 
FROM adm_fatura WHERE DATE_PART('month', dtager) = extract(month from now()) 
AND DATE_PART('year', dtager) = extract(year from now())) AS f
ON f.id_cliente = c.id_cliente
WHERE (NOT (CASE WHEN c.mens_atual IS NULL THEN 0.00 ELSE c.mens_atual END = 0 AND 
CASE WHEN c.desc_mens IS NULL THEN 0.00 ELSE c.desc_mens END = 0 AND
CASE WHEN get_serv_extra(c.id_cliente) IS NULL THEN 0.00 ELSE get_serv_extra(c.id_cliente) END = 0 AND
CASE WHEN get_reembolso(c.id_cliente) IS NULL THEN 0.00 ELSE get_reembolso(c.id_cliente) END = 0 AND
CASE WHEN get_pg_conta(c.id_cliente) IS NULL THEN 0 ELSE get_pg_conta(c.id_cliente) END = 0)) AND mger IS NULL
ORDER BY c.codcli;

/*
SELECT dtager, id_cliente, DATE_PART('month', dtager) AS mger, 
DATE_PART('year', dtager) AS ager, extract(month from now()) 
FROM adm_fatura WHERE DATE_PART('month', dtager) = extract(month from now()) 
AND DATE_PART('year', dtager) = extract(year from now())
*/