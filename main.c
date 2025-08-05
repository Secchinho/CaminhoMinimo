#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "algoritmo.h"
#define INF 9999999

int main(int argc, char *argv[])
{
    int numCidades = 0;
    int numEstradas = 0;
    int cidade1 = 0;
    int cidade2 = 0;
    int tamEstrada = 0;
    int origem = 0;
    int destino = 0;
    int qtdProibidas = 0;

    if(argc != 2)
    {
        printf("\nERRO!!!\n");
        exit(1);
    }

    FILE *arq = fopen(argv[1], "r");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    fscanf(arq, "%d", &numCidades);
    fscanf(arq, "%d", &numEstradas);

    int dist[numCidades];
    int pre[numCidades];
    int grafo[numCidades][numCidades];

    for(int i = 0; i < numCidades; i++)
    {
        for(int j = 0; j < numCidades; j++)
        {
            if(i == j)
            {
                grafo[i][j] = 0;
            }
            else
            {
                grafo[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < numEstradas; i++)
    {
        fscanf(arq, "%d", &cidade1);
        fscanf(arq, "%d", &cidade2);
        fscanf(arq, "%d", &tamEstrada);
        lerGrafo(numCidades, grafo, tamEstrada, cidade1, cidade2);
    }

    printf("Digite a cidade de origem de YL: ");
    scanf(" %d", &origem);
    printf("Digite a cidade de destino de YL: ");
    scanf(" %d", &destino);
    printf("Digite a quantidade de cidades proibidas para YL: ");
    scanf(" %d", &qtdProibidas);

    dijkstra(qtdProibidas, numCidades, grafo, origem - 1, dist, pre);

    int tamCaminho = dist[destino - 1];

    if(tamCaminho < INF)
    {
        printf("\nO menor caminho a ser percorrido é: %d \n", tamCaminho);
    }
    else
    {
        printf("\nNão é possível realizar essa viagem\n");
    }

    fclose(arq);
    return 0;
}