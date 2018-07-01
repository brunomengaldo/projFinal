#define HTML "text/html"

/* Structure Types */
typedef struct {
    char nome[1000];
    char valor[1000];
} Param;

void input(char * name, char * value){
    printf("<input name=\"%s\" value=\"%s\" />", name, value);
}



int dividir_string(char * string, char * delimiter, char *** list){
    char string_copy[1000], * aux, * ptr;
    int i, matches = 1, init_len, token_len;
    init_len = strlen(string);
    
    // Verificar tamanho
    for(i = 0; i < init_len; i++)
        if(string[i] == *delimiter)
            matches++;
    *list = (char **) malloc(matches * sizeof(char *));
    i = 0;

    strcpy(string_copy, string);
    ptr = strtok(string_copy, delimiter);
    token_len = strlen(ptr);
    (*list)[i] = (char*) malloc(sizeof(char) * token_len);
    strcpy((*list)[i++], ptr);

    while(ptr != NULL){
        ptr = strtok(NULL, delimiter);
        if(ptr == NULL) break;
        token_len = strlen(ptr);
        (*list)[i] = (char*) malloc(sizeof(char) * token_len);
        strcpy((*list)[i++], ptr);
    }

    return matches;
}



void tipo_conteudo(char * content_type){
    printf("Content-type: %s\n\n", content_type);
}


void imprimir_arquivo(char * filename){
    FILE * arquivo = fopen(filename, "r");
    char * line = NULL;
    int read;
    size_t len = 0;

    while((read = getline(&line, &len, arquivo)) != -1)
        printf("%s", line);
}


int pegar_parametros(Param ** parametros){
    char ** params = NULL;
    int count, i;
    count = dividir_string(getenv("QUERY_STRING"), "&", &params);
    *parametros = (Param *) malloc( count * sizeof(Param));
    for(i = 0; i < count; i++){
        char ** single = NULL;
        dividir_string(params[i], "=", &single);
        Param singleParam;
        strcpy(singleParam.nome, single[0]);
        strcpy(singleParam.valor, single[1]);
        (*parametros)[i] = singleParam;
    }
    return count;
}