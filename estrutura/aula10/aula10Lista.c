#include <stdio.h>
#include <stdlib.h>
 
#include "Aula10header.h" 

int main() {

    No *inicio;

    inicializaLista(&inicio);

    imprimeLista(inicio);



    insereInicio(&inicio, 1);
    imprimeLista(inicio);
    insereInicio(&inicio, 2);
    imprimeLista(inicio);
    insereInicio(&inicio, 3);
    imprimeLista(inicio);
 
    insereFinal(&inicio, 5);
    imprimeLista(inicio);
    insereFinal(&inicio, 6);
    imprimeLista(inicio);
    insereFinal(&inicio, 7);
    imprimeLista(inicio);

    removeInicio(&inicio);
    imprimeLista(inicio);
    removeInicio(&inicio);
    imprimeLista(inicio);
    removeInicio(&inicio);
    imprimeLista(inicio);
	
    removeFinal(&inicio);
    imprimeLista(inicio);
    removeFinal(&inicio);
    imprimeLista(inicio);
    removeFinal(&inicio);
    imprimeLista(inicio);

    return 0;
}