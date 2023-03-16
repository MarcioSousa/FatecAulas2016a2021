package aula02;

public class App4 {

	public static void main(String[] args) {

		Produto p1 = new Produto();
		Produto p2 = new Produto();
		Produto p3 = null, p4 =null;
		
		p1.codigo = 10;
		p2 = p1;
		p2.codigo = 30;
		p3 = p2;
		p2 = new Produto();
		p1 = p2;
		p4 = p2;
		p4.codigo++;
		p2.codigo = p1.codigo + 1;
		p2.codigo = p2.codigo + 3;
			
		System.out.println("Codigo:    " + p1.codigo);
		System.out.println("Codigo:    " + p2.codigo);
		System.out.println("Codigo:    " + p3.codigo);
		System.out.println("Codigo:    " + p4.codigo);
		
	}
}

	
	