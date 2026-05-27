/* ****************************************** */
/* **** operacoes - arquivo A10operac.c  **** */
/* ****************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "Aula10header.h" 
 
/* funcao que inicializa a lista -------------------------------------- */
void inicializaLista (No **lista) {

    *lista = NULL;

} /* fim da funcao inicializaLista */

/* funcao que verifica se a lista esta vazia -------------------------- */
int listaVazia (No *lista) {

    if (lista == NULL)
        return 1;

    return 0;

} /* fim da funcao listaVazia */

/* funcao que imprime o conteudo da lista ----------------------------- */
void imprimeLista (No *lista) {

    No *aux = lista;

    if (listaVazia(lista) ){
        printf("A lista esta vazia!\n");
        return;
    }

    printf("Lista:  [  ");

    while (aux != NULL) {
        printf("%d  ", aux->dado);
        aux = aux->proximo;
    }
    printf("]\n");
} /* fim da funcao imprimeLista */


void insereInicio(No **lista, int valorIncluir){

    No *novo;

    novo = (NO*) malloc(sizeof(No));

    novo->dado = valorIncluir;
    novo->proximo = *list;

    *lista = novo;
}

void insereFinal(No **lista, int dado){

    No *novo;
    No *aux = *lista;

    novo = (No*) malloc(sizeof(No));

    novo->dado = dado;
    novo->proximo = NULL;

    if(*lista == NULL){
        *lista = novo;
    }else{

        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void removeInicio(No **lista){

    if(*lista == NULL){
        return;
    }
    No *aux = *lista;

    *lista = aux->proximo;
    free(aux);
}

void removeFinal(No **lista){

    if(*lista == NULL){
        return;
    }

    No *aux = *lista;
    No *anterior = *lista;

    while(aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == *lista){
        *lista = NULL;
    }else{
        anterior->proximo = NULL;
    }
    free(aux);
}




