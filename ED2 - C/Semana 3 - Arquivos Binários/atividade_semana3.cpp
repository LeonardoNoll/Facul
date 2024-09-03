#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cpessoa {
    char nome[20];
    int idade;
} Cpessoa;

void insert() {
    Cpessoa aluno;
    FILE *bin;

    if((bin = fopen("arquivo_binario.bin", "ab")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
    } else {
        printf("Digite o nome: ");
        scanf("%s", aluno.nome);
        printf("Digite a idade: ");
        scanf("%d", &aluno.idade);
        fwrite(&aluno, sizeof(Cpessoa), 1, bin);
        fclose(bin);
    }
}

void list() {
    Cpessoa aluno;
    FILE *bin;

    if((bin = fopen("arquivo_binario.bin", "rb")) == NULL) {
        printf("Erro ao abrir o arquivo\n");
    } else {
        while(fread(&aluno, sizeof(Cpessoa), 1, bin) == 1) {
            printf("Nome: %s\n", aluno.nome);
            printf("Idade: %d\n", aluno.idade);
        }
        fclose(bin);
    }
}

int main(void) {
	Cpessoa *alunos;
	int option = 0, aluno_size = 0;
	
    if((alunos = (Cpessoa*)malloc(200*sizeof(Cpessoa))) == NULL) {
        printf("Erro ao alocar memoria");
    } else {
        while(option != 3) {
            printf("[1] - Inserir\n");
            printf("[2] - Listar\n");
            printf("[3] - Sair\n");
            printf("Digite a opcao: ");
            scanf("%d", &option);    
            switch(option) {
                case 1:
                    insert();
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
        }
        free(alunos);
    }
	
	return 0;
}