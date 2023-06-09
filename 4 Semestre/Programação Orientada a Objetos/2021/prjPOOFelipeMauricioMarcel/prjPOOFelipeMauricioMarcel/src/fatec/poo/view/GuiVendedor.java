package fatec.poo.view;

import fatec.poo.model.Pessoa;
import fatec.poo.model.Vendedor;
import java.util.ArrayList;
import java.util.HashSet;
import javax.swing.JOptionPane;

/**
 *
 * @author Felipe
 */
public class GuiVendedor extends javax.swing.JFrame {

    /**
     * Creates new form GuiVendedor
     */
    public GuiVendedor(ArrayList<Pessoa> c) {
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

        jTextFieldNome = new javax.swing.JTextField();
        jTextFieldEnd = new javax.swing.JTextField();
        jTextFieldCid = new javax.swing.JTextField();
        jTextFieldCep = new javax.swing.JTextField();
        jTextFieldDdd = new javax.swing.JTextField();
        jTextFieldFone = new javax.swing.JTextField();
        jTextFieldComissao = new javax.swing.JTextField();
        jTextFieldSalBase = new javax.swing.JTextField();
        jComboBoxUf = new javax.swing.JComboBox<>();
        jFormattedTxtCPF = new javax.swing.JFormattedTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jButtonConsult = new javax.swing.JButton();
        jButtonIncluir = new javax.swing.JButton();
        jButtonAlterar = new javax.swing.JButton();
        jButtonExcluir = new javax.swing.JButton();
        jButtonSair = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Vendedor");
        setName("GuiVendedor"); // NOI18N

        jTextFieldNome.setEnabled(false);

        jTextFieldEnd.setEnabled(false);

        jTextFieldCid.setEnabled(false);

        jTextFieldCep.setEnabled(false);

        jTextFieldDdd.setEnabled(false);

        jTextFieldFone.setEnabled(false);

        jTextFieldComissao.setEnabled(false);

        jTextFieldSalBase.setEnabled(false);

        jComboBoxUf.setEnabled(false);

        try {
            jFormattedTxtCPF.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.MaskFormatter("###.###.###-##")));
        } catch (java.text.ParseException ex) {
            ex.printStackTrace();
        }
        jFormattedTxtCPF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jFormattedTxtCPFActionPerformed(evt);
            }
        });

        jLabel1.setText("CPF");

        jLabel2.setText("Nome");

        jLabel3.setText("Endereço");

        jLabel4.setText("Cidade");

        jLabel8.setText("CEP");

        jLabel6.setText("Salario Base");

        jLabel9.setText("Taxa Comissão");

        jLabel5.setText("Telefone");

        jLabel7.setText("UF");

        jButtonConsult.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/pesq.png"))); // NOI18N
        jButtonConsult.setText("Consultar");
        jButtonConsult.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonConsultActionPerformed(evt);
            }
        });

        jButtonIncluir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/add.png"))); // NOI18N
        jButtonIncluir.setText("Incluir");
        jButtonIncluir.setEnabled(false);
        jButtonIncluir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonIncluirActionPerformed(evt);
            }
        });

        jButtonAlterar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Alterar.png"))); // NOI18N
        jButtonAlterar.setText("Alterar");
        jButtonAlterar.setEnabled(false);
        jButtonAlterar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonAlterarActionPerformed(evt);
            }
        });

        jButtonExcluir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/Eraser.png"))); // NOI18N
        jButtonExcluir.setText("Excluir");
        jButtonExcluir.setEnabled(false);
        jButtonExcluir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonExcluirActionPerformed(evt);
            }
        });

        jButtonSair.setIcon(new javax.swing.ImageIcon(getClass().getResource("/fatec/poo/view/icon/exit.png"))); // NOI18N
        jButtonSair.setText("Sair");
        jButtonSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSairActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(23, 23, 23)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2)
                            .addComponent(jLabel3)
                            .addComponent(jLabel4)
                            .addComponent(jLabel8)))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 69, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jFormattedTxtCPF, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jTextFieldCid)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel7)
                        .addGap(10, 10, 10)
                        .addComponent(jComboBoxUf, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(43, 43, 43))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jTextFieldNome, javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextFieldEnd, javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jTextFieldCep, javax.swing.GroupLayout.PREFERRED_SIZE, 98, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel5)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jTextFieldDdd, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(3, 3, 3))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jTextFieldSalBase, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel9)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jTextFieldComissao)
                                    .addComponent(jTextFieldFone, javax.swing.GroupLayout.DEFAULT_SIZE, 83, Short.MAX_VALUE))))
                        .addGap(54, 54, 54))))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButtonConsult)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButtonIncluir)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonAlterar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonExcluir)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonSair)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jFormattedTxtCPF, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldEnd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldCid, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jComboBoxUf, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4)
                    .addComponent(jLabel7))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldFone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFieldDdd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFieldCep, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8)
                    .addComponent(jLabel5))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldComissao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFieldSalBase, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(jLabel9))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonConsult)
                    .addComponent(jButtonSair)
                    .addComponent(jButtonExcluir)
                    .addComponent(jButtonAlterar)
                    .addComponent(jButtonIncluir))
                .addGap(37, 37, 37))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jFormattedTxtCPFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jFormattedTxtCPFActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jFormattedTxtCPFActionPerformed

    private void jButtonSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSairActionPerformed
        dispose();
    }//GEN-LAST:event_jButtonSairActionPerformed

    private void jButtonConsultActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonConsultActionPerformed
        int x;
        for (x = 0; x < cadCliVend.size(); x++){
         if(cadCliVend.get(x) instanceof Vendedor)
            if (((Vendedor)cadCliVend.get(x)).getCpf().equals(jFormattedTxtCPF.getText())){
            break;
            }
       
      }
         if(Pessoa.validarCPF(jFormattedTxtCPF.getText())== true){
        if(x < cadCliVend.size()){
         posVendedor = x;
        }else{
         posVendedor = -1;
        
        }
      if(posVendedor >= 0){
        jFormattedTxtCPF.setText(((Vendedor)cadCliVend.get(posVendedor)).getCpf());
        jTextFieldNome.setText(cadCliVend.get(posVendedor).getNome());
        jTextFieldEnd.setText(cadCliVend.get(posVendedor).getEndereco());
        jTextFieldCid.setText(cadCliVend.get(posVendedor).getCidade());
        jTextFieldDdd.setText(cadCliVend.get(posVendedor).getCidade());
        jTextFieldFone.setText(String.valueOf(cadCliVend.get(posVendedor).getTelefone()));
        jTextFieldCep.setText(String.valueOf(cadCliVend.get(posVendedor).getCep()));
        jComboBoxUf.setActionCommand(cadCliVend.get(posVendedor).getUf());
        jTextFieldSalBase.setText(String.valueOf(((Vendedor)cadCliVend.get(posVendedor)).getSalarioBase()));
        jTextFieldComissao.setText(String.valueOf(((Vendedor)cadCliVend.get(posVendedor)).getTaxaComissao()));
            jButtonConsult.setEnabled(false);
            jButtonIncluir.setEnabled(false);
            jButtonAlterar.setEnabled(true);
            jButtonExcluir.setEnabled(true);
      }else{
            jButtonConsult.setEnabled(false);
            jButtonIncluir.setEnabled(true);
            jButtonAlterar.setEnabled(false);
            jButtonExcluir.setEnabled(false);
            jTextFieldNome.requestFocus();
      

      }
        jFormattedTxtCPF.setEnabled(false);
        jTextFieldNome.setEnabled(true);
        jTextFieldEnd.setEnabled(true);
        
        jTextFieldCid.setEnabled(true);
        jTextFieldDdd.setEnabled(true);
        jTextFieldFone.setEnabled(true);   
        jTextFieldCep.setEnabled(true);   
        jTextFieldSalBase.setEnabled(true);
        jTextFieldComissao.setEnabled(true);
        jComboBoxUf.setEnabled(true);
        
        }else{
         JOptionPane.showMessageDialog(null, "CPF INVALIDO");
         jFormattedTxtCPF.requestFocus();
        }
    }//GEN-LAST:event_jButtonConsultActionPerformed

    private void jButtonIncluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonIncluirActionPerformed
        Vendedor vend = new Vendedor(jFormattedTxtCPF.getText(), 
                               jTextFieldNome.getText(), 
                               Double.parseDouble(jTextFieldSalBase.getText()));
                              
                               vend.setEndereco(jTextFieldEnd.getText());
                               vend.setCidade(jTextFieldCid.getText());
                               vend.setDdd(jTextFieldDdd.getText());
                               vend.setTelefone(jTextFieldFone.getText());
                               vend.setCep(jTextFieldCep.getText());
                               vend.setUf(jComboBoxUf.getActionCommand());
                               vend.setTaxaComissao(Double.parseDouble(jTextFieldComissao.getText()));
        cadCliVend.add(vend);        
        
        jFormattedTxtCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEnd.setText(null);
        jTextFieldCid.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCep.setText(null);
        jTextFieldSalBase.setText(null);
        jComboBoxUf.setActionCommand(null);
        jTextFieldComissao.setText(null);
        jButtonConsult.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonExcluir.setEnabled(false);       
        jFormattedTxtCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEnd.setEnabled(false);
        jTextFieldCid.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCep.setEnabled(false);   
        jComboBoxUf.setEnabled(false);    
        jTextFieldSalBase.setEnabled(false);
        jTextFieldComissao.setEnabled(false);
        jFormattedTxtCPF.requestFocus();
    }//GEN-LAST:event_jButtonIncluirActionPerformed

    private void jButtonAlterarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAlterarActionPerformed
        jFormattedTxtCPF.setEnabled(false);
        cadCliVend.get(posVendedor).setNome(jTextFieldNome.getText());
        cadCliVend.get(posVendedor).setEndereco(jTextFieldEnd.getText());
        cadCliVend.get(posVendedor).setCidade(jTextFieldCid.getText());
        cadCliVend.get(posVendedor).setDdd(jTextFieldDdd.getText());        
        cadCliVend.get(posVendedor).setTelefone(jTextFieldFone.getText());
        cadCliVend.get(posVendedor).setCep(jTextFieldCep.getText());
        cadCliVend.get(posVendedor).setUf(jComboBoxUf.getActionCommand());
        ((Vendedor)cadCliVend.get(posVendedor)).setSalarioBase(Double.parseDouble(jTextFieldSalBase.getText()));
        ((Vendedor)cadCliVend.get(posVendedor)).setTaxaComissao(Double.parseDouble(jTextFieldComissao.getText()));
        
        jFormattedTxtCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEnd.setText(null);
        jTextFieldCid.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCep.setText(null);
        jTextFieldSalBase.setText(null);
        jComboBoxUf.setActionCommand(null);
        jTextFieldComissao.setText(null);
        jButtonConsult.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonExcluir.setEnabled(false);       
        jFormattedTxtCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEnd.setEnabled(false);
        jTextFieldCid.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCep.setEnabled(false);   
        jComboBoxUf.setEnabled(false);    
        jTextFieldSalBase.setEnabled(false);
        jTextFieldComissao.setEnabled(false);
        jFormattedTxtCPF.requestFocus();
    }//GEN-LAST:event_jButtonAlterarActionPerformed

    private void jButtonExcluirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonExcluirActionPerformed
        if (posVendedor >= 0)
        {
            cadCliVend.remove(posVendedor);
            posVendedor = -1;
        }
        jFormattedTxtCPF.setText(null);
        jTextFieldNome.setText(null);
        jTextFieldEnd.setText(null);
        jTextFieldCid.setText(null);
        jTextFieldDdd.setText(null);
        jTextFieldFone.setText(null);
        jTextFieldCep.setText(null);
        jTextFieldSalBase.setText(null);
        jComboBoxUf.setActionCommand(null);
        jTextFieldComissao.setText(null);
        jButtonConsult.setEnabled(true);
        jButtonIncluir.setEnabled(false);
        jButtonAlterar.setEnabled(false);
        jButtonExcluir.setEnabled(false);       
        jFormattedTxtCPF.setEnabled(true);
        jTextFieldNome.setEnabled(false);
        jTextFieldEnd.setEnabled(false);
        jTextFieldCid.setEnabled(false);
        jTextFieldDdd.setEnabled(false);
        jTextFieldFone.setEnabled(false);   
        jTextFieldCep.setEnabled(false);   
        jComboBoxUf.setEnabled(false);    
        jTextFieldSalBase.setEnabled(false);
        jTextFieldComissao.setEnabled(false);
        jFormattedTxtCPF.requestFocus();
    }//GEN-LAST:event_jButtonExcluirActionPerformed

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
            java.util.logging.Logger.getLogger(GuiVendedor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GuiVendedor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GuiVendedor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GuiVendedor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new GuiVendedor().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAlterar;
    private javax.swing.JButton jButtonConsult;
    private javax.swing.JButton jButtonExcluir;
    private javax.swing.JButton jButtonIncluir;
    private javax.swing.JButton jButtonSair;
    private javax.swing.JComboBox<String> jComboBoxUf;
    private javax.swing.JFormattedTextField jFormattedTxtCPF;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JTextField jTextFieldCep;
    private javax.swing.JTextField jTextFieldCid;
    private javax.swing.JTextField jTextFieldComissao;
    private javax.swing.JTextField jTextFieldDdd;
    private javax.swing.JTextField jTextFieldEnd;
    private javax.swing.JTextField jTextFieldFone;
    private javax.swing.JTextField jTextFieldNome;
    private javax.swing.JTextField jTextFieldSalBase;
    // End of variables declaration//GEN-END:variables
    private ArrayList<Pessoa> cadCliVend;
    private int posVendedor;

}
