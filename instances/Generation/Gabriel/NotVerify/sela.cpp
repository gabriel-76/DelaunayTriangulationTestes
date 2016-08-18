#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void Create_Instance(int NUM_VERTICES){	
srand48(time(NULL));	
	double x, y, z, a, b;
	int i = 0, cont = 0;	
	cout << NUM_VERTICES << endl; 
	
	while(i < NUM_VERTICES){
		
		a = 0.4 + drand48()/10;
		b = 0.4 + drand48()/10;

		do{
			x = drand48();
			y = drand48();
			z = ((pow(x,2)/pow(a,2)) - (pow(y,2)/pow(b,2)));
		}while(z >= 0.5 || z <= -0.5 || x >= 0.5 || y >= 0.5);	
		
		x += 0.5;
		y += 0.5;
		z += 0.5;
		
		if(cont == 0){
			cout << x << " " 
				 << y << " "
				 << z << endl;
		}else if(cont == 1){			 
			cout << 1-x << " " 
				 << y  << " "
				 << z << endl;
		}else if(cont == 2){
			cout << x  << " " 
				 << 1-y  << " "
				 << z << endl;
			
		}else {
			cout << 1-x  << " " 
			     << 1-y  << " "
			     <<  z << endl;			
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
