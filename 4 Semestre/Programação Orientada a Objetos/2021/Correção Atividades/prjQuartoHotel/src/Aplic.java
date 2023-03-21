import fatec.poo.model.QuartoHotel;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * @author Dimas
 */
public class Aplic {
    public static void main(String [] args){   
        DecimalFormat df = new DecimalFormat("#,##0.00");	
        Scanner entrada = new Scanner(System.in);
        int opcao, numQuarto, rg,nq, qtdeDias;
        double valorDiaria;
       
        System.out.println("Informe o Numero do quarto: ");
        numQuarto = entrada.nextInt();
        System.out.println("Informe o valor da diária: ");
        valorDiaria = entrada.nextDouble();

        QuartoHotel objQuarto = new QuartoHotel(numQuarto,valorDiaria);
        
        do{  
            System.out.println("\n\n1-Consultar quarto");
            System.out.println("2-Reservar quarto");
            System.out.println("3-Liberar quarto");
            System.out.println("4-Consultar faturamento quarto");
            System.out.println("5-Sair");
            System.out.print("\n\tDigite a opcao: ");
            opcao = entrada.nextInt();
            
            switch (opcao) {
                case 1:
                    if(objQuarto.getSituacao())
                        System.out.print("\nSituacao: Ocupado");
                    else
                        System.out.print("\nSituacao: Livre");
                    break;
                case 2:
                    if(objQuarto.getSituacao())
                        System.out.println("\nO quarto já foi reservado.");
                    else{
                        System.out.println("\nInforme o RG: ");
                        rg = entrada.nextInt();
                        objQuarto.reservar(rg);
                    }
                    break;
                case 3:                    
                    if(objQuarto.getSituacao()){
                        System.out.println("\nInforme a qtde de Dias que o cliente ficou hospedado: ");
                        qtdeDias = entrada.nextInt();
                        System.out.println("\nValor a pagar: " + df.format(objQuarto.liberar(qtdeDias))); 
                    }else{
                        System.out.println("\nO quarto já foi liberado.");
                    }                   
                    break;
                case 4:
                    System.out.println("\nFaturamento total: " + df.format(objQuarto.getTotalFaturado()));
                    break;
            }
        }while(opcao < 5);        
    }
}
