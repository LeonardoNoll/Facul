    #include<stdio.h>
    #include<stdlib.h>
    #define INICIO -1
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

    int pop(int pilha[],int * topo,int * valor){
        if(*topo==INICIO){
            return 0;
        } else {
            *valor=pilha[*topo];
            (*topo)--;
            return 1;
        }
    }

    int main(){
        int pilha[FIM], topo=INICIO;
        printf("Valor de retorno:%d\n", push(pilha,&topo,10));
        printf("Valor topo: %d\n",pilha[topo]);
        push(pilha,&topo,20);
        printf("Valor topo: %d\n",pilha[topo]);
        printf("Variável topo:%d\n",topo);
        printf("Array todo\n");
        for(int i=0;i<3;i++){
            printf("%d\n",pilha[i]);
        }

        return 0;
    }
