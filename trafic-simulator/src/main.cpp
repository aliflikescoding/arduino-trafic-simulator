#include <Arduino.h>

// variable declarations

const int buttonPinRight = 2;

const int leftRedLed = 12;
const int leftYellowLed = 11;
const int leftGreenLed = 10;

const int rightGreenLed = 3;
const int rightYellowLed = 4;
const int rightRedLed = 5;

const int buzzer = 7;

// put function declarations here:
void startTrafficPhases();

void setup()
{
  // Buttons as input (use INPUT_PULLUP if wired to ground)
  pinMode(buttonPinRight, INPUT);
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
  startTrafficPhases();
}

// put function definitions here:
void startTrafficPhases() {
  digitalWrite(leftGreenLed, HIGH);
  digitalWrite(leftYellowLed, LOW);
  digitalWrite(leftRedLed, LOW);

  digitalWrite(rightRedLed, HIGH);
  digitalWrite(rightYellowLed, LOW);
  digitalWrite(rightGreenLed, LOW);
  delay(5000);

  digitalWrite(leftGreenLed, LOW);
  digitalWrite(leftYellowLed, HIGH);
  digitalWrite(leftRedLed, LOW);
  delay(2000);
  digitalWrite(leftYellowLed, LOW);

  digitalWrite(leftRedLed, HIGH);
  digitalWrite(rightRedLed, LOW);
  digitalWrite(rightYellowLed, HIGH);
  delay(1500);
  digitalWrite(rightYellowLed, LOW);

  digitalWrite(rightGreenLed, HIGH);
  delay(5000);

  digitalWrite(rightGreenLed, LOW);
  digitalWrite(rightYellowLed, HIGH);
  digitalWrite(rightRedLed, LOW);
  delay(2000);
  digitalWrite(rightYellowLed, LOW);

  digitalWrite(leftRedLed, LOW);
  digitalWrite(rightRedLed, HIGH);
  digitalWrite(leftYellowLed, HIGH);
  delay(1500);
};
