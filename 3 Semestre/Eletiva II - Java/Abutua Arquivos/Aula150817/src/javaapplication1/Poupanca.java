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
public class Poupanca {
    double saldo;
    String cliente;
    
    boolean sacar(double valor){
       if(saldo >= valor && valor > 0){
           saldo -= valor;
           return true;
       }
       else
           return false;
   }    
   
   boolean depositar(double valor)
   {
       if(valor > 0){
          saldo += valor;
          return true;
       }
       else{
          return false;
       }
   }
   
   void imprimirDados(){
       System.out.println("Cliente: " + cliente);
       System.out.println("Saldo:   " + saldo);
   }
   
   
   
   
   
   
   
           
           
           
           
    
    
    
    
    
}
