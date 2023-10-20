#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char fixo[20];
    char celular[20];
    char email[50];
    char endereco[100];
    char aniversario[10];
} contato;

void main(){
    contato lista[3];
    int i;

    for(i = 0; i<3; i++){
        printf("CONTATO %d\n", i);
        printf("Nome: ");
        gets(lista[i].nome);
        printf("Telefone Fixo: ");
        gets(lista[i].fixo);
        printf("Celular: ");
        gets(lista[i].celular);
        printf("Email: ");
        gets(lista[i].email);
        printf("Endereco: ");
        gets(lista[i].endereco);
        printf("Aniversario: ");
        gets(lista[i].aniversario);
        printf("\n\n");
    }
    do {
        printf("======================================");
        printf("\nQue usuário você deseja consultar?\n"); 
        printf("0. %s\n", lista[0].nome); 
        printf("1. %s\n", lista[1].nome); 
        printf("2. %s\n", lista[2].nome);
        scanf("%d", &i);
       if ((i>-1) && (i<3)){
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone Fixo: %s\n", lista[i].fixo);
        printf("Celular: %s\n", lista[i].celular);
        printf("Email: %s\n", lista[i].email);
        printf("Endereco: %s\n", lista[i].endereco);
        printf("Aniversario: %s\n", lista[i].aniversario);
         } else {
       }
    } while ((i>-1) && (i<3));
}
