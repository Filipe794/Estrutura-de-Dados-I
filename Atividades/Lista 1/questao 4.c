#include <stdio.h>
int main(){
  int i=5;
  float f=3.5;
  char c='f';
  int *pointer_i=&i;
  float *pointer_f=&f;
  char *pointer_c=&c;
    
    printf("antes da mudanca:\ni vale %d \nf vale %.2f \nc vale %c\n", i,f,c);
    printf("insira o Novo valor da variavel inteira: ");
    scanf("%d", pointer_i);
    printf("insira o Novo valor da variavel float: ");
    scanf("%f", pointer_f);
    printf("insira o Novo valor da variavel char: ");
    scanf(" %c", pointer_c);
    printf("apos a mudanca:\ni vale %d \nf vale %.2f \nc vale %c\n", i,f,c);
    return 0;
}