#include <stdio.h>

int main(){
    float preco,pago,troco;

    printf("insira o valor do produto: ");
    scanf("%f",&preco);
    printf("insira o valor pago pelo cliente: ");
    scanf("%f",&pago);
    troco = pago-preco;
    printf("devolta %.2f reais de troco para o cliente",troco);
    return 0;
}