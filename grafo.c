#include <stdio.h>
#include "grafo.h"

void lerGrafo(int numCidades, int matGrafo[numCidades][numCidades], int tamEstrada, int cidade1, int cidade2)
{
    matGrafo[cidade1 - 1][cidade2 - 1] = tamEstrada;
    matGrafo[cidade2 - 1][cidade1 - 1] = tamEstrada;
}