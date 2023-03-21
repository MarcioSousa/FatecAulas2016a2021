
package fatec.poo.model;

public class Projeto {
    private String identificacao;
    private String descricao;
    private String dtInicio;
    private String dtTermino;
    private Funcionario[] funcionarios;
    private int numFunc;

    public Projeto(String identificacao, String descricao) {
        this.identificacao = identificacao;
        this.descricao = descricao;
        funcionarios = new Funcionario[10];
    }

    public String getIdentificacao() {
        return identificacao;
    }

    public String getDescricao() {
        return descricao;
    }

    public String getDtInicio() {
        return dtInicio;
    }

    public String getDtTermino() {
        return dtTermino;
    }

    public void setDtInicio(String dtInicio) {
        this.dtInicio = dtInicio;
    }

    public void setDtTermino(String dtTermino) {
        this.dtTermino = dtTermino;
    }
    public void addFuncionario(Funcionario f){
        funcionarios[numFunc] = f;
	numFunc++;
    }
    public void listar(){
        System.out.println("\n\nIdentificação: " + identificacao);
        System.out.println("Descrição: " + descricao);
        System.out.println("Data de Inicio: " + dtInicio);
        System.out.println("Data de termino: " + dtTermino);
        System.out.println("\nRegistro  \tNome    \tCargo   \tDepartamento");
        
        for(int c =0; c < numFunc;c++){
            System.out.print(funcionarios[c].getRegistro());
            System.out.print("    \t" + funcionarios[c].getNome());
            System.out.print("\t" + funcionarios[c].getCargo());
            System.out.println("\t" + funcionarios[c].getDepartamento().getNome());
        }
    }
    
}


