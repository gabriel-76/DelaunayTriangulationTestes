#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>       /* ceil */
#include <GL/glut.h>
#include <fstream>

#include <cmath> // ou <math.h>
#include <iostream>
#include <cstdlib>

int mesh_len = 4*4096;

struct coordinate {
    double xC, yC, zC;    
};



int temp = 0, nroPts = 50000;
coordinate *tempCoord = new coordinate[nroPts];
using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
                    int x, int y) {    //The current mouse coordinates
    switch (key) {
        case 27: //Escape key
            exit(0); //Exit the program
    }
}

//Initializes 3D rendering
void initRendering() {
    //Makes 3D drawing work when something is in front of something else
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(10.0,                  //The camera angle
                   10, //The width-to-height ratio
                   10.0,                   //The near z clipping coordinate
                   10.0);                //The far z clipping coordinate
}

//Draws the 3D scene
void drawScene() {
    //Clear information from last draw
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
	glRotatef(800.0f, 800.0f, 0.0f, 0.0f);
	
	glColor3f(0,0,0);
    for(int i=0; i<nroPts; i++){
		glBegin(GL_POINTS); //Begin structure coordinates
		glVertex3f((double)tempCoord[i].xC/(double)1.25, (double)tempCoord[i].yC/(double)1.25, (double)tempCoord[i].zC/(double)1.25);
		glEnd(); //End structure coordinates
	}
    
        
    glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
	srand(time(NULL));
	ofstream fout("paraboloide50000.txt"); // Abre arquivo para gravação em modo texto
	
	int i = 0;
	
	double xc = mesh_len/2, yc = mesh_len/2, z;
	while(i<nroPts){
		double xp = rand()%100000/(100000*1.0);
		double yp = rand()%100000/(100000*1.0);
		z = 1-2*(pow(sin(((sqrt(((xp-0.5)*(xp-0.5))+((yp-0.5)*(yp-0.5)))))),2)/pow(cos(((sqrt(((xp-0.5)*(xp-0.5))+((yp-0.5)*(yp-0.5)))))),1));
		//z = z*cos(z);
		if((sqrt((((xp*mesh_len)-xc)*((xp*mesh_len)-xc))+(((yp*mesh_len)-yc)*((yp*mesh_len)-yc))))<=mesh_len/2){
			bool previouslyInserted = false;
			for(int k=0; k<i; k++){
				if(tempCoord[k].xC==xp && tempCoord[k].yC ==yp && z<1){
					previouslyInserted = true;
					break;
				}
				
			}
			if(!previouslyInserted){
				tempCoord[i].xC = xp+(rand()%10000/(10000*1.0))*0.01;
				if(tempCoord[i].xC>=1)
					tempCoord[i].xC = 0.9999;
				tempCoord[i].yC = yp+(rand()%10000/(10000*1.0))*0.01;
				if(tempCoord[i].yC>=1)
					tempCoord[i].yC = 0.9999;
				tempCoord[i].zC = z;
				//cout<<"i:"<<i<<endl;
				i++;
			}
		} 
	}
	
	
	int tempI;
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
		if(tempCoord[i].xC>=1 || tempCoord[i].xC<0 || tempCoord[i].yC>=1 || tempCoord[i].yC<0 || tempCoord[i].zC>=1 || tempCoord[i].zC<0)
			cout<<"erro!"<<endl;

		//if(tempCoord[i].zC<0.5)
		//	cout<<"aqui"<<endl;
	}
	
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

        glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600); //Set the window size
    
    //Create the window
    glutCreateWindow("Entrada em espiral");
    initRendering(); //Initialize rendering
    //Set handler functions for drawing, keypresses, and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0;
}
