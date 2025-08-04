#include <Arduino.h>

// variable declarations

const int buttonPinRight = 2;
const int buttonPinLeft = 13;

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
  startTrafficPhases();
}

// put function definitions here:
void startTrafficPhases() {
  // Phase 1: Left Green, Right Red
  digitalWrite(leftGreenLed, HIGH); // left green on
  digitalWrite(leftYellowLed, LOW); // left yellow off
  digitalWrite(leftRedLed, LOW);    // left red off

  digitalWrite(rightRedLed, HIGH);   // right red on
  digitalWrite(rightYellowLed, LOW); // right yellow off
  digitalWrite(rightGreenLed, LOW);  // right green off
  delay(5000);                       // 5 seconds next step

  // Phase 2: Left Yellow, Right Red
  digitalWrite(leftGreenLed, LOW);   // left green off`
  digitalWrite(leftYellowLed, HIGH); // left yellow on
  digitalWrite(leftRedLed, LOW);     // left red off
  delay(2000);
  digitalWrite(leftYellowLed, LOW); // left yellow off

  // Phase 3: Left Red, Right Yellow
  digitalWrite(leftRedLed, HIGH);
  digitalWrite(rightRedLed, LOW);
  digitalWrite(rightYellowLed, HIGH);
  delay(1500);
  digitalWrite(rightYellowLed, LOW);

  // Phase 4: Left Red, Right Green
  digitalWrite(rightGreenLed, HIGH);
  delay(5000);

  // Phase 5: Left Red, Right Yellow
  digitalWrite(rightGreenLed, LOW);   // right green off`
  digitalWrite(rightYellowLed, HIGH); // right yellow on
  digitalWrite(rightRedLed, LOW);     // right red off
  delay(2000);
  digitalWrite(rightYellowLed, LOW);

  // Phase 6:  Left Yellow, Right Red
  digitalWrite(leftRedLed, LOW);
  digitalWrite(rightRedLed, HIGH);
  digitalWrite(leftYellowLed, HIGH);
  delay(1500);
};
