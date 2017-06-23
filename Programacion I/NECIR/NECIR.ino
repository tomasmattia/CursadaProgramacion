#include <NECIRrcv.h>
#include <Arduino.h>
int pin=2;
int led=3;
int flag=1;
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
      digitalWrite(led,HIGH);
        switch(valor)
        {
          case 3810328320:
            Serial.println("OK");
            break;
          case 3125149440:
            Serial.println("BOTON 1");
            break;
          case 3108437760:
            Serial.println("BOTON 2");
            break;
          case 3091726080:
            Serial.println("BOTON 3");
            break;
          case 3141861120:
            Serial.println("BOTON 4");
            break;
          case 3208707840:
            Serial.println("BOTON 5");
            break;
          case 3158572800:
            Serial.println("BOTON 6");
            break;
          case 4161273600:
            Serial.println("BOTON 7");
            break;
          case 3927310080:
            Serial.println("BOTON 8");
            break;
          case 4127850240:
            Serial.println("BOTON 9");
            break;
          case 3910598400:
            Serial.println("BOTON *");
            break;
          case 3860463360:
            Serial.println("BOTON 0");
            break;
          case 4061003520:
            Serial.println("BOTON #");
            break;
          case 3877175040:
            Serial.println("FLECHA UP");
            break;
          case 4144561920:
            Serial.println("FLECHA LEFT");
            break;
          case 2774204160:
            Serial.println("FLECHA RIGHT");
            break;
          case 2907897600:
            Serial.println("FLECHA DOWN");
            break; 
          default:
            Serial.println(valor);
            break;
        }
       delay(100);
       digitalWrite(led,LOW);
     }
 }
