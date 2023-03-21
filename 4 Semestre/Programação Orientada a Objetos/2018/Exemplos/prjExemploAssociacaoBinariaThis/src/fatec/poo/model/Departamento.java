package fatec.poo.model;

import java.util.ArrayList;

/**
 *
 * @author dimas
 */
public class Departamento {
    private String sigla;
    private String nome;
    private ArrayList<Funcionario> funcionarios;     

    public Departamento(String sigla, String nome) {
        this.sigla = sigla;
        this.nome = nome;
        funcionarios = new ArrayList<Funcionario>();        
    }

    public String getSigla() {
        return sigla;
    }

    public String getNome() {
        return nome;
    }
    
    public void addFuncionario(Funcionario f){
       funcionarios.add(f);
       f.setDepartamento(this);
    }
    
    public void listar(){
        System.out.println("\n\nSigla: " + sigla);               
        System.out.println("Nome: " + nome);
        System.out.println("\nRegistro\t\tNome\t\tCargo\t\tDt.Admissao");
        for(int x=0; x < funcionarios.size(); x++){
            System.out.println(funcionarios.get(x).getRegistro() + "\t\t" + 
                               funcionarios.get(x).getNome() + "\t\t" +
                               funcionarios.get(x).getCargo() + "\t\t" +
                               funcionarios.get(x).getDtAdmissao());
        }
    }
   
}
