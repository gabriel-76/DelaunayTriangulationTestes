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

void Create_Instance(){	
	
	srand(time(NULL));
	vertices.reserve(NUM_VERTICES);	
	
	double x, y, z;
	int i = 0;
	
	while(i < NUM_VERTICES){
		x = (rand()%1000000)/(1000000.0);
		y = (rand()%1000000)/(1000000.0);
		z = (rand()%1000000)/(1000000.0);
		
			
		if(!dispersion_table.Point_Exist(x,y,z)){
			vertices[i].x = x;
			vertices[i].y = y;
			vertices[i++].z = z;
			dispersion_table.Insert_Dispersion_Table(&vertices[(i-1)]);
		}
		
		 if (!(i % INTERVAL_MENSAGE)) cout << i << endl;
		
	}
}

int main(int argc, char** argv) {
	
	Create_Instance();
	Write_Instance(argv[1]);	
	
	//~ string mash_view ("../MashView ");
	//~ mash_view += argv[1];	
	//~ system(mash_view.c_str());


	return 0;
}
