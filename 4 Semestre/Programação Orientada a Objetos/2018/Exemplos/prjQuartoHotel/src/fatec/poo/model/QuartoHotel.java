package fatec.poo.model;

/**
 *
 * @author Aluno - Marcio Sousa
 */
public class QuartoHotel {
    private final int NumQuarto;
    private final double ValorDiaria;
    private int NumRG;
    private boolean Situacao;
    private double TotalFaturado;
    
    public QuartoHotel(int numQuarto, double valorDiaria){
        NumQuarto = numQuarto;
        ValorDiaria = valorDiaria;
        Situacao = false; //livre
        TotalFaturado = 0;
    }
    
    public void reservar(int numeroRG){
        NumRG = numeroRG;
        Situacao = true; //ocupado
    }
    
    public double liberar(int numeroDias){
        TotalFaturado = TotalFaturado + (numeroDias * ValorDiaria);
        NumRG = 0;
        Situacao = false; //livre
        return numeroDias * ValorDiaria;
    }
    
    public boolean getSituacao(){
        return Situacao;
    }
    
    public double getTotalFaturado(){
        return TotalFaturado;
    }
}
