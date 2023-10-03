    #include<stdio.h>
    #include<stdlib.h>
    #define INICIO 0
    #define FIM 10

    int push(int pilha[],int * topo,int valor){
        if(*topo-1==FIM){
            return 0;
        } else {
            (*topo)++;
            pilha[*topo-1]=valor;
            return 1;
        }
    }

    int pop(int pilha[],int * topo,int * status){
        int *valor;
        if(*topo==-1){
            return 0;
        } else {
            *valor=pilha[*topo];
            (*topo)--;
            return *valor;
        }
    }

    int main(){
        int pilha[FIM], topo=INICIO;
        printf("Valor de retorno:%d\n", push(pilha,&topo,10));
        printf("Valor topo: %d\n",pilha[topo-1]);
        printf("Valor de retorno:%d\n", push(pilha,&topo,20));
        printf("Valor topo: %d\n",pilha[topo-1]);
        printf("Valor de retorno:%d\n", push(pilha,&topo,30));
        printf("Valor topo: %d\n",pilha[topo-1]);
        printf("Valor de retorno:%d\n", pop(pilha,&topo,40));
        printf("Variável topo:%d\n",topo);
        printf("Array todo\n");
        for(int i=0;i<3;i++){
            printf("%d\n",pilha[i]);
        }

        return 0;
    }

