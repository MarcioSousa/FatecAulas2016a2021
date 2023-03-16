package aula02;

public class App2 {

	public static void main(String[] args) {

		Produto p1 = new Produto();
		Produto p2 = new Produto();
		Produto p3 = null;
		
		p1.codigo = 10;
		p1.preco  = 10.5;
		p1.descricao = "Computador";
		
		
		System.out.println("Codigo:    " + p1.codigo);
		System.out.println("Descricao: " + p1.descricao);
		System.out.println("Preço:     " + p1.preco);
		
		System.out.println("Codigo:    " + p2.codigo);
		System.out.println("Descricao: " + p2.descricao);
		System.out.println("Preço:     " + p2.preco);
		
		System.out.println("Codigo:    " + p3.codigo);
		System.out.println("Descricao: " + p3.descricao);
		System.out.println("Preço:     " + p3.preco);
	}

}
