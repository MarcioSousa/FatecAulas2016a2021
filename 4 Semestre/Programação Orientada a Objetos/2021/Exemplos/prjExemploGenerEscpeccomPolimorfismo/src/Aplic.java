
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;
import java.text.DecimalFormat;


/**
 *
 * @author Aulas
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        FuncionarioHorista funcHor = new FuncionarioHorista(1010,
                                                            "Pedro Silveira",
                                                            "14/05/1978",
                                                            15.80);
        
        funcHor.setCargo("Programador");
        funcHor.setQtdeHorTrab(90);
        System.out.println("Registro         => " + funcHor.getRegistro());
        System.out.println("Nome             => " + funcHor.getNome()); 
        System.out.println("DataAdmissão     => " + funcHor.getDtAdmissao());
        System.out.println("Cargo            => " + funcHor.getCargo());
        System.out.println("Salário Bruto    => " + df.format(funcHor.calcSalBruto()));
        System.out.println("Desconto         => " + df.format(funcHor.calcDesconto()));
        System.out.println("Gratificação     => " + df.format(funcHor.calcGratificacao()));
        System.out.println("Salário Liquido  => " + df.format(funcHor.calcSalLiquido()));
    
    
        FuncionarioMensalista funcMen = new FuncionarioMensalista(2020,
                                                                  "Ana Beatriz",
                                                                  "22/10/1997",
                                                                  600.0);
        
        funcMen.setCargo("Auxiliar Administrativo");
        funcMen.setNumSalMin(2.5);       
      
        System.out.println("\n\nRegistro         => " + funcMen.getRegistro());
        System.out.println("Nome             => " + funcMen.getNome()); 
        System.out.println("DataAdmissão     => " + funcMen.getDtAdmissao());
        System.out.println("Cargo            => " + funcMen.getCargo());
        System.out.println("Salário Bruto    => " + df.format(funcMen.calcSalBruto()));
        System.out.println("Desconto         => " + df.format(funcMen.calcDesconto()));
        System.out.println("Salario Liquido  => " + df.format(funcMen.calcSalLiquido()));
    
        
    
    }
}
