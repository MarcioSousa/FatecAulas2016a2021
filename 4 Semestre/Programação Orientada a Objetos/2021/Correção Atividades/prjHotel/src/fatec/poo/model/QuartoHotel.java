package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class QuartoHotel {
    private int numQuarto;
    private double valorDiaria;
    private int numRG;
    private boolean situacao;//false-livre   true-ocupado
    private double totalFaturado;
    
    public QuartoHotel(int numQuarto, double valorDiaria) {
        this.numQuarto = numQuarto;
        this.valorDiaria = valorDiaria;
        situacao = false; //livre
        totalFaturado = 0;
    }
        
    public void reservar(int rg){
        numRG = rg;
        situacao = true; //ocupado
    }
    
    public double liberar(int dias){
        double valHosped;
        numRG = 0;
        situacao = false; //livre 
        
        valHosped = valorDiaria * dias;
        totalFaturado += valHosped;
        
        return valHosped;
    }   
    
    public boolean getSituacao(){
        return situacao;    
    }
           
    public double getTotalFaturado(){
        return totalFaturado;
    }

    public int getNumQuarto() {
        return(numQuarto);
    }
}
