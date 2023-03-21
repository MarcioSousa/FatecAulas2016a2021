import fatec.poo.model.QuartoHotel;
import java.util.Scanner;

/**
 * @author Aluno - Marcio Sousa
 */
public class Aplic {
    public static void main(String[] args) {       
        int numQuarto, valorDiaria, opcao, Rg, qtdeDias;
        
        Scanner entrada = new Scanner(System.in);
        
        QuartoHotel objQuartoHotel = new QuartoHotel(numQuarto, valorDiaria);
        
        do{  //Menu
            System.out.println(" Hotel Recanto do Sossego");
            System.out.println();
            System.out.println("1 - Consultar Quarto.");
            System.out.println("2 - Reservar Quarto.");
            System.out.println("3 - Liberar Quarto.");
            System.out.println("4 - Consultar Faturamento.");
            System.out.println("5 - Sair.");
            System.out.println("");
            System.out.print("  Digite a opção: ");
            opcao = entrada.nextInt();
           
        }while(opcao != 5);
    }
}