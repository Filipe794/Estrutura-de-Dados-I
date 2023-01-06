#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

void merge(paciente **first_1,paciente **first_2,paciente **last_1,paciente **last_2){
    if(*first_1==NULL){
        first_1=first_2;
        last_1=last_2;
        return;
    }
    if(*first_2==NULL) return;
    (*last_1)->prox=*first_2;
    last_1=last_2;
    last_2=NULL;
    first_2=NULL;
    return;
}
int main(){
    paciente *first_1=NULL,*first_2=NULL,*last_1=NULL,*last_2=NULL;
    int tam;
    printf("qual o tamanho da fila 1?");
    scanf("%d", &tam);
    for (int i = 1; i <= tam; i++){
        paciente *e = (paciente *)malloc(sizeof(paciente));
        printf("Insira um valor: ");
        scanf("%d", &e->conteudo);
        if (first_1 == NULL){
            enqueue(&last_1, e, &first_1);
        }
        else enqueue(&last_1, e);
    }
    printf("qual o tamanho da fila 2?");
    scanf("%d", &tam);
    for (int i = 1; i <= tam; i++){
        paciente *e = (paciente *)malloc(sizeof(paciente));
        printf("Insira um valor: ");
        scanf("%d", &e->conteudo);
        if (first_2 == NULL){
            enqueue(&last_2, e, &first_2);
        }
        else enqueue(&last_2, e);
    }
    print(first_1);
    merge(&first_1,&first_2,&last_1,&last_2);
    print(first_1);
    return 0;
}