#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, int size, long long int *pesquisas)
{
 int i, min, max;
 int j=0; 
 min = max = array[0];
 //Identifica o Maior Elemento
 for(i = 1; i < size;  i++) {
  if (array[i] < min)
     min = array[i];
  else if (array[i] > max)
     max = array[i];  
     }
  int range = max - min + 1;
  int *count = (int *) malloc(range * sizeof(int));
//Marca Todas as posi��es com Zero
  for(i = 0; i < range; i++)
          count[i] = 0;
//Marca as posi��es ocupadas
  for(i = 0; i < size; i++)
         count[array[i] - min]++;
 int indice;
 indice=0; 
//Array recebe as posicoes ocupadas
        for(i = min; i <= max; i++)
           for(j = 0; j < count[ i - min ]; j++)
           {
            (*pesquisas)++;
            array[indice] = i;
            indice++;
		   }
        free(count);
}

int main () {
//Inicializa�� do Vetor
    int v[100000];
    int n=100000;
    int i = 0, j = 0,  aux;
    char leitor[5];
    long long int pesquisas = 0LL;
    FILE *fonte, *destino;

 //Lê arquivo
 if((fonte = fopen("Arquivo.txt", "r")) == NULL) {
 	printf("Erro na abertura de arquivo");
  exit(1);
 } else {
		printf("Leitura aberta!\n");
		while(!feof(fonte)) {
 			fscanf(fonte, "%d", &v[i]);
 			i++;
		}
		fclose(fonte);
		printf("Leitura fechada!\n");
 }
//Algoritmo de Ordena��o 
 counting_sort(v,n, &pesquisas);

//La�o de impress�o do Vetor
    if((destino = fopen("OrdenadoCount.txt", "w")) == NULL) {
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

