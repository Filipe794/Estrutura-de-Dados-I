#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int valor;
    struct No *proximo;

}No;

// Função para Ler um valor.
void ler_valor(int *valor){

    printf("\n\tInforme um Valor: ");
    scanf("%d", &*valor);
}

// Função para Inserir No Inicio.
void inserir_No_inicio(No **lista_inicio, No **lista_fim, int valor, int *tam){

    No *Novo = (No *)malloc(sizeof(No));

    Novo->valor = valor;
    Novo->proximo = *lista_inicio;
    *lista_inicio = Novo;

    // inicio: 300
    // fim: 100
    // 300 -> 200 -> 100
    if(*lista_fim == NULL){

        *lista_fim = Novo;
    }

    // 300 -> 200 -> 100 -> 300
    (*lista_fim)->proximo = *lista_inicio;

    *tam += 1;
}

// Função para Inserir No Fim.
void inserir_No_fim(No **lista_inicio, No **lista_fim, int valor, int *tam){

    No *Novo = (No *)malloc(sizeof(No));
    Novo->valor = valor;

    if(*lista_inicio == NULL){

        inserir_No_inicio(lista_inicio, lista_fim, valor, tam);
    }
    else{

        // Novo: 300
        // fim: 300
        // 100 -> 200 -> 300 -> 100
        (*lista_fim)->proximo = Novo;
        *lista_fim = Novo;

        Novo->proximo = *lista_inicio;
        //(*lista_fim)->proximo = *lista_inicio;

        *tam += 1;
    }
}

// Função para Inserir Ordenado.
void inserir_ordenado(No **lista_inicio, No **lista_fim, int valor, int *tam){

    No *aux, *Novo =(No *)malloc(sizeof(No));

    Novo->valor = valor;

    // NULL
    if(*lista_inicio == NULL){

        inserir_No_inicio(lista_inicio, lista_fim, valor, tam);
    }
    else if(Novo->valor < (*lista_inicio)->valor){

        // Novo: 50
        // 50 -> 100
        inserir_No_inicio(lista_inicio, lista_fim, valor, tam);
    }
    else{

        aux = *lista_inicio;

        while(aux->proximo != *lista_inicio && Novo->valor > aux->proximo->valor){

            aux = aux->proximo;
        }

        // Novo: 400
        // 100 -> 200 -> 300 -> 400 || 300 -> 100
        if(aux->proximo == *lista_inicio){

            inserir_No_fim(lista_inicio, lista_fim, valor, tam);
        }
        else{

            // Novo: 250
            // 100 -> 200 -> 250 -> 300 -> 400
            Novo->proximo = aux->proximo;
            aux->proximo = Novo;

            *tam += 1;
        }
    }
}

// Função para Inserir No Meio.
void inserir_No_meio(No **lista_inicio, No **lista_fim, int ant, int valor, int *tam){

    No *aux, *Novo = (No *)malloc(sizeof(No));
    Novo->valor = valor;

    if(*lista_inicio == NULL){

        inserir_No_inicio(lista_inicio, lista_fim, valor, tam);
    }
    else{

        aux = *lista_inicio;

        while(aux->proximo != *lista_inicio && aux->valor != ant){

            aux = aux->proximo;
        }

        if(aux->proximo == *lista_inicio){

            inserir_No_fim(lista_inicio, lista_fim, valor, tam);
        }
        else{

            Novo->proximo = aux->proximo;
            aux->proximo = Novo;

            *tam += 1;
        }
    }
}

// Função para Imprimir a Lista usando o Tamanho.
void imprimir_1(No *lista_inicio, int tam){

    int cont = 0;

    printf("\n\t-------------------------------------------------\n\t");

    while(cont != tam){

        // 100 -> 200 -> 300
        printf("%d ", lista_inicio->valor);

        lista_inicio = lista_inicio->proximo;

        cont++;
    }

    printf("\n\t-------------------------------------------------\n");
}

// Função para Imprimir a Lista Usando o Inicio e fim da Lista.
void imprimir_2(No *lista_inicio, No *lista_fim){

    printf("\n\t-------------------------------------------------\n\t");

    do{
        printf("%d ", lista_inicio->valor);

        lista_inicio = lista_inicio->proximo;

    // 100 -> 200 -> 300 || 300 -> 100
    }while(lista_inicio != lista_fim->proximo);

    printf("\n\t-------------------------------------------------\n");
}

void inserir(No **head, int valor) {
  No *Nova = (No *)malloc(sizeof(No));
  Nova->valor = valor;

  if (*head == NULL) {
    *head = Nova;
    Nova->proximo = *head;
    return;
  }

  Nova->proximo = *head;
  No *tail = ultimo(*head);
  tail->proximo = Nova;
  *head = Nova;
}

No *ultimo(No *head) {
  if (head == NULL) return NULL;
  No *tail = head;
  while (tail->proximo != head) {
    tail = tail->proximo;
  }
  return tail;
}

void remover(No **head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->proximo == *head) {
    free(*head);
    *head = NULL;
    return;
  }

  No *tail = ultimo(*head);
  tail->proximo = (*head)->proximo;
  free(*head);
  *head = tail->proximo;
}

void imprimir(No *head) {
  No *aux = head;
  if (aux != NULL) {
    while (aux->proximo != head) {
      printf("%d -> ", aux->valor);
      aux = aux->proximo;
    }
    printf("%d -> ", aux->valor);
  }
  printf("HEAD\n");
}

