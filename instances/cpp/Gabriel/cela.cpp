#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "DispersionTable/DispersionTable.hpp"

using namespace std;

vector<Ponto> vertices;
static DispersionTable dispersion_table;

void Write_Instance(const char *name_instance){
	ofstream fout(name_instance); // Abre arquivo para gravação em modo texto
	fout << NUM_VERTICES << "\n";	
	for(int i = 0; i< NUM_VERTICES; i++){
		fout << vertices[i].x << " ";
		fout << vertices[i].y << " ";
		fout << vertices[i].z << "\n";
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
	
	const double a = 0.5; 
	const double b = 0.5; 
	const double c = 1.0;

	double x, y, z;
	int i = 0;
	
	while(i < NUM_VERTICES){

		do{
			x = (rand()%1000000)/(1000000.0);
			y = (rand()%1000000)/(1000000.0);
			z = ((pow(x,2)/pow(a,2)) - (pow(y,2)/pow(b,2))) / c;
		}while(z >= 0.5 || z <= -0.5 || x >= 0.5 || x <= -0.5 || y >= 0.5 || y <= -0.5);	
		
		x += 0.5;
		y += 0.5;
		z += 0.5;
		
			
		//if(!dispersion_table.Point_Exist(x,y,z)){				
			Recebe_Quadrante(x,y,z,&i);
			//dispersion_table.Insert_Dispersion_Table(&vertices[(i-1)/4]);
			Recebe_Quadrante(1.0-x,y,z,&i);
			Recebe_Quadrante(x,1.0-y,z,&i);
			Recebe_Quadrante(1.0-x,1.0-y,z,&i);
		//}
		
		 if (!(i % INTERVAL_MENSAGE)) cout << i << endl;
		
	}
}

int main(int argc, char** argv) {
	
	Create_Instance();
	Write_Instance(argv[1]);	
	
	//~ string mash_view ("../MashView ");
	//~ mash_view += argv[1];	
	//system("../MeshView cela.txt");

	return 0;
}
