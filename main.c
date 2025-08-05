#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numCidades = 0;
    int numEstradas = 0;
    int cidade1 = 0;
    int cidade2 = 0;
    int tamEstrada = 0;

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

    for(int i = 0; i < numEstradas; i++)
    {
        fscanf(arq, "%d", &cidade1);
        fscanf(arq, "%d", &cidade2);
        fscanf(arq, "%d", &tamEstrada);
    }
    printf("\n");

    fclose(arq);
    return 0;
}