#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main() {
    vertice *raiz;
    char msg[30] = "testanmto";

    // Testando a criação de um grafo
    raiz = criaRaiz(msg);
    strcpy(msg, "teste1");
    adicionarVertice(raiz, msg);
    strcpy(msg, "teste2");
    adicionarVertice(raiz, msg);
    strcpy(msg, "teste3");
    adicionarVertice(raiz, msg);
    strcpy(msg, "teste4");
    adicionarVertice(raiz, msg);
    strcpy(msg, "teste5");
    adicionarVertice(raiz, msg);
    strcpy(msg, "teste6");
    adicionarVertice(raiz, msg);

    // Testando a criação de uma matriz de adjacência
    matrizDeAdjacenscia *matriz = criarMatriz(raiz);
    adicionarAresta(matriz, acessarIndice(raiz, 0), acessarIndice(raiz, 1));
    adicionarAresta(matriz, acessarIndice(raiz, 0), acessarIndice(raiz, 2));
    adicionarAresta(matriz, acessarIndice(raiz, 0), acessarIndice(raiz, 3));
    adicionarAresta(matriz, acessarIndice(raiz, 2), acessarIndice(raiz, 0));


    for(int i = 0; i < tamanho(raiz); i++){
        printf("%s\n", acessarIndice(raiz, i)->nome);
    }

    printf("Tamanho do grafo %d\n", tamanho(raiz));

    imprimirMatriz(matriz);
    return 0; 
}