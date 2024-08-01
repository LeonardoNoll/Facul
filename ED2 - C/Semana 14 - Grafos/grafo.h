#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct vertice {
    char nome[30];
    vertice *proxVertice;
} vertice;

typedef struct matrizDeAdjacenscia {
    vertice *grafo;
    int **matriz;
} matmatrizDeAdjacensciariz;

// retorna novo vertice em um vácuo
// proxVertice = null
vertice *criaRaiz(char nome[]) {
    vertice *novoVertice = (vertice*)malloc(sizeof(vertice));
    
    if(!novoVertice) {
        printf("Erro: falha na alocacao de memoria!");
        exit(1);
    }
    strcpy(novoVertice->nome, nome); 
    novoVertice->proxVertice = NULL;
    return novoVertice; 
};

vertice *acessarIndice(vertice *raiz, int i) {
    if(raiz == NULL || i == 0) { return raiz; }
    return acessarIndice(raiz->proxVertice, i-1);
};

int tamanho(vertice *raiz){
    if(raiz == NULL) { return 0; } 
    else if(!raiz->proxVertice) { return 1;} 
    return tamanho(raiz->proxVertice) + 1;
};

void adicionarVertice(vertice *raiz, char nome[]) {
    vertice *novoVertice = criaRaiz(nome);
    vertice *ultimoItem = acessarIndice(raiz, tamanho(raiz)-1);
    ultimoItem->proxVertice = novoVertice;
    return;
}

matrizDeAdjacenscia *criarMatriz (vertice *grafo) {
    matrizDeAdjacenscia *novaMatriz = (matrizDeAdjacenscia*)malloc(sizeof(matrizDeAdjacenscia));
    novaMatriz->grafo = grafo;
    novaMatriz->matriz = (int**)malloc(sizeof(int*)*tamanho(grafo));
    for(int i = 0; i < tamanho(grafo); i++) {
        novaMatriz->matriz[i] = (int*)malloc(sizeof(int)*tamanho(grafo));
        for(int j = 0; j < tamanho(grafo); j++) {
            novaMatriz->matriz[i][j] = 0;
        }
    }
    return novaMatriz;
}

void adicionarAresta(matrizDeAdjacenscia *matriz, vertice *v1, vertice *v2) {
    int i = 0;
    int j = 0;
    vertice *aux = matriz->grafo;
    while(aux != NULL) {
        if(strcmp(aux->nome, v1->nome) == 0) {
            break;
        }
        i++;
        aux = aux->proxVertice;
    }
    aux = matriz->grafo;
    while(aux != NULL) {
        if(strcmp(aux->nome, v2->nome) == 0) {
            break;
        }
        j++;
        aux = aux->proxVertice;
    }
    matriz->matriz[i][j] = 1;
    matriz->matriz[j][i] = 1;
}

void imprimirMatriz(matrizDeAdjacenscia *matriz) {
    for(int i = 0; i < tamanho(matriz->grafo); i++) {
        for(int j = 0; j < tamanho(matriz->grafo); j++) {
            printf("%d ", matriz->matriz[i][j]);
        }
        printf("\n");
    }
}






// vertice *percorrerLista(vertice *raiz) {
//     if (raiz->proxVertice == NULL) {
//         return raiz;
//     }
//     return percorrerLista(raiz->proxVertice);
// }