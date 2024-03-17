#include <stdio.h>
int main()
{
    int i;
    FILE *txt;
    if ((txt = fopen("arquivo.txt", "a+")) == NULL) {
        printf("Erro ao abrir arquivo");
    }
    else {
        i = 50;
        while (i < 100)
        {
            fprintf(txt, "%d\n", i);
            ++i;
        }
        fclose(txt);
    }
    return 0;
}