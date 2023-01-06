#include <stdio.h>
int soma(int *p, int *q){
    *p = *p*2;
    *q= *q*2;
    return *p + *q;
    }
int main(){
    int A,B,*pointer_A=&A,*pointer_B=&B;
    printf("Insira o valor de A:\n");
    scanf("%d",&A);
    printf("Insira o valor de B:\n");
    scanf("%d",&B);
    printf("%d\n",soma(pointer_A,pointer_B));
    printf("A = %d\n",A);
    printf("B = %d\n",B);
    return 0;
}