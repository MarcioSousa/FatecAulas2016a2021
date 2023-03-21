
import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;


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
          
          System.out.println("\nRegistro         =>  " + funchor.getRegistro());
          System.out.println("Nome             =>  " + funchor.getNome());
          System.out.println("Data Admissão    =>  " + funchor.getDtAdmissao());
          System.out.println("Cargo            =>  " + funchor.getCargo());
          System.out.println("Salario Bruto    =>  " + funchor.calcSalBruto());
          System.out.println("Desconto         =>  " + funchor.calcDesconto());
          System.out.println("Gratificação     =>  " + funchor.calcGratificacao());
          System.out.println("Salario Liquido  =>  " + funchor.calcSalLiquido());
    
          FuncionarioMensalista funcmen = new FuncionarioMensalista(2020,"Ana Beatriz", "15/08/1999", 2.5);
          funcmen.apontarValSalMin(600.00);                  
          funcmen.setCargo("Aux. Administrativo");
          
          System.out.println("\nRegistro         =>  " + funcmen.getRegistro());
          System.out.println("Nome             =>  " + funcmen.getNome());
          System.out.println("Data Admissão    =>  " + funcmen.getDtAdmissao());
          System.out.println("Cargo            =>  " + funcmen.getCargo());
          System.out.println("Salario Bruto    =>  " + funcmen.calcSalBruto());
          System.out.println("Desconto         =>  " + funcmen.calcDesconto());
          System.out.println("Salario Liquido  =>  " + funcmen.calcSalLiquido());
    
          FuncionarioComissionado funccom = new FuncionarioComissionado(3030, "Joao Mendes", "10/12/1975", 10);
          
          funccom.setCargo("Vendedor");
        
          funccom.setSalBase(900);
          funccom.addVendas(1000);
          funccom.addVendas(3000);
          funccom.addVendas(4000);
          
          System.out.println("\n\nRegistro: " + funccom.getRegistro());
          System.out.println("Nome: " + funccom.getNome());
          System.out.println("Data admissão: " + funccom.getDtAdmissao());
          System.out.println("Cargo: " + funccom.getCargo());
          System.out.println("Salario Bruto: " + funccom.calcSalBruto());
          System.out.println("Vendas: " + funccom.getTotalVendas());
          System.out.println("Comissao: " + funccom.getTaxaComissao() + "%");
          System.out.println("Desconto: " + funccom.calcDesconto());
          System.out.println("Gratificacao: " + funccom.calcGratificacao());
          System.out.println("Salario Liquido: " + funccom.calcSalLiquido()); 
    }    
}
