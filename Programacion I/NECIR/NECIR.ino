#include <NECIRrcv.h>
#include <Arduino.h>
int pin=2;
int led=3;
int flag=0;
NECIRrcv IR(pin);
unsigned long valor;
void setup() {
  // put your setup code here, to run once:
  IR.begin();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
    while(IR.available())
    {
      valor=IR.read();
        switch(valor)
        {
          case 3810328320:
            Serial.println("OK");
            digitalWrite(led,HIGH);
            delay(50);
            digitalWrite(led,LOW);
            break;
          default:
            break;
        }
       
     }
 }
