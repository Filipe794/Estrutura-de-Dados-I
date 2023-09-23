#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct No
{
    char Nome[40];
    int ano_fabricacao, preco_compra, preco_venda;
    struct No *proximo;
    struct No *anterior;

} No;



No *criar_no()
{
    No *node = (No *)malloc(sizeof(No));

    printf("Digite o Nome do veiculo: ");
    scanf("%s", node->Nome);
    fflush(stdin);

    printf("Digite o ano de fabricação: ");
    scanf("%d", &node->ano_fabricacao);

    printf("Digite o valor de compra: ");
    scanf("%d", &node->preco_compra);

    node->preco_venda = (node->preco_compra * 1.2);

    return node;
}

void remover_No(No **lista, int valor)
{

    No *aux, *remover = NULL;

    if (*lista != NULL)
    {

        if ((*lista)->preco_compra >= valor)
        {

            *lista = remover->proximo;
            remover = *lista;

            if (*lista != NULL)
            {

                (*lista)->anterior = NULL;
            }
        }
        else
        {

            aux = *lista;
            while (aux->proximo != NULL && aux->proximo->preco_compra != valor)
            {

                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;

                if (aux->proximo != NULL)
                {

                    aux->proximo->anterior = aux;
                }
            }
        }
    }
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
        printf("Nome do veiculo: %s\n", No->Nome);

        printf("aNo de fabricação: %d\n", No->ano_fabricacao);

        printf("valor de compra: %d\n ", No->preco_compra);

        printf("valor de venda: %d\n ", No->preco_venda);

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
        if (No->preco_venda < valor)
        {
            printf("Nome do veiculo: %s\n", No->Nome);

            printf("aNo de fabricação: %d\n", No->ano_fabricacao);

            printf("valor de compra: %d\n ", No->preco_compra);

            printf("valor de venda: %d\n ", No->preco_venda);
        }
        No = No->proximo;
    }
}

void busca_aNo(No *No)
{
    int valor;
    printf("insira o aNo de fabricação a ser procurado: ");
    scanf("%d", &valor);
    while (No != NULL)
    {
        if (No->ano_fabricacao == valor)
        {
            printf("Nome do veiculo: %s\n", No->Nome);

            printf("aNo de fabricação: %d\n", No->ano_fabricacao);

            printf("valor de compra: %d\n ", No->preco_compra);

            printf("valor de venda: %d\n ", No->preco_venda);
        }
        No = No->proximo;
    }
}

void lucro(No *a_vender, No *vendido)
{
    int lucro = 0, soma_venda = 0, soma_estoque = 0;

    No *aux = a_vender;
    while (aux != NULL)
    {
        soma_estoque = soma_estoque + aux->preco_compra;
        aux = aux->proximo;
    }
    aux = vendido;
    while (aux != NULL)
    {
        soma_venda = soma_venda + aux->preco_venda;
        aux = aux->proximo;
    }
    lucro = soma_venda + soma_estoque;
    printf("%d", lucro);
}

/*
void vender(No **No, No **No_2)
{
int valor_negociado;
printf("qual o valor da venda:");
    scanf("%d", &valor_negociado);
    No *aux = *No;
    No *remover;
    remover = busca_Nome(*No,valor_negociado);
    remover_No(&No,valor_negociado);
    inserir_ordenado_2(&No_2,remover);
}
*/

No *busca_Nome(No *No,int valor_negociado){
    
    char modelo[40];
    printf("Insira o modelo do carro:");
    scanf("%s", modelo);
    fflush(stdin);
    
     while (No->proximo != NULL){
        if (strcmp(modelo, No->Nome) == 0){
            return No;
     }
     No=No->proximo;
     if(No->proximo==NULL){
         if (strcmp(modelo, No->Nome) != 0)
            {
                printf("carro nao encontrado");
            }
            else if (valor_negociado < No->preco_venda)
            {
                printf("o valor de venda está abaixo do valor de compra, venda não permitida");
            }else printf("carro nao encontrado");
     }
    }
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
        if (strcmp(node->Nome, (*lista)->Nome) < 0)
        { // Inserindo inicio
            node->proximo = (*lista);
            node->anterior = NULL;
            (*lista)->anterior = node;
            (*lista) = node;
            return;
        }

        No *aux = *lista;
        No *anterior = NULL;

        while (aux != NULL && strcmp(node->Nome, aux->Nome) >= 0)
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
        else{
        node->proximo = NULL; // Inserindo fim
        node->anterior = anterior;
        anterior->proximo = node;
        }
    }
    return;
}

int main()
{
    No *a_vender = NULL;
    No *vendido = NULL;
    No *node = NULL;
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
            inserir_ordenado(&a_vender,node);
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
            busca_aNo(a_vender);
            break;

        case 6:
            lucro(a_vender, vendido);
            break;
        case 7:
            //vender(&a_vender, &vendido);
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    }
    return 0;
}
