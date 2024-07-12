#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int fatorialRecursivo(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorialRecursivo(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);

    printf("Fatorial usando recursividade: %d\n", fatorialRecursivo(n));

    return 0;
}