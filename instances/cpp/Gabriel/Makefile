#all: aleatorio cilindro cela disco eixos espiral paraboloide planos
#	make clean

all: aleatorio cilindro cela disco eixos paraboloide planos
	make clean

aleatorio:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	aleatorio.cpp
	g++ aleatorio.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o aleatorio
	
	
cilindro:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	cilindro.cpp 
	g++ cilindro.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o cilindro

cela:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	cela.cpp 
	g++ cela.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o cela
	
	
disco:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	disco.cpp 
	g++ disco.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o disco
	
	
eixos:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	eixos.cpp 
	g++ eixos.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o eixos
	
	
espiral:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	espiral.cpp 
	g++ espiral.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o espiral
	
	
paraboloide:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	paraboloide.cpp
	g++ paraboloide.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o paraboloide
	
	
planos:	Ponto/Ponto.o	DispersionTable/DispersionTable.o	planos.cpp 
	g++ planos.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o planos
	
	
aleatorio.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	aleatorio.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	aleatorio.cpp
	
cilindro.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	cilindro.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	cilindro.cpp
	
cela.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	cela.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	cela.cpp
	
	
disco.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	disco.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	disco.cpp
	
	
eixos.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	eixos.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	eixos.cpp
	
	
#espiral.o: Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	espiral.cpp
#	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	espiral.cpp
	
	
paraboloide.o:	Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	paraboloide.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	paraboloide.cpp
	
	
planos.o:	Ponto/Ponto.hpp	DispersionTable/DispersionTable.hpp	planos.cpp
	g++	-c	Ponto/Ponto.o	DispersionTable/DispersionTable.o	planos.cpp
	
	
Ponto.o:	Ponto/Ponto.cpp	Ponto/Ponto.hpp
	g++ -c Ponto/Ponto.cpp
	
DispersionTable.o:	DispersionTable/DispersionTable.cpp	DispersionTable/DispersionTable.hpp
	g++	-c	DispersionTable/DispersionTable.cpp	
	
clean:
	rm	-rf	*.o
	rm	-rf	Ponto/*.o
	rm	-rf	DispersionTable/*.o
mrproper:	clean
	rm	-rf	aleatorio cilindro disco eixos espiral paraboloide planos cela
