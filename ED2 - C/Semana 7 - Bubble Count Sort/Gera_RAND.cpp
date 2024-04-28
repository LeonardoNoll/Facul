#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

main(){
int i;
unsigned int ex;
FILE *txt;
char namefile[20];

printf("Conectando. . .\n");

for(int j = 0; j < 100; j++){
     sprintf(namefile, "bingchiling%d.txt", j);
     if((txt = fopen(namefile, "wb")) == NULL)    {
        printf("Erro ao abrir arquivo");
        exit(1);
     } else {
	  	//Definindo a Semente Inicial do Gerador Aleat�rio
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		
	     i = 0;
         while(i < 100000)
         {
               float c = 100000;
			   fwrite(&c, 1, sizeof(c),txt);
               ++i;
          }
		fclose(txt);
      }
      }
}

