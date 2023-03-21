package fatec.poo.model;

import java.util.ArrayList;

public class Curso {

    private String Sigla;
    private String Nome;
    private String CargaHoraria;
    private double Valor;
    private String DataVigencia;
    private double ValorHoraInstrutor;
    private String Programa;

    private Turma[] turmas;
    private int numTurma;
    
    public Curso(String sigla, String nome){
        this.Sigla = sigla;
        this.Nome = nome;
        //turmas = new ArrayList<Turma>();
    }
    public Curso(String SiglaCurso, String Nome, String CargaHoraria, String DataVigencia, Double Valor, Double ValorHoraInstrutor, String Programa) {
        this.Sigla = SiglaCurso;
        this.Nome = Nome;
        this.CargaHoraria = CargaHoraria;
        this.DataVigencia = DataVigencia;
        this.Valor = Valor;
        this.ValorHoraInstrutor = ValorHoraInstrutor;
        this.Programa = Programa;
    }
    
    public void setSigla(String Sigla) {
        this.Sigla = Sigla;
        turmas = new Turma[10];
    }

    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public void setCargaHoraria(String CargaHoraria) {
        this.CargaHoraria = CargaHoraria;
    }

    public void setValor(double Valor) {
        this.Valor = Valor;
    }

    public void setDataVigencia(String DataVigencia) {
        this.DataVigencia = DataVigencia;
    }

    public void setValorHoraInstrutor(double ValorHoraInstrutor) {
        this.ValorHoraInstrutor = ValorHoraInstrutor;
    }

    public void setPrograma(String Programa) {
        this.Programa = Programa;
    }

    public void addTurma(Turma a){
        turmas[numTurma]=a;
        numTurma++;
    }

    public String getSigla() {
        return Sigla;
    }

    public String getNome() {
        return Nome;
    }

    public String getCargaHoraria() {
        return CargaHoraria;
    }

    public double getValor() {
        return Valor;
    }

    public String getDataVigencia() {
        return DataVigencia;
    }

    public double getValorHoraInstrutor() {
        return ValorHoraInstrutor;
    }

    public String getPrograma() {
        return Programa;
    }
    
}
