#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

void setup() {
  // put your setup code here, to run once:
  byte numDigits = 4;
  byte digitPins[] = { 6, 8, 9, 12 };
  byte segmentPins[] = { 1, 2, 3, 4, 5, 7, 10, 11 };
  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  display.setBrightness(100);
  // Reference: https://electronics-project-hub.com/interfacing-7-segment-display-with-arduino/ 
}

void loop() {
  // put your main code here, to run repeatedly:
}
