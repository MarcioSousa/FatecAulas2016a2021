public class Exemplo4{
	public static void main(String[] args){
	   //definição de uma matriz
	   //formada por 10 elementos do 
	   //tipo int
	   
	   int[] MatNum; //definição do ponteiro
	   int cont;
	   MatNum = new int[10]; //alocação da matriz
	  						 //na memória
	   for (cont=0; cont < 10; cont++){
		   MatNum[cont]=(int)(Math.random() * 100);
		   System.out.println("MatNum[" + cont +
		                      "] = " + MatNum[cont]);
	   }
	}
}