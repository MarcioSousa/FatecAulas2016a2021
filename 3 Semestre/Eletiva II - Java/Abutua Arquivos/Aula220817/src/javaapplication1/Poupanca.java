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
	private double saldo;
	private String cliente;
	
	public Poupanca(String cliente){
		this.cliente = cliente;
		System.out.println("Construtor");
	}
	
	
	
	public double getSaldo() {
		return saldo;
	}

	

	public String getCliente() {
		return cliente;
	}

	public void setCliente(String cliente) {
		this.cliente = cliente;
	}

	public boolean sacar(double valor){
       if(saldo >= valor && valor > 0){
           saldo -= valor;
           return true;
       }
       else
           return false;
   }    
   
	public boolean depositar(double valor)
   {
       if(valor > 0){
          saldo += valor;
          return true;
       }
       else{
          return false;
       }
   }
   
	public void imprimirDados(){
       System.out.println("Cliente: " + cliente);
       System.out.println("Saldo:   " + saldo);
   }



	@Override
	public String toString() {
		return "Poupanca [saldo=" + saldo + ", cliente=" + cliente + "]";
	}
   
   
   
	
   
   
   
           
           
           
           
    
    
    
    
    
}
