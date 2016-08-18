#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
//~ #define TAM 10
//~ using namespace std;

//~ int *vp = new int[TAM];
//~ vector<int> p;


//~ void imprime(int v[]){
	//~ 
	//~ for(int i = 0; i < TAM; ++i){
		//~ cout << v[i] << "  ";
	//~ }
	//~ cout << endl;
//~ }
//~ 
//~ void imprime(vector<int> &v){
	//~ 
	//~ for(int i = 0; i < TAM; ++i){
		//~ cout << v[i] << "  ";
	//~ }
	//~ cout << endl;
//~ }


template <typename points>
void BRIO(int bend, int tend, std :: vector<points> &p) {

	int *vp = new int[tend];
    int tam = tend - bend + 1;	// cout << "tam  : " << tam << endl;
    int log = (int)log2((double)tam);	//    cout << "log  : " << log << endl;
    bool is_inserted[tam];
    int cont = bend;

    for (int i = 0; i < tam; ++i) 
		is_inserted[i] = false;

	srand((unsigned)time(NULL) );
	
    for (int j = 0; j < log; ++j) {
        for (int i = bend; i <= tend; ++i) {
            if (rand() % 2 && !is_inserted[i - bend]) {
                vp[cont++] = i;
                is_inserted[i - bend] = true;	//cout << i << ' ';
            }
        } //cout << endl;
    }//cout << endl;
    
    //imprimeBoole(is_inserted);
    //imprime(vp);
    
    for (int i = bend; i <= tend; ++i) {
        if(!is_inserted[i - bend]){
            vp[cont++] = i;	//cout << i << ' ';
        }
    }//cout << endl;
    
    points aux;
    for(int i = 0; i < tend; i++){
		aux = p[i];
		p[i] = p[vp[i]];
		p[vp[i]] = aux; 
	}
    
}

//~ int main(){
	//~ 
	//~ p.reserve(TAM);
	//~ for(int i = 0; i < TAM; i++){
		//~ ////~ vp[i] = i;
		//~ p[i] = i;
	//~ }
	//~ ////~ imprime(vp);
	//~ ////~ cout << endl;
	//~ imprime(p);
	//~ cout << endl;
	//~ 
	//~ BRIO(0,TAM-1, p);	
	//~ ////~ imprime(vp);
	//~ cout << endl;
	//~ imprime(p);
	//~ 
//~ }
