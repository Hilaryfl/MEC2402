#include <Servo.h>

// Motor setup
#define M2_PWM 3
#define M2_DIR 8
#define M4_PWM 11
#define M4_DIR 13

// Switch setup
const int switchPin = 22;  // switch input
const int ledPin = 23;     // LED output

// Servo setup
Servo bigServo;
Servo smallServo1;
Servo smallServo2;

int pos = 0;
int duty = 0;    // variable to store duty cycle which controls the motor's effective voltage (range 0-255)


void setup() {
  pinMode(switchPin, INPUT);   // Read switch state
  pinMode(ledPin, OUTPUT);     // Control LED

  bigServo.attach(9);
  smallServo1.attach(10);
  smallServo2.attach(11);

  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  Serial.begin(9600);          // Start the serial monitor
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(ledPin, HIGH);              // Turn LED ON
    mainFunction();     // CHANGE TO FINAL CODE
  } else {
    digitalWrite(ledPin, LOW);               // Turn LED OFF
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
  delay(10);


  digitalWrite(M2_DIR, LOW); 
  digitalWrite(M4_DIR, LOW); 
  delay(10);

  for (pos = 90; pos >= 0; pos--) {
    smallServo1.write(pos);
    smallServo2.write(pos);
    delay(15);
  }

  for (pos = 90; pos >= 0; pos--) {
    bigServo.write(pos);
    delay(15);
  }

// ROTATES 
  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  delay(5);

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  delay(10);

// stop to allow seesaw to tilt
  analogWrite(M2_PWM, 0); // Stop motor M2
  analogWrite(M4_PWM, 0); // Stop motor M4

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  delay(10);

  digitalWrite(M2_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  delay(5);
  
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
