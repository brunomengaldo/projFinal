
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cgi_utilidades.c"

int main()
{
    // Declarações
    int quantidade_parametros, i, disporEncontrados = 0, qtdPalavrasEncontradas = 0;
    char palavraraw[1000], palavra[1000], encontradosraw[1000], encontrados[1000], *ptr, query[1000], **palavrasEncontradas;
    Param *parametros;
    palavra[0] = '\0';
    encontradosraw[0] = '\0';
    char macaco[6], veado[6], coelho[6], lagosta[6], gato[6], tigre[6], pato[6];
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
    print("Content-Type:text/html\n\n");
    imprimir_arquivo("../header.html");
    printf("J S P L H Q G R K K C P X T L <br>");
    printf("P I H <span class=\"tigre %s\">T I G R E</span> Q <span class=\"pato %s\">P</span> N Z L N H <br>", tigre, pato);
    printf("L L S V O S U G B X <span class=\"pato %s\">A</span> Q G C B <br>", pato);
    printf("B K J D T M L K S H P <span class=\"pato %s\">T</span> F C J <br>", pato);
    printf("G E T I <span class=\"lagosta %s\">L</span> O I H H Z X L <span class=\"pato %s\">O</span> B E <br>", lagosta, pato);
    printf("<span class=\"coelho %s\">C</span> H G M G <span class=\"lagosta %s\">A</span> L N J Q K W K U S <br>", coelho, lagosta);
    printf("<span class=\"coelho %s\">O</span> L N E S K <span class=\"lagosta %s\">G</span> E R D Q U L <span class=\"gato %s\">O</span> Q <br>", coelho, lagosta, gato);
    printf("<span class=\"coelho %s\">E</span> S M <span class=\"veado %s\">O</span> U N U <span class=\"lagosta %s\">O</span> Z U F F Q <span class=\"gato %s\">T</span> U <br>", coelho, veado, lagosta, gato);
    printf("<span class=\"coelho %s\">L</span> Z E U <span class=\"veado %s\">D</span> F C M <span class=\"lagosta %s\">S</span> C V Y G <span class=\"gato %s\">A</span> Y <br>", coelho, veado, lagosta, gato);
    printf("<span class=\"coelho %s\">H</span> F H R K <span class=\"veado %s\">A</span> M K I <span class=\"lagosta %s\">T</span> A W V <span class=\"gato %s\">G</span> W <br>", coelho, veado, lagosta, gato);
    printf("<span class=\"coelho %s\">O</span> K C E W C <span class=\"veado %s\">E</span> R Q I <span class=\"lagosta %s\">A</span> Z A I R <br>", coelho, veado, lagosta);
    printf("A Y Q Z I P Q <span class=\"veado %s\">V</span> G A F F N L F <br>", veado);
    printf("C U F F V Z D C V W W P L Y N <br>");
    printf("K W E W V E N <span class=\"macaco %s\">O C A C A M</span> W X <br>", macaco);
    printf("N N C I P Z V N T A C P X M H <br>");

    if (strlen(palavra))
    {
    }
    /*if(qtdPalavrasEncontradas){
        printf("<hr>");
        printf("<h1>Palavras Encontradas</h1>");
        printf("<ul>");
        for(i = 0; i < qtdPalavrasEncontradas; i++)
            printf("<li>%s</li>", palavrasEncontradas[i]);
        printf("</ul>");*/
    if (disporEncontrados)
    {
        printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
    }

    imprimir_arquivo("footer.html");

    return 0;
}
