main : compile

compile :	
	./compile.sh
#	g++ -o menu SourceCode/Menu/MenuPrincipal.cpp -lm

install-pre-requisites :
	./install-pre-requisites.sh

clean :
	./clean.sh
