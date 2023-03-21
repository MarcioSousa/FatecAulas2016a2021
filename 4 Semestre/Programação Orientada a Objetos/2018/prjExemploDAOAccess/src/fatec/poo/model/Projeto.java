package fatec.poo.model;

public class Projeto {

    private String Codigo;

    private String Descricao;
    private String DataInicio;
    private String DataTermino;   
   
    public Projeto(String Codigo, String Descricao, String DataInicio, String DataTermino) {
        this.Codigo = Codigo;
        this.Descricao = Descricao;    
        this.DataInicio = DataInicio;
        this.DataTermino = DataTermino;
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

    public String getCodigo() {
        return Codigo;
    }

    public String getDescricao() {
        return Descricao;
    }

    public String getDataTermino() {
        return (DataTermino);
    }

    public String getDataInicio() {
        return (DataInicio);
    }
    
}
