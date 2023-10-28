#include <stdio.h>
#include <stdlib.h>

//STRUCT
typedef struct {
    char nome[30];
    char tel[11];
    char cel[11];
    char endereco[60];
    char aniver[10];
}   contato;

//FUNCOES
void limpaBuffer(){
    __fpurge(stdin); // Linux
    fflush(stdin); // Windows
}

void leitura(contato* cont) {
    limpaBuffer();
    printf("\nDigite o nome do contato: ");
    gets(cont->nome);
    printf("\nDigite o telefone do contato: ");
    gets(cont->tel);
    printf("\nDigite o celular do contato: ");
    gets(cont->cel);
    printf("\nDigite o endereço do contato: ");
    gets(cont->endereco);
    printf("\nDigite o aniversário do contato: ");
    gets(cont->aniver);
}

int main() {
    contato * agenda[100];
    int i; int ocupados = 0; int opcao;

    printf("\nBem-vindo ao aplicativo de agenda");
    do {
        printf("\n\n=====================================");
        printf("\nCOMANDOS");
        printf("\n1 - Inserir contato");
        printf("\n2 - Visualziar posição da agenda");
        printf("\n3 - Sair");
        printf("\n=====================================\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            agenda[ocupados] = (contato*) malloc(sizeof(contato));
            if (agenda[ocupados] != 0){
                leitura(agenda[ocupados]);
                ocupados++;
            } else {
                printf("\nERRO: Falha em alocar memória");
            }
            break;
        case 2:
            printf("\nQue posição você deseja visualizar? ");
            scanf("%d", &i);
            if (i >= 0 && i < ocupados) {
                printf("\nNome: %s", agenda[i]->nome);
                printf("\nTelefone: %s", agenda[i]->tel);
                printf("\nCelular: %s", agenda[i]->cel);
                printf("\nEndereço: %s", agenda[i]->endereco);
                printf("\nAniversário: %s", agenda[i]->aniver);
            } else {
                printf("\nERRO: Posição inválida");
            }
            break;
        case 3:
            break;
        default:
            printf("\nERRO: Comando inválido");
            break;
        }

    } while (opcao != 3);
    
    for(i=0; i<=ocupados; i++){
        free(agenda[i]);
    }
    return 0;
}