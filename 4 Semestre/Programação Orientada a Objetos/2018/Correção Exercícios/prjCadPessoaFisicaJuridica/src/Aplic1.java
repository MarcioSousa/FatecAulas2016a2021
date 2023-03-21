import fatec.poo.model.Pessoa;
import fatec.poo.model.PessoaFisica;
import fatec.poo.model.PessoaJuridica;
import java.util.Scanner;

/**
 *
 * @author Dimas
 */
public class Aplic1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Pessoa[] CadPes = new Pessoa[20];

        double valBase, valCompra, txIncentivo;
        String nome, CPFCG;
        int nPes = 0, opcao, ano;

        do {
            System.out.println("\n\n1- Cadastrar Pessoa Fisica");
            System.out.println("2- Cadastrar Pessoa Juridica");
            System.out.println("3- Listar Bonus");
            System.out.println("4- Fim");
            System.out.println("\nOpção: ");
            opcao = entrada.nextInt();

            switch (opcao) {
                case 1:
                    if (nPes == CadPes.length) {
                        System.out.println("Limite da matriz esgostado\n");
                    } else {

                        System.out.println("Digite o CPF");
                        CPFCG = entrada.next();
                        System.out.println("Digite o nome");
                        nome = entrada.next();
                        System.out.println("Digite o ano");
                        ano = entrada.nextInt();
                        CadPes[nPes] = new PessoaFisica(CPFCG, nome, ano);

                        System.out.println("Digite o valor base: ");
                        valBase = entrada.nextDouble();
                        ((PessoaFisica) CadPes[nPes]).setBase(valBase);

                        System.out.println("Digite valor da compra");
                        valCompra = entrada.nextDouble();
                        while (valCompra > 0) {
                            CadPes[nPes].addCompras(valCompra);

                            System.out.println("Digite valor da compra");
                            valCompra = entrada.nextDouble();
                        }
                        nPes++;
                    }

                    break;
                case 2:
                    if (nPes == CadPes.length) {
                        System.out.println("Limite da matriz esgostado\n");
                    } else {

                        System.out.println("\n\nDigite o CGC");
                        CPFCG = entrada.next();
                        System.out.println("Digite o nome");
                        nome = entrada.next();
                        System.out.println("Digite o ano");
                        ano = entrada.nextInt();
                        CadPes[nPes] = new PessoaJuridica(CPFCG, nome, ano);

                        System.out.println("Digite a taxa de incentivo: ");
                        txIncentivo = entrada.nextDouble();
                        ((PessoaJuridica) CadPes[nPes]).setTaxaIncentivo(txIncentivo);

                        System.out.println("Digite valor da compra");
                        valCompra = entrada.nextDouble();
                        while (valCompra > 0) {
                            CadPes[nPes].addCompras(valCompra);

                            System.out.println("Digite valor da compra");
                            valCompra = entrada.nextDouble();
                        }
                        nPes++;
                    }
                    break;
                case 3:
                    System.out.println("Digite o ano atual(aaaa)");
                    ano = entrada.nextInt();
                    
                    System.out.println("\n\n   Tipo       CPF/CGC             Nome           Bonus");
                    for (int x = 0; x < nPes; x++) {
                        if (CadPes[x] instanceof PessoaFisica){
                            System.out.printf("Fisica       %-13s ", ((PessoaFisica) CadPes[x]).getCPF());
                        }else{    
                            System.out.printf("Juridica     %-13s ", ((PessoaJuridica) CadPes[x]).getCGC());
                        } 
                        System.out.printf("%-20s ", CadPes[x].getNome());
                        System.out.printf("%10.2f", CadPes[x].calcBonus(ano));
                    }
                    break;
            }
        }while(opcao != 4);          
      }
    }
