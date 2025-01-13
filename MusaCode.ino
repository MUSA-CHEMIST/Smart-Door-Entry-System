#include <Servo.h>

// Create a Servo object
Servo myServo;
int pir=5;

// Define constants for speed control
const int stopSpeed = 90;  // 90 stops the servo
const int fullSpeedCW = 0; // 0 is full speed clockwise
const int fullSpeedCCW = 180; // 180 is full speed counterclockwise

void setup() {
  // Attach the servo to pin 9
  myServo.attach(9);
  pinMode(pir, INPUT);
  
  Serial.begin(9600);
  Serial.println("360 Servo Motor Control Initialized");
  
  // Stop the servo initially
  myServo.write(stopSpeed);
}

void loop() {

  int pirState = digitalRead(pir); // Read the PIR sensor state

  if (pirState == HIGH) {             // If motion is detected
    Serial.println("Motion Detected!");
  Serial.println("Rotating Clockwise");
  myServo.write(fullSpeedCCW);
  delay(5000); // Rotate for 2 seconds

  // Stop
  Serial.println("Stopping");
  myServo.write(stopSpeed);
  delay(2000);

  // Rotate Counterclockwise
  Serial.println("Rotating Counterclockwise");
  myServo.write(fullSpeedCW);
  delay(5000); // Rotate for 2 seconds

  // Stop
  Serial.println("Stopping");
  myServo.write(stopSpeed);
  delay(2000);
 
}
}
