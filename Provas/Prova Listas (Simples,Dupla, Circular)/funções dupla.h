#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct No{
    char Nome[40];
    int aNo_fabricacao, preco_compra, preco_venda;
    struct No *proximo;
    struct No *anterior;

}No;

void ler_No(No *No){

  printf("Digite o Nome do veiculo: ");
  scanf("%40[^\n]s", No->Nome);

  printf("Digite o aNo de fabricação: ");
  scanf("%d", &No->aNo_fabricacao);

  printf("Digite o valor de compra: ");
  scanf("%d", &No->preco_compra);

  No->preco_venda=(No->preco_compra + (No->preco_compra)*(20/100));
}

void imprimir_valor(int valor){

    printf(" <- %d -> ", valor);
}

No* remover_No(No **lista, int valor){

    No *aux, *remover = NULL;

    if(*lista != NULL){

        // valor 4
        // 4, 5, 8, 9, NULL
        if((*lista)->preco_compra == valor){

            // remover 4
            // 4, 5, 8, 9, NULL
            // Nova Lista: 5, 8, 9, NULL
            remover = *lista;
            *lista = remover->proximo;

            // Nova Lista: NULL, 5, 8, 9, NULL
            if(*lista != NULL){

                (*lista)->anterior = NULL;
            }
        }
        else{

            aux = *lista;

            // valor 8
            // 4, 5, 8, 9, NULL
            // aux 9
            while(aux->proximo != NULL && aux->proximo->preco_compra != valor){

                aux = aux->proximo;
            }

            // valor 8
            // 4, 5, 8, 9, NULL
            // aux 5
            if(aux->proximo != NULL){

                // remover 8
                // NULL, 4 -><- 5 -><- 9, NULL
                remover = aux->proximo;
                aux->proximo = remover->proximo;

                if(aux->proximo != NULL){

                    aux->proximo->anterior = aux;
                }
            }
        }
    }
}

// Função para Imprimir a Lista.
void imprimir_lista(No *No){

    printf("\n\t--------------------------------------------------------\n\t");

    if(No == NULL){
        printf("NULL");
    }

    while(No != NULL){
        printf("Nome do veiculo: %s\n",No->Nome);

        printf("aNo de fabricação: %d\n", No->aNo_fabricacao);

        printf("valor de compra: %d\n ", No->preco_compra);

        printf("valor de venda: %d\n ", No->preco_venda);

        No = No->proximo;
    }

    printf("NULL");

    printf("\n\t--------------------------------------------------------\n");
}

// Função que Encontra o Ultimo Nó.
No* ultimo_No(No **lista){

    No *aux = *lista;

    while(aux->proximo != NULL){

        aux = aux->proximo;
    }

    // aux 6
    // 2, 3, 6, NULL
    return aux;
}

void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir produto\t*\n");
  printf("*\t2 - Imprimir produtos à venda\t*\n");
  printf("*\t3 - Imprimir produtos ja vendidos\t*\n");
  printf("*\t4 - Calcular valor total dos produtos\t*\n");
  printf("*\t5 - Calcular valor médio dos produtos\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}



int tamanho(No *cabeca) {
  if (cabeca == NULL) {
    return 0;
  }
int tam = 0;
  No *aux = cabeca;
  while (aux != NULL){
    tam++; 
    aux = aux->proximo;
  }
  return tam;
}

No *metade(No *cabeca1) {
    int tam_total = tamanho(cabeca1);
    if (tam_total == 1) {
        return NULL;
    }
    
    int tam1 = ceil(tam_total / 2.0f);
    printf("TAM1: %d\n", tam1);

    No *cabeca2 = NULL;

    No *aux = cabeca1;
    int i = 0;
    while (i < tam1 - 1) {
        aux = aux->proximo;
        i++;
    }

    cabeca2 = aux->proximo;
    aux->proximo = NULL;
    cabeca2->anterior = NULL;

    return cabeca2;
    }

    void troca(No *elem1, No *elem2) {

    No *prim = elem1->anterior;
    No *ult = elem2->proximo;

    prim->proximo = elem2;
    ult->anterior = elem1;
    elem2->proximo = elem1;
    elem1->proximo = ult;
    elem1->anterior = elem2;
    elem2->anterior = prim;
    }

void inserir_ordenado(No **lista){

    No *aux, *Novo = (No *)malloc(sizeof(No));;

    ler_No(Novo);
    if(*lista == NULL){

        Novo->proximo = NULL;
        Novo->anterior = NULL;

        *lista = Novo;
    }
    else if(strcmp(Novo->Nome,(*lista)->Nome)<0){
        Novo->proximo = *lista;
        Novo->anterior = NULL;

        *lista = Novo;
    }
    else{
        aux = *lista;
        while(aux->proximo != NULL && strcmp(Novo->Nome,aux->Nome)> 0){
            aux = aux->proximo;
        }
        Novo->proximo = aux;
        Novo->anterior = aux->anterior;
        aux->anterior->proximo=Novo;
        aux->anterior = Novo;
    }
}
