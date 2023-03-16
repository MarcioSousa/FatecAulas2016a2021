package teste;

public class TesteArray5 {

	public static void main(String[] args) {
		
		TV tv = new TV(55);
		TV tvs[] = new TV[10];
		
		for(int i=0; i < tvs.length; i++){
			tvs[i] = tv;
		}
		
		tvs[4].setCanal(100);
		
		for(int i=0; i <= tvs.length; i++){
			System.out.println(tvs[i].getCanal());
		}
		
		for(TV aux : tvs){
			System.out.println(aux.getCanal());
		}
		
		
		
		
		
		
				
		// TODO Auto-generated method stub

	}

}
