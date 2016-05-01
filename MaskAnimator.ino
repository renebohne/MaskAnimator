/*
 * MaskAnimator
 * 
 * done: sad, fear, disgust
 * todo: happy, surprise, shy, anger
 */

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "animations.h"
 
Adafruit_NeoPixel stripLeft = Adafruit_NeoPixel(N_LEDS, PIN_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripMiddle = Adafruit_NeoPixel(N_LEDS, PIN_MIDDLE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripRight = Adafruit_NeoPixel(N_LEDS, PIN_RIGHT, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  #ifdef DEBUG_SINGLESTRIP
  Serial.println("Singlestrip DEBUG mode");
  #else
  Serial.println("Normal mode");
  #endif
  
  stripLeft.begin();
  stripLeft.show();
  stripMiddle.begin();
  stripMiddle.show();
  stripRight.begin();
  stripRight.show();
}

void loop() {
sad();
fear();
disgust();
}


void sad()
{
  for(int i=0; i<20; i++)
  {
    showFrame(FRAME_SAD0);
    delay(300);
    showFrame(FRAME_SAD1);
    delay(300);
    showFrame(FRAME_SAD2);
    delay(300);
    showFrame(FRAME_SAD3);
    delay(300);
  }
}

void fear()
{
    showFrame(FRAME_FEAR0);
    delay(1200);
    showFrame(FRAME_FEAR1);
    delay(1200);
    showFrame(FRAME_FEAR2);
    delay(1200);
    showFrame(FRAME_FEAR3);
    delay(20400);
}


void disgust()
{
    showFrame(FRAME_DISGUST0);
    delay(24000);
}

uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

void showFrame(const uint8_t frame[])
{

  #ifdef DEBUG_SINGLESTRIP
  for(int i=0; i<24;i++)
  {
    stripRight.setPixelColor(i, stripRight.Color(pgm_read_byte_near(frame+3*i),pgm_read_byte_near(frame+3*i+1),pgm_read_byte_near(frame+3*i+2)) );
  }
  #else
  
  for(int i= 0; i<8; i++)
  {
      stripLeft.setPixelColor(i, stripLeft.Color(pgm_read_byte_near(frame+3*i),pgm_read_byte_near(frame+3*i+1),pgm_read_byte_near(frame+3*i+2)) );
      stripMiddle.setPixelColor(i, stripMiddle.Color(pgm_read_byte_near(frame+24+3*i),pgm_read_byte_near(frame+24+3*i+1),pgm_read_byte_near(frame+24+3*i+2)) );
      stripRight.setPixelColor(i, stripRight.Color(pgm_read_byte_near(frame+48+3*i),pgm_read_byte_near(frame+48+3*i+1),pgm_read_byte_near(frame+48+3*i+2)) );
  }
  
  #endif

  stripLeft.show();
  stripMiddle.show();
  stripRight.show();
}

