public class Colab {
    String nome;
    int re;
    double salario;

    public Colab() {
    }

     public Colab(String n, int r, double s) {
        this.nome = n;
        this.re = r;
        this.salario = s;
    }

    public String getNome() {
        return nome;
    }



    public void setNome(String nome) {
        this.nome = nome;
    }

    

    public void getRe(int re) {
        this.re = re;
    }


    public double getSalario() {
        return salario;

    }


    public double aumentoSalario(double aumento){
        double resultado = (salario * aumento) / 100;

        this.salario += resultado;


        return  resultado;
    }

    public String infoColab (){
        String dados = "nome do colaborador: "+this.nome+"\nRE: "+re+"\nSalario: "+salario+ " reais";
        
        return dados;
    }

    

}

/*
O sistema deve permitir o cadastro de funcionários, a exibição de suas
informações e a aplicação de um aumento salarial baseado em um percentual
fornecido (por exemplo, um aumento de 10% sobre o salário atual).
Crie um programa principal para testar as funcionalidades, cadastrando alguns
funcionários, exibindo suas informações e aplicando aumentos salariais.
Implemente esse sistema de forma que o controle dos dados seja seguro e
adequado às boas práticas de programação orientada a objetos. */