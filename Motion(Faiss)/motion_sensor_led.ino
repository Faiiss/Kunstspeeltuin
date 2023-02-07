const int MOTION_SENSOR_PIN = A0;   // Arduino pin connected to the OUTPUT pin of motion sensor
const int R_PIN           = 5;
const int G_PIN           = 6; 
const int B_PIN           = 9; // Arduino pin connected to LED's pin
int motionStateCurrent      = LOW; // current  state of motion sensor's pin
int motionStatePrevious     = LOW; // previous state of motion sensor's pin

#define FADESPEED 5     // make this higher to slow down

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(R_PIN, OUTPUT);          // set arduino pin to output mode
  pinMode(G_PIN, OUTPUT);          // set arduino pin to output mode
  pinMode(B_PIN, OUTPUT);          // set arduino pin to output mode
}

void loop() {
  motionStatePrevious = motionStateCurrent;             // store old state
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // read new state
  int r, g, b;

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
 
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(R_PIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(B_PIN, b);
    delay(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    analogWrite(G_PIN, g);
    delay(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    analogWrite(R_PIN, r);
    delay(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(B_PIN, b);
    delay(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(G_PIN, g);
    delay(FADESPEED);
  }
  delay(5000);
  }
  else
  if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
    analogWrite(R_PIN, LOW);  // turn off
    analogWrite(G_PIN, LOW);  // turn off 
    analogWrite(B_PIN, LOW);  // turn off
  }
}
