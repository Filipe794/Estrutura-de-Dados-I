#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int valor;
    struct No *proximo;

}No;

void ler_valor(No *No){

    printf("\nDigite um Valor: ");
    scanf("%d", &No->valor);
}

int ler_valor_remover(){

    int valor;

    printf("\nDigite um Valor para Remover: ");
    scanf("%d", &valor);

    return valor;
}

void inserir(No **lista){

    No *Novo =(No *)malloc(sizeof(No));

    // Novo->valor = 100;
    ler_valor(Novo);

    // Novo->proximo = lista;
    Novo->proximo = *lista;

    *lista = Novo;
}

void inserir_ordenado(No **lista){

    No *aux, *Novo = (No *)malloc(sizeof(No));;

    ler_valor(Novo);

    // 10 -> NULL
    // Não Existe Ninguem
    if(*lista == NULL){

        Novo->proximo = NULL;

        *lista = Novo;
    }
    else if(Novo->valor < (*lista)->valor){

        // 10 -> 50 -> 100 -> NULL
        Novo->proximo = *lista;

        *lista = Novo;
    }
    else{

        aux = *lista;

        // 10 -> 50 -> 60 -> 100 -> NULL
        while(aux->proximo != NULL && Novo->valor > aux->proximo->valor){

            aux = aux->proximo;
        }

        Novo->proximo = aux->proximo;

        aux->proximo = Novo;
    }
}

void concatenar_listas(No **lista_1, No **lista_2){

    No *aux;

    if(lista_1 != NULL){

        aux = *lista_1;

        // aux->proximo = NULL;
        while(aux->proximo != NULL){

            aux = aux->proximo;
        }

        aux->proximo = *lista_2;
    }
}

No* remover_No(No **lista, int valor){

    No *aux, *rem = NULL;

    if(*lista != NULL){

        // 10 = 10
        if((*lista)->valor == valor){

            // rem = 10 -> 20 -> NULL
            rem = *lista;

            // 20 -> NULL
            *lista = rem->proximo;
        }
        else{

            aux = *lista;

            // 10 -> 20 -> 30 -> NULL
            while(aux->proximo != NULL && aux->proximo->valor != valor){

                aux = aux->proximo;
            }

            if(aux->proximo != NULL){

                // 30 -> NULL
                rem = aux->proximo;

                // 10 -> 20 -> NULL
                aux->proximo = rem->proximo;
            }
        }
    }

    return rem;
}

void remover_ocorrencias(No **lista, int valor){

    No *aux;

    if(*lista != NULL){

        aux = *lista;

        while(aux != NULL){

            if(aux->valor == valor){

                remover_No(lista, valor);
            }

            aux = aux->proximo;
        }
    }
}

void imprimir(int valor){

    printf("%d -> ", valor);
}

void imprimir_lista(No *lista){

    printf("\n\t------------------------------------------------\n\t");

    if(lista != NULL){

        while(lista != NULL){

            imprimir(lista->valor);

            lista = lista->proximo;
        }
    }

    printf("NULL");

    printf("\n\t------------------------------------------------\n");
}

No *buscar(No *aux, int valor) {
  while (aux != NULL) {
    if (aux->valor == valor) {
      return aux;  //"Elemento encontrado"
    }
    aux = aux->proximo;
  }
  return NULL;  //"Elemento não encontrado"
}

No *troca_prox(No *cabeca, int valor) {
  No *a = NULL;
  No *c = cabeca;
  No *p = NULL;

  if (c->proximo == NULL) {
        printf("O proximo é NULL\n");
        return cabeca;
    }

  if (c->valor == valor) {
    p = c->proximo;
    c->proximo = p->proximo;
    p->proximo = c;
    return p;
  }

  while ((c != NULL) && (c->proximo != NULL)) {
    if (c->valor == valor) {
      a->proximo = p;
      c->proximo = p->proximo;
      p->proximo = c;
      return cabeca;
    }
    a = c;
    c = c->proximo;
    p = c->proximo;
  }
  return cabeca;
  // return -1;  //"Elemento não encontrado"
}