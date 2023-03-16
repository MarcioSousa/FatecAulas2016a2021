using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dto
{
   public class Pessoa
    {
        public int Codigo { get; set; }
        public string Nome { get; set; }
        public string Logradouro { get; set; }
        public string Numero { get; set; }
        public string Bairro { get; set; }
        public string Cidade { get; set; }
        public string Uf { get; set; }
        public string Cep { get; set; }
        public string CelularUm { get; set; }
        public string CelularDois { get; set; }
        public string ContatoFixo { get; set; }
        public double Custo { get; set; }
    }
}
