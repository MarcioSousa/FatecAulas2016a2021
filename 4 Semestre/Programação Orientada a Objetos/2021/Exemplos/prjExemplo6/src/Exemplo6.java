/**
 *
 * @author Dimas
 */
public class Exemplo6 {
    public static void main(String[] args) {
       int[] tabNum; //ponteiro para enderaçamento do tipo int
       int cont;
       
       tabNum = new int[3];//aloção da matriz unidimensional na memória
       tabNum[0]=34;
       tabNum[1]=18;
       tabNum[2]=27;
       
       for (cont=0; cont<3; cont++){
           System.out.println("tabNum[" + cont + "] = " + tabNum[cont]);
       }
    }    
}
