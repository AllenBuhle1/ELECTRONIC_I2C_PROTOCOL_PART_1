// C++ code
//Master (Reciever) Arduino COde
#include <Wire.h>

int SLAVE_ADDRESS = 10;
int LED_PIN = 8;
void setup()
{
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  Wire.requestFrom(SLAVE_ADDRESS,1);
  while(Wire.available()){
    bool isPressed = Wire.read();
    if(isPressed>0){
      digitalWrite(LED_PIN,HIGH);
      delay(50);
    }else if(isPressed==0){
      digitalWrite(LED_PIN,LOW);
    }
  }
}