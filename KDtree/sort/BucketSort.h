#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "../KDTree.h"

using namespace std;

struct ComparaPonto {
    int dimensao;

    ComparaPonto(int dimensao) {
        this->dimensao = dimensao;
    }

    inline bool operator()(const Ponto& p1, const Ponto& p2) {
        return (p1.coordenadas[dimensao] < p2.coordenadas[dimensao]);
    }
};

class BucketSort {
public:

    BucketSort();

    static void ordenaInPlace(vector<Ponto> &lista, int inferior, int superior, int dimensao);
};


#endif//BUCKET_SORT_H_
