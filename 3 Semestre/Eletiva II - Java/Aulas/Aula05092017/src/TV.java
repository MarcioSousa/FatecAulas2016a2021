

public class TV {
	private int canal;
	private int volume;
	private boolean ligada;
	
	public TV(int canal, int volume, boolean ligada) {
		this.canal = canal;
		this.volume = volume;
		this.ligada = ligada;
	}
	
	public TV(int canal, int volume) {
		this.canal = canal;
		this.volume = volume;
	}
	
	public TV(int canal) {
		this.canal = canal;
	}

	public TV() {
		
	}

	
	public int getCanal() {
		return canal;
	}
	public void setCanal(int canal) {
		this.canal = canal;
	}
	public int getVolume() {
		return volume;
	}
	public void setVolume(int volume) {
		this.volume = volume;
	}
	public boolean isLigada() {
		return ligada;
	}
	
	public void ligar(){
		this.ligada = true;
	}
	
	public void ligar(int canal){
		this.ligada = true;
		this.canal  = canal;
	}
	public void ligar (int canal, int volume){
		this.ligada = true;
		this.volume  = volume;
		this.canal   = canal;
	}
	
	
	public void desligar(){
		this.ligada = false;
	}
	
	@Override
	public String toString() {
		return "TV [canal=" + canal + ", volume=" + volume + ", ligada=" + ligada + "]";
	}
	

	
}




