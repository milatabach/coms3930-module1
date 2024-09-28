/*
 * Project Name: Fall...ing Love
 * Description: This program draws a little love story between two characters. 
 * When the chracters lock eyes, random hearts generate in the background. 
 * Author: Mila Lin Tabach
 * UNI: ml4851
 * Date: 9/28/2024
 * Hardware: LillyTT GO esp32
 */

#include <TFT_eSPI.h>
#include <SPI.h>
#include <stdlib.h>   

TFT_eSPI tft = TFT_eSPI();


void setup() {
    tft.init();
    tft.setRotation(1);   //  landscape  
    randomSeed(analogRead(0));  // seed to random number
    tft.fillScreen(0x5043);  // background color - maroon
  }

void loop() {
    title();
    fallingInLove();
}


/*
 * Function: title()
 * -------------------
 * Draws the title and erases it
 * 
 * Parameters:
 * Returns:
 * - void
 */
void title(){
  tft.setTextWrap(true);
  tft.setTextSize(2);
  tft.setCursor(10, 10); // 10 of the origin
  tft.setTextColor(TFT_WHITE);
  tft.setTextFont(1);
  tft.println("A quick love story"); 
  delay(1300);
  tft.fillRect(5, 5, tft.width(), 30, 0x5043); // erases title
}


/*
 * Function: drawRandomHearts()
 * -------------------
 * Draws hearts with random colors in random positions. 
 * 
 * Parameters:
 * Returns:
 * - void
 */
void drawRandomHearts() {
    int numHearts = 20; // Number of hearts drawn
    uint16_t colors[] = {0xb886, 0x9865, 0xe0a8, 0xb886, 0xf6da, 0x70c4};

    for (int i = 0; i < numHearts; ++i) {  
        int randomX = rand() % (tft.width());
        int randomY = rand() % (tft.height()/2); // The hearts should only appear in the top half to not overlap with the characters
          int randomColorIndex = rand() % (sizeof(colors) / sizeof(colors[0]));

        drawHeart(randomX, randomY, colors[randomColorIndex]);
        delay(500);
    }
}

/*
 * Function: drawHeart()
 * -------------------
 * Draws the title and erases it
 * 
 * Parameters:
 * x: x coordinate of the heart
 * y: y coordinate of the heart
 * color: color of the heart
 * Returns:
 * - void
 */
void drawHeart(int x, int y, uint16_t color) {
  tft.fillCircle(x, y, 4, color);        
  tft.fillCircle(x + 8, y, 4, color);    
  tft.fillTriangle(x - 4, y, x + 12, y, x + 4, y + 10, color);  
}


/*
 * Function: person1Foward()
 * -------------------
 * Draws person 1 looking foward
 * 
 * Parameters:
 * Returns:
 * - void
 */
void person1Foward() { 
  // person 1 is on the right
  tft.fillCircle(170, 110, 20, TFT_WHITE);

  // eye
  tft.fillCircle(160, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(160, 108, 5, TFT_WHITE);
  tft.fillCircle(160, 108, 2, TFT_BLACK);  
  
  // eye
  tft.fillCircle(180, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(180, 108, 5, TFT_WHITE);
  tft.fillCircle(180, 108, 2, TFT_BLACK);  
}

/*
 * Function: person1Middle()
 * -------------------
 * Draws person 1 looking at person 2
 * 
 * Parameters:
 * Returns:
 * - void
 */
void person1Middle() {
  // person 1 is on the left
 tft.fillCircle(170, 110, 20, TFT_WHITE);

  // eye
  tft.fillCircle(160, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(160, 108, 5, TFT_WHITE);
  tft.fillCircle(156, 108, 2, TFT_BLACK);  
  
  // eye
  tft.fillCircle(180, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(180, 108, 5, TFT_WHITE);
  tft.fillCircle(176, 108, 2, TFT_BLACK);  
}


/*
 * Function: person1Outside()
 * -------------------
 * Draws person 1 looking at the opposite direction of person 2
 * 
 * Parameters:
 * Returns:
 * - void
 */
void person1Outside() {
  // person 1 is on the left
 tft.fillCircle(170, 110, 20, TFT_WHITE);

  // eye
  tft.fillCircle(160, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(160, 108, 5, TFT_WHITE);
  tft.fillCircle(164, 108, 2, TFT_BLACK);  
  
  // eye
  tft.fillCircle(180, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(180, 108, 5, TFT_WHITE);
  tft.fillCircle(184, 108, 2, TFT_BLACK);  
}


/*
 * Function: person2Foward()
 * -------------------
 * Draws person 2 foward
 * 
 * Parameters:
 * Returns:
 * - void
 */
void person2Foward() {
  // person 2 is on the right
  tft.fillCircle(80, 110, 20, TFT_WHITE);

  // left eye
  tft.fillCircle(90, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(90, 108, 5, TFT_WHITE);
  tft.fillCircle(90, 108, 2, TFT_BLACK);  
  
  // right eye
  tft.fillCircle(70, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(70, 108, 5, TFT_WHITE);
  tft.fillCircle(70, 108, 2, TFT_BLACK);  
}

/*
 * Function: person2Middle()
 * -------------------
 * Draws person 2 looking at person 1
 * 
 * Parameters:
 * Returns:
 * - void
 */
void person2Middle() {
  // person 2 is on the right
  tft.fillCircle(80, 110, 20, TFT_WHITE);

  // eye
  tft.fillCircle(90, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(90, 108, 5, TFT_WHITE);
  tft.fillCircle(94, 108, 2, TFT_BLACK);  
  
  // eye
  tft.fillCircle(70, 108, 6.5, TFT_BLACK);  
  tft.fillCircle(70, 108, 5, TFT_WHITE);
  tft.fillCircle(74, 108, 2, TFT_BLACK);  
}

/*
 * Function: makeThemFlush()
 * -------------------
 * Draws little pink circles on their cheeks as well as smiles
 * 
 * Parameters:
 * Returns:
 * - void
 */
void makeThemFlush(){
  tft.fillCircle(92, 118, 3, 0xfddc);
  tft.fillCircle(68, 118, 3, 0xfddc);
  drawSubtleSmile(80, 122, 8, 2, TFT_BLACK);
  
  tft.fillCircle(180, 118, 3, 0xfddc);
  tft.fillCircle(158, 118, 3, 0xfddc);
  drawSubtleSmile(170, 122, 8, 2, TFT_BLACK);

}

/*
 * Function: drawSubtleSmile()
 * -------------------
 * Draws u shape on their faces
 * 
 * Parameters:
 * Returns:
 * - void
 */
void drawSubtleSmile(int x, int y, int width, int height, uint16_t color) {
  tft.drawLine(x - width/2, y, x - width/4, y + height, color);
  tft.drawLine(x - width/4, y + height, x, y + height + 1, color);
  tft.drawLine(x, y + height + 1, x + width/4, y + height, color);
  tft.drawLine(x + width/4, y + height, x + width/2, y, color);
}

/*
 * Function: drawSubtleSmile()
 * -------------------
 * Call the functions to make them look at each other, flush and smile. 
 * 
 * Parameters:
 * Returns:
 * - void
 */
void lookingAtEachOther() {         
  person1Middle();  
  person2Middle();  
  delay(200);
  makeThemFlush();
}


/*
 * Function: fallingInLove()
 * -------------------
 * Call other functions telling the story
 * 
 * Parameters:
 * Returns:
 * - void
 */
void fallingInLove(){
  // this is just a little story
  person1Foward();  
  person2Foward();
  delay(1000);
  person2Middle();
  delay(500);
  person1Middle();
  delay(2000);
  person1Outside();
  delay(2500);
  person2Foward();
  person1Middle();
  delay(800);
  person1Foward();
  delay(900);
  person2Middle();
  person1Outside();
  delay(700);
  person1Foward();  
  person2Foward();
  delay(2000);
  lookingAtEachOther();
  drawHeart(125, 80, 0xf800);
  delay(300);
  drawRandomHearts();
  delay(700);
  tft.fillScreen(0x5043);
}

