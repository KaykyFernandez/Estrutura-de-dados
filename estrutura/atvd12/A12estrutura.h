#ifndef LOTEDECARGA_H
#define LOTEDECARGA_H

// Estrutura de um Lote de Carga Computacional (Nó da Lista)
typedef struct no {
    int id;                     // ID único do lote
    int prioridade;             // Quanto maior, mais urgente
    int tempo_execucao;         // Tempo em milissegundos
    long quantidade_dados;      // Quantidade de dados em bytes (Novo campo)
    struct no* proximo;         // Ponteiro para o próximo nó
} No;

// Declaração das funções do TAD
void inicializar_lista(No** cabeca);
void inserir_lote(No** cabeca, int id, int prioridade, int tempo, long dados);
void otimizar_lista(No** cabeca);
void exibir_lista(No* cabeca);
void liberar_lista(No** cabeca);

#endif // LOTEDECARGA_H