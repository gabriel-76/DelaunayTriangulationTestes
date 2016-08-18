#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void Create_Instance(int NUM_VERTICES){
	
	srand48(time(NULL));
	double t, f, r;
	int i = 0;
	
	f = 100.0;
	
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		
		t = drand48();
		r = drand48()/2;
		
		// //~ f = 100 + (rand() % 10);
		
		r = 0.45 + drand48()/15;
		
		cout << ((1-t)*r)*cos(t*f) + 0.5 << " " 
			 << ((1-t)*r)*sin(t*f) + 0.5 << " "
			 <<  t << endl;
			
		i++;
	}
}

int main(int argc, char** argv) {	
	
	Create_Instance(atoi(argv[1]));
	

	return 0;
}
