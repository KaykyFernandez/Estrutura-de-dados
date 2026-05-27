#include <stdio.h>
#include <stdlib.h>

/* ************************************************ */
/* ************ FUNCOES PARA MERGESORT ************ */
/* ************************************************ */

/* -------------------------------------------------------------------- */
void merge(int *v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = v[left + i];
    for (int j = 0; j < n2; j++) R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

/* -------------------------------------------------------------------- */
void mergeSortRec(int *v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(v, left, mid);
        mergeSortRec(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}


void mergeSort(int *v, int n) {
    mergeSortRec(v, 0, n - 1);
}

/* ************************************************ */
/* ***********           MAIN           *********** */
/* ************************************************ */
int main(void) {

    int *baseDados;
    int n = 10;

    baseDados = (int*) malloc(n * sizeof(int));
    if (!baseDados) {
        printf("Erro de alocacao de memoria\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) 
        baseDados[i] = rand() % 80;

    /* testando Merge sort */
    printf("\nMerge sort\n\n");

    printf("\nEstrutura nao ordenada:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", baseDados[i]);

    mergeSort(baseDados, n);

    printf("\n\nEstrutura ordenada:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", baseDados[i]);

    printf("\n");

    free(baseDados);

    return 0;
}