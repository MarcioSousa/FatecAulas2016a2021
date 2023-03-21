package fatec.poo.control;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import fatec.poo.model.Instrutor;

public class DaoInstrutor {
    private Connection conn;
    
    public DaoInstrutor(Connection conn){
        this.conn = conn;
    }
    
    public void inserir(Instrutor instrutor){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("INSERT INTO tbinstrutor(cpf_ins, nome_ins, datanascimento_ins, sexo_ins, estadocivil_ins, endereco_ins, numero_ins, bairro_ins, cep_ins, cidade_ins, estado_ins, telres_ins, rg_ins, celular_ins, formacao_ins, areadeatuacao_ins, email_ins)VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
            
            ps.setString(1, instrutor.getCPF());
            ps.setString(2, instrutor.getNome());
            ps.setString(3, instrutor.getDataNasc());
            ps.setString(4, instrutor.getSexo());
            ps.setString(5, instrutor.getEstadoCivil());
            ps.setString(6, instrutor.getEndereco());
            ps.setString(7, instrutor.getNumero());
            ps.setString(8, instrutor.getBairro());
            ps.setString(9, instrutor.getCEP());
            ps.setString(10, instrutor.getCidade());
            ps.setString(11, instrutor.getEstado());
            ps.setString(12, instrutor.getTelefone());
            ps.setString(13, instrutor.getRG());
            ps.setString(14, instrutor.getCelular());
            ps.setString(15, instrutor.getFormacao());
            ps.setString(16, instrutor.getAreaAtuacao());
            ps.setString(17, instrutor.getEmail());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public void alterar(Instrutor instrutor){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("UPDATE tbinstrutor set nome_ins = ?, datanascimento_ins = ?, sexo_ins = ?, estadocivil_ins = ?, endereco_ins = ?, numero_ins = ?, bairro_ins = ?, cep_ins = ?, cidade_ins = ?, estado_ins = ?, telres_ins = ?, rg_ins = ?, celular_ins = ?, formacao_ins = ?, areadeatuacao_ins = ?, email_ins = ? WHERE cpf_ins = ? ");
            
            ps.setString(1, instrutor.getNome());
            ps.setString(2, instrutor.getDataNasc());
            ps.setString(3, instrutor.getSexo());
            ps.setString(4, instrutor.getEstadoCivil());
            ps.setString(5, instrutor.getEndereco());
            ps.setString(6, instrutor.getNumero());
            ps.setString(7, instrutor.getBairro());
            ps.setString(8, instrutor.getCEP());
            ps.setString(9, instrutor.getCidade());
            ps.setString(10, instrutor.getEstado());
            ps.setString(11, instrutor.getTelefone());
            ps.setString(12, instrutor.getRG());
            ps.setString(13, instrutor.getCelular());
            ps.setString(14, instrutor.getFormacao());
            ps.setString(15, instrutor.getAreaAtuacao());
            ps.setString(16, instrutor.getEmail());
            ps.setString(17, instrutor.getCPF());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());  
        }
    }
    
    public Instrutor consultar (String CPF){
        Instrutor i = null;
        PreparedStatement ps = null;
        
        try {
            ps = conn.prepareStatement("SELECT * from tbinstrutor where cpf_ins = ?");
            
            ps.setString(1, CPF);
            
            ResultSet rs = ps.executeQuery();
                       
            if (rs.next() == true) {
                i = new Instrutor(CPF, rs.getString("nome_ins"), rs.getString("datanascimento_ins"), rs.getString("sexo_ins"), rs.getString("estadocivil_ins"), rs.getString("endereco_ins"), rs.getString("numero_ins"), rs.getString("bairro_ins"), rs.getString("cep_ins"), rs.getString("cidade_ins"), rs.getString("estado_ins"), rs.getString("telres_ins"), rs.getString("rg_ins"), rs.getString("celular_ins"), rs.getString("formacao_ins"), rs.getString("areadeatuacao_ins"), rs.getString("email_ins"));
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
        return (i);
    }
    
    public void excluir(Instrutor instrutor){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("DELETE FROM tbinstrutor WHERE cpf_ins = ?");
            
            ps.setString(1, instrutor.getCPF());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
}
