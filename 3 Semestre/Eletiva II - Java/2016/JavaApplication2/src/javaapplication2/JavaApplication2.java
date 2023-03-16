
package javaapplication2;

/**
 *
 * @author Aluno - Gti-Ads
 */
public class JavaApplication2 {

    public static void main(String[] args) {
        int codProd, qtdeProd;
        String descProd;
        double precUnid, valVenda;
        Scanner entrada = new Scanner();
        
        System.out.println("Digite o código do Produto: ");
        codProd = entrada.nextInt();
        
        System.out.println("Digite a descrição do Produto: ");
        descProd = entrada.next();
        
        System.out.println("Digite o preço unitário: ");
        precUnid = entrada.NextDouble();
        
        System.out.println("Digite a quantidade vendida: ");
        qtdeProd = entrada.nextInt();
        
        valVenda = PrecUnit * qtdeVenda;
        System.out.println("O valor da Venda é: " + valVenda);
    }
}
