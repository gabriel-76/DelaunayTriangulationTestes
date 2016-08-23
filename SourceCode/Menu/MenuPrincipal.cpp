#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define SIZE_WORD 500

using namespace std;

void static_test_inexact(const char *file_name) {

    char caminho[SIZE_WORD];
    char caminho2[SIZE_WORD];
    strcpy(caminho, "./../Sequential/InexactPredicates/inexact 1 ");
    strcpy(caminho2, "./../KDtreeLiu/InexactPredicates/inexact 1 ");

    ifstream file(file_name);
    if (!file) {
        cout << "File open error\n";
        exit(1);
    }

    strcat(caminho, file_name);
    strcat(caminho2, file_name);

    strcat(caminho, " >> ../Resultados/StaticInexact.csv");
    strcat(caminho2, " >> ../Resultados/StaticInexact.csv");

    system(caminho);
    system(caminho2);
    exit(0);
}

void static_test_exact(const char *file_name) {

    char caminho[SIZE_WORD];
    char caminho2[SIZE_WORD];

    strcpy(caminho, "./../Sequential/ExactPredicates/exact 1 ");
    strcpy(caminho2, "./../KDtreeLiu/ExactPredicates/exact 1 ");

    ifstream file(file_name);
    if (!file) {
        cout << "File open error\n";
        exit(1);
    }

    strcat(caminho, file_name);
    strcat(caminho2, file_name);

    strcat(caminho, " >> ../Resultados/StaticExact.csv");
    strcat(caminho2, " >> ../Resultados/StaticExact.csv");

    system(caminho);
    //system(caminho2);
    exit(0);
}

void dinamic_test_inexact(const char* inst) {

    char caminho[300];
    char caminho2[300];
    strcpy(caminho, "./../Sequential/InexactPredicates/inexact 2 ");
    strcpy(caminho2, "./../KDtreeLiu/InexactPredicates/inexact 2 ");

    strcat(caminho, inst);
    strcat(caminho2, inst);

    strcat(caminho, " ");
    strcat(caminho2, " ");

    char qtd[50];
    cout << "Qual a quantidade de pontos" << endl;
    cin >> qtd;

    strcat(caminho, qtd);
    strcat(caminho2, qtd);

    strcat(caminho, " >> ../Resultados/DinamicInexact.csv");
    strcat(caminho2, " >> ../Resultados/DinamicInexact.csv");

    system(caminho);
    system(caminho2);
    exit(0);
}

void dinamic_test_exact(const char* inst) {

    char caminho[300];
    char caminho2[300];
    strcpy(caminho, "./../Sequential/ExactPredicates/exact 2 ");
    strcpy(caminho2, "./../KDtreeLiu/ExactPredicates/exact 2 ");

    strcat(caminho, inst);
    strcat(caminho2, inst);

    strcat(caminho, " ");
    strcat(caminho2, " ");

    char qtd[50];
    cout << "Qual a quantidade de pontos" << endl;
    cin >> qtd;

    strcat(caminho, qtd);
    strcat(caminho2, qtd);

    strcat(caminho, " >> ../Resultados/DinamicExact.csv");
    strcat(caminho2, " >> ../Resultados/DinamicExact.csv");

    system(caminho);
    system(caminho2);
    exit(0);
}

void check_args(int argc, char **argv) {
    if (argc == 3) {
        int op = atoi(argv[1]);
        if (op == 1) {
            //Static inexact 
            static_test_inexact(argv[2]);
        } else if (op == 2) {
            //Static test exact
            static_test_exact(argv[2]);
        }
    } else if (argc == 4) {
        //exact
    } else {
        cout << "Parametros errados" << endl;
    }

}

int main(int argc, char **argv) {
    check_args(argc, argv);
    return EXIT_SUCCESS;
}
