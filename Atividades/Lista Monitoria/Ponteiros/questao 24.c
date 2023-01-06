#include <stdio.h>
#include <stdlib.h>

void max_min(int* V,int* min,int* max,int n){
    for(int i =0;i<n;i++){
        printf("Insira o valor %d: ",i+1);
        scanf("%d",&V[i]);
        if(i==0){
            *min=V[i];
            *max=V[i];
        }
         if(V[i]>*max){
            *max=V[i];
        }else if(V[i]<*min){
            *min=V[i];
        }
    }
}
int main(){
    int min,max;
    int *V,n;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d",&n);
    V=malloc(sizeof(int)*n);
    max_min(V,&min,&max,n);
    printf("min: %d\nmax: %d",min,max);
    free(V);
    return 0;
}