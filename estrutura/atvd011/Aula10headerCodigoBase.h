/* *************************************** */ 
/* **** header - arquivo A10header.h  **** */
/* *************************************** */
#ifndef LISTA_H 
 
#define LISTA_H
/* 1.Definir a estrutura do noh da lista */
// 1.1 Definir um tipo e nomeá-lo de No
// 1.2 O tipo No deve ser uma estrutura (atribuir um nome para a estrutura, por exemplo, _no)
// 1.3 A estrutura deve conter o atributo dado (inteiro qur vai identificar um elemento na lista)
// 1.4 A estrutura deve conter o atributo proximo (ponteiro para o próximo elemento da lista)
typedef struct _no {
    int dado;
    struct _no *proximo;
} No;
/* 2. Declarações das funções para operação na lista */

// 2.1 Declarar a função inicializaLista
//     Recebe um ponteiro para ponteiro de No (duplo apontamento)
//     Não retorna nada
void inicializaLista(No **inicio);

// 2.2 Declarar a função listaVazia
//     Recebe um ponteiro de No 
//     Retorna um inteiro (1 se a lista estiver vazia, 0 caso contrário)
int listaVazia(No *inicio);
// 2.3 Declarar a funcao que pesquisa por um elemento na lista
//     Recebe um ponteiro de No
//     Recebe um inteiro (dadoPesquisa)
//     Retorna o endereço de memória do elemento encontrado
//     Retorna NULL se o elemento não for encontrado

// 2.4 Declarar a função imprimeLista
//     Recebe um ponteiro de No
//     Não retorna nada
void imprimeLista(No *inicio);

// 2.5 Declarar a função insereInicio
//     Recebe um ponteiro para ponteiro de No
//     Recebe um inteiro (dado)
//     Não retorna nada

// 2.6 Declarar a função insereFinal
//     Recebe um ponteiro para ponteiro de No
//     Recebe um inteiro (dado)
//     Não retorna nada

// 2.7 Declarar a função insereOrdenado
//     Recebe um ponteiro para ponteiro de No
//     Recebe um inteiro (dado)
//     Não retorna nada

// 2.8 Declarar a função removeInicio
//     Recebe um ponteiro para ponteiro de No
//     Não retorna nada

// 2.9 Declarar a função removeFinal
//     Recebe um ponteiro para ponteiro de No
//     Não retorna nada

// 2.10 Declarar a função removeEspecifico
//     Recebe um ponteiro para ponteiro de No
//     Recebe um inteiro (dado)
//     Não retorna nada

// 2.11 Declarar a função esvaziaLista
//     Recebe um ponteiro para ponteiro de No
//     Não retorna nada 

#endif