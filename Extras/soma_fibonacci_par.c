#include <stdio.h>

int main(void) {
  int soma,n1=0, n2=1,fib;
  while(fib<4000000){
    if(fib%2==0){
        soma=soma+fib;
    }
    fib=n1+n2;
    n1=n2;
    n2=fib;
  }
  printf("%d",soma);
return 0;
}