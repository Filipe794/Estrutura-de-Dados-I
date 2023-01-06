#include <stdio.h>

typedef struct{
    int matricula;
    char Nome[30];
    int codigo_disciplina;
    float Nota_1;
    float Nota_2;
}aluNo;

float media_final();

int main(){

    aluNo turma[10];





    return 0;
}

float media_final(float n1, float n2){
    return (n1+(n2*2))/2;
}