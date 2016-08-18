#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glut.h> 

#define WINDOWNS_SIZE_HEIGHT 1300 // haltura
#define WINDOWNS_SIZE_WIDTH 800 // largura
#define WINDOWNS_POSITION 0

using namespace std;

typedef struct{
	double x;
	double y;
	double z;
}Ponto;
vector<Ponto> vertices;

int size = 0;
bool is_rotate = true;

GLfloat horzangle = 0.0, vertangle = 0.0, dist = 0.0; 

void PauseRotate(void);
void Print_unity_cube(void);
//Draws the 3D scene
void drawScene(void) {
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	
	//~ gluPerspective(2.0,2.0,2.0,2.0);
	//~ gluLookAt(0,0,0, 10.0,10.0,10.0, 0,1,0);
	
	glTranslatef(0.0f,0.0f,dist); 
	glRotatef(vertangle,1.0f,0.0f,0.0f); 
	glRotatef(horzangle,0.0f,1.0f,0.0f); 
    //Clear information from last draw
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
	//glRotatef(30.0f, 30.0f, 10.0f, 0.0f);
	
	glColor3f(0,0,0);
	glBegin(GL_POINTS); //Begin structure coordinates
    for(int i=0; i<size; i++){		
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);		
	}
	glEnd(); //End structure coordinates
	
	Print_unity_cube();
    
    glutSwapBuffers(); //Send the 3D scene to the screen
}

void ReturnKey(void) { 
  dist += 0.5; 
  drawScene();
} 
  
void SpaceKey(void) { 
  dist -= 0.5; 
  drawScene(); 
} 

void LeftMouse(){	
	horzangle -= 20;
	drawScene();
}

void RightMouse(){	
	horzangle += 20;
	drawScene();
}
  
void LeftKey(void) { 
  horzangle -= 5; 
  drawScene(); 
} 
  
void RightKey(void) { 
  horzangle += 5; 
  drawScene(); 
} 
  
void UpKey(void) { 
  vertangle -= 5; 
  drawScene();
} 
  
void DownKey(void) { 
  vertangle += 5; 
  drawScene(); 
} 

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0); 
        break;
        
        case 127: ReturnKey();
        break;
        
        case 32: SpaceKey(); 
        break;
        
        case 'w':UpKey();
		break;

		case 'a':LeftKey();
		break;

		case 'd':RightKey();
		break;

		case 's':DownKey();
		break;
  }
  PauseRotate();
}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
}
void handleResize(int w, int h) {    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); 
    
    
    glLoadIdentity(); 
    gluPerspective(45.0,     //The camera angle
                   w/h, 	 //The width-to-height ratio
                   10.0,     //The near z clipping coordinate
                   10.0);    //The far z clipping coordinate
}

void read_points(char *name, int qtdMax){	
	ifstream file_in;	
	file_in.open(name);
	
	if(file_in == NULL){
		cout << "Filename not exist\n";
		exit(1);
	}
	
	file_in >> size;	
	
	if(size - qtdMax > 0) size -= qtdMax;
	cout << size << endl;
	
	vertices.reserve(size);
	int i = 0;
	while(i < size){
		file_in >> vertices[i].x;
		file_in >> vertices[i].y;
		file_in >> vertices[i++].z;		
	}
	file_in.close();
}

void verify_args(int argc, char** argv) {	
	if(argc < 2){ 
		cout << "Pass the filename and \"instance limit size (optional)\", in parameter\n";
		exit(0);
	}
	else if(argc >= 3){
		read_points(argv[1], atoi(argv[2]));
	}else{
		read_points(argv[1], 0);
	}	
}

void print_verrtices( vector<Ponto> &p, int tam){
	
	for(int i = 0; i < tam; i++){
		cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
	}
}


void Mouse(int button, int state, int x, int y){

	switch (button){
		case GLUT_LEFT_BUTTON: LeftMouse();
		break;
		
		case GLUT_RIGHT_BUTTON: RightMouse();
		break;
    }
    PauseRotate();
}

void Rotate(void){
	if (is_rotate) LeftKey();
}

void PauseRotate(void){
	is_rotate = false;
}

void Print_unity_cube(void){
	//~ double var = 0.0;	
	glColor3f(0.9,0,0);
	glBegin(GL_LINE_STRIP);
	
	glVertex3f(0,0,0);
	glVertex3f(1,0,0);
	glVertex3f(1,0,1);
	glVertex3f(0,0,1);
	
	glVertex3f(0,1,1);
	glVertex3f(0,1,0);
	glVertex3f(1,1,0);
	glVertex3f(1,0,0);
	
	glVertex3f(1,0,1);
	glVertex3f(1,1,1);
	glVertex3f(0,1,1);
	glVertex3f(1,1,1);
	glVertex3f(1,1,0);
	

	glEnd(); //End structure coordinates
	
	glBegin(GL_LINES);
	
		glVertex3f(0,0,0);
		glVertex3f(0,0,1);
		
		glVertex3f(0,0,0);
		glVertex3f(0,1,0);
	
	
	glEnd();
	
	
}

void MashView(int argc, char** argv){
	verify_args(argc, argv);
	
	//print_verrtices(vertices, size);
	
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA ); 
    glutInitWindowSize(WINDOWNS_SIZE_HEIGHT, WINDOWNS_SIZE_WIDTH);
    glutInitWindowPosition(WINDOWNS_POSITION,WINDOWNS_POSITION);
    
    //Create the window
    glutCreateWindow(argv[1]);
    initRendering(); 
        
    glutKeyboardFunc(handleKeypress);
	glutMouseFunc(Mouse);
   
    glutDisplayFunc(drawScene);
    
    glutReshapeFunc(handleResize);
    glutIdleFunc(Rotate);
    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
}

int main(int argc, char** argv) {
	MashView(argc,argv);
	return 0;
}
