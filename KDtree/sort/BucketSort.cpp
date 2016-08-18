#include "BucketSort.h"


BucketSort::BucketSort() {

}

void BucketSort::ordenaInPlace(vector<Ponto> &lista, int inferior, int superior, int dimensao) {

    int i, j, bucket_index, listPosition = 0, intervalo = superior - inferior;

    vector< vector<Ponto> > buckets(intervalo);

    //for (i = 0; i < intervalo; i++){
    //
    //  sort(buckets[i].begin(), buckets[i].end(), ComparaPonto(dimensao));
    //
    //}

    float maior = -INFINITY, menor = INFINITY;

    for (i = inferior; i < superior; i++) {

        if (lista[i].coordenadas[dimensao] > maior) {
            maior = lista[i].coordenadas[dimensao];
        }
        if (lista[i].coordenadas[dimensao] < menor) {
            menor = lista[i].coordenadas[dimensao];
        }

    }

    if (menor < 0) {
        menor = -menor;
        maior += menor;
    }

    /*	Inserindo os elementos nos baldes	*/
    for (i = inferior; i < superior; i++) {

        bucket_index = floor((intervalo - 1) * (lista[i].coordenadas[dimensao] / maior));

        buckets[bucket_index].push_back(lista[i]);

    }

    /*	Ordenando cada balde	*/
    for (i = 0; i < intervalo; i++) {

        sort(buckets[i].begin(), buckets[i].end(), ComparaPonto(dimensao));

    }

    /*	Concatenando os baldes na lista	*/
    for (i = 0; i < intervalo; i++) {

        for (j = 0; j < (int) buckets[i].size(); j++) {

            lista[inferior + listPosition++] = buckets[i][j];

        }

    }

}
