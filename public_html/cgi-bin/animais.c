#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000


void imprimir_arquivo(char *);


int main (int argc, char *argv[]){

    int i,
        foundDispor = 0,
        foundQtd = 0;

    char *ptr=NULL,
         *achou,
         **foundLista,
         palavraBruta[MAX],
         palavra[MAX],
         foundBruto[MAX],
         found[MAX],
         query[MAX],
         ref[MAX]={"MACACO\nGATO\nPATO\nCOELHO\nTIGRE\nVEADO\nLAGOSTA\0"};

    palavra[0] = '\0';
    foundBruto[0]='\0';
    found[0]='0';


    // Definindo tipo de conteúdo
    printf("Content-type: text/html\n\n");

    // Pegando os parametros
    strcpy(query, getenv("QUERY_STRING"));


    // Se parametros tiverem conteudo
    if(strcmp(query, "") != 0){
        
        // Corta parametros no & e atribui anterior pra palavras 
        ptr = strtok(query, "&");
        strcpy(palavraBruta, ptr);

        // Depois, se tiver conteudo, atribui parte posterior pra found
        ptr = strtok(NULL, "&");
        if (ptr != NULL)
        strcpy(foundBruto, ptr);

    

        // Refina palavra
        strtok(palavraBruta, "=");
        ptr = strtok(NULL, "=");
        strcpy(palavra, ptr);


        // Refina found
        ptr = strtok(foundBruto, "=");
        if (ptr != NULL){
            ptr = strtok(NULL, "=");
            strcpy(found, ptr);
        }

        if (strlen(foundBruto)){
            int count = 1,
                tam_temp;
            char foundCopia[1000];

            strcpy(foundCopia, found);

            for (i = 0; i < strlen(found); i++){
                if (found[i] == '.'){
                    count++;
                }
            }
            
            foundLista = (char **)malloc(sizeof(char *) * count);

            // Inserirndo a primeira palavra
            ptr = strtok(foundCopia, ".");
            tam_temp = strlen(ptr);
            foundLista[0] = (char *)malloc(sizeof(char) * tam_temp);
            strcpy(foundLista[0], ptr);

            // Intserindo as demais palavras
            for (i = 1; i < count; i++){
                ptr = strtok(NULL, ".");
                tam_temp = strlen(ptr);
                foundLista[i] = (char *)malloc(sizeof(char) * tam_temp);
                strcpy(foundLista[i], ptr);
            }

            foundQtd = count;

        }

        foundDispor = 1;
        
        
        // Comparar palavra com string referencia
        achou = strstr(ref, palavra);
        if(achou!=NULL){
            strcat(found, ".");
            strcat(found, palavra);
        }
        

    }





    //===================INICIO-HTML=========================

    imprimir_arquivo("animais1.html");
    printf("<br>");

    printf("<hr>");
    if (strlen(palavra)){
        printf("<div class='palavra'>%s</div>", palavra);
    }

    printf("<style>");
    if(foundQtd){
        for (i = 0; i < foundQtd; i++){
            printf(".%s{", foundLista[i]);
            printf("color: #FD5B78;");
            printf("animation-name: example;");
            printf("animation-duration: 1s;");
            printf("animation-iteration-count: infinite;");
            printf("}");
        }
    }
    if(achou!=NULL){
        printf(".%s{", palavra);
        printf("color: #FD5B78;");
        printf("animation-name: example;");
        printf("animation-duration: 1s;");
        printf("animation-iteration-count: infinite;");
        printf("}");
    }
    printf("</style>");

    if (foundDispor){
        printf("<input type='hidden' name='encontradas' value='%s' />", found);
    }

    imprimir_arquivo("footer.html");

    //===================FINAL-HTML==========================


    return 0;
}



// Objetivo: Imprimir os arquivos html
// Parâmetros Formais:
// - filename: string com nome do arquivo (entrada de dados)
// Valor de Retorno: não há (procedimento)
void imprimir_arquivo(char *filename){

    FILE *arquivo = fopen(filename, "r");

    char *line = NULL;

    int read;

    size_t len = 0;

    while ((getline(&line, &len, arquivo)) != -1){
        printf("%s", line);
    }

    return;
}