#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

    // Retornar a posição de um elemento da lista
    int busca(celula *cabeca, int valor) {
    celula *tmp = cabeca;
    int cont=1;
    while (tmp->conteudo != valor) {
        tmp = tmp->prox;
        cont++;
    }
    return cont;
    }

void imprimir(celula *cabeca) {
  // for (celula *tmp = cabeca; tmp != NULL; tmp = tmp->prox) {
  //   printf("%d -> ", tmp->conteudo);
  // }
  celula *tmp = cabeca;
  while (tmp != NULL) {
    printf("%d -> ", tmp->conteudo);
    tmp = tmp->prox;
  }
  printf("NULL\n");
}

celula *inserir_inicio(celula *cabeca, celula *Nova) {
  Nova->prox = cabeca;
  cabeca = Nova;
  return cabeca;
}

void inserir_fim(celula *cabeca, celula *Nova) {

  celula *ultima = cabeca;
  while (ultima->prox != NULL) {
    ultima = ultima->prox;
  }

  Nova->prox = ultima->prox;
  ultima->prox = Nova;
}

void inserir_inicio2(celula **ptr, celula *Nova) {
  Nova->prox = *ptr;
  *ptr = Nova;
}

void busca(celula *cabeca, int valor) {
  celula *tmp = cabeca;
  while (tmp != NULL) {
    if (tmp->conteudo == valor) {
      printf("Encontrei %d\n", valor);
      return;
    }
    tmp = tmp->prox;
  }
  printf("Não encontrei\n");
}

void remover(celula *cabeca, celula *rem) {
  celula *ant = cabeca;
  while (ant->prox != rem) {
    ant = ant->prox;
  }
  ant->prox=rem->prox;
}

int main(){
    celula *Nova;
    celula *cabeca;
    int *ptr_cabeca;

    // Inserindo No inicio
    Nova->prox = *ptr_cabeca;
    *ptr_cabeca=Nova;

    // Inserindo No final
    celula *ultima;
    Nova->prox = NULL;
    ultima->prox=Nova;

    // Inserindo No meio
    celula *meio;
    Nova->prox = meio->prox;
    meio->prox= Nova;

    // Imprimindo
    celula *aux = cabeca;
    while(aux!=NULL){
        printf("conteudo: %d\n", aux->conteudo);
        aux=aux->prox;
    }

    // Buscando elemento
    celula *aux = cabeca;
    int valor;
    while (aux != NULL) {
        if (aux->conteudo == valor){
            return aux; //"Elemento encontrado"
        }
        aux = aux->prox;
    }
    return NULL; //"Elemento não encontrado"

    // Removendo elemento
    celula *aux = cabeca;
    celula *rem;
    while (aux != NULL) {
        if (aux->prox == rem) {
            aux->prox = rem->prox;
            free(rem);
        }
        aux = aux->prox;
    }
}
