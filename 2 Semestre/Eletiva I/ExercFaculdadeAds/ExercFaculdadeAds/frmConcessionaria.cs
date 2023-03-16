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
    public partial class frmConcessionaria : Form
    {
        double dvalorCor;
        double dvalorFabricacao;
        double dvalorIpi;
        double dvalorFrete;
        double dvalorTotal;

        public frmConcessionaria()
        {
            InitializeComponent();
        }

        private void rbdNao_CheckedChanged(object sender, EventArgs e)
        {
            calcularValor();
        }
        private void cbxCor_SelectedIndexChanged(object sender, EventArgs e)
        {
            calcularValor();
        }
        private void cbxDestino_SelectedIndexChanged(object sender, EventArgs e)
        {
            calcularValor();
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Deseja fechar e voltar a tela inicial?", "Encerramento do Formulário", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                Close();
            }
        }
        private void txtValorMontagem_Leave(object sender, EventArgs e)
        {
            calcularValor();
        }
        private void pbxResultado_Click(object sender, EventArgs e)
        {
            //string.Format("{0:C}", 1532.236)
            MessageBox.Show("Calculo de Venda ao Consumidor:\nValor da Cor: R$ " + string.Format("{0:F}", dvalorCor) + "\nValor de Fabricação: R$ " + string.Format("{0:F}", dvalorFabricacao) + "\nValor do IPI: R$ " + string.Format("{0:F}", dvalorIpi) + "\nValor do Frete: R$ " + string.Format("{0:F}", dvalorFrete) + "\n-------------------\nValor de Venda: R$ " + string.Format("{0:F}", dvalorTotal), "Venda da Concessionária");
        }
        private void btnRelogio_Click(object sender, EventArgs e)
        {
            DateTime dataAtual = DateTime.Now;
            MessageBox.Show("Dia e Horário : " + dataAtual, "Data Atual");
        }
        private void btnLimpar_Click(object sender, EventArgs e)
        {
            cbxCor.Text = "";
            cbxDestino.Text = "";
            rbdNao.Checked = true;
            txtValorMontagem.Text = "0";
            txtValorVenda.Text = "0";
            cbxCor.Focus();
        }

        void teste()
        {
            MessageBox.Show("teste");
        }
        void calcularValor()
        {
            try
            {
                if (cbxCor.Text == "" || cbxDestino.Text == "")
                {
                    txtValorVenda.Text = "0";
                }
                else
                {

                    dvalorCor = 0;
                    dvalorFabricacao = 0;
                    dvalorIpi = 0;
                    dvalorFrete = 0;
                    dvalorTotal = 0;

                    dvalorCor = Convert.ToDouble(valorCor(Convert.ToDouble(txtValorMontagem.Text), cbxCor.Text));
                    dvalorFabricacao = Convert.ToDouble(valorFabricacao(Convert.ToDouble(txtValorMontagem.Text), dvalorCor));
                    dvalorIpi = Convert.ToDouble(valorIPI(dvalorFabricacao));

                    if (rbdSim.Checked == true)
                    {
                        dvalorFrete = Convert.ToDouble(valorFrete(cbxDestino.Text));
                    }
                    else
                    {
                        dvalorFrete = 0;
                    }

                    dvalorTotal = dvalorFabricacao + dvalorIpi + dvalorFrete;
                    txtValorVenda.Text = "R$ " + string.Format("{0:0.00}", dvalorTotal);
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show("O correu o segunte erro abaixo:\n" + exc.Message);
                txtValorMontagem.Text = "0";
            }
        }

        /// Fórmulas para Calcular o valor de venda
        /// </summary>
        /// <param name="Fórmulas para Calcular o valor de venda"></param>
        /// /// <returns></returns>
        double valorCor(double valorMontagem, string cor)
        {
            if (cor != "Outras")
            {
                return valorMontagem * 0.01;
            }
            else
            {
                return 0;
            }
        }
        double valorFabricacao(double valorMontagem, double valorCor)
        {
            return valorMontagem + valorCor;
        }
        double valorIPI(double valorFabricacao)
        {
            return valorFabricacao * 0.18;
        }
        double valorFrete(string estado)
        {
            if (estado == "SP" || estado == "RJ")
            {
                return 100;
            }
            else if (estado == "AM")
            {
                return 300;
            }
            else
            {
                return 50;
            }
        }
    }
}