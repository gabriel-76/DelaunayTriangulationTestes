#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void Create_Instance(int NUM_VERTICES){	
	
	srand48(time(NULL));
	
	double x, y, z, t, r;
	int i = 0;
	
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		r = drand48()/2;
		t = rand();
		
		cout << r*cos(t) + 0.5 << " " 
			 << r*sin(t) + 0.5 << " "
			 << drand48()/10 << endl;
		i++;
		
	}
}

int main(int argc, char** argv) {
	
	Create_Instance(atoi(argv[1]));

	return 0;
}
