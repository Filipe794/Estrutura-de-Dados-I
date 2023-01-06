#include <stdio.h>
#include <stdlib.h>
#include "lista dupla.h"

int main()
{
  int valor;
  celula *c = NULL;
  scanf("%d",&valor);
  inseririnicio(&c, valor);
  inseririnicio(&c, 6);
  inseririnicio(&c, 7);
  inserirfim(&c, 10);
  inserirfim(&c, 11);
  inserirmeio(&c, 10, 6);
  imprimir(c);

  return 0;
}