#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../KDTree.h"

#define SIZE_BUCKET 10000

using namespace std;

typedef Ponto generic;

class RadixSort {
public:

    RadixSort();

    static void radixSort(int vetor[], int tamanho);

    static void radixSort2(vector<generic> &vetor, int inicio, int tamanho, int dimensao);
    
};

#endif//RADIX_SORT_H_

