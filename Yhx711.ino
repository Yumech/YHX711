

// YHx711.DOUT - pin 6
// YHx711.SCK - pin 7

#include "Yhx711.h"

YHx711 adc (6, 7);
long tare1 = 0;
long tare2 = 0;
void setup(){
  Serial.begin(9600);
  delay(200);
  adc.setMode(3);
  delay(200);
  tare1 = adc.averageValue(80);
  adc.setMode(2);
  delay(200);
  tare2 = adc.averageValue(80); 
}


void loop()
{
  //delay(1000);
  adc.setMode(3);
  Serial.print("Channel A:");
   Serial.println((adc.averageValue(32)- tare1)/973.3);
  adc.setMode(2);
  Serial.print("Channel B:");
  Serial.println((adc.averageValue(32)- tare2)/973.3);

  
}
