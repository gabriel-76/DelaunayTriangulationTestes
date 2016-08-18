#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>       /* ceil */
#include <GL/glut.h>
#include <fstream>

//g++ -Wall -c "aleatorio.cpp" -lmpfr -lgmp -lGL -lGLU -lglut

int mesh_len = 4*4096;

struct coordinate {
    double xC, yC, zC;    
};


int *vetCoordenadas = new int[mesh_len*mesh_len];

int temp = 0, nroPts = 1000;
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
	glRotatef(30.0f, 30.0f, 10.0f, 0.0f);
	
	glColor3f(0,0,0);
    for(int i=0; i<nroPts; i++){
		glBegin(GL_POINTS); //Begin structure coordinates
		glVertex3f((double)tempCoord[i].xC/(double)2, (double)tempCoord[i].yC/(double)2, (double)tempCoord[i].zC/(double)2);
		glEnd(); //End structure coordinates
	}
    
        
    glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {

	
	double x, y,  z;
	int cont=0;
	
	while(cont<nroPts){
		x = rand()%1000000/(1000000*1.0);
		y = rand()%1000000/(1000000*1.0);
		z = rand()%1000000/(1000000*1.0);

		tempCoord[cont].xC = x;
		tempCoord[cont].yC = y;
		tempCoord[cont].zC = z;
				cont++;
		
	}
	ofstream fout("aleat1000000.txt"); 
	
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
	cout<<"Cont: "<<temp<<endl;
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
