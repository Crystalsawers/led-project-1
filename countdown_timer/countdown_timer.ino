#include <SevSeg.h>
#include <IRremote.hpp>

SevSeg display;

unsigned long timer = millis();
int seconds = 21;  // this is including zero

int soundPin = 3;


void setup() {
  // Setting up the 4-digit, 7-segment display
  byte numDigits = 4;
  byte digitPins[] = { 12, 9, 8, 6 };
  byte segmentPins[] = { 11, 7, 4, 2, 1, 10, 5 };  // based on the segment pins from CC56-12SURKWA datasheet, A, B, C, D, E, F, G, DP
  // got rid of segment pin 3 as it is a decimal only  due to running out of digital pins/outputs
  bool resistorsOnSegments = false;
  bool updateWithDelaysIn = true;
  bool leadingZeros = true;
  bool disableDecPoint = true;  // Use 'true' if your decimal point doesn't exist or isn't connected
  byte hardwareConfig = COMMON_CATHODE;

  display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, disableDecPoint);
  // display.setBrightness(-200); - display brightness ranges in the negatives from -200 to 0
  display.setBrightness(70);

  // buzzer
  pinMode(soundPin, OUTPUT);

  //LED
  pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //blink();
  countdown();

  // remote();
}

/* Function where the 1 minute timer in 7 segment display counts down */

void countdown() {


  // Wait for a short period of time before starting the countdown again

  if (millis() - timer >= 1000) {

    timer += 1000;
    seconds--;
    tone(soundPin, 247, 100);

    if (seconds < 0) {
      seconds = 0;
      digitalWrite(A0, HIGH);
      playATune();  // call the function to play a song
    }

    display.setNumber(seconds, 3);
  }

  display.refreshDisplay();
}

/* Function where the buzzer plays after the countdown timer is finished */
void playATune() {


// nokia 3310 ringtone 

  buzzerSounds('C', 1);
  buzzerSounds('E', 4);
  buzzerSounds('G', 2);

  buzzerSounds(' ', 2);

  buzzerSounds('C', 1);
  buzzerSounds('E', 4);
  buzzerSounds('G', 2);
}

// this function is for all the notes in a song
void buzzerSounds(char note, int beats) {

  int numNotes = 14;  // number of notes in our note and frequency array (there are 15 values, but arrays start at 0)

  //Note: these notes are C major (there are no sharps or flats)

  //this array is used to look up the notes
  char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' ' };
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = { 131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0 };

  int currentFrequency = 0;  //the frequency that we find when we look up a frequency in the arrays
  int beatLength = 150;      //the length of one beat (changing this will speed up or slow down the tempo of the song)

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 14
  {
    if (notes[i] == note)  // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];  // Yes! Set the current frequency to match that note
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(soundPin, currentFrequency, beats * beatLength);
  delay(beats * beatLength);  //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural
}

void remote() {

  // IR remote stuff
}

void blink() {

    digitalWrite(A0, HIGH);
    delay(100);
    digitalWrite(A0, LOW);
    delay(1000);
}
