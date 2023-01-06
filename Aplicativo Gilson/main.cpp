#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <math.h>
#include "funcoes app.h"

int main(){
    int s=-1;
    celula *cabeca;
    while(s!=0){
        imprimir_menu();
        scanf("%d",&s);
        switch(s){
            case 1:
            inserir_inicio(&cabeca);
            break;

            case 2:
            sorteio(cabeca);
            break;
            



        }

    }
    return 0;
}