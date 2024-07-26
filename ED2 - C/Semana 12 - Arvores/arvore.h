typedef struct Nodo {
		         struct Nodo *esq;
		         char info;
		         struct Nodo *dir;
		        } TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, char info, TArvore* dir)
{
 TArvore *p;

 p = (TArvore*) malloc(sizeof(TArvore));
 if (p == NULL)
     {
      printf("ERRO FATAL: Falta de Mem�ria\n");
      getchar();
      exit(0); 

     }
 else
     {
      p->info = info;
      p->esq = esq;
      p->dir = dir;
     }
 return p;
}


int Vazia(TArvore *a)
{
 if (a == NULL)
     return(1);
 else
     return(0);
}


void Caminhamento_Pre_Ordem(TArvore *a)
{
 if (!Vazia(a))
    {
     printf("%c ", a->info); 			
     Caminhamento_Pre_Ordem(a->esq);     
     Caminhamento_Pre_Ordem(a->dir);     
    }
}


void Caminhamento_In_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_In_Fixado(a->esq);     
     printf("%c ", a->info); 			
     Caminhamento_In_Fixado(a->dir);     
    }
}


void Caminhamento_Pos_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_Pos_Fixado(a->esq);      
     Caminhamento_Pos_Fixado(a->dir);      
     printf("%c ", a->info); 			
    }
}


TArvore *Destroi(TArvore *a)
{
 if (!Vazia(a))
    {
     Destroi(a->esq); 
     Destroi(a->dir); 
     free(a);         
    }
 return(NULL);
}

int Altura(TArvore *a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = Altura(a->esq);
        int dir = Altura(a->dir);
        if (esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

TArvore* Encontrar(TArvore* a, char info) {
    if (a == NULL) {
        return NULL;
    } else if (a->info == info) {
        return a;
    } else {
        TArvore* esq = Encontrar(a->esq, info);
        TArvore* dir = Encontrar(a->dir, info);
        if (esq != NULL) {
            return esq;
        } else {
            return dir;
        }
    }
}