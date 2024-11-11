#include <Adafruit_CircuitPlayground.h>
//Don't Wake the Baby
//By Joe Crighton
//Makes a noise if you shake the Arduino while left button is pressed, just so it isnt constantly beeping.
bool leftButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  leftButtonPressed = CircuitPlayground.leftButton();
  int x = CircuitPlayground.motionX(); //tracks movement on the x axis
  CircuitPlayground.clearPixels();
    if (leftButtonPressed && x > 3) { //if the button is held, any movement value greater than 3 will trigger the code
      CircuitPlayground.playTone(200, 200); //plays tone
      CircuitPlayground.setPixelColor(0,255,0,0); //Lights up left side pixels red
      CircuitPlayground.setPixelColor(1,255,0,0);
      CircuitPlayground.setPixelColor(2,255,0,0);
      CircuitPlayground.setPixelColor(3,255,0,0);
      CircuitPlayground.setPixelColor(4,255,0,0);
      Serial.print(1); //prints 1 for debugging
      Serial.println();
    } else {
      Serial.print(0); //prints 0 if fine
      Serial.println();
    }
  }

//check if leftbutton is being pressed AND check motion value on x axis, if its over 3, play a noise, if not, dont