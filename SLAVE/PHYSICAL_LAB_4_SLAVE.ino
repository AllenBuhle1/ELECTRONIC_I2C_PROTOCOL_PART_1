// C++ code
//SLAVE (SENDER) ARDUINO CODE
#include <Wire.h>

int SLAVE_ADDRESS = 10;
int SLAVE_BTN_PIN = 4;
void setup()
{
  Serial.begin(9600);
  //Setting push button pin mode
  pinMode(SLAVE_BTN_PIN,INPUT);
  
  //Setting slave address
  Wire.begin(SLAVE_ADDRESS);
  
  //Handling master request events
  Wire.onRequest(handleRequestEvent);
}

void loop(){
  Serial.println(digitalRead(SLAVE_BTN_PIN));
 }

void handleRequestEvent(){
  //Sending slave button status to master
  
  Wire.write(digitalRead(SLAVE_BTN_PIN));
}