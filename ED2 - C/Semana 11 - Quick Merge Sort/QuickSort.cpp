#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

void swap(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;}
 
int partition(int vec[], int left, int right) {
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j) {
    if (vec[j] < vec[left]) {
      ++i;
      swap(&vec[i], &vec[j]);
    }
  }
  swap(&vec[left], &vec[i]);
   return i;}
 
void quickSort(int vec[], int left, int right) {
  int r;
   if (right > left) {
    r = partition(vec, left, right);
    quickSort(vec, left, r - 1);
    quickSort(vec, r + 1, right);  }
}

main ()
{

//Lendo arquivo
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

//Algoritmo de Ordena��o 
 quickSort(vetor,0,tamanho);

//Escrever arquivo
    if(((saida = fopen("SaidaQuickSort.txt", "w")) == NULL)) {
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

