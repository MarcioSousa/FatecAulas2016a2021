/**
 *
 * @author Dimas
 */
public class Exemplo7 {
    public static void main(String[] args) {
       int cont;
       double media=0;
       
       double[] tabNum = new double[10];     
       
       for (cont=0; cont<10; cont++){
           tabNum[cont] = Math.random() * 100;
           media = media + tabNum[cont];
           System.out.println("tabNum[" + cont + "] = " + tabNum[cont]);
       }
       System.out.println("\nMédia: " + media/10);
    }    
}
