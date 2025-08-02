#include <Arduino.h>

// put function declarations here:
const int buttonPinRight = 2;
const int buttonPinLeft = 13;

const int leftRedLed = 12;
const int leftYellowLed = 11;
const int leftGreenLed = 10;

const int rightGreenLed = 3;
const int rightYellowLed = 4;
const int rightRedLed = 5;

const int buzzer = 7;

void setup()
{
  // Buttons as input (use INPUT_PULLUP if wired to ground)
  pinMode(buttonPinRight, INPUT);
  pinMode(buttonPinLeft, INPUT);

  // Left side LEDs as output
  pinMode(leftRedLed, OUTPUT);
  pinMode(leftYellowLed, OUTPUT);
  pinMode(leftGreenLed, OUTPUT);

  // Right side LEDs as output
  pinMode(rightGreenLed, OUTPUT);
  pinMode(rightYellowLed, OUTPUT);
  pinMode(rightRedLed, OUTPUT);

  // Buzzer as output
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  digitalWrite(leftRedLed, HIGH);
  digitalWrite(leftYellowLed, HIGH);
  digitalWrite(leftGreenLed, HIGH);

  digitalWrite(rightGreenLed, HIGH);
  digitalWrite(rightYellowLed, HIGH);
  digitalWrite(rightRedLed, HIGH);
}

// put function definitions here: