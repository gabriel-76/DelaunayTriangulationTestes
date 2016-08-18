#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>       /* ceil */
#include <GL/glut.h>
#include <fstream>

int mesh_leng = 4096;

struct XYZ{
  double x, y, z;
};

int nmbPts = 2500;


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
	glRotatef(400.0f, 400.0f, 50.0f, 0.0f);
	
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
    int xc = mesh_leng/2;
	int yc = mesh_leng/2;
	int i=0;
	while (i<nmbPts){
		double xp = rand()%1000000/(1000000*1.0);
		double yp = rand()%1000000/(1000000*1.0);
		
		if((sqrt((((xp*mesh_leng)-xc)*((xp*mesh_leng)-xc))+(((yp*mesh_leng)-yc)*((yp*mesh_leng)-yc))))<=mesh_leng/2){
			bool previouslyInserted = false;
			for(int k=0; k<i; k++){
				if(coordinates[k].x==xp && coordinates[k].y ==yp){
					previouslyInserted = true;
					break;
				}
			}
			if(!previouslyInserted){
				coordinates[i].x = xp;
				coordinates[i].y = yp;
				double z = rand()%1000000/(1000000*1.0);
				coordinates[i].z = z;
				i++;
			}
		} 
	}
	
	ofstream fout("circuloComZ750000.txt"); 
	fout << nmbPts; // Grava o caracter no arquivo
	fout<<"\n";
	for(int i =0; i<nmbPts; i++){
		if(coordinates[i].x>=1 || coordinates[i].x<0 || coordinates[i].y>=1 || coordinates[i].y<0 || coordinates[i].z>=1 || coordinates[i].z<0)
			cout<<"erro!"<<endl;
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
    glutInitWindowSize(600, 600); //Set the window size
    
    //Create the window
    glutCreateWindow("Entrada em circulo com coordenada z");
    initRendering(); //Initialize rendering
    //Set handler functions for drawing, keypresses, and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
    return 0; //This line is never reached
}
