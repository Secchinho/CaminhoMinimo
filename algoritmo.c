#include <stdio.h>
#include "algoritmo.h"
#define INF 9999999

void dijkstra(int qtdProibidas ,int numCidades, int matGrafo[numCidades][numCidades], int vetIni, int dist[], int pre[])
{
    int conj[numCidades];
    int cidProibidas[numCidades];
    
    for(int i = 0; i < numCidades; i++)
    {
        cidProibidas[i] = 0;
    }
    
    for(int i = numCidades; i > (numCidades - qtdProibidas); i--)
    {
        cidProibidas[i - 1] = 1;
    }


    for(int i = 0; i < numCidades; i++)
    {
        conj[i] = 0;
    }

    dist[vetIni] = 0;
    pre[vetIni] = -1;
    conj[vetIni] = -1;

    for(int i = 0; i < numCidades; i++)
    {
        if(i != vetIni)
        {
            dist[i] = INF;
        }
    }

    for(int i = 0; i < numCidades; i++)
    {
        if(matGrafo[vetIni][i] < INF)
        {
            dist[i] = matGrafo[vetIni][i];
            pre[i] = vetIni;
        }
    }

    int op = 1;

    while(op)
    {
        op = 0;
        int menor = INF;
        int menorIndex = 0;

        for(int i = 0; i < numCidades; i++)
        {
            if(dist[i] < menor && conj[i] != -1)
            {
                op = 1;
                menor = dist[i];
                menorIndex = i;
            }
        }

        conj[menorIndex] = -1;

        if(cidProibidas[menorIndex])
        {
            continue;
        }

        for(int i = 0; i < numCidades; i++)
        {
            if(matGrafo[menorIndex][i] < INF)
            {
                if(conj[i] != -1)
                {
                    if(dist[i] > (dist[menorIndex] + matGrafo[menorIndex][i]))
                    {
                        dist[i] = (dist[menorIndex] + matGrafo[menorIndex][i]);
                        pre[i] = menorIndex;
                    }
                }
            }
        }
    }

}
