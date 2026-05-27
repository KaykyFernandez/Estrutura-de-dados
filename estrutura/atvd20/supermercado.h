#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

typedef struct Cliente {
    int id;
    int qtdItens;
    struct Cliente *proximo;
} No; 


void inicializaLista(No **fila);
void chegarCliente(No **fila, int id, int qtdItens);
void atenderCliente(No **fila);
void imprimeFila(No *fila);

#endif 