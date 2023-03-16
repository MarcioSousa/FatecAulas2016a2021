/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula01082017;

import javax.swing.JOptionPane;


/**
 *
 * @author Aluno - Gti-Ads
 */
public class Aula01082017 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int valor, dobro;
        float num1;
        double num2;
        char   letra;
        String aux;
        
        aux    = JOptionPane.showInputDialog("Digite um valor");
        valor  = Integer.parseInt(aux);
        
        dobro = valor * 2;
        
        System.out.println("O dobro de " + valor + " e " + dobro);
        
                
        
        
        
        
        // TODO code application logic here
    }
    
}
