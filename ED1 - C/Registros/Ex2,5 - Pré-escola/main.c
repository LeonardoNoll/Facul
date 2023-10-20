#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char emergencia[20];
    char contato[50];
    int idade;
} aluno;


void limpaBuffer(){
    __fpurge(stdin); // Linux
    fflush(stdin); // Windows
}

aluno setAluno (aluno a, int i){
    printf("===INFORME OS DADOS DO ALUNO [%d]===\n", i);
    printf("Nome: ");
    limpaBuffer();
    gets(a.nome);
    printf("Idade em anos completos: ");
    scanf("%d", &a.idade);
    printf("Nome do contato de emergencia: ");
    limpaBuffer();
    gets(a.contato);
    printf("Contato de emergencia: ");
    limpaBuffer();
    gets(a.emergencia);
    printf("\n");
    return a;
}

void main(){
    aluno a[5]; // Vetor de alunos
    int i;
    for (i = 0; i < 5; i++){
        a[i] = setAluno(a[i], i);
    }
    printf("\e[1;1H\e[2J"); // Limpa a tela
    for (i = 0; i < 5; i++){
        printf("\n===INFORMACOES DO ALUNO [%d]===\n", i);
        printf("Nome: %s\n", a[i].nome);
        printf("Idade: %d\n", a[i].idade);
        printf("Contato de emergencia: %s\n", a[i].contato);
        printf("Numero de emergencia: %s\n", a[i].emergencia);
    }
}
