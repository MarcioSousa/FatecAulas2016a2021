package fatec.poo.view;

import fatec.poo.model.Cliente;
import fatec.poo.model.Pessoa;
import java.util.ArrayList;
import javax.swing.JOptionPane;

/**
 *
 * @author Felipe
 */
public class GuiCliente extends javax.swing.JFrame {

    /**
     * Creates new form GuiCliente
     */
    public GuiCliente(ArrayList<Pessoa> c) {
        initComponents();
        cadCliVend = c;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel4 = new javax.swing.JLabel();
        jTextFieldCEP = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabelLimDisp = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jComboBoxUF = new javax.swing.JComboBox<>();
        jLabel8 = new javax.swing.JLabel();
        jButtonConsultar = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        jButtonIncluir = new javax.swing.JButton();
        jFormattedTextFieldCPF = new javax.swing.JFormattedTextField();
        jButtonAlterar = new javax.swing.JButton();
        jTextFieldNome = new javax.swing.JTextField();
        jButtonExcluir = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jTextFieldEndereco = new javax.swing.JTextField();
        jButtonSair = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jTextFieldCidade = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jTextFieldLimCred = new javax.swing.JTextField();
        jTextFieldFone = new javax.swing.JTextField();
        jTextFieldDdd = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Cliente");
        setName("GuiCliente"); // NOI18N

        jLabel4.setText("Cidade");

        jTextFieldCEP.setEnabled(false);

        jLabel5.setText("Telefone");

        jLabel6.setText("Limite de Crédito");

        jLabelLimDisp.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        jLabelLimDisp.setEnabled(false);

        jLabel7.setText("UF");

        jComboBoxUF.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "SP", "RJ", "DF", "PR" }));
        jComboBoxUF.setEnabled(false);

        jLabel8.setText("CEP");

        jButtonConsultar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/pesq.png"))); // NOI18N
        jButtonConsultar.setText("Consultar");
        jButtonConsultar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonConsultarActionPerformed(evt);
            }
        });

        jLabel9.setText("Limite Disponivel");

        jButtonIncluir.setText("Incluir");
        jButtonIncluir.setEnabled(false);
        jButtonIncluir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonIncluirActionPerformed(evt);
            }
        });

        try {
            jFormattedTextFieldCPF.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("###.###.###-##")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }

        jButtonAlterar.setText("Alterar");
        jButtonAlterar.setEnabled(false);
        jButtonAlterar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonAlterarActionPerformed(evt);
            }
        });

        jTextFieldNome.setEnabled(false);
        jTextFieldNome.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextFieldNomeActionPerformed(evt);
            }
        });

        jButtonExcluir.setText("Excluir");
        jButtonExcluir.setEnabled(false);
        jButtonExcluir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonExcluirActionPerformed(evt);
            }
        });

        jLabel1.setText("CPF");

        jTextFieldEndereco.setEnabled(false);

        jButtonSair.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/exit.png"))); // NOI18N
        jButtonSair.setText("Sair");
        jButtonSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSairActionPerformed(evt);
            }
        });

        jLabel2.setText("Nome");

        jTextFieldCidade.setEnabled(false);

        jLabel3.setText("Endereço");

        jTextFieldLimCred.setEnabled(false);

        jTextFieldFone.setEnabled(false);

        jTextFieldDdd.setEnabled(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(64, 64, 64)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jTextFieldLimCred, javax.swing.GroupLayout.PREFERRED_SIZE, 61, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel9)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabelLimDisp, javax.swing.GroupLayout.PREFERRED_SIZE, 76, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel2)
                                    .addComponent(jLabel1))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jFormattedTextFieldCPF, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jTextFieldNome)))))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(63, 63, 63)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel3)))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGap(77, 77, 77)
                                .addComponent(jLabel5)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jTextFieldEndereco, javax.swing.GroupLayout.PREFERRED_SIZE, 284, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                    .addComponent(jTextFieldCidade, javax.swing.GroupLayout.PREFERRED_SIZE, 213, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jLabel7)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jComboBoxUF, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jTextFieldDdd, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jTextFieldFone, javax.swing.GroupLayout.PREFERRED_SIZE, 71, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel8)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jTextFieldCEP, javax.swing.GroupLayout.PREFERRED_SIZE, 76, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButtonConsultar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonIncluir, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jButtonAlterar, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonExcluir, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jButtonSair)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jFormattedTextFieldCPF, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jTextFieldNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jTextFieldEndereco, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(jLabel7)
                    .addComponent(jTextFieldCidade, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jComboBoxUF, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jLabel8)
                    .addComponent(jTextFieldCEP, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFieldFone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFieldDdd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabelLimDisp, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel6)
                        .addComponent(jLabel9)
                        .addComponent(jTextFieldLimCred, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(30, 30, 30)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonConsultar)
                    .addComponent(jButtonSair)
                    .addComponent(jButtonExcluir)
                    .addComponent(jButtonAlterar)
                    .addComponent(jButtonIncluir))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonConsultarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonConsultarActionPerformed
            int x;
        
        for (x = 0; x < cadCliVend.size(); x++)
        {
         if(cadCliVend.get(x) instanceof Cliente)
         {             
          if (((Cliente)cadCliVend.get(x)).getCpf().equals(jFormattedTextFieldCPF.getText()))
          {
            break;
          }
         }
        }
        if(Pessoa.validarCPF(jFormattedTextFieldCPF.getText())== true)
        {
            if(x < cadCliVend.size()){
                posCliente = x;
            }else{
                posCliente = -1;        
            }
            if(posCliente >= 0)
            {
                jFormattedTextFieldCPF.setText(((Cliente)cadCliVend.get(posCliente)).getCpf());
                jTextFieldNome.setText(cadCliVend.get(posCliente).getNome());
                jTextFieldEndereco.setText(cadCliVend.get(posCliente).getEndereco());
                jTextFieldCidade.setText(cadCliVend.get(posCliente).getCidade());
                jTextFieldDdd.setText(cadCliVend.get(posCliente).getDdd());
                jTextFieldFone.setText(String.valueOf(cadCliVend.get(posCliente).getTelefone()));
                jTextFieldCEP.setText(String.valueOf(cadCliVend.get(posCliente).getCep()));
                jComboBoxUF.setActionCommand(cadCliVend.get(posCliente).getUf());
                jTextFieldLimCred.setText(String.valueOf(((Cliente)cadCliVend.get(posCliente)).getLimiteCred()));
                jLabelLimDisp.setText(String.valueOf(((Cliente)cadCliVend.get(posCliente)).getLimiteDisp()));
                jButtonConsultar.setEnabled(false);
                jButtonIncluir.setEnabled(false);
                jButtonAlterar.setEnabled(true);
                jButtonExcluir.setEnabled(true);
            }
            else
            {
                jButtonConsultar.setEnabled(false);
                jButtonIncluir.setEnabled(true);
                jButtonAlterar.setEnabled(false);
                jButtonExcluir.setEnabled(false);
                jTextFieldNome.requestFocus();
            }
            jFormattedTextFieldCPF.setEnabled(false);
            jTextFieldNome.setEnabled(true);
            jTextFieldEndereco.setEnabled(true);
            jTextFieldCidade.setEnabled(true);
            jTextFieldDdd.setEnabled(true);
            jTextFieldFone.setEnabled(true);   
            jTextFieldCEP.setEnabled(true);   
            jTextFieldLimCred.setEnabled(true);
            jComboBoxUF.setEnabled(true);
        }
        else
        {
         JOptionPane.showMessageDialog(null, "CPF Invalido");
         jFormattedTextFieldCPF.requestFocus();
        }
    }//GEN-LAST:event_jButtonConsultarActionPerformed

    private void jButtonIncluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonIncluirActionPerformed
         Cliente cl = new Cliente(jFormattedTextFieldCPF.getText(), 
                               jTextFieldNome.getText(), 
                               Double.parseDouble(jTextFieldLimCred.getText()));                              
                               cl.setEndereco(jTextFieldEndereco.getText());
                               cl.setCidade(jTextFieldCidade.getText());
                               cl.setDdd(jTextFieldDdd.getText());
                               cl.setTelefone(jTextFieldFone.getText());
                               cl.setCep(jTextFieldCEP.getText());
                               cl.setUf(jComboBoxUF.getActionCommand());
                               
        cadCliVend.add(cl);
        
        
        jFormattedTextFieldCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEndereco.setText(null);
        jTextFieldCidade.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCEP.setText(null);
        jTextFieldLimCred.setText(null);
        jLabelLimDisp.setText(null);
        jComboBoxUF.setActionCommand(null);
        jButtonConsultar.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonExcluir.setEnabled(false);
        
        jFormattedTextFieldCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEndereco.setEnabled(false);
        jTextFieldCidade.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCEP.setEnabled(false);   
        jComboBoxUF.setEnabled(false);    
        jTextFieldLimCred.setEnabled(false);
       
        jFormattedTextFieldCPF.requestFocus();
    }//GEN-LAST:event_jButtonIncluirActionPerformed

    private void jButtonAlterarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAlterarActionPerformed
        jFormattedTextFieldCPF.setEnabled(false);
        cadCliVend.get(posCliente).setNome(jTextFieldNome.getName());
        cadCliVend.get(posCliente).setEndereco(jTextFieldEndereco.getText());
        cadCliVend.get(posCliente).setCidade(jTextFieldCidade.getText());
        cadCliVend.get(posCliente).setTelefone(jTextFieldFone.getText());
        cadCliVend.get(posCliente).setCep(jTextFieldCEP.getText());
        cadCliVend.get(posCliente).setUf(jComboBoxUF.getActionCommand());
        ((Cliente)cadCliVend.get(posCliente)).setLimiteCred(Double.parseDouble(jTextFieldLimCred.getText()));
        ((Cliente)cadCliVend.get(posCliente)).setLimiteDisp(Double.parseDouble(jLabelLimDisp.getText()));
        jFormattedTextFieldCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEndereco.setText(null);
        jTextFieldCidade.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCEP.setText(null);
        jTextFieldLimCred.setText(null);
        jLabelLimDisp.setText(null);
        jComboBoxUF.setActionCommand(null);
        jButtonConsultar.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonIncluir.setEnabled(false);
        
        jFormattedTextFieldCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEndereco.setEnabled(false);
        jTextFieldCidade.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCEP.setEnabled(false);   
        jTextFieldLimCred.setEnabled(false);
        jComboBoxUF.setEnabled(false);    
        jFormattedTextFieldCPF.requestFocus();
    }//GEN-LAST:event_jButtonAlterarActionPerformed

    private void jTextFieldNomeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldNomeActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextFieldNomeActionPerformed

    private void jButtonExcluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonExcluirActionPerformed
        if (posCliente >= 0){
            cadCliVend.remove(posCliente);
            posCliente = -1;
        }
        
        jFormattedTextFieldCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEndereco.setText(null);
        jTextFieldCidade.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCEP.setText(null);
        jTextFieldLimCred.setText(null);
        jLabelLimDisp.setText(null);
        jComboBoxUF.setActionCommand(null);
        jButtonConsultar.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonIncluir.setEnabled(false);        
        
        jFormattedTextFieldCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEndereco.setEnabled(false);
        jTextFieldCidade.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCEP.setEnabled(false);   
        jTextFieldLimCred.setEnabled(false);
        jComboBoxUF.setEnabled(false);    
        jFormattedTextFieldCPF.requestFocus();

    }//GEN-LAST:event_jButtonExcluirActionPerformed

    private void jButtonSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSairActionPerformed
        dispose();
    }//GEN-LAST:event_jButtonSairActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GuiCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GuiCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GuiCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GuiCliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAlterar;
    private javax.swing.JButton jButtonConsultar;
    private javax.swing.JButton jButtonExcluir;
    private javax.swing.JButton jButtonIncluir;
    private javax.swing.JButton jButtonSair;
    private javax.swing.JComboBox<String> jComboBoxUF;
    private javax.swing.JFormattedTextField jFormattedTextFieldCPF;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLabelLimDisp;
    private javax.swing.JTextField jTextFieldCEP;
    private javax.swing.JTextField jTextFieldCidade;
    private javax.swing.JTextField jTextFieldDdd;
    private javax.swing.JTextField jTextFieldEndereco;
    private javax.swing.JTextField jTextFieldFone;
    private javax.swing.JTextField jTextFieldLimCred;
    private javax.swing.JTextField jTextFieldNome;
    // End of variables declaration//GEN-END:variables
    private ArrayList<Pessoa> cadCliVend;
    private int posCliente;
}
