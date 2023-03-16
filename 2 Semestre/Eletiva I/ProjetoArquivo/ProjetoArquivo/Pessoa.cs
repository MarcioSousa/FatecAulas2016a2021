using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjetoArquivo
{
    class Pessoa
    {
        private string _nome;     //atributo nome  //modificador de acesso; encapsulamento
        public string Nome
        {
            get { return _nome; }

            set { _nome = value.ToUpper(); }
        }
        private string _telefone;
        public string Telefone
        {
            get { return _telefone; }

            set { _telefone = value; }
        }
    }
}