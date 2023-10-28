#include <stdio.h>
#define MAX 7

int push(int * pilha, int valor, int *topo){
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
        return pilha[*topo];
    }
}

void main(){
    int pilha[MAX];
    int topo = 0;
    int a; int b;
    
    for (int i = 0; i<MAX; i++){
        push(pilha, i+1, &topo);
    }
    for (int i = 0; i<MAX; i++){
        printf("\n%d ", pilha[i]);
    }

     a = pop(pilha, &topo);
        printf("\n\n\n%d ", a);
     a = pop(pilha, &topo);
        printf("\n\n\n%d ", a);
     a = pop(pilha, &topo);
        printf("\n\n\n%d ", a);

}