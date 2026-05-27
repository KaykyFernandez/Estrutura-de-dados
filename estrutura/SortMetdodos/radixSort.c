#include <stdio.h>
#include <stdlib.h>

int obterDigito(unsigned long long num, unsigned long long exp) {
    return (num / exp) % 10;
}


void countingSort(unsigned long long arr[], int n, unsigned long long exp) {
    unsigned long long output[n];
    int count[10] = {0};

    
    for (int i = 0; i < n; i++) {
        count[obterDigito(arr[i], exp)]++;
    }

    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    
    for (int i = n - 1; i >= 0; i--) {
        int digito = obterDigito(arr[i], exp);
        output[count[digito] - 1] = arr[i];
        count[digito]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(unsigned long long arr[], int n) {
    unsigned long long exp = 1;
    
    for (int i = 0; i < 12; i++) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

int main() {
    unsigned long long ids[] = {999888777666, 111222333444, 555444333222, 111000111000};
    int n = sizeof(ids) / sizeof(ids[0]);

    radixSort(ids, n);

    printf("IDs de Rastreamento Ordenados (Infraestrutura ODS 9):\n");
    for (int i = 0; i < n; i++) {
        printf("%llu\n", ids[i]);
    }

    return 0;
}