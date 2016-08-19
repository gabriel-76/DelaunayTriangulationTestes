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

    char caminho[300];
    char caminho2[300];
    strcpy(caminho, "./../Sequential/InexactPredicates/inexact 1 ");
    strcpy(caminho2, "./../KDtreeLiu/InexactPredicates/inexact 1 ");
    
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
   
	strcat(caminho, " >> ../Resultados/StaticInexact.csv");
    strcat(caminho2," >> ../Resultados/StaticInexact.csv");
    
    system(caminho);
    system(caminho2);
    exit(0);
}

void static_test_exact() {
    char caminho[300];
    char caminho2[300];
    strcpy(caminho, "./../Sequential/ExactPredicates/exact 1 ");
    strcpy(caminho2, "./../KDtreeLiu/ExactPredicates/exact 1 ");
    
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
   
	strcat(caminho, " >> ../Resultados/StaticExact.csv");
    strcat(caminho2," >> ../Resultados/StaticExact.csv");
    
    system(caminho);
    system(caminho2);
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
    strcat(caminho2," ");
    
    char qtd[50];
    cout << "Qual a quantidade de pontos" << endl;
    cin >> qtd;
    
    strcat(caminho, qtd);
    strcat(caminho2,qtd);
   
	strcat(caminho, " >> ../Resultados/dinamicInexact.csv");
    strcat(caminho2," >> ../Resultados/dinamicInexact.csv");
    
    //~ cout << caminho << endl;
    //~ cout << caminho2 << endl;
    
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
    strcat(caminho2," ");
    
    char qtd[50];
    cout << "Qual a quantidade de pontos" << endl;
    cin >> qtd;
    
    strcat(caminho, qtd);
    strcat(caminho2,qtd);
   
	strcat(caminho, " >> ../Resultados/dinamicExact.csv");
    strcat(caminho2," >> ../Resultados/dinamicExact.csv");
    
    //~ cout << caminho << endl;
    //~ cout << caminho2 << endl;
    
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
            
    cin >> op;
    switch (op) {
        case '1': dinamic_test_inexact("1");
            break;
        case '2': static_test_exact();
            break;
        case's': exit(0);
            break;
    }
    exit(0);       
    
            
    
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
	menu_select_instance();

}
/*switch (atoi(argv[2])){
            case 1:strcpy(str,"Aleatorio");
            break;
            case 2:strcpy(str,"Planos");
            break;
            case 3:strcpy(str,"Paraboloide");
            break;
            case 4:strcpy(str,"Espiral");
            break;
            case 5:strcpy(str,"Disco");
            break;
            case 6:strcpy(str,"Cilindro");
            break;
            case 7:strcpy(str,"Eixos");
            break;
            case 8:strcpy(str,"Sela");
            break;            
        }
*/
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
