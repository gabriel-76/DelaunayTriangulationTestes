#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

#define NUM_VERTICES 10000
#define NUM_SUBDIVISION 10
#define GET_ID(A) (A / (1.0f / NUM_SUBDIVISION))

const double a = 0.5; 
const double b = 0.5; 
const double c = 1.0;

using namespace std;

typedef struct{
	double x;
	double y;
	double z;
}Ponto;


vector<Ponto> vertices;

Ponto *dispersion_table [NUM_SUBDIVISION][NUM_VERTICES];
int num_interval[NUM_SUBDIVISION];

void print_verrtices( vector<Ponto> &p, int tam){	
	for(int i = 0; i < tam; i++){
		cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
	}
}

void print_ponto(Ponto p){	
	cout << p.x << " " << p.y << " " << p.z << "\t";
}

void print_ponto(double x, double y, double z){	
	cout << x << " " << y << " " << z << "\t";
}

void print_num_interval(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		cout << num_interval[i] << " " ;
	}
	cout<< endl;
}

void print_dispersion_table(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		for(int j = 0; j < num_interval[i]; j++ ){
			print_ponto(*dispersion_table[i][j]);
		}
		cout << endl;
	}
}

void Inicializa_Num_Interval(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		num_interval[i] = 0;
	}
}

void Inicializa_Dispersion_Table(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		for(int j = 0; j < NUM_VERTICES; j++ ){
			dispersion_table[i][j] = NULL;
		}
	}
}

void Insert_Table_Dispersion(Ponto *p){	
	//print_ponto(*p);
	int id = GET_ID(p->z);	
	//cout << "(insert) linha "<< id << ", coluna " << num_interval[id] << endl;	
	dispersion_table[id][num_interval[id]] = p;
	num_interval[id]++;	
}

bool Point_Exist(double x, double y, double z){
	
	//print_ponto(x,y,z);
	
	int id = GET_ID(z);	
	int size = num_interval[id]; 
	//cout << "\nid : " << id  << " size : " << size << endl;
	
	//cout << "(verifica) linha "<< id << ", max " << num_interval[id] << endl;
	
	for(int i = 0; i < size; i++){
		//cout << "instancia ponto" << endl;
		Ponto *p = dispersion_table[id][i];
		//print_ponto(*p);
		if(x == p->x and y == p->y and z == p->z){
			//cout << "Ponto ja esxiste" << endl;
			//getchar();
			return true;
		}
	}
	//cout << "Ponto nao esxiste" << endl;
	return false;	
}

void Write_Instance(){
	ofstream fout("espiral.txt"); // Abre arquivo para gravação em modo texto
	fout << NUM_VERTICES; // Grava o caracter no arquivo
	fout<<"\n";
	for(int i = 0; i< NUM_VERTICES; i++){
		fout << vertices[i].x; // Grava o caracter no arquivo
		fout<<" ";
		fout << vertices[i].y; // Grava o caracter no arquivo
		fout<<" ";
		fout << vertices[i].z; // Grava o caracter no arquivo
		fout<<"\n";
	}
	fout.close();
}

void Recebe_Quadrante(double x, double y, double z, int *indice){					
	vertices[*indice].x = x;
	vertices[*indice].y = y;
	vertices[*indice].z = z;
	(*indice) += 1;		
}

void Create_Instance(){
	
	srand(time(NULL));
	vertices.reserve(NUM_VERTICES);	
	double x, y, z;
	double t, f, r;
	int i = 0;	
	r = M_PI/5;
	f = 100.0;
	
	while(i < NUM_VERTICES){
		
		t = (rand()%1000000)/(1000000.0);
		
		x = (t*r)*cos(f*t);
		y = (t*r)*sin(f*t);
		z = t;
		
		Recebe_Quadrante(x,y,z,&i);
		
		//~ x += 0.01;
		//~ y += 0.01;
		//~ Recebe_Quadrante(x,y,z,&i);
		
		//~ while(
		
		
		//~ int cont = 0;		
		//~ while(pow(x,2)+pow(y,2) <= 0.00001 && cont < 100){
			//~ Recebe_Quadrante(x,y,z,&i);
			//~ cont ++;
		//~ }
		
		 if (!(i % INTERVAL_MENSAGE)) cout << i << endl;
		
	}
}

int main(int argc, char** argv) {
	
	Inicializa_Num_Interval();
	
//~ Inicializa_Dispersion_Table();
	
	Create_Instance();
	
	Write_Instance();
	
	//print_num_interval();
	//print_dispersion_table();
		
	//system("../MashView espiral.txt");

	return 0;
}
