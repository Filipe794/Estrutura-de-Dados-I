#include <stdio.h>

typedef struct {
    int hora,minutos,segundos;
}horario;
typedef struct {
    int dia,mes,aNo;
}data;

typedef struct {
    data data;
    horario horario;
    char descricao[100];
}compromisso;

int main(){
    
    return 0;
}