#include <stdio.h>
#include <stdlib.h>

void mergeSort(int vec[], int vecSize);

void merge(int vec[], int vecSize);

main()
{
    int* vetor;
    int capacidade = 1000, tamanho = 0;
    FILE *fonte, *saida;

    //Ler arquivo
    if((fonte = fopen("Arquivo.txt", "r")) == NULL) {
 	    printf("Erro na abertura de arquivo");
        exit(1);
    } else {
		printf("Leitura aberta!\n");
        vetor = (int*)malloc(capacidade * sizeof(int));
		while(!feof(fonte)) {
            fscanf(fonte, "%d", &vetor[tamanho]);
            tamanho++;
            if(tamanho == capacidade) {
                capacidade += 1000;
                int* vecAux = (int*)realloc(vetor, capacidade * sizeof(int));
                if(vecAux == NULL) {
                    printf("Erro ao realocar memória\n");
                    free(vetor);
                    fclose(fonte);
                    exit(1);
                }
                vetor = vecAux;
            }
		}
		fclose(fonte);
		printf("Leitura fechada!\n");
    }

    //Algoritmo de ordenacao
    mergeSort(vetor, tamanho);

    //Escrever arquivo
    if(((saida = fopen("SaidaMergeSort.txt", "w")) == NULL)) {
        printf("Erro na gravacao");
        free(vetor);
        exit(1);
    } else {
        for (int j = 0; j < tamanho - 1; j++) {
            fprintf(saida, "%d\n", vetor[j]);
        }
        fclose(saida);
        free(saida);
        free(vetor);
    }
}

void mergeSort(int vec[], int vecSize) {
    int mid;
    if (vecSize > 1)
    {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
}

//Kernell do Algoritmo
void merge(int vec[], int vecSize)
{
    int mid;
    int i, j, k;
    int *tmp;
    tmp = (int *)malloc(vecSize * sizeof(int));
    if (tmp == NULL)
    {
        exit(1);
    }
    mid = vecSize / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize)
    {
        if (vec[i] < vec[j])
        {
            tmp[k] = vec[i];
            ++i;
        }
        else
        {
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    if (i == mid)
    {
        while (j < vecSize)
        {
            tmp[k] = vec[j];
            ++j;
            ++k;
        }
    }
    else
    {
        while (i < mid)
        {
            tmp[k] = vec[i];
            ++i;
            ++k;
        }
    }
    for (i = 0; i < vecSize; ++i)
    {
        vec[i] = tmp[i];
    }
    free(tmp);
}
