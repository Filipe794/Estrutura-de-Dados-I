#include <stdio.h> 

int main(){
    int localizador=1;
    int soma=0;

    for(localizador=0;localizador<=1000;localizador++){
        if((localizador%3==0 || localizador%5==0)){
            soma=soma+localizador;
        }
    }
    printf("soma: %d",soma);
    return 0;
}