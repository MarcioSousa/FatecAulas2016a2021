
import fatec.poo.model.Aluno;
import fatec.poo.model.Professor;
import java.text.DecimalFormat;

/**
 *
 * @author Dimas
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        
        //instanciação de um objeto da classe Aluno
        Aluno objAluno = new Aluno(1010, "CarlosSilveira", "15/03/1978");
        
        objAluno.setMensalidade(1500);
        System.out.println("Registro Escolar: " + objAluno.getRegEscolar());
        System.out.println("Nome: " + objAluno.getNome());
        System.out.println("Data de Nascimento: " + objAluno.getDataNascimento());
        System.out.println("Mensalidade: " + df.format(objAluno.getMensalidade()));  
        
        //instanciação de um objeto da classe Professor
        Professor objProfessor = new Professor(1010, "Pedro Campos", "11/07/1967");
        
        objProfessor.setSalario(1345.5);
        System.out.println("\n\nRegistro Escolar: " + objProfessor.getRegFuncional());
        System.out.println("Nome: " + objProfessor.getNome());
        System.out.println("Data de Nascimento: " + objProfessor.getDataNascimento());
        System.out.println("Mensalidade: " + df.format(objProfessor.getSalario())); 
    }    
}
