        #include <stdio.h>
        #include <string.h>
        #include "funcoes.c"
        int main(){ 
            char * palavra = NULL;
            int numeroPalavrass, i, encontrada=0;
            char lagosta[20];
            char tigre[20];
            char veado[20];
            char gato[20];
            char coelho[20];
            char macaco[20];
            char pato[20];

            lagosta = NULL;

            palavra=getenv("QUERY_STRING");

            for(i=0; i<numeroPalavrass; i++){
                if (strcmp(palavra,lista[i])==0){
                    encontrada=1;
                    break;
                }
            }





            if (encontrada){
                lagosta = "found";
                print("Content-Type:text/html\n\n");
                    
                 printf("<!DOCTYPE html>");
                    printf("<html>");
                    printf("<head>");
                        printf("<meta charset="utf-8" />");
                        printf("<meta http-equiv="X-UA-Compatible" content="IE=edge">");
                        printf("<meta name="viewport" content="width=device-width, initial-scale=1">");
                        printf("<title>Caça Palavras Boladex - Animais</title>");
                        printf("<link rel="icon" href="../imgs/cifferi.png">");
                        printf("<link rel="stylesheet" type="text/css" media="screen" href="../estilos/jogo.css" />");
                        printf("<link href="https://fonts.googleapis.com/css?family=Amatic+SC" rel="stylesheet">")
                        printf("<script src="jogo.js"></script>")
                    printf("</head>")
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
                            printf("</div>
                            printf("<br>
                            printf("<br>    
                            printf("</div>
                                printf("<form method="get">
                                    printf("Digite a palavra: <input type="text" name="palavra">
                                    printf("<button type="submit" value="Submit">Submit</button>
                                printf("</form>
                            printf("<h2><a href="../html/tela1.html">Voltar</a><h2>
                        printf("</main>
                    printf("</body>
                    printf("</html>
            return 0;
        }


        <div class = "found"> banana </div>