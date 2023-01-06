#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem
{
    char Nome[50];
    char nivel[15];
    char cpf[11];
    struct elem *prox;

} paciente;

int emergencia = 0;
int urgencia = 0;
int eletivo = 0;
int chamada = 0;

paciente *primeiro_emergencia = NULL, *ultimo_emergencia = NULL;
paciente *primeiro_urgencia = NULL, *ultimo_urgencia = NULL;
paciente *primeiro_eletivo = NULL, *ultimo_eletivo = NULL;

void menu()
{
    printf("----------------MENU---------------------\n");
    printf("1- Inserir Paciente como Emergencia\n");
    printf("2- Inserir Paciente como Urgencia\n");
    printf("3- Inserir Paciente como Eletivo\n");
    printf("4- Chamar proximo\n");
    printf("5- Quantidade de passagems na frente\n");
    printf("6- Quantidade de atendimentos realizados\n");
    printf("7- Imprimir filas\n");
    printf("0- Sair\n");
}

paciente *dequeue(paciente **first, paciente **last)
{
    if (*first == NULL)
    {
        return NULL;
    }
    paciente *front = *first;
    (*first) = (*first)->prox;
    if (*first == NULL)
    {
        *last = NULL;
    }
    front->prox = NULL;
    return front;
}

void enqueue(paciente **last, paciente *e, paciente **first)
{
    if (e == NULL)
        return;
    e->prox = NULL;
    if (*last == NULL)
    {
        *first = e;
        *last = e;
        return;
    }
    (*last)->prox = e;
    *last = e;
}

void print(paciente *aux)
{
    if (aux == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("Paciente: %s-> ", aux->Nome);
    printf("CPF: %s-> ", aux->cpf);
    printf("%s", aux->nivel);
    printf("\n");
}
void print_fila(paciente *aux)
{
    while (aux != NULL)
    {
        print(aux);
        aux = aux->prox;
    }
    printf("NULL\n\n");
}

int passagems_na_frente(char *cpf)
{

    paciente *emergencia = primeiro_emergencia;
    paciente *urgencia = primeiro_urgencia;
    paciente *eletivo = primeiro_eletivo;

    if (emergencia == NULL && urgencia == NULL && eletivo == NULL)
        return -2;

    int cont_paciente = -1;
    int cont_urg = 0;
    int cont_ele = 0;

    while (emergencia != NULL)
    {

        cont_paciente++;

        if (strcmp(emergencia->cpf, cpf) == 0)
        {
            return cont_paciente;
        }

        emergencia = emergencia->prox;
    }

    while (urgencia != NULL || eletivo != NULL)
    {

        while (cont_urg != 3 && urgencia != NULL)
        {

            cont_paciente++;
            cont_urg++;
            cont_ele = 0;

            if (strcmp(emergencia->cpf, cpf) == 0)
            {
                return cont_paciente;
            }

            urgencia = urgencia->prox;

            if (eletivo == NULL)
            {
                cont_urg = 0;
            }
        }

        while (cont_ele != 1 && eletivo != NULL)
        {

            cont_paciente++;
            cont_ele++;
            cont_urg = 0;

            if (strcmp(emergencia->cpf, cpf) == 0)
            {
                return cont_paciente;
            }
            eletivo = eletivo->prox;
            if (urgencia == NULL)
            {
                cont_ele = 0;
            }
        }
    }
    return -1;
}

paciente *criar_paciente(char *nivel)
{
    paciente *e = (paciente *)malloc(sizeof(paciente));
    printf("Insira o cpf do paciente: ");
    scanf("%s", e->cpf);
    fflush(stdin);
    int teste = passagems_na_frente(e->cpf);
    if (teste > -1)
    {
        printf("\nCPF ja registrado\n\n");
        free(e);
        return NULL;
    }
    printf("Insira o Nome do paciente: ");
    scanf("%s", e->Nome);
    while (strcmp(e->Nome, " ") == 0)
    {
        printf("Insira um Nome válido");
        printf("Insira o Nome do paciente: ");
        scanf("%s", e->Nome);
        fflush(stdin);
    }
    fflush(stdin);
    strcpy(e->nivel, nivel);
    fflush(stdin);
    printf("\n");
    return e;
}

paciente *next()
{

    paciente *proximo = NULL;

    if (primeiro_emergencia != NULL)
    {
        proximo = dequeue(&primeiro_emergencia, &ultimo_emergencia);
        emergencia++;
        return proximo;
    }
    if (primeiro_urgencia != NULL && (chamada % 3 != 0 || chamada == 0))
    {
        proximo = dequeue(&primeiro_urgencia, &ultimo_urgencia);
        chamada++;
        urgencia++;
        return proximo;
    }
    if (primeiro_eletivo != NULL)
    {
        proximo = dequeue(&primeiro_eletivo, &ultimo_eletivo);
        chamada++;
        eletivo++;
        return proximo;
    }
    return NULL;
}

void total_atendimentos(){
    printf("Emergencia: %d\n", emergencia);
    printf("Urgencia: %d\n", urgencia);
    printf("Eletivo: %d\n", eletivo);
    printf("Total: %d\n", urgencia + eletivo + emergencia);
}

int main()
{
    int opc = -1;
    while (opc != 0)
    {
        menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            enqueue(&ultimo_emergencia, criar_paciente("emergencia"), &primeiro_emergencia);
            break;

        case 2:
            enqueue(&ultimo_urgencia, criar_paciente("urgencia"), &primeiro_urgencia);
            break;
        case 3:
            enqueue(&ultimo_eletivo, criar_paciente("eletivo"), &primeiro_eletivo);
            break;

        case 4:
            print(next());
            break;
        case 5:
            int tam;
            char cpf[11];
            printf("Insira o cpf a ser procurado:\n");
            scanf("%s", cpf);
            tam = passagems_na_frente(cpf);
            if (tam == -2)
            {
                printf("As filas estão vazias\n");
                break;
            }
            if (tam == -1)
            {
                printf("CPF nao encontrado\n");
                break;
            }
            printf("Existem %d passagems na frente\n\n", tam);
            break;

        case 6:
            total_atendimentos();
            break;
        case 7:
            printf("FILA EMERGENCIA\n");
            print_fila(primeiro_emergencia);
            printf("FILA URGENCIA\n");
            print_fila(primeiro_urgencia);
            printf("FILA ELETIVO\n");
            print_fila(primeiro_eletivo);
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