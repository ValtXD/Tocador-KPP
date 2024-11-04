#include <stdio.h>
#include "stdlib.h"
#include "filacircular.h"

typedef struct f_circular t_fila_circular;
struct f_circular{
void* *elementos;
int frente;
int atras;
int tamanho;
};

t_fila_circular* criar_fila_circular(int tam){
  t_fila_circular* fc = malloc(sizeof(t_fila_circular));
  fc -> elementos = malloc(sizeof(void*)*tam);
  fc -> frente = -1;
  fc -> atras = -1;
  fc -> tamanho = tam;

  return fc;

}

int vazia_fila_circular(t_fila_circular* fc){
  return (fc -> frente == -1);
}

//ocupacao_fila_circular: retorna a quantidade de elementos da fila circular
int ocupacao_fila_circular(t_fila_circular* fc){
    if (fc -> frente < fc -> atras) {
        return (fc -> atras - fc -> frente) + 1;
    } else {
        return (fc -> tamanho - fc -> frente) + fc -> atras + 1;
    }
  }

short enfileirar_fila_circular(t_fila_circular* fc, void* novo){
  if(ocupacao_fila_circular(fc) == fc -> tamanho){
    return 0;
  }

  if(vazia_fila_circular(fc)){
    fc -> frente = 0;
    fc -> atras = 0;
    //fc -> elementos[0] = novo;
  }else{
    fc -> atras = (fc -> atras + 1) % fc -> tamanho;
  }
  fc -> elementos[fc -> atras] = novo;
  
  return 1; //verdade
}

void* desenfileirar_fila_circular(t_fila_circular* fc){
    void* elem = NULL;
    if (vazia_fila_circular(fc)){
      return NULL;
    }else if(ocupacao_fila_circular(fc)==1){
      elem = fc -> elementos[fc -> frente];
      fc->frente = -1;
      fc->atras = -1;
    }else{
        elem = fc -> elementos[fc -> frente];
        fc->frente = (fc->frente + 1) % fc->tamanho;
    }
    return elem;
}

void* primeiro_fila_circular(t_fila_circular* fc){
  void* elem = NULL;
  if(!vazia_fila_circular(fc)){
    elem = fc -> elementos[fc -> frente];
  }
  return elem;
}

//void*: retorna o elemento que está no início da fila circular
//void avancar_fila_circular(t_fila_circular* fc){

//}

