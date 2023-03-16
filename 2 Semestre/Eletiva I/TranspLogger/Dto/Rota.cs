using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dto
{
    public class Rota
    {
        public int Codigo { get; set; }
        public string Origem { get; set; }
        public string Destino { get; set; }
        public int Km { get; set; }
        public int Horas { get; set; }
        public double CodPedagio { get; set; }
    }
}
