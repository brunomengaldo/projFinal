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
        printf("Z T J R H D J U K T P F K P T<br>");
        printf("V J S P L H Q G R K K C P X T<br>");
        printf("K P I <span class=\"acerola %s\">A</span> T E X L E Q Q N Z L N<br>", acerola);
        printf("U L L S <span class=\"acerola %s\">C</span> O S U G B X U Q <span class=\"goiaba %s\">G</span> C<br>", acerola, goiaba);
        printf("O <span class=\"laranja %s\">A</span> K J D <span class=\"acerola %s\">E</span> M L K S H P S <span class=\"goiaba %s\">O</span> C<br>", laranja, acerola, goiaba);
        printf("Z <span class=\"laranja %s\">J</span> E T I O <span class=\"acerola %s\">R</span> I H H Z X L <span class=\"goiaba %s\">I</span> B<br>", laranja, acerola, goiaba);
        printf("E <span class=\"laranja %s\">N</span> H G M G Q <span class=\"acerola %s\">O</span> N J Q K W <span class=\"goiaba %s\">A</span> U<br>", laranja, acerola, goiaba);
        printf("K <span class=\"laranja %s\">A</span> L N E S K S <span class=\"acerola %s\">L</span> R D Q U <span class=\"goiaba %s\">B</span> L<br>", laranja, acerola, goiaba);
        printf("Z <span class=\"laranja %s\">R</span> S M A U N U R <span class=\"acerola %s\">A</span> U F F <span class=\"goiaba %s\">A</span> T<br>", laranja, acerola, goiaba);
        printf("X <span class=\"laranja %s\">A</span> Z E U <span class=\"banana %s\">A N A N A B</span> Y G U Q<br>", laranja, banana);
        printf("I <span class=\"laranja %s\">L</span> F H R K R M K I U A W V R<br>", laranja);
        printf("H V K C E W <span class=\"morango %s\">M O R A N G O</span> A I<br>", morango);
        printf("M A Y Q Z I P Q I <span class=\"uva %s\">A</span> G F F N L<br>", uva);
        printf("A Q L <span class=\"kiwi %s\">I W I K</span> L Q <span class=\"uva %s\">V</span> Y A H T E<br>", kiwi, uva);
        printf("I C U F F V Z D C <span class=\"uva %s\">U</span> W W P L Y<br>", uva);
        // printf("<div class='found'>%s</div>", palavra);
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
