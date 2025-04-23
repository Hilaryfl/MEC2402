const int switchPin = 5;
const int outputPin = 6;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
}


void loop() {
  static boolean oldSwitchState = digitalRead(switchPin);
  boolean newSwitchState = digitalRead(switchPin);
  if (newSwitchState != oldSwitchState) {
    // Switch has changed state.  Remember the new state
    oldSwitchState = newSwitchState;
    digitalWrite(outputPin, HIGH);
    delay(100);  // Pulse length
    digitalWrite(outputPin, LOW);
  }
}
