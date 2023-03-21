 package fatec.poo.model;

/**
 *
 * @author professor
 */
public abstract class Funcionario {
    private int registro;
    private String nome;
    private String dtAdmissao;
    private String cargo;
    
    Funcionario(int r, String n, String dta){
        registro = r;
        nome = n;
        dtAdmissao = dta;        
    }
    
    //definição do método abstrato
    abstract public double calcSalBruto();
    
    public double calcDesconto(){
        return(0.10 * calcSalBruto());
    }
    
    public double calcSalLiquido(){
        return(calcSalBruto() - calcDesconto());
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public int getRegistro() {
        return registro;
    }

    public String getNome() {
        return nome;
    }

    public String getDtAdmissao() {
        return dtAdmissao;
    }

    public String getCargo() {
        return cargo;
    }
    
    
}
