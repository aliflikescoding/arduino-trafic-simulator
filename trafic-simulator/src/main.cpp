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

// function declarations
void PhaseOne();
void yellowBlink(int position, int seconds);
void PhaseTwo();
void PhaseThree();
void PhaseFour();
void PhaseFive();
void PhaseSix();
void PhaseSeven();

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
  // left green on, right red on, others off
  PhaseOne();
  // delay 5 secs, right red on, others off
  delay(5000);
  PhaseTwo();
  // no delay, left side yellow blink
  yellowBlink(0, 2000);
  // no delay, all off
  PhaseThree();
  // no delay, left red on, others off
  PhaseFour();
  // no delay, right side yellow blink
  yellowBlink(1, 2000);
  // no delay, left red on, right green on, others off
  PhaseFive();
  // delay 5 secs, left red on, others off
  delay(5000);
  PhaseSix();
  // no delay, left side blink
  yellowBlink(0, 1500);
  // no delay, right side yellow blink
  yellowBlink(1, 2000);
  PhaseSeven();
  /* loop back to phase one */
}

void yellowBlink(int position, int seconds)
{
  if (position == 0)
  {
    digitalWrite(leftYellowLed, HIGH);
    delay(seconds);
    digitalWrite(leftYellowLed, LOW);
  }
  else if (position == 1)
  {
    digitalWrite(rightYellowLed, HIGH);
    delay(seconds);
    digitalWrite(rightYellowLed, LOW);
  }
}

void PhaseOne()
{
  // Left side: green on, others off
  digitalWrite(leftGreenLed, HIGH);
  digitalWrite(leftYellowLed, LOW);
  digitalWrite(leftRedLed, LOW);

  // Right side: red on, others off
  digitalWrite(rightRedLed, HIGH);
  digitalWrite(rightYellowLed, LOW);
  digitalWrite(rightGreenLed, LOW);
}

void PhaseTwo()
{
  digitalWrite(leftGreenLed, LOW);
}

void PhaseThree()
{
  digitalWrite(rightRedLed, LOW);
}

void PhaseFour()
{
  digitalWrite(leftRedLed, HIGH);
}

void PhaseFive()
{
  digitalWrite(rightGreenLed, HIGH);
}

void PhaseSix()
{
  digitalWrite(rightGreenLed, LOW);
  digitalWrite(leftRedLed, LOW);
}

void PhaseSeven() {
  digitalWrite(rightRedLed, HIGH);
}