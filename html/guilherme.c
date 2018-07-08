//inclusao de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//constantes globais
#define tam_max 10000

//protótipos
void tipo_conteudo(char *);
void input(char *, char *, char *);
void imprimir_arquivo(char *);

int main()
{
    // Declarações
    int quantidade_parametros, i, disporEncontrados = 0, qtdPalavrasEncontradas = 0;
    char palavraraw[tam_max], palavra[tam_max], encontradosraw[tam_max], encontrados[tam_max], * ptr, query[tam_max], **palavrasEncontradas;
    char solucaoFrutas[tam_max]="jabuticaba/uva/banana/mamao/manga/amendoa/melancia/guarana/goiaba/ameixa/acerola/roma/caju/caqui/kiwi/cacau/melao/maracuja";

    //Inicialização de string para evitar bugs de memória
    palavra[0] = '\0';
    encontradosraw[0] = '\0';

    // Definindo tipo de conteúdo
    tipo_conteudo("HTML");

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
    //imprimindo a parte superior da pagina html
    imprimir_arquivo("up-code.html");

    //estilizando as palavras encontradas
    if(strstr(solucaoFrutas, palavra)!=NULL){
        printf("#%s-found{", palavra);
        printf("font-weight: bold;\n");
        printf("color: red\n");
        printf("}\n\n");

        printf(".%s-escondido{", palavra);
        printf("font-size: 18px;\n");
        printf("}\n\n");

        printf("#%s-box{", palavra);
        printf("text-decoration: line-through;\n");
        printf("}\n");
    }

    for(i=0;i<qtdPalavrasEncontradas;i++)
        if(strstr(solucaoFrutas, palavrasEncontradas[i])!=NULL)
        {
            printf("#%s-found{", palavrasEncontradas[i]);
            printf("font-weight: bold;\n");
            printf("color: red\n");
            printf("}\n\n"); 

            printf(".%s-escondido{", palavrasEncontradas[i]);
            printf("font-size: 16px;\n");
            printf("}\n\n");

            printf("#%s-box{", palavrasEncontradas[i]);
            printf("text-decoration: line-through;\n");
            printf("}\n");
        }

    //imprimindo a parte intermediaria da pagina html
    imprimir_arquivo("mid-code.html");

    //colocando as palavras encontradas como um input escondido
    if(disporEncontrados){
        input("hidden", "encontrados", encontrados);
    }

    //imprimindo a parte inferior da pagina html
    imprimir_arquivo("down-code.html");

    return 0;
}

//Objetivo: Imprimir o tipo de conteúdo da pagina (em geral, HTML)
//Parametros formais: Ponteiro para uma string com o tipo do conteúdo
//Saída: --
void tipo_conteudo(char * content_type){
    printf("Content-type: %s\n\n", content_type);
}

//Objetivo: Imprimir o input de um formulario em HTML
//Parametros formais: Ponteiros para tres strings, tipo, nome e valor do input, respectivamente
//Saída: --
void input(char * type, char * name, char * value){
    printf("<input type=\"%s\" name=\"%s\" value=\"%s\" />", type, name, value);
}

//Objetivo: Imprimir um arquivo (em geral, a pagina HTMl_)
//Parametros formais: Ponteiro para o nome do arquivo a ser impresso
//Saída: --
void imprimir_arquivo(char * filename){
    FILE * arquivo = fopen(filename, "r");
    char * line = NULL;
    int read;
    size_t len = 0;

    while((read = getline(&line, &len, arquivo)) != -1)
        printf("%s", line);
}
