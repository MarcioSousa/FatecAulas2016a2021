import java.util.Scanner;

/**
 * @author Marcio Sousa
 */

public class Exemplo3 {
    public static void main(String[] args) {
        int CodProd, QtdeVend;
        String DescProd;
        double PrecUnid, ValVenda, Desconto, ValPagar, TotalVendas = 0; 
        Scanner Entrada = new Scanner(System.in);

        System.out.println("Digite o código do Produto: ");
        CodProd = Entrada.nextInt();
        
        while(CodProd != 0){
            System.out.println("Digite a descrição do Produto: ");
            DescProd = Entrada.next();

            System.out.println("Digite o preço unitário: ");
            PrecUnid = Entrada.nextDouble();

            System.out.println("Digite a quantidade vendida: ");
            QtdeVend = Entrada.nextInt();
            
            ValVenda = PrecUnid * QtdeVend;
        
            if(ValVenda <= 1200){
                Desconto = 0;
            }else if(ValVenda <= 2600){
                Desconto = ValVenda * 0.06;
            }else{
                Desconto = ValVenda * 0.08;
            }

            ValPagar = ValVenda - Desconto;
            TotalVendas = TotalVendas + ValVenda;
            
            System.out.println("O valor da Venda é: " + ValVenda);
            System.out.println("O valor de desconto é de: " + Desconto);
            System.out.println("O valor a pagar é de: " + ValPagar);

            System.out.println("\n\nDigite o código do Produto: ");
            CodProd = Entrada.nextInt();
        }
        System.out.println("O Valor Total das Vendas é: " + TotalVendas);
    }
}
