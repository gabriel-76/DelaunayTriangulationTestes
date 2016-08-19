#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;
char op = '0';

void exit(){
	exit(0);
}

void static_test(){
	
	char caminho[60];
	char caminho2[60];
	strcpy(caminho,"./../Sequential/InexactPredicates/inexact ");
	strcpy(caminho2,"./../KDtreeLiu/InexactPredicates/inexact ");
	
    char file_name[20];
    cout << "Digite o caminho do arquivo" << endl;
    cin >> file_name;
    strcat(caminho,file_name);
    strcat(caminho2,file_name);
    
    
    //cout << caminho << endl;    
    system(caminho);
    system(caminho2);
}

void menu_select_instance(){
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
            << "s- Exit " << endl;
}

void menu_type_tests() {
    cout << "=============== Menu de Testes =================" << endl
         << "=========Select predicate kernel type ==========" <<endl
            << "1- Use inexact predicate kernel type" << endl
            << "2- Use exact predicate kernel type" << endl
            << "s- Exit " << endl;
            
    cin >> op;
    switch (op) {
        case '1': static_test();
            break;
        case '2':
            break;
        case's': exit();
            break;
    }
    op = '0';
    //system("clear");
    //menu_select_instance();

}

void menu() {
    cout << "=============== Menu de Testes =================" << endl
         << "============== Select type test ================" << endl
            << "1- Run static tests" << endl
            << "2- Run dinamic tests" << endl
            << "s- Exit " << endl;
    cin >> op;

    switch (op) {
        case '1': 
            break;
        case'2':
            break;
        case's': exit();
            break;
    }
    op = '0';
    system("clear");
    menu_type_tests();
}

int main() {

    menu();

}
