#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  char Nome[30];
  float n1;
  float n2;
  float n3;
  float media;
  struct lista *prox;
}AluNo;

void aluNo_maior_media(AluNo *p) {
  AluNo *aux = p;
  int maior=0;
  while(p!=NULL){
    if(p->media>maior){
      maior=p->media;
      aux=p;
    }
    p=p->prox;
  }
  printf("%s(%.1f,%.1f,%.1f) --> ", aux->Nome,aux->n1,aux->n2,aux->n3);

}

void aluNos_recuperacao(AluNo **p) {
  AluNo *aux=*p;
  AluNo *ant=NULL;
  AluNo *remover;
  while(aux!=NULL){
    if(aux->media>7){
      if(aux==*p){
        *p=aux->prox;
        remover=aux;
        free(remover);
      }else{
        ant->prox=aux->prox;
        ant=aux;
        remover=aux;
        aux=aux->prox;
        free(remover);
        continue;
      }
      }else {
      printf("ALUNo DE RECUPERAÇÃO:");
      printf("%s", aux->Nome);
      }
     ant=aux;
     aux=aux->prox;
  }
}

AluNo* adiciona_aluNo(AluNo *p) {

  AluNo *Novo=(AluNo*)malloc(sizeof(AluNo));

  printf("Digite o Nome do aluNo: ");
  scanf("%s",&Novo->Nome);

  printf("Digite a 1ª Nota do aluNo: ");
  scanf("%f",&Novo->n1);

  printf("Digite a 2ª Nota do aluNo: ");
  scanf("%f",&Novo->n2);

  printf("Digite a 3ª Nota do aluNo: ");
  scanf("%f",&Novo->n3);
  Novo->media=(Novo->n1+Novo->n2+Novo->n3)/3;
  Novo->prox=p;

  return Novo;
}

void imprimir(AluNo *p){
  printf("Lista de aluNos:\n");
  while(p!=NULL){
    printf("%s(%.1f,%.1f,%.1f) --> ", p->Nome,p->n1,p->n2,p->n3);
    p=p->prox;
  }
  printf("NULL\n");
}

void desaloca_lista(AluNo* p){
  AluNo *prox = p;
  while (p != NULL) {
    prox = p->prox;
    free(p);
    p = prox;
  }
}

int main(int argc, char **argv) {

  AluNo* cabeca = NULL;

  int opt=0;
  do{
    if(opt!=0){
      printf("\nAperte Enter para continuar\n");
      getchar();
      getchar();
    }
    printf("\n|\t**********************************\t|\n");
    printf("|\t\t\tMENU\t\t\t|\n");
    printf("|\t1-Adicionar aluNo\t\t\t|\n");
    printf("|\t2-Imprimir lista\t\t\t|\n");
    printf("|\t3-Imprimir aluNo com maior média\t|\n");
    printf("|\t4-Imprimir aluNos de recuperação\t|\n");
    printf("|\t0-Sair\t\t\t\t\t|\n");
    printf("|\t**********************************\t|\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opt);
    printf("\n");
    switch (opt) {
      case 1:
        cabeca=adiciona_aluNo(cabeca);
        break;
      case 2:
        imprimir(cabeca);
        break;
      case 3:
        aluNo_maior_media(cabeca);
        break;
      case 4:
        aluNos_recuperacao(&cabeca);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }

  }while (opt!=0);

  desaloca_lista(cabeca);

  return 0;
}
