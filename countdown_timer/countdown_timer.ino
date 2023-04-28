#include <SevSeg.h>
SevSeg display;

unsigned long timer = millis();
int seconds = 31;  // this is including zero

int soundPin = 3;

void setup() {
  /* Setting up the 4-digit, 7-segment display:
  
    digitPins array is ordered based on the CC56-12SURKWA datasheet:

    Digit 1: Pin 12,
    Digit 2: Pin 9,
    Digit 3: Pin 8,
    Digit 4: Pin 6

    Segment pins order

    A, B, C, D, E, F, G, DP
    11, 7, 4, 2, 1, 10, 5      
 
    Note: I got rid of segment pin 3 as it is a decimal only, due to running out of digital pins/outputs
        
    In my design I have put resistors on the digit pins in order to use less jumper wires on this display

 */

  byte numDigits = 4;
  byte digitPins[] = { 12, 9, 8, 6 }; 
  byte segmentPins[] = { 11, 7, 4, 2, 1, 10, 5 };  // based on the order of segment pins
  bool resistorsOnSegments = false;
  bool updateWithDelaysIn = true;
  bool leadingZeros = true;
  bool disableDecPoint = true;  // As I ommitted pin 3 the decimal point I set this to true
  byte hardwareConfig = COMMON_CATHODE;

  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, disableDecPoint);
  // display.setBrightness(-200); - display brightness ranges in the negatives from -200 to 0
  display.setBrightness(70);

  /* Buzzer */
  pinMode(soundPin, OUTPUT);

  /* LEDs */
  pinMode(A0, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // I used the countdown functionality into a seperate function here, because I didn't want to put everything in loop at once
  countdown();
}

/* Function where the 1 minute timer in 7 segment display counts down */

void countdown() {

  if (millis() - timer >= 1000) {

    digitalWrite(13, HIGH); // turn on Yellow LED to signal that the timer is in progress
    timer += 1000;
    seconds--;

    tone(soundPin, 247, 100);

    if (seconds < 10) {

      digitalWrite(13, HIGH);    
      digitalWrite(A0, HIGH); // turn on Blue LED to signal that time is nearly up
      delay(1000); // gives flashing effect on both clock and led
      digitalWrite(A0, LOW);

      
    }
    if (seconds <= 0) {
      seconds = 0;
      digitalWrite(13, LOW);
      digitalWrite(A0, HIGH);  // LED flashes when finished
      playATune();           // call the function to play a song
    }

    display.setNumber(seconds, 3);
  }

  display.refreshDisplay();
}

/* Function where the buzzer plays after the countdown timer is finished */
void playATune() {

  // Song played: nokia 3310 ringtone

  int numNotes = 13;

  int frequencies[] = { 1318, 1174, 739, 830, 1109, 988, 587, 659, 988, 880, 554, 659, 880 };

  int rhythm[] = { 2, 2, 4, 4, 2, 2, 4, 4, 2, 2, 4, 4, 8 };

  for (int i = 0; i < numNotes; i++) {
    tone(soundPin, frequencies[i], 150 * rhythm[i]);
    delay(60 * rhythm[i]);
  }
  noTone(soundPin);
  digitalWrite(A0, LOW);  
  delay(5000);
}