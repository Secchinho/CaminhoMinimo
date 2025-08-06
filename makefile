all: compila

compila: main.o algoritmo.o
	gcc -Wall -Wextra main.o algoritmo.o -o prog

main.o: main.c
	gcc -c main.c

algoritmo.o: algoritmo.c
	gcc -c algoritmo.c

rm:
	rm main.o algoritmo.o prog

del:
	del main.o algoritmo.o prog
