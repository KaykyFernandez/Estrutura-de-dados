#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamento.h"

void estacionarCarro(Carro** topo, const char* placa) {
    
    Carro* novoCarro = (Carro*)malloc(sizeof(Carro));
    if (novoCarro == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        return;
    }

    
    strncpy(novoCarro->placa, placa, 8);
    novoCarro->placa[8] = '\0';


    novoCarro->proximo = *topo;

    
    *topo = novoCarro;

    printf("Carro [%s] estacionado com sucesso!\n", placa);
}


void retirarUltimoCarro(Carro** topo) {
    
    if (*topo == NULL) {
        printf("Aviso: O estacionamento ja esta vazio. Nenhum carro para retirar.\n");
        return;
    }

    
    Carro* aux = *topo;

    
    *topo = (*topo)->proximo;

    printf("Carro [%s] saindo do estacionamento...\n", aux->placa);

    
    free(aux);
}


void consultarVagas(Carro* topo) {
    printf("\n--- ESTADO ATUAL DO ESTACIONAMENTO (Topo -> Fundo) ---\n");
    
    if (topo == NULL) {
        printf("[ Estacionamento Vazio ]\n");
        printf("------------------------------------------------------\n\n");
        return;
    }

    Carro* atual = topo;
    int posicao = 1;

    
    while (atual != NULL) {
        printf(" Posicao %d: Vaga ocupada pelo carro de placa [%s]\n", posicao, atual->placa);
        atual = atual->proximo;
        posicao++;
    }
    printf("------------------------------------------------------\n\n");
}