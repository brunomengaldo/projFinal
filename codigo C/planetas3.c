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
        printf("U K J P <span class=\"jupiter %s\">J</span> S O Q G <span class=\"venus %s\">V E N U S</span> K<br>", jupiter, venus);
        printf("N E R G <span class=\"jupiter %s\">U</span> B I F Q B O D V Y U<br>", jupiter);
        printf("D D C W <span class=\"jupiter %s\">P</span> S J I C K E Y A J H<br>", jupiter);
        printf("K F A R <span class=\"jupiter %s\">I</span> B Y L W B H Q M Z <span class=\"mercurio %s\">O</span><br>", jupiter, mercurio);
        printf("L K W L <span class=\"jupiter %s\">T</span> Z M G A F O Z N M <span class=\"mercurio %s\">I</span><br>", jupiter, mercurio);
        printf("J E X K <span class=\"jupiter %s\">E</span> E P H H F R X B R <span class=\"mercurio %s\">R</span><br>", jupiter, mercurio);
        printf("Y O <span class=\"saturno %s\">O N</span> <span class=\"jupiter %s saturno %s \">R</span> <span class=\"saturno %s\">U T A S</span> G F F R R <span class=\"mercurio %s\">U</span><br>", saturno, jupiter, saturno, saturno, mercurio);
        printf("R A A F O A I W L P K K A Y <span class=\"mercurio %s\">C</span><br>", mercurio);
        printf("U A O D Y C <span class=\"plutao %s\">O</span> U N J N Z C I <span class=\"mercurio %s\">R</span><br>", plutao, mercurio);
        printf("T C K E N M C <span class=\"plutao %s\">A</span> R K W E M T <span class=\"mercurio %s\">E</span><br>", plutao, mercurio);
        printf("N A Q D I Z C X <span class=\"plutao %s terra %s \">T</span> E P O Q Q <span class=\"mercurio %s\">M</span><br>", plutao, terra, mercurio);
        printf("N M P D Z H C <span class=\"terra %s\">E</span> X <span class=\"plutao %s\">U</span> Y F N O J<br>", terra, plutao);
        printf("<span class=\"marte %s\">M A R T E</span> Q <span class=\"terra %s\">R</span> Q Q M <span class=\"plutao %s\">L</span> F G Q J<br>", marte, terra, plutao);
        printf("K R G P M <span class=\"terra %s\">R</span> I Y U I X <span class=\"plutao %s\">P</span> C W E<br>", plutao);
        printf("A T K A <span class=\"terra %s\">A</span> A D O C T L E E J U<br>", terra);
    }
    /*if(qtdPalavrasEncontradas){
        printf("<hr>");
        printf("<h1>Palavras Encontradas</h1>");
        printf("<ul>");
        for(i = 0; i < qtdPalavrasEncontradas; i++)
            printf("<li>%s</li>", palavrasEncontradas[i]);
        printf("</ul>");
    }*/
    if (disporEncontrados)
    {
        printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
    }

    imprimir_arquivo("footer.html");

    return 0;
}
