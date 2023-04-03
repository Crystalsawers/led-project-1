#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

<<<<<<< HEAD
int displaySeconds = 1;  // each number to display in 1 second
int displayTime = (displayTimeSecs * 5000);
int countdownStart = 40;  // start off with 40 seconds
int countdownEnd = 0;     // ends at 0;
=======
int startTimer = 10;
int secDelay = 1000;
//int endTimer = 0;
>>>>>>> 39a66b3d17ca567dd49fab68ccc769eba2e51214

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
<<<<<<< HEAD
  // have different numbers counting down in a loop
  // display.setNumber(0, 4);
  // display.refreshDisplay();
=======
  remote();
  playATune();
}

/* Function where the 1 minute timer in 7 segment display counts down */
void countdown() {

  // have different numbers counting down in a loop from 1 minute

  static unsigned long timer = millis();
  int deciSeconds = 0;

  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++;  // 100 milliSeconds is equal to 1 deciSecond

    if (deciSeconds == 10000) {  // Reset to 0 after counting for 1000 seconds.
      deciSeconds = 0;
    }
    display.setNumber(deciSeconds, 4);
  }

  display.refreshDisplay();  // Must run repeatedly
}



/* Function to use IR remote sensor*/
void remote() {
}

/* Function where the buzzer plays after the countdown timer is finished */
void playATune() {
>>>>>>> 39a66b3d17ca567dd49fab68ccc769eba2e51214
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