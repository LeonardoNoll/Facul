#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

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
};

