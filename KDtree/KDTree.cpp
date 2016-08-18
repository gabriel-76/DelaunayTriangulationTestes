#include "KDTree.h"

#include <stddef.h>
#include <cmath>
#include <iostream>
#include <boost/pool/pool_alloc.hpp>
#include "sort/BucketSort.h"
#include "sort/MergeSort.h"

using namespace std;

int Node::nodeCount;

/*
 * Construtor de Node
 * */
Node::Node(int dimensao, Ponto valor) {
    esquerda = direita = NULL; // ponteiros da arvore
    this->valor = valor; // Valor da Coordenada dos pontos
    this->dimensao = dimensao; // Eixo, referente ao ponto, 0 = x, 1 = y, 2 = z
    this->id = Node::nodeCount++; // Numero referente a insercao do ponto
}

/*
 * Construtor de KDTree
 * */
KDTree::KDTree(std::vector<Ponto> &ponto, std::vector<Point> &H) {

    Node::nodeCount = 0;

    pontos = ponto; // Vetor com pontos

    this->raiz = constroi(0, pontos.size(), -1, H); // constroi a arvore e retorna o no da raiz

    //this->pontos.~vector();

}

KDTree::~KDTree() {

    //delete[] pontos;

}

Node* KDTree::constroi(int inferior, int superior, int dimensao, std::vector<Point> &HEAP) {

    // Final do vetor
    if (inferior == superior) {
        return NULL;
    }

    /*	Nodo folha	*/
    if (superior - inferior == 1) {
        Node* nodo = new Node(dimensao, this->pontos[inferior]);
        HEAP[nodo->id] = Point (nodo->valor.coordenadas[0] / 1000000000.0,nodo->valor.coordenadas[1] / 1000000000.0,nodo->valor.coordenadas[2] / 1000000000.0);
        return nodo;
    }

    // recebe o endereco do maior, menor , da mediana e o eixo que foi cortado
    RefDimensao dimensaoCorte = obterMaiorDimensao(inferior, superior);

    /*
     * So eh necessario ordenar o intervalo [inferior, superior]
     * se o corte nao for feito na mesma dimensao do nodo pai
     */

    if (dimensaoCorte.dimensao != dimensao) {
        //RadixSort :: radixSort2(pontos, inferior, superior, dimensaoCorte.dimensao);
        MergeSort :: mergeSort2(pontos, inferior, superior - 1, dimensaoCorte.dimensao);
        //BucketSort::ordenaInPlace(pontos, inferior, superior, dimensaoCorte.dimensao);
    }

    //constroi o ponto da mediana com eixo de maior diferenca
    Ponto pontoMediana = pontos[inferior + dimensaoCorte.mediana];


    /*	Nodo raiz dessa (sub-)arvore	*/
    Node* nodo = new Node(dimensaoCorte.dimensao, pontoMediana);

    // Chamada Recursiva para a sub arvore a esquerda
    nodo->esquerda = constroi(inferior, inferior + dimensaoCorte.mediana, dimensaoCorte.dimensao, HEAP);

    // Chamada Recursiva para a sub arvore a direita
    nodo->direita = constroi(inferior + dimensaoCorte.mediana + 1, superior, dimensaoCorte.dimensao, HEAP);

    HEAP[nodo->id] = Point (nodo->valor.coordenadas[0] / 1000000000.0,nodo->valor.coordenadas[1] / 1000000000.0,nodo->valor.coordenadas[2] / 1000000000.0);
    return nodo;

}

/*
 * Calcula maior e menor valor para cada dimensao.
 * Retorna um RefDimensao referente aa maior dimensao
 * */
RefDimensao KDTree::obterMaiorDimensao(int inferior, int superior) {

    long int maior[3], menor[3];
    int mediana[3], maiorIntervalo = -1, maiorDimensao = -1;
    for (int d = 0; d < 3; ++d) {

        maior[d] = -999999999;
        menor[d] = 999999999; //INFINITY;

        for (int i = inferior; i < superior; ++i) {

            if (this->pontos[i].coordenadas[d] > maior[d]) {
                maior[d] = this->pontos[i].coordenadas[d];
            }
            if (this->pontos[i].coordenadas[d] < menor[d]) {
                menor[d] = this->pontos[i].coordenadas[d];
            }

        }
        mediana[d] = (superior - inferior) / 2;
        if (maior[d] - menor[d] > maiorIntervalo) {
            maiorIntervalo = maior[d] - menor[d];
            maiorDimensao = d;
        }

    }

    RefDimensao dimensaoCorte = {};
    dimensaoCorte.maior = maior[maiorDimensao];
    dimensaoCorte.menor = menor[maiorDimensao];
    dimensaoCorte.mediana = mediana[maiorDimensao];
    dimensaoCorte.dimensao = maiorDimensao;

    return dimensaoCorte;

}

void KDTree::heap(std::vector<Point> &HEAP) {
    
    queue<Node*> fila;    
    fila.push(this->raiz);
    
    Node * aux = NULL;
    
    while(!fila.empty()){
        
        aux = fila.front();
        //cout << aux->id << endl;
        
        if(aux->direita){
            fila.push(aux->direita);
        }
        
        if(aux->esquerda){
            fila.push(aux->esquerda);
        }
        
                
        HEAP.push_back(Point (aux->valor.coordenadas[0] / 1000000000.0,aux->valor.coordenadas[1] / 1000000000.0,aux->valor.coordenadas[2] / 1000000000.0));        
        fila.pop();
    }
}
