package fatec.poo.control;

import fatec.poo.model.Curso;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;
import fatec.poo.model.Turma;

public class DaoTurma {
    private Connection conn;
    
    public void inserir(Turma turma, Curso curso){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("INSERT INTO tbturma(sigla_tur, siglacurso_tur, nome_tur, qtdevagas_tur, periodo_tur, datainicio_tur, datatermino_tur)VALUES(?,?,?,?,?,?,?)");
            
            ps.setString(1, turma.getSiglaTurma());
            ps.setString(2, curso.getSigla());
            ps.setString(3, turma.getDescricao());
            ps.setInt(4, turma.getQtdVagas());
            ps.setString(5, turma.getPeriodo());
            ps.setString(6, turma.getDataInicio());
            ps.setString(7, turma.getDataTermino());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    public void alterar(Turma turma, Curso curso){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("UPDATE tbturma set siglacurso_tur = ?, nome_tur = ?, qtdevagas_tur = ?, periodo_tur = ?, datainicio_tur = ?, datatermino_tur = ? WHERE sigla_tur = ?");
            
            
            ps.setString(1, curso.getSigla());
            ps.setString(2, turma.getDescricao());
            ps.setInt(3, turma.getQtdVagas());
            ps.setString(4, turma.getPeriodo());
            ps.setString(5, turma.getDataInicio());
            ps.setString(6, turma.getDataTermino());
            ps.setString(7, turma.getSiglaTurma());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());  
        }
    }
    
        
    public Turma consultar (String siglaCurso){
        Turma t = null;
        PreparedStatement ps = null;
        
        try {
            
            ps = conn.prepareStatement("SELECT * from tbturma where siglacurso_tur = ?");
            
            ps.setString(1, siglaCurso);
            ResultSet rs = ps.executeQuery();
                       
            if (rs.next() == true) {
                t = new Turma (siglaCurso, rs.getString("sigla_tur"), rs.getString("nome_tur"), rs.getString("datainicio_tur"), rs.getString("datatermino_tur"), rs.getString("periodo_tur"), rs.getInt("qtdevagas_tur"));
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
        return (t);
    }
    
    public void excluir(Turma turma){
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement("DELETE FROM tbturma WHERE sigla_tur = ?");
            
            ps.setString(1, turma.getSiglaTurma());
            
            ps.execute();
        } catch (Exception ex) {
            System.out.println(ex.toString());   
        }
    }
    
    //public Curso carregaTurma (){
    //    Turma t = null;
    //    PreparedStatement ps = null;
    //    
    //    try {
    //        ps = conn.prepareStatement("SELECT siglacurso_tur from tbturma");
    //        
    //        ResultSet rs = ps.executeQuery();
    //                   
    //        if (rs.next() == true) {
    //            t = new Turma (rs.getString("siglacurso_tur"));
    //        }
    //        //for(t = 0; t < ; t++){
    //            
    //        //}
    //    } catch (Exception ex) {
    //        System.out.println(ex.toString());   
    //    }
    //    return (t);
    //}
}
