package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class Aluno extends Pessoa{
    private int regEscolar;
    private double mensalidade;

    public Aluno(int regEscolar, String nome, String dataNascimento) {
        super(nome, dataNascimento);//chamada ao método construtor da superclasse Pessoa
        this.regEscolar = regEscolar;
    }

    public int getRegEscolar() {
        return regEscolar;
    }

    public double getMensalidade() {
        return mensalidade;
    }

    public void setMensalidade(double mensalidade) {
        this.mensalidade = mensalidade;
    }
}
