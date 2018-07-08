
    

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
                    
                 
                   
            printf("X M T A A A J J S U R S X M I<br>");
            printf("J A F H <span class=\"mercurio %s \">M</span> M S <span class=\"jupiter %s\">R</span> M I R L <span class=\"venus %s\">S</span> B D<br>", mercurio, jupiter, venus);
            printf("E M G J X <span class=\"mercurio %s \">E</span> K S <span class=\"jupiter %s\">E</span> F C R U <span class=\"venus %s\">U</span> M E<br>", mercurio, jupiter, venus);
            printf("S <span class=\"saturno %s\">S</span> B X O A <span class=\"mercurio %s \">R</span> Z S <span class=\"jupiter %s\">T</span> E I <span class=\"venus %s\">N</span> X S<br>", saturno, mercurio, jupiter, venus);
            printf("U <span class=\"saturno %s\">A</span> L F T J K <span class=\"mercurio %s \">C</span> K R <span class=\"jupiter %s\">I</span> X <span class=\"venus %s\">E</span> S P<br>",saturno, mercurio, jupiter, venus);
            printf("T <span class=\"saturno %s\">T</span> J V T J E U <span class=\"mercurio %s \">U</span> U U <span class=\"jupiter %s\">P</span> <span class=\"venus %s\">V</span> Z U<br>");
            printf("Y <span class=\"saturno %s\">U</span> L V E C E Z F <span class=\"mercurio %s \">R</span> Q G <span class=\"jupiter %s\">U</span> C I<br>", saturno, mercurio, jupiter);
            printf("B <span class=\"saturno %s\">R</span> N K M K F C J K <span class=\"mercurio %s \">I</span> N I <span class=\"jupiter %s\">J</span> Z<br>", saturno, mercurio, jupiter);
            printf("U <span class=\"saturno %s\">N</span> C L M G W A M B O <span class=\"mercurio %s \">O</span> U Q G<br>", saturno, mercurio);
            printf("Q <span class=\"saturno %s\">O</span> W B <span class=\"terra %s\">A R R E T</span> L F I <span class=\"plutao %s\">P</span> Q R<br>",saturno, terra, plutao);
            printf("S Q D D M R N R Q R Z <span class=\"plutao %s\">L</span> V Q C<br>",plutao);
            printf("B D O H K T W W I M <span class=\"plutao %s\">U</span> I F J K<br>",plutao);
            printf("L N X Y L K T V T <span class=\"plutao %s\">T</span> L A Q H Q<br>",plutao);
            printf("X O <span class=\"marte %s\">M A R T E</span> X <span class=\"plutao %s\">A</span> K A P E T A<br>",marte);
            printf("E T Q S K Z N <span class=\"plutao %s\">O</span> U I G S E U B<br>",plutao);
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
