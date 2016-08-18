#ifndef DISPERSION_TABLE
#define	DISPERSION_TABLE

#include <iostream>
#include "../Ponto/Ponto.hpp"

#define NUM_VERTICES 100000
#define INTERVAL_MENSAGE 1000
#define NUM_SUBDIVISION 200
#define MAX_COLUM_DISPERSION_TABLE (NUM_VERTICES/10)

#define GET_ID(A) (A / (1.0f / NUM_SUBDIVISION))

using namespace std;

class DispersionTable{
	
	private :
		Ponto *dispersion_table [NUM_SUBDIVISION][MAX_COLUM_DISPERSION_TABLE];
		int num_interval[NUM_SUBDIVISION];		
		void Inicializa_Num_Interval();		
		void Inicializa_Dispersion_Table();		
		
	public :
		DispersionTable();
		
		void Print_Num_Interval();

		void Print_Dispersion_Table();

		void Insert_Dispersion_Table(Ponto *p);

		bool Point_Exist(float x, float y, float z);				
		
};

#endif	/* DISPERSION_TABLE */
