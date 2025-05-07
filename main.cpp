//ONLY USED TO TEST IF WHEELS WORK 
// <WM1 PIN DEFINITIONS>
#define M1_PWM 6
#define M1_DIR 7

#define M4_PWM 11
#define M4_DIR 13

// optional??
//#define RELAY1 2 
//#define RELAY2 4
//#define SERVO1 9
//#define SERVO2 10

// <GLOBAL DECLARATIONS>
int duty = 0;    // variable to store duty cycle which controls the motor's effective voltage (range 0-255)


void setup() {
  // put your setup code here, to run once:

  /* <CONFIGURE ALL WM1 PINS AS OUTPUTS>
    while not all pins are used in this example it is good practice to 
    configure them as outputs so that they are not left floating */
  // Used Pins    
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);
  //pinMode(RELAY1, OUTPUT);
  //pinMode(RELAY2, OUTPUT);
  //pinMode(SERVO1, OUTPUT);
  //pinMode(SERVO2, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:

  // DIR pin dictates motor's dirrection
  // PWM pin dictates the motor's voltage, which loosely controls speed

  // <SET M3 DIRECTION TO FORWARDS assuming backwheel drive>
  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  delay(10);


  digitalWrite(M1_DIR, LOW); 
  digitalWrite(M4_DIR, LOW); 
  delay(10);

// ROTATES 
  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  delay(5);

  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  delay(10);

// stop to allow seesaw to tilt
  analogWrite(M1_PWM, 0); // Stop motor M2
  analogWrite(M4_PWM, 0); // Stop motor M4

  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M4_DIR, HIGH); 
  delay(10);

  digitalWrite(M1_DIR, HIGH); 
  digitalWrite(M4_DIR, LOW); 
  delay(5);


}

