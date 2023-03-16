using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace ExercFaculdadeAds
{
    public partial class TipoPagamento : Form
    {
        double vista;
        double prazo;

        public TipoPagamento()
        {
            InitializeComponent();
        }

        private void txtCodigo_Leave(object sender, EventArgs e)
        {
            if (txtCodigo.Text == "")
            {
                MessageBox.Show("Digite um Código para o Pagamento", "Código", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtCodigo.Focus();
            }
        }

        private void btnPagamento_Click(object sender, EventArgs e)
        {
            try
            {
                double total;
                total = Convert.ToDouble(txtValorUnitario.Text) * Convert.ToInt32(txtQtde.Text);
                calcular(total);

                txtTotalVista.Text = vista.ToString("C");
                txtTotalCartao.Text = prazo.ToString("C");
            }
            catch (Exception exc)
            {
                MessageBox.Show("Ocorreu o seguinte erro: " + exc, "Erro no sistema", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        void calcular(double valores)
        {
            vista = valores * 0.95;
            prazo = valores * 1.30;
        }

        private void txtValorUnitario_Leave(object sender, EventArgs e)
        {
            gbxFormaPagamento.Visible = true;
        }

        private void btnCalculadora_Click(object sender, EventArgs e)
        {
            Process.Start("Calc.exe");
        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Deseja Finalizar?", "Finalizar Programa", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                Close();
            }
        }
    }
}
