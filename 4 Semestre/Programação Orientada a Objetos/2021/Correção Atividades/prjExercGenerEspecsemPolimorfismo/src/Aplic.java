
import fatec.poo.model.Cliente;
import fatec.poo.model.Instrutor;
import java.text.DecimalFormat;

/**
 *
 * @author Dimas
 */
public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("0.0");

        //instanciaçãlo de um objeto da classe Instrutor
        Instrutor objInstrutor = new Instrutor(133, "Marcos Andrade", "3222-5578");

        //instanciaçãlo de um objeto da classe Cliente
        Cliente objCliente  = new Cliente ("123.456.789-11", "José Medeiros", "3231-7654");

        objInstrutor.setAreaAtuacao("Atletismo");

        System.out.println("Identificação: " + objInstrutor.getIdentificacao());
        System.out.println("Nome: " + objInstrutor.getNome());
        System.out.println("Telefone: " + objInstrutor.getTelefone());
        System.out.println("Área de Atuação: " + objInstrutor.getAreaAtuacao());

        objCliente.setAltura(1.78);
        objCliente.setPeso(65);

        System.out.println("\n\nCPF: " + objCliente.getCpf());
        System.out.println("Nome: " + objCliente.getNome());
        System.out.println("Telefone: " + objCliente.getTelefone());
        System.out.println("Altura: " + df.format(objCliente.getAltura()));
        System.out.println("Peso: " + df.format(objCliente.getPeso()));
    }
}
