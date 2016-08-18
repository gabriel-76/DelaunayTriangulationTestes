#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void Create_Aleatorio(int NUM_VERTICES){	
	int i = 0;	
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		cout << drand48() << " "
			 << drand48() << " "
			 << drand48() << endl;
		i++;		
	}
}

void Create_Cilindro(int NUM_VERTICES){	
	double t, r;
	int i = 0;
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		r = drand48()/2;
		t = rand();
		
		cout << r*cos(t) + 0.5 << " " 
			 << r*sin(t) + 0.5 << " "
			 << drand48() << endl;
		i++;
	}
}


void Create_Disco(int NUM_VERTICES){	
	double t, r;
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

void Create_Eixos(int NUM_VERTICES){		
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

void Create_Paraboloide(int NUM_VERTICES){	
	double x, y, z, a, b;
	int i = 0, cont = 0;	
	cout << NUM_VERTICES << endl; 
	while(i < NUM_VERTICES){

		a = 0.4 + drand48()/10;
		b = 0.4 + drand48()/10;		
		do{
			x = drand48();
			y = drand48();
			z = ((pow(x,2)/pow(a,2)) + (pow(y,2)/pow(b,2)));
		}while(z > 1.0);	
			
		x += 0.5;
		y += 0.5;
		
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

void Create_Planos(int NUM_VERTICES){		
	const double large_axes = 30;
	int i = 0, cont = 0;
	
	cout << NUM_VERTICES << endl;
	while(i < NUM_VERTICES){
		
		if(cont == 0){
			cout << drand48()/large_axes << " "
				 << drand48() << " "
				 << drand48() << endl;
			
		}else if(cont == 1){
			cout << drand48() << " "
				 << drand48()/large_axes  << " "
				 << drand48() << endl;
			
		}else {
			
			cout << drand48() << " "
				 << drand48() << " "
				 << drand48()/large_axes << endl;
			
			cont = -1;
		}
		i++;
		cont++;
		
	}
}

void Create_Sela(int NUM_VERTICES){	
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

void menu(){
	cout << "Select "
}


int main(int argc, char** argv) {
	srand48(time(NULL));
	return 0;
}
