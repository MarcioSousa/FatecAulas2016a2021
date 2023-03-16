package teste;

import javax.swing.JOptionPane;

public class TesteTV {

	public static void main(String[] args) {
		
		
		JOptionPane.showInputDialog("Teste");
		JOptionPane.showInputDialog(null,"Texto1","Texto2");
		JOptionPane.showInputDialog(null
				                    ,"Texto1",
				                    "Texto2",
				                    JOptionPane.ERROR_MESSAGE);
		
		
		TV tv1 = new TV(10,30,true);
		TV tv2 = new TV(10,30);
		TV tv3 = new TV(10);
		TV tv4 = new TV();
		
		tv1.ligar();
		tv1.desligar();
		tv1.ligar(10);
		tv1.desligar();
		tv1.ligar(10, 30);
		
		System.out.println(tv1);

	}

}
