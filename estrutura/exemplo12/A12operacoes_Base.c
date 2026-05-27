/* ********************************************* */
/* **** operacoes - arquivo A12operacoes.c  **** */
/* ********************************************* */
#include <stdio.h>
#include <stdlib.h>
#include "Aula12header.h"

/* funcao que inicializa a lista ------------- */
void inicializaLista (No **lista) {

    *lista = NULL;

} /* fim da funcao inicializaLista */

/* funcao que verifica se a lista esta vazia - */
int listaEstaVazia (No *lista) {

    if (lista == NULL)
        return 1;

    return 0;
} /* fim da funcao listaVazia */

/* funcao que imprime o conteudo da lista ----- */
void imprimeLista (No *lista) {

    No *aux = lista;

    if (listaEstaVazia(lista) ){
        printf("A lista esta vazia!\n");
        return;
    }

    printf("Lista:  [  ");

    // loop percorrendo do primeiro ao �ltimo n� da lista  
    while (aux != NULL) {
        printf("%d  ", aux->id);
        aux = aux->proximo;
    }

    printf("]\n");

} /* fim da funcao imprimeLista */


/* funcao que pesquisa por um elemento na lista ----------------------- */
No* pesquisaElemento (No *lista, int idPesquisa) {
    No *aux =lista;
    
    printf("estamos pesquisando o nó %d", idPesquisa);

    //navegar na lista até encotrar o elemnto pesquisado
    while((aux != NULL) && (aux->id != idPesquisado)){
        aux = aux->proximo;
    }

    //são duas possibilidades de retorno um valor nulo indicando que o elemnto não está na lista
    //ou o endereço do elemnto é encontrado

    return aux;

} /* fim da funcao pesquisaElemento */


/* funcao que insere um elemento no inicio da lista ------------------- */
void insereInicio (No **lista, int novoid) {
    
    No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc(sizeof(No));
    novo->id = novoid;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaEstaVazia(*lista) == 1)
        novo->proximo = NULL;
    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

} /* fim da funcao insereInicio */

/* funcao que insere um elemento no final da lista -------------------- */
void insereFinal (No **lista, int novoid) {
    No *novo;
    No *aux = *lista;

    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->id = novoid;
    novo->proximo = NULL;

    /* se a lista estiver vazia, novo noh passa a ser o inicio da lista */
     if (listaEstaVazia(*lista)) {
        *lista = novo;
        return;
    }
	
	/* caso contrario, caminha na lista ate parar no ultimo noh */
    while (aux->proximo != NULL)
         aux = aux->proximo;
        
    /* ultimo noh aponta para o novo noh */
    aux->proximo = novo;

} /* fim da funcao insereFinal */

/* funcao que insere um elemento de forma ordenada na lista */
void insereOrdenado (No **lista, int novoid) {
    No *novo;
    No *atual = *lista;
    No *anterior = *lista;

    //criar o novo nó e aliemntar os dados 
    novo = (No*) malloc(sizeof(No));
    novo->id = novoid;
    novo->proximo = NULL;


    //testar se a lista esta vazia
    if(listaVazia(*lista)){
        *lista = novo;
        return;
    }

    //procurar o local de inclusao na lista
    while((atual != NULL) && (atual->id < novovid) ){
        anterior = atual;
        atual = atual->proximo;
    }

    //testar se a inclusão sera antes do inicio da nó da lista
    if(atual == *lista){
        insereinicio(lista, novoid);
        return;
    }

    //testar se o local é apos o ultimo elemento;
    
    if(atual == NULL){
        insereFinal(lista, novoid);
        return;
    }

    //chegando aqui signifca que a inclusão sera no final da lista
    anterio->proximo = novo;
    novo->proximo = atual;

} /* fim da funcao insereOrdenado */


/* funcao que remove um elemento no inicio da lista -------------------- */
void removeInicio (No **lista){
	
	No *aux = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// fazer o in�cio apontar para o segundo n� da estrutura
	*lista = aux->proximo;
	
	// devolver o uso da mem�ria para o sistema operacional
	free(aux);	
}

/* funcao que remove um elemento no final da lista -------------------- */
void removeFinal (No **lista){
	No *aux = *lista;
	No *anterior = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// caminhar at� o final da lista
	while(aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}
	
	// se existir apenas um no na lista, inicializar a lista
	if(aux == *lista)
		*lista = NULL;
		
	// caso contr�rio, remover o �ltimo elemento da lista
	else
		anterior->proximo = NULL;
		
	// libera a mem�ria do elemento removido
	free(aux);

}

/* funcao que remove um elemento especifico da lista ------------------ */
void removeEspecifico (No **lista, int idRemover){
    No *atual =*lista;
    No *anterior = *lista;

    //testar se a lista esta vazia
    if(listaVazia(*lista))
        return;

    printf("remoção do nó %d\n", idRemover);

    //encontrar o nó a ser removido
    while((atual != NULL) && (atual -> id != idRemover)){
        anterior = atual;
        atual = atual->proximo;
    }

    //testar se o elemento a ser removido não esta na lista
    if(atual ==NULL){
        printf("elemento ID %d não encontrado na lista", idRemover);
    }

    //tester em que local o elemento removido está no inicio da lista
    if(atual == *lista){
        removeInicio(lista);
        return;
    }

    //testar se o elemnto a  ser removido esra no final da lista 
    if(atual ->proximo == NULL){
        removerFinal(lista);
        return;
    }
    

    //chegando aqui siginfa que o elemnto a ser removido está no "meio" da lista
    anterior->proximo = atual->proximo;
    free(atual);
} /* fim da funcao removeElemento */                                                       


/* funcao que esvazia a lista ----------------------------------------- */
void esvaziaLista (No **lista) {

    /* enquanto a lista nao estiver vazia, entao 
	   remove o primeiro noh 
	*/
    while(!listaVazia(*lista))
        removeInicio(lista);
   
    
} /* fim da funcao esvaziaLista */