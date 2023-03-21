
import java.util.Scanner;

/**
 *
 * @author Marcio Sousa
 */
public class Exemplo1 {
    public static void main(String[] args) {
        int CodProd, QtdeVend;
        String DescProd;
        double PrecUnid, ValVenda;
        Scanner Entrada = new Scanner(System.in);
        
        System.out.println("Digite o código do Produto: ");
        CodProd = Entrada.nextInt();
        
        System.out.println("Digite a descrição do Produto: ");
        DescProd = Entrada.next();
        
        System.out.println("Digite o preço unitário: ");
        PrecUnid = Entrada.nextDouble();
        
        System.out.println("Digite a quantidade vendida: ");
        QtdeVend = Entrada.nextInt();
        
        ValVenda = PrecUnid * QtdeVend;
        System.out.println("O valor da Venda é: " + ValVenda);
    }
}