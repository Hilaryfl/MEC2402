const int switchPin = 22;  // Toggle switch input
const int ledPin = 23;     // LED output

void setup() {
  pinMode(switchPin, INPUT);   // Read switch state
  pinMode(ledPin, OUTPUT);     // Control LED

  Serial.begin(9600);          // Start the serial monitor
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(ledPin, HIGH);              // Turn LED ON
    Serial.println("I can read pin 22");     // Print message
  } else {
    digitalWrite(ledPin, LOW);               // Turn LED OFF
  }
}
