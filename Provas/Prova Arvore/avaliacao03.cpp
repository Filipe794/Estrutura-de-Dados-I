
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct só pra armazenar a passagem
typedef struct passagem
{
  char data[10];
  float preco;
  int localizador;
  char destiNo[50];
} passagem;
// struct pra armazenar os dados da arvore
typedef struct Node
{
  passagem passagem;
  struct Node *esquerda;
  struct Node *direita;
} No;

// arvore pra armazenar a passagem dos dois paises
No *argentina = NULL;
No *brasil = NULL;
No *consolidada = NULL;
// contadores pra armazenar o numero de passagens de cada pais e o preço total vendido
int cont_argentina = 0;
int cont_brasil = 0;
float contador_preco = 0;

// função pra somar as passagens vendidas
int soma(No *Node)
{
  if (Node == NULL)
    return -1;
  contador_preco = contador_preco + (Node->passagem.preco);

  soma(Node->direita); // recursividade
  soma(Node->esquerda); // recursividade

  return contador_preco;
}

No *criar_passagem()
{
  int loc = rand() % 100;
  No *pass = (No *)malloc(sizeof(No));

  printf("Escolha a data:\n ");
  scanf("%s", pass->passagem.data);
  fflush(stdin);
  printf("Escolha o destiNo:\n ");
  scanf("%50[^\n]s", pass->passagem.destiNo);
  fflush(stdin);
  printf("Escolha o preço:");
  scanf("%f", &pass->passagem.preco);
  fflush(stdin);
  pass->passagem.localizador = loc;
  printf("Localizador: %d\n", pass->passagem.localizador);

  pass->esquerda = NULL;
  pass->direita = NULL;

  return pass;
}
void inserir_passagem(No *Node, No *Novo)
{
  if (Node == NULL)
  {
    printf("Erro\n");
    return;
  }

  if (Node->passagem.localizador == Novo->passagem.localizador)
  {
    printf("Número já existe\n");
    return;
  }

  if (Node->passagem.localizador < Novo->passagem.localizador)
  {
    if (Node->direita == NULL)
    {
      Node->direita = Novo;
      return;
    }
    inserir_passagem(Node->direita, Novo);
  }
  else
  {
    if (Node->esquerda == NULL)
    {
      Node->esquerda = Novo;
      return;
    }
    inserir_passagem(Node->esquerda, Novo);
  }
}
void inserir_raiz(No **raiz)
{
  if (*raiz == NULL)
  {
    *raiz = criar_passagem();
    return;
  }

  No *Novo = criar_passagem();
  inserir_passagem(*raiz, Novo);
}
void menu()
{

  printf("MENU\n");
  printf("1-Passagem para Argentina\n");
  printf("2-Passagem para Brasil\n");
  printf("3-buscar passagem para Argentina\n");
  printf("4-buscar passagem para Brasil\n");
  printf("5-Faturamento da Argentina\n");
  printf("6-Faturamento do Brasil\n");
  printf("7-Total de voos realizados\n");
  printf("8-Vendas consolidadas\n");
  printf("9- Imprimir passagens para argentina\n");
  printf("10- Imprimir passagens para brasil\n");
  printf("11- Imprimir vendas consolidadas\n");
  printf("0-Sair\n");
}

void imprimir_No(No *Node)
{

  if (Node == NULL)
  {
    return;
  }
  printf("%s\n", Node->passagem.data);
  printf("%s\n", Node->passagem.destiNo);
  printf("%f\n", Node->passagem.preco);
}
No *buscar_pai(No *Node, int num)
{
  if (Node == NULL)
    return NULL;

  if ((Node->esquerda != NULL) && (Node->esquerda->passagem.localizador == num))
  {
    return Node;
  }

  if ((Node->direita != NULL) && (Node->direita->passagem.localizador == num))
  {
    return Node;
  }

  if (Node->passagem.localizador < num)
  {
    return buscar_pai(Node->direita, num);
  }
  else
  {
    return buscar_pai(Node->esquerda, num);
  }
}

bool um_filho(No *Node)
{
  // return (Node->esquerda == NULL) && (Node->direita == NULL);
  if ((Node->esquerda == NULL) && (Node->direita != NULL))
  {
    return true;
  }

  if ((Node->esquerda != NULL) && (Node->direita == NULL))
  {
    return true;
  }

  return false;
}

bool eh_folha(No *Node)
{
  // return (Node->esquerda == NULL) && (Node->direita == NULL);
  if ((Node->esquerda == NULL) && (Node->direita == NULL))
  {
    return true;
  }
  else
  {
    return false;
  }
}

No *maior(No *Node)
{
  if (Node == NULL)
    return NULL;
  if (Node->direita == NULL)
    return Node;
  return maior(Node->direita);
}

No *remover(No *Node, int num);

void substituir(No *pai, No *removido)
{
  if (um_filho(removido))
  {
    if (removido->esquerda != NULL)
    {
      pai->esquerda = removido->esquerda;
    }
    else
    {
      pai->direita = removido->direita;
    }
  }
  else
  {
    No *substituto = maior(removido->esquerda);
    remover(pai, substituto->passagem.localizador);
    substituto->esquerda = removido->esquerda;
    substituto->direita = removido->direita;
    if (pai->passagem.localizador < substituto->passagem.localizador)
    {
      pai->direita = substituto;
    }
    else
    {
      pai->esquerda = substituto;
    }
    removido->direita = NULL;
    removido->esquerda = NULL;
  }
}

No *remover(No *Node, int num)
{
  No *pai = buscar_pai(Node, num);
  if (pai == NULL)
  {
    printf("Numero não encontrado");
    return NULL;
  }
  else
  {
    // printf("Pai: %d\n", pai->num);
    No *removido = NULL;
    if (pai->passagem.localizador < num)
    {
      removido = pai->direita;
      if (eh_folha(removido))
      {
        pai->direita = NULL;
      }
      else
      {
        substituir(pai, removido);
      }
    }
    else
    {
      removido = pai->esquerda;
      if (eh_folha(removido))
      {
        pai->esquerda = NULL;
      }
      else
      {
        substituir(pai, removido);
      }
    }
    // printf("Removido: %d\n", removido->num);
    return removido;
  }
}

void arvore_consolidada(No **raiz, No *Node)
{
  if (*raiz == NULL)
  {
    *raiz = Node;
    return;
  }
  if (((*raiz)->passagem.localizador) < (Node->passagem.localizador))
  {
    if ((*raiz)->direita == NULL)
    {
      (*raiz)->direita = Node;
      return;
    }
    arvore_consolidada(&(*raiz)->direita, Node);
  }
  else
  {
    if ((*raiz)->esquerda == NULL)
    {
      (*raiz)->esquerda = Node;
      return;
    }
    arvore_consolidada(&(*raiz)->esquerda, Node);
  }
}

void remover_raiz(No **raiz)
{
  if (*raiz == NULL)
  {
    printf("Árvore vazia\n");
    return;
  }

  int num = (*raiz)->passagem.localizador;

  if ((*raiz)->passagem.localizador == num)
  {
    if (eh_folha(*raiz))
    {
      arvore_consolidada(&consolidada, *raiz);
      *raiz = NULL;
      return;
    }

    if (um_filho(*raiz))
    {
      No *remover = *raiz;
      if ((*raiz)->esquerda != NULL)
      {
        *raiz = (*raiz)->esquerda;
        remover->esquerda = NULL;
      }
      else
      {
        *raiz = (*raiz)->direita;
        remover->direita = NULL;
      }
      arvore_consolidada(&consolidada, remover);
    }
    else
    {
      No *substituto = maior((*raiz)->esquerda);

      remover(*raiz, substituto->passagem.localizador);

      substituto->esquerda = (*raiz)->esquerda;
      substituto->direita = (*raiz)->direita;

      (*raiz)->esquerda = NULL;
      (*raiz)->direita = NULL;

      arvore_consolidada(&consolidada, *raiz);

      *raiz = substituto;
    }
  }
}

void consolidar(No **root)
{
  while ((*root) != NULL)
  {
    remover_raiz(root);
  }
}

void buscar_destiNo(No *No, char *destiNo)
{
  if (No == NULL)
  {
    return;
  }
  if (strcmp(No->passagem.destiNo, destiNo) == 0)
  {
    imprimir_No(No);
  }

  buscar_destiNo(No->direita, destiNo);
  buscar_destiNo(No->esquerda, destiNo);
}

void imprimir(No *Node) // função para imprimir a arvore
{
  if (Node == NULL)
  {
    return;
  }
  imprimir_No(Node);
  printf("\n");
  imprimir(Node->direita);
  imprimir(Node->esquerda);
}
int main()
{
  srand(time(NULL));
  float preco_arg;
  float preco_br;
  char destiNo[30];
  int opc = -1;
  while (opc != 0)
  {
    menu();
    scanf("%d", &opc);
    switch (opc)
    {
      {
      case 1: // vender passagem pra argentina
        inserir_raiz(&argentina);
        cont_argentina++;
        break;
      case 2: // vender passagem para o brasil
        inserir_raiz(&brasil);
        cont_brasil++;
        break;

      case 3: // buscar destiNo pra argentina
        printf("informe o destiNo que deseja buscar\n");
        scanf("%s", destiNo);
        buscar_destiNo(argentina, destiNo);
        break;

      case 4: // buscar destiNo para brasil
        printf("informe o destiNo que deseja buscar\n");
        scanf("%s", destiNo);

        buscar_destiNo(brasil, destiNo);

        break;

      case 5: // faturamento argentina
        preco_arg = soma(argentina);
        printf("Faturamento - Argentina: %f\n", preco_arg);

        printf("faturamento total = %f", preco_arg + preco_br);
        contador_preco = 0;

        break;
      case 6: // faturamento brasil
        preco_br = soma(brasil);
        printf("Faturamento - Brasil: %f\n", preco_br);
        printf("faturamento total = %f", preco_arg + preco_br);
        contador_preco = 0;
        break;
      case 7: // total de voos realizados
        printf("Quantidade de voos para Argentina=%d", cont_argentina);
        printf("Quantidade de voos para Brasil=%d", cont_brasil);
        printf("Quantidade total de voos =%d", cont_argentina + cont_brasil);
        break;
      case 8: // vendas consolidadas
        consolidar(&brasil);
        consolidar(&argentina);
        break;
      case 9: // imprimir passagem pra argentina
        imprimir(argentina);
        break;
      case 10: // imprimir passagem para brasil
        imprimir(brasil);
        break;
      case 11: // imprimir arvore consolidada
        imprimir(consolidada);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
      }
    }
  }
  return 0;
}
