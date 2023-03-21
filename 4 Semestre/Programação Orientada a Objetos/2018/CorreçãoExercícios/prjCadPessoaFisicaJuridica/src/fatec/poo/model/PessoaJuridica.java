package fatec.poo.model;

/**
 *
 * @author 0030481521013
 */
public class PessoaJuridica extends Pessoa{
    private String cgc;
    private double taxaIncentivo;

    public PessoaJuridica(String cgc, String nome,int anoIscricao){
        super(nome,anoIscricao);
        this.cgc = cgc;
    }
    public double calcBonus(int ano){
        
     return (taxaIncentivo/100 * getTotalCompras())*(ano-getAnoInscricao()) ;
        
    }
    public String getCGC() {
        return cgc;
    }
    
    public double getTaxaIncentivo() {
        return taxaIncentivo ;
    }

    public void setTaxaIncentivo(double TaxaIncentivo) {
        this.taxaIncentivo = TaxaIncentivo;
    }
    
    
}
