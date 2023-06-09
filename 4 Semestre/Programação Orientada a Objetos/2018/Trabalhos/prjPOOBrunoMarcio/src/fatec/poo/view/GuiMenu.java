package fatec.poo.view;

public class GuiMenu extends javax.swing.JFrame {

    public GuiMenu() {
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenuCadastros = new javax.swing.JMenu();
        jMenuCurso = new javax.swing.JMenuItem();
        jMenuTurma = new javax.swing.JMenuItem();
        jMenuInstrutor = new javax.swing.JMenuItem();
        jMenuAluno = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JPopupMenu.Separator();
        jMenuSair = new javax.swing.JMenuItem();
        jMenuOperacoes = new javax.swing.JMenu();
        jMenuAlocarInstrutor = new javax.swing.JMenuItem();
        jMenuEfetuarMatricula = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Trabalho POO");

        jMenuCadastros.setText("Cadastros");

        jMenuCurso.setText("Curso");
        jMenuCurso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuCursoActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuCurso);

        jMenuTurma.setText("Turma");
        jMenuTurma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuTurmaActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuTurma);

        jMenuInstrutor.setText("Instrutor");
        jMenuInstrutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuInstrutorActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuInstrutor);

        jMenuAluno.setText("Aluno");
        jMenuAluno.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuAlunoActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuAluno);
        jMenuCadastros.add(jSeparator1);

        jMenuSair.setText("Sair");
        jMenuSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuSairActionPerformed(evt);
            }
        });
        jMenuCadastros.add(jMenuSair);

        jMenuBar1.add(jMenuCadastros);

        jMenuOperacoes.setText("Operações");

        jMenuAlocarInstrutor.setText("Alocar Instrutor");
        jMenuAlocarInstrutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuAlocarInstrutorActionPerformed(evt);
            }
        });
        jMenuOperacoes.add(jMenuAlocarInstrutor);

        jMenuEfetuarMatricula.setText("Efetuar Matrícula");
        jMenuEfetuarMatricula.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuEfetuarMatriculaActionPerformed(evt);
            }
        });
        jMenuOperacoes.add(jMenuEfetuarMatricula);

        jMenuBar1.add(jMenuOperacoes);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 815, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 421, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuCursoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuCursoActionPerformed
        new GuiCurso().setVisible(true);
    }//GEN-LAST:event_jMenuCursoActionPerformed

    private void jMenuTurmaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuTurmaActionPerformed
        new GuiTurma().setVisible(true);
    }//GEN-LAST:event_jMenuTurmaActionPerformed

    private void jMenuInstrutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuInstrutorActionPerformed
        new GuiInstrutor().setVisible(true);
    }//GEN-LAST:event_jMenuInstrutorActionPerformed

    private void jMenuAlunoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuAlunoActionPerformed
        new GuiAluno().setVisible(true);
    }//GEN-LAST:event_jMenuAlunoActionPerformed

    private void jMenuSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuSairActionPerformed
        dispose();
    }//GEN-LAST:event_jMenuSairActionPerformed

    private void jMenuAlocarInstrutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuAlocarInstrutorActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuAlocarInstrutorActionPerformed

    private void jMenuEfetuarMatriculaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuEfetuarMatriculaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuEfetuarMatriculaActionPerformed

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
    private javax.swing.JMenuItem jMenuAlocarInstrutor;
    private javax.swing.JMenuItem jMenuAluno;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenu jMenuCadastros;
    private javax.swing.JMenuItem jMenuCurso;
    private javax.swing.JMenuItem jMenuEfetuarMatricula;
    private javax.swing.JMenuItem jMenuInstrutor;
    private javax.swing.JMenu jMenuOperacoes;
    private javax.swing.JMenuItem jMenuSair;
    private javax.swing.JMenuItem jMenuTurma;
    private javax.swing.JPopupMenu.Separator jSeparator1;
    // End of variables declaration//GEN-END:variables
}
