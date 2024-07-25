#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int vec[], int left, int right) {
    int i = left;
    for (int j = left + 1; j <= right; ++j) {
        if (vec[j] < vec[left]) {
            ++i;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[left], &vec[i]);
    return i;
}

void quickSort(int vec[], int left, int right) {
    if (right > left) {
        int r = partition(vec, left, right);
        quickSort(vec, left, r - 1);
        quickSort(vec, r + 1, right);
    }
}

int main() {
    // Lendo arquivo
    int* vetor;
    int capacidade = 1000, tamanho = 0;
    FILE *fonte, *saida;

    // Ler arquivo
    if ((fonte = fopen("Arquivo.txt", "r")) == NULL) {
        printf("Erro na abertura de arquivo");
        exit(1);
    } else {
        printf("Leitura aberta!\n");
        vetor = (int*)malloc(capacidade * sizeof(int));
        while (fscanf(fonte, "%d", &vetor[tamanho]) != EOF) {
            tamanho++;
            if (tamanho == capacidade) {
                capacidade += 1000;
                int* vecAux = (int*)realloc(vetor, capacidade * sizeof(int));
                if (vecAux == NULL) {
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

    // Algoritmo de Ordenação
    quickSort(vetor, 0, tamanho - 1);

    // Escrever arquivo
    if ((saida = fopen("SaidaQuickSort.txt", "w")) == NULL) {
        printf("Erro na gravação");
        free(vetor);
        exit(1);
    } else {
        for (int j = 0; j < tamanho; j++) {
            fprintf(saida, "%d\n", vetor[j]);
        }
        fclose(saida);
        free(vetor);
    }

    return 0;
}