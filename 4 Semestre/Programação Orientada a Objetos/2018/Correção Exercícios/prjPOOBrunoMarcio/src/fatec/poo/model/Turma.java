package fatec.poo.model;

public class Turma {
    private String SiglaTurma;
    private String Descricao;
    private String DataInicio;
    private String DataTermino;
    private String Periodo;
    private int QtdVagas;
    private String Observacoes;

    private Matricula[] matriculas;
    private int numMatricula;
    
    public Turma(String SiglaTurma, String Descricao) {
        this.SiglaTurma = SiglaTurma;
        this.Descricao = Descricao;
        matriculas = new Matricula[10];
    }
    
    public void addMatricula(Matricula a){
        matriculas[numMatricula]=a;
        numMatricula++;
    }
    public void setDescricao(String Descricao) {
        this.Descricao = Descricao;
    }

    public void setDataInicio(String DataInicio) {
        this.DataInicio = DataInicio;
    }

    public void setDataTermino(String DataTermino) {
        this.DataTermino = DataTermino;
    }

    public void setPeriodo(String Periodo) {
        this.Periodo = Periodo;
    }

    public void setQtdVagas(int QtdVagas) {
        this.QtdVagas = QtdVagas;
    }

    public void setObservacoes(String Observacoes) {
        this.Observacoes = Observacoes;
    }
    
    
}
