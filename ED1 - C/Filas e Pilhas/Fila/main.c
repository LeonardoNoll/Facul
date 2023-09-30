    #include<stdio.h>
    #include<stdlib.h>
    #define INICIO 0
    #define FIM 10

    int push(int pilha[],int * topo,int valor){
        if(*topo==FIM){
            return 0;
        } else {
            (*topo)++;
            pilha[*topo]=valor;
            return 1;
        }
    }

    int main(){
        int pilha[3], topo=INICIO;
        push(pilha,&topo,10);
        printf("%d\n",pilha[topo]);

        return 0;
    }
