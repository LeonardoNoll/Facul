#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    char email[150];
    char fone[15];
} contato;



typedef struct{
	contato c;
	struct no* prox;
} no;


typedef struct{
     no *topo;
} pilha;
	
//retorna 1 se está vazia, senão retorna 0;
int empty(pilha *p){
    if (p -> topo == NULL){
        return 1;
    } else {
        return 0;
    }
}; 
// retorna 1 se o empilhamento deu certo; retorna 0 se o empilhamento deu 
// recebe como parametro um contato c, os dados dessa struct devem ser copiados para o novo elemento criado
int push (pilha *p, contato c){
    no *novo;
    novo = (no*) malloc(sizeof(no)); //Aloca a memoria para o novo elemento	
    if(novo == NULL || p == NULL){
        return 0; //Erro na alocacao
    } else {
        //Copia as informacoes do param para o novo elemento
        strcpy(novo -> c.nome, c.nome);
        strcpy(novo -> c.email, c.email);
        strcpy(novo -> c.fone, c.fone);
        novo -> prox = p -> topo; //Insere o novo elemento no topo da pilha
        p -> topo = novo;
        return 1;
    }
}	
    //retorna 1 se a remoção deu certo, retorna 0 se deu errado;
	//recebe como parametro um ponteiro para um contato c, que deve receber as informações removidas da pilha
int pop  (pilha *p, contato *c){
    no *aux = p -> topo; //Cria um ponteiro auxiliar q armazena o topo da pilha
    if (empty(p) == 0){ 
        //Copia as informacoes do topo da pilha para o param
        strcpy(c -> nome, aux -> c.nome);
        strcpy(c -> email, aux -> c.email);
        strcpy(c -> fone, aux -> c.fone);
        p -> topo = aux -> prox; //Muda o topo da pilha        
        free(aux); //Libera a memoria do antigo topo
        return 1; 
    } else {
        printf("Pilha vazia!\n");
        return 0; 
    }
}
// mesmo que o pop, mas não remove;
int top  (pilha *p, contato *c){
    if (!empty(p)){
        strcpy(c -> nome, p -> topo -> c.nome);
        strcpy(c -> email, p -> topo -> c.email);
        strcpy(c -> fone, p -> topo -> c.fone);
        return 1;
    } else {
        return 0;
    }
}

int tamanho(pilha *p){
    int tam = 0;
    no *aux = p -> topo;
    while (aux != NULL){
        tam++;
        aux = aux -> prox;
    }
    return tam;
};


// atribui nulo para o topo da pilha
void inicializar(pilha *p){
    p -> topo = NULL;
};