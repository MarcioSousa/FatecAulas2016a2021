
import fatec.poo.model.GameShop;
import java.util.Scanner;

/**
 *
 * @author Dimas
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int cod, idade, opcao;
        double qtdeHor;

        System.out.println("Digite o código: ");
        cod = entrada.nextInt();
        System.out.println("Digite a idade: ");
        idade = entrada.nextInt();

        //instanciação do objeto da classe GameShop
        //e chamada do método construtor
        GameShop objGame = new GameShop(cod,idade);       
        do {
            System.out.println("\n\n1 - Comprar Horas");
            System.out.println("2 - Jogar");
            System.out.println("3 - Brinde");
            System.out.println("4 - Consultar Saldo de Horas");
            System.out.println("5 - Sair");
            System.out.print("\n\n\t Digite a opcao: ");
            opcao = entrada.nextInt();

            switch (opcao) {
                case 1: System.out.println("\nDigite a qtde. de horas compradas: ");
                        qtdeHor = entrada.nextDouble();
                        objGame.comprar(qtdeHor);
                        break;

                case 2: System.out.println("\nDigite a qtde. de horas jogadas: ");
                        qtdeHor = entrada.nextDouble();
                        if (qtdeHor <= objGame.getQtdeHoras()){
                            objGame.jogar(qtdeHor);
                        }else{
                            System.out.println("Saldo de horas insuficiente");
                        }    
                        break; 
                case 3: objGame.brinde();                    
                        break;
                case 4: System.out.println("\nSaldo de Horas: " + objGame.getQtdeHoras());
                        break;
            }
        } while (opcao < 5);
    } 
}
