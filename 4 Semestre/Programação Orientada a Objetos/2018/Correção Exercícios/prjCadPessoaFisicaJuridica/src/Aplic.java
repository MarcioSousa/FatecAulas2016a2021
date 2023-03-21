
import fatec.poo.model.PessoaFisica;
import fatec.poo.model.PessoaJuridica;
import java.util.Scanner;

/**
 *
 * @author 0030481521013
 */
public class Aplic {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {            
        Scanner entrada = new Scanner(System.in);
        PessoaFisica objPesFis;
        PessoaJuridica objPesJur;
        
        double valBase, valCompra, txIncentivo;
        String nome, CPFCG;
        int ano;
        
        System.out.println("Digite o CPF");
        CPFCG = entrada.next();
        System.out.println("Digite o nome");
        nome = entrada.next();
        System.out.println("Digite o ano");
        ano = entrada.nextInt();
	objPesFis = new PessoaFisica(CPFCG, nome, ano);
                        
	System.out.println("Digite o valor base: ");
        valBase = entrada.nextDouble();
	objPesFis.setBase(valBase);
                        
	System.out.println("Digite valor da compra");
        valCompra = entrada.nextDouble();                       
        while (valCompra >0){  						      
            objPesFis.addCompras(valCompra);
	    
            System.out.println("Digite valor da compra");
            valCompra = entrada.nextDouble();
	} 
        
        System.out.println("\n\nDigite o CGC");
        CPFCG = entrada.next();
        System.out.println("Digite o nome");
        nome = entrada.next();
        System.out.println("Digite o ano");
        ano = entrada.nextInt();
        objPesJur= new PessoaJuridica(CPFCG, nome, ano);                      
        
        System.out.println("Digite a taxa de incentivo: ");
        txIncentivo = entrada.nextDouble();
        objPesJur.setTaxaIncentivo(txIncentivo);
                         
        System.out.println("Digite valor da compra");
        valCompra = entrada.nextDouble();
        while (valCompra >0){                             
            objPesJur.addCompras(valCompra);
                            
            System.out.println("Digite valor da compra");
            valCompra = entrada.nextDouble();   
        } 
        
        System.out.println("Digite o ano atual(aaaa)");
        ano = entrada.nextInt();
        
        System.out.println("CPF        : " + objPesFis.getCPF());
        System.out.println("Nome       : " + objPesFis.getNome());
        System.out.println("Valor Base : " + objPesFis.getBase());
        System.out.println("Valor Bonus: " + objPesFis.calcBonus(ano));
        
        System.out.println("\n\n\nCGC          : " + objPesJur.getCGC());
        System.out.println("Nome          : " + objPesJur.getNome());
        System.out.println("Tx. Incentivo : " + objPesJur.getTaxaIncentivo());
        System.out.println("Valor Bonus   : " + objPesJur.calcBonus(ano));
    }
}
