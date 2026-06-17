#include <Servo.h> // Include Servo Library

// Define pins for LDRs and Servo
#define ldrEast A1
#define ldrWest A0
Servo trackerServo;

// Variables
int pos = 90; // Initial position (middle)
int tolerance = 0; // Sensitivity tolerance

void setup() {
  trackerServo.attach(12); // Servo attached to pin 12
  trackerServo.write(pos);
  delay(50); // Allow time for movement
}

void loop() {
  int valEast = analogRead(ldrEast); // Read East LDR
  int valWest = analogRead(ldrWest); // Read West LDR

  // Calculate difference
  if ((abs(valEast - valWest) <= tolerance)) {
    // If difference is within tolerance, do nothing
  } else {
    if (valEast > valWest) {
      pos = pos + 1; // Move toward East
    } else {
      pos = pos - 1; // Move toward West
    }
  }

  // Limit servo range
  if (pos > 150) pos = 150;
  if (pos < 30) pos = 30;

  trackerServo.write(pos); // Write new position
  delay(50); // Speed control
}
