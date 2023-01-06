#include <stdio.h>
int main(){

    int *vetor, tamanho;
    printf("tamanho vetor:\n");
    scanf("%d", &tamanho);
    vetor = malloc(tamanho * sizeof(int));
    
    for (int i = 0; i <tamanho; i++)
    {
        printf("insira um valor: ");
        scanf("%d", &vetor[i]);
    }

    printf("--------vetor antes do acrescimo-----------\n");
    for (int i = 0; i <tamanho; i++)
    {
        printf("%d  ", vetor[i]);
    }

    for (int i = 0; i <tamanho; i++)
    {
        vetor[i] = vetor[i]+1;
    }
    printf("\n------------vetor apos o acrescimo------------\n");
    for (int i = 0; i <tamanho; i++)
    {
        printf("%d  ", vetor[i]);
    }
    free(vetor);
    return 0;
}