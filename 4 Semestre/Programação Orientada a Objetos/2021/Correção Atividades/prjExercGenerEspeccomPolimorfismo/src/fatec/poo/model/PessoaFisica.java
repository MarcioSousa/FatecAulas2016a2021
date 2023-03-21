package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class PessoaFisica extends Pessoa{
    private String cpf;
    private double base;

    public PessoaFisica(String cpf, String nome, int anoInscricao) {
        super(nome, anoInscricao);//chamada do método construtor da superclasse Pessoa
        this.cpf = cpf;
    }

    @Override
    public double calcBonus(int anoAtual) {
        double bonus=0;
        if (getTotalCompras() > 12000){
            bonus = (anoAtual - getAnoInscricao()) * base;
        }
        
        return(bonus);
    }

    public String getCpf() {
        return cpf;
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }
}
