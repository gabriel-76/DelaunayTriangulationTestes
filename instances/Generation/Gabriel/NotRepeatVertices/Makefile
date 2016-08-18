#all: aleatorio cilindro sela disco eixos espiral paraboloide planos
#	make clean

all: aleatorio cilindro sela disco eixos espiral paraboloide planos
	make clean

aleatorio:	aleatorio.o	aleatorio.cpp
	g++ aleatorio.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o aleatorio
	
	
cilindro:	cilindro.o	cilindro.cpp 
	g++ cilindro.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o cilindro

sela:	sela.o	sela.cpp 
	g++ sela.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o sela
	
	
disco:	disco.o disco.cpp 
	g++ disco.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o disco
	
	
eixos:	eixos.o	eixos.cpp 
	g++ eixos.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o eixos
	
	
espiral:    espiral.o	espiral.cpp 
	g++ espiral.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o espiral
	
	
paraboloide:	paraboloide.o	paraboloide.cpp
	g++ paraboloide.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o paraboloide
	
	
planos:	planos.o	planos.cpp 
	g++ planos.cpp	Ponto/Ponto.o	DispersionTable/DispersionTable.o	-o planos
	
	
aleatorio.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	aleatorio.cpp
	g++	-c	aleatorio.cpp
	
cilindro.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	cilindro.cpp
	g++	-c	cilindro.cpp
	
sela.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	sela.cpp
	g++	-c	sela.cpp
	
	
disco.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	disco.cpp
	g++	-c	disco.cpp
	
	
eixos.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	eixos.cpp
	g++	-c	eixos.cpp
	
	
espiral.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	espiral.cpp
	g++	-c	espiral.cpp
	
	
paraboloide.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	paraboloide.cpp
	g++	-c	paraboloide.cpp
	
	
planos.o:   Ponto/Ponto.o	DispersionTable/DispersionTable.o	planos.cpp
	g++	-c	planos.cpp
	
	
Ponto.o:	Ponto/Ponto.cpp	Ponto/Ponto.hpp
	g++ -c Ponto/Ponto.cpp
	
DispersionTable.o:	DispersionTable/DispersionTable.cpp	DispersionTable/DispersionTable.hpp
	g++	-c	DispersionTable/DispersionTable.cpp	
	
clean:
	rm	-rf	*.o
	rm	-rf	Ponto/*.o
	rm	-rf	DispersionTable/*.o
mrproper:	clean
	rm	-rf	aleatorio cilindro disco eixos espiral paraboloide planos sela
