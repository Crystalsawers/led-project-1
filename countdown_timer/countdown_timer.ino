#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

unsigned long timer = millis();
int seconds = 61; // this is including zero

void setup() {
  // Setting up the 4-digit, 7-segment display
  byte numDigits = 4;
  byte digitPins[] = { 12, 9, 8, 6 };
  byte segmentPins[] = { 11, 7, 4, 2, 1, 10, 5, 3 };  // based on the segment pins from CC56-12SURKWA datasheet, A, B, C, D, E, F, G, DP
  // got rid of segment pin 3 as it is a decimal only  due to running out of digital pins/outputs 
  bool resistorsOnSegments = false;
  bool updateWithDelaysIn = true;
  bool leadingZeros = true;
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected
  byte hardwareConfig = COMMON_CATHODE;


  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, disableDecPoint);
  // display.setBrightness(-200); - display brightness ranges in the negatives from -200 to 0
    display.setBrightness(70);
}

void loop() {
  // put your main code here, to run repeatedly:

  countdown();

  // remote();
  // playATune();
}

/* Function where the 1 minute timer in 7 segment display counts down */

void countdown() {


  // Wait for a short period of time before starting the countdown again

  if (millis() - timer >= 1000) {
    timer += 1000;
    seconds--;

    if (seconds < 0) {
      seconds = 0;
      // play song from buzzer here
      //
    }

    display.setNumber(seconds, 3);
  }

  display.refreshDisplay();
}

// /* Function to use IR remote sensor*/
// void remote() {
// }

// /* Function where the buzzer plays after the countdown timer is finished */
// void playATune() {
// }



// reference: https://www.youtube.com/watch?v=b7yCvvrDPSw