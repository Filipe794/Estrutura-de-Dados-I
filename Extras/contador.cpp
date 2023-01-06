#include <stdio.h> 
#include <windows.h>
#include <math.h>

int main(){
    for(float i=1;i>0;i++){
        printf("%.2f\n",pow(2.0,i));
        Sleep(500);
    }
    return 0;
}