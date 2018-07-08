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
        printf("F G M R R O A H M B O B M S W<br>");
        printf("K P Q J I U A G T I V Z Y N B<br>");
        printf("A <span class=" morango ">M O R A N G O</span> E K R I B L H<br>", morango);
        printf("<span class=" laranja ">L</span> K J P D S O Q G S D L <span class=" banana ">A</span> A K<br>", laranja, banana);
        printf("N <span class=" laranja ">A</span> R G U B I F Q B O D <span class=" banana ">N</span> N U<br>", laranja, banana);
        printf("D D <span class=" laranja ">R</span> W H S J I C K E Y <span class=" banana ">A</span> Y H<br>", laranja, banana);
        printf("K F A <span class=" laranja ">A</span> P B Y L W B H Q <span class=" banana ">N</span> S M<br>", laranja, banana);
        printf("L <span class=" acerola ">A</span> W L <span class=" laranja ">N</span> Z M G A F O Z <span class=" banana ">A</span> O W<br>", acerola, laranja, banana);
        printf("J <span class=" acerola ">L</span> X K I <span class=" laranja ">J</span> P H H F R X <span class=" banana ">B</span> H G<br>", acerola, laranja, banana);
        printf("Y <span class=" acerola ">O</span> K E V I <span class=" laranja ">A</span> X E G F F R G T<br>", acerola, laranja);
        printf("R <span class=" acerola ">R</span> A F O A I <span class=" goiaba ">A B A I O G</span> H C<br>", acerola, goiaba);
        printf("U <span class=" acerola ">E</span> O D Y C G U N J N Z C V <span class=" kiwi ">K</span><br>", acerola, kiwi);
        printf("T <span class=" acerola ">C</span> K E N M <span class=" uva ">A V U</span> K W E M X <span class=" kiwi ">I</span><br>", acerola, uva, kiwi);
        printf("N <span class=" acerola ">A</span> Q D I Z C X J E P O Q Q <span class=" kiwi ">W</span><br>", acerola, kiwi);
        printf("N G P D Z H C Y X E Y F N W <span class=" kiwi ">I</span><br>", kiwi);
        // printf("<div class='found'>%s</div>", palavra);
    }
    /*if(qtdPalavrasEncontradas){
        printf("<hr>");
        printf("<h1>Palavras Encontradas</h1>");
        printf("<ul>");
        for(i = 0; i < qtdPalavrasEncontradas; i++)
            printf("<li>%s</li>", palavrasEncontradas[i]);
        printf("</ul>");*/
}
if (disporEncontrados)
{
    printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
}

imprimir_arquivo("footer.html");

return 0;
}
