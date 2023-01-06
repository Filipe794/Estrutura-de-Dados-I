#include <stdio.h>

int main(){
    int fatorial=1,valor;
    printf("insira um valor");
    scanf("%d",&valor);

    while(fatorial<=valor){
        if(fatorial==valor){
            printf("a raiz do fatorial de %d vale %d",valor,fatorial);
        }
        fatorial=(fatorial+1)*fatorial;
    }
    return 0;
}