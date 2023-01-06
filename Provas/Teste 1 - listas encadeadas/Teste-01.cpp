#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct cel {
  char Nome[30];
  int quantidade_estoque;
  int quantidade_minima;
  float preco;
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("PRODUTO: %s\n", aux->Nome);
    printf("PRECO: %.2f\n",aux->preco);
    printf("QUANTIDADE EM ESTOQUE: %d\n",aux->quantidade_estoque);
    printf("QUANTIDADE MINIMA: %d\n",aux->quantidade_minima);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir(celula **ptr_cabeca) {
  celula *Nova = (celula *)malloc(sizeof(celula));

  printf("Digite o Nome do produto: ");
  scanf("%30[^\n]s", Nova->Nome);

  printf("Digite a quantidade No estoque do produto: ");
  scanf("%d", &Nova->quantidade_estoque);

  printf("Digite a quantidade minima do produto: ");
  scanf("%d", &Nova->quantidade_minima);

  printf("Digite o preco do produto: ");
  scanf("%f", &Nova->preco);
  
  Nova->prox = *ptr_cabeca;
  *ptr_cabeca = Nova;
}

void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir produto\t*\n");
  printf("*\t2 - Imprimir produtos\t*\n");
  printf("*\t3 - Calcular valor total dos produtos\t*\n");
  printf("*\t4 - Calcular valor médio dos produtos\t*\n");
  printf("*\t5 - Dividireita a lista em duas\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

float valor_total(celula *cabeca){
  if (cabeca == NULL) {
    printf("a lista está vazia\n");
    return 0;
  }
  float soma=0.0;
  celula *aux = cabeca;
  while (aux != NULL) {
    soma=soma+(aux->preco*aux->quantidade_estoque);
    aux = aux->prox;
  }
  return soma;
}

float valor_medio(celula *cabeca){
  if (cabeca == NULL) {
    printf("a lista está vazia\n");
    return 0;
  }
  float soma=0.0;
  float cont=0.0;
  celula *aux = cabeca;
  while (aux != NULL) {
    soma=soma+(aux->preco);
    aux = aux->prox;
    cont++;
  }
  return soma/cont;
}

celula *dividireita_lista(celula *aux, char Nome[30]){
  celula *Nova = (celula *)malloc(sizeof(celula));
  while (aux !=NULL) {
    if(strcmp(Nome,aux->Nome)!=0){
      Nova=aux->prox;
      aux->prox=NULL;
    }
    aux = aux->prox;
  }
  return Nova;
}

void inserir_ordenado(celula **ptr_cabeca,celula *cabeca) {
  celula *Nova = (celula *)malloc(sizeof(celula));
  celula *aux = cabeca;

  printf("Digite o Nome do produto: ");
  scanf("%30[^\n]s", Nova->Nome);

  printf("Digite a quantidade No estoque do produto: ");
  scanf("%d", &Nova->quantidade_estoque);

  printf("Digite a quantidade minima do produto: ");
  scanf("%d", &Nova->quantidade_minima);

  printf("Digite o preco do produto: ");
  scanf("%f", &Nova->preco);

  while (aux !=NULL) {
    if(strcmp(Nova->Nome,aux->prox->Nome)!=0){
      Nova=aux->prox;
      aux->prox=NULL;
    }
    aux = aux->prox;
  }
  Nova->prox = *ptr_cabeca;
  *ptr_cabeca = Nova;
}

int main(int argc, char const *argv[]) {
  celula *head = NULL;
  int opc = 1;
  while (opc != 0) {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc) {
      case 1:
        fflush(stdin);
        inserir(&head);
        break;

      case 2:
        imprimir(head);
        break;

      case 3:
        printf("o valor total dos produtos é: %.2f",valor_total(head));
        break;

      case 4:
        printf("o valor medio dos produtos é: %.2f", valor_medio(head));
        break;

      case 5:
        char Nome[30];
        printf("Insira o Nome de referencia. (a lista sera dividida a partir dele");
        scanf("%30[^\n]s",Nome);
        celula *head2;
        head2=dividireita_lista(head,Nome);
      break;

      default:
        printf("Opção inválida\n");
        break;
    }
  }
  return 0;
}