import fatec.poo.model.QuartoHotel;
import java.util.Scanner;

public class Aplic {
    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        
        QuartoHotel[] Hotel = new QuartoHotel[10];
        
        int Opcao, Cont, NumQuarto;
        double ValorQuarto,TotFatHot;
        
        for(Cont = 0; Cont < Hotel.length ; Cont++){
            System.out.println("Informe o Numero do quarto: ");
            NumQuarto = S.nextInt();
            System.out.println("Informe o valor da diaria: ");
            ValorQuarto = S.nextDouble();
            
            Hotel[Cont] =  new QuartoHotel(NumQuarto,
                                           ValorQuarto);            
        }
            
        
        do{
            System.out.println("\t  Hotel Recanto do Sossego");
            System.out.println("\t1 - Consultar quarto");
            System.out.println("\t2 - Reservar Quarto");
            System.out.println("\t3 - Liberar Quarto");
            System.out.println("\t4 - Consultar Faturamento Quarto");
            System.out.println("\t5 - Consultar Faturamento Hotel");            
            System.out.println("\t6 - Sair");

            System.out.println("\t\tDigite a opção: ");
            Opcao = S.nextInt();
            
            if( Opcao == 1 ){                
                System.out.println("Informe o numero do quarto a ser consultado: ");
                NumQuarto= S.nextInt();               
                                
                if( pesqQuarto(Hotel, NumQuarto) == -1 ){
                    System.out.println("Quarto não cadastrado");
                }else 
                   if(!Hotel[pesqQuarto(Hotel, NumQuarto)].getSituacao()){
                      System.out.println("Quarto Livre");
                   }else{
                      System.out.println("Quarto Ocupado");
                   }   
            }
            else
              if (Opcao == 2){
                   System.out.println("Informe o numero do quarto a ser consultado: ");
                   NumQuarto= S.nextInt();   
                   if( pesqQuarto(Hotel, NumQuarto) == -1 ){
                       System.out.println("Quarto não cadastrado");
                   }else
                     if (Hotel[pesqQuarto(Hotel, NumQuarto)].getSituacao()){
                         System.out.println("Quarto Ocupado");
                     }
                     else{
                       System.out.println("Digite o RG: ");
                       Hotel[pesqQuarto(Hotel, NumQuarto)].reservar(S.nextInt());
                   }                        
              }
              else
                 if (Opcao == 3){  
                     System.out.println("Informe o numero do quarto a ser consultado: ");
                     NumQuarto= S.nextInt();   
                     if( pesqQuarto(Hotel, NumQuarto) == -1 ){
                         System.out.println("Quarto não cadastrado");
                     }else
                       if (!Hotel[pesqQuarto(Hotel, NumQuarto)].getSituacao()){
                           System.out.println("Quarto Livre");
                       }
                       else{
                            int qtdeDias;
                            System.out.println("Informe a qtde. de dias: ");
                            qtdeDias = S.nextInt();
                            System.out.println("Valor da hospedagem: " +
                                               Hotel[pesqQuarto(Hotel, NumQuarto)].liberar(qtdeDias));
                       }
                 }
                 else
                   if (Opcao == 4){
                       System.out.println("Informe o numero do quarto a ser consultado: ");
                     NumQuarto= S.nextInt();   
                     if( pesqQuarto(Hotel, NumQuarto) == -1 ){
                         System.out.println("Quarto não cadastrado");
                     }else{
                         System.out.println("Valor do Faturamento: " +
                                               Hotel[pesqQuarto(Hotel, NumQuarto)].getTotalFaturado());
                      }                   
                   }
                   else
                     if (Opcao == 5){
                         TotFatHot=0;
                         for (int x=0; x<Hotel.length;x++){
                             TotFatHot += Hotel[x].getTotalFaturado();
                         }
                         System.out.println("Faturamento Hotel: " +
                                             TotFatHot);
                     }
        }while(Opcao != 6);        
    }        
    
    public static int pesqQuarto(QuartoHotel[] h,
                                 int nq){
        int Cont, Resultado = -1;
        
        Cont = 0; 
        while(Cont < h.length && 
              h[Cont].getNumQuarto() != nq){ 
             Cont++;
        }
        if (Cont < h.length)
            Resultado = Cont;
        return(Resultado);
    }
}
