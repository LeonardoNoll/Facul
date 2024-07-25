#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void)
{
 TArvore *a0,*a1,*a2,*a3,*a4,*a5,*a6, *a7;

 
 a1 = Cria(NULL,'Y',NULL);
 a2 = Cria(NULL,'L',NULL);
 a3 = Cria(a1,'W',a2);
 a4 = Cria(NULL,'V',NULL);
 a5 = Cria(a3,'E',a4);
 a6 = Cria(NULL,'T',NULL);
 a0 = Cria(a5,'S',a6);
 
 printf("Caminhamentos na Arvore:\n\n");
 
 printf("\n - Pre-Ordem: \t");
 Caminhamento_Pre_Ordem(a0);
 
 printf("\n - In-Fixado: \t");
 Caminhamento_In_Fixado(a0);
 
 printf("\n - Pos-Fixado: \t");
 Caminhamento_Pos_Fixado(a0);

return(0);
}

