package fatec.poo.control;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import fatec.poo.model.Curso;

public class DaoCurso {
    private Connection conn;
    
    public DaoCurso(Connection conn){
        this.conn = conn;
    }
    
}
