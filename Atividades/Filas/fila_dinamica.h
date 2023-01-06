#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int conteudo;
  struct elem *prox;
} paciente;

void enqueue(paciente **last, paciente *e, paciente **first = NULL) {
  e->prox = NULL;
  if (*last == NULL) {
    *first = e;
    *last = e;
    return;
  }
  (*last)->prox = e;
  *last = e;
}

paciente *dequeue(paciente **first, paciente **last = NULL) {
  if (*first == NULL) {
    return NULL;
  }
  paciente *front = *first;
  (*first) = (*first)->prox;
  if (*first == NULL) {
    *last == NULL;
  }
  front->prox = NULL;
  return front;
}

void print(paciente *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

int size(paciente *aux) {
  int s = 0;
  while (aux != NULL) {
    s++;
    aux = aux->prox;
  }
  return s;
}

void clear(paciente **first) {
  paciente *aux = dequeue(first);
  while (aux != NULL) {
    // free(aux);
    aux = dequeue(first);
  }
}

int position(paciente *aux, paciente *e) {
  int s = 0;
  while (aux != NULL) {
    s++;
    if (e->conteudo == aux->conteudo) {
      return s;
    }
    aux = aux->prox;
  }
  return -1;
}

bool is_empty(paciente *first) {
  return (first == NULL);
  //   if (top == NULL) {
  //     return true;
  //   } else {
  //     return false;
  //   }
}