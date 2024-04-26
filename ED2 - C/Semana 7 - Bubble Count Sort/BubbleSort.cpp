#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

int main() {
//Inicializaçã do Vetor
 int v[100000]= {0}, n=100000;
 int i = 0, j = 0,  aux;
 long long int pesquisas = 0LL;
 char leitor[5];
 FILE *fonte, *destino;
 
 //Lê arquivo
 if((fonte = fopen("Arquivo.txt", "r")) == NULL) {
 	printf("Erro na abertura de arquivo");
 } else {
		printf("Leitura aberta!\n");
		while(!feof(fonte)) {
 			fscanf(fonte, "%s", leitor);
 			v[i] = atoi(leitor);
 			i++;
		}
		fclose(fonte);
		printf("Leitura fechada!\n");

//Algoritmo de Ordenação 
		while (j < n) {
			for(i = 0; i < n-1; i++) {
				pesquisas++;
				if(v[i] > v[i + 1]){	
				aux=v[i];
             	v[i] = v[i+1];
             	v[i+1] = aux;
				}
			}
			j++;
		}
		
//Gravação do arquivo ordenado}
		if((destino = fopen("OrdenadoBubble.txt", "w")) == NULL) {
		 	printf("Erro ao abrir arquivo de escrita\n");
		 	exit(1);
		} else {
			printf("Gravando arquivo!\n");
			for (int q=0; q<n; q++) {
        		fprintf(destino,"%d\n",v[q]); 
    		}
    		fclose(destino);
			printf("Arquivo gravado!\n");
		}
	}
	printf("Pesquisas executadas: %llu\n", pesquisas);
	return 0;
}
//Laço de impressão do Vetor
	