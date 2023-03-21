package fatec.poo.control;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import fatec.poo.model.Aluno;

public class DaoAluno {
    private Connection conn;
    
    public DaoAluno(Connection conn){
        this.conn = conn;
    }
    
    public void inserir(Aluno aluno){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("INSERT INTO tbaluno(cpf_alu, nome_alu, datanascimento_alu, sexo_alu, estadocivil_alu, escolaridade_alu, endereco_alu, numero_alu, bairro_alu, cep_alu, cidade_alu, estado_alu, telres_alu, rg_alu, celular_alu, email_alu)VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
            
            ps.setString(1, aluno.getCPF());
            ps.setString(2, aluno.getNome());
            ps.setString(3, aluno.getDataNasc());
            ps.setString(4, aluno.getSexo());
            ps.setString(5, aluno.getEstado());
            ps.setString(6, aluno.getEscolaridade());
            ps.setString(7, aluno.getEndereco());
            ps.setString(8, aluno.getNumero());
            ps.setString(9, aluno.getBairro());
            ps.setString(10, aluno.getCEP());
            ps.setString(11, aluno.getCidade());
            ps.setString(12, aluno.getEstado());
            ps.setString(13, aluno.getTelefone());
            ps.setString(14, aluno.getRG());
            ps.setString(15, aluno.getCelular());
            ps.setString(16, aluno.getEmail());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public void alterar(Aluno aluno){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("UPDATE tbaluno set nome_alu = ?, datanascimento_alu = ?, sexo_alu= ?, estadocivil_alu = ?, escolaridade_alu = ?, endereco_alu = ?, numero_alu = ?, bairro_alu = ?, cep_alu = ?, cidade_alu = ?, estado_alu = ?, telres_alu = ?, rg_alu = ?, celular_alu = ?, email_alu = ? WHERE cpf_alu = ?");
            //nome_alu = ?, 
            ps.setString(1, aluno.getNome());
            //datanascimento_alu = ?, 
            ps.setString(2, aluno.getDataNasc());
            //sexo_alu= ?, 
            ps.setString(3, aluno.getSexo());
            //estadocivil_alu = ?,
            ps.setString(4, aluno.getEstadoCivil());
            // escolaridade_alu = ?, 
            ps.setString(5, aluno.getEscolaridade());
            //endereco_alu = ?, 
            ps.setString(6, aluno.getEndereco());
            //numero_alu = ?, 
            ps.setString(7, aluno.getNumero());
            //bairro_alu = ?, 
            ps.setString(8, aluno.getBairro());
            //cep_alu = ?, 
            ps.setString(9, aluno.getCEP());
            //cidade_alu = ?, 
            ps.setString(10, aluno.getCidade());
            //estado_alu = ?, 
            ps.setString(11, aluno.getEstado());
            //telres_alu = ?, 
            ps.setString(12, aluno.getTelefone());
            //rg_alu = ?,
            ps.setString(13, aluno.getRG());
            // celular_alu = ?, 
            ps.setString(14, aluno.getCelular());
            //email_alu
            ps.setString(15, aluno.getEmail());
            ps.setString(16, aluno.getCPF());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());  
        }
    }
    
    public Aluno consultar (String CPF){
        Aluno i = null;
        PreparedStatement ps = null;
        
        try {
            
            ps = conn.prepareStatement("SELECT * from tbaluno where cpf_alu = ?");
            
            ps.setString(1, CPF);
            ResultSet rs = ps.executeQuery();
                       
            if (rs.next() == true) {
                i = new Aluno(CPF, rs.getString("nome_alu"), rs.getString("datanascimento_alu"), rs.getString("endereco_alu"), rs.getString("numero_alu"), rs.getString("bairro_alu"), rs.getString("cidade_alu"), rs.getString("estado_alu"), rs.getString("cep_alu"), rs.getString("telres_alu"), rs.getString("celular_alu"), rs.getString("sexo_alu"), rs.getString("estadocivil_alu"), rs.getString("rg_alu"), rs.getString("email_alu"), rs.getString("escolaridade_alu"));
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
        return (i);
    }
    
    public void excluir(Aluno aluno){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("DELETE FROM tbaluno WHERE cpf_alu = ?");
            
            ps.setString(1, aluno.getCPF());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
}
