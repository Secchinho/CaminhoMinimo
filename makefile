all: compila

compila: main.o grafo.o algoritmo.o
	gcc -Wall -Wextra main.o grafo.o algoritmo.o -o prog

grafo.o: grafo.c
	gcc -c grafo.c

main.o: main.c
	gcc -c main.c

algoritmo.o: algoritmo.c
	gcc -c algoritmo.c

rm:
	rm main.o grafo.o algoritmo.o prog

del:
	del main.o grafo.o algoritmo.o prog
