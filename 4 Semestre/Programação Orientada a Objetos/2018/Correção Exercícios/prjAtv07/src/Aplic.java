
import fatec.poo.model.Aluno;
import fatec.poo.model.Curso;
import fatec.poo.model.Professor;
import fatec.poo.model.Turma;


/**
 *
 * @author Professor
 */
public class Aplic {

    
    public static void main(String[] args) {
       Curso objCur = new Curso("POO", "Programação Orientada a Objetos", "80");
       
       Professor objProf = new Professor("1010", "Joao Mendes");
       Turma objTur = new Turma("POO_01", 40);              
       
       //instanciação dos alunos
       Aluno objAlu1 = new Aluno("001", "Joao");
       Aluno objAlu2 = new Aluno("002", "Maria");
       Aluno objAlu3 = new Aluno("003", "Pedro");
       Aluno objAlu4 = new Aluno("004", "Carlos");
       Aluno objAlu5 = new Aluno("005", "Rodrigo");
       
       //associações binárias unidirecional
       //entre Turma e Curso, Turma e Professor,
       //Turma e Aluno
       objTur.setCurso(objCur);
       objTur.setProfessor(objProf);
       objTur.addAluno(objAlu1);
       objTur.addAluno(objAlu2);
       objTur.addAluno(objAlu3);
       objTur.addAluno(objAlu4);
       objTur.addAluno(objAlu5);
        
       objTur.listarAlunos();       
    }    
}
