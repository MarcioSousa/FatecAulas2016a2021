
package fatec.poo.model;

/**
 *
 * @author Tamie
 */
public class ContaCorrente {
    private int numero;
    private double saldo;
    
    public ContaCorrente(int num, double sd){
        numero = num;
        saldo = sd;
    }
    public int getNumero(){
        return numero;
    }
    public double getSaldo(){
        return saldo;
    }
    public void sacar(double saque){
        saldo -= saque; 
    }
    public void depositar(double deposito){
        saldo += deposito;
    }
}
