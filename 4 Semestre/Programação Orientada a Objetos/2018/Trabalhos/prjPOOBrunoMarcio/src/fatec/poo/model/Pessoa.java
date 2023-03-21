package fatec.poo.model;

public class Pessoa {
    private String CPF;
    private String Nome;
    private String DataNasc;
    private String Endereco;
    private String Numero;
    private String Bairro;
    private String Cidade;
    private String Estado;
    private String CEP;
    private String Telefone;
    private String Celular;
    private String Sexo;
    private String EstadoCivil;
    private String RG;
    private String Email;
    private static final int[] pesoCPF = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

    public Pessoa(String CPF, String Nome, String DataNasc, String Endereco, String Numero, String Bairro, String Cidade, String Estado, String CEP, String Telefone, String Celular, String Sexo, String EstadoCivil, String RG, String Email) {
        this.CPF = CPF;
        this.Nome = Nome;
        this.DataNasc = DataNasc;
        this.Endereco = Endereco;
        this.Numero = Numero;
        this.Bairro = Bairro;
        this.Cidade = Cidade;
        this.Estado = Estado;
        this.CEP = CEP;
        this.Telefone = Telefone;
        this.Celular = Celular;
        this.Sexo = Sexo;
        this.EstadoCivil = EstadoCivil;
        this.RG = RG;
        this.Email = Email;
    }

    public Pessoa(String CPF, String Nome, String Endereco) {
        this.CPF = CPF;
        this.Nome = Nome;
        this.Endereco = Endereco;
    }
    
    public String getNome() {
        return Nome;
    }
        
    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public void setDataNasc(String DataNasc) {
        this.DataNasc = DataNasc;
    }

    public void setEndereco(String Endereco) {
        this.Endereco = Endereco;
    }

    public void setNumero(String Numero) {
        this.Numero = Numero;
    }

    public void setBairro(String Bairro) {
        this.Bairro = Bairro;
    }

    public void setCidade(String Cidade) {
        this.Cidade = Cidade;
    }

    public void setEstado(String Estado) {
        this.Estado = Estado;
    }

    public void setCEP(String CEP) {
        this.CEP = CEP;
    }

    public void setTelefone(String Telefone) {
        this.Telefone = Telefone;
    }

    public void setCelular(String Celular) {
        this.Celular = Celular;
    }

    public void setSexo(String Sexo) {
        this.Sexo = Sexo;
    }

    public void setEstadoCivil(String EstadoCivil) {
        this.EstadoCivil = EstadoCivil;
    }

    public void setRG(String RG) {
        this.RG = RG;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setEmail(String Email) {
        this.Email = Email;
    }

    public String getCPF() {
        return CPF;
    }

    public String getDataNasc() {
        return DataNasc;
    }

    public String getEndereco() {
        return Endereco;
    }

    public String getNumero() {
        return Numero;
    }

    public String getBairro() {
        return Bairro;
    }

    public String getCidade() {
        return Cidade;
    }

    public String getEstado() {
        return Estado;
    }

    public String getCEP() {
        return CEP;
    }

    public String getTelefone() {
        return Telefone;
    }

    public String getCelular() {
        return Celular;
    }

    public String getSexo() {
        return Sexo;
    }

    public String getEstadoCivil() {
        return EstadoCivil;
    }

    public String getRG() {
        return RG;
    }

    public String getEmail() {
        return Email;
    }

    private static int calcularDigito(String str, int[] peso) {
      int soma = 0;
      for (int indice=str.length()-1, digito; indice >= 0; indice-- ) {
         digito = Integer.parseInt(str.substring(indice,indice+1));
         soma += digito*peso[peso.length-str.length()+indice];
      }
      soma = 11 - soma % 11;
      return soma > 9 ? 0 : soma;
   }
    public static boolean ValidarCPF(String cpf) {
      if ((cpf==null) || (cpf.length()!=11)) return false;

      Integer digito1 = calcularDigito(cpf.substring(0,9), pesoCPF);
      Integer digito2 = calcularDigito(cpf.substring(0,9) + digito1, pesoCPF);
      return cpf.equals(cpf.substring(0,9) + digito1.toString() + digito2.toString());
   }
}
