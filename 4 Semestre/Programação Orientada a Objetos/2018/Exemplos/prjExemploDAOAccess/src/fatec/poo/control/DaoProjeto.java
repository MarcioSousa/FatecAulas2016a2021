package fatec.poo.control;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import fatec.poo.model.Projeto;

public class DaoProjeto {
    private Connection conn;
    
    public DaoProjeto(Connection conn){
        this.conn = conn;
    }
    
    public void inserir(Projeto projeto){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("INSERT INTO tbprojeto(Codigo_Pro, Descricao_Pro, DataInicio_Pro, DataTermino_Pro) VALUES (?,?,?,?)");
            
            ps.setString(1,projeto.getCodigo());
            ps.setString(2, projeto.getDescricao());
            ps.setString(3, projeto.getDataInicio());
            ps.setString(4, projeto.getDataTermino());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public void alterar(Projeto projeto){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("UPDATE tbprojeto set Descricao_Pro = ?, DataInicio_Pro = ?, DataTermino_Pro = ? WHERE Codigo_Pro = ?");
            
            ps.setString(1, projeto.getDescricao());
            ps.setString(2, projeto.getDataInicio());
            ps.setString(3,projeto.getDataTermino());
            ps.setString(4, projeto.getCodigo());
            ps.execute();
            
        } catch (Exception ex) {
            System.out.println(ex.toString());  
        }
    }
    
    public Projeto consultar (String codigo){
        Projeto p = null;
        PreparedStatement ps = null;
        
        try {
            
            ps = conn.prepareStatement("SELECT * from tbprojeto where Codigo_Pro = ?");
            
            ps.setString(1, codigo);
            ResultSet rs = ps.executeQuery();
                       
            if (rs.next() == true) {
                p = new Projeto (codigo, rs.getString("Descricao_Pro"), rs.getString("DataInicio_Pro"), rs.getString("DataTermino_Pro"));
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
        return (p);
    }
    
    public void excluir(Projeto projeto){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("DELETE FROM tbprojeto WHERE Codigo_Pro = ?");
            
            ps.setString(1, projeto.getCodigo());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
}
















