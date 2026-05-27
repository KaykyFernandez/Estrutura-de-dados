#include <stdio.h>
#include <stdlib.h>
 
#include "header.h" 



void inicializaLista(No **inicio){
    *inicio = NULL;
}

int listaVazia(No *inicio) {
    
    return (inicio == NULL);
}

void imprimeLista(No *inicio) {
    No *atual = inicio;
    if(listaVazia(inicio)){
        printf("Lista vazia!\n");
        return;
    }
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}