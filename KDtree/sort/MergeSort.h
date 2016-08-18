#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../KDTree.h"

using namespace std;

typedef Ponto generic;

class MergeSort {
public:

    MergeSort();

    static void mergeSort(vector<int> &vetor, int posicaoInicio, int posicaoFim);

    //static void mergeSort2(vector<generic> &vetor, int posicaoInicio, int posicaoFim, int dimensao);
    
    static void mergeSort2(vector<generic> &vetor, int posicaoInicio, int posicaoFim, int dimensao) {
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
}
};

#endif//MERGE_SORT_H_
