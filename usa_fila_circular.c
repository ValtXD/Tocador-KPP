#include "stdio.h"
#include "stdlib.h"
#include "string.h" 
#include "filacircular.h"
#include "musica.h"

int main(int argc, char const *argv[])
{  
char nome[60]; 
char genero[30];
  
     int duracao;
     t_fila_circular *playlist = criar_fila_circular(10);
     scanf("%s", nome);

     while(strcmp(nome,"FIM")!=0){
       
         scanf("%s", genero);
         scanf("%d", &duracao);
        
         enfileirar_fila_circular(playlist, criar_musica(nome,genero,duracao));

         scanf("%s", nome);
    }
     t_musica* m = primeiro_fila_circular(playlist);
     imprimir_musica(m);
  
     m = desenfileirar_fila_circular(playlist);
     free(m);

     scanf("%s", nome);
     scanf("%s", genero);
     scanf("%d", &duracao);

     enfileirar_fila_circular(playlist, criar_musica(nome,genero,duracao));

    printf("ocupação: %d\n", ocupacao_fila_circular(playlist));
}
   