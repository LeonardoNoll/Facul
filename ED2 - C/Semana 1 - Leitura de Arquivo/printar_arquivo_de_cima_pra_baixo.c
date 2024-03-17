#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *txt;
    char linha[3000][1024];
    int i = 0;

    if((txt = fopen("arquivo_texto.txt", "r")) == NULL) {
        printf("Erro na abertura do arquivo");
    } else {
        while(!feof(txt)){
            fgets(linha[i], 1024, txt);
            printf("%s", linha[i]);
            i++;
        }
        fclose(txt);
        while(i > -1){
            printf("%s", linha[i]);
            i--;
        }
    }
    // printf("%", sizeof(txt));
    return 0;
}

        // while(!feof(txt)){
        //     fgets(linha[i], 1024, txt);
        //     printf("%s", linha[i]);
        //     i++;
        // }
        // fclose(txt);
        // while(i > -1){
        //     printf("%s", linha[i]);
        //     i--;
        // }