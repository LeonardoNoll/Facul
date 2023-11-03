#include <stdio.h>

int potencia(int b, int p){
    if (p == 0) return 1; //caso potencia 0
    else if (p == 1) return b; //valor base
    return b * potencia(b,p - 1); //recursao
}

void main(){
    int base; int expoente;

    printf("\nDigite a base: ");
    scanf("%d", &base);
    printf("\nDigite o expoente: ");
    scanf("%d", &expoente);
    printf("\n%d elevado a %d: %d", base, expoente, potencia(base,expoente));
}