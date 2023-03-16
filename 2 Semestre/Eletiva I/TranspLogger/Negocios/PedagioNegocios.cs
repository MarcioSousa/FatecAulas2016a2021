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
    public class PedagioNegocios
    {
        AcessoDadosSql acessoDadosSql = new AcessoDadosSql();

        //Inserir, Alterar, Excluir, Consultar um(s) Pedagio(s) usando StoreProcedure
        public string Inserir(Pedagio pedagio)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@ped_Nome", pedagio.Nome);
                acessoDadosSql.AdicionarParametros("@ped_Preco", pedagio.Preco);

                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_PedagioInserir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Alterar(Pedagio pedagio)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@ped_Codigo", pedagio.Codigo);
                acessoDadosSql.AdicionarParametros("@ped_Nome", pedagio.Nome);
                acessoDadosSql.AdicionarParametros("@ped_Preco", pedagio.Preco);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_PedagioAlterar").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Excluir(Pedagio pedagio)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@ped_Codigo", pedagio.Codigo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_PedagioExcluir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public PedagioColecao ConsultarPorNome(string nome)
        {
            try
            {
                //Criação de uma coleão nova de Ajudantes (aqui está vazio)
                PedagioColecao pedagioColecao = new PedagioColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@ped_Nome", nome);

                DataTable dataTableAjudante = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_PedagioConsultarPorNome");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTableAjudante.Rows)
                {
                    //Criar um pedágio vazio
                    Pedagio pedagio = new Pedagio();

                    //Colocar os dados da linha nele
                    pedagio.Codigo = Convert.ToInt32(linha["ped_Codigo"]);
                    pedagio.Nome = Convert.ToString(linha["ped_Nome"]);
                    pedagio.Preco = Convert.ToDouble(linha["ped_Preco"]);

                    //Adicionar ele na coleção
                    pedagioColecao.Add(pedagio);
                }

                return pedagioColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o Pedágio por Nome.\nDetalhes: " + ex.Message);
            }
        }
    }
}