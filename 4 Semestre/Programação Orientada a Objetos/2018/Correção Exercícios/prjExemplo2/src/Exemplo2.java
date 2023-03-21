

import java.util.Scanner;

/**
 * @author Marcio Sosua
 */

public class Exemplo2 {
    public static void main(String[] args) {
        int CodProd, QtdeVend;
        String DescProd;
        double PrecUnid, ValVenda, Desconto, ValPagar;
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
        
        if(ValVenda <= 1200){
            Desconto = 0;
        }else if(ValVenda <= 2600){
            Desconto = ValVenda * 0.06;
        }else{
            Desconto = ValVenda * 0.08;
        }
        
        ValPagar = ValVenda - Desconto;
         
        System.out.println("O valor da Venda é: " + ValVenda);
        System.out.println("O valor de desconto é de: " + Desconto);
        System.out.println("O valor a pagar é de: " + ValPagar);
    }
}