#include <stdio.h>
#include <string.h>

typedef struct{
    char sexo[20],cor_olho[20],cor_cabelo[20];
    int idade;
}habitante;

void preencher(habitante *habitante){
    
    for(int i=0; i<50;i++){
        printf("insira o sexo da passagem %d: ",i+1);
        scanf("%s",habitante[i].sexo);
        printf("insira a cor do olho da passagem %d: ",i+1);
        scanf("%s",habitante[i].cor_olho);
        printf("insira a cor do cabelo da passagem %d: ",i+1);
        scanf("%s",habitante[i].cor_cabelo);
        printf("insira a idade da passagem %d: ",i+1);
        scanf("%d",&habitante[i].idade);
    }
}

int main(){
    habitante habitante[50];
    preencher(habitante);
    return 0;
}