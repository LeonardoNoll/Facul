#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

main () {
 //Inicialização do Vetor
    int v[100000], n=100000;
    long long int pesquisas = 0LL;
    FILE *fonte, *destino;
  	int i, j, min;
    
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
	}

//Algoritmo de Ordenação
  for (i = 0; i < (n-1); i++) {
    min = i;
    for (j = (i+1); j < n; j++) {
      if(v[j] < v[min]) {
        min = j;
      }
	}
    if (i != min) {
//      pesquisas++;
      int swap = v[i];
      v[i] = v[min];
      v[min] = swap;
	  }
	}
	
//Gravação do arquivo ordenado}
		if((destino = fopen("Arquivo.txt", "w")) == NULL) {
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
	printf("Pesquisas executadas: %llu\n", pesquisas);
	return 0;
}

