#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    int ra;
    float n1;
	float n2;
	float media;
} Aluno;


/* ********************************************* */
/* ***     preenche o vetor de submissoes    *** */
/* ***       a partir do arquivo texto       *** */
/* ********************************************* */
void preencheVetor (Aluno *v, int n) {

    Aluno alu;
    int i;

    for (i = 0; i < n; i++) {

        scanf("%d", &alu.ra);
        scanf("%f", &alu.n1);
        scanf("%f", &alu.n2);
        alu.media = (alu.n1 + alu.n2) / 2;
        
        v[i] = alu;
    }
} 


/* ********************************************* */
/* ***   imprime os dados de uma submissao   *** */
/* ***           contida no vetor            *** */
/* ********************************************* */
void imprimeDados (Aluno *v, int ind) {

    if (ind == -1) {
        printf("\nAluno nao foi encontrado!\n");
        return;
    }

    printf("\nDADOS DO ALUNO\n" );

    printf("RA:%d\nN1:%.1f\nN2:%.1f\nMedia:%.1f\n",
                v[ind].ra,
                v[ind].n1,
                v[ind].n2,
                v[ind].media
          );

} 




/* ********************************************* */
/* ***          pesquisa sequencial          *** */
/* ***           pelo RA do aluno            *** */
/* ********************************************* */
int pesquisaSEQ(Aluno *v, int n, int raPesquisado) {
    int i;
    
    for(i =0 ; i < n; i++){
        if(raPesquisado == v[i].ra){
            return v[i].ra;
            break;
        }
    }
}




/* ********************************************* */
/* ***          Codigo principal             *** */
/* ********************************************* */
int main () {

    Aluno *vet;
    int ra;
    int n;
    int indiceRetornado;

    printf("Quantidade de alunos a gerar: ");
    scanf("%d", &n);
    
    vet = (Aluno*) malloc (n * sizeof(Aluno));  // aloca o vetor vet
    preencheVetor(vet, n);                      // preenche o vetor a partir do arquivo texto de entrada

    printf("\nDigite o RA do aluno: ");
    scanf("%d", &ra);  // entra com o RA do aluno a ser pesquisada

    indiceRetornado = pesquisaSEQ(vet, n, ra);   // pesquisa pelos dados da �ltima submiss�o da equipe 
    imprimeDados(vet, indiceRetornado); 	  // imprime os dados do aluno

    printf("\n");
    return 0;

}