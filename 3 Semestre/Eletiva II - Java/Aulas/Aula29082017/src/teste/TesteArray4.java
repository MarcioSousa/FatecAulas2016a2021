package teste;

public class TesteArray4 {

	public static void main(String[] args) {
		
		TV tvs[] = {new TV(1), new TV(2), new TV(3)};
		
		tvs[0].setCanal(33);
		tvs[1] = new TV(44);
		tvs[2] = tvs[1];
		tvs[1].setCanal(55);
		
		System.out.println(tvs[0].getCanal());
		System.out.println(tvs[1].getCanal());
		System.out.println(tvs[2].getCanal());
		
		

	}

}
