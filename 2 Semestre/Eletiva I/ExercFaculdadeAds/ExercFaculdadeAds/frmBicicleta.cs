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
    public partial class frmBicicleta : Form
    {
        double vLucro;
        double vSalarioVendedor;

        public frmBicicleta()
        {
            InitializeComponent();
        }

        private void btnLucro_Click(object sender, EventArgs e)
        {
            try
            {
 Lucro(Convert.ToDouble(txtPreco.Text));
            SalarioTotal(Convert.ToInt32(txtQtde.Text), Convert.ToDouble(txtPreco.Text), Convert.ToDouble(txtSalario.Text));
            MessageBox.Show("Salário Mínimo é: " + (Convert.ToDouble(txtSalario.Text)).ToString("C") + "\nPreço por Unidade: " + (Convert.ToInt32(txtPreco.Text)).ToString("C") + "\n Foram vendidos " + Convert.ToInt32(txtQtde.Text) + " bykes.\n--------------------\nSalário Final do Empregado: " + (vSalarioVendedor).ToString("C") + "\nLucro líquido: " + (vLucro * Convert.ToInt32(txtQtde.Text)).ToString("C"), "Resultado Final", MessageBoxButtons.OK,MessageBoxIcon.Information);
            limpaCampos();
            }
            catch (Exception)
            {
                MessageBox.Show("Aconteceu algo de errado, tente novamente!", "Erro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                limpaCampos();
            }
           
        }
        void Lucro(double preco)
        {
            vLucro = preco * 0.1;
        }
        void SalarioTotal(int qtdeVendida, double preco, double salario)
        {
            double valorTotal = 0;

            for (int t = 0; t < qtdeVendida; t++)
            {
                valorTotal = valorTotal + (preco * 0.015);
            }

            vSalarioVendedor = (salario * 2) + valorTotal;
        }
        void limpaCampos()
        {
            txtSalario.Text = "";
            txtPreco.Text = "";
            txtQtde.Text = "";
        }
        private void btnEncerrar_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Deseja encerrar esse sistema?", "Encerramento", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.OK)
            {
                Close();
            } 
        }
    }
}