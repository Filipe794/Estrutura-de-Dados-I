#include <stdio.h>
    void preencher(int n, int *p){
        for(int i=0;i<n;i++){
             printf("Digite o valor do %d elemento vetor\n", i);
        scanf("%d",&p[i]);
        }
    }
int main(){
    int n,*pointer;
    printf("quantos elementos deseja inserir No vetor?\n");
    scanf("%d",&n);
    pointer= malloc(n*sizeof(int));
    preencher(n,pointer);
    for(int i=0; i<n;i++){
        printf("valor da posicao %d: %d\n",i,pointer[i]);
    }
    free(pointer);
    return 0;
}
