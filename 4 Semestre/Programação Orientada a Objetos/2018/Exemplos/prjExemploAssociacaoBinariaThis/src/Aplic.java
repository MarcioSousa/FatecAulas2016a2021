
import fatec.poo.model.Departamento;
import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;
import fatec.poo.model.Projeto;


/**
 *
 * @author dimas
 */
public class Aplic {
    public static void main(String[] args) {             
          //Instanciação          
          FuncionarioHorista funchor=new FuncionarioHorista(1010, "Pedro Silveira", "14/05/1978", 15.80); 
          funchor.apontarHoras(90);         
          funchor.setCargo("Programador");
                        
          FuncionarioMensalista funcmen = new FuncionarioMensalista(2020,"Ana Beatriz", "15/08/1999", 2.5);
          funcmen.apontarValSalMin(600.00);                  
          funcmen.setCargo("Aux. Administrativo");
                       
          FuncionarioComissionado funccom = new FuncionarioComissionado(3030, "Joao Mendes", "10/12/1975", 10);
          funccom.setCargo("Vendedor");
          funccom.setSalBase(900);
          
          //instanciação de objetos da 
          //classe Departamento
          Departamento dep1 = new Departamento("RH", "Recursos Humanos");
          Departamento dep2 = new Departamento("VD", "Vendas");
          
          //estabalecendo a associação binária
          //entre um objeto da classe Departamento
          //com um ou mais objetos da classe Funcionario 
          //(Horista, Mensalista, Comissionado)
          dep1.addFuncionario(funchor);
          dep2.addFuncionario(funcmen);
          dep2.addFuncionario(funccom);
          
          
          System.out.println("O funcionário " +
                              funchor.getNome() +
                             " trabalha no departamento " +
                             funchor.getDepartamento().getNome());
          
          System.out.println("O funcionário " +
                              funcmen.getNome() +
                             " trabalha no departamento " +
                             funcmen.getDepartamento().getNome());
          
          System.out.println("O funcionário " +
                              funccom.getNome() +
                             " trabalha no departamento " +
                             funccom.getDepartamento().getNome());
          
          
          
          dep1.listar();
          dep2.listar();
          
          Projeto proj = new Projeto("IS001", "Segurança no Trabalho");
          proj.setDtInicio("24/04/2018");
          proj.setDtTermino("12/05/2018");
                           
          
          //estabalecendo a associação binária
          //entre um objeto da classe Projeto
          //com um ou mais objetos da classe Funcionario 
          //(Horista, Mensalista, Comissionado)
          proj.addFuncionario(funchor);
          proj.addFuncionario(funcmen);
          proj.addFuncionario(funccom);
          
          proj.listar();
    }    
}
