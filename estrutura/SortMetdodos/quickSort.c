#include <stdio.h>

// Estrutura de Transação conforme solicitado
typedef struct {
    int id;
    float valor;
    long timestamp; // Chave principal de ordenação
} Transacao;


void quickSort(Transacao vetor[], int esquerda, int direita){
    int i, j; 
    Transacao aux;
    Transacao pivo;
    
    pivo = vetor[direita];

    i = esquerda;
    j = direita;

    while(i <= j){
        while(vetor[i].timestamp < pivo.timestamp && i < direita)
            i++;
        while(vetor[j].timestamp > pivo.timestamp && j > esquerda)
            j--;
        

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            
            i++;
            j--;
        }

    }

    if(j > esquerda){
        quickSort(vetor, esquerda, j);
    }
    if(j < direita){
        quickSort(vetor, i, direita);

    }

}


// Função para exibir o extrato ordenado
void exibirExtrato(Transacao arr[], int n) {
    printf("ID\tValor (R$)\tTimestamp\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t\t%ld\n", arr[i].id, arr[i].valor, arr[i].timestamp);
    }
}

int main() {
    Transacao extrato[] = {
        {101, 250.00, 1709900000},
        {102, 50.00, 1709800000},
        {103, 1200.50, 1709950000},
        {104, 30.00, 1709700000}    // ACRESCENTE MAIS REGISTROS SE DESEJAR
    };
    int n = sizeof(extrato) / sizeof(extrato[0]);
    
    quickSort(extrato, 0, n - 1);
    exibirExtrato(extrato, n);

    return 0;
}