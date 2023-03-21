package fatec.poo.view;

import fatec.poo.model.Cliente;
import fatec.poo.model.Pedido;
import fatec.poo.model.Pessoa;
import fatec.poo.model.Produto;
import fatec.poo.model.Vendedor;
import java.util.ArrayList;

/**
 *
 * @author Felipe
 */
public class GuiMenu extends javax.swing.JFrame {

    /**
     * Creates new form GuiMenu
     */
    public GuiMenu() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenuCadastros = new javax.swing.JMenu();
        jMenuClientes = new javax.swing.JMenuItem();
        jMenuVendedores = new javax.swing.JMenuItem();
        jMenuProdutos = new javax.swing.JMenuItem();
        jMenuSair = new javax.swing.JMenuItem();
        jMenuPedido = new javax.swing.JMenu();
        jMenuEmitPedido = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Controle de Vendas");
        setName("GuiMenu"); // NOI18N

        jMenuBar1.setName("jMenuBar"); // NOI18N

        jMenuCadastros.setText("Cadastros");

        jMenuClientes.setText("Clientes");
        jMenuClientes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuClientesActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuClientes);

        jMenuVendedores.setText("Vendedores");
        jMenuVendedores.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuVendedoresActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuVendedores);

        jMenuProdutos.setText("Produtos");
        jMenuProdutos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuProdutosActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuProdutos);

        jMenuSair.setText("Sair");
        jMenuSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuSairActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuSair);

        jMenuBar1.add(jMenuCadastros);

        jMenuPedido.setText("Pedido");

        jMenuEmitPedido.setText("Emitir Pedido");
        jMenuEmitPedido.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuEmitPedidoActionPerformed(evt);
            }
        });
        jMenuPedido.add(jMenuEmitPedido);

        jMenuBar1.add(jMenuPedido);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 279, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuClientesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuClientesActionPerformed
        new GuiCliente(cadCliVend).setVisible(true);
    }//GEN-LAST:event_jMenuClientesActionPerformed

    private void jMenuVendedoresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuVendedoresActionPerformed
        new GuiVendedor(cadCliVend).setVisible(true);
    }//GEN-LAST:event_jMenuVendedoresActionPerformed

    private void jMenuProdutosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuProdutosActionPerformed
        new GuiProduto(cadProd).setVisible(true);
    }//GEN-LAST:event_jMenuProdutosActionPerformed

    private void jMenuSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuSairActionPerformed
        dispose();
    }//GEN-LAST:event_jMenuSairActionPerformed

    private void jMenuEmitPedidoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuEmitPedidoActionPerformed
        new GuiEmitirPedido(emitirPed, pesqCliente, pesqVendedor, cadCliVend, cadProd).setVisible(true);
    }//GEN-LAST:event_jMenuEmitPedidoActionPerformed

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
            java.util.logging.Logger.getLogger(GuiMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GuiMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GuiMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GuiMenu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GuiMenu().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenu jMenuCadastros;
    private javax.swing.JMenuItem jMenuClientes;
    private javax.swing.JMenuItem jMenuEmitPedido;
    private javax.swing.JMenu jMenuPedido;
    private javax.swing.JMenuItem jMenuProdutos;
    private javax.swing.JMenuItem jMenuSair;
    private javax.swing.JMenuItem jMenuVendedores;
    // End of variables declaration//GEN-END:variables
    private ArrayList<Pessoa> cadCliVend = new ArrayList<Pessoa>();
    private ArrayList<Produto> cadProd = new ArrayList<Produto>();
    private ArrayList<Pedido> emitirPed = new ArrayList<Pedido>();
    private ArrayList<Cliente> pesqCliente = new ArrayList<Cliente>();
    private ArrayList<Vendedor> pesqVendedor = new ArrayList<Vendedor>();

}
