all: main test_arista test_bosque
FLAGS = -O2

main: arista.o bosque.o Comparador.o main.cpp
	g++ ${FLAGS} arista.o bosque.o Comparador.o main.cpp -o main

arista.o: arista.cpp arista.h
	g++ ${FLAGS} -c arista.cpp

bosque.o: bosque.cpp bosque.h
	g++ ${FLAGS} -c  bosque.cpp

Comparador.o: Comparador.cpp Comparador.h
	g++ ${FLAGS} -c Comparador.cpp

test_arista: test_arista.cpp arista.o
	g++  ${FLAGS} arista.o test_arista.cpp -o test_arista

test_bosque: test_bosque.cpp bosque.o Comparador.o arista.o
	g++  ${FLAGS} bosque.o arista.o Comparador.o test_bosque.cpp -o test_bosque
 
clean:
	rm -rf *.o main