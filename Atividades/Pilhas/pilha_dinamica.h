#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int conteudo;
  struct elem *prox;
} paciente;

void push(paciente **top, paciente *e) {
  e->prox = *top;
  *top = e;
}

paciente *pop(paciente **top) {
  if (*top == NULL) {
    return NULL;
  }
  paciente *p = *top;
  *top = (*top)->prox;
  p->prox = NULL;
  return p;
}

void print(paciente *aux) {
  while (aux != NULL) {
    printf("%d\n", aux->conteudo);
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

void clear(paciente **top) {
  paciente *aux = pop(top);
  while (aux != NULL) {
    // free(aux);
    aux = pop(top);
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

bool is_empty(paciente *top) {
  return (top == NULL);
  //   if (top == NULL) {
  //     return true;
  //   } else {
  //     return false;
  //   }
}
