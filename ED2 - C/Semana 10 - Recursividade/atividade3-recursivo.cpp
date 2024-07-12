#include <stdio.h>

unsigned long long decimalParaBinario(unsigned long long n, unsigned long long base) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 2) * base + decimalParaBinario(n / 2, base * 10);
    }
}

int main() {
    unsigned long long n;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%llu", &n);

    printf("%llu", decimalParaBinario(n, 1));

    return 0;
}
