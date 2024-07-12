#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main() {
    int n;
    int bin = 0;
    int base = 1;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);

    while (n > 0) {
        bin = bin + n % 2 * base;
        base = base * 10;
        n = n / 2;
    }

    bin;
    printf("%d", bin);

    return 0;
}