package fatec.poo.model;

/**
 *
 * @author dimas
 */
public class Departamento {
    private String sigla;
    private String nome;
    private Funcionario[] funcionarios;
    private int numFunc;        

    public Departamento(String sigla, String nome) {
        this.sigla = sigla;
        this.nome = nome;
        funcionarios = new Funcionario[10];        
    }

    public String getSigla() {
        return sigla;
    }

    public String getNome() {
        return nome;
    }
    
    public void addFuncionario(Funcionario f){
        funcionarios[numFunc]=f;
        numFunc++;
    }
    
    public void listar(){
        System.out.println("\n\nSigla: " + sigla);               
        System.out.println("Nome: " + nome);
        System.out.println("\nRegistro\t\tNome\t\tCargo\t\tDt.Admissao");
        for(int x=0; x < numFunc; x++){
            System.out.println(funcionarios[x].getRegistro() + "\t\t" + 
                               funcionarios[x].getNome() + "\t\t" +
                               funcionarios[x].getCargo() + "\t\t" +
                               funcionarios[x].getDtAdmissao());
        }
    }
   
}
