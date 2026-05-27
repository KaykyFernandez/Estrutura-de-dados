#include <stdio.h>
#include <stdlib.h>


void countingSort(unsigned long long arr[], int n, unsigned long long exp, int crescente) {
    unsigned long long output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    if (crescente) {
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    } else {
        for (int i = 8; i >= 0; i--) count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;
        output[count[digito] - 1] = arr[i];
        count[digito]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(unsigned long long arr[], int n, int crescente) {
    unsigned long long exp = 1;
    for (int i = 0; i < 12; i++) {
        countingSort(arr, n, exp, crescente);
        exp *= 10;
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    unsigned long long *pares = malloc(N * sizeof(unsigned long long));
    unsigned long long *impares = malloc(N * sizeof(unsigned long long));
    int p = 0, im = 0;

    for (int i = 0; i < N; i++) {
        unsigned long long valor;
        scanf("%llu", &valor);
        if (valor % 2 == 0) pares[p++] = valor;
        else impares[im++] = valor;
    }

    radixSort(pares, p, 1);    // Crescente
    radixSort(impares, im, 0); // Decrescente

    for (int i = 0; i < p; i++) printf("%llu\n", pares[i]);
    for (int i = 0; i < im; i++) printf("%llu\n", impares[i]);

    free(pares);
    free(impares);
    return 0;
}