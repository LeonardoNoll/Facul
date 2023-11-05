#include <stdio.h>
#include <stdlib.h>



typedef struct tipoNo{
	int dado;
	struct tipoNo* prox;
	struct tipoNo* ant;
} tipoNo;

typedef struct tFila{
	tipoNo* head;//primeiro
	tipoNo* tail;//ultimo
	int size;//tamanho: opcional
} tFila;

void inicializar (tFila *f){
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;
};

//retorna 1 se a fila está vazia
//retorna 0 se a fila é não-vazia
int vazia (tFila *f){
    if (f -> head == NULL){
        return 1;
    } else {
        return 0;
    }
}
//retorna 1 se a insercao deu certo
//retorna 0 se a insercao deu errado
int inserir(tFila *f, int d){
    tipoNo *novo;
    novo = (tipoNo*) malloc(sizeof(tipoNo));

    if(novo != NULL){
        novo -> ant == f -> tail;
        novo -> prox == NULL;
        novo -> dado = d;

        if (vazia(f)){ //Para fila vazia
            f -> head = novo;
        } else {                //Para fila nao vazia
            f -> tail -> prox = novo;
        }

        f -> tail = novo;
        f -> size++;
        return 1; 
    } else {
        printf("ERRO DE ALOCACAO\n");
        return 0;
    }
}


//imprime na tela o conteudo da fila
void imprimeFila (tFila *f) {
    tipoNo * aux;
    aux = f -> head;

    if (aux == NULL){
        printf("\nFILA VAZIA\n");
    }
    while (aux != NULL) {
        printf("ITEM: %d\n", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

int remover(tFila *f, int *d){
    tipoNo *aux = f -> head;

    if(aux != NULL){
        *d = aux -> dado;
        f -> head = f -> head -> prox;
        f -> size--;
        free(aux);
        return 0;        
    }
    printf("ERRO DE REMOÇÃO\n");
    return 1;
}
	//retorna 0 se a remocao deu certo
	//retorna 1 se a remocao deu errado
	// se a operacao deu certo, a variavel apontada por d
	//deve receber o valor removido da fila

int tamanho(tFila *f){
    return f->size;
}