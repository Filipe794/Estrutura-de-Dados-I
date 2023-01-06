#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;
typedef struct
{
    No *inicio, *fim;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor)
{
    No *Novo = (No *)malloc(sizeof(No)); // cria um Novo nó
    Novo->valor = valor;
    if (lista->inicio == NULL){
        Novo->proximo = NULL;
        /*cabeca*/ lista->inicio = Novo;
        lista->fim = Novo;
    }
    else{ // a lista não estiver vazia
        Novo->proximo = lista->inicio;
        lista->inicio = Novo;
    }
    lista->tam++;
}
void inserirFim(Lista *lista, int valor)
{
    No *Novo = (No *)malloc(sizeof(No));
    Novo->valor = valor;
    Novo->proximo = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = Novo;
        lista->fim = Novo;
    }
    else
    {
        lista->fim->proximo = Novo;
        lista->fim = Novo;
    }
    lista->tam++;
}
void imprimir(Lista *lista)
{
    No *inicio = lista->inicio;
    printf("tamanho da lista: %d\n", lista->tam);
    while (inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
// remover um elemento da lista
void remover(Lista *lista, int valor){
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No *NoARemover = NULL;      // ponteiro para o nó a ser removido

    if (inicio != NULL && lista->inicio->valor == valor){ // remover 1º elemento
        NoARemover = lista->inicio;
        lista->inicio = NoARemover->proximo;
        if (lista->inicio == NULL)
            lista->fim = NULL;
    }
    else{ // remoção No meio ou No final
        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor)
        {
            inicio = inicio->proximo;
        }
        if (inicio != NULL && inicio->proximo != NULL)
        {
            NoARemover = inicio->proximo;
            inicio->proximo = NoARemover->proximo;
            if (inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if (NoARemover){
        free(NoARemover); // libera a memória do nó
        lista->tam--;     // decrementa o tamanho da lista
    }
}
void ordem_crescente(Lista *lista){
    Lista *ordem=lista->inicio;
    int cont=0;
    ordem->inicio=lista->inicio->proximo;
    //testar se o elemento atual é meNor q o seu proximo
    while((lista->inicio)!=NULL){
        if((lista->inicio->valor)<(ordem->inicio->valor)){
            cont++;
        }
    } 
    if(cont==lista->tam){
        printf("A lista está ordenada");
    }else{
        printf("A lista nao está ordenada");
    }
}
void tamanho(Lista *lista){
    No *inicio = lista->inicio;
    int cont=0;
    while (inicio != NULL){
        cont++;
        inicio = inicio->proximo;
    }
    printf("A lista tem %d elementos",cont);
}
void inserir_inicio(No **lista,int localizador){// com ponteiro pra ponteiro
    No *Novo = malloc(sizeof(No));
    Novo->valor=localizador;
    Novo->proximo=*lista;
    *lista=Novo;
}

void inserir_No_meio(No **lista,int localizador, int ant){// recebe o valor a ser inserido e o valor de referencia para procurar a posição a ser inserido
    No *aux,*Novo = malloc(sizeof(No));

    if(Novo){
        Novo->valor=localizador;
        if(*lista==NULL){
            *lista=Novo;
        }else{
            aux=*lista;
            while(aux->valor!=ant && aux->proximo){
                aux = aux->proximo;
                Novo->proximo=aux->proximo;
                aux->proximo=Novo;
            }
        }
    }
}

int main() {
    Lista lista, listaI, listaP; // criação de 3 listas
    int opcao, valor;

    // inicialização das listas
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    listaI.inicio = NULL;
    listaI.fim = NULL;
    listaI.tam = 0;

    listaP.inicio = NULL;
    listaP.fim = NULL;
    listaP.tam = 0;

    do { // menu de opções
        printf("1 - Inserir No inicio\n2 - Imprimir\n3 - Inserir No fim\n4 - Remover\n6 - verificar ordem\n5 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            printf("\nLista original:\n");
            imprimir(&lista);
            printf("\nLista impar:\n");
            imprimir(&listaI);
            printf("\nLista par:\n");
            imprimir(&listaP);
            break;
        case 3:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&lista, valor);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        case 6:
            tamanho(lista.inicio);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

    return 0;
}