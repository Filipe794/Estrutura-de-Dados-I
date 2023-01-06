#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct cel
{
  char Nome[100];
  struct cel *prox;
  struct cel *ant;
} celula;

/*
void remover(celula *cabeca){

    celula *aux = cabeca; // ponteiro para o início da lista
    celula *NoARemover = NULL;      // ponteiro para o nó a ser removido
    celula *ref;

    printf("Insira o aluNo a ser removido: ");
    scanf("%100[^\n]s",ref->Nome);

    if (aux != NULL && aux->Nome == valor){ // remover 1º elemento
        NoARemover = lista->inicio;
        lista->inicio = NoARemover->proximo;
        if (lista->inicio == NULL)
            lista->fim = NULL;
    }
    else{ // remoção No meio ou No final
        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor)
        {
            inicio = inicio->proximo;
        }
        if (inicio != NULL && inicio->proximo != NULL)
        {
            NoARemover = inicio->proximo;
            inicio->proximo = NoARemover->proximo;
            if (inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if (NoARemover){
        free(NoARemover); // libera a memória do nó
        lista->tam--;     // decrementa o tamanho da lista
    }
}
*/


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


void inserir_inicio(celula **ptrhead)
{
  celula *Nova = (celula *)malloc(sizeof(celula));
  printf("Insira o Nome do aluNo: ");
  fflush(stdin);
  scanf("%100[^\n]s",Nova->Nome);
  Nova->prox = *ptrhead;
  Nova->ant = NULL;
  if (*ptrhead != NULL)
  {
    (*ptrhead)->ant = Nova;
  }

  *ptrhead = Nova;
}



void imprimir(celula *aux)
{
  while (aux != NULL)
  {
    printf("%s\n", aux->Nome);
    aux = aux->prox;
  }
}


void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir aluNos\t*\n");
  printf("*\t2 - Sortear\t*\n");
  printf("*\t3 - Remover aluNo\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

void sorteio(celula *cabeca){
  int tam = tamanho(cabeca);
  printf("tamanho: %d",tam);
   time_t t;
   srand(time(&t));
  int posicao= (rand() % tam);
  printf("%d",posicao);
}