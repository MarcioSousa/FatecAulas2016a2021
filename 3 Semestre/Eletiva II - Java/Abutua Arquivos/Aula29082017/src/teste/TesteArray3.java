package teste;

public class TesteArray3 {

	public static void main(String[] args) {
		
		TV tvs[];
		
		tvs = new TV[10];
		
		for(int i=0; i < tvs.length; i++){
		   tvs[i] = new TV(i);	
		}
		
		for(int i=0; i < tvs.length; i++){
			System.out.println(tvs[i]);
		}
		
		
		
		
	}

}
