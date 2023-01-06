#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cel
{
  int conteudo;
  struct cel *prox;
  struct cel *ant;

} celula;



void inserirfim(celula **head, int valor)
{
  celula *aux = *head;
  celula *Nova = (celula *)malloc(sizeof(celula));
  Nova->conteudo = valor;
  Nova->prox = NULL;
  if (*head == NULL)
  {
    *head = Nova;
    Nova->ant = NULL;
  }
  else
  {
    while (aux->prox != NULL)
    {

      aux = aux->prox;
    }

    aux->prox = Nova;
    Nova->ant = aux;
  }
}

void inserirmeio(celula **head, int valor, int ref)
{
  celula *aux = *head;
  celula *Nova = (celula *)malloc(sizeof(celula));
  Nova->conteudo = valor;
  if (*head == NULL)
  {
    Nova->prox = NULL;
    Nova->ant = NULL;
    *head = Nova;
  }
  else
  {
    while (aux->conteudo != ref && aux->prox != NULL)
    {
      aux = aux->prox;
    }
    Nova->prox = aux->prox;
    if (aux->prox != NULL)
    {
      aux->prox->ant = Nova;
    }
    Nova->ant = aux;
    aux->prox = Nova;
  }
}

void concatenar(celula *head, celula *head2)
{
  celula *aux = head;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }
  aux->prox = head2;
  head2->ant = aux;
}

void imprimir(celula *aux)
{
  while (aux != NULL)
  {
    printf("%d->", aux->conteudo);
    aux = aux->prox;
  }
}


int tamanho(celula *cabeca) {
  if (cabeca == NULL) {
    return 0;
  }
int tam = 0;
  celula *aux = cabeca;
  while (aux != NULL){
    tam++; 
    aux = aux->prox;
  }
  return tam;
}

celula *metade(celula *cabeca1) {
  int tam_total = tamanho(cabeca1);
  if (tam_total == 1) {
    return NULL;
  }
  
 int tam1 = ceil(tam_total / 2.0f);
  printf("TAM1: %d\n", tam1);

  celula *cabeca2 = NULL;

  celula *aux = cabeca1;
  int i = 0;
  while (i < tam1 - 1) {
    aux = aux->prox;
    i++;
  }

  cabeca2 = aux->prox;
  aux->prox = NULL;
  cabeca2->ant = NULL;

  return cabeca2;
}

celula *ultimo(celula *aux) {
  if (aux == NULL) {
    return NULL;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  return aux;
}

void troca(celula *elem1, celula *elem2) {
  celula *prim = elem1->ant;
  celula *ult = elem2->prox;

  prim->prox = elem2;
  ult->ant = elem1;
  elem2->prox = elem1;
  elem1->prox = ult;
  elem1->ant = elem2;
  elem2->ant = prim;
}

void inseririnicio(celula **ptrhead, int valor)
{
  celula *Nova = (celula *)malloc(sizeof(celula));
  Nova->conteudo = valor;
  Nova->prox = *ptrhead;
  Nova->ant = NULL;
  if (*ptrhead != NULL)
  {
    (*ptrhead)->ant = Nova;
  }

  *ptrhead = Nova;
}









