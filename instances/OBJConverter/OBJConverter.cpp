//-----------------I/O INCLUDES ----------------------------------------
#include <iostream>
#include <cstdlib>
#include <fstream>

//----------------BUILD INCLUDES ---------------------------------------
#include <vector>
#include <cstring>

typedef struct {
    double x, y, z;
} Point_3;

using namespace std;


vector<Point_3> P;
string sout;
int cont = 0;

void Read_File_obj(){	
	size_t extencion = sout.find("obj");
    sout.replace(extencion, 3, "txt");
    ofstream out(sout.c_str());
    out << cont;
    out << "\n";
    for (int j = 0; j < cont; j++) {
		out << P[j].x;
		out << " ";
		out << P[j].y;
        out << " ";
        out << P[j].z;
        out << " ";
        out << "\n";
	}
	out.close();
}

void Create_Instance(int argc, char **argv){
	ifstream arq;
    for (int i = 1; i != argc; ++i) {
		sout = argv[i];
		arq.open(sout.c_str());
        string s;
        Point_3 Paux;
        while (!arq.eof()) {
			arq >> s;
			if (s == "v") {
				arq >> Paux.x;
                arq >> Paux.y;
                arq >> Paux.z;
                P.push_back(Paux);
                cont++;
                    //cout << x << ' ' << y << ' ' << z << endl;
            }
                //cout << s << endl;
        }
        arq.close();
        
        Read_File_obj();
        P.clear();
	}
}



void verify_args(int argc){
	if (argc < 2) {
        cout << "Enter from arquive to XXXX.obj to parmeter please" << endl;
        exit(1);
    }
}

int main(int argc, char **argv) {	
	verify_args(argc);
	Create_Instance(argc, argv);
	return EXIT_SUCCESS;
}
