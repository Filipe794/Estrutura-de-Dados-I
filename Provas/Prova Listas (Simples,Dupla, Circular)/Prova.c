#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct No
{
    char nome[40];
    int ano_fabricacao;
    int preco_compra;
    int preco_venda;
    struct No *proximo;
    struct No *anterior;

} No;

No *remover_no(No **lista, No *remover)
{
    if (remover == NULL)
    {
        return NULL;
    }

    if ((*lista) == NULL)
    {
        return NULL;
    }

    if ((*lista) == remover)
    {
        (*lista) = remover->proximo;

        if ((*lista) != NULL)
        {

            (*lista)->anterior = NULL;
        }

        remover->proximo = NULL;
        return remover;
    }

    No *anterior = remover->anterior;
    No *proximo = remover->proximo;

    if (anterior != NULL)
    {
        anterior->proximo = proximo;
    }

    if (proximo != NULL)
    {
        proximo->anterior = anterior;
    }

    remover->proximo = NULL;
    remover->anterior = NULL;

    return remover;
}

void imprimir_no(No *node)
{
    if (node == NULL)
    {
        printf("NULL");
        return;
    }

    printf("Nome do veiculo: %s\n", node->nome);

    printf("ano de fabricação: %d\n", node->ano_fabricacao);

    printf("valor de compra: %d\n ", node->preco_compra);

    printf("valor de venda: %d\n ", node->preco_venda);
}

void imprimir_lista(No *No)
{

    printf("\n\t--------------------------------------------------------\n\t");

    if (No == NULL)
    {
        printf("NULL");
    }

    while (No != NULL)
    {
        imprimir_no(No);

        No = No->proximo;
    }

    printf("NULL");

    printf("\n\t--------------------------------------------------------\n");
}

void imprimir_menu()
{
    printf("\n\n");
    printf("*******\t\tMENU\t********\n");
    printf("*\t1 - Inserir produto\t*\n");
    printf("*\t2 - Imprimir carros à venda\t*\n");
    printf("*\t3 - Imprimir carros ja vendidos\t*\n");
    printf("*\t4 - Procurar carros abaixo de um preço \t*\n");
    printf("*\t5 - Procurar carros por aNo de fabricação\t*\n");
    printf("*\t6 - Lucro\t*\n");
    printf("*\t7 - Vender carro //nao ta funcionando//\t*\n");
    printf("*\t0 - Sair\t\t*\n");
}

void busca_preco(No *No)
{
    int valor;
    printf("insira o preço do carro: ");
    scanf("%d", &valor);
    while (No != NULL)
    {
        if (No->preco_venda <= valor)
        {
            imprimir_no(No);
        }
        No = No->proximo;
    }
}

void busca_ano(No *No)
{
    int valor;
    printf("insira o aNo de fabricação a ser procurado: ");
    scanf("%d", &valor);
    while (No != NULL)
    {
        if (No->ano_fabricacao == valor)
        {
            imprimir_no(No);
        }
        No = No->proximo;
    }
}

No *busca_nome(No *node, char *modelo)
{
    while (node != NULL)
    {
        if (strcmp(modelo, node->nome) == 0)
        {
            return node;
        }
        node = node->proximo;
    }
    return NULL;
}

void lucro(No *vendido)
{
    int lucro, total_venda = 0, total_compra = 0;

    No *aux = vendido;
    while (aux != NULL)
    {
        total_venda = total_venda + aux->preco_venda;
        total_compra = total_compra + aux->preco_compra;
        aux = aux->proximo;
    }
    lucro = total_venda - total_compra;
    printf("%d", lucro);
}

No *criar_no()
{
    No *node = (No *)malloc(sizeof(No));

    printf("Digite o Nome do veiculo: ");
    scanf("%s", node->nome);
    fflush(stdin);

    printf("Digite o ano de fabricação: ");
    scanf("%d", &node->ano_fabricacao);

    printf("Digite o valor de compra: ");
    scanf("%d", &node->preco_compra);

    node->preco_venda = (node->preco_compra * 1.2);

    return node;
}

void inserir_ordenado(No **lista, No *node)
{
    if (node == NULL)
    {
        return;
    }

    if ((*lista) == NULL) // lista vazia
    {
        node->proximo = NULL;
        node->anterior = NULL;
        (*lista) = node;
        return;
    }
    else
    {
        if (strcmp(node->nome, (*lista)->nome) < 0)
        { // Inserindo inicio
            node->proximo = (*lista);
            node->anterior = NULL;
            (*lista)->anterior = node;
            (*lista) = node;
            return;
        }

        No *aux = *lista;
        No *anterior = NULL;

        while (aux != NULL && strcmp(node->nome, aux->nome) >= 0)
        { // Inserir No meio da lista
            anterior = aux;
            aux = aux->proximo;
        }
        if (aux != NULL)
        {
            node->proximo = aux;
            node->anterior = anterior;
            anterior->proximo = node;
            aux->anterior = node;
            return;
        }
        else
        {
            node->proximo = NULL; // Inserindo fim
            node->anterior = anterior;
            anterior->proximo = node;
        }
    }
    return;
}

void vender(No **a_vender, No **vendido)
{
    char nome[40];
    int valor_negociado;
    No *remover;

    printf("Qual carro foi vendido? (modelo)");
    scanf("%s", nome);

    remover = busca_nome((*a_vender), nome);
    if (remover == NULL)
    {
        printf("Veiculo não existe no sistema");
        return;
    }

    printf("qual o valor da venda:");
    scanf("%d", &valor_negociado);

    if (valor_negociado < remover->preco_compra)
    {
        printf("Valor de venda não permitido, está abaixo do preco de compra");
        return;
    }

    remover->preco_venda = valor_negociado;

    remover = remover_no(a_vender, remover);
    inserir_ordenado(vendido, remover);
}

int main()
{
    No *a_vender = NULL;
    No *vendido = NULL;
    No *node;

    int opc = 1;
    while (opc != 0)
    {
        imprimir_menu();
        scanf("%d", &opc);
        fflush(stdin);
        switch (opc)
        {
        case 1:
            fflush(stdin);
            node = criar_no();
            inserir_ordenado(&a_vender, node);
            break;

        case 2:
            imprimir_lista(a_vender);
            break;

        case 3:
            imprimir_lista(vendido);
            break;

        case 4:
            busca_preco(a_vender);
            break;

        case 5:
            busca_ano(a_vender);
            break;

        case 6:
            lucro(vendido);
            break;
        case 7:
            vender(&a_vender, &vendido);
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    }
    return 0;
}
