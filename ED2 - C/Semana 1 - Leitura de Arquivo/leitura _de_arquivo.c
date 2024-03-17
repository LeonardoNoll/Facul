#include <stdlib.h>
#include <stdio.h>

int main() {
    int codigo;
    char empresa[10];
    char sobre[12];
    char nome[10];
    char funcao[10];

    FILE *txt;

    if ((txt = fopen("arquivo_colunas.txt", "r")) == NULL) {
        printf("Erro na abertura do arquivo");
    } else {
        while (!feof(txt)) {
        fscanf(txt, "%d %s %s %s %s", &codigo, empresa, sobre, nome, funcao);
        printf("%d %s %s %s %s\n", codigo, empresa, sobre, nome, funcao);
        }
        fclose(txt);
    }
    return 0;
}