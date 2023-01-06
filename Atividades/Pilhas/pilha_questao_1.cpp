#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    char Nome[50];
    char link[100];
    struct elem *prox;
} paciente;

void push(paciente **top) {
    paciente *e = (paciente *)malloc(sizeof(paciente));
    printf("Nome do site: ");
    scanf("%s",e->Nome);
    printf("link do site: ");
    fflush(stdin);
    scanf("%s",e->link);
    fflush(stdin);
    e->prox = *top;
    *top = e;
}
paciente *pop(paciente **top) {
  if (*top == NULL) {
    return NULL;
  }
  paciente *p = *top;
  *top = (*top)->prox;
  p->prox = NULL;
  return p;
}
paciente *voltar(paciente *top,int n){
    for(int i=0;i<n;i++){
        pop(&top);
    }
    return top;
}
void print_sites(paciente *top){
    if(top==NULL){
        printf("NULL");
        return;
    }
    while(top!=NULL){
    printf("Nome do site: %s\nlink do site: %s", top->Nome,top->link);
    top=top->prox;
    }
}
void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("\t1 - Adicionar Site\t\n");
  printf("\t2 - Voltar Site\t\n");
  printf("\t3 - Imprimir Sites\t\n");
  printf("\t0 - Sair\t\t*\n");
}
int main(){
    paciente *top=NULL;
    int op=-1;
    int qnt_voltar;
    paciente *Nova;
    while(op!=0){
        imprimir_menu();
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1:
            push(&top);
            break;
            case 2:
            printf("quantos sites voltar: ");
            scanf("%d", &qnt_voltar);
            top = voltar(top,qnt_voltar);
            break;
            case 3:
            print_sites(top);
            break;
        }
    }
    return 0;
}