namespace ExercFaculdadeAds
{
    partial class frmConcessionaria
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmConcessionaria));
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rbdNao = new System.Windows.Forms.RadioButton();
            this.rbdSim = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtValorVenda = new System.Windows.Forms.TextBox();
            this.txtValorMontagem = new System.Windows.Forms.TextBox();
            this.cbxCor = new System.Windows.Forms.ComboBox();
            this.cbxDestino = new System.Windows.Forms.ComboBox();
            this.btnRelogio = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pbxResultado = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.btnLimpar = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbxResultado)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Margin = new System.Windows.Forms.Padding(5);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(851, 46);
            this.panel1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Consolas", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Location = new System.Drawing.Point(218, 7);
            this.label1.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(375, 32);
            this.label1.TabIndex = 0;
            this.label1.Text = "Concessionária Fatec Itu";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(15, 57);
            this.label2.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(140, 22);
            this.label2.TabIndex = 1;
            this.label2.Text = "Cor Escolhida";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 100);
            this.label3.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(110, 22);
            this.label3.TabIndex = 2;
            this.label3.Text = "UF Destino";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 43);
            this.label4.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(290, 22);
            this.label4.TabIndex = 3;
            this.label4.Text = "Valor de Venda ao Consumidor";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(15, 255);
            this.label5.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(240, 22);
            this.label5.TabIndex = 4;
            this.label5.Text = "Valor da Montagem    R$";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbdNao);
            this.groupBox1.Controls.Add(this.rbdSim);
            this.groupBox1.Location = new System.Drawing.Point(15, 143);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(202, 80);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Cobra Frete?";
            // 
            // rbdNao
            // 
            this.rbdNao.AutoSize = true;
            this.rbdNao.Checked = true;
            this.rbdNao.Location = new System.Drawing.Point(128, 37);
            this.rbdNao.Name = "rbdNao";
            this.rbdNao.Size = new System.Drawing.Size(58, 26);
            this.rbdNao.TabIndex = 1;
            this.rbdNao.TabStop = true;
            this.rbdNao.Text = "Não";
            this.rbdNao.UseVisualStyleBackColor = true;
            this.rbdNao.CheckedChanged += new System.EventHandler(this.rbdNao_CheckedChanged);
            // 
            // rbdSim
            // 
            this.rbdSim.AutoSize = true;
            this.rbdSim.Location = new System.Drawing.Point(12, 37);
            this.rbdSim.Name = "rbdSim";
            this.rbdSim.Size = new System.Drawing.Size(58, 26);
            this.rbdSim.TabIndex = 0;
            this.rbdSim.Text = "Sim";
            this.rbdSim.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtValorVenda);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Location = new System.Drawing.Point(15, 308);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(494, 94);
            this.groupBox2.TabIndex = 6;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Resultados";
            // 
            // txtValorVenda
            // 
            this.txtValorVenda.Enabled = false;
            this.txtValorVenda.Location = new System.Drawing.Point(300, 40);
            this.txtValorVenda.Name = "txtValorVenda";
            this.txtValorVenda.Size = new System.Drawing.Size(188, 30);
            this.txtValorVenda.TabIndex = 8;
            this.txtValorVenda.Text = "0";
            this.txtValorVenda.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // txtValorMontagem
            // 
            this.txtValorMontagem.Location = new System.Drawing.Point(256, 252);
            this.txtValorMontagem.Name = "txtValorMontagem";
            this.txtValorMontagem.Size = new System.Drawing.Size(117, 30);
            this.txtValorMontagem.TabIndex = 3;
            this.txtValorMontagem.Text = "0";
            this.txtValorMontagem.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtValorMontagem.Leave += new System.EventHandler(this.txtValorMontagem_Leave);
            // 
            // cbxCor
            // 
            this.cbxCor.FormattingEnabled = true;
            this.cbxCor.Items.AddRange(new object[] {
            "Pérola",
            "Cinza",
            "Outras"});
            this.cbxCor.Location = new System.Drawing.Point(163, 54);
            this.cbxCor.Name = "cbxCor";
            this.cbxCor.Size = new System.Drawing.Size(178, 30);
            this.cbxCor.TabIndex = 0;
            this.cbxCor.SelectedIndexChanged += new System.EventHandler(this.cbxCor_SelectedIndexChanged);
            // 
            // cbxDestino
            // 
            this.cbxDestino.FormattingEnabled = true;
            this.cbxDestino.Items.AddRange(new object[] {
            "SP",
            "RJ",
            "AM",
            "Outros"});
            this.cbxDestino.Location = new System.Drawing.Point(133, 97);
            this.cbxDestino.Name = "cbxDestino";
            this.cbxDestino.Size = new System.Drawing.Size(208, 30);
            this.cbxDestino.TabIndex = 1;
            this.cbxDestino.SelectedIndexChanged += new System.EventHandler(this.cbxDestino_SelectedIndexChanged);
            // 
            // btnRelogio
            // 
            this.btnRelogio.AutoSize = true;
            this.btnRelogio.Image = ((System.Drawing.Image)(resources.GetObject("btnRelogio.Image")));
            this.btnRelogio.Location = new System.Drawing.Point(778, 260);
            this.btnRelogio.Name = "btnRelogio";
            this.btnRelogio.Size = new System.Drawing.Size(60, 60);
            this.btnRelogio.TabIndex = 5;
            this.btnRelogio.UseVisualStyleBackColor = true;
            this.btnRelogio.Click += new System.EventHandler(this.btnRelogio_Click);
            // 
            // btnClose
            // 
            this.btnClose.AutoSize = true;
            this.btnClose.Location = new System.Drawing.Point(778, 329);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(60, 60);
            this.btnClose.TabIndex = 6;
            this.btnClose.Text = "&Sair";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pbxResultado
            // 
            this.pbxResultado.Image = ((System.Drawing.Image)(resources.GetObject("pbxResultado.Image")));
            this.pbxResultado.Location = new System.Drawing.Point(440, 100);
            this.pbxResultado.Name = "pbxResultado";
            this.pbxResultado.Size = new System.Drawing.Size(100, 100);
            this.pbxResultado.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pbxResultado.TabIndex = 12;
            this.pbxResultado.TabStop = false;
            this.pbxResultado.Click += new System.EventHandler(this.pbxResultado_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(638, 54);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(200, 200);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 13;
            this.pictureBox2.TabStop = false;
            // 
            // btnLimpar
            // 
            this.btnLimpar.AutoSize = true;
            this.btnLimpar.Font = new System.Drawing.Font("Consolas", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLimpar.Location = new System.Drawing.Point(638, 261);
            this.btnLimpar.Name = "btnLimpar";
            this.btnLimpar.Size = new System.Drawing.Size(66, 28);
            this.btnLimpar.TabIndex = 4;
            this.btnLimpar.Text = "&Limpar";
            this.btnLimpar.UseVisualStyleBackColor = true;
            this.btnLimpar.Click += new System.EventHandler(this.btnLimpar_Click);
            // 
            // frmConcessionaria
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 22F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(850, 431);
            this.Controls.Add(this.btnLimpar);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pbxResultado);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnRelogio);
            this.Controls.Add(this.cbxDestino);
            this.Controls.Add(this.cbxCor);
            this.Controls.Add(this.txtValorMontagem);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(5);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmConcessionaria";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Venda de Veículos";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbxResultado)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton rbdNao;
        private System.Windows.Forms.RadioButton rbdSim;
        private System.Windows.Forms.TextBox txtValorVenda;
        private System.Windows.Forms.TextBox txtValorMontagem;
        private System.Windows.Forms.ComboBox cbxCor;
        private System.Windows.Forms.ComboBox cbxDestino;
        private System.Windows.Forms.Button btnRelogio;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.PictureBox pbxResultado;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Button btnLimpar;
    }
}

