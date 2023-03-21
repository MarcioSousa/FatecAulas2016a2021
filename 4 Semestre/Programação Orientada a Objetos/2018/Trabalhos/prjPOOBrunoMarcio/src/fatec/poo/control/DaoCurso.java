package fatec.poo.control;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import fatec.poo.model.Curso;
import java.util.ArrayList;

public class DaoCurso {
    private Connection conn;
    
    public DaoCurso(Connection conn){
        this.conn = conn;
    }
    
    public void inserir(Curso curso){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("INSERT INTO tbcurso(sigla_cur, nome_cur, cargahoraria_cur, datavigencia_cur, valor_cur, valorhorainstrutor_cur, programa_cur)VALUES(?,?,?,?,?,?,?)");
            ps.setString(1, curso.getSigla());
            ps.setString(2, curso.getNome());
            ps.setString(3, curso.getCargaHoraria());
            ps.setString(4, curso.getDataVigencia());
            ps.setDouble(5, curso.getValor());
            ps.setDouble(6, curso.getValorHoraInstrutor());
            ps.setString(7, curso.getPrograma());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public void alterar(Curso curso){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("UPDATE tbcurso set nome_cur = ?, cargahoraria_cur = ?, datavigencia_cur = ?, valor_cur = ?, valorhorainstrutor_cur = ?, programa_cur = ? WHERE sigla_cur = ?");
            
            ps.setString(1, curso.getNome());
            ps.setString(2, curso.getCargaHoraria());
            ps.setString(3, curso.getDataVigencia());
            ps.setDouble(4, curso.getValor());
            ps.setDouble(5, curso.getValorHoraInstrutor());
            ps.setString(6, curso.getPrograma());
            ps.setString(7, curso.getSigla());
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());  
        }
    }
    
    public Curso consultar (String sigla){
        Curso c = null;
        PreparedStatement ps = null;
        
        try {
            
            ps = conn.prepareStatement("SELECT * from tbcurso where sigla_cur = ?");
            
            ps.setString(1, sigla);
            ResultSet rs = ps.executeQuery();
                       
            if (rs.next() == true) {
                c = new Curso (sigla, rs.getString("nome_cur"), rs.getString("cargahoraria_cur"), rs.getString("datavigencia_cur"), rs.getDouble("valor_cur"), rs.getDouble("valorhorainstrutor_cur"), rs.getString("programa_cur"));
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
        return (c);
    }
    
    public void excluir(Curso curso){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("DELETE FROM tbcurso WHERE sigla_cur = ?");
            
            ps.setString(1, curso.getSigla());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public ArrayList listarSiglas(){
         PreparedStatement ps = null;
         try {
             ArrayList<Curso> ListarCursos = new ArrayList<Curso>();
             
             ps = conn.prepareStatement("SELECT sigla_cur, nome_cur FROM tbCurso");
             
             ResultSet rs = ps.executeQuery();
             int contador = 0;
             while(rs.next()){
                 Curso curso = new Curso(rs.getString("sigla_cur"), rs.getString("nome_cur"));
                 ListarCursos.add(curso);
             }
             return ListarCursos;
             
         } catch (Exception ex) {
             System.out.println(ex.toString());
             return null;
         }
     }
    
}
