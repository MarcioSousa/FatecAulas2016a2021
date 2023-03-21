package fatec.poo.model;

/**
 *
 * @author professor
 */
public class FuncionarioHorista extends Funcionario{
    private double valHorTrab;
    private int qtdeHorTrab;
    
    public FuncionarioHorista(int r, String n, String dta, double vht) {
        super(r, n, dta);//chamada do método construtor
        valHorTrab = vht;
    }

    public void apontarHoras(int qht){
        qtdeHorTrab = qht;
    }
    
    @Override
    public double calcSalBruto() {
        return(valHorTrab * qtdeHorTrab);
    }
    
    public double calcGratificacao(){
        return(0.075 * calcSalBruto());
    }
    
    //aplicando o polimorfismo 
    public double calcSalLiquido(){
        return(super.calcSalLiquido() + calcGratificacao());
    }    
    
}
