#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char Nome[30];
    float Nota_1;
    float Nota_2;
    float Nota_3;
}estudante;

typedef struct{
    float media_Notas;
    char Nome[30];
}media_aluNo;

int main(){
    estudante aluNo[5];
    media_aluNo media[5];

    for(int i=0; i<2;i++){

    printf("insira a matricula do aluNo %d: ",i+1);
    scanf("%d", &aluNo[i].matricula);
    
    printf("insira o Nome do aluNo %d: ",i+1);
    scanf("%s", aluNo[i].Nome);
    fflush(stdin);

    printf("insira a Nota 1 do aluNo %d: ",i+1);
    scanf("%f", &aluNo[i].Nota_1);

    printf("insira a Nota 2 do aluNo %d: ",i+1);
    scanf("%f", &aluNo[i].Nota_2);

    printf("insira a Nota 3 do aluNo %d: ",i+1);
    scanf("%f", &aluNo[i].Nota_3);
    }

    // maior Nota da primeira prova
    int maior=0, aluNo_maior_Nota;
        for(int i=0; i<2;i++){
            if(aluNo[i].Nota_1>maior) {
                maior=aluNo[i].Nota_1;
                aluNo_maior_Nota=i;
        }
        }
        printf("o aluNo com a maior Nota na primeira prova é %s, a Nota dele é %d\n",aluNo[aluNo_maior_Nota].Nome,maior);

    // maior e meNor media geral 
    for(int i=0;i<2;i++){
        media[i].media_Notas=(aluNo[i].Nota_1+aluNo[i].Nota_2+aluNo[i].Nota_3)/3;
        strcpy(media[i].Nome,aluNo[i].Nome);
        }
    float maior_media=0.0;
    float meNor_media=media[0].media_Notas;
    int posicao_maior_Nota=0;
    int posicao_meNor_Nota=0;
    for(int i=0;i<2;i++){
        if(media[i].media_Notas>maior_media){
            maior_media=media[i].media_Notas;
            posicao_maior_Nota=i;
        }
        if(media[i].media_Notas<meNor_media){
            meNor_media=media[i].media_Notas;
            posicao_meNor_Nota=i;
        }
        }
    printf("o aluNo com a maior media é %s\n",media[posicao_maior_Nota].Nome);
    printf("o aluNo com a meNor media é %s\n",media[posicao_meNor_Nota].Nome);
  return 0;
}