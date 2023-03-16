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
    public class ImprevistoNegocios
    {
        AcessoDadosSql acessoDadosSql = new AcessoDadosSql();

        //Inserir, Alterar, Excluir, Consultar impreviso(s) usando StoreProcedure
        public string Inserir(Imprevisto imprevisto)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@imp_Nome", imprevisto.Nome);

                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_ImprevistoInserir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Alterar(Imprevisto imprevisto)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@imp_Codigo", imprevisto.Codigo);
                acessoDadosSql.AdicionarParametros("@imp_Nome", imprevisto.Nome);

                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_ImprevistoAlterar").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Excluir(Imprevisto imprevisto)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@imp_Codigo", imprevisto.Codigo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_ImprevistoExcluir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public ImprevistoColecao ConsultarPorNome(string nome)
        {
            try
            {
                //Criação de uma coleão nova de clientes (aqui está vazio)
                ImprevistoColecao imprevistoColecao = new ImprevistoColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@imp_Nome", nome);

                DataTable dataTablecliente = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_ImprevistoConsultarPorNome");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTablecliente.Rows)
                {
                    //Criar um cliente vazio
                    Imprevisto imprevisto = new Imprevisto();

                    //Colocar os dados da linha nele
                    imprevisto.Codigo = Convert.ToInt32(linha["imp_Codigo"]);
                    imprevisto.Nome = Convert.ToString(linha["imp_Nome"]);

                    //Adicionar ele na coleção
                    imprevistoColecao.Add(imprevisto);
                }

                return imprevistoColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o imprevisto por Nome.\nDetalhes: " + ex.Message);
            }
        }
    }
}
