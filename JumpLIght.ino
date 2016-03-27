
/* 
 * Example of using the ChainableRGB library for controlling a Grove RGB.
 * This code puts a red dot (led) moving along a strip of blue dots.
 */

#include "ChainableLED.h"
#include "math.h"

#define NUM_LEDS  5

ChainableLED leds(7, 8, NUM_LEDS);

#define SENSOR_PORT_1 1
#define SENSOR_PORT_2 2
#define TILT_PORT 0
#define JUMP_LIGHT_VALUE 50
#define JUMP_TILT_VALUE 1000

void setup()
{
  Serial.begin(9600);
}

void loop()
{  
  if( isJump() ){
   // Serial.println(" jump! ");
    for(byte i=0; i<NUM_LEDS; i++){
       leds.setColorRGB(i, 255, 255, 255);  
    }
  }else{
  //  Serial.println(" walk ");
    for(byte i=0; i<NUM_LEDS; i++){
      leds.setColorRGB(i, 0, 0, 0); 
    }
  }
 
}


int oldTiltValue = 0;
boolean isJump(){
  int newTiltValue = analogRead(TILT_PORT);
  int diffTiltValue = abs(newTiltValue - oldTiltValue);
  int sensorValue1 = analogRead(SENSOR_PORT_1);
  int sensorValue2 = analogRead(SENSOR_PORT_2);
  oldTiltValue = newTiltValue;
  Serial.println(diffTiltValue);
  return sensorValue1 > JUMP_LIGHT_VALUE 
    && sensorValue2 > JUMP_LIGHT_VALUE
    && diffTiltValue > JUMP_TILT_VALUE;  
}





