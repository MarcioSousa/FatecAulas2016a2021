package fatec.poo.model;

/**
 *
 * @author Dimas
 */
public class GameShop {
   private int codigo;
   private int idade;
   private double qtdeHoras;

   public GameShop(int codigo, int idade) {
       this.codigo = codigo;
       this.idade = idade;
   }
   
   public void comprar(double qh){
       qtdeHoras += qh; //qtdeHoras = qtdeHoras + qh
   }
   
   public void jogar(double qh){
        qtdeHoras -= qh; //qtdeHoras = qtdeHoras - qh
   }
   
   public void brinde(){
        qtdeHoras = qtdeHoras * 2;
   }

    public int getCodigo() {
        return codigo;
    }

    public int getIdade() {
        return idade;
    }

    public double getQtdeHoras() {
        return qtdeHoras;
    }
}
