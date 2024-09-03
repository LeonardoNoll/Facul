#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

int main() {
    char nome[30] = "portoAlegre";
    cidade *cidades = criaCidade(nome);
    strcpy(nome, "saoPaulo");
    addCidade(cidades, nome);
    strcpy(nome, "rioDeJaneiro");
    addCidade(cidades, nome);
    
    matrizDeAdjacenscia *matriz = constroiMatriz(cidades);


    printf("cidade %d: %s\n", 0, acessar(cidades, 0)->nome);
    printf("cidade %d: %s\n", 1, acessar(cidades, 1)->nome);
    printf("cidade %d: %s\n", 2, acessar(cidades, 2)->nome);

    printMatriz(matriz);


    definirDistancia(300, 1, 0, matriz);

    printMatriz(matriz);

    menorCaminho(0, 1, matriz);
}