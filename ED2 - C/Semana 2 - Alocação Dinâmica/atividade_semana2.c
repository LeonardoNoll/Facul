#include <stdio.h>
#include <stdlib.h>

#define tamanho 300000000

int main() {
    double *a;
    a = (double *)malloc(tamanho * sizeof(double));

    for(long int i = 0; i < tamanho; i++) {
        a[i] = 0;
    }
        
    printf("1. Número de posições de memória ocupada %d",(long int)sizeof(double));

	printf("%x\n", &a[1]);
	printf("%x\n", &a[2]);
	printf("%x\n", &a[3]);
	
    system("pause");
	free(a);
    return 0;
}
