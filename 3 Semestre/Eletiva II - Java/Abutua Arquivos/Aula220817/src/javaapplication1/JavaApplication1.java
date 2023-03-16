/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author Convidado
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
     
        Poupanca p = new Poupanca("Joao");
        
        		
        //p.cliente = "Joao";
        p.setCliente("Joao Silva");
        
        //System.out.println(p.cliente);
        System.out.println(p.getCliente());
        
        
        System.out.println(p.depositar(100));
        System.out.println(p.depositar(80));
        System.out.println(p.sacar(40));
        System.out.println(p.sacar(344));
        //p.saldo = -1000;
       // p.setSaldo(-1000);
        
        p.imprimirDados();
        
    }
    
}
