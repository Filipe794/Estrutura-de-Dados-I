#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char rua[50];
    char bairro[30];
    int localizadorero_casa;
}endereco;
typedef struct{
    int idade;
    char Nome[30];
    endereco endereco_passagem;
}passagem;

int main(){
    passagem N;

    printf("Insira o Nome da passagem: ");
    scanf("%[^\n]s", N.Nome);

    fflush(stdin);

    printf("Insira a idade da passagem: ");
    scanf("%d", &N.idade);
  
    fflush(stdin);

    printf("Insira o Nome da rua: ");
    scanf(" %[^\n]s", N.endereco_passagem.rua);

    fflush(stdin);
    
    printf("Insira o bairro: ");
    scanf(" %[^\n]s", N.endereco_passagem.bairro);

    fflush(stdin);

    printf("Insira o localizadorero da casa: ");
    scanf("%d", &N.endereco_passagem.localizadorero_casa);
    return 0;
}