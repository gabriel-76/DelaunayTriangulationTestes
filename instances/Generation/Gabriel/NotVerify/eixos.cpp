#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void Create_Instance(int NUM_VERTICES){		
	srand(time(NULL));
	
	const double large_axes = 30;
	int i = 0, cont = 0;
	
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		
		if(cont == 0){
			cout << drand48() << " "
				 << drand48()/large_axes << " "
				 << drand48()/large_axes << endl;
			
		}else if(cont == 1){
			cout << drand48()/large_axes << " "
				 << drand48() << " "
				 << drand48()/large_axes << endl;
			
		}else {
			
			cout << drand48()/large_axes << " "
				 << drand48()/large_axes << " "
				 << drand48() << endl;
			
			cont = -1;
		}
		i++;
		cont++;
		
	}
}

int main(int argc, char** argv) {
	
	Create_Instance(atoi(argv[1]));

	return 0;
}
