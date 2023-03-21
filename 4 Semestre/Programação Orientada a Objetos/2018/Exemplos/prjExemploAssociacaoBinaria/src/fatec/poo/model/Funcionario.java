package fatec.poo.model;

/**
 *
 * @author dimas
 */
public abstract class Funcionario {
    private int registro;
    private String nome;
    private String dtAdmissao;
    private String cargo;
    private Departamento departamento;
    private Projeto projeto;
   
   

    public Funcionario(int registro, String nome, String dtAdmissao) {
        this.registro = registro;
        this.nome = nome;
        this.dtAdmissao = dtAdmissao;
    }

    

    
    
    //definição de um método abstrato
    abstract public double calcSalBruto();
    
    public double calcDesconto(){
        double desconto;
        desconto = 0.10 * calcSalBruto();
        return(desconto);
    }
    
    public double calcSalLiquido(){
        double salLiquido;
        salLiquido = calcSalBruto() - calcDesconto();
        return(salLiquido); 
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

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    //retorna o endereço de um objeto
    //da classe Departamento
    public Departamento getDepartamento() {
        return departamento;    }
    

    //tem como parâmetro de entrada o
    //endereço de um objeto da classe Departamento
    public void setDepartamento(Departamento departamento) {
        this.departamento = departamento;
    }

    //retorna o endereço de um objeto
    //da classe Projeto
    public Projeto getProjeto() {
        return projeto;
    }

    //tem como parâmetro de entrada o
    //endereço de um objeto da classe Projeto
    public void setProjeto(Projeto projeto) {
        this.projeto = projeto;
    }

   
    
    
    
   
    
    
    
    
}
