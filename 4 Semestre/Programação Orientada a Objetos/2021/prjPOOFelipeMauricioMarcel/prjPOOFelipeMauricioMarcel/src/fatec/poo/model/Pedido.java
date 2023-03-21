
package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author Felipe
 */
public class Pedido {
    private String numero;
    private String dataEmissao;
    private String dataPagto;
    private boolean formaPagto;
    private boolean situacao;
    private Cliente cliente;
    private Vendedor vendedor;
    private ArrayList<ItemPedido> itemPedidos;

    public Pedido(String numero, String dataEmissao) {
        this.numero = numero;
        this.dataEmissao = dataEmissao;
    }

    public void setDataPagto(String dataPagto) {
        this.dataPagto = dataPagto;
    }

    public void setFormaPagto(boolean formaPagto) {
        this.formaPagto = formaPagto;
    }

    public void setSituacao(boolean situacao) {
        this.situacao = situacao;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }
    
    public void setVendedor(Vendedor vendedor) {
        this.vendedor = vendedor;
    }
    
    public String getNumero() {
        return numero;
    }

    public String getDataEmissao() {
        return dataEmissao;
    }

    public String getDataPagto() {
        return dataPagto;
    }

    public boolean isFormaPagto() {
        return formaPagto;
    }

    public boolean isSituacao() {
        return situacao;
    }

    public void addItemPedido(ItemPedido itemPedido){
        itemPedidos.add(itemPedido);
        itemPedido.setPedido(this);       
        
        cliente.setLimiteCred(cliente.getLimiteCred() - (itemPedido.getQtdeVendida() * itemPedido.getProduto().getPreco()));
    }
}
