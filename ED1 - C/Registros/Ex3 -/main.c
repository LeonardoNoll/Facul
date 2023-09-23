#include <stdio.h>
#include <string.h>

void limpaBuffer(){
    __fpurge(stdin); // Linux
    fflush(stdin); // Windows
}

typedef struct {
    char nome[50];
    int matricula;
    int notas[4];
    int faltas;
} aluno;
aluno a[5]; // Vetor de alunos

aluno setAluno(aluno a){
    printf("===INFORME OS DADOS DO ALUNO===\n");
    printf("Nome: ");
    limpaBuffer();
    gets(a.nome);
    printf("Matricula: ");
    scanf("%d", &a.matricula);
    printf("Nota 1: ");
    scanf("%d", &a.notas[0]);
    printf("Nota 2: ");
    scanf("%d", &a.notas[1]);
    printf("Nota 3: ");
    scanf("%d", &a.notas[2]);
    printf("Nota 4: ");
    scanf("%d", &a.notas[3]);
    printf("Faltas: ");
    scanf("%d", &a.faltas);
    printf("\n");

    return a;
}

float media(aluno a){
    int i;
    float soma = 0;
    for (i = 0; i < 4; i++){
        soma = soma + a.notas[i];
    }
    return soma / 4;
}

void main(){
    int i;
    for (i = 0; i < 5; i++){
        a[i] = setAluno(a[i]);
    }
    printf("\e[1;1H\e[2J"); // Limpa a tela
    for (i = 0; i < 5; i++){
        printf("\n===INFORMACOES DO ALUNO [%d]===\n", i);
        printf("Nome: %s\n", a[i].nome);
        printf("Matricula: %d\n", a[i].matricula);
        printf("Nota 1: %d\n", a[i].notas[0]);
        printf("Nota 2: %d\n", a[i].notas[1]);
        printf("Nota 3: %d\n", a[i].notas[2]);
        printf("Nota 4: %d\n", a[i].notas[3]);
        printf("Faltas: %d\n", a[i].faltas);
        printf("Media: %.2f\n", media(a[i]));
    }
}