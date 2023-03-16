using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using AcessoBD;
using Dto;

namespace Negocios
{
    public class AjudanteNegocios
    {
        AcessoDadosSql acessoDadosSql = new AcessoDadosSql();

        //Inserir, Alterar, Excluir, Consultar um(s) Ajudante(s) usando StoreProcedure
        public string Inserir(Pessoa ajudante)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@aju_Nome", ajudante.Nome);
                acessoDadosSql.AdicionarParametros("@aju_Logradouro", ajudante.Logradouro);
                acessoDadosSql.AdicionarParametros("@aju_Numero", ajudante.Numero);
                acessoDadosSql.AdicionarParametros("@aju_Bairro", ajudante.Bairro);
                acessoDadosSql.AdicionarParametros("@aju_Cidade",ajudante.Cidade);
                acessoDadosSql.AdicionarParametros("@aju_Uf",ajudante.Uf);
                acessoDadosSql.AdicionarParametros("@aju_Cep", ajudante.Cep);
                acessoDadosSql.AdicionarParametros("@aju_CelularUm",ajudante.CelularUm);
                acessoDadosSql.AdicionarParametros("@aju_CelularDois",ajudante.CelularDois);
                acessoDadosSql.AdicionarParametros("@aju_ContatoFixo", ajudante.ContatoFixo);
                acessoDadosSql.AdicionarParametros("@aju_Custo", ajudante.Custo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_AjudanteInserir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Alterar(Pessoa ajudante)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@aju_Codigo", ajudante.Codigo);
                acessoDadosSql.AdicionarParametros("@aju_Nome", ajudante.Nome);
                acessoDadosSql.AdicionarParametros("@aju_Logradouro", ajudante.Logradouro);
                acessoDadosSql.AdicionarParametros("@aju_Numero", ajudante.Numero);
                acessoDadosSql.AdicionarParametros("@aju_Bairro", ajudante.Bairro);
                acessoDadosSql.AdicionarParametros("@aju_Cidade", ajudante.Cidade);
                acessoDadosSql.AdicionarParametros("@aju_Uf", ajudante.Uf);
                acessoDadosSql.AdicionarParametros("@aju_Cep", ajudante.Cep);
                acessoDadosSql.AdicionarParametros("@aju_CelularUm", ajudante.CelularUm);
                acessoDadosSql.AdicionarParametros("@aju_CelularDois", ajudante.CelularDois);
                acessoDadosSql.AdicionarParametros("@aju_ContatoFixo", ajudante.ContatoFixo);
                acessoDadosSql.AdicionarParametros("@aju_Custo", ajudante.Custo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_AjudanteAlterar").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Excluir(Pessoa ajudante)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@aju_Codigo", ajudante.Codigo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_AjudanteExcluir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public AjudanteColecao ConsultarPorNome(string nome)
        {
            try
            {
                //Criação de uma coleão nova de Ajudantes (aqui está vazio)
                AjudanteColecao ajudanteColecao = new AjudanteColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@aju_Nome", nome);

                DataTable dataTableAjudante = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_AjudanteConsultarPorNome");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTableAjudante.Rows)
                {
                    //Criar um cliente vazio
                    Pessoa ajudante = new Pessoa();

                    //Colocar os dados da linha nele
                    ajudante.Codigo = Convert.ToInt32(linha["aju_Codigo"]);
                    ajudante.Nome = Convert.ToString(linha["aju_Nome"]);
                    ajudante.Logradouro = Convert.ToString(linha["aju_Logradouro"]);
                    ajudante.Bairro = Convert.ToString(linha["aju_Bairro"]);
                    ajudante.Numero = Convert.ToString(linha["aju_Numero"]);
                    ajudante.Cidade = Convert.ToString(linha["aju_Cidade"]);
                    ajudante.Uf = Convert.ToString(linha["aju_Uf"]);
                    ajudante.Cep = Convert.ToString(linha["aju_Cep"]);
                    ajudante.CelularUm = Convert.ToString(linha["aju_CelularUm"]);
                    ajudante.CelularDois = Convert.ToString(linha["aju_CelularDois"]);
                    ajudante.ContatoFixo = Convert.ToString(linha["aju_ContatoFixo"]);
                    ajudante.Custo = Convert.ToDouble(linha["aju_Custo"]);

                    //Adicionar ele na coleção
                    ajudanteColecao.Add(ajudante);
                }

                return ajudanteColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o Ajudante por Nome.\nDetalhes: " + ex.Message);
            }
        }
        public AjudanteColecao ConsultarPorCodigo(int codigo)
        {
            try
            {
                //Criação de uma coleão nova de Ajudantes (aqui está vazio)
                AjudanteColecao ajudanteColecao = new AjudanteColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@aju_Codigo", codigo);

                DataTable dataTableAjudante = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_AjudanteConsultar");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTableAjudante.Rows)
                {
                    //Criar um cliente vazio
                    Pessoa ajudante = new Pessoa();

                    //Colocar os dados da linha nele
                    ajudante.Codigo = Convert.ToInt32(linha["aju_Codigo"]);
                    ajudante.Nome = Convert.ToString(linha["aju_Nome"]);
                    ajudante.Logradouro = Convert.ToString(linha["aju_Logradouro"]);
                    ajudante.Bairro = Convert.ToString(linha["aju_Bairro"]);
                    ajudante.Numero = Convert.ToString(linha["aju_Numero"]);
                    ajudante.Cidade = Convert.ToString(linha["aju_Cidade"]);
                    ajudante.Uf = Convert.ToString(linha["aju_Uf"]);
                    ajudante.Cep = Convert.ToString(linha["aju_Cep"]);
                    ajudante.CelularUm = Convert.ToString(linha["aju_CelularUm"]);
                    ajudante.CelularDois = Convert.ToString(linha["aju_CelularDois"]);
                    ajudante.ContatoFixo = Convert.ToString(linha["aju_ContatoFixo"]);
                    ajudante.Custo = Convert.ToDouble(linha["aju_Custo"]);

                    //Adicionar ele na coleção
                    ajudanteColecao.Add(ajudante);
                }
                return ajudanteColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o Ajudante por Código.\nDetalhes: " + ex.Message);
            }
        }

    }
}
