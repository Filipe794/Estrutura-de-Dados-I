#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct No
{
    char Nome[40];
    int aNo_fabricacao, preco_compra, preco_venda;
    struct No *proximo;
    struct No *anterior;

} No;

void inserir_No_inicio(No **lista, No *Novo)
{

    Novo->proximo = *lista;
    Novo->anterior = NULL;

    if (*lista != NULL)
    {

        (*lista)->anterior = Novo;
    }

    *lista = Novo;
}

void ler_No(No *No)
{

    printf("Digite o Nome do veiculo: ");
    scanf("%s", No->Nome);
    fflush(stdin);

    printf("Digite o aNo de fabricação: ");
    scanf("%d", &No->aNo_fabricacao);

    printf("Digite o valor de compra: ");
    scanf("%d", &No->preco_compra);

    No->preco_venda = (No->preco_compra * 1.2);
}

void inserir_ordenado(No **lista)
{

    No *aux, *Novo = (No *)malloc(sizeof(No));
    ler_No(Novo);
    if (*lista == NULL)
    {

        Novo->proximo = NULL;
        Novo->anterior = NULL;

        *lista = Novo;
    }
    else if (strcmp(Novo->Nome, (*lista)->Nome) < 0)
    {
        Novo->proximo = *lista;
        Novo->anterior = NULL;
        if (*lista != NULL)
        {
            (*lista)->anterior = Novo;
        }
        *lista = Novo;
    }
    else
    {
        aux = *lista;
        while (aux->proximo != NULL && strcmp(Novo->Nome, aux->Nome) > 0)
        {
            aux = aux->proximo;
        }
        Novo->proximo = aux;
        Novo->anterior = aux->anterior;
        aux->anterior->proximo = Novo;
        aux->anterior = Novo;
    }
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

        printf("aNo de fabricação: %d\n", No->aNo_fabricacao);

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

            printf("aNo de fabricação: %d\n", No->aNo_fabricacao);

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
        if (No->aNo_fabricacao == valor)
        {
            printf("Nome do veiculo: %s\n", No->Nome);

            printf("aNo de fabricação: %d\n", No->aNo_fabricacao);

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

void inserir_ordenado_2(No **lista, No *Novo)
{

    No *aux;
    if (*lista == NULL)
    {
        Novo->proximo = NULL;
        Novo->anterior = NULL;
        *lista = Novo;
    }
    else if (strcmp(Novo->Nome, (*lista)->Nome) < 0)
    {
        Novo->proximo = *lista;
        Novo->anterior = NULL;
        if (*lista != NULL)
        {
            (*lista)->anterior = Novo;
        }
        *lista = Novo;
    }
    else
    {
        aux = *lista;
        while (aux->proximo != NULL && strcmp(Novo->Nome, aux->Nome) > 0)
        {
            aux = aux->proximo;
        }
        Novo->proximo = aux;
        Novo->anterior = aux->anterior;
        aux->anterior->proximo = Novo;
        aux->anterior = Novo;
    }
}


int main()
{
    No *a_vender = NULL;
    No *vendido = NULL;
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
            inserir_ordenado(&a_vender);
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
