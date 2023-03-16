using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace ProjetoBD1
{
    public partial class frm_Cadastro : Form
    {
        public frm_Cadastro()
        {
            InitializeComponent();
        }

        private void btnConectar_Click(object sender, EventArgs e)
        {
            try
            { 
                string strcon = @"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = 'C:\Users\Aluno - Gti-Ads\Desktop\ProjetoBD1\ProjetoBD1\Empresa.mdf'; Integrated Security = True";
                SqlConnection objconexao = new SqlConnection(strcon);
                objconexao.Open();
                MessageBox.Show("Conectou");
                //objconexao.Close();
            }
            catch (Exception erro)
            {
                MessageBox.Show("Erro de conexão " + erro.Message);
            }
        }
    }
}
