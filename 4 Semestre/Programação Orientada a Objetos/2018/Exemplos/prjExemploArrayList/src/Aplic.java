
import fatec.poo.model.Circulo;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author dimas
 */
public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        ArrayList<Circulo> circulos = new ArrayList<Circulo>();
        double medRaio;
        
        System.out.println("Digite a medida do raio: ");
        medRaio = entrada.nextDouble();        
        while (medRaio > 0){
            Circulo objCirc = new Circulo();
            objCirc.setRaio(medRaio);
            circulos.add(objCirc);
            
            System.out.println("Digite a medida do raio: ");
            medRaio = entrada.nextDouble();
        }    
        
        
        for (int x=0; x < circulos.size(); x++){
            System.out.println("\nObjeto Circulo " + (x+1));
            System.out.println("Medida do Raio: " +  circulos.get(x).getRaio());
            System.out.println("Medida da área: " + 
                                circulos.get(x).calcArea());
            System.out.println("Medida do perímetro: " +
                               circulos.get(x).calcPerimetro());
            System.out.println("Medida do diâmetro: " +
                               circulos.get(x).calcDiametro());
        }    
        
    }      
}








