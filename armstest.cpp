#include <Servo.h>

// Motor setup
#define M1_PWM 6
#define M1_DIR 7
#define M4_PWM 11
#define M4_DIR 13

// Button setup
const int buttonPin = 38;  // button input (now using internal pull-up)

// Servo setup
Servo bigServo;
Servo smallServo1;
Servo smallServo2;

int pos = 0;
int duty = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  bigServo.attach(10);
  smallServo1.attach(9);
  smallServo2.attach(3); //left arm

  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Since pull-up is enabled, button is pressed when LOW
  if (buttonState == HIGH) {
    Serial.println("Run started");
    mainFunction();     
  } else {
    Serial.println("Waiting for button press...");
  }
}

void mainFunction() {

  bigServo.write(180);              // tell servos to go to position in variable 'pos'

  smallServo1.write(90);
  smallServo2.write(90);
  
}
