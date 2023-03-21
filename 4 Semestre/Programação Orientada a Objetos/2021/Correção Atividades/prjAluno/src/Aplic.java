
import fatec.poo.model.Aluno;
import java.util.Scanner;

/**
 *
 * @author dimas
 */
public class Aplic {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Aluno objAluno = new Aluno();
        int opcao;

        System.out.println("Digite o RA do aluno:");
        objAluno.setRa(entrada.nextInt());
        System.out.println("Digite a nota da 1a Prova:");
        objAluno.setNtPrv1(entrada.nextDouble());
        System.out.println("Digite a nota da 2a Prova:");
        objAluno.setNtPrv2(entrada.nextDouble());
        System.out.println("Digite a nota do 1o Trabalho:");
        objAluno.setNtTrab1(entrada.nextDouble());
        System.out.println("Digite a nota do 2o Trabalho:");
        objAluno.setNtTrab2(entrada.nextDouble());

        do {
            System.out.println("\n\n1 - Exibir Nota das Provas/Trabalhos");
            System.out.println("2 - Exibir Média dos Trabalhos/Provas");
            System.out.println("3 - Exibir Média Final");
            System.out.println("4 - Sair");
            System.out.print("\n\n\t Digite a opcao: ");
            opcao = entrada.nextInt();

            System.out.println("\n\nRa: " + objAluno.getRa());
            switch (opcao) {
                case 1:
                    System.out.println("Nota 1a. Prova    : " + objAluno.getNtPrv1());
                    System.out.println("Nota 2a. Prova    : " + objAluno.getNtPrv2());
                    System.out.println("Nota 1o. Trabalho : " + objAluno.getNtTrab1());
                    System.out.println("Nota 2o. Trabalho : " + objAluno.getNtTrab2());
                    break;

                case 2:
                    System.out.println("Média dos Trabalhos: " + objAluno.calcMediaTrab());
                    System.out.println("Média das Provas  : " + objAluno.calcMediaProva());
                    break;

                case 3:
                    System.out.println("Média Final : " + objAluno.calcMediaFinal());
                    break;
            }
        } while (opcao < 4);

    }
}
