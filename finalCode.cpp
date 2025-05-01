#include <Servo.h>

// Motor setup
#define M2_PWM 3
#define M2_DIR 8
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
  bigServo.attach(9);
  smallServo1.attach(10);
  smallServo2.attach(6);

  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Since pull-up is enabled, button is pressed when LOW
  if (buttonState == HIGH) {
    mainFunction();     
  } else {
    Serial.println("Waiting for button press...");
  }
}

void mainFunction() {
  for (pos = 0; pos <= 90; pos++) {
    bigServo.write(pos);
    delay(15);
  }

  for (pos = 0; pos <= 90; pos++) {
    smallServo1.write(pos);
    smallServo2.write(pos);
    delay(15);
  }

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  analogWrite(M2_PWM, 255); 
  analogWrite(M4_PWM, 255);
  delay(4000);

  analogWrite(M2_PWM, 0); 
  analogWrite(M4_PWM, 0);
  delay(4000);

  for (pos = 90; pos >= 0; pos--) {
    smallServo1.write(pos);
    smallServo2.write(pos);
    delay(15);
  }

  for (pos = 90; pos >= 0; pos--) {
    bigServo.write(pos);
    delay(15);
  }

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  analogWrite(M2_PWM, 255); 
  analogWrite(M4_PWM, 255);
  delay(4000);

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  analogWrite(M2_PWM, 255); 
  analogWrite(M4_PWM, 255);
  delay(4000);

  analogWrite(M2_PWM, 0); 
  analogWrite(M4_PWM, 0); 
  delay(4000);

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  delay(4000);

  for (pos = 0; pos <= 90; pos++) {
    bigServo.write(pos);
    delay(15);
  }

  for (pos = 0; pos <= 90; pos++) {
    smallServo1.write(pos);
    smallServo2.write(pos);
    delay(15);
  }

  for (pos = 90; pos >= 0; pos--) {
    smallServo1.write(pos);
    smallServo2.write(pos);
    delay(15);
  }

  for (pos = 90; pos >= 0; pos--) {
    bigServo.write(pos);
    delay(15);
  }
}
