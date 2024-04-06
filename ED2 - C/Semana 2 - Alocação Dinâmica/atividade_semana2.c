#include <stdio.h>
#include <stdlib.h>

#define tamanho 20

int main() {
	long int i;
    double *a;
    a = (double *)malloc(tamanho * sizeof(double));

    for(i = 0; i < tamanho; i++) {
        a[i] = 0;
    }

    system("pause");
	free(a);
    return 0;
}
