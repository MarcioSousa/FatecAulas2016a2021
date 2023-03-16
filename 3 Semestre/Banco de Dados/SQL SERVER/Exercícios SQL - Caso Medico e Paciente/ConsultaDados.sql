SELECT * FROM MEDICOS
GO

SELECT * FROM AMBULATORIOS
GO

SELECT * FROM PACIENTES
GO

SELECT * FROM CONSULTA
GO

SELECT * FROM MEDICOS
WHERE Cidade = 'Itu'
GO

SELECT NmPaciente FROM PACIENTES
WHERE NmPaciente LIKE 'R%'
GO

SELECT CRM, NmMedico, Especialidade FROM MEDICOS
ORDER BY Especialidade
GO

SELECT * FROM PACIENTES
WHERE Idade > 10 AND Idade < 30
GO

SELECT NmPaciente, Idade FROM PACIENTES
WHERE Cidade = 'Sorocaba' OR Doenca = 'Virose'
GO

SELECT NmMedico FROM MEDICOS
WHERE Especialidade = 'Oftalmologia' AND Idade > 35 AND Idade < 55 AND Cidade = 'Salto'
GO

SELECT NmMedico, Nr_Ambul FROM MEDICOS
GO

SELECT NrAmbul FROM AMBULATORIOS
WHERE NrAndar <> 2 AND NrAndar <> 4 AND Capacidade > 50
GO

SELECT * FROM CONSULTA
WHERE CRM <> '46' AND CRM <> '79'
GO

SELECT NmMedico, Especialidade FROM MEDICOS
GO

SELECT * FROM AMBULATORIOS
WHERE Capacidade = 50 OR NrAmbul > 10
GO

SELECT C.RGPaciente FROM PACIENTES P
INNER JOIN CONSULTA C
ON P.RGPaciente = C.RGPaciente
WHERE C.Data_hora > '20160901'
GO

SELECT NrAmbul FROM AMBULATORIOS
WHERE NrAndar = 3
GO

SELECT * FROM PACIENTES
WHERE Doenca = 'Sarampo'
GO

SELECT DISTINCT Doenca FROM PACIENTES
GO

SELECT NmPaciente,Idade FROM PACIENTES
ORDER BY NmPaciente, Cidade
GO

SELECT * FROM PACIENTES
WHERE idade > 15 AND (Cidade = 'Itu' OR Cidade = 'Salto') AND Doenca = 'Rubéola'
GO

SELECT VrConsulta, VrConsulta + ( VrConsulta * 0.1) AS ValorTotal FROM CONSULTA
WHERE CRM = '111222' AND MONTH(Data_hora) BETWEEN 4 AND 4 AND YEAR(Data_hora) BETWEEN 2016 AND 2016
GO

-- Exercícios 03 --
SELECT A.NrAmbul, A.NrAndar, M.NmMedico
FROM MEDICOS M, AMBULATORIOS A
WHERE M.Nr_Ambul = A.NrAmbul
AND A.NrAndar = 5
GO

SELECT M.NmMedico
FROM MEDICOS M, CONSULTA C
WHERE M.CRM = C.CRM
AND M.Especialidade = 'Ortopedia'
AND C.Data_hora BETWEEN '15-04-2003 07:00:00' AND '15-04-2003 12:00:00'
GO

SELECT *
FROM MEDICOS
WHERE Idade > 55
AND Especialidade = 'Ortopedia'
GO

SELECT M.CRM, C.Data_hora 
FROM MEDICOS M, CONSULTA C, PACIENTES P
WHERE M.CRM = C.CRM
AND C.RGPaciente = P.RGPaciente
AND (P.RGPaciente = '122'
OR P.RGPaciente = '725')
GO

SELECT M.CRM
FROM MEDICOS M, CONSULTA C
WHERE M.CRM = C.CRM
AND C.VrConsulta > 150
GO

SELECT M.NmMedico, P.NmPaciente, C.Data_hora, C.VrConsulta
FROM CONSULTA C, MEDICOS M, PACIENTES P
WHERE M.CRM = C.CRM
AND C.RGPaciente = P.RGPaciente
GO

SELECT DISTINCT Nr_Ambul
FROM AMBULATORIOS A, MEDICOS M
WHERE A.NrAmbul = M.Nr_Ambul
GO

SELECT M.NmMedico, P.NmPaciente, C.Data_hora
FROM MEDICOS M, PACIENTES P, CONSULTA C
WHERE M.CRM = C.CRM
AND C.RGPaciente = P.RGPaciente
GO

SELECT M.NmMedico, C.Data_hora
FROM MEDICOS M, CONSULTA C
WHERE M.CRM = C.CRM
GO

SELECT P.NmPaciente
FROM MEDICOS M, CONSULTA C, PACIENTES P
WHERE M.CRM = C.CRM
AND C.RGPaciente = P.RGPaciente
AND (M.NmMedico = 'João Carlos Santos'
OR M.NmMedico = 'Ruth Aparecida')
AND P.Doenca = 'Sarampo'
GO

SELECT p.NmPaciente, C.Data_hora
FROM PACIENTES P, CONSULTA C, MEDICOS M
WHERE P.RGPaciente = C.RGPaciente
AND C.CRM = M.CRM
AND(M.NmMedico = 'João Carlos Santos' OR M.NmMedico = 'Maria Souza')
AND P.Doenca = 'Pneumonia'
GO

SELECT A.NrAndar
FROM AMBULATORIOS A, MEDICOS M, CONSULTA C, PACIENTES P
WHERE A.NrAmbul = M.Nr_Ambul
AND M.CRM = C.CRM
AND C.RGPaciente = P.RGPaciente
AND (P.NmPaciente = 'Marcio Silva' AND P.Doenca = 'Sarampo')
GO

SELECT COUNT(*)
FROM PACIENTES
WHERE Idade < 12
AND Cidade = 'Itu'
AND Doenca = 'Dengue'
GO


SELECT Especialidade, COUNT(*) as Qtde
FROM MEDICOS
GROUP BY Especialidade
GO


SELECT A.NrAndar, COUNT(*) as QtdeMedico
FROM MEDICOS M, AMBULATORIOS A
WHERE M.Nr_Ambul = A.NrAmbul
GROUP BY A.NrAndar
GO



SELECT M.NmMedico, AVG(C.VrConsulta) AS Media
FROM CONSULTA C, MEDICOS M
WHERE C.CRM = M.CRM
GROUP BY M.NmMedico
GO



SELECT Cidade, COUNT(*) AS Qtde
FROM PACIENTES 
GROUP BY Cidade
HAVING COUNT (*) > 2



SELECT  MAX(VrConsulta)
FROM CONSULTA
WHERE Data_hora = '13-11-2017'




SELECT NrAndar ,SUM(Capacidade) 
FROM AMBULATORIOS
GROUP BY NrAndar




SELECT COUNT(*), Cidade, Doenca
FROM PACIENTES
GROUP BY Cidade, Doenca





--TEste esses
--10.	Buscar os nomes dos pacientes, com consultas 
--		marcadas para os médicos João Carlos Santos ou 
--		Maria Souza, que estão com pneumonia
--11.	Buscar o número do andar onde está localizado o 
--		ambulatório que o paciente José de Almeida foi 
--		atendido e diagnosticada a doença Dengue
--12.	Buscar quantos pacientes menores de 12 anos, que são da cidade de Itu, estão com Dengue.
--13.	Buscar quantos médicos existem cadastrados, por especialidade.
--14.	Buscar quantos médicos existem cadastrados nos ambulatórios, por andar. Mostrar o número do andar e a quantidade de médicos cadastrados.
--15.	Buscar a média do valor das consultas cobradas pelos médicos. Mostrar o nome do médico e a média do valor das consultas.-
--16.	Buscar quantos pacientes existem cadastrados por cidade. Mostrar somente as cidades que possuem mais de 2 pacientes cadastrados.
--17.	Buscar o maior valor de todas as consultas realizadas no dia de hoje.
--18.	Buscar a soma das capacidades dos ambulatórios abrigados em cada andar.
--19.	Buscar quantos pacientes existem cadastrados, por cidade e doença.
--20.	Buscar a soma dos valores das consultas pagas pelos pacientes. Mostrar o nome do paciente e a soma dos valores das consultas, mas somente dos pacientes cujo valor da soma for maior que R$ 600,00.

 
























