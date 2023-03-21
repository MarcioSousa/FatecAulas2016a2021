package fatec.poo.model;

public class Turma {
    private String SiglaTurma;
    private String SiglaCursoTurma;
    private String Descricao;
    private String DataInicio;
    private String DataTermino;
    private String Periodo;
    private int QtdVagas;
    
    private String Observacoes;

    private Curso curso;
    private Matricula[] matriculas;
    private int numMatricula;
    
    public Turma(String SiglaCursoTurma){
        this.SiglaCursoTurma = SiglaCursoTurma;
    }

    public Turma(String SiglaCursoTurma, String SiglaTurma, String Descricao, String DataInicio, String DataTermino, String Periodo, int QtdVagas) {
        this.SiglaTurma = SiglaTurma;
        this.Descricao = Descricao;
        this.DataInicio = DataInicio;
        this.DataTermino = DataTermino;
        this.Periodo = Periodo;
        this.QtdVagas = QtdVagas;
        this.Observacoes = Observacoes;
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
    
    public String getPeriodo() {
        return Periodo;
    }
    
    public void setQtdVagas(int QtdVagas) {
        this.QtdVagas = QtdVagas;
    }

    public void setObservacoes(String Observacoes) {
        this.Observacoes = Observacoes;
    }

    public String getSiglaTurma() {
        return SiglaTurma;
    }

    public String getDataInicio() {
        return DataInicio;
    }

    public String getDataTermino() {
        return DataTermino;
    }
 
    public int getQtdVagas() {
        return QtdVagas;
    }
    public Curso getCurso() {
        return curso;
    }

    public String getDescricao() {
        return Descricao;
    }

    public void setCurso(Curso curso) {
        this.curso = curso;
    }
    
    public String getSiglaCursoTurma() {
        return SiglaCursoTurma;
    }

    public void setSiglaCursoTurma(String SiglaCursoTurma) {
        this.SiglaCursoTurma = SiglaCursoTurma;
    }
}
