#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
    char Nome[50];
    char plaNo_saude[100];
    int idade;
    struct elem *prox;
} paciente;

void enqueue(paciente **last, paciente *e, paciente **first = NULL){
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

paciente *dequeue(paciente **first, paciente **last = NULL){
    if (*first == NULL)
    {
        return NULL;
    }
    paciente *front = *first;
    (*first) = (*first)->prox;
    if (*first == NULL)
    {
        *last == NULL;
    }
    front->prox = NULL;
    return front;
}

void print(paciente *aux){
    while (aux != NULL){
        printf("%s\n", aux->Nome);
        printf("%s\n", aux->plaNo_saude);
        printf("%d\n", aux->idade);
        aux = aux->prox;
    }
    printf("NULL\n");
}
int passagems_na_frente(paciente *first, char *Nome){

    int s = 0;
    while (first != NULL){
        
        if (strcmp(first->Nome, Nome) == 0){
            return s;
        }
        first = first->prox;
        s++;
    }
    return -1;
}

int main(){
    paciente *first = NULL, *last = NULL;
    int tam;
    printf("qual o tamanho da fila?");
    scanf("%d", &tam);
    for (int i = 1; i <= tam; i++){
        paciente *e = (paciente *)malloc(sizeof(paciente));
        printf("Insira o Nome do paciente: ");
        scanf("%s", e->Nome);
        printf("Insira o plaNo de saude do paciente: ");
        scanf("%s", e->plaNo_saude);
        printf("Insira a idade do paciente: ");
        scanf("%d", &e->idade);
        if (first == NULL){
            enqueue(&last, e, &first);
        }
        else enqueue(&last, e);
    }
    print(first);
    char Nome[30];
    printf("passagem a ser procurada: ");
    scanf("%s", Nome);
    printf("passagems na frente: %d", passagems_na_frente(first,Nome));
    return 0;
}