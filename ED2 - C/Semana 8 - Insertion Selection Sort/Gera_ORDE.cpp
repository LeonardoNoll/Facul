#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

main(){
int i;
unsigned int ex;

FILE *txt;

if((txt = fopen("Arquivocrescente.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
	     i = 0;
         while(i < 100000)
         {
			   fprintf(txt, "%d\n",i);
               ++i;
          }
		fclose(txt);
      }
}

