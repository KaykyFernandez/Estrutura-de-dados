#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inicializar_lista(No** cabeca) {
    *cabeca = NULL;
}


No* criar_carga(int id, int prioridade, int tempo, long dados) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        return NULL; 
    }

    novo->id = id;
    novo->prioridade = prioridade;
    novo->tempoExecucao = tempo;     
    novo->quantidadeDados = dados;
    novo->proximo = NULL;

    return novo;
}

// Inserção simples no final da lista para carga inicial de dados
void inserir_lote(No** cabeca, int id, int prioridade, int tempo, long dados) {
    No *novo = criar_carga(id, prioridade, tempo, dados);
    if (novo == NULL) return;
    
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}


void exibir_lista(No* cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No* atual = cabeca;
    while (atual != NULL) {
        printf("[ID:%d P:%d T:%dms D:%ldB] -> \n", 
               atual->id, atual->prioridade, atual->tempoExecucao, atual->quantidadeDados);
        atual = atual->proximo;
    }
    printf("Fim da lista.\n");
}

void liberar_lista(No** cabeca) {
    No* atual = *cabeca;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    *cabeca = NULL;
}


void otimizar_lista(No** cabeca) {
    if (cabeca == NULL || *cabeca == NULL) 
        return;

    // --- PASSO 1 e 3: MOVER PRIORITÁRIOS (P > 10) E EXPURGAR INVÁLIDOS (T <= 0) ---
    No* alta_inicio = NULL;
    No* alta_fim = NULL;
    No* normal_inicio = NULL;
    No* normal_fim = NULL;

    No* atual = *cabeca;
    
    while (atual != NULL) {
        No* proximo_no = atual->proximo; 

        // Passo 3: Expurgo de Lotes Inválidos
        if (atual->tempoExecucao <= 0) {
            free(atual);
        } 
        // Passo 1: Priorização de Emergência (Separação para os de alta prioridade)
        else if (atual->prioridade > 10) {
            if (alta_inicio == NULL) {
                alta_inicio = atual;
                alta_fim = atual;
            } else {
                alta_fim->proximo = atual;
                alta_fim = atual;
            }
            alta_fim->proximo = NULL; 
        } 
        // Cargas Normais
        else {
            if (normal_inicio == NULL) {
                normal_inicio = atual;
                normal_fim = atual;
            } else {
                normal_fim->proximo = atual;
                normal_fim = atual;
            }
            normal_fim->proximo = NULL; 
        }
        
        atual = proximo_no;
    }

    // Reconexão das duas sublistas na lista principal original
    if (alta_inicio != NULL) {
        *cabeca = alta_inicio;
        alta_fim->proximo = normal_inicio;
    } else {
        *cabeca = normal_inicio;
    }

    // --- PASSO 2: FUSÃO DE CARGAS ADJACENTES ---
    atual = *cabeca;
    while (atual != NULL && atual->proximo != NULL) {
        No* proximo = atual->proximo;

        // Se vizinhos têm a mesma prioridade, funde
        if (atual->prioridade == proximo->prioridade) {
            atual->tempoExecucao += proximo->tempoExecucao;
            atual->quantidadeDados += proximo->quantidadeDados;

            // Remove o nó seguinte que foi fundido
            atual->proximo = proximo->proximo;
            free(proximo);
            
        } else {
            atual = atual->proximo;
        }
    }
}