
package fatec.poo.model;

import java.util.ArrayList;

public class Projeto {
    private String identificacao;
    private String descricao;
    private String dtInicio;
    private String dtTermino;
    private ArrayList<Funcionario> funcionarios;

    public Projeto(String identificacao, String descricao) {
        this.identificacao = identificacao;
        this.descricao = descricao;
        funcionarios = new ArrayList<Funcionario>();
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
        funcionarios.add(f);
        f.setProjeto(this);
    }
    public void listar(){
        System.out.println("\n\nIdentificação: " + identificacao);
        System.out.println("Descrição: " + descricao);
        System.out.println("Data de Inicio: " + dtInicio);
        System.out.println("Data de termino: " + dtTermino);
        System.out.println("\nRegistro  Nome    Cargo   Dt.Admissão     Tipo    Departamento");
        
        for(int c =0; c < funcionarios.size();c++){
            System.out.print(funcionarios.get(c).getRegistro());
            System.out.print("\t" + funcionarios.get(c).getNome());
            System.out.print("\t" + funcionarios.get(c).getCargo());
            System.out.print("\t" + funcionarios.get(c).getDtAdmissao());
            System.out.println("\t\t" + funcionarios.get(c).getDepartamento().getNome());
        }
    }
    
}
