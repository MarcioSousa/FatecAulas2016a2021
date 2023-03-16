
import java.util.ArrayList;

public class Teste3 {

	public static void main(String[] args) {

		
		ArrayList list = new ArrayList();
		
		System.out.println(list.size());
		
		list.add(new TV());
		list.add(new TV());
		list.add(new TV());
		list.add(new TV());
		list.add("adsasdasdasdas");
		
		for(int i=0; i < list.size(); i++){
			System.out.println(list.get(i));
		}
		
		for(Object  aux : list){
			if(aux instanceof TV){
				TV aux2 = (TV) aux;
				System.out.println("----->" + aux2.getCanal());
			}
			
		}
		
		
		
		
		
		
	}

}
