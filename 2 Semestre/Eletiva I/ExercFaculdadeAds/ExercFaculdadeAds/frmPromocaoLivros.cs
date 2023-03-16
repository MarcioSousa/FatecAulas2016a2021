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
    public partial class frmPromocaoLivros : Form
    {
        public frmPromocaoLivros()
        {
            InitializeComponent();
        }

        private void txtNomeLivro_Leave(object sender, EventArgs e)
        {
            txtNomeLivro.Text = txtNomeLivro.Text.ToLower();
            abreFechaCampos();
        }

        private void btnLimpar_Click(object sender, EventArgs e)
        {
            txtNomeLivro.Text = "";
            txtQtdeVendida.Text = "";
            txtNomeLivro.Focus();
        }

        private void btnCalcular_Click(object sender, EventArgs e)
        {
            if (cbxCategoria.Text == "Romance" || cbxCategoria.Text == "Aventura")
            {
                txtValorPagar.Text = (Convert.ToDouble(txtQtdeVendida.Text) * 10).ToString("C");
            }
            else
            {
                txtValorPagar.Text = (Convert.ToDouble(txtQtdeVendida.Text) * 20).ToString("C");
            }
        }

        private void cbxCategoria_Leave(object sender, EventArgs e)
        {
            abreFechaCampos();
        }

        private void txtQtdeVendida_Leave(object sender, EventArgs e)
        {
            abreFechaCampos();
        }

        private void txtNomeLivro_TextChanged(object sender, EventArgs e)
        {
            if (txtNomeLivro.Text != "" && txtQtdeVendida.Text != "" && cbxCategoria.Text != "")
            {
                btnCalcular.Enabled = true;
                btnConfirmar.Enabled = true;
                btnLimpar.Enabled = true;
            }
            else
            {
                btnCalcular.Enabled = false;
                btnConfirmar.Enabled = false;
            }
        }

        private void cbxCategoria_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (txtNomeLivro.Text != "" && txtQtdeVendida.Text != "" && cbxCategoria.Text != "")
            {
                btnCalcular.Enabled = true;
                btnConfirmar.Enabled = true;
                btnLimpar.Enabled = true;
            }
            else
            {
                btnCalcular.Enabled = false;
                btnConfirmar.Enabled = false;
            }
        }

        private void txtQtdeVendida_TextChanged(object sender, EventArgs e)
        {
            if (txtNomeLivro.Text != "" && txtQtdeVendida.Text != "" && cbxCategoria.Text != "")
            {
                btnCalcular.Enabled = true;
                btnConfirmar.Enabled = true;
                btnLimpar.Enabled = true;
            }
            else
            {
                btnCalcular.Enabled = false;
                btnConfirmar.Enabled = false;
            }
        }

        void abreFechaCampos()
        {
            if (txtNomeLivro.Text != "" && txtQtdeVendida.Text != "" && cbxCategoria.Text != "")
            {
                btnConfirmar.Enabled = true;
                btnCalcular.Enabled = true;
                btnLimpar.Enabled = true;
            }
            else if (txtNomeLivro.Text != "")
            {
                btnLimpar.Enabled = true;
            }
            else if (txtQtdeVendida.Text != "")
            {
                btnLimpar.Enabled = true;
            }
            else if (cbxCategoria.Text != "")
            {
                btnLimpar.Enabled = true;
            }
            else
            {
                btnLimpar.Enabled = false;
            }
        }
    }
}