#include <stdio.h>
#include "estrutura.h"

int main() {
    No* minha_lista;
    inicializar_lista(&minha_lista);

    // Simulando a Entrada Bruta conforme o fluxo do exemplo técnico
    // [ID:1 P:5 T:10] -> [ID:2 P:15 T:5] -> [ID:3 P:15 T:20] -> [ID:4 P:8 T:-5] -> [ID:5 P:20 T:10]
    inserir_lote(&minha_lista, 1, 5, 10, 1024);
    inserir_lote(&minha_lista, 2, 15, 5, 512);
    inserir_lote(&minha_lista, 3, 15, 20, 2048);  
    inserir_lote(&minha_lista, 4, 15, 10, 1024);
    inserir_lote(&minha_lista, 5, 8, -5, 0); // Lote inválido (será expurgado)
    inserir_lote(&minha_lista, 6, 20, 10, 4096);

    printf("==================================================\n");
    printf("1. ESTADO INICIAL (ENTRADA BRUTA):\n");
    printf("==================================================\n");
    exibir_lista(minha_lista);
    printf("==================================================\n");
    printf("\n");

    // Executa a higienização e otimização por ponteiros
    otimizar_lista(&minha_lista);

    printf("==================================================\n");
    printf("2. RESULTADO FINAL APOS OTIMIZACAO (SAIDA ESPERADA):\n");
    printf("==================================================\n");
    exibir_lista(minha_lista);
    printf("==================================================\n");

    // Limpeza da memória antes de encerrar o programa
    liberar_lista(&minha_lista);

    return 0;
}