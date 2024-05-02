#include <stdio.h>
#include <stdlib.h>

int main ()  {
    //Inicializa�� do Vetor
    int v[100000],  n=100000;
    int i, j, chave;
    long long int pesquisas = 0LL;
    FILE *fonte, *destino;
   
   int c = 0; 
   
    //Lê arquivo
 if((fonte = fopen("Arquivo.txt", "r")) == NULL) {
 	printf("Erro na abertura de arquivo");
 } else {
		printf("Leitura aberta!\n");
		while(!feof(fonte)) {
 			fscanf(fonte, "%d", &v[i]);
 			i++;
		}
		fclose(fonte);
		printf("Leitura fechada!\n");
   
    //Algoritmo de Ordena��o 
	for(j=1; j<n; j++) 
	{
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave) {
			v[i+1] = v[i];
			i--;
//			pesquisas++;
		}		
		v[i+1] = chave;
	}
	
//Gravação do arquivo ordenado}
		if((destino = fopen("OrdenadoInsert.txt", "w")) == NULL) {
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

