select codcli, nome, nome_lograd, numero, nome_cidade, uf,
CASE WHEN p.cnpj_cpf <> '' THEN 
CASE WHEN p.nat_pessoa = 1 THEN substring(p.cnpj_cpf, 1, 3) || '.' || substring(p.cnpj_cpf, 4, 3) || '.' || substring(p.cnpj_cpf, 7, 3) || '-' || substring(p.cnpj_cpf, 10, 2)
WHEN p.nat_pessoa = 2 THEN substring(p.cnpj_cpf, 1, 2) || '.' || substring(p.cnpj_cpf, 3, 3) || '.' || substring(p.cnpj_cpf, 6, 3) || '/' || substring(p.cnpj_cpf, 9, 4) || '-' || substring(p.cnpj_cpf, 13, 2)
ELSE NULL
END
ELSE NULL
END AS cpf_cnpj, ie_rg, numnota, mensalid, desconto, desc_neg, sextra, reembolso, pgconta, irrf, valliquido  
from adm_fatura f
inner join cliente c on c.id_cliente = f.id_cliente
inner join pessoa p on p.id_pessoa = c.id_pessoa 
left join endereço e on e.id_pessoa = p.id_pessoa
left join sis_tipo_endereço tp on tp.id_sis_tip_end = e.id_sis_tip_end
left join cidade ci on ci.id_cidade = e.id_cidade
left join estado es on es.id_estado = ci.id_estado
inner join sis_pessoa sp on sp.id_sis_pessoa = p.nat_pessoa
--INNER JOIN if1_temp07082014204855 sf on sf.id_fatsel = f.id_fatura 
where datvenc = '31/07/2014' and (tipo_end = 'PRINCIPAL' OR tipo_end IS NULL)
order by codcli
