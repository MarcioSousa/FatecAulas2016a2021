
import fatec.poo.model.PessoaFisica;
import fatec.poo.model.PessoaJuridica;
import java.text.DecimalFormat;


/**
 *
 * @author Dimas
 */
 
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        
        PessoaFisica objFisica = new PessoaFisica("123.456.789-11", 
                                                  "Carlos Silva",
                                                  2010);
                        
        PessoaJuridica objJuridica = new PessoaJuridica("121.233.0001-57",
                                                        "KKK Esporitva",
                                                        2005);
        
        objFisica.setBase(100);                      
	objFisica.addCompras(2000);
	objFisica.addCompras(4000);
        objFisica.addCompras(8000); 
        System.out.println("Ano Atual: 2021");
        System.out.println("\nCPF: " + objFisica.getCpf());
        System.out.println("Nome: " + objFisica.getNome());
        System.out.println("Ano de Inscrição: " + objFisica.getAnoInscricao());
        System.out.println("Valor Base: " + df.format(objFisica.getBase()));
        System.out.println("Total Compras: " + df.format(objFisica.getTotalCompras()));
        System.out.println("Valor do Bonus:  " + df.format(objFisica.calcBonus(2021)));
                         
	objJuridica.setTaxaIncentivo(1);//1%
        objJuridica.addCompras(5000);
	objJuridica.addCompras(10000);
        objJuridica.addCompras(5000);                  
	System.out.println("\n\nCGC: " + objJuridica.getCGC());
        System.out.println("Nome: " + objJuridica.getNome());
        System.out.println("Ano de Inscrição: " + objJuridica.getAnoInscricao());
        System.out.println("Taxa de Incentivo: " + objJuridica.getTaxaIncentivo() + "%");
        System.out.println("Total Compras: " +df.format(objJuridica.getTotalCompras()));
        System.out.println("Valor do Bonus: " + df.format(objJuridica.calcBonus(2021)));
    }
}
