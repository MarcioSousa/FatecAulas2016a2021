namespace ExercFaculdadeAds
{
    partial class TipoPagamento
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtTotalVista = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.txtTotalCartao = new System.Windows.Forms.TextBox();
            this.gbxFormaPagamento = new System.Windows.Forms.GroupBox();
            this.rbtAvista = new System.Windows.Forms.RadioButton();
            this.rbtCartao = new System.Windows.Forms.RadioButton();
            this.btnPagamento = new System.Windows.Forms.Button();
            this.btnSair = new System.Windows.Forms.Button();
            this.btnCalculadora = new System.Windows.Forms.Button();
            this.txtCodigo = new System.Windows.Forms.TextBox();
            this.txtQtde = new System.Windows.Forms.TextBox();
            this.txtValorUnitario = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2.SuspendLayout();
            this.gbxFormaPagamento.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.txtTotalVista);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.txtTotalCartao);
            this.groupBox2.Location = new System.Drawing.Point(24, 169);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(5);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(5);
            this.groupBox2.Size = new System.Drawing.Size(663, 73);
            this.groupBox2.TabIndex = 27;
            this.groupBox2.TabStop = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(23, 31);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(140, 22);
            this.label6.TabIndex = 5;
            this.label6.Text = "Total a Vista";
            // 
            // txtTotalVista
            // 
            this.txtTotalVista.Location = new System.Drawing.Point(169, 28);
            this.txtTotalVista.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.txtTotalVista.Name = "txtTotalVista";
            this.txtTotalVista.Size = new System.Drawing.Size(148, 30);
            this.txtTotalVista.TabIndex = 0;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(359, 31);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(130, 22);
            this.label7.TabIndex = 6;
            this.label7.Text = "Total Cartão";
            // 
            // txtTotalCartao
            // 
            this.txtTotalCartao.Location = new System.Drawing.Point(495, 28);
            this.txtTotalCartao.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.txtTotalCartao.Name = "txtTotalCartao";
            this.txtTotalCartao.Size = new System.Drawing.Size(148, 30);
            this.txtTotalCartao.TabIndex = 1;
            // 
            // gbxFormaPagamento
            // 
            this.gbxFormaPagamento.Controls.Add(this.rbtAvista);
            this.gbxFormaPagamento.Controls.Add(this.rbtCartao);
            this.gbxFormaPagamento.Location = new System.Drawing.Point(24, 80);
            this.gbxFormaPagamento.Margin = new System.Windows.Forms.Padding(5);
            this.gbxFormaPagamento.Name = "gbxFormaPagamento";
            this.gbxFormaPagamento.Padding = new System.Windows.Forms.Padding(5);
            this.gbxFormaPagamento.Size = new System.Drawing.Size(295, 79);
            this.gbxFormaPagamento.TabIndex = 4;
            this.gbxFormaPagamento.TabStop = false;
            this.gbxFormaPagamento.Text = "Forma de Pagamento";
            this.gbxFormaPagamento.Visible = false;
            // 
            // rbtAvista
            // 
            this.rbtAvista.AutoSize = true;
            this.rbtAvista.Checked = true;
            this.rbtAvista.Location = new System.Drawing.Point(52, 33);
            this.rbtAvista.Margin = new System.Windows.Forms.Padding(5);
            this.rbtAvista.Name = "rbtAvista";
            this.rbtAvista.Size = new System.Drawing.Size(98, 26);
            this.rbtAvista.TabIndex = 0;
            this.rbtAvista.TabStop = true;
            this.rbtAvista.Text = "à vista";
            this.rbtAvista.UseVisualStyleBackColor = true;
            // 
            // rbtCartao
            // 
            this.rbtCartao.AutoSize = true;
            this.rbtCartao.Location = new System.Drawing.Point(189, 33);
            this.rbtCartao.Margin = new System.Windows.Forms.Padding(5);
            this.rbtCartao.Name = "rbtCartao";
            this.rbtCartao.Size = new System.Drawing.Size(88, 26);
            this.rbtCartao.TabIndex = 1;
            this.rbtCartao.Text = "Cartão";
            this.rbtCartao.UseVisualStyleBackColor = true;
            // 
            // btnPagamento
            // 
            this.btnPagamento.AutoSize = true;
            this.btnPagamento.Location = new System.Drawing.Point(731, 73);
            this.btnPagamento.Margin = new System.Windows.Forms.Padding(5);
            this.btnPagamento.Name = "btnPagamento";
            this.btnPagamento.Size = new System.Drawing.Size(130, 32);
            this.btnPagamento.TabIndex = 5;
            this.btnPagamento.Text = "&Pagamento";
            this.btnPagamento.UseVisualStyleBackColor = true;
            this.btnPagamento.Click += new System.EventHandler(this.btnPagamento_Click);
            // 
            // btnSair
            // 
            this.btnSair.AutoSize = true;
            this.btnSair.Location = new System.Drawing.Point(659, 115);
            this.btnSair.Margin = new System.Windows.Forms.Padding(5);
            this.btnSair.Name = "btnSair";
            this.btnSair.Size = new System.Drawing.Size(130, 32);
            this.btnSair.TabIndex = 6;
            this.btnSair.Text = "&Sair";
            this.btnSair.UseVisualStyleBackColor = true;
            this.btnSair.Click += new System.EventHandler(this.btnSair_Click);
            // 
            // btnCalculadora
            // 
            this.btnCalculadora.AutoSize = true;
            this.btnCalculadora.Location = new System.Drawing.Point(591, 73);
            this.btnCalculadora.Margin = new System.Windows.Forms.Padding(5);
            this.btnCalculadora.Name = "btnCalculadora";
            this.btnCalculadora.Size = new System.Drawing.Size(130, 32);
            this.btnCalculadora.TabIndex = 3;
            this.btnCalculadora.Text = "&Calculadora";
            this.btnCalculadora.UseVisualStyleBackColor = true;
            this.btnCalculadora.Click += new System.EventHandler(this.btnCalculadora_Click);
            // 
            // txtCodigo
            // 
            this.txtCodigo.Location = new System.Drawing.Point(85, 22);
            this.txtCodigo.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.txtCodigo.Name = "txtCodigo";
            this.txtCodigo.Size = new System.Drawing.Size(73, 30);
            this.txtCodigo.TabIndex = 0;
            this.txtCodigo.Leave += new System.EventHandler(this.txtCodigo_Leave);
            // 
            // txtQtde
            // 
            this.txtQtde.Location = new System.Drawing.Point(255, 20);
            this.txtQtde.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.txtQtde.Name = "txtQtde";
            this.txtQtde.Size = new System.Drawing.Size(73, 30);
            this.txtQtde.TabIndex = 1;
            // 
            // txtValorUnitario
            // 
            this.txtValorUnitario.Location = new System.Drawing.Point(539, 22);
            this.txtValorUnitario.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.txtValorUnitario.Name = "txtValorUnitario";
            this.txtValorUnitario.Size = new System.Drawing.Size(148, 30);
            this.txtValorUnitario.TabIndex = 2;
            this.txtValorUnitario.Leave += new System.EventHandler(this.txtValorUnitario_Leave);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(383, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(150, 22);
            this.label3.TabIndex = 19;
            this.label3.Text = "Valor Unitário";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(199, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 22);
            this.label2.TabIndex = 18;
            this.label2.Text = "Qtde";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 22);
            this.label1.TabIndex = 17;
            this.label1.Text = "Códig";
            // 
            // TipoPagamento
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 22F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(886, 277);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.gbxFormaPagamento);
            this.Controls.Add(this.btnPagamento);
            this.Controls.Add(this.btnSair);
            this.Controls.Add(this.btnCalculadora);
            this.Controls.Add(this.txtCodigo);
            this.Controls.Add(this.txtQtde);
            this.Controls.Add(this.txtValorUnitario);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "TipoPagamento";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TipoPagamento";
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.gbxFormaPagamento.ResumeLayout(false);
            this.gbxFormaPagamento.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtTotalVista;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtTotalCartao;
        private System.Windows.Forms.GroupBox gbxFormaPagamento;
        private System.Windows.Forms.RadioButton rbtAvista;
        private System.Windows.Forms.RadioButton rbtCartao;
        private System.Windows.Forms.Button btnPagamento;
        private System.Windows.Forms.Button btnSair;
        private System.Windows.Forms.Button btnCalculadora;
        private System.Windows.Forms.TextBox txtCodigo;
        private System.Windows.Forms.TextBox txtQtde;
        private System.Windows.Forms.TextBox txtValorUnitario;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}