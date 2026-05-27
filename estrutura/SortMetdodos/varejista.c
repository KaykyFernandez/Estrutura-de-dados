#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura que representa um item no estoque
typedef struct {
    int id;
    float preco;
} Produto;

/* ************************************************************** */
/* ****                FUNÇÃO PARA GERAR DADOS               **** */
/* ************************************************************** */
void gerarDados(Produto arr[], int n) {

    for (int i = 0; i < n; i++) {

        arr[i].id = rand() % 100000;      // ID aleatório
        arr[i].preco = (rand() % 10000) / 10.0; // preço entre 0 e 1000
    }
}

/* ************************************************************** */
/* ****              FUNÇÃO PARA IMPRESSÃO                   **** */
/* ************************************************************** */
void imprimirEstoque(Produto arr[], int n) {

    printf("-------------------------------------\n");
    printf("%-10s | %-10s\n", "ID Produto", "Preco");
    printf("-------------------------------------\n");

    for (int i = 0; i < n; i++) {

        printf("%-10d | %.2f\n", arr[i].id, arr[i].preco);
    }

    printf("-------------------------------------\n");
}

/* ************************************************************** */
/* ****           IMPLEMENTAÇÃO DO SHELL SORT                **** */
/* ************************************************************** */

void shellSort(Produto vet[], int n){
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    int numGaps = 8;

    for (int g = 0; g < numGaps; g++) {
        int gap = gaps[g];

        if (gap >= n) continue;
        for (int i = gap; i < n; i++) {
            Produto aux = vet[i]; 
            int j;
            for (j = i; j >= gap && vet[j - gap].id > aux.id; j -= gap) {
                vet[j] = vet[j - gap];
            }
            vet[j] = aux;
        }
    }
}

/* ************************************************************** */
/* ****                 FUNÇÃO PRINCIPAL                   ****** */
/* ************************************************************** */
int main() {

    int n;

    printf("Quantidade de produtos a gerar: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor
    Produto *estoque = (Produto*) malloc(n * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    // Gerar dados simulando carga do sistema
    gerarDados(estoque, n);

    printf("\n>>> SISTEMA DE INVENTARIO LEGADO <<<\n");

    printf("\nEstado Inicial do Estoque:\n");
    imprimirEstoque(estoque, n);

    printf("\nExecutando Shell Sort...\n");

    shellSort(estoque, n);

    printf("\nEstado Final do Estoque Ordenado:\n");
    imprimirEstoque(estoque, n);

    free(estoque);

    return 0;
}