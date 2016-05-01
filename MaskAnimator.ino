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
  Serial.println("Singlestrip DEBUG mode - not for mask. See config.h");
  #else
  Serial.println("Normal mode - for mask");
  #endif
  
  stripLeft.begin();
  stripMiddle.begin();
  stripRight.begin();
  show();
}

void loop() {

fear();
surprise();
happiness();
sad();
anger();
shy();
disgust();

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

void surprise()
{
// five vertical lines
// line1: 3, 7
// line2: 1,2,5,8
// line3: 9-14
// line4: 15,16,19,22
// line5: 17,21

  //set the five colors for the five vertical lines
  uint32_t color1 = color(0,0,255);
  uint32_t color2 = color(0,255,255);
  uint32_t color3 = color(255,255,0);
  uint32_t color4 = color(255,0,255);
  uint32_t color5 = color(0,0,255);

  int colors[] = {color1, color2, color3, color4, color5};

  int idx0 = 0;
  int idx1 = 1;
  int idx2 = 2;
  int idx3 = 3;
  int idx4 = 4;

  //initial delay: 1 second. 
  int speeddelay = 1000;

  //clear als strips
  stripLeft.clear();
  stripMiddle.clear();
  stripRight.clear();

  //the animation is made out of 250 frames
  for(int i=0; i<250; i++)
  {
    setPixelColor(3, colors[idx0]); 
    setPixelColor(7, colors[idx0]);
    setPixelColor(1, colors[idx1]); 
    setPixelColor(2, colors[idx1]);
    setPixelColor(5, colors[idx1]); 
    setPixelColor(8, colors[idx1]);
    setPixelColor(9, colors[idx2]); 
    setPixelColor(10, colors[idx2]);
    setPixelColor(11, colors[idx2]); 
    setPixelColor(12, colors[idx2]);
    setPixelColor(13, colors[idx2]);
    setPixelColor(14, colors[idx2]);
    setPixelColor(15, colors[idx3]); 
    setPixelColor(16, colors[idx3]);
    setPixelColor(19, colors[idx3]); 
    setPixelColor(22, colors[idx3]);
    setPixelColor(17, colors[idx4]); 
    setPixelColor(21, colors[idx4]);
    
    idx0++;
    idx1++;
    idx2++;
    idx3++;
    idx4++;
    idx0 = idx0 % 5;
    idx1 = idx1 % 5;
    idx2 = idx2 % 5;
    idx3 = idx3 % 5;
    idx4 = idx4 % 5;

    show();
    delay(speeddelay);
    speeddelay -= 4;
  }
  
}

void happiness()
{
  for (int i = 0; i<9;i++){
    showFrame(FRAME_HAPPY1);
    delay(300);
    showFrame(FRAME_HAPPY2);
    delay(300);
    showFrame(FRAME_HAPPY3);
    delay(300);
    showFrame(FRAME_HAPPY4);
    delay(300);
    showFrame(FRAME_HAPPY5);
    delay(300);
  }

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

void anger()
{
 //original idea: flames 
  for (int i= 0;i<15;i++){
    showFrame(FRAME_ANGER);
    delay(100);
    showFrame(FRAME_ANGER0);
    delay(100);
    showFrame(FRAME_ANGER1);
    delay(100);
    showFrame(FRAME_ANGER2);
    delay(100);
    showFrame(FRAME_ANGER3);
    delay(100);
    showFrame(FRAME_ANGER4);
    delay(100);
  }
}

void shy()
{
  //a red diagonal line per side
  //5,6,7  and 19,20,21
  for(int i=0;i<255;i++)
  {
     setPixelColor(5, i,0,0);
     setPixelColor(6, i,0,0);
     setPixelColor(7, i,0,0);
     setPixelColor(19, i,0,0);
     setPixelColor(20, i,0,0);
     setPixelColor(21, i,0,0);
     delay(5);
     
     show();
     
  }
  delay(227300);
}

void disgust()
{
    showFrame(FRAME_DISGUST0);
    delay(24000);
}

uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}


void setPixelColor(int index, int r, int g, int b)
{
  index = index -1;

  #ifdef DEBUG_SINGLESTRIP
  stripRight.setPixelColor(index,r,g,b  );
  #else
  
  if(index >14)
  {
    stripRight.setPixelColor(index-14,r,g,b  );  
  }
  else if(index >8)
  {
    stripMiddle.setPixelColor(index-8, r,g,b );  
  }
  else
  {
    stripLeft.setPixelColor(index, r,g,b);
  }
  #endif  
}

void setPixelColor(int index, uint32_t rgb)
{
  index = index -1;
  #ifdef DEBUG_SINGLESTRIP
  stripRight.setPixelColor(index,rgb );
  #else
  
  if(index >14)
  {
    stripRight.setPixelColor(index-14,rgb  );  
  }
  else if(index >8)
  {
    stripMiddle.setPixelColor(index-8, rgb );  
  }
  else
  {
    stripLeft.setPixelColor(index, rgb);
  }
  #endif
  
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
  show();
}

void show()
{
    stripLeft.show();
    stripMiddle.show();
    stripRight.show();

}

