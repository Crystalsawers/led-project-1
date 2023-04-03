#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

int displaySeconds = 1;  // each number to display in 1 second
int displayTime = (displayTimeSecs * 5000);
int countdownStart = 40;  // start off with 40 seconds
int countdownEnd = 0;     // ends at 0;

void setup() {
  // Setting up the 4-digit, 7-segment display
  byte numDigits = 4;
  byte digitPins[] = { 12, 9, 8, 6 };
  byte segmentPins[] = { 11, 7, 4, 2, 1, 10, 5, 3 };  // based on the segment pins from CC56-12SURKWA datasheet, A, B, C, D, E, F, G, DP
  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  display.setBrightness(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  countdown();
  // have different numbers counting down in a loop
  // display.setNumber(0, 4);
  // display.refreshDisplay();
}

void countdown() {
  if (countdownStart >= countdownEnd) {
    for (int i = 0; i <= displayTime; i++) {
      display.setNumber(countdownStart, 0);
      display.refreshDisplay();
    }
    countdownStart--;  // decrement on countdown number
  }
}

void remotecontrols(){

  // function for the IR remote sensor

  
}

// reference: https://www.youtube.com/watch?v=b7yCvvrDPSw