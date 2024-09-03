#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7

typedef struct cidade {
    char nome[30];
} cidade;

cidade *criaCidade(char nome[]) {
    cidade *novaCidade = (cidade*)malloc(sizeof(cidade));
    if(!novaCidade) {
        printf("Erro: falha na alocacao de memoria!");
        exit(1);
    }
    strcpy(novaCidade->nome, nome); 
    return novaCidade; 
}

void buscaMenorCaminho(int grafo[MAX][MAX], int inicio, int destino, int visitados[], int numVertices, cidade cidades[], int distanciaAtual, int *menorDistancia, int caminhoAtual[], int melhorCaminho[], int nivel) {
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
            if (grafo[inicio][i] > 0 && !visitados[i]) {
                buscaMenorCaminho(grafo, i, destino, visitados, numVertices, cidades, distanciaAtual + grafo[inicio][i], menorDistancia, caminhoAtual, melhorCaminho, nivel);
            }
        }
    }

    visitados[inicio] = 0;
    nivel--;
}

int main() {
    int visitados[MAX] = {0};
    int caminhoAtual[MAX];
    int melhorCaminho[MAX];
    int menorDistancia = -1;
    int inicio, destino;

    // Criação de cidades
    cidade cidades[MAX];
    cidades[0] = *criaCidade("Porto Alegre");
    cidades[1] = *criaCidade("Sao Paulo");
    cidades[2] = *criaCidade("Rio de Janeiro");
    cidades[3] = *criaCidade("VitOria");
    cidades[4] = *criaCidade("Recife");
    cidades[5] = *criaCidade("Salvador");
    cidades[6] = *criaCidade("Natal");

    int matrizCidades[MAX][MAX] = {
            // POA, SP, RJ, VIT, REC, SAL, NAT
    /* POA */  {0, 1100, 1700, 0, 0, 0, 0},
    /* SP  */  {1100, 0, 0, 0, 2300, 1500, 0},
    /* RJ  */  {1700, 0, 0, 300, 0, 0, 2700},
    /* VIT */  {0, 0, 300, 0, 800, 0, 0},
    /* REC */  {0, 2300, 0, 800, 0, 0, 650},
    /* SAL */  {0, 1500, 0, 0, 0, 0, 1900},
    /* NAT */  {0, 0, 2700, 0, 650, 1900, 0}
    };


    inicio = 0;
    destino = 6;
    printf("Algoritmo DFS para encontrar o menor caminho\n");
    printf("Iniciando pelo Vertice...: %s\n", cidades[0].nome);
    printf("Destino Final...: %s\n", cidades[6].nome);
    buscaMenorCaminho(matrizCidades, inicio, destino, visitados, MAX, cidades, 0, &menorDistancia, caminhoAtual, melhorCaminho, 0);

    printf("Menor Distancia: %d\n", menorDistancia);
    printf("Melhor Caminho: ");
    for (int i = 0; melhorCaminho[i] != -1; i++) {
        printf("%s -> ", cidades[melhorCaminho[i]].nome);
    }
    printf("\n");

    return 0;
}