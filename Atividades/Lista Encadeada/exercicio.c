#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cel
{
  int conteudo;
  struct cel *prox;
} celula;

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

int retorna_posicao(celula *cabeca, int valor){
  celula *tmp = cabeca;
  int cont = 0;
  while (tmp != NULL){
  if(tmp->conteudo==valor){
    return cont;
  }
    tmp = tmp->prox;
    cont++;
  }
  return -1;
}

celula *troca_proxima(celula *cabeca, int valor){
  celula *cel = cabeca;
  celula *ant=NULL;
  celula *prox=NULL;

  if(cel->conteudo==valor){
    if(cel->prox==NULL){
      printf("nao existe proximo");
      return cabeca;
    } else{
      prox=cel->prox;
    cel->prox=prox-prox;
    prox->prox=cel;
    return prox;
    }
  }

  while ((cel != NULL)&&(cel->prox!=NULL)){
    if ((cel->conteudo == valor)){
      ant->prox=prox;
      cel->prox=prox->prox;
      prox->prox=cel;
      return cabeca;
    }
    ant=cel;
    cel=cel->prox;
    prox=cel->prox;
    return cabeca;
  }
}


// função tamanho

int tamanho(celula *cabeca) {
  if (cabeca == NULL) {
    return 0;
  }

  int tam = 0;
  celula *aux = cabeca;
  while (aux != NULL) {
    aux = aux->prox;
    tam++;
  }
  return tam;
}

void concatenar(celula *cabeca_1, celula *cabeca_2){
 celula *tmp=cabeca_1;
 while(tmp!=NULL){
   if((tmp->prox==NULL)){
     tmp->prox=cabeca_2;
     return;
   }
   tmp=tmp->prox;
 }
}
void concatenar_2(){ 
}
int main()
{

  celula c1;
  celula c2;
  celula c3;
  celula c4;
  celula c5;

  celula *head = &c1;

  c1.conteudo = 1;
  c2.conteudo = 2;
  c3.conteudo = 3;
  c4.conteudo = 4;
  c5.conteudo = 5;

  c1.prox = &c2;
  c2.prox = &c3;
  c3.prox = &c4;
  c4.prox = &c5;
  c5.prox = NULL;

  /*celula *tmp = head;
  while (tmp != NULL)
  {
    printf("%d -> ", tmp->conteudo);
    tmp = tmp->prox;
  }
  printf("NULL\n");*/

  // achar um valor

  /*printf("insira o valor a ser procurado: ");
  scanf("%d",&valor);
  printf("o valor %d esta na posicao %d",valor,busca(head,valor));*/

  /* trocar a posição com o proximo

  printf("insira o valor a ser procurado: ");
  scanf("%d",&valor);
  troca(head,valor); */

  celula b1;

  celula b2;
  celula b3;
  celula b4;
  celula b5;

  celula *head2 = &b1;
  b1.conteudo = 10;
  b2.conteudo = 11;
  b3.conteudo = 12;
  b4.conteudo = 13;
  b5.conteudo = 14;

  b1.prox = &b2;
  b2.prox = &b3;
  b3.prox = &b4;
  b4.prox = &b5;
  b5.prox = NULL;
  
  
  imprimir(head);
  imprimir(head2);
  
  concatenar(head,head2);
  imprimir(head);

  celula *cabeca2=metade(head);





  return 0;
}

/*
--------concatenar-----------
ultimo_lista_1.prox=head2;
head2=NULL;

---------dividireita em duas------
celular *head2;
head2=divisor.prox;

---------reverter-------------

while(celula.prox!=NULL){
  if(celula.prox=NULL){
    head=&celula
  }
  else{
    armazenar endereço de cada posição e reverter
  }
}
*/

/*celula *tmp=cabeca_1;
  while(tmp->prox!=NULL){
    if((tmp->prox=NULL)){
      tmp->prox=cabeca_2;
      return;
    }
    tmp=tmp->prox;
  }

    printf("\ndepois da contatencacao\n");
    while (tmp != NULL) {
      printf("%d -> ", tmp->conteudo);
      tmp = tmp->prox;
    }*/