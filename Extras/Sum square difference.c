#include <stdio.h>

int main(){
   int localizador=1;
    int soma_quadrado=0;
    int quadrado_da_soma=0;
//soma dos quadrados
    for(localizador=0;localizador<=100;localizador++){
        soma_quadrado=soma_quadrado+(localizador*localizador);
    }
//quadrado da soma
    for(localizador=0;localizador<=100;localizador++){
        quadrado_da_soma=quadrado_da_soma+localizador;
    }
    quadrado_da_soma=quadrado_da_soma*quadrado_da_soma;
    printf("%d",quadrado_da_soma-soma_quadrado);
    return 0;
}