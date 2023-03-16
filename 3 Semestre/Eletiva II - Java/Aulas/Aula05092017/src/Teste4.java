
import java.util.ArrayList;

public class Teste4 {

	public static void main(String[] args) {

	
		ArrayList <TV> list = new ArrayList <TV>();
		
		System.out.println(list.size());
	
		
		list.add(new TV());
		list.add(new TV());
		list.add(new TV());
		list.add(new TV());
		//list.add("adsasdasdasdas");
		
		
		for(Object  aux : list){
			if(aux instanceof TV){
				TV aux2 = (TV) aux;
				System.out.println("----->" + aux2.getCanal());
			}
			
		}
		
		for(TV tv : list){
			System.out.println(tv.getCanal());
		}
			
			
			
			
			
			
		
		
		
		
		
	}

}
