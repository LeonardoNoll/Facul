#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void clean_str(char *str) {
    int last_char = strlen(str) - 1;
    if(!isalpha(str[last_char]))
    str[last_char] = '\0';
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    FILE *txt;
    char linha[1024], letra, *maiorPalavra, *ultima;
    char **lista_de_linhas;
    int i = 0, j, contadorA = 0, contador_Direito = 0, contador_Dever = 0, contador_Deveres = 0;

    if ((txt = fopen("arquivo_texto.txt", "r")) == NULL)
    {
        printf("Erro na abertura do arquivo");
    }
    else
    {
        // Conta o número de linhas do arquivo
        while (!feof(txt))
        {
            fgets(linha, 1024, txt);
            i++;
        }

        // Aloca memória para a lista de linhas
        lista_de_linhas = (char **)malloc(i * sizeof(char *));
        if (lista_de_linhas == NULL)
        {
            printf("Erro na alocação de memória");
        }
        else
        {
            rewind(txt);
            j = i;
            while (!feof(txt))
            {
                i--;
                fgets(linha, 1024, txt);
                lista_de_linhas[i] = (char *)malloc(1024 * sizeof(char)); // Aloca memória para a linha
                if (lista_de_linhas[i] == NULL)
                {
                    printf("Erro na alocação de memória");
                }
                else
                {
                    strcpy(lista_de_linhas[i], linha); // Copia a linha para a lista
                }
            }
            // Imprime as linhas na ordem inversa e libera a memória alocada
            for (i; i < j; i++)
            {
//                printf("%s", lista_de_linhas[i]);
                free(lista_de_linhas[i]);
            }
            free(lista_de_linhas);
        }

        // Ler a quanta de vezes que a letra "a" ou "A" aparece no arquivo
        rewind(txt);
        while (!feof(txt))
        {
            letra = fgetc(txt);
            if (letra == 'a' || letra == 'A')
            { 
				// Conta apenas A sem acento
                contadorA++;
            }
        }
        printf("\n");
        printf("A letra 'a' ou 'A' aparece %d vezes no arquivo\n", contadorA);

        // Ler quantas vezes as palavras "Direito", "Dever" ou "Deveres" aparecem no arquivo e descobrir qual a maior palavra
        rewind(txt);
        while (!feof(txt))
        {
            fgets(linha, 1024, txt);
            ultima = strtok(linha, " ");
            while (ultima != NULL)
            {   
            	clean_str(ultima);
                i = 0;
                while (ultima[i]) { //normaliza pra lowercase
                    ultima[i] = tolower(ultima[i]);
                    i++;
                }
                if(sizeof(ultima) > sizeof(maiorPalavra)) {
                	strcpy(maiorPalavra, ultima);
				}
                if (strcmp(ultima, "direito") == 0) //tem que trabalhar esse
                {
                    contador_Direito++;
                }
                else if (strcmp(ultima, "dever") == 0)
                {
                    contador_Dever++;
                }
                else if (strcmp(ultima, "deveres") == 0)
                {
                    contador_Deveres++;
                }
                ultima = strtok(NULL, " ");
            }
        }
        printf("\n");
        printf("Instancias da palavra \"direito\": %d\n", contador_Direito);
        printf("Instancias da palavra \"dever\": %d\n", contador_Dever);
        printf("Instancias da palavra \"deveres\": %d\n", contador_Deveres);
        printf("\n");
        printf("Maior palavra: %s", maiorPalavra);
        fclose(txt);
    }
    return 0;
}