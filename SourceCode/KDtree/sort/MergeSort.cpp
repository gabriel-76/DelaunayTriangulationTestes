#include "MergeSort.h"

MergeSort::MergeSort() {
};

static void MergeSort::mergeSort(vector<int> &vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if (posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof (int) * (posicaoFim - posicaoInicio + 1));

    while (i < metadeTamanho + 1 || j < posicaoFim + 1) {
        if (i == metadeTamanho + 1) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for (i = posicaoInicio; i != posicaoFim + 1; ++i) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

/*static void MergeSort :: mergeSort2(vector<generic> &vetor, int posicaoInicio, int posicaoFim, int dimensao) {
    int i, j, k, metadeTamanho;
    generic *vetorTemp;

    if (posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    mergeSort2(vetor, posicaoInicio, metadeTamanho, dimensao);
    mergeSort2(vetor, metadeTamanho + 1, posicaoFim, dimensao);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (generic *) malloc(sizeof (generic) * (posicaoFim - posicaoInicio + 1));

    while (i < metadeTamanho + 1 || j < posicaoFim + 1) {
        if (i == metadeTamanho + 1) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i].coordenadas[dimensao] < vetor[j].coordenadas[dimensao]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for (i = posicaoInicio; i <= posicaoFim; ++i) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}*/