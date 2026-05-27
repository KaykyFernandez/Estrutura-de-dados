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
void imprimeDados (Aluno *v, int ra) {

    if (ra == -1) {
        printf("\nAluno nao foi encontrado!\n");
        return;
    }

    printf("\nDADOS DE SAIDA\n");

    printf("RA:%d\nN1:%.1f\nN2:%.1f\nMedia:%.1f\n",
                v[ra].ra,
                v[ra].n1,
                v[ra].n2,
                v[ra].media
          );

} 


/* ********************************************** */
/* ***            Pesquisa binaria            *** */
/* ***           chave: RA do aluno           *** */
/* ********************************************** */
int pesquisaBinaria(Aluno *v, int inicio, int fim, int raPesquisado) {
    
    int meio  = (inicio + fim) / 2;

    if(raPesquisado == v[meio].ra){

        return meio;

    }if(inicio>= fim){

        return -1;

    }if(raPesquisado < v[meio].ra){

        return pesquisaBinaria(v,inicio, meio-1, raPesquisado);
    
    }else{
        return pesquisaBinaria(v,meio+1, fim, raPesquisado);
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
	
	indiceRetornado = pesquisaBinaria(vet, 0, n-1, ra); // pesquisa pelo RA do aluno

    imprimeDados(vet, indiceRetornado);   // imprime os dados do aluno

    printf("\n");
    return 0;

}