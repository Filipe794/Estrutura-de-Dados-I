#include <stdio.h>

typedef struct{
    int conteudo;
    celula *prox;
    celula *ant;
}celula;

void troca(celula *elem1,celula *elem2){
    

}

int main(int argc, char const *argv[]) {
  celula c1;
  celula c2;
  celula c3;
  celula c4;
  celula c5;

  c1.conteudo = 1;
  c2.conteudo = 2;
  c3.conteudo = 3;
  c4.conteudo = 4;
  c5.conteudo = 5;

  c1.ant = NULL;
  c1.prox = &c2;
  c2.ant = &c1;
  c2.prox = &c3;
  c3.ant = &c2;
  c3.prox = &c4;

  c4.ant = &c3;
  c4.prox = &c5;
  c5.ant = &c4;
  c5.prox = NULL;
  celula *cabeca1 = &c1;

  

  return 0;
}