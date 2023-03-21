
import java.util.Scanner;

/**
 *
 * @author Marcio Sousa
 */
public class Exemplo5 {
    public static void main(String[] args) {
        //Definição de uma matriz unidimencional
        //formada por 10 elementos do tipo int.
        int[] MatNum = new int[20];
        int par, impar;
        
        Scanner Entrada = new Scanner(System.in);
        
        for(int t = 1; t < MatNum.length + 1; t++){
            System.out.println("Digite o " + t + "º número inteiro: ");
            MatNum[t - 1] = Entrada.nextInt();
        }
        par = impar = 0;
        //Acesso a matriz
        for(int t = 0; t < MatNum.length; t++){
            if(MatNum[t]%2 == 0){
                par++;
            }else{
                impar++;
            };
        } 
        
        System.out.println("Quantidade de números pares: " + par);
        System.out.println("Quantidade de números impares: " + impar);
    }
}
