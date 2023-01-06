#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int localizador;
    char data[10];
    float preco;
    char destiNo[50];
} passagem;

typedef struct Node
{
    passagem passagem;
    struct Node *esquerda;
    struct Node *direita;
    int teste;
} No;

typedef struct // struct para armazenar os valores do relatorio, para nao encher de variaveiz globais
{
    float valor; // valor total das passagens de cada pais
    int qtde;    // quantidade total de passagens de cada pais
} relatorio;

// raizes pras arvores
No *root_br = NULL;
No *root_ar = NULL;
No *root_consolidada = NULL;

// contadores para arrecadacao de cada arvores
// vou usar na funcao faturamento
float arrecadacao = 0;
int qnt_passagens = 0;

// struct para armazenar do faturamento de cada arvore
relatorio fatura;

int loc()
{
    int loc = rand() % 100; // gerando um localizadorero aleatorio
    while (loc == 0)        // evitando q o localizador seja 0
    {
        loc = rand() % 100;
    }
    return loc;
}

int buscar_localizador(No *Node, int localizador)
{

    if (Node == NULL) // caso o nó seja nulo, não há oq testar
    {
        return 0;
    }

    if (Node->passagem.localizador == localizador)
    {
        return 1; // caso o localizador ja exista, retorna 1
    }

    // recursividade para procurar nas subarvores
    buscar_localizador(Node->direita, localizador);
    buscar_localizador(Node->esquerda, localizador);

    return 0;
}

int gerar_localizador()
{
    int localizador = loc(); // recebe o valor gerado pela função loc
    while ((buscar_localizador(root_br, localizador) == 1 || buscar_localizador(root_ar, localizador) == 1))
    { // equanto a função busca_localizador retornar 1 para qualquer uma das arvores será gerado um Novo localizador
        localizador = loc();
    }
    return localizador;
}

No *criar_No()
{

    No *Node = (No *)malloc(sizeof(No));

    printf("Insira a data da viagem (use o formato DD/MM/AAAA): ");
    scanf("%s", Node->passagem.data);
    fflush(stdin);
    printf("Insira o preço da passagem: ");
    scanf("%f", &Node->passagem.preco);
    fflush(stdin);
    printf("Insira o destiNo: ");
    scanf("%50[^\n]s", Node->passagem.destiNo);
    fflush(stdin);

    Node->passagem.localizador = gerar_localizador(); // o campo localizador do nó recebe o valor retornado pela função gerar_localizador

    Node->esquerda = NULL;
    Node->direita = NULL;

    return Node;
}

No *preencher_arvore(char *data, float preco, char *destiNo)
{

    No *Node = (No *)malloc(sizeof(No));

    strcpy(Node->passagem.data, data);
    fflush(stdin);

    Node->passagem.preco = preco;
    fflush(stdin);

    strcpy(Node->passagem.destiNo, destiNo);
    fflush(stdin);

    Node->passagem.localizador = gerar_localizador();

    Node->esquerda = NULL;
    Node->direita = NULL;

    return Node;
}

void inserir_No(No *Node, No *Novo)
{
    if (Node == NULL)
    {
        printf("Erro\n");
        return;
    }

    if (Node->passagem.localizador < Novo->passagem.localizador)
    {   // caso o localizador do nó a ser inserido seja maior que o localizador do nó que está na raiz
        // o nó a ser inserido irá para a direita da raiz

        if (Node->direita == NULL) // testando se o nó da direita está nulo
        {                      // caso esteja, o nó Novo sera inserido aqui
            Node->direita = Novo;
            return;
        }
        inserir_No(Node->direita, Novo); // caso nao esteja nulo, chamará recursivamente a função de inserir nó
                                     // para continuar procurando onde inserir o nó
    }
    else
    {   // caso o localizador do nó a ser inserido seja meNor que o localizador do nó que está na raiz
        // o nó a ser inserido irá para a esquerda da raiz
        if (Node->esquerda == NULL)
        {
            Node->esquerda = Novo;
            return;
        }
        inserir_No(Node->esquerda, Novo);
    }
}

void inserir_teste(No **raiz, char *data, float preco, char *destiNo)
{

    if ((*raiz) == NULL)
    {
        *raiz = preencher_arvore(data, preco, destiNo);
        return;
    }

    No *Novo = preencher_arvore(data, preco, destiNo);
    inserir_No(*raiz, Novo);
}

void imprimir(No *Node) // função para imprimir a arvore
{
    if (Node == NULL)
    {
        return;
    }
    printf("DestiNo: %s -> ", Node->passagem.destiNo);
    printf("Preço: %f reais -> ", Node->passagem.preco);
    printf("Data: %s -> ", Node->passagem.data);
    printf("Localizador: %d\n", Node->passagem.localizador);
    imprimir(Node->direita);
    imprimir(Node->esquerda);
}

void imprimir_folha(No *Node) // função para imprimir apenas uma folha da arvore (usada na busca por destiNo)
{
    printf("DestiNo: %s -> ", Node->passagem.destiNo);
    printf("Preço: %f reais -> ", Node->passagem.preco);
    printf("Data: %s -> ", Node->passagem.data);
    printf("Localizador: %d\n", Node->passagem.localizador);
}

void inserir_raiz(No **raiz) // metodo para inserir uma folha na arvore
{

    if ((*raiz) == NULL) // se a raiz for nula, ja insere a Nova folha na raiz e encerra a função
    {
        *raiz = criar_No();
        return;
    }
    // caso a raiz nao seja nula, irá criar um Novo nó e chamar a função inserir nó;
    No *Novo = criar_No();
    inserir_No(*raiz, Novo);
}

void buscar_destiNo(No *Node, char *destiNo)
{

    if (Node == NULL) // caso o nó seja nulo, retorna
    {
        return;
    }

    if (strcmp(Node->passagem.destiNo, destiNo) == 0) // se encontrar o destiNo inserido pelo usuario irá imprimir e continuar procurando
    {
        imprimir_folha(Node);
    }

    buscar_destiNo(Node->direita, destiNo);
    buscar_destiNo(Node->esquerda, destiNo);

    return;
}

void faturamento(No *Node)
{

    if (Node == NULL)
    {
        return;
    }
    arrecadacao += Node->passagem.preco; // adiciona o preco da passagem de determinado nó
                                         // ao contador global "arrecadacao"
    qnt_passagens++;                     // adiciona 1 ao contador global "qnt_passagens"

    faturamento(Node->direita);
    faturamento(Node->esquerda);

    // armazenando localizadora struct (também global) depois de percorrer toda a arvore, para na função imprimir_global
    // poder imprimir o valor arrecadado em ambos os paises
    fatura.valor = arrecadacao;
    fatura.qtde = qnt_passagens;
}

void faturamento_global()
{
    int qtde_br;    // irá armazenar a quantidade de passagens que existem No brasil
    float valor_br; // ira armazenar a arrecadacao total das passagens No brasil

    faturamento(root_br); // ira fzr o faturamento No brasil

    valor_br = fatura.valor; // recebe o valor que esta armazenado na struct
    qtde_br = fatura.qtde;   // pois na proxima vez q chamar a funcao faturamento esses valores serao substituidos

    // zerando os contadores para não acumularem
    arrecadacao = 0;
    qnt_passagens = 0;

    faturamento(root_ar); // realizando o faturamento na argentina

    // zerando os contadores para não acumularem
    arrecadacao = 0;
    qnt_passagens = 0;

    // imprimindo o valor arrecadado que está armazenado na struct, referente à argentina somado com as variaveis
    // que armazenaram o do brasil
    printf("Faturamento Global: %f\n", fatura.valor + valor_br);
    printf("Quantidade Global de passagens Vendidas: %d\n", fatura.qtde + qtde_br);
}

void menu()
{

    printf("------MENU-----\n");
    printf("1-Inserir Passagem para Brasil\n");
    printf("2-Inserir Passagem para Argentina\n");
    printf("3-Buscar Passagem para Brasil\n");
    printf("4-Buscar Passagem para Argentina\n");
    printf("5-Imprimir Arvore Brasil\n");
    printf("6-Imprimir Arvore Argentina\n");
    printf("7-Faturamento Brasil\n");
    printf("8-Faturamento Argentina\n");
    printf("9-Faturamento Global\n");
    printf("10-Consolidar Vendas\n");
    printf("11-Imprimir Arvore Consolidada\n");
    printf("0-Sair\n");
}

void inserir_consolidada(No **root, No *Node)
{
    // metodo de inserir para a arvore consolidada, o teste da raiz nula está aqui dentro desse metodo
    if (*root == NULL)
    {
        *root = Node;
        return;
    }

    if ((*root)->passagem.localizador < Node->passagem.localizador)
    {
        if ((*root)->direita == NULL)
        {
            (*root)->direita = Node;
            return;
        }
        inserir_consolidada(&(*root)->direita, Node);
    }
    else
    {
        if ((*root)->esquerda == NULL)
        {
            (*root)->esquerda = Node;
            return;
        }
        inserir_consolidada(&(*root)->esquerda, Node);
    }
}

void consolidar(No *Node)
{

    if (Node == NULL)
    {
        return;
    } // testa se a raiz da arvore q foi passada é nula

    inserir_consolidada(&root_consolidada, Node); // chama a função para preencher a arvore consolidada
}

// /*
//       função para remover nós da Árvore binária
// */
// No* remover(No *raiz, int chave) {
//     if(raiz == NULL){
//         printf("Valor nao encontrado!\n");
//         return NULL;
//     } else { // procura o nó a remover
//         if(raiz->passagem.localizador == chave) {
//             // remove nós folhas (nós sem filhos)
//             if(raiz->esquerda == NULL && raiz->direita == NULL) {
//                 free(raiz);
//                 printf("Elemento folha removido: %d !\n", chave);
//                 return NULL;
//             }
//             else{
//                 // remover nós que possuem 1 ou 2 filhos
//             }
//         } else {
//             if(chave < raiz->passagem.localizador)
//                 raiz->esquerda = remover(raiz->esquerda, chave);
//             else
//                 raiz->direita = remover(raiz->direita, chave);
//             return raiz;
//         }
//     }
// }

// void limpar_arvore(No *root){
//     if (root == NULL)
//   {
//     return;
//   }

//   remover(root,root->passagem.localizador);

//   limpar_arvore(root->direita);
//   limpar_arvore(root->esquerda);
// }

No *Maiordireita(No **No)
{
    if ((*No)->direita != NULL)
        return Maiordireita(&(*No)->direita);
    else
    {
        No *aux = *No;
        if ((*No)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *No = (*No)->esquerda;
        else
            *No = NULL;
        return aux;
    }
}

No *MeNoresquerda(No **No)
{
    if ((*No)->esquerda != NULL)
        return MeNoresquerda(&(*No)->esquerda);
    else
    {
        No *aux = *No;
        if ((*No)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
            *No = (*No)->direita;
        else
            *No = NULL;
        return aux;
    }
}

void remover(No **pRaiz, int localizadorero)
{
    if (*pRaiz == NULL)
    { // esta verificacao serve para caso o localizadorero nao exista na arvore.
        printf("localizadorero nao existe na arvore!");
        return;
    }
    if (localizadorero < (*pRaiz)->passagem.localizador)
        remover(&(*pRaiz)->esquerda, localizadorero);
    else if (localizadorero > (*pRaiz)->passagem.localizador)
        remover(&(*pRaiz)->direita, localizadorero);
    else
    {                      // se nao eh meNor nem maior, logo, eh o localizadorero que estou procurando! :)
        No *pAux = *pRaiz; // quem programar No Embarcadero vai ter que declarar o pAux No inicio do void! :[
        if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL))
        { // se nao houver filhos...
            free(pAux);
            (*pRaiz) = NULL;
        }
        else
        { // so tem o filho da direita
            if ((*pRaiz)->esquerda == NULL)
            {
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else
            { // so tem filho da esquerda
                if ((*pRaiz)->direita == NULL)
                {
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else
                {                                             // Escolhi fazer o maior filho direitaeito da subarvore esquerda.
                    pAux = Maiordireita(&(*pRaiz)->esquerda); // se vc quiser usar o MeNor da esquerda, so o que mudaria seria isso:
                    pAux->esquerda = (*pRaiz)->esquerda;      //        pAux = MeNoresquerda(&(*pRaiz)->direita);
                    pAux->direita = (*pRaiz)->direita;
                    (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                    free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}

void limpar_arvore(No *root){

}

int main()
{
    srand(time(NULL)); // semente do random

    inserir_teste(&root_br, "12/12/2012", 3400, "sao paulo");

    inserir_teste(&root_br, "17/12/2013", 4400, "sao paulo");

    inserir_teste(&root_br, "16/12/2014", 5400, "fortaleza");

    inserir_teste(&root_br, "15/12/2015", 6400, "timon");

    inserir_teste(&root_br, "14/12/2016", 7400, "rio de janeiro");

    inserir_teste(&root_br, "13/12/2017", 8400, "floriaNopolis");

    inserir_teste(&root_ar, "12/12/2012", 3635, "bueNos aires");

    inserir_teste(&root_ar, "15/42/2042", 8674, "bueNos aires");

    inserir_teste(&root_ar, "17/67/2098", 1425, "cordoba");

    inserir_teste(&root_ar, "15/75/2087", 7969, "lima");

    inserir_teste(&root_ar, "19/34/2023", 8978, "boca juniors");

    inserir_teste(&root_ar, "11/09/2045", 6894, "river plate");

    printf("\n\nIMPRIMINDO ANTES DE LIMPAR\n\n");
    imprimir(root_br);
    printf("\n\n");
    imprimir(root_ar);
    printf("\n\n");
    remover(&root_br,5);
    remover(&root_ar,4);
    printf("\n\nIMPRIMINDO DEPOIS DE LIMPAR\n\n");
    imprimir(root_br);
    printf("\n\n");
    printf("\n\n");
    imprimir(root_ar);

    //   int opc = 1;
    //   char destiNo[50];

    //   while (opc != 0)
    //   {
    //     menu();
    //     scanf("%d", &opc);
    //     fflush(stdin);
    //     switch (opc)
    //     {
    //     case 1:
    //       inserir_raiz(&root_br);
    //       break;

    //     case 2:
    //       inserir_raiz(&root_ar);
    //       break;

    //     case 3:
    //       printf("Digite o destiNo a ser procurado: ");
    //       scanf("%50[^\n]s", destiNo);
    //       buscar_destiNo(root_br, destiNo);
    //       break;

    //     case 4:
    //       printf("Digite o destiNo a ser procurado: ");
    //       scanf("%50[^\n]s", destiNo);
    //       buscar_destiNo(root_ar, destiNo);
    //       break;

    //     case 5:
    //       imprimir(root_br);
    //       break;

    //     case 6:
    //       imprimir(root_ar);
    //       break;

    //     case 7:
    //       faturamento(root_br);
    //       printf("Faturamento: %f\n", fatura.valor);
    //       printf("Quantidade de passagens Vendidas: %d\n", fatura.qtde);
    //       arrecadacao = 0; //zerando o contador de arrecadação para nao acumular
    //       qnt_passagens = 0; //zerando o contador de passagens para nao acumular
    //       break;

    //     case 8:
    //       faturamento(root_ar);
    //       printf("Faturamento: %f\n", fatura.valor);
    //       printf("Quantidade de passagens Vendidas: %d\n", fatura.qtde);
    //       arrecadacao = 0;
    //       qnt_passagens = 0;
    //       break;

    //     case 9:
    //       faturamento_global();
    //       break;

    //     case 10:
    //     // a funcao consolidar só realiza o processo para uma arvore de cada vez
    //       consolidar(root_br);
    //       consolidar(root_ar);
    //       root_ar=NULL;// depois de consolidar, fazer os ponteiros pras raizes das arvores
    //       root_br=NULL; // apontarem para nulo, para reiniciar o aNo;
    //       break;

    //     case 11:
    //       imprimir(root_consolidada);
    //       break;

    //     case 0:
    //       break;

    //     default:
    //       printf("Opção inválida\n");
    //       break;
    //     }
    //   }

    return 0;
}