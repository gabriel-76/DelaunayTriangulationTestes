#all: aleatorio cilindro sela disco eixos espiral paraboloide planos
#	make clean

compile : 
	g++ instances.cpp - o intancesGenerate

all: aleatorio cilindro sela disco eixos espiral paraboloide planos
	make clean

aleatorio:	aleatorio.cpp
	g++ aleatorio.cpp	-o aleatorio
	
	
cilindro:	cilindro.cpp 
	g++ cilindro.cpp	-o cilindro

sela:	sela.cpp 
	g++ sela.cpp	-o sela
	
	
disco:	disco.cpp 
	g++ disco.cpp	-o disco
	
	
eixos:	eixos.cpp 
	g++ eixos.cpp	-o eixos
	
	
espiral:	espiral.cpp 
	g++ espiral.cpp	-o espiral
	
	
paraboloide:	paraboloide.o	paraboloide.cpp
	g++ paraboloide.cpp	-o paraboloide
	
	
planos:	planos.cpp 
	g++ planos.cpp	-o planos
	
clean:
	rm	-rf	*.o
mrproper:	clean
	rm	-rf	intancesGenerate
