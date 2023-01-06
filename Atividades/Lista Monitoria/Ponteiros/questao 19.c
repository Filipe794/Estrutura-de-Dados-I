#include <stdio.h>
#include <stdlib.h>

/*void array(int *vetor,int n){
    printf("Informe o tamanho do vetor");
    scanf("%d",&n); 
    vetor=malloc(sizeof(int)*n);
     printf("preencha o vetor");
    for(int i =0;i<n;i++){
        scanf("%d",&vetor[i]);
    }

}*/

void comparar(int *vetor,int n){
    int maior=0;
    int cont=0;
    for(int i=0;i<n;i++){
        //testar se a posição do vetor ja é igual
        if(vetor[i]==maior){
            cont++;
        } else if(vetor[i]>maior){
            maior=vetor[i];
            cont=1;
            }
        }
        
    printf("o maior é %d e ele aparece %d vezes ",maior,cont);
 }

int main (){


    /*array(vetor,&n);*/

    int *vetor,n;

    printf("Informe o tamanho do vetor");
    scanf("%d",&n); 

    vetor=malloc(sizeof(int)*n);

    printf("preencha o vetor");

    // tu tava fznd o for com i<=n, desse jeito ele preenchia o vetor 1 vez a mais doq o tamanho q o usuario inseria, pq a contagem começa do zero
    for(int i =0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    comparar(vetor,n);
    return 0;
}