package fatec.poo.model;


public class Instrutor extends Pessoa{
    private String Formacao;
    private String AreaAtuacao;
    private Turma[] turmas;
    private int numTurma;
    
    /*private Aluno[] alunos;         
    private int numAlu;
    
    public Turma(String sigla, int qtdeVagas){
        this.sigla = sigla;
        this.qtdeVagas = qtdeVagas;
        alunos = new Aluno[qtdeVagas];
    }*/
    public Instrutor(String CPF, String Nome, String DataNascimento, String Sexo, String EstadoCivil, String Endereco, String Numero, String Bairro, String Cep, String Cidade, String Estado, String TelRes, String Rg, String Celular, String Formacao, String AreaAtuacao, String Email) {
        super(CPF, Nome, DataNascimento, Endereco, Numero, Bairro, Cidade, Estado, Cep, TelRes, Celular, Sexo, EstadoCivil, Rg, Email);
        this.Formacao = Formacao;
        this.AreaAtuacao = AreaAtuacao;
        turmas = new Turma[10];
    }
    
    public void setFormacao(String Formacao) {
        this.Formacao = Formacao;
    }

    public void setAreaAtuacao(String AreaAtuacao) {
        this.AreaAtuacao = AreaAtuacao;
    }
    
    public void addTurma(Turma a){
        turmas[numTurma]=a;
        numTurma++;
    }
    
    /*public void listarTurma(){
        System.out.println("\nSigla do Curso: " + curso.getSigla() + "\t\tNome do Curso: " + getCurso().getDescricao());
        System.out.println("\nSigla da Turma: " + sigla);
        System.out.println("\nNome do Professsor: " + professor.getNome());
        System.out.println("\n\tNome do Aluno\n");
        for(int cont = 0; cont < numTurma; cont++){            
            System.out.println(cont + 1 + " - " + turmas[cont].());
        }
    }*/

    public String getFormacao() {
        return Formacao;
    }

    public String getAreaAtuacao() {
        return AreaAtuacao;
    }
    
}
