# Embedded Systems ID620 2023

## Arduino LED Project 1: Countdown Timer

Project Timeframe: 15 March - 4 April 2023

## Main Components used:

- Arduino Uno board
- 4 character, 7 segment display LED
- Piezo Buzzer, to play a song and make a buzz for every second
- 2 LEDs (1 Yellow for during the timer, and 1 Blue for playing a song)
- Breadboard
- Jumper Wires
- Seven segment 4-digit Display, the model I used was a Common cathoode CC56-12SURKWA
- 220 ohm resistors

# Project Concept

A purposefully annoying countdown timer that sounds like a ticking time bomb that goes for 30 seconds, flashes within the last 10 seconds to make the user uncomfortable and alarmed, an then would play a song at the end of the timer. The "song" in question, or rather a ringtone is the classic Nokia 3310 ringtone.

My original plan for this project was to add a remote control sensor to add functionality of stopping, restarting, pausing, and playing the current time on the timer, but due to the short timeframe I coudn't implement this due to running out of pins to wire it up. I also thought about using LED strips to make some cool effect on how the timer would end with the song. The song I originally was going to use was "The Final Countdown", but then I thought of something much better and shorter.

## References

- https://projecthub.arduino.cc/tylerpeppy/86bb3eef-23ec-4873-ad3b-86c7c277142f
- https://www.youtube.com/watch?v=b7yCvvrDPSw
- https://makingarduino.com/arduino-30-days/7segment-display/
- Library I used for SevSeg display: https://github.com/DeanIsMe/SevSeg/blob/master/examples/SevSeg_Counter/SevSeg_Counter.ino
