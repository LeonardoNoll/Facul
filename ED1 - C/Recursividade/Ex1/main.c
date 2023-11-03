#include <stdio.h> 

int somatoria(int n) {
    if (n == 1) {
        return 1;
    }else{
        return n + somatoria(n-1);
    }
}

void main(){
    int n;

    printf("\nDigite um numero: ");
    scanf("%d", &n);

    printf("\nSomatoria de %d: %d", n, somatoria(n));
}