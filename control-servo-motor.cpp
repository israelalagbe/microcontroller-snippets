#include <Arduino.h>
#include <Servo.h> 

Servo myServo;

const int startingAngle = 0;

void setup() {
  myServo.attach(9); 
  myServo.write(startingAngle);   // Start at angle 0 degrees
  delay(1000);         // Wait 1 second for motor to reach initial angle
}

void loop() {
  // start at 0 degrees and move slowly to 90 degrees
  for (int angle = 0; angle <= 90; angle++) {
    myServo.write(angle);
    delay(20);            // Wait 15ms for servo to reach position
  }

  delay(1000);  // 1 second

  for (int angle = 90; angle <= 181; angle++) {
    myServo.write(angle); 
    delay(20);
  }
  
  delay(1000);
  myServo.write(startingAngle);  //go back to starting angle
  delay(1000); // 1 second
}