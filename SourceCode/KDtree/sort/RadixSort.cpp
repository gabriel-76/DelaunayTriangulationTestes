#include "RadixSort.h"

RadixSort :: RadixSort() {
}

void RadixSort :: radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *) calloc(tamanho, sizeof (int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior / exp > 0) {
        int bucket[10] = {0};
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
}

void RadixSort :: radixSort2(vector<generic> &vetor, int inicio, int tamanho, int dimensao) {
    int i;
    generic *b;
    int maior = vetor[inicio].coordenadas[dimensao];
    int exp = inicio + 1;

    b = (generic*) calloc(tamanho, sizeof (generic));

    for (i = inicio; i < tamanho; i++) {
        if (vetor[i].coordenadas[dimensao] > maior)
            maior = vetor[i].coordenadas[dimensao];
    }

    while (maior / exp > inicio) {
        int bucket[SIZE_BUCKET] = {inicio};
        for (i = inicio; i < tamanho; i++)
            bucket[(vetor[i].coordenadas[dimensao] / exp) % SIZE_BUCKET]++;
        for (i = 1; i < SIZE_BUCKET; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= inicio; i--)
            b[--bucket[(vetor[i].coordenadas[dimensao] / exp) % SIZE_BUCKET]] = vetor[i];
        for (i = inicio; i < tamanho; i++)
            vetor[i].coordenadas[dimensao] = b[i].coordenadas[dimensao];
        exp *= SIZE_BUCKET;
    }

    free(b);
}