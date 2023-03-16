using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ProjetoArquivo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnGerarTxt_Click(object sender, EventArgs e)
        {
            Pessoa cadastro = new Pessoa();
            cadastro.Nome = txtNome.Text;
            cadastro.Telefone = txtTelefone.Text;

            StreamWriter arquivo = new StreamWriter("cadastro.txt", true);
            arquivo.WriteLine("Cadastro de Clientes");
            arquivo.WriteLine("========================");
            arquivo.WriteLine("Cadastro em " + DateTime.Now);
            arquivo.WriteLine("Nome: " + cadastro.Nome);
            arquivo.WriteLine("Telefone: " + cadastro.Telefone);
            arquivo.Close();
        }

        private void btnGerarHtml_Click(object sender, EventArgs e)
        {
            Pessoa cadastro = new Pessoa();
            cadastro.Nome = txtNome.Text;
            cadastro.Telefone = txtTelefone.Text;
        }
    }
}