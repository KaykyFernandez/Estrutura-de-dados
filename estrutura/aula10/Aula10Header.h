/* *************************************** */ 
/* **** header - arquivo A10header.h  **** */
/* *************************************** */
#ifndef LISTA_H 
 
#define LISTA_H
/* estrutura do noh da lista */
typedef struct _no {
    int dado;
    struct _no *proximo;
} No;


/* declaracoes das funcoes de lista */
void inicializaLista (No**);
int listaVazia (No*);

void imprimeLista (No*);

void insereInicio (No**, int);
void insereFinal (No**, int);

void removeInicio (No**);
void removeFinal (No**);


No* pesquisaElemento (No*, int);
void insereOrdenado (No**, int);    
void removeEspecifico (No**, int);
void esvaziaLista (No**)

#endif

