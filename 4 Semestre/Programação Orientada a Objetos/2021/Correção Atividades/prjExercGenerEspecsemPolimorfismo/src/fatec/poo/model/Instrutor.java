package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class Instrutor extends Pessoa{
    private int identificacao;
    private String areaAtuacao;

    public Instrutor(int identificacao, String nome, String telefone) {
        super(nome, telefone);//chamada do método construtor da superclasse Pessoa
        this.identificacao = identificacao;
    }

    public void setAreaAtuacao(String areaAtuacao) {
        this.areaAtuacao = areaAtuacao;
    }

    public int getIdentificacao() {
        return identificacao;
    }

    public String getAreaAtuacao() {
        return areaAtuacao;
    }  
}
