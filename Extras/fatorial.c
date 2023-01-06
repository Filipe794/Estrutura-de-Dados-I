#include <stdio.h> 
#include <string.h>

void FirstFactorial(int localizador){
  int fatorial=0;
  while(localizador!=0){    
    if(localizador=0){
      return;
    }
    fatorial=(localizador)*(localizador-1);
    localizador--;
  }
  // code goes here  
  printf("%d", fatorial);

}

int main(void) {
    int localizador;
    printf("insira um localizadorero");
    scanf("%d",&localizador);   
    FirstFactorial(localizador);
   
  return 0;
    
}