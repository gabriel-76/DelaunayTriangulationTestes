#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>       /* ceil */
#include <GL/glut.h>
#include <fstream>

struct XYZ{
  double x, y, z;
};

int nmbPts = 25000;

XYZ *coordinates = new XYZ[nmbPts];


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
    glViewport(0, 0, w/1.5, h/1.5);
    
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
	glRotatef(15.0f, 15.0f, 10.0f, 0.0f);
	
	glColor3f(0,0,0);
    for(int i=0; i<nmbPts; i++){
		glBegin(GL_POINTS); //Begin structure coordinates
		glVertex3f((double)coordinates[i].x/(double)1.25, (double)coordinates[i].y/(double)1.25, (double)coordinates[i].z/(double)1.25);
		glEnd(); //End structure coordinates
	}
    
        
    glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
    //Initialize GLUT
    srand(time(NULL));
    int valueX = ceil((nmbPts-3)/3);
    int valueY = ceil((nmbPts-3)/3);
    
    double x, y, z; 
    for(int i=0; i<valueX; i++){
		z = 1; x=1;
		while(z>0.03){
			z = rand()%1000000/(1000000*1.0);
		}
		while(x>0.03){
			x = rand()%1000000/(1000000*1.0);
		}
		y = rand()%1000000/(1000000*1.0);
		bool previouslyInserted = false;
		for(int k=0; k<i; k++){
			if(coordinates[k].x==x && coordinates[k].y==y && coordinates[k].z==z){
				previouslyInserted = true;
				i--;
				break;
			}
		}
		if(!previouslyInserted){
			coordinates[i].x = x;
			coordinates[i].y = y;
			coordinates[i].z = z;
		}
	}
	
	for(int i=valueX; i<valueY+valueX; i++){
		y = 1; x = 1;
		while(y>0.03){
			y = rand()%1000000/(1000000*1.0);
		}
		while(x>0.03){
			x = rand()%1000000/(1000000*1.0);
		}
		z = rand()%1000000/(1000000*1.0);
		bool previouslyInserted = false;
		for(int k=valueX; k<i; k++){
			if(coordinates[k].x==x && coordinates[k].y==y && coordinates[k].z==z){
				previouslyInserted = true;
				i--;
				break;
			}
		}
		if(!previouslyInserted){
			coordinates[i].x = x;
			coordinates[i].y = y;
			coordinates[i].z = z;
			if(coordinates[i].x>=1 || coordinates[i].x<0 || coordinates[i].y>=1 || coordinates[i].y<0 || coordinates[i].z>=1 || coordinates[i].z<0)
				cout<<"erro!"<<endl;
		}
	}
	
	for(int i=valueY+valueX; i<nmbPts; i++){
		y = 1; z=1;
		while(y>0.03){
			y = rand()%100000000/(100000000*1.0);
		}
		while(z>0.03){
			z = rand()%100000000/(100000000*1.0);
		}
		x = rand()%1000000/(1000000*1.0);
		bool previouslyInserted = false;
		for(int k=valueY+valueX; k<i; k++){
			if(coordinates[k].x==x && coordinates[k].z==z && coordinates[k].y==y){
				previouslyInserted = true;
				i--;
				break;
			}
		}
		if(!previouslyInserted){
			coordinates[i].x = x;
			coordinates[i].y = y;
			coordinates[i].z = z;
		}
	}
	
	ofstream fout("eixos50000.txt"); 
	fout << nmbPts; // Grava o caracter no arquivo
	fout<<"\n";
	for(int i =0; i<nmbPts; i++){
		fout << coordinates[i].x; // Grava o caracter no arquivo
		fout<<" ";
		fout << coordinates[i].y; // Grava o caracter no arquivo
		fout<<" ";
		fout << coordinates[i].z; // Grava o caracter no arquivo
		fout<<"\n";
	}
	fout.close();
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 720); //Set the window size
    
    //Create the window
    glutCreateWindow("Entrada em torno dos eixos");
    initRendering(); //Initialize rendering
    //Set handler functions for drawing, keypresses, and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
    return 0; //This line is never reached
}
