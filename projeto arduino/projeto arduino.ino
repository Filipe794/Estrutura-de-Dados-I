// Programa : Sensor de detecção de osbtaculos para ciclistas com HC-SR04  
// Autor : Equipe IFMA CC 09
#include <Ultrasonic.h>   //Carrega a biblioteca Ultrasonic  
#include <NewTone.h>    //Carrega a biblioteca Newtone  
//Dados do buzzer  
#define tempo 500   
int frequencia = 2000;
int PiNofalante = 2;
int atraso = 1000;
//Define o piNo do ArduiNo a ser utilizado com o piNo Trigger do sensor  
#define PINo_TRIGGER 13   
//Define o piNo do ArduiNo a ser utilizado com o piNo Echo do sensor  
#define PINo_ECHO   10 
//Inicializa o sensor ultrasonico  
Ultrasonic ultrasonic(PINo_TRIGGER, PINo_ECHO);   
void setup(){  
  pinMode(PiNofalante,OUTPUT); //PiNo do buzzer   
  Serial.begin(9600); //Inicializa a serial  
}  
void loop(){  
  float cmMsec, inMsec;  
    
  //Le os dados do sensor, com o tempo de retorNo do sinal  
  long microsec = ultrasonic.timing();   
   
  //Calcula a distancia em centimetros  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Ajusta o atraso de acordo com a distancia  
  if (cmMsec < 2000)  
  {  
    atraso = 500; 
  }
  
  //Emite o bip  
  NewTone(PiNofalante, frequencia, tempo);   
   
  delay(atraso);  
}