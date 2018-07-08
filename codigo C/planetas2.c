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
                    
                 
                   
          printf("T J R H D J U K T P F K P T M<br>");
          printf("<span class=\"jupiter %s\">J U P I T E R</span> R K K C P <span class=\"mercurio %s\">M</span> T L<br>",jupiter, mercurio);
          printf("P I H T E X L E Q Q N Z <span class=\"mercurio %s\">E</span> N H<br>", mercurio);
          printf("L <span class=\"venus %s\">V</span> S V O S U G B X U Q <span class=\"mercurio %s\">R</span> C B<br>", venus, mercurio);
          printf("B K <span class=\"venus %s\">E</span> D T M L K S H P S <span class=\"mercurio %s\">C</span> C J<br>", venus, mercurio);
          printf("G E T <span class=\"venus %s\">N</span> O O I H H Z X L <span class=\"mercurio %s\">U</span> B E<br>", venus, mercurio);
          printf("Z H G M <span class=\"venus %s\">U</span> Q L N J Q K W <span class=\"mercurio %s\">R</span> U S<br>", venus, mercurio);
          printf("<span class=\"terra %s\">A</span> L N E S <span class=\"venus %s\">S</span> S E R D Q U <span class=\"mercurio %s\">I</span> L Q<br>", terra, venus, mercurio);
          printf("T <span class=\"terra %s\">R</span> M A U N U R Z U F F <span class=\"mercurio %s\">O</span> T U<br>", terra, mercurio);
          printf("D Z <span class=\"terra %s\">R</span> U J F C M D C V Y G U Y<br>", terra);
          printf("Y F H <span class=\"terra %s\">E</span> K R M K <span class=\"saturno %s\">O N R U T A S</span><br>", terra, saturno);
          printf("V K C E <span class=\"terra %s\">T</span> C O R Q I C Z A I R<br>", terra);
          printf("A Y Q Z I P Q I G A F F N L F<br>");
          printf("Q L F Q J R L <span class=\"plutao %s\">P L U T A O</span> E G<br>",plutao);
          printf("K <span class=\"marte %s\">M A R T E</span> N Z V V U D T W X<br>", marte);
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
