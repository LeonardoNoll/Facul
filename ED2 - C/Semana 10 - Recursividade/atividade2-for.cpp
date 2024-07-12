#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main() {
    int n;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);

    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }

    printf("Fatorial usando for: %d\n", fatorial);
    return 0;
}