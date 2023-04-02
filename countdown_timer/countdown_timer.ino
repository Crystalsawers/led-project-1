#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

void setup() {
  // Setting up the 4-digit, 7-segment display
  byte numDigits = 4;
  byte digitPins[] = { 12, 9, 8, 6 };
  byte segmentPins[] = { 11, 7, 4, 2, 1, 10, 5, 3 }; // based on the segment pins from CC56-12SURKWA datasheet, A, B, C, D, E, F, G, DP
  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  display.setBrightness(100);

  // Serial.begin(9600);

  // pinMode(3, OUTPUT);
  // pinMode(9, OUTPUT);
  // pinMode(12, OUTPUT);

  // pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

// have different numbers counting down in a loop from 1 minute
  display.setNumber(0, 4);
  display.refreshDisplay();
}
