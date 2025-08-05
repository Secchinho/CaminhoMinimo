all: compila

compila: main.o grafo.o
	gcc main.o grafo.o -o prog -Wall -Wextra -Wpedantic -Wconversion

grafo.o: grafo.c
	gcc -c grafo.c

main.o: main.c
	gcc -c main.c

rm:
	rm main.o grafo.o prog

del:
	del main.o grafo.o prog
