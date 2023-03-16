
import java.util.ArrayList;

public class Teste2 {

	public static void main(String[] args) {

		
		ArrayList list = new ArrayList();
		
		System.out.println(list.size());
		
		list.add(new TV());
		list.add(new TV());
		list.add("asdasdasdas");
		list.add(list);
		list.add(10.5);
		list.add(new Double(10.5));
		System.out.println(list.size());
		
	}

}
