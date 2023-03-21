package fatec.poo.model;

public class Aluno extends Pessoa{
    private String Escolaridade;
    private Matricula matricula;
    
    public Aluno(String CPF, String Nome) {
        super(CPF, Nome);
    }

    public void setEscolaridade(String Escolaridade) {
        this.Escolaridade = Escolaridade;
    }
}
