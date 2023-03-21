package fatec.poo.model;

public class Aluno extends Pessoa{
    private String Escolaridade;
    private Matricula matricula;

    public Aluno(String CPF, String Nome, String DataNasc, String Endereco, String Numero, String Bairro, String Cidade, String Estado, String CEP, String Telefone, String Celular, String Sexo, String EstadoCivil, String RG, String Email, String Escolaridade) {
        super(CPF, Nome, DataNasc, Endereco, Numero, Bairro, Cidade, Estado, CEP, Telefone, Celular, Sexo, EstadoCivil, RG, Email);
        this.Escolaridade = Escolaridade;
    }

    public void setEscolaridade(String Escolaridade) {
        this.Escolaridade = Escolaridade;
    }

    public String getEscolaridade() {
        return Escolaridade;
    }
    
}
