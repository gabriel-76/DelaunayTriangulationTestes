#include "DispersionTable.hpp"

DispersionTable :: DispersionTable (){
	void Inicializa_Num_Interval();		
	void Inicializa_Dispersion_Table();		
}

void DispersionTable :: Print_Num_Interval(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		cout << num_interval[i] << " " ;
	}
	cout<< endl;
}

void DispersionTable :: Print_Dispersion_Table(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		for(int j = 0; j < num_interval[i]; j++ ){
			//print_ponto(*dispersion_table[i][j]);
		}
		cout << endl;
	}
}

void DispersionTable :: Inicializa_Num_Interval(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		num_interval[i] = 0;
	}
}

void DispersionTable :: Inicializa_Dispersion_Table(){
	for(int i = 0; i < NUM_SUBDIVISION; i++){
		for(int j = 0; j < MAX_COLUM_DISPERSION_TABLE; j++ ){
			dispersion_table[i][j] = NULL;
		}
	}
}

void DispersionTable :: Insert_Dispersion_Table(Ponto *p){	
	int id = GET_ID(p->z);	
	dispersion_table[id][num_interval[id]] = p;
	num_interval[id]++;	
}

bool DispersionTable :: Point_Exist(float x, float y, float z){
	
	int id = GET_ID(z);	
	int size = num_interval[id]; 
	
	for(int i = 0; i < size; i++){

		Ponto *p = dispersion_table[id][i];

		if(x == p->x and y == p->y and z == p->z){
			return true;
		}
	}
	return false;	
}
