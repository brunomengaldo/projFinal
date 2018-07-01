#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cgi_utilidades.c"



int main()
{
    // Declarações
    int quantidade_parametros, i, disporEncontrados = 0, qtdPalavrasEncontradas = 0;
    char palavraraw[1000], palavra[1000], encontradosraw[1000], encontrados[1000], * ptr, query[1000], **palavrasEncontradas;
    Param * parametros;
    palavra[0] = '\0';
    encontradosraw[0] = '\0';
    // printf("%s", getenv("QUERY_STRING"));
    // Definindo tipo de conteúdo
    tipo_conteudo(HTML);

    // Pegando os parametros
    strcpy(query, getenv("QUERY_STRING"));
    if(strcmp(query, "") != 0){
        ptr = strtok(query, "&");
        strcpy(palavraraw, ptr);
        ptr = strtok(NULL, "&");
        if(ptr != NULL)
            strcpy(encontradosraw, ptr);

        // Extraindo palavra
        strtok(palavraraw, "=");
        ptr = strtok(NULL, "=");
        strcpy(palavra, ptr);

        // Extraindo encontrados
        ptr = strtok(encontradosraw, "=");
        if(ptr != NULL){
            ptr = strtok(NULL, "=");
            strcpy(encontrados, ptr);
        }

        if(strlen(encontradosraw)){
            int count = 1, i, token_len;
            char copiaEncontrados[1000];
            strcpy(copiaEncontrados, encontrados);
            for(i = 0; i < strlen(encontrados); i++)
                if(encontrados[i] == '.')
                    count++;
            palavrasEncontradas = (char**) malloc(sizeof(char *) * count);

            ptr = strtok(copiaEncontrados, ".");
            token_len = strlen(ptr);
            palavrasEncontradas[0] = (char*) malloc(sizeof(char) * token_len);
            strcpy(palavrasEncontradas[0], ptr);


            for(i = 1; i < count; i++){
                ptr = strtok(NULL, ".");
                token_len = strlen(ptr);
                palavrasEncontradas[i] = (char*) malloc(sizeof(char) * token_len);
                strcpy(palavrasEncontradas[i], ptr);
            }

            qtdPalavrasEncontradas = count;

            strcat(encontrados, ".");
            strcat(encontrados, palavra);
        } else {
            strcpy(encontrados, "");
            strcat(encontrados, palavra);
        }
        disporEncontrados = 1;
    } else {

    }
    //imprimir_arquivo("header.html");

    if(strlen(palavra)){
        print("Content-Type:text/html\n\n");
                    
                 
                    printf("<body class=\"container\">")
                        printf("<main>")
                            printf("<h2><strong>Animais</strong></h2>")
                            printf("<div class=\"jogo1\">")
                                printf("N N F X W C E R X X N O U F G<br>")
                                printf("Y H J <span class=\"lagosta %s\">L A G O S T A</span> O X K M F<br>", lagosta)
                                printf("K E H Q F S D G K J W M N V <span class=\"tigre %s\">T</span><br>", tigre)
                                printf("P V K <span class=\"coelho %s\">C</span> D A Y P Q F H G Y <span class=\"tigre %s\">I</span> F<br>", coelho, tigre)
                                printf("M N T L <span class=\"coelho %s\">O</span> T G N O Z U W <span class=\"tigre %s\">G</span> X J<br>", coelho, tigre)
                                printf("R H V H Q <span class=\"coelho %s\">E</span> X A U F L <span class=\"tigre %s\">R</span> T N Y<br>", coelho, tigre)
                                printf("G <span class=\"gato %s\">G</span> R M O Y <span class=\"coelho %s\">L</span> P H J <span class=\"tigre %s\">E</span> Y Y <span class=\"veado %s\">O</span> U<br>", gato, coelho, tigre, veado)
                                printf("A <span class=\"gato %s\">A</span> F D C N I <span class=\"coelho %s\">H</span> Z S Y Z H <span class=\"veado %s\">D</span> E<br>", gato, coelho, veado)
                                printf("A <span class=\"gato %s\">T</span> Q U B S H R <span class=\"coelho %s\">O</span> J O E R <span class=\"veado %s\">A</span> L<br>", gato, coelho, veado)
                                printf("D <span class=\"gato %s\">O</span> P I H X S Z V W I N A <span class=\"veado %s\">E</span> N<br>", gato, veado);
                                printf("T V F I V J V R U B T R S <span class=\"veado %s\">V</span> C<br>", veado)
                                printf("W T Y F G <span class=\"macaco %s\">O C A C A M</span> E O A Y<br>",macaco)
                                printf("P B A A Q U H <span class =\"pato %s\">P A T O</span> R N D D<br>", pato)
                                printf("S D Z E A J X O P G O A X K J<br>");
                                printf("S U Y I O C J W A A M V N I K<br>");
                            printf("</div>")
                            printf("<br>")
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
    if(disporEncontrados){
        printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
    }

    
    imprimir_arquivo("footer.html");
    
    return 0;
}
