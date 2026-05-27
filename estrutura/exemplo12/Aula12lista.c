#include <stdio.h> 
#include "Aula12header.h"

int main() {
    No *inicio, *aux;

    inicializaLista(&inicio);
    imprimeLista(inicio);

  
    printf("\nInsere 4 no inicio\n");
    insereInicio(&inicio, 4);
    imprimeLista(inicio);

    printf("\nInsere 8 no inicio\n");
    insereInicio(&inicio, 8);
    imprimeLista(inicio);

    printf("\nInsere 3 no inicio\n");
    insereInicio(&inicio, 3);
    imprimeLista(inicio);

    printf("\nInsere 23 no inicio\n");
    insereInicio(&inicio, 23);
    imprimeLista(inicio);
    
    printf("\nInsere 18 no final\n");
    insereFinal(&inicio, 18);
    imprimeLista(inicio);

    printf("\nInsere 6 no final\n");
    insereFinal(&inicio, 6);
    imprimeLista(inicio);

    printf("\nInsere 30 no final\n");
    insereFinal(&inicio, 30);
    imprimeLista(inicio);

    printf("\nRemove no final\n");
    removeFinal(&inicio);
    imprimeLista(inicio);

    printf("\nRemove no final\n");
    removeFinal(&inicio);
    imprimeLista(inicio);

    printf("\nRemove no inicio\n");
    removeInicio(&inicio);
    imprimeLista(inicio);
    
 
    aux = pesquisaElemento(inicio, 8);
    if (aux == NULL) 
	    printf("Elemento nao encontrado!\n");
    else 
	    printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 30);
    if (aux == NULL) 
		printf("Elemento nao encontrado!\n");
    else 
		printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 23);
    if (aux == NULL) 
		printf("Elemento nao encontrado!\n");
    else 
		printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 18);
    if (aux == NULL) 
		printf("Elemento nao encontrado!\n");
    else 
		printf("%d encontrado!\n", aux->id);
    
    

    printf("\nRemove o elemento 'id = 15'\n");    
    removeEspecifico(&inicio, 15);
    imprimeLista(inicio);

    printf("\nRemove 'id = 4'\n");    
    removeEspecifico(&inicio, 4);
    imprimeLista(inicio);

    printf("\nRemove 'id = 18'\n");    
    removeEspecifico(&inicio, 18);
    imprimeLista(inicio);

    printf("\nRemove 'id = 12'\n");    
    removeEspecifico(&inicio, 12);
    imprimeLista(inicio);


/*  ROTINA PARA ESVAZIAR A LISTA */
	printf("\n\nEsvaziando a lista\n");
	esvaziaLista(&inicio);
    imprimeLista(inicio);
   
    printf("\nInsere 50\n");    
    insereOrdenado(&inicio, 50);
    imprimeLista(inicio);

    printf("\nInsere 55\n");    
    insereOrdenado(&inicio, 55);
    imprimeLista(inicio);

    printf("\nInsere 52\n");    
    insereOrdenado(&inicio, 52);
    imprimeLista(inicio);

    printf("\nInsere 45\n");    
    insereOrdenado(&inicio, 45);
    imprimeLista(inicio);

    printf("\nInsere 47\n");    
    insereOrdenado(&inicio, 47);
    imprimeLista(inicio);

    printf("\nInsere 60\n");    
    insereOrdenado(&inicio, 60);
    imprimeLista(inicio);

    printf("\nInsere 54\n");    
    insereOrdenado(&inicio, 54);
    imprimeLista(inicio);
    

    aux = pesquisaElemento(inicio, 45);
   if (aux == NULL) 
	    printf("Elemento nao encontrado!\n");
    else 
	    printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 100);
    if (aux == NULL) printf("Elemento nao encontrado!\n");
    else printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 60);
    if (aux == NULL) printf("Elemento nao encontrado!\n");
    else printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 55);
    if (aux == NULL) printf("Elemento nao encontrado!\n");
    else printf("%d encontrado!\n", aux->id);

    aux = pesquisaElemento(inicio, 51);
    if (aux == NULL) printf("Elemento nao encontrado!\n");
    else printf("%d encontrado!\n", aux->id);

    printf("\n");
	imprimeLista(inicio);

    printf("\n\nEsvaziando a lista\n");
	esvaziaLista(&inicio);
    imprimeLista(inicio);
    
    return 0;

} /* fim da funcao main */