#include <stdio.h>
float media();
int main(){
    int aluNos;
    float *Notas;
    printf("quantidade de aluNos na sala: ");
    scanf("%d",&aluNos);
    Notas=malloc(aluNos*sizeof(float));
    printf("a media da turma vale: %f",media(aluNos,Notas));
    free (Notas);
    return 0;
}
float media(int n, float *p){
    float soma=0;
        for(int i=0;i<n;i++){
             printf("Digite o valor do %d elemento vetor\n", i);
        scanf("%f",&p[i]);
        soma=soma+p[i];
        }
        return soma/n;
    }