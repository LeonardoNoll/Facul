#include <stdio.h>
#define MAX 6

int push(int pilha[], int valor, int *topo){
    if (*topo==MAX) {
        printf("!Lista cheia!");
        return 0; 
    } else {
        pilha[*topo] = valor;
        (*topo)++;
        return 1;
    }
}

int pop(int pilha[], int *topo){
    if (*topo==0){
        printf("!Lista vazia!");
        return 0;
    } else {
        (*topo)--;
        return pilha[*topo+1];
    }
}

void main(){
    int pilha[MAX];
    int topo = 0;
    int a; int b;
    
    for (int i; i<MAX; i++){
        push()
    }