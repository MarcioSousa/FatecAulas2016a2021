
package fatec.poo.model;

/**
 *
 * @author Professor
 */
public class Pessoa {
    private String nome;
    private String dtNascimento;
    private String endereco;
    private String Cidade;
      
    public Pessoa(String nome){
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public String getDtNascimento() {
        return dtNascimento;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getCidade() {
        return Cidade;
    }
}