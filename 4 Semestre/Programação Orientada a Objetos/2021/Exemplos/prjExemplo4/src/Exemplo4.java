/**
 *
 * @author Dimas
 */
public class Exemplo4 {
    public static void main(String[] args) {
       int cont, num;
       num = (int)(Math.random() * 100);
       System.out.println("\t\t\tTabuada do " + num);
       
       for (cont=1; cont<=10; cont++){
           System.out.println(num + " x " + cont + " = " + cont * num);
       }
    }    
}
