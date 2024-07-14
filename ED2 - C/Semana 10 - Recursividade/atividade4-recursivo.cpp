#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

void toLower(char c[]) {
    for(int i = 0; c[i] != '\0'; i++){
        if (c[i] >= 'A' && c[i] <= 'Z') {
            c[i] += 32;
        }
    }
    return;
}

int checaRepeticao(char *original, char comparativo) {    
    if (*original == '\0') {
        return 0;
    }
    if (*original == comparativo) {
        return 1 + checaRepeticao(original+1, comparativo);
    }
    return checaRepeticao(original+1, comparativo);
}

int contarRepeticaoDeLetra(char str[], char comparativo) {
    toLower(str);
    toLower(&comparativo);

    return checaRepeticao(str, comparativo);
}

int main() {
    char str[100];
    char c;

    printf("Digite um palavra como base: ");
    scanf("%s", str);
    printf("Digite uma letra para descobrir quantas vezes ela se repete na palavra: ");
    fflush(stdin);
    scanf("%c", &c);

    printf("Numero de repeticoes da letra \"%c\" na palavra \"%s\": %d", c, str, contarRepeticaoDeLetra(str, c));
}