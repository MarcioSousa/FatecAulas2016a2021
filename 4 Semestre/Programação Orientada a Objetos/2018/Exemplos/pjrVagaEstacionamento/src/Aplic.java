import fatec.poo.model.VagaEstacionamento;
import java.util.Scanner;

/**
 *
 * @author Marcio Sousa - Gti-Ads
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner Entrada = new Scanner(System.in);
        VagaEstacionamento matrizVaga[] = new VagaEstacionamento[20];
        int rol;
        
        
        for(int t = 0; t < matrizVaga.length; t++){
            System.out.println("Digite o número do estacionamento: ");
            //matrizVaga[t] = new VagaEstacionamento(Entrada.nextInt());
            matrizVaga[t] = new VagaEstacionamento(t + 1);
        }
        
        do{
           rol = 0;
           System.out.println("1 - Consultar Vaga");
           System.out.println("2 - Ocupar Vaga");
           System.out.println("3 - Liberar Vaga");
           System.out.println("4 - Consultar Faturamento do Estacionamento");
           System.out.println("5 - Sair");
           rol = Entrada.nextInt();
           
           if(rol < 1 || rol > 5){
               System.out.println("Número incorreto.\nDigite um número das opções a seguir:");
           }
           
        }while(rol != 5);
        
  
    }
    
}
