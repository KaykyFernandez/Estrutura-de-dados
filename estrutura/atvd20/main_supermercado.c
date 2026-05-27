#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h" 

int main() {
    No *fila;

    inicializaLista(&fila);
    imprimeFila(fila);

    printf("\n--- CHEGADA DE CLIENTES ---\n");
    chegarCliente(&fila, 101, 12);
    chegarCliente(&fila, 102, 5);
    chegarCliente(&fila, 103, 24);
    imprimeFila(fila);

    printf("\n--- PROCESSANDO ATENDIMENTOS (FIFO) ---\n");
    atenderCliente(&fila);
    imprimeFila(fila);
    
    atenderCliente(&fila);
    imprimeFila(fila);
    atenderCliente(&fila);
    imprimeFila(fila);
    atenderCliente(&fila); // Teste de fila vazia
    imprimeFila(fila);

    return 0;
}