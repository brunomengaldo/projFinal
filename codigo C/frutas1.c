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
                    
                 
                    printf("<body class=\"container\">");
                        printf("<main>");
                            printf("<h2><strong>Frutas</strong></h2>");
                            printf("<div class=\"jogo1\">");
                                printf("X M T A Q A J J S U R S X M I<br>");
                                printf("J A F <span class=\"banana %s\">B A N A N A</span> I R L M B D<br>", banana);
                                printf("E M <span class=\"morango %s\">O</span> J X C K S K F C R A M E<br>", morango);
                                printf("S S B <span class=\"morango %s\">G</span> O A P Z S L E C F X S<br>", morango);
                                printf("U O L F <span class=\"morango %s\">N</span> J K S <span class=\"acerola %s\">A L O R E C A</span><br>", morango, acerola);
                                printf("T <span class=\"goiaba %s\">A</span> J V T <span class=\"morango %s\">A</span> E U F R U T E Z U<br>", goiaba, morango);
                                printf("Y <span class=\"goiaba %s\">B</span> L V E C <span class=\"morango %s\">R</span> Z O F Q G B <span class=\"laranja %s\">L</span> I<br>", goiaba, morango, laranja);
                                printf("B <span class=\"goiaba %s\">A</span> N K M K F <span class=\"morango %s\">O</span> J K B N I <span class=\"laranja %s\">A</span> Z<br>", goiaba, morango, laranja);
                                printf("U <span class=\"goiaba %s\">I</span> C L M G A A <span class=\"morango %s\">M</span> B O V U <span class=\"laranja %s\">R</span> G<br>", goiaba, morango, laranja);
                                printf("Q <span class=\"goiaba %s\">O</span> W B L Z H U Q L F I N <span class=\"laranja %s\">A</span> R<br>", goiaba, laranja);
                                printf("S <span class=\"goiaba %s\">G</span> D D M R <span class=\"kiwi %s\">I</span> R Q R Z Z V <span class=\"laranja %s\">N</span> C<br>", goiaba, kiwi, laranja);
                                printf("B D O H K <span class=\"kiwi %s\">W</span> J K I <span class=\"uva %s\">A</span> D I F <span class=\"laranja %s\">J</span> K<br>", kiwi, uva, laranja);
                                printf("L N X Y <span class=\"kiwi %s\">I</span> K T V T G <span class=\"uva %s\">V</span> A Q <span class=\"laranja %s\">A</span> U<br>", kiwi, uva, laranja);
                                printf("X O N <span class=\"kiwi %s\">K</span> T B T X S K A <span class=\"uva %s\">U</span> E J A<br>", kiwi, uva);
                                printf("E T Q S K Z N O U I G S A U B<br>");
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
    if(disporEncontrados){
        printf("<input type='hidden' name='encontrados' value='%s' />", encontrados);
    }

    
    imprimir_arquivo("footer.html");
    
    return 0;
}
