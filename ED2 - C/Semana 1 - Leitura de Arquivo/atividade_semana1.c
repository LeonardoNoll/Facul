#include <stdio.h>
#include <stdlib.h>

int inverter_arquivo(FILE *txt) {
    char linha[1024];
    char** lista_de_linhas;
    int i = 0;

        while(!feof(txt)){
            fgets(linha, 1024, txt);
            i++;
            printf("%d\n", i);
        }
        // rewind(txt);
        // while(!feof(txt)){
        //     fgets(linha, 1024, txt);
        //     i--;
        //     printf("aa%d\n", i);
        // }

        lista_de_linhas = (char **)malloc(i*sizeof(char *));
        if (lista_de_linhas == NULL) {
            printf("Erro na alocação de memória");
        } else {
            printf("%d\n", sizeof(lista_de_linhas));
            printf("%x\n", lista_de_linhas);
            printf("%x\n", &lista_de_linhas[0]);
            printf("%x\n", &lista_de_linhas[1]);
            printf("%d\n", (int)sizeof(linha));
        }
    
        // printf("linhas %d\ntamanho linha %d\ntamanho lista %d", i, (int)sizeof(linha), (int)sizeof(lista_de_linhas));
        
        fclose(txt);
        free(lista_de_linhas);
    return 0;
}

void main() {
    FILE *txt;
    if((txt = fopen("arquivo_texto.txt", "r")) == NULL) {
        printf("Erro na abertura do arquivo");
    } else {
        inverter_arquivo(txt);
    }
}