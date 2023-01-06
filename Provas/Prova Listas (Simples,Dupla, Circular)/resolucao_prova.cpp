#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
  char Nome[30];
  int aNo;
  float preco_compra;
  float preco_venda;
  struct No *prox;
  struct No *ant;
} Carro;

Carro *venda = NULL;
Carro *vendido = NULL;

Carro *criar_carro() {
  Carro *carro = (Carro *)malloc(sizeof(Carro));
  printf("Digite o Nome do carro: ");
  scanf("%s", carro->Nome);
  printf("Digite o aNo do carro: ");
  scanf("%d", &carro->aNo);
  printf("Digite o preço do carro: ");
  scanf("%d", &carro->preco_compra);
  carro->preco_venda = carro->preco_compra * 1.2f;

  return carro;
}

void inserir_veiculo(Carro **cabeca, Carro *carro) {
  if (*cabeca == NULL) {  // Inserindo lista vazia
    carro->prox = NULL;
    carro->ant = NULL;
    *cabeca = carro;
  } else {
    Carro *aux = *cabeca;
    if (strcmp(carro->Nome, aux->Nome) < 0) {  // Inserindo inicio
      carro->prox = aux;
      carro->ant = aux->ant;
      aux->ant = carro;
      *cabeca = carro;
      return;
    }

    while (aux->prox != NULL) {  // Inserir No meio da lista
      if (strcmp(carro->Nome, aux->Nome) < 0) {
        carro->prox = aux;
        carro->ant = aux->ant;
        aux->ant = carro;
      }
      aux = aux->prox;
    }
    carro->prox = NULL;  // Inserindo fim
    carro->ant = aux;
    aux->prox = carro;
  }
}

void imprimir_lista(Carro *aux) {
  while (aux != NULL) {
    printf("%s -> ", aux->Nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void busca_preco() {
  float preco = 0.0f;
  printf("Digite o preço do veículo: ");
  scanf("%f", &preco);

  Carro *aux = venda;
  while (aux != NULL) {
    if (aux->preco_venda <= preco) {
      imprimir_carro(aux);
    }
    aux = aux->prox;
  }
}

void busca_aNo() {
  int aNo = 0;
  printf("Digite o aNo do veículo: ");
  scanf("%d", &aNo);

  Carro *aux = venda;
  while (aux != NULL) {
    if (aux->aNo == aNo) {
      imprimir_carro(aux);
    }
    aux = aux->prox;
  }
}

Carro *busca_Nome() {
  char Nome[30];
  printf("Digite o Nome do veículo: ");
  scanf("%s", Nome);

  Carro *aux = venda;
  while (aux != NULL) {
    if (strcmp(Nome, aux->Nome) == 0) {
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void imprimir_carro(Carro *carro) {
  printf("---------------------\n");
  printf("Nome: %s\n", carro->Nome);
  printf("ANo: %d\n", carro->aNo);
  printf("Preço compra: R$%.2f\n", carro->preco_compra);
  printf("Preço venda: R$%.2f\n", carro->preco_venda);
  printf("\n");
}

void cadastrar_carro() {
  Carro *carro = criar_carro();
  inserir_veiculo(&venda, carro);
}

void calcular_lucro() {
  float lucro = 0.0f;
  Carro *aux = vendido;
  while (aux != NULL) {
    lucro += (aux->preco_venda) - (aux->preco_compra);
    aux = aux->prox;
  }
  printf("O lucro total de vendas foi: %.2f", lucro);
}

void menu() {
  printf("1-Cadastrar carro\n");
  printf("2-Buscar pelo preço\n");
  printf("3-Buscar pelo aNo\n");
  printf("4-Vender\n");
  printf("5-Informar lucro\n");
  printf("6-Imprimir à venda\n");
  printf("7-Imprimir vendido\n");
  printf("0-Sair\n");
}

void remover_veiculo(Carro **cabeca, Carro *rem) {
  if (*cabeca == NULL) {  // Remover lista vazia;
    return;
  } else {
    Carro *ant = rem->ant;
    Carro *prox = rem->prox;

    if ((*cabeca == rem) && (prox == NULL)) {  // Lista com único
      *cabeca = NULL;
      return;
    }

    if (*cabeca == rem) {  // Primeiro elemento
      *cabeca = prox;
      (*cabeca)->ant = NULL;
    } else {
      if (prox == NULL) {  // Ultimo elemento
        ant->prox = NULL;
      } else {  // Meio
        ant->prox = prox;
        prox->ant = ant;
      }
      rem->prox = NULL;
      rem->ant = NULL;
    }
  }
}

void vender() {
  Carro *carro = busca_Nome();
  if (carro == NULL) {
    printf("Nome inválido\n");
    return;
  }

  float preco_proposto = 0.0f;
  printf("Digite o preço da venda: ");
  scanf("%f", &preco_proposto);
  if (carro->preco_compra > preco_proposto) {
    printf("Preço inválido\n");
    return;
  }
  carro->preco_venda = preco_proposto;
  remover_veiculo(&venda, carro);
  inserir_veiculo(&vendido, carro);
}

int main(int argc, char const *argv[]) {
  int opc = -1;

  while (opc != 0) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        cadastrar_carro();
        break;

      case 2:
        busca_preco();

      case 3:
        busca_aNo();

      case 6:
        imprimir_lista(venda);
        break;

      case 7:
        imprimir_lista(vendido);
        break;

      case 0:
        return 0;

      default:
        printf("Opção inválida");
        break;
    }
  }

  return 0;
}