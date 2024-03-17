#include <stdio.h>
#include <stdlib.h>

#define tamanho 20

int main() {
    double *a;
    a = (double *)malloc(tamanho * sizeof(double));

    for(long int i = 0; i < tamanho; i++) {
        a[i] = 0;
    }

    system("pause");
    return 0;
}
