#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

paciente *inverso(paciente **top) {
  int tam = size(*top);
  paciente *top_2 = NULL;
  if(*top==NULL) return;
  for (int i = 1; i <= tam; i++) {
    push(&top_2, pop(top));
  }
  return top_2;
}

int main() {
  paciente *top = NULL;
  int tam;
  printf("qual o tamanho da pilha?");
  scanf("%d",&tam);
  for (int i = 1; i <= tam; i++) {
    paciente *e = (paciente *)malloc(sizeof(paciente));
    printf("Insira um valor: ");
    scanf("%d", &e->conteudo);
     push(&top, e);
  }
  print(top);
  paciente *top_2 = inverso(&top);
  print(top_2);
  return 0;
}