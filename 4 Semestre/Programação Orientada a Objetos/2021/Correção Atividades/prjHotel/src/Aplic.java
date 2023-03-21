import fatec.poo.model.QuartoHotel;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * @author Dimas
 */

public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#,##0.00");
        
        //definição da matriz de objetos
        QuartoHotel[] hotel = new QuartoHotel[10];
        
        int opcao, cont, numQuarto, rg, qtdeDias;
        double valDiaria,fatHotel;
        
        System.out.println("Informe o valor da diaria: ");
        valDiaria = entrada.nextDouble();
        for(cont = 0; cont < hotel.length ; cont++){
            System.out.println("Informe o Numero do quarto: ");
            numQuarto = entrada.nextInt();
                        
            hotel[cont] =  new QuartoHotel(numQuarto,valDiaria);            
        }
        
        do{           
            System.out.println("\n1-Consultar quarto");
            System.out.println("2-Reservar quarto");
            System.out.println("3-Liberar quarto");
            System.out.println("4-Consultar faturamento quarto");
            System.out.println("5-Consultar faturamento hotel");
            System.out.println("6-Sair");
            System.out.print("\n\tDigite a opção: ");
            opcao = entrada.nextInt();
            
            switch(opcao){
                case 1 : System.out.println("\nInforme o numero do quarto: ");
                         numQuarto = entrada.nextInt();
                         cont = 0; 
                         while (cont < hotel.length && hotel[cont].getNumQuarto() != numQuarto){ 
                            cont++;
                         }
                         if (cont == hotel.length){
                            System.out.println("\nQuarto não cadastrado");
                         }else 
                            if (hotel[cont].getSituacao()){
                                System.out.println("\nQuarto Ocupado");
                            }else{
                                System.out.println("\nQuarto Livre");
                            } 
                          break;
                          
                case 2 : System.out.println("\nInforme o numero do quarto: ");
                         numQuarto= entrada.nextInt();
                         cont = 0; 
                         while (cont < hotel.length && hotel[cont].getNumQuarto() != numQuarto){ 
                            cont++;
                         }
                         if (cont == hotel.length){
                            System.out.println("\nQuarto não cadastrado");
                         }else 
                            if (hotel[cont].getSituacao()){
                                System.out.println("\nQuarto já foi Ocupado");
                            }
                            else{
                                System.out.println("\nDigite o RG: ");
                                rg = entrada.nextInt();
                                hotel[cont].reservar(rg);
                            } 
                         break; 
                case 3 : System.out.println("\nInforme o numero do quarto: ");
                         numQuarto= entrada.nextInt();
                         cont = 0; 
                         while (cont < hotel.length && hotel[cont].getNumQuarto() != numQuarto){ 
                            cont++;
                         }
                         if (cont == hotel.length){
                            System.out.println("\nQuarto não cadastrado");
                         }else  
                            if (hotel[cont].getSituacao()){                               
                               System.out.println("\nInforme a qtde. de dias: ");
                               qtdeDias = entrada.nextInt(); 
                               System.out.println("\nValor da hospedagem: " + df.format(hotel[cont].liberar(qtdeDias)));                           
                            }else{
                               System.out.println("\nQuarto já está Livre");                              
                            }
                         break; 
                         
                case 4 : System.out.println("\nInforme o numero do quarto: ");
                         numQuarto= entrada.nextInt();
                         cont = 0; 
                         while (cont < hotel.length && hotel[cont].getNumQuarto() != numQuarto){ 
                            cont++;
                         }
                         if (cont == hotel.length){
                            System.out.println("\nQuarto não cadastrado");
                         }else{
                            System.out.println("\nFaturamento total: " + df.format(hotel[cont].getTotalFaturado())); 
                         }
                         break;
                         
                case 5 : fatHotel=0;
                         for (cont=0; cont < hotel.length; cont++){
                             fatHotel += hotel[cont].getTotalFaturado();
                         }
                         System.out.println("\nFaturamento do hotel: R$ " + df.format(fatHotel));
            }   
        }while(opcao < 6);        
    } 
}
