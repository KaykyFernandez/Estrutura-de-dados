#include <stdio.h>
#include <stdlib.h>
#include "estacionamento.h"

int main() {
    
    Carro* estacionamento = NULL;
    
    printf("--- SIMULACAO: ESTACIONAMENTO EM PILHA ---\n");
    estacionarCarro(&estacionamento, "ABC-1234");
    consultarVagas(estacionamento);
    estacionarCarro(&estacionamento, "XYZ-9876");
    estacionarCarro(&estacionamento, "MNO-4455");
    
    consultarVagas(estacionamento);
    
    printf("\n--- LIBERACAO DE VEICULOS ---\n");
    retirarUltimoCarro(&estacionamento);
    consultarVagas(estacionamento);
    
    retirarUltimoCarro(&estacionamento);
    consultarVagas(estacionamento);
 
    retirarUltimoCarro(&estacionamento);
    consultarVagas(estacionamento);
 
    retirarUltimoCarro(&estacionamento); 
    consultarVagas(estacionamento);
 
    
    return 0;
}