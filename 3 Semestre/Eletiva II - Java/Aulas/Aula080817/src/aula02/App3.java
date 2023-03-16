package aula02;

public class App3 {

	public static void main(String[] args) {

		Produto p1 = new Produto();
		Produto p2 = new Produto();
		Produto p3 = null;
		
		p1.codigo = 10;
		p2 = p1;
		p3 = new Produto();
		p2.codigo = 20;
		
		
		System.out.println("Codigo:    " + p1.codigo);
		System.out.println("Codigo:    " + p2.codigo);
		System.out.println("Codigo:    " + p3.codigo);
		
	}
}

	
	