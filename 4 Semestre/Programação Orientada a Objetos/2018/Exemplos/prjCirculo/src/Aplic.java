
import fatec.poo.model.Circulo;
import java.util.Scanner;/**
 *
 * @author dimas
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Circulo objCirc = new Circulo();
        double medRaio;
        
        System.out.println("Digite a medida do raio: ");
        medRaio = entrada.nextDouble();
        objCirc.setRaio(medRaio);
        
        System.out.println("Medida da área: " + 
                            objCirc.calcArea());
        System.out.println("Medida do perímetro: " +
                            objCirc.calcPerimetro());
        System.out.println("Medida do diâmetro: " +
                            objCirc.calcDiametro());
        
    }      
}








