/*
  Single heart drawing;
  single-heart.ino
  Draws a single heart
  
  Mila Lin Tabach - 9/24/2024
*/


#include <TFT_eSPI.h>  
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  

void setup() {
  tft.init();
  tft.setRotation(1); // 1 for landscape

  tft.fillScreen(0xd189); // backgrounf color

  drawHeart();
}

void loop() {
}

void drawHeart() {
  tft.fillCircle(51, 30, 10, 0x70c4);   // Left circle
  tft.fillCircle(69, 30, 10, 0x70c4);   // Right circle
  tft.fillTriangle(40, 30, 80, 30, 60, 57, 0x70c4);  // Bottom triangle
  
}
