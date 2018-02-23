all: main 

Serpiente: Serpiente.cpp Serpiente.h
	g++ -c Serpiente.cpp

main: main.cpp Serpiente.h
	g++  main.cpp Serpiente.cpp -lncurses
	
