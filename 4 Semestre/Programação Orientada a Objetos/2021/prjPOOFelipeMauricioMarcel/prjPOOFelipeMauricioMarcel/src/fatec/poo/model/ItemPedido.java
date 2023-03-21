
package fatec.poo.model;

/**
 *
 * @author Felipe
 */
public class ItemPedido {
    private int sequencia;
    private double qtdeVendida;
    private Produto produto;
    private Pedido pedido;

    public ItemPedido(double qtdeVendida, Produto produto) {
        
        this.qtdeVendida = qtdeVendida;
        this.produto = produto;
        produto.setQtdeEstoque(produto.getQtdeEstoque() - qtdeVendida);
    }

    public void setQtdeVendida(double qtdeVendida) {
        this.qtdeVendida = qtdeVendida;
    }
    
    public int getSequencia() {
        return sequencia;
    }
    
    public double getQtdeVendida() {
        return qtdeVendida;
    }  
    
    public Produto getProduto() {
        return produto;
    }   
    
    public void setPedido(Pedido pedido) {
        this.pedido = pedido;
    }
}
