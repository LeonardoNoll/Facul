#include <stdio.h>
#include <stdlib.h>

void main ()  {
    //Inicializa�� do Vetor
    int v[5]= {1,7,4,3,5},  n=5;
    int i, j, chave;
   
   int c = 0; 
   
    //Algoritmo de Ordena��o 
	for(j=1; j<n; j++) 
	{
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave) {
			v[i+1] = v[i];
			i--;
		}		
		v[i+1] = chave;
	}
	
    //La�o de impress�o do Vetor
	for (int q=0; q<5; q++)	{
        		printf("%d \n",v[q]);
    	}
}

