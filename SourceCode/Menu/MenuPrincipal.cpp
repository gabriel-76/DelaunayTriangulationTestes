#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;
char op = '0';

void exit() {
    exit(0);
}

void static_test_inexact() {

    char caminho[150];
    char caminho2[150];
    strcpy(caminho, "./../Sequential/InexactPredicates/inexact ");
    strcpy(caminho2, "./../KDtreeLiu/InexactPredicates/inexact ");
    
    char file_name[60];
    cout << "Digite o caminho do arquivo" << endl;
    cin >> file_name;
    
    ifstream file(file_name);
    if (!file) {
        cout << "File open error\n";
        exit(1);
    }
    
    strcat(caminho, file_name);
    strcat(caminho2, file_name);
   
	strcat(caminho, " >> ../Resultados/inexact.csv");
    strcat(caminho2," >> ../Resultados/inexact.csv");
    
    system(caminho);
    system(caminho2);
    exit(0);
}

void static_test_exact() {
    char caminho[150];
    char caminho2[150];
    strcpy(caminho, "./../Sequential/ExactPredicates/exact ");
    strcpy(caminho2, "./../KDtreeLiu/ExactPredicates/exact ");
    
    char file_name[60];
    cout << "Digite o caminho do arquivo" << endl;
    cin >> file_name;
    
    ifstream file(file_name);
    if (!file) {
        cout << "File open error\n";
        exit(1);
    }
    
    strcat(caminho, file_name);
    strcat(caminho2, file_name);
   
	strcat(caminho, " >> ../Resultados/exact.csv");
    strcat(caminho2," >> ../Resultados/exact.csv");
    
    system(caminho);
    system(caminho2);
    exit(0);
}

void menu_select_instance() {
    cout << "=============== Menu de Testes =================" << endl
            << "============== Select instance =================" << endl
            << "1- Random instance" << endl
            << "2- Planes instance" << endl
            << "3- Paraboloid instance" << endl
            << "4- Spiral instance" << endl
            << "5- Disk instance" << endl
            << "6- Cylinder instance" << endl
            << "7- Axes instance" << endl
            << "8- Saddle instance" << endl
            << "other- Exit " << endl;
}

void menu_type_tests_static() {
    cout << "=============== Menu de Testes =================" << endl
            << "=========Select predicate kernel type ==========" << endl
            << "1- Use inexact predicate kernel type" << endl
            << "2- Use exact predicate kernel type" << endl
            << "other- Exit " << endl;

    cin >> op;
    switch (op) {
        case '1': static_test_inexact();
            break;
        case '2': static_test_exact();
            break;
        case's': exit(0);
            break;
    }
    exit(0);

}

void menu_type_tests_dinamic() {
    cout << "=============== Menu de Testes =================" << endl
            << "=========Select predicate kernel type ==========" << endl
            << "1- Use inexact predicate kernel type" << endl
            << "2- Use exact predicate kernel type" << endl
            << "other - Exit " << endl;

    cin >> op;
    system("clear");
    switch (op) {
        case '1': static_test_inexact();
            break;
        case '2': static_test_exact();
            break;
        case's': exit(0);
            break;
    }
    exit(0);

}

void menu() {
    cout << "=============== Menu de Testes =================" << endl
            << "============== Select type test ================" << endl
            << "1- Run static tests" << endl
            << "2- Run dinamic tests" << endl
            << "other - Exit " << endl;
    cin >> op;
    system("clear");

    switch (op) {
        case '1': menu_type_tests_static();
            break;
        case '2':  menu_type_tests_dinamic();
            break;
        case's': exit();
            break;
    }
    exit(0);
}

int main() {

    menu();

}
