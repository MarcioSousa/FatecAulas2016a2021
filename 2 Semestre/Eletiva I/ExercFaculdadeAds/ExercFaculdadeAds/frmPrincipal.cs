using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExercFaculdadeAds
{
    public partial class frmPrincipal : Form
    {
        public frmPrincipal()
        {
            InitializeComponent();
        }

        private void btnConcessionaria_Click(object sender, EventArgs e)
        {
            frmConcessionaria Concessionaria = new frmConcessionaria();
            Concessionaria.ShowDialog();  
        }

        private void btnLivros_Click(object sender, EventArgs e)
        {
            frmPromocaoLivros Livros = new frmPromocaoLivros();
            Livros.ShowDialog();
        }

        private void btnBicicletas_Click(object sender, EventArgs e)
        {
            frmBicicleta Bicicletas = new frmBicicleta();
            Bicicletas.ShowDialog();
        }

        private void btnEventos_Click(object sender, EventArgs e)
        {
            TipoPagamento Pagamento = new TipoPagamento();
            Pagamento.ShowDialog();
        }
    }
}
