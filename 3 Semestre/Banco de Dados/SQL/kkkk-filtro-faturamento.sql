/*
SELECT '' AS id, 'Totais:' AS cli, '' AS nome, '' AS fatura, '' AS dtager, '' AS datvenc,
SUM(mensalid), SUM(desconto), SUM(sextra), SUM(reembolso), SUM(pgconta), SUM(imposts),
SUM(valliquido), '' AS numnota, '' AS liquidado, mger, ager from 
(SELECT c.id_cliente, c.codcli, p.nome, f.id_fatura, f.dtager, f.datvenc, f.mensalid,
f.desconto, f.sextra, f.reembolso, f.pgconta, irrf+cofins+csll+pis as imposts, valliquido, numnota,
liquidado, DATE_PART('month', f.dtager) AS mger, DATE_PART('year', f.dtager) AS ager, c.forma
FROM cliente c
INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
INNER JOIN adm_fatura f on f.id_cliente = c.id_cliente) as temp
WHERE mger = 3 AND ager = 2014
GROUP BY mger, ager
--ORDER BY c.codcli, f.dtager DESC;
*/

--SELECT * from adm_fatura
/*
SELECT '' AS id, 'Totais:' AS cli, '' AS nome, '' AS fatura, '' AS dtager, '' AS datvenc,
SUM(f.mensalid), SUM(f.desconto), SUM(f.sextra), SUM(f.reembolso), SUM(f.pgconta), SUM(irrf+cofins+csll+pis),
SUM(valliquido), '' AS numnota, '' AS liquidado
FROM cliente c
INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
INNER JOIN adm_fatura f on f.id_cliente = c.id_cliente
--WHERE DATE_PART('month', f.dtager) = 3 AND DATE_PART('year', f.dtager) = 2014;
--WHERE f.id_cliente = (select id_cliente from cliente where codcli = 20)
WHERE liquidado = FALSE AND datvenc < (now() - interval '10 DAYS')
*/

--/*
SELECT * FROM (SELECT c.id_cliente, c.codcli, p.nome, f.id_fatura, f.dtager, f.datvenc, f.mensalid,
f.desconto, f.sextra, f.reembolso, f.pgconta, irrf+cofins+csll+pis as imposts, valliquido, numnota,
liquidado, DATE_PART('month', f.dtager) AS mger, DATE_PART('year', f.dtager) AS ager, c.forma, TRUNC((date_part('epoch', (now() - datvenc)::interval))/86400) AS atraso
FROM cliente c
INNER JOIN pessoa p ON p.id_pessoa = c.id_pessoa
INNER JOIN adm_fatura f on f.id_cliente = c.id_cliente) AS temp
WHERE ager = 2013
ORDER BY codcli, dtager DESC;
--*/

--select date_part('epoch', '01 day 1:30:00'::interval);

