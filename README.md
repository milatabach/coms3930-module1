# coms3930-module1
This page is dedicated to Module 1: Generative Art from COMS 3930: Creative Embbeded Systems

Project Title: Fall...ing in Lovw

Description: This project draws a little story of two people looking at each other. It is a generative art project. 

Components Needed: Lily TTGO esp32

Code Explanation: The code has several functions that each draw an element of the story. The fallingInLove() function brings those functions together to tell the story. 

### Function Descriptions

#### `setup()`
Initializes the TFT display, sets the rotation, seeds the random number generator, and fills the screen with a maroon background.

- **Parameters**: None
- **Returns**: void

---

#### `loop()`
Continuously executes the main functions of the program, including displaying the title and animating the love story.

- **Parameters**: None
- **Returns**: void

---

#### `title()`
Displays the title of the story on the screen and erases it after a brief delay.

- **Parameters**: None
- **Returns**: void

---

#### `drawRandomHearts()`
Generates and displays a specified number of hearts with random colors and positions in the top half of the screen.

- **Parameters**: None
- **Returns**: void

---

#### `drawHeart(int x, int y, uint16_t color)`
Draws a heart shape at the specified coordinates with the given color.

- **Parameters**:
  - `x`: x coordinate of the heart
  - `y`: y coordinate of the heart
  - `color`: color of the heart
- **Returns**: void

---

#### `person1Foward()`
Draws person 1 facing forward on the screen.

- **Parameters**: None
- **Returns**: void

---

#### `person1Middle()`
Draws person 1 looking at person 2, indicating a moment of connection.

- **Parameters**: None
- **Returns**: void

---

#### `person1Outside()`
Draws person 1 looking away from person 2, showing a moment of hesitation.

- **Parameters**: None
- **Returns**: void

---

#### `person2Foward()`
Draws person 2 facing forward on the screen.

- **Parameters**: None
- **Returns**: void

---

#### `person2Middle()`
Draws person 2 looking at person 1, indicating a moment of connection.

- **Parameters**: None
- **Returns**: void

---

#### `makeThemFlush()`
Adds pink circles on the characters' cheeks and draws subtle smiles to indicate affection.

- **Parameters**: None
- **Returns**: void

---

#### `drawSubtleSmile(int x, int y, int width, int height, uint16_t color)`
Draws a subtle smile in a "U" shape on the characters' faces at the specified coordinates.

- **Parameters**:
  - `x`: x coordinate of the smile
  - `y`: y coordinate of the smile
  - `width`: width of the smile
  - `height`: height of the smile
  - `color`: color of the smile
- **Returns**: void

---

#### `lookingAtEachOther()`
Animates person 1 and person 2 looking at each other, followed by them blushing and smiling.

- **Parameters**: None
- **Returns**: void

---

#### `fallingInLove()`
Sequentially calls functions to narrate the love story, showcasing interactions between the characters and drawing hearts in the background.

- **Parameters**: None
- **Returns**: void

