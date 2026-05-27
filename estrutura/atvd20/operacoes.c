#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"

void inicializaLista(No **fila) {
    *fila = NULL;
}

void chegarCliente(No **fila, int id, int qtdItens) {
    
    No *novoCliente = (No *)malloc(sizeof(No));
    if (novoCliente == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return;
    }
    

    novoCliente->id = id;
    novoCliente->qtdItens = qtdItens;
    novoCliente->proximo = NULL;

    
    if (*fila == NULL) {
        *fila = novoCliente;
    } else {
        
        No *atual = *fila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoCliente;
    }
    printf("Cliente %d (com %d itens) entrou na fila.\n", id, qtdItens);
}


void atenderCliente(No **fila) {
    
    if (*fila == NULL) {
        printf("Aviso: Tentativa de atendimento, mas a fila esta VAZIA!\n");
        return;
    }

    
    No *clienteAtendido = *fila;
    
    
    *fila = (*fila)->proximo;

    printf("Atendendo Cliente ID: %d. Removido da fila.\n", clienteAtendido->id);
    free(clienteAtendido);
}


void imprimeFila(No *fila) {
    printf("Estado da Fila: ");
    if (fila == NULL) {
        printf("[ VAZIA ]\n");
        return;
    }

    No *atual = fila;
    while (atual != NULL) {
        printf("[%d (%dit)] -> ", atual->id, atual->qtdItens);
        atual = atual->proximo;
    }
    printf("NULL\n");
}