
package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Felipe
 */
public class Cliente extends Pessoa {
    private Double limiteCred;
    private Double limiteDisp;
    private ArrayList<Pedido> pedidos;    
    
    public Cliente (String cpf, String nome, Double limiteCred){
        super(cpf, nome);
        this.limiteCred = limiteCred;
        this.limiteDisp = limiteCred;
        pedidos = new ArrayList<>();
    }
    
    public void setLimiteCred(double limiteCred) {
        this.limiteCred = limiteCred;
    }
    
    public void setLimiteDisp(double limiteCred) {
        this.limiteCred = limiteCred;
    }

    public double getLimiteCred() {
        return limiteCred;
    }

    public double getLimiteDisp() {
        return limiteDisp;
    }
    
    public void addPedido(Pedido pedido) {
        pedidos.add(pedido);
        pedido.setCliente(this);
        
    }
}
