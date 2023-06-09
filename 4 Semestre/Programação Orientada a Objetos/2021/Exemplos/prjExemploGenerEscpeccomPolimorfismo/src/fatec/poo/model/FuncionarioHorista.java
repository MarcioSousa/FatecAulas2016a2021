package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class FuncionarioHorista extends Funcionario {  
    private double valHorTrab;
    private int qtdeHorTrab;

    public FuncionarioHorista(int registro, String nome, String dtAdmissao, double valHorTrab) {
        super(registro, nome, dtAdmissao); //chamada ao método construtor da superclasse Funcionario
        this.valHorTrab = valHorTrab;
    }

    public void setQtdeHorTrab(int qtdeHorTrab) {
        this.qtdeHorTrab = qtdeHorTrab;
    }
    
    @Override
    //Aplicado o polimortfismo
    public double calcSalBruto() {
        return(valHorTrab * qtdeHorTrab);
    }
    
    public double calcGratificacao(){
        return(0.075 * calcSalBruto());
    }
    
    //Aplicando o polimorfismo
    public double calcSalLiquido(){
        return(super.calcSalLiquido() + calcGratificacao());
    }
}
