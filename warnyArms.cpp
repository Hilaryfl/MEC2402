#include <Servo.h>

// Servo setup
Servo bigServo;
Servo smallServo1;
Servo smallServo2;

int pos = 0;

void setup() {
  bigServo.attach(9);
  smallServo1.attach(10);
  smallServo2.attach(11);
}

void arms() {
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

void call() {
  arms();      
  delay(90);
  arms();      
}

void loop() {
  call();         // call the function once
  while (true);   // stop looping (remove this if you want it to repeat forever)
}
