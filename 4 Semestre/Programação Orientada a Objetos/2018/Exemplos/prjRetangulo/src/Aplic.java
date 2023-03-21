
import fatec.poo.model.Retangulo;
import java.util.Scanner;

/**
 *
 * @author dimas
 */
public class Aplic {
    public static void main(String[] args) {
        double medAlt, medBase;
        Scanner entrada = new Scanner(System.in);
        Retangulo objRet = new Retangulo();

        System.out.println("Digite a medida da altura: ");
        medAlt = entrada.nextDouble();
        System.out.println("Digite a medida da base: ");
        medBase = entrada.nextDouble();
        
        objRet.setAltura(medAlt);
        objRet.setBase(medBase);
        
        System.out.println("Área: " + objRet.calcArea());
        System.out.println("Perímetro: " + objRet.calcPerimetro());
        System.out.println("Diagonal: " + objRet.calcDiagonal());
    
        Retangulo objRet1 = new Retangulo();
        System.out.println("\nDigite a medida da altura: ");
        medAlt = entrada.nextDouble();
        System.out.println("Digite a medida da base: ");
        medBase = entrada.nextDouble();
        
        objRet1.setAltura(medAlt);
        objRet1.setBase(medBase);
        
        System.out.println("Área: " + objRet1.calcArea());
        System.out.println("Perímetro: " + objRet1.calcPerimetro());
        System.out.println("Diagonal: " + objRet1.calcDiagonal());
       
        Retangulo objRet2 = new Retangulo();
        System.out.println("\nDigite a medida da altura: ");
        medAlt = entrada.nextDouble();
        System.out.println("Digite a medida da base: ");
        medBase = entrada.nextDouble();
        
        objRet2.setAltura(medAlt);
        objRet2.setBase(medBase);
        
        System.out.println("Área: " + objRet2.calcArea());
        System.out.println("Perímetro: " + objRet2.calcPerimetro());
        System.out.println("Diagonal: " + objRet2.calcDiagonal());
    
    }
    
}
