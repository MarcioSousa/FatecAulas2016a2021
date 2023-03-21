
import fatec.poo.model.ContaCorrente;
import java.util.Scanner;


public class Aplic {    
    public static void main(String[] args) {
       Scanner entrada = new Scanner(System.in);
       ContaCorrente[] Banco = new ContaCorrente[15];
       int numConta, num, opcao; 
       double valor;
       
       for (int cont = 0; cont < Banco.length; cont++){
           System.out.println("Digite o numero da conta: ");
           numConta = entrada.nextInt();
           System.out.println("Digite o saldo inicial: ");
           valor = entrada.nextDouble();
           Banco[cont] = new ContaCorrente(numConta, valor);
       }
       
       do{
            System.out.println("\n\n\n\tConta Corrente");
            System.out.println("1-Depositar");
            System.out.println("2-Sacar");
            System.out.println("3-Consultar saldo");
            System.out.println("4-Sair");
            System.out.println("\n\n\tDigite a opcao:");
            opcao = entrada.nextInt();
            
            switch(opcao){
                case 1:
                    System.out.println("Digite o numero da conta");
                    numConta = entrada.nextInt();
                    num = pesqConta(Banco, numConta);
                    if(num == -1){
                        System.out.println("Conta nao cadastrada!");
                    }
                    else{
                        System.out.println("Digite o valor depósito: ");
                        Banco[num].depositar(entrada.nextDouble());
                        System.out.println("Operação efetuada com sucesso!");
                    }
                    break;
                case 2:
                    System.out.println("Digite o numero da conta");
                    numConta = entrada.nextInt();
                    num = pesqConta(Banco, numConta);
                    if(num == -1){
                        System.out.println("Conta nao cadastrada!");
                    }
                    else{
                        System.out.println("Digite o valor do saque: ");
                        valor = entrada.nextDouble();
                        if(valor > Banco[num].getSaldo()){
                            System.out.println("Saldo insuficiente!");
                        }
                        else{
                            Banco[num].sacar(valor);
                            System.out.println("Operacao realizada com sucesso");
                        }
                    }
                    
                    break;
                
                case 3:
                    System.out.println("Digite o numero da conta");
                    numConta = entrada.nextInt();
                    num = pesqConta(Banco, numConta);
                    if(num == -1){
                        System.out.println("conta nao cadastrada!");
                    }
                    else{
                        System.out.println("O saldo da conta: " + Banco[num].getSaldo());
                    }
                    
                    break;
                
                case 4:
                    break;               
            }
        }while(opcao != 4);
    }
    public static int pesqConta(ContaCorrente[] banco, int nc) {
        int cont = 0, result = -1;

        while (cont < banco.length && banco[cont].getNumero() != nc) {
            cont++;
        }
        if (cont < banco.length) {
            result = cont;
        }
        return (result);
    }

    
}
