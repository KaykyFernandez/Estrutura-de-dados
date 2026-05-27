public class Produto {

    private String  nome;
    private double preco;
    private int quantidadeEstoque;

    public Produto(String nome, double preco, int quantidade) {
        this.nome = nome;
        this.preco = this.corrigeNegativo(preco);
        this.quantidadeEstoque = (int)this.corrigeNegativo(quantidade);

    }

    public void exibirDetalhes(){
        System.out.println("Nome: "+ this.nome);
        System.out.println("Preço: R$"+this.preco);
        System.out.println("Qquantidade em Estoque: "+this.quantidadeEstoque);
    }
    
    private double corrigeNegativo(double valor){
        if(valor >=0){
            return valor;
        }else{
            return 0;
        }
    }

    public void adicionarEstoque(int quantidade){
        this.quantidadeEstoque += quantidade;
    }

    public void removerEstoque(int quantidade){
        if (this.quantidadeEstoque >= quantidade) {
            this.quantidadeEstoque -= quantidade;
        }else{
            System.out.println("quantidade insuficiente");
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuantidadeEstoque() {
        return quantidadeEstoque;
    }

    public void setQuantidadeEstoque(int quantidadeEstoque) {
        this.quantidadeEstoque = quantidadeEstoque;
    }

    
        
}
