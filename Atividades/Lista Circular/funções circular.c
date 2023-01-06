#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

//achar ultimo elemento da lista
celula *ultimo(celula *head) {
  if (head == NULL) return NULL;
  celula *tail = head;
  while (tail->prox != head) {
    tail = tail->prox;
  }
  return tail;
}

void remover(celula **head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->prox == *head) {
    free(*head);
    *head = NULL;
    return;
  }

  celula *tail = ultimo(*head);
  tail->prox = (*head)->prox;
  free(*head);
  *head = tail->prox;
}

void inserir(celula **head, int valor) {
  celula *Nova = (celula *)malloc(sizeof(celula));
  Nova->conteudo = valor;

  if (*head == NULL) {
    *head = Nova;
    Nova->prox = *head;
    return;
  }

  Nova->prox = *head;
  celula *tail = ultimo(*head);
  tail->prox = Nova;
  *head = Nova;
}

void imprimir(celula *head) {
  celula *aux = head;
  if (aux != NULL) {
    while (aux->prox != head) {
      printf("%d -> ", aux->conteudo);
      aux = aux->prox;
    }
    printf("%d -> ", aux->conteudo);
  }
  printf("HEAD\n");
}

int main(int argc, char const *argv[]) {
  celula *cabeca = NULL;

  imprimir(cabeca);
  inserir(&cabeca, 3);
  imprimir(cabeca);
  inserir(&cabeca, 2);
  imprimir(cabeca);
  inserir(&cabeca, 1);

  imprimir(cabeca);

  remover(&cabeca);
  imprimir(cabeca);
  remover(&cabeca);
  imprimir(cabeca);
  remover(&cabeca);
  imprimir(cabeca);

  return 0;
}