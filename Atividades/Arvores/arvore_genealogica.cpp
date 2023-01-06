#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Nome[30];
    int idade;

} passagem;

typedef struct Node
{
    passagem *passagem;
    struct Node *filho1;
    struct Node *filho2;
    struct Node *filho3;
} No;

No *criar_No()
{
    passagem *p = (passagem *)malloc(sizeof(passagem));
    No *Node = (No *)malloc(sizeof(No));

    printf("Digite o Nome: ");
    scanf(" %s", p->Nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    Node->passagem = p;
    Node->filho1 = NULL;
    Node->filho2 = NULL;
    Node->filho3 = NULL;

    return Node;
}

void inserir_No(No *pai, No *Novo)
{
    if (pai->filho1 == NULL)
    {
        pai->filho1 = Novo;
        return;
    }

    if (pai->filho2 == NULL)
    {
        pai->filho2 = Novo;
        return;
    }

    if (pai->filho3 == NULL)
    {
        pai->filho3 = Novo;
        return;
    }

    printf("Não inseriu. Excesso de filhos.\n");
}

No *busca_larg(No *Node, char *Nome)
{
    if (Node == NULL)
        return NULL;

    if (strcmp(Node->passagem->Nome, Nome) == 0)
    {
        return Node;
    }

    No *f1, *f2, *f3;
    f1 = Node->filho1;
    f2 = Node->filho2;
    f3 = Node->filho3;

    if ((f1 != NULL) && (strcmp(f1->passagem->Nome, Nome) == 0))
    {
        return f1;
    }

    if ((f2 != NULL) && (strcmp(f2->passagem->Nome, Nome) == 0))
    {
        return f2;
    }

    if ((f3 != NULL) && (strcmp(f3->passagem->Nome, Nome) == 0))
    {
        return f3;
    }

    No *res = NULL;
    res = busca_larg(Node->filho1, Nome);
    if (res != NULL)
    {
        return res;
    }

    res = busca_larg(Node->filho2, Nome);
    if (res != NULL)
    {
        return res;
    }

    res = busca_larg(Node->filho3, Nome);
    if (res != NULL)
    {
        return res;
    }

    return NULL;
}

No *busca_prof(No *Node, char *Nome)
{
    if (Node == NULL)
        return NULL;

    if (strcmp(Node->passagem->Nome, Nome) == 0)
    {
        return Node;
    }

    No *res = NULL;
    res = busca_prof(Node->filho1, Nome);
    if (res != NULL)
    {
        return res;
    }

    res = busca_prof(Node->filho2, Nome);
    if (res != NULL)
    {
        return res;
    }

    res = busca_prof(Node->filho3, Nome);
    if (res != NULL)
    {
        return res;
    }

    return NULL;
}

void imprimir(No *Node, int tab = 0)
{
    if (Node == NULL)
        return;

    for (int i = 0; i < tab; i++)
    {
        printf("\t");
    }

    printf("%s - %d\n", Node->passagem->Nome, Node->passagem->idade);
    imprimir(Node->filho1, tab + 1);
    imprimir(Node->filho2, tab + 1);
    imprimir(Node->filho3, tab + 1);
}

void inserir_pai(No **Node)
{
    if (*Node == NULL)
    {
        *Node = criar_No();
        return;
    }

    char Nome_pai[30];
    printf("Digite o Nome do nó pai: ");
    scanf(" %s", Nome_pai);

    No *pai = busca_prof(*Node, Nome_pai);
    if (pai == NULL)
    {
        printf("Nó não encontrado\n");
        return;
    }

    No *filho = criar_No();
    inserir_No(pai, filho);
}

void buscar_pai(No *root)
{
    char Nome[30];
    printf("Digite o Nome da passagem: ");
    scanf(" %s", Nome);
    No *No = busca_prof(root, Nome);
    if (No == NULL)
    {
        printf("passagem não encontrada\n");
        return;
    }
    printf("%s - %d\n", No->passagem->Nome, No->passagem->idade);
}

void menu()
{
    printf("MENU\n");
    printf("1-Inserir\n");
    printf("2-Buscar\n");
    printf("3-Imprimir Árvore\n");
    printf("0-Sair\n");
}

int main(int argc, char const *argv[])
{
    No *root = NULL;

    int opc = 1;
    while (opc != 0)
    {
        menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            inserir_pai(&root);
            break;
        case 2:
            buscar_pai(root);
            break;
        case 3:
            imprimir(root);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
    return 0;
}