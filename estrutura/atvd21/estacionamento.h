#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

typedef struct Carro {
    char placa[9];             
    struct Carro* proximo;     
} Carro;


void estacionarCarro(Carro** topo, const char* placa);
void retirarUltimoCarro(Carro** topo);
void consultarVagas(Carro* topo);

#endif 