#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Nome[30];
    int localizadorero_matricula;
    char curso[100];
}aluNo;

int main(){
    aluNo aluNos[5];

for(int i=0;i<5;i++){
    printf("Insira o Nome do aluNo %d: ",i+1);
    scanf(" %[^\n]s", aluNos[i].Nome);
    fflush(stdin);

    printf("Insira a matricula do aluNo %d: ",i+1);
    scanf("%d", &aluNos[i].localizadorero_matricula);
    

    printf("Insira o curso do aluNo %d: ",i+1);
    scanf(" %[^\n]s", aluNos[i].curso);
    fflush(stdin);
}
  for(int i=0;i<5;i++){

    printf("---------ALUNo %d------------\n",i+1);
    printf("Nome: %s\nMatricula: %d\nCurso: %s\n", aluNos[i].Nome,aluNos[i].localizadorero_matricula,aluNos[i].curso);
}
    return 0;
}