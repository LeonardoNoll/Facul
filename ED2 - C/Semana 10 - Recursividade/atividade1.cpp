#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int somatorio(int n) {
    if (n == 0) {
        return 0;
    }
    return n + somatorio(n - 1);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("O somatorio de %d eh %d\n", n, somatorio(n));
}