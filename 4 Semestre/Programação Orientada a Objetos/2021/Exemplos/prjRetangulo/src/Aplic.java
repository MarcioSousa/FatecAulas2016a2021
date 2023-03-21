
import fatec.poo.model.Retangulo;
import java.util.Scanner;

/**
 *
 * @author Dimas
 */
public class Aplic {
    public static void main(String[] args) {
        //Instanciação de objetos da classe Scanner 
        //e da classe Retangulo
        Scanner entrada = new Scanner(System.in);
        Retangulo objRet = new Retangulo();
        
        double medBase, medAlt;
        int opcao;
        
        System.out.println("Digite a altura: ");
        medAlt = entrada.nextDouble(); //scanf("%lf", &medAlt);
        System.out.println("Digite a base: ");
        medBase = entrada.nextDouble(); //scanf("%lf", &medBase);
        
        //passagem mensagens
        objRet.setAltura(medAlt);
        objRet.setBase(medBase);
        
        do{
            System.out.println("\n1 - Consultar Área");   
            System.out.println("2 - Consultar Perímetro");
            System.out.println("3 - Sair");
            System.out.print("\n\tDigite sua opção: ");
            opcao = entrada.nextInt(); //scanf("%d", &opcao);
            
            switch(opcao){                                        //passagem de mensagens
                case 1 : System.out.println("\nMedida da Área " + objRet.calcArea());
                         break;
                case 2 : System.out.println("\nMedida da Perímetro " + objRet.calcPerimetro());
                         break;
            }             
        }while(opcao < 3);        
    }    
}
