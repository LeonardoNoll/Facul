#include <stdlib.h>
#include <stdio.h>

main() {
    int codigo;
    char empresa[10];
    char sobre[12];
    char nome[10];
    char funcao[10];

    FILE *txt;

    if ((txt = fopen("funcionarios.txt", "r")) == NULL) {
        printf("Erro na abertura do arquivo");
    } else {

    }
    
    return 0;
}