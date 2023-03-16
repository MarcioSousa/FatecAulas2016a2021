
import java.util.ArrayList;

public class Teste {

	public static void main(String[] args) {

		TV tv = new TV();
		tv.setCanal(33);
		ArrayList list = new ArrayList();
		
		list.add(tv);
		list.add(tv);
		list.add(tv);
		
		System.out.println(list.size());
		System.out.println(list.get(0));
		System.out.println(list.get(1));
		System.out.println(list.get(2));
		
	}

}
