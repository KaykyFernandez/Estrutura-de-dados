import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int opcao = 0;
        
        Colab funcionario = new Colab("João", 228, 1586.002);

        System.out.println(funcionario.infoColab());


        Double aumento ;
        

        System.out.println(funcionario.infoColab());

        boolean decisao = true;
        double salarioAtual = funcionario.getSalario();

        while (decisao) {
            System.out.println("o que irá fazer ?\n cadastrar(1) aumento(2) consultar(3)");
            opcao = sc.nextInt();

            switch (opcao) {
                case 1:
                    

                case 2:
                    System.out.println("qual a porcetagem de aumento que quer dar ?");
                    System.out.println(salarioAtual);
                    aumento = sc.nextDouble();
                    funcionario.aumentoSalario(aumento);
                    
                    decisao = false;

                case 3:
                    
                    break;
            
                default:
                    break;
            }
            
        }
        System.out.println(salarioAtual);
        sc.close();
    }
}