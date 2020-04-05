/*****
 Beginning of watch with things I have laying around
 ****/

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

/********************
  Screen pins
********************/
//Using hardware SPI
#define TFT_CS 7
#define TFT_RST -1 // Tied directly to arduino RST
#define TFT_DC 15
#define LITE A0
/*******************
  End Screen pins
******************/

/******************
  Screen object
******************/
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(){

    setup_screen();
    Scheduler.startLoop(blink);
    Scheduler.startLoop(brightness);
}


void loop(){
    //Do nothing since we are scheduling
    testdrawtext("Hello world!", ST77XX_WHITE);
}

void blink(){
    digitalToggle(LED_RED);
    delay(500);
}

void setup_screen(){
    tft.initR(INITR_BLACKTAB);    
    tft.fillScreen(ST77XX_BLACK);

}

void brightness(){
    static uint8_t backlight = 255;
    analogWrite(LITE, backlight);
    backlight--;
}

void testdrawtext(char *text, uint16_t color){
    tft.setCursor(0,0);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
}
