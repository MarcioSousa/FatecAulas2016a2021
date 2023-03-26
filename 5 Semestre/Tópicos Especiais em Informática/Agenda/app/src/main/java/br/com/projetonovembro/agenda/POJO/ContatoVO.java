package br.com.projetonovembro.agenda.POJO;

import java.io.Serializable;

/**
 * Created by joseg_000 on 09/04/2016.
 */
public class ContatoVO implements Serializable{
    private static final long serialVersionUID = 1L;
    private long id;
    private String nome;
    private String endereco;
    private String telefone;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String value) {
        this.nome = value;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String value) {
        this.endereco = value;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String value) {
        this.telefone = value;
    }
    // Will be used by the ArrayAdapter in the ListView
    @Override
    public String toString() {
        return nome;
    }

}
