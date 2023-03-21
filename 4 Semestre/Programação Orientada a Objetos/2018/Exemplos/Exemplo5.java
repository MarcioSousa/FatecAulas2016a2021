
import java.util.Scanner;


public class Exemplo5 {
    public static void main(String[] args) {
        int CodProd, QtdeVend;
        String DescProd;
        double PrecUnit, ValVenda, Desconto=0, ValPagar, TotVend=0;
        Scanner Entrada = new Scanner(System.in);
        
        System.out.println("Digite o codigo do produto: ");
        CodProd = Entrada.nextInt();
		
		while (CodProd > 0){
			System.out.println("Digite a descricao do produto: ");
			DescProd = Entrada.next();
			System.out.println("Digite preco unitario do produto: ");  
			PrecUnit = Entrada.nextDouble();
			System.out.println("Digite a quantidade vendida do produto: ");
			QtdeVend = Entrada.nextInt();
         
			ValVenda = PrecUnit * QtdeVend;
		
			if (ValVenda > 1200 && ValVenda <= 2600){
			   Desconto = 0.06 * ValVenda;
			}
			else
				if (ValVenda > 2600){
					Desconto = 0.08 * ValVenda;
				}
			ValPagar = ValVenda - Desconto;
		    TotVend += ValPagar;
			
			System.out.println("Valor da Venda: " + 
								ValVenda);
			System.out.println("Valor do Desconto: " +
								Desconto);
			System.out.println("Valor a Pagar: " + 
								ValPagar);
								
			System.out.println("\nDigite o codigo do produto: ");
			CodProd = Entrada.nextInt();					
		}	
		System.out.println("Total das Vendas: " +
						   TotVend);
    }
    
}
