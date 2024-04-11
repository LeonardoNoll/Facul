#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale.h>

//******** DEFINICAO DE STRUCT ********
typedef struct DADOS {
    int icodigo;
    char esfera[16]; 
    char solicitante[80]; 
    char situacao[10]; 
    char data[16]; 
    char motivo[80]; 
} DADOS;

void busca(int x, DADOS *ptr, int TAMANHO) {
    int meio=0, esquerda = -1, direita = TAMANHO; 
    while (esquerda < direita-1) {  
      int meio = (esquerda + direita)/2;
      if ((ptr+meio)->icodigo < x) esquerda = meio;
      else direita = meio; 
   }
if ((ptr+direita)->icodigo == x) printf("Valor Localizado na posição %d", direita); 
else printf("Valor NAO Localizado"); 
}

int main() {
setlocale(LC_ALL, "Portuguese");

DADOS *pessoa;
FILE *txt, *bin;
int leituras = 0, escritas = 0;

//******** ALOCAÇÃO DINAMICA ********//
if((pessoa = (DADOS*)malloc(999*sizeof(DADOS))) == NULL){
    printf("Erro ao alocar memoria");
} else {
    //******** ABERTURA DE ARQUIVO PARA LEITURA ********//
    if((txt = fopen("dados.prn","r")) == NULL) {
            printf("Erro ao abrir arquivo");
        }
    else {
            while (!feof(txt)) {
                fscanf(txt, "%d %10s %79[^\n] %8s %10s %80[^\n]", &(pessoa+leituras)->icodigo, (pessoa+leituras)->esfera, (pessoa+leituras)->solicitante, (pessoa+leituras)->situacao, (pessoa+leituras)->data, (pessoa+leituras)->motivo);
                // printf("%d - %s - %s - %s - %s - %s\n", (pessoa+leituras)->icodigo, (pessoa+leituras)->esfera, (pessoa+leituras)->solicitante, (pessoa+leituras)->situacao, (pessoa+leituras)->data, (pessoa+leituras)->motivo);
                leituras++;
                if(leituras%999 == 0) {
                    //******** REALLOC ********//
                    printf("%d\n", leituras);
                    if((pessoa = (DADOS*)realloc(pessoa,(999+leituras)*sizeof(DADOS)))== NULL) {
                        printf("Erro de realocação\n");
                        fclose(txt);
                        free(pessoa);
                        return 0;
                    }
                }
            }
            fclose(txt);
        // printf("i: %d\n", i);
        // printf("pessoa: %x\n", pessoa);
        // printf("pessoa+i: %x\n", pessoa+i);
        }

        //******** CRIAR ARQUIVO BINARIO ********
        if((bin = fopen("dados.bin", "wb+")) == NULL) {
            printf("Erro ao abrir arquivo binário");
        } else {
            //******** GRAVAR ARQUIVO BINARIO ********
            for(escritas; escritas < leituras; escritas++) {
                fwrite((pessoa+escritas), 1, sizeof(DADOS), bin);
            }

            rewind(bin);
            leituras = 0;
            while(!feof(bin)) {
                //******** LEITURA DE ARQUIVO BINARIO ********
                fread((pessoa+leituras), sizeof(DADOS), 1, bin);
                printf("%d - %s - %s - %s - %s - %s\n", (pessoa+leituras)->icodigo, (pessoa+leituras)->esfera, (pessoa+leituras)->solicitante, (pessoa+leituras)->situacao, (pessoa+leituras)->data, (pessoa+leituras)->motivo);
                leituras++;
            }
            free(bin);

            //******** TESTANDO BUSCA BINARIA ********
            printf("\nPosição do codigo %d no vetoer pessoas: ", (pessoa+4)->icodigo);
            busca((pessoa+4)->icodigo,pessoa,leituras);            
            free(pessoa);
    }
system("pause");
    
return 0; 
}}

    
