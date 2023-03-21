
package fatec.poo.model;

/**
 *
 * @author Dimas
 */
 
public class PessoaJuridica extends Pessoa{
    private String cgc;
    private double taxaIncentivo;

    public PessoaJuridica(String cgc, String nome,int anoInscricao){
        super(nome,anoInscricao);//chamada ao método construtor da superclasse Pessoa
        this.cgc = cgc;
    }
    
    @Override
    public double calcBonus(int anoAtual){        
      return (taxaIncentivo/100 * getTotalCompras())*(anoAtual-getAnoInscricao());        
    }
    
    public String getCGC() {
        return cgc;
    }

    public double getTaxaIncentivo() {
        return taxaIncentivo;
    }

    public void setTaxaIncentivo(double taxaIncentivo) {
        this.taxaIncentivo = taxaIncentivo;
    }
}
