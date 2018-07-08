#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cgi_utilidades.c"
int selecionadorDeJogo();

int main()
{
    int tipojogo;
    tipojogo = selecionadorDeJogo();
    printf("%d", tipojogo);
    // Declarações
    int quantidade_parametros, i, disporEncontrados = 0, qtdPalavrasEncontradas = 0;
    char palavraraw[1000], palavra[1000], encontradosraw[1000], encontrados[1000], *ptr, query[1000], **palavrasEncontradas;
    char ref[50]={"MACACO\nGATO\nPATO\nCOELHO\nTIGRE\nVEADO\nLAGOSTA\0"};
    Param *parametros;
    palavra[0] = '\0';
    encontradosraw[0] = '\0';
    // printf("%s", getenv("QUERY_STRING"));
    // Definindo tipo de conteúdo
    tipo_conteudo(HTML);

    // Pegando os parametros
    strcpy(query, getenv("QUERY_STRING"));
    if (strcmp(query, "") != 0)
    {
        ptr = strtok(query, "&");
        strcpy(palavraraw, ptr);
        ptr = strtok(NULL, "&");
        if (ptr != NULL)
            strcpy(encontradosraw, ptr);

        // Extraindo palavra
        strtok(palavraraw, "=");
        ptr = strtok(NULL, "=");
        strcpy(palavra, ptr);

        // Extraindo encontrados
        ptr = strtok(encontradosraw, "=");
        if (ptr != NULL)
        {
            ptr = strtok(NULL, "=");
            strcpy(encontrados, ptr);
        }

        if (strlen(encontradosraw))
        {
            int count = 1, i, token_len;
            char copiaEncontrados[1000];
            strcpy(copiaEncontrados, encontrados);
            for (i = 0; i < strlen(encontrados); i++)
                if (encontrados[i] == '.')
                    count++;
            palavrasEncontradas = (char **)malloc(sizeof(char *) * count);

            ptr = strtok(copiaEncontrados, ".");
            token_len = strlen(ptr);
            palavrasEncontradas[0] = (char *)malloc(sizeof(char) * token_len);
            strcpy(palavrasEncontradas[0], ptr);

            for (i = 1; i < count; i++)
            {
                ptr = strtok(NULL, ".");
                token_len = strlen(ptr);
                palavrasEncontradas[i] = (char *)malloc(sizeof(char) * token_len);
                strcpy(palavrasEncontradas[i], ptr);
            }

            qtdPalavrasEncontradas = count;

            strcat(encontrados, ".");
            strcat(encontrados, palavra);
        }
        else
        {
            strcpy(encontrados, "");
            strcat(encontrados, palavra);
        }
        disporEncontrados = 1;
    }
    else
    {
    }

    if (tipojogo == 1)
    {

        if (strlen(palavra))
        {
            printf("Content-Type:text/html\n\n");

            imprimir_arquivo("../animais/header1.html");

                if (disporEncontrados)
            {
                printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
            }

            imprimir_arquivo("../animais/footer1.html");
        }
    }

    else if (tipojogo == 2)

    {
        if (strlen(palavra))
        {
            imprimir_arquivo("../animais/header2.html");

                if (disporEncontrados)
            {
                printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
            }

            imprimir_arquivo("../animais/footer2.html");
        }
    }

    else if (tipojogo == 3)

    {
        if (strlen(palavra))
        {
            imprimir_arquivo("../animais/header3.html");

                if (disporEncontrados)
            {
                printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
            }

            imprimir_arquivo("../animais/footer3.html");
        }
    }
    return 0;
}

//Objetivo: Decidir qual jogo será aberto quando o usuario clicar no tipo animais
//Paramentros formais: Não há
//Retorno: Numero de jogo
int selecionadorDeJogo()
{
    srand(time(NULL));
    int aleatorio = rand() % 3 + 1;
    return aleatorio;
}