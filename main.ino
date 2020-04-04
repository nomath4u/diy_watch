/*****
 Beginning of watch with things I have laying around
 ****/

#include <Arduino.h>

void setup(){
  Scheduler.startLoop(blink);
}


void loop(){
    //Do nothing since we are scheduling
}

void blink(){
    digitalToggle(LED_RED);
    delay(500);
}

