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
    public class RotaNegocios
    {
        AcessoDadosSql acessoDadosSql = new AcessoDadosSql();

        //Inserir, Alterar, Excluir, Consultar um(s) Pedagio(s) usando StoreProcedure
        public string Inserir(Rota rota)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@rot_Origem", rota.Origem);
                acessoDadosSql.AdicionarParametros("@rot_Destino", rota.Destino);
                acessoDadosSql.AdicionarParametros("@rot_Km", rota.Km);
                acessoDadosSql.AdicionarParametros("@rot_Horas", rota.Horas);

                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_RotaInserir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Alterar(Rota rota)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@rot_Codigo", rota.Codigo);
                acessoDadosSql.AdicionarParametros("@rot_Origem", rota.Origem);
                acessoDadosSql.AdicionarParametros("@rot_Destino", rota.Destino);
                acessoDadosSql.AdicionarParametros("@rot_Km", rota.Km);
                acessoDadosSql.AdicionarParametros("@rot_Horas", rota.Horas);
                acessoDadosSql.AdicionarParametros("@rot_CodPedPerc", rota.CodPedagio);

                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_RotaAlterar").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Excluir(Rota rota)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@rot_Codigo", rota.Codigo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_RotaExcluir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public RotaColecao ConsultarPorNome(string nome)
        {
            try
            {
                //Criação de uma coleção nova de Rota (aqui está vazio)
                RotaColecao rotaColecao = new RotaColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@rot_Origem", nome);

                DataTable dataTableRota = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_RotaConsultarPorNome");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTableRota.Rows)
                {
                    //Criar um pedágio vazio
                    Rota rota = new Rota();

                    //Colocar os dados da linha nele
                    rota.Codigo = Convert.ToInt32(linha["rot_Cod"]);
                    rota.Origem = Convert.ToString(linha["rot_Origem"]);
                    rota.Destino = Convert.ToString(linha["rot_Destino"]);
                    rota.Km = Convert.ToInt32(linha["rot_Km"]);
                    rota.Horas = Convert.ToInt32(linha["rot_Horas"]);
                    rota.CodPedagio = Convert.ToInt32(linha["rot_CodPedPerc"]);

                    //Adicionar ele na coleção
                    rotaColecao.Add(rota);
                }

                return rotaColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar a Rota por Origem.\nDetalhes: " + ex.Message);
            }
        }
        public RotaColecao CarregaComboOrigem()
        {
            try
            {
                //Criação de uma coleão nova de Ajudantes (aqui está vazio)
                RotaColecao rotaColecao = new RotaColecao();

                acessoDadosSql.LimparParametros();

                DataTable dataTableRota = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_RotaCerregaComboOrigem");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTableRota.Rows)
                {
                    //Criar um pedágio vazio
                    Rota rota = new Rota();

                    //Colocar os dados da linha nele
                    rota.Codigo = Convert.ToInt32(linha["rot_Cod"]);
                    rota.Origem = Convert.ToString(linha["rot_Origem"]);
                    //rota.Destino = Convert.ToString(linha["rot_Destino"]);
                    //rota.Km = Convert.ToInt32(linha["rot_Km"]);
                    //rota.Horas = Convert.ToInt32(linha["rot_Horas"]);
                    //rota.CodPedagio = Convert.ToInt32(linha["rot_CodPedPerc"]);

                    //Adicionar ele na coleção
                    rotaColecao.Add(rota);
                }

                return rotaColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar a Rota por Origem.\nDetalhes: " + ex.Message);
            }
        }
    }
}