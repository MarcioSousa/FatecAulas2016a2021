package fatec.poo.model;

public class Curso {

    private String Sigla;
    private String Nome;
    private int CargaHoraria;
    private double Valor;
    private String DataVigencia;
    private double ValorHoraInstrutor;
    private String Programa;

    private Turma[] turmas;
    private int numTurma;
    
    public void setSigla(String Sigla) {
        this.Sigla = Sigla;
        turmas = new Turma[10];
    }

    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public void setCargaHoraria(int CargaHoraria) {
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

    public Curso(String Sigla, String Nome) {
        this.Sigla = Sigla;
        this.Nome = Nome;
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

    public int getCargaHoraria() {
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
