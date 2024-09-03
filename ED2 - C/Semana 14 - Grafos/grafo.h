#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// METODOS DOS ITENS
typedef struct cidade {
    char nome[30];
    struct cidade *proximo;
} cidade;

typedef struct matrizDeAdjacenscia {
    int **matriz;
    cidade *raiz;
} matrizDeAdjacenscia;

cidade *criaCidade(char *nome) {
    cidade *novaCidade;
    if ((novaCidade = (cidade*)malloc(sizeof(cidade))) == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }    
    strcpy(novaCidade->nome, nome);
    novaCidade->proximo = NULL;
    return novaCidade;
}

int addCidade(cidade *raiz, char *nome) {
    while (raiz->proximo != NULL) {
        raiz = raiz->proximo;
    }
    raiz->proximo = criaCidade(nome);
    return 0;
}

cidade *acessar(cidade *raiz, int index) {
    if (index == 0 || raiz == NULL) {
        return raiz;
    }
    return acessar(raiz->proximo, index-1);
}

int tamanho(cidade *raiz) {
    int i = 0;
    while (raiz != NULL) {
        raiz = raiz->proximo;
        i++;
    }
    return i;
}


// METODOS DA MATRIZ
matrizDeAdjacenscia *constroiMatriz(cidade *raiz) {
    matrizDeAdjacenscia *novaMatriz;

    // Alocação dinámica
    if((novaMatriz = (matrizDeAdjacenscia*)malloc(sizeof(matrizDeAdjacenscia))) == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    
    // Definição da raiz
    novaMatriz->raiz = raiz;

    // Criação da matriz em si
    int tamanhoGrafo = tamanho(raiz);
    novaMatriz->matriz = (int**)malloc(sizeof(int) * tamanhoGrafo);
    if (novaMatriz->matriz == NULL) {
        printf("Erro de alocacao\n");
        exit(1);
    }
    
    // Loop das linhas
    for(int linha = 0; linha < tamanhoGrafo; linha++) {
        novaMatriz->matriz[linha] = (int*)malloc(sizeof(int) * tamanhoGrafo);
        if(novaMatriz->matriz[linha] == NULL) {
            printf("Erro de alocacao\n");
            exit(1);
        }
        for(int coluna = 0; coluna < tamanhoGrafo; coluna++) {
            novaMatriz->matriz[linha][coluna] = 0;
        }
    }

    return novaMatriz;
}

void printMatriz(matrizDeAdjacenscia *matriz) {
    int tamanhoMatriz = tamanho(matriz->raiz);

    // Cabeçalho
    printf("                    ");
    for(int i = 0; i < tamanhoMatriz; i++) {
        printf("%-20s", acessar(matriz->raiz, i)->nome);
    }  
    printf("\n");

    //Linhas
    for(int linha = 0; linha < tamanho(matriz->raiz); linha++) {
        printf("%-20s", acessar(matriz->raiz, linha)->nome);
        for (int coluna = 0; coluna < tamanho(matriz->raiz); coluna++) {
            printf("%-20d", matriz->matriz[linha][coluna]);
        }
        printf("\n");
    }
}

void definirDistancia(int distancia, int cidade1, int cidade2, matrizDeAdjacenscia *matriz) {
    matriz->matriz[cidade1][cidade2] = distancia;
    matriz->matriz[cidade2][cidade1] = distancia;
}



void buscaMenorCaminho(int **matriz, int inicio, int destino, int visitados[], int numVertices, int distanciaAtual, int *menorDistancia, int caminhoAtual[], int melhorCaminho[], int nivel) {
    visitados[inicio] = 1;
    caminhoAtual[nivel] = inicio;
    nivel++;

    if (inicio == destino) {
        if (distanciaAtual < *menorDistancia || *menorDistancia == -1) {
            *menorDistancia = distanciaAtual;
            for (int i = 0; i < nivel; i++) {
                melhorCaminho[i] = caminhoAtual[i];
            }
            melhorCaminho[nivel] = -1; // Marcar o fim do caminho
        }
    } else {
        for (int i = 0; i < numVertices; i++) {
            if (matriz[inicio][i] > 0 && !visitados[i]) {
                buscaMenorCaminho(matriz, i, destino, visitados, numVertices, distanciaAtual + matriz[inicio][i], menorDistancia, caminhoAtual, melhorCaminho, nivel);
            }
        }
    }

    visitados[inicio] = 0;
    nivel--;
}


void menorCaminho(int inicio, int destino, matrizDeAdjacenscia *matriz) {
    int TAMANHO = tamanho(matriz->raiz);
    int visitados[TAMANHO] = {0};
    int caminhoAtual[TAMANHO];
    int melhorCaminho[TAMANHO];
    int menorDistancia = -1;

    buscaMenorCaminho(matriz->matriz, inicio, destino, visitados, TAMANHO, 0, &menorDistancia, caminhoAtual, melhorCaminho, 0);

    printf("Melhor Caminho: ");
    for (int i = 0; melhorCaminho[i] != -1; i++) {
        printf("%s -> ", acessar(matriz->raiz, melhorCaminho[i])->nome);
    }
}