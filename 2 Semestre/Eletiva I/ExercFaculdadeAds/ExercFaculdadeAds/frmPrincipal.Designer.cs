namespace ExercFaculdadeAds
{
    partial class frmPrincipal
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmPrincipal));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnLivros = new System.Windows.Forms.Button();
            this.btnBicicletas = new System.Windows.Forms.Button();
            this.btnEventos = new System.Windows.Forms.Button();
            this.btnConcessionaria = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnLivros);
            this.groupBox1.Controls.Add(this.btnBicicletas);
            this.groupBox1.Controls.Add(this.btnEventos);
            this.groupBox1.Controls.Add(this.btnConcessionaria);
            this.groupBox1.Location = new System.Drawing.Point(23, 22);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(241, 190);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Lista de Exercícios 1";
            // 
            // btnLivros
            // 
            this.btnLivros.AutoSize = true;
            this.btnLivros.Location = new System.Drawing.Point(15, 67);
            this.btnLivros.Name = "btnLivros";
            this.btnLivros.Size = new System.Drawing.Size(210, 32);
            this.btnLivros.TabIndex = 3;
            this.btnLivros.Text = "02 - Livros";
            this.btnLivros.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnLivros.UseVisualStyleBackColor = true;
            this.btnLivros.Click += new System.EventHandler(this.btnLivros_Click);
            // 
            // btnBicicletas
            // 
            this.btnBicicletas.AutoSize = true;
            this.btnBicicletas.Location = new System.Drawing.Point(15, 105);
            this.btnBicicletas.Name = "btnBicicletas";
            this.btnBicicletas.Size = new System.Drawing.Size(210, 32);
            this.btnBicicletas.TabIndex = 2;
            this.btnBicicletas.Text = "03 - Bicicletas";
            this.btnBicicletas.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnBicicletas.UseVisualStyleBackColor = true;
            this.btnBicicletas.Click += new System.EventHandler(this.btnBicicletas_Click);
            // 
            // btnEventos
            // 
            this.btnEventos.AutoSize = true;
            this.btnEventos.Location = new System.Drawing.Point(15, 143);
            this.btnEventos.Name = "btnEventos";
            this.btnEventos.Size = new System.Drawing.Size(210, 32);
            this.btnEventos.TabIndex = 1;
            this.btnEventos.Text = "04 - Eventos";
            this.btnEventos.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnEventos.UseVisualStyleBackColor = true;
            this.btnEventos.Click += new System.EventHandler(this.btnEventos_Click);
            // 
            // btnConcessionaria
            // 
            this.btnConcessionaria.AutoSize = true;
            this.btnConcessionaria.Location = new System.Drawing.Point(15, 29);
            this.btnConcessionaria.Name = "btnConcessionaria";
            this.btnConcessionaria.Size = new System.Drawing.Size(210, 32);
            this.btnConcessionaria.TabIndex = 0;
            this.btnConcessionaria.Text = "01 - Concessionária";
            this.btnConcessionaria.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnConcessionaria.UseVisualStyleBackColor = true;
            this.btnConcessionaria.Click += new System.EventHandler(this.btnConcessionaria_Click);
            // 
            // frmPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 22F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(290, 250);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(5);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmPrincipal";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Aulas de Eletiva I - Profª Angelina Melare.";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnLivros;
        private System.Windows.Forms.Button btnBicicletas;
        private System.Windows.Forms.Button btnEventos;
        private System.Windows.Forms.Button btnConcessionaria;
    }
}