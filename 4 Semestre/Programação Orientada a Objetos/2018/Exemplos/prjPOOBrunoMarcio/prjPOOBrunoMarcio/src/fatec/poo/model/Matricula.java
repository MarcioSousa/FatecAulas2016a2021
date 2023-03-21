
package fatec.poo.model;

public class Matricula {
    private String Data;
    private int QtdeFaltas;
    private double Nota;
    private Aluno aluno;
    private AVista avista;
    private APrazo aprazo;
    
    public Aluno getAluno() {
        return aluno;
    }

    public void setAluno(Aluno aluno) {
        this.aluno = aluno;
    }

    public AVista getAvista() {
        return avista;
    }

    public void setAvista(AVista avista) {
        this.avista = avista;
    }

    public APrazo getAprazo() {
        return aprazo;
    }

    public void setAprazo(APrazo aprazo) {
        this.aprazo = aprazo;
    }

    
    public Matricula(String Data) {
        this.Data = Data;
    }

    public void setQtdeFaltas(int QtdeFaltas) {
        this.QtdeFaltas = QtdeFaltas;
    }

    public void setNota(double Nota) {
        this.Nota = Nota;
    }
    
    public void EmitirCarne(){
    
    };
    
}
