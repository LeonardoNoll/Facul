#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cpessoa {
	char nome[20];
	int idade;
};

void insert(Cpessoa *target, int *i) {
	FILE *bin;
	
	if((bin = fopen("arquivo_binario.txt","ab")) == NULL){
		printf("Erro ao abrir o arquivo");
	} else {
		printf("Informe o nome: ");
        scanf("%s", target[*i].nome);
        printf("%s", target[*i].nome);
		fclose(bin);
	}
}
void list() {
	
}

int main(void) {
	Cpessoa *aluno;
	int option = 0, aluno_size = 0;
	
    if((aluno = (*Cpessoa)malloc(200*sizeof(Cpessoa))) == NULL) {
        printf("Erro ao alocar memoria");
    } else {
        do {
            printf("[1] - Inserir\n");
            printf("[2] - Listar\n");
            printf("[3] - Sair\n");
            printf("Digite a opcao: ");
            scanf("%d", &option);
            
            switch(option) {
                case 1:
                    insert(aluno+aluno_size, &aluno_size);
                    break;
                case 2:
                    list();
                    break;
                case 3:
                    break;
                default:
                    printf("Codigo Invalido\n");
                    break;
            }
            system("pause");
        } while(option != 3);
        free(aluno);
    }
	
	return 0;
}