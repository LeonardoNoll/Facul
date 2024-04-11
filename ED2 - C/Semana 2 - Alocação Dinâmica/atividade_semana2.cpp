#include <stdio.h>
#include <stdlib.h>
 
#define TAMANHO 600000000
 
int main() {
long int i;
    double *a;
    a = (double *)malloc(tamanho * sizeof(double));
 
    for(i = 0; i < tamanho; i++) {
        a[i] = 0;
    }
        
    printf("a) Numero de posicoes de memoria ocupadas: %lu\n", (long int)(i * sizeof(double)));
    printf("\n");
    printf("b) Megabytes ocupados aproximadamente: %f\n", (float)(i * sizeof(double)/1000000));
    printf("\n");
    for(int j = 0; j < 5; j++) { 
        printf("c) Posicao [%d] da memoria dinamicamente alocada %x\n", j, a+j);
    }
    printf("\n");
    printf("d) O deslocamento entre cada endereco de memoria sera de 8 bytes,\n visto que esse e o tamanho de variaveis do dipo double\n\n");
 
    system("pause");
    free(a);
    return 0;
}