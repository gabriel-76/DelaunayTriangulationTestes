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
	
	//~ cout << "escrevendo a instancia" << endl;
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
	
	const double large_axes = 35000000.0;
	double x, y, z;
	int i = 0;
	
	while(i < NUM_VERTICES){
		
		x = (rand()%1000000)/(1000000.0);
		y = (rand()%1000000)/(large_axes);
		z = (rand()%1000000)/(large_axes);
		
			
		if(!dispersion_table.Point_Exist(x,y,z)){
			Recebe_Quadrante(x,y,z,&i);
			dispersion_table.Insert_Dispersion_Table(&vertices[(i-1)]);
		}
		
		if (!(i % INTERVAL_MENSAGE)) cout << i << endl;
		
		x = (rand()%1000000)/(large_axes);
		y = (rand()%1000000)/(1000000.0);
			
		if(!dispersion_table.Point_Exist(x,y,z)){
			Recebe_Quadrante(x,y,z,&i);
			dispersion_table.Insert_Dispersion_Table(&vertices[(i-1)]);
		}
		
		y = (rand()%1000000)/(large_axes);
		z = (rand()%1000000)/(1000000.0);
			
		if(!dispersion_table.Point_Exist(x,y,z)){
			Recebe_Quadrante(x,y,z,&i);
			dispersion_table.Insert_Dispersion_Table(&vertices[(i-1)]);
		}
		
	}
}

int main(int argc, char** argv) {
	
	Create_Instance();
	Write_Instance(argv[1]);	
	
	//~ string mash_view ("../MashView ");
	//~ mash_view += argv[1];	
	system("../MeshView eixos.txt");


	return 0;
}
