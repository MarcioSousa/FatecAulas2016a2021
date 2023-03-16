package teste;

import javaapplication1.Poupanca;

public class ClasseOutroPacote {
	public static void main(String[] args) {
	     
        Poupanca p = new Poupanca("sad");
        
        //p.cliente = "Joao";
        p.setCliente("Joao");
        
        System.out.println(p.depositar(100));
        System.out.println(p.depositar(80));
        System.out.println(p.sacar(40));
        System.out.println(p.sacar(344));
        //p.saldo = -1000;
        
        p.imprimirDados();
	}
        
    
}
