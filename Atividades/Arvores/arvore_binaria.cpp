#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int localizador;
  struct Node *esquerda;
  struct Node *direita;
} No;

No *criar_No() {
  No *Node = (No *)malloc(sizeof(No));

  printf("Digite o localizadorero: ");
  scanf("%d", &Node->localizador);

  Node->esquerda = NULL;
  Node->direita = NULL;

  return Node;
}

void inserir_No(No *Node, No *Novo) {
  if (Node == NULL) {
    printf("Erro\n");
    return;
  }

  if (Node->localizador == Novo->localizador) {
    printf("Número já existe\n");
    return;
  }

  if (Node->localizador < Novo->localizador) {
    if (Node->direita == NULL) {
      Node->direita = Novo;
      return;
    }
    inserir_No(Node->direita, Novo);
  } else {
    if (Node->esquerda == NULL) {
      Node->esquerda = Novo;
      return;
    }
    inserir_No(Node->esquerda, Novo);
  }
}

No *buscar_No(No *Node, int localizador) {
  if (Node == NULL) {
    // printf("Número não encontrado\n");
    return NULL;
  }

  if (Node->localizador == localizador) {
    return Node;
  }

  if (Node->localizador > localizador) {
    return buscar_No(Node->direita, localizador);
  } else {
    return buscar_No(Node->esquerda, localizador);
  }
}

void imprimir(No *Node, int tab = 0) {
  if (Node == NULL) return;

  imprimir(Node->direita, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", Node->localizador);
  imprimir(Node->esquerda, tab + 1);
}

void inserir_raiz(No **raiz) {
  if (*raiz == NULL) {
    *raiz = criar_No();
    return;
  }

  No *Novo = criar_No();
  inserir_No(*raiz, Novo);
}

void buscar_raiz(No *raiz) {
  int localizador = 0;
  printf("Digite o localizadorero: ");
  scanf("%d", &localizador);
  No *res = buscar_No(raiz, localizador);
  if (res == NULL) {
    printf("localizadorero não encontrado");
  } else {
    imprimir(res);
  }
}

void menu() {
  printf("MENU\n");
  printf("1-Inserir\n");
  printf("2-Buscar\n");
  printf("3-Imprimir Árvore\n");
  printf("0-Sair\n");
}

int main(int argc, char const *argv[]) {
  No *root = NULL;

  int opc = 1;
  while (opc != 0) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        inserir_raiz(&root);
        break;
      case 2:
        buscar_raiz(root);
        break;
      case 3:
        imprimir(root);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}