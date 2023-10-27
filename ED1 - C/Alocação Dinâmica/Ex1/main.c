#include <stdio.h>
#include <string.h>
typedef struct{
char nome[40];
char telefone[15];
} contato;


int main(int argc, char *argv[]){
  	contato *teste;
  	teste = (contato*)malloc(sizeof(contato));
	if (teste == 0){
		printf("Erro de alocação de memória\n");
		return 1;
	}
	printf("Memória alocada com sucesso\n");
	printf("Endereço de teste = %p\n", teste);
	printf("Digite seu nome: ");
  	gets((*teste).nome);
  	strcpy((*teste).telefone, "1234567");
  	printf("Nome = %s\nTelefone =  %s\n",(*teste).nome,(*teste).telefone);
	free(teste);

	return 0;
}
