#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Defina a struct 'aluno' conforme as especificações
typedef struct{
    int ra;
    char nome[20];
    int idade;
    float media;    
}aluno;

int main() {
     // 2. Declare um ponteiro para a struct aluno (aluno *a)
    // 3. Aloque memória dinamicamente para este aluno
    aluno *a = (aluno*) malloc(sizeof(aluno));  
    
    if (a == NULL){
        printf("erro de alocação!");
        return 1;
    }
    
    // 4. Leitura dos dados via teclado (Dica: use a->campo)
    int i;
    for(i = 0; i < 5; i++){

        printf("Digite o RA: ");
        scanf("%d",&a[i].ra);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Digite o Nome: ");
        fgets(a->nome, sizeof(a->nome), stdin);
        a->nome[strlen(a->nome) - 1] = '\0';

        printf("Digite a Idade: ");
        scanf("%d", &a[i].idade);

        printf("Digite a Nota: ");
        scanf("%f",&a[i].media);

    }
    
    // 5. Saída de dados: Imprimir Conteúdo, Endereço e Tamanho de cada campo
    for(i=0; i < 5; i++){
        printf("\n--- RELATÓRIO DE MEMÓRIA ---\n");
        printf("RA: %d | End: %p | %zu\n", a[i].ra, &a[i].ra, sizeof(a[i].ra));
        printf("NOME: %s | End %p | %zu\n", a[i].nome, a[i].nome, sizeof(a[i].nome));
        printf("IDADE: %d | End %p | %zu\n", a[i].idade, &a[i].idade, sizeof(a[i].idade));
        printf("MÉDIA: %f | End %p | %zu\n", a[i].media, &a[i].media, sizeof(a[i].media));
    }
    // 6. Imprimir o endereço do ponteiro 'a' e o tamanho total da struct '*a'
     printf("ENDEREÇO: 'a':%p | tamanho struct: %zu\n",&a, sizeof(*a));
  
    // 7. Liberar a memória
      free(a);
    
    return 0;
}