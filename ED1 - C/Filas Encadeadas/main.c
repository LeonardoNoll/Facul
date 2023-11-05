
#include <stdio.h>
#include "fila.h"

int main()
{
    int i;
    int r, a, b; 
    tFila fila; 
    inicializar(&fila);
    imprimeFila(&fila);  
    for(i=0;i<7;i++){
        inserir(&fila, i);
        printf("\nInserindo %d. \n",i);
        imprimeFila(&fila);
    }

    while(tamanho(&fila)>1){
        remover(&fila,&a);
        remover(&fila,&b);
        r = a+b;
        inserir(&fila, r);
        imprimeFila(&fila); 
    }

    free(fila.head);
    return 0;
}