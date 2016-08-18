#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>       /* ceil */
#include <GL/glut.h>
#include <fstream>

int mesh_len = 4*4096;

struct coordinate {
    double xC, yC, zC;    
};


int *vetCoordenadas = new int[mesh_len*mesh_len];

int temp = 0, nroPts = 10;
coordinate *tempCoord = new coordinate[nroPts];

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	ofstream fout("entEspiral25000.txt"); // Abre arquivo para gravação em modo texto
	int xc = (mesh_len/2);
	int yc = (mesh_len/2);
	for (int i=0; i<mesh_len; i++){
		for (int j=0; j<mesh_len; j++){
			vetCoordenadas[j*mesh_len+i] = 0;			
		}
	}
	
	for (int i=0; i<mesh_len; i++){
		for (int j=0; j<mesh_len; j++){
			int k = 256;
			while(k<mesh_len/2){
				if(((((sqrt(((i-xc)*(i-xc))+((j-yc)*(j-yc))))>=k))&&(((sqrt(((i-xc)*(i-xc))+((j-yc)*(j-yc))))<=k+128)))&&(j<(mesh_len/2))){
					vetCoordenadas[j*mesh_len+i] = 1;
					temp++;
				}
				k += 256;
				if(k<mesh_len/2){
					if((j>=(mesh_len/2))&&((((sqrt(((i-xc)*(i-xc))+((j-yc)*(j-yc))))>=k))&&(((sqrt(((i-xc)*(i-xc))+((j-yc)*(j-yc))))<=k+128)))){
						vetCoordenadas[(j*mesh_len)+i-256] = 1;
						temp++;
					}
					k += 256;
				} else {
					break;
				}
				
			}
		}
	}
	
	
	int x, y; double z;
	int cont=0;
	
	while(cont<nroPts){
		x = rand()%mesh_len;
		y = rand()%mesh_len;
		if(vetCoordenadas[(y*mesh_len+x)] == 1){
			tempCoord[cont].xC = (double)x/(double)mesh_len;
			tempCoord[cont].yC = (double)y/(double)mesh_len;
			
			z = 1-(2*((sqrt(((tempCoord[cont].xC-0.5)*(tempCoord[cont].xC-0.5))+((tempCoord[cont].yC-0.5)*(tempCoord[cont].yC-0.5))))));
			
			tempCoord[cont].xC += (rand()%10000/(10000*1.0))*0.02;
			tempCoord[cont].yC += (rand()%10000/(10000*1.0))*0.02;
			tempCoord[cont].zC = z+(rand()%10000/(10000*1.0))*0.02;
			cont++;
			vetCoordenadas[(y*mesh_len+x)] = 2;
		}
	}
	
	int tempI;
	double maxZP = 0;
	float tempF;
	for(int i=0; i<nroPts	; i++){
		tempI = tempCoord[i].xC*100000;
		tempF = (double)tempI/(double)100000;
		tempCoord[i].xC = tempF;
		
		tempI = tempCoord[i].yC*100000;
		tempF = (double)tempI/(double)100000;
		tempCoord[i].yC = tempF;
		
		tempI = tempCoord[i].zC*100000;
		tempF = (double)tempI/(double)100000;
		tempCoord[i].zC = tempF;
		
		if(tempCoord[i].xC>=1)
			tempCoord[i].xC = 0.99;
		if(tempCoord[i].yC>=1)
			tempCoord[i].yC = 0.99;
		if(tempCoord[i].zC>=1)
			tempCoord[i].zC = 0.99;
		if(maxZP<tempCoord[i].zC){
			maxZP = tempCoord[i].zC;
		}
		if(tempCoord[i].xC<0 || tempCoord[i].xC>=1 || tempCoord[i].yC<0 || tempCoord[i].yC>=1 || tempCoord[i].zC<0 || tempCoord[i].zC>=1){
			cout<<"Erro!"<<endl;
			cout<<"tempCoord[i].zC: "<<tempCoord[i].zC<<endl;
		}
	}
	
	cout<<"Max zp: "<<maxZP<<endl; 
	fout << nroPts; // Grava o caracter no arquivo
	fout<<"\n";
	for(int i=0; i<nroPts; i++){
		//cout<<tempCoord[i].xC<<" - "<<tempCoord[i].yC<<endl;
		fout << tempCoord[i].xC; // Grava o caracter no arquivo
		fout<<" ";
		fout << tempCoord[i].yC; // Grava o caracter no arquivo
		fout<<" ";
		fout << tempCoord[i].zC; // Grava o caracter no arquivo
		fout<<"\n";
		//cout<<tempCoord[i].zC<<endl;
	}
	fout.close();
	return 0;
}
