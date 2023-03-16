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
    public class ClienteNegocios
    {
        AcessoDadosSql acessoDadosSql = new AcessoDadosSql();

        //Inserir, Alterar, Excluir, Consultar um(s) cliente(s) usando StoreProcedure
        public string Inserir(Pessoa cliente)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@cli_Nome", cliente.Nome);
                acessoDadosSql.AdicionarParametros("@cli_Logradouro", cliente.Logradouro);
                acessoDadosSql.AdicionarParametros("@cli_Numero", cliente.Numero);
                acessoDadosSql.AdicionarParametros("@cli_Bairro", cliente.Bairro);
                acessoDadosSql.AdicionarParametros("@cli_Cidade", cliente.Cidade);
                acessoDadosSql.AdicionarParametros("@cli_Uf", cliente.Uf);
                acessoDadosSql.AdicionarParametros("@cli_Cep", cliente.Cep);
                acessoDadosSql.AdicionarParametros("@cli_CelularUm", cliente.CelularUm);
                acessoDadosSql.AdicionarParametros("@cli_CelularDois", cliente.CelularDois);
                acessoDadosSql.AdicionarParametros("@cli_ContatoFixo", cliente.ContatoFixo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_clienteInserir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Alterar(Pessoa cliente)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@cli_Codigo", cliente.Codigo);
                acessoDadosSql.AdicionarParametros("@cli_Nome", cliente.Nome);
                acessoDadosSql.AdicionarParametros("@cli_Logradouro", cliente.Logradouro);
                acessoDadosSql.AdicionarParametros("@cli_Numero", cliente.Numero);
                acessoDadosSql.AdicionarParametros("@cli_Bairro", cliente.Bairro);
                acessoDadosSql.AdicionarParametros("@cli_Cidade", cliente.Cidade);
                acessoDadosSql.AdicionarParametros("@cli_Uf", cliente.Uf);
                acessoDadosSql.AdicionarParametros("@cli_Cep", cliente.Cep);
                acessoDadosSql.AdicionarParametros("@cli_CelularUm", cliente.CelularUm);
                acessoDadosSql.AdicionarParametros("@cli_CelularDois", cliente.CelularDois);
                acessoDadosSql.AdicionarParametros("@cli_ContatoFixo", cliente.ContatoFixo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_clienteAlterar").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string Excluir(Pessoa cliente)
        {
            try
            {
                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@cli_Codigo", cliente.Codigo);
                return acessoDadosSql.ExecutarManipulacao(CommandType.StoredProcedure, "usp_clienteExcluir").ToString();
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public ClienteColecao ConsultarPorNome(string nome)
        {
            try
            {
                //Criação de uma coleão nova de clientes (aqui está vazio)
                ClienteColecao clienteColecao = new ClienteColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@cli_Nome", nome);

                DataTable dataTablecliente = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_clienteConsultarPorNome");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTablecliente.Rows)
                {
                    //Criar um cliente vazio
                    Pessoa cliente = new Pessoa();

                    //Colocar os dados da linha nele
                    cliente.Codigo = Convert.ToInt32(linha["cli_Cod"]);
                    cliente.Nome = Convert.ToString(linha["cli_Nome"]);
                    cliente.Logradouro = Convert.ToString(linha["cli_Logradouro"]);
                    cliente.Bairro = Convert.ToString(linha["cli_Bairro"]);
                    cliente.Numero = Convert.ToString(linha["cli_Numero"]);
                    cliente.Cidade = Convert.ToString(linha["cli_Cidade"]);
                    cliente.Uf = Convert.ToString(linha["cli_Uf"]);
                    cliente.Cep = Convert.ToString(linha["cli_Cep"]);
                    cliente.CelularUm = Convert.ToString(linha["cli_CelularUm"]);
                    cliente.CelularDois = Convert.ToString(linha["cli_CelularDois"]);
                    cliente.ContatoFixo = Convert.ToString(linha["cli_ContatoFixo"]);

                    //Adicionar ele na coleção
                    clienteColecao.Add(cliente);
                }

                return clienteColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o cliente por Nome.\nDetalhes: " + ex.Message);
            }
        }
        public ClienteColecao ConsultarPorCodigo(int codigo)
        {
            try
            {
                //Criação de uma coleão nova de clientes (aqui está vazio)
                ClienteColecao clienteColecao = new ClienteColecao();

                acessoDadosSql.LimparParametros();
                acessoDadosSql.AdicionarParametros("@cli_Codigo", codigo);

                DataTable dataTablecliente = acessoDadosSql.ExecutarConsulta(CommandType.StoredProcedure, "usp_clienteConsultar");

                //Faz um conjunto de coleção
                foreach (DataRow linha in dataTablecliente.Rows)
                {
                    //Criar um cliente vazio
                    Pessoa cliente = new Pessoa();

                    //Colocar os dados da linha nele
                    cliente.Codigo = Convert.ToInt32(linha["cli_Codigo"]);
                    cliente.Nome = Convert.ToString(linha["cli_Nome"]);
                    cliente.Logradouro = Convert.ToString(linha["cli_Logradouro"]);
                    cliente.Bairro = Convert.ToString(linha["cli_Bairro"]);
                    cliente.Numero = Convert.ToString(linha["cli_Numero"]);
                    cliente.Cidade = Convert.ToString(linha["cli_Cidade"]);
                    cliente.Uf = Convert.ToString(linha["cli_Uf"]);
                    cliente.Cep = Convert.ToString(linha["cli_Cep"]);
                    cliente.CelularUm = Convert.ToString(linha["cli_CelularUm"]);
                    cliente.CelularDois = Convert.ToString(linha["cli_CelularDois"]);
                    cliente.ContatoFixo = Convert.ToString(linha["cli_ContatoFixo"]);

                    //Adicionar ele na coleção
                    clienteColecao.Add(cliente);
                }
                return clienteColecao;
            }
            catch (Exception ex)
            {
                throw new Exception("Não foi possível consultar o cliente por Código.\nDetalhes: " + ex.Message);
            }
        }
    }
}