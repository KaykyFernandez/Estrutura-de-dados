public class balcao {
    public static void main(String[] args) throws Exception {
        Produto p1 = new Produto("caneca", 5.00, 10);
        p1.exibirDetalhes();

        Produto p2 =new Produto("MOuse", 50.00,10);
        p2.exibirDetalhes();
        p2.adicionarEstoque(4);
        p2.exibirDetalhes();
        p2.removerEstoque(4);
        p2.exibirDetalhes();

        

    }
}
