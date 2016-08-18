#ifndef KDTREE_H_
#define KDTREE_H_

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_vertex_base_with_info_3.h>
#include <CGAL/Delaunay_triangulation_3.h>


#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <queue> 

using namespace std;


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_3 <K> Vb;
//typedef CGAL::Triangulation_vertex_base_with_info_3<unsigned, K> Vb;
typedef CGAL::Triangulation_data_structure_3<Vb> Tds;
typedef CGAL::Delaunay_triangulation_3<K, Tds> Delaunay;
typedef Delaunay::Point Point;

class Ponto {
public:

    long int coordenadas[4];

    Ponto() {
    }

    Ponto(long int x, long int y, long int z, int i) {
        coordenadas[0] = x;
        coordenadas[1] = y;
        coordenadas[2] = z;
        coordenadas[3] = i;
    }

    string toString() {
        ostringstream ss;
        ss << coordenadas[0] << "," << coordenadas[1] << "," << coordenadas[2];
        string str = ss.str();
        return str;
    }

};

typedef struct {
    int maior;
    int menor;
    int mediana;
    int dimensao;
} RefDimensao;

class Node {
public:
    Node(int dim, Ponto valor);

    static int nodeCount;

    Node *esquerda, *direita; /*	Referência para cada filho	*/
    int dimensao; /*	Qual a dimensao do corte?	*/
    Ponto valor; /*	Valor (coordenadas) do Node	*/
    int id;

    string toString() {
        string dim[] = {"x", "y", "z"};
        ostringstream ss;
        ss << "[" << valor.toString() << "], " << dim[dimensao] << ", " << id;
        return ss.str();
    }

};

class KDTree {
public:

    vector<Ponto> pontos;

    Node * raiz;

    KDTree(std::vector<Ponto> &ponto, std::vector<Point> &H) ;

    Node * constroi(int inferior, int superior, int dimensao, std::vector<Point> &HEAP);

    RefDimensao obterMaiorDimensao(int inferior, int superior);


    int contValue, contValue2;

    void heap(std::vector<Point> &HEAP);

    virtual ~KDTree();

};

#endif /* KDTREE_H_ */
