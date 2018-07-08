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
    char macaco[5], veado[5], coelho[5], lagosta[5], gato[5], tigre[5], pato[5];
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

    if (strlen(palavra))
    {
        print("Content-Type:text/html\n\n");
        imprimir_arquivo("header.html");
        printf("G U K <span class=" coelho ">C</span> D S O Q G S D L <span class=" macaco ">M</span> A K <br>", coelho, macaco);
        printf("P N E G <span class=" coelho ">O</span> B I F Q B O <span class=" macaco ">A</span> Y N U <br>", coelho, macaco);
        printf("N D D W H <span class=" coelho ">E</span> J I C K <span class=" macaco ">C</span> A J Y E <br>", coelho, macaco);
        printf("<span class=" veado ">V</span> K F R P B <span class=" coelho ">L</span> L W <span class=" macaco ">A</span> Q M Z S R <br>", veado, coelho, macaco);
        printf("<span class=" veado ">E</span> L K L U Z M <span class=" coelho ">H</span> <span class=" macaco ">C</span> O Z N M O G <br>", veado, coelho, macaco);
        printf("<span class=" veado ">A</span> J E K I E P <span class=" macaco ">O</span> <span class=" coelho ">O</span> F R X B <span class=" tigre ">E</span> H <br>", veado, macaco, coelho, tigre);
        printf("<span class=" veado ">D</span> Y O E V I X X E G F F R <span class=" tigre ">R</span> G <br>", veado, tigre);
        printf("<span class=" veado ">O</span> <span class=" gato ">G</span> A F O A <span class=" pato ">O T A P</span> K K A <span class=" tigre ">G</span> H <br>", veado, gato, pato, tigre);
        printf("W <span class=" gato ">A</span> A D Y C G U N J N Z C <span class=" tigre ">I</span> V <br>", gato, tigre);
        printf("F <span class=" gato ">T</span> C E N M C V R K W E M <span class=" tigre ">T</span> X <br>", gato, tigre);
        printf("X <span class=" gato ">O</span> A D I Z C X J E P O Q Q Q <br>", gato);
        printf("G N G D Z H C Y X E Y F N O W <br>");
        printf("P M J G A Q Y Q Q M J F G Q W <br>");
        printf("M K Y P M U I Y U I X L C W N <br>");
        printf("P A Q I <span class=" lagosta ">A T S O G A L</span> E E J F <br>", lagosta);
        // printf("<div class='found'>%s</div>", palavra);
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
