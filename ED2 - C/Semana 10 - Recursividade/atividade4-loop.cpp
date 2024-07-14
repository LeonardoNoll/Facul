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

int main() {
    char str[100];
    char c;
    int repeticoes = 0;

    printf("Digite um palavra como base: ");
    scanf("%s", str);
    printf("Digite uma letra para descobrir quantas vezes ela se repete na palavra: ");
    fflush(stdin);
    scanf("%c", &c);

    toLower(str);
    toLower(&c);

    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] == c) { repeticoes++; }
    }

    printf("Numero de repeticoes da letra \"%c\" na palavra \"%s\": %d", c, str, repeticoes);
}