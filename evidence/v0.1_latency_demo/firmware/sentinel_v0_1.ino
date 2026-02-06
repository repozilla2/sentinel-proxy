/*
 * SENTINEL v0.1 - PROOF OF CONCEPT
 * Target: Teensy 4.1
 * Actuator: SG90 Servo (Pin 2)
 * Invariant: [10, 170] degrees safety envelope
 */

#include <Servo.h>

Servo myServo;
const int servoPin = 2; 

// Buffer for incoming packets
String inputString = ""; 
boolean stringComplete = false; 

// --- SAFETY INVARIANTS ---
const int SAFE_MIN = 10;
const int SAFE_MAX = 170;

void setup() {
  myServo.attach(servoPin);
  
  // FAIL-SAFE STATE: Initialize to center (Safe)
  myServo.write(90); 
  
  // Initialize Serial (USB Virtual UART)
  Serial.begin(9600); 
  while (!Serial) { ; } // Wait for host connection
  
  Serial.println("SENTINEL v0.1 ONLINE. INVARIANTS ACTIVE.");
}

void loop() {
  // --- KERNEL LOOP ---
  if (stringComplete) {
    // 1. PARSE (Decode the command)
    int requested_angle = inputString.toInt(); 
    int final_angle = requested_angle;
    
    // 2. ENFORCE (The "Physics Firewall")
    // This logic runs independently of the high-level intent
    bool intervention = false;
    
    if (requested_angle < SAFE_MIN) {
      final_angle = SAFE_MIN;
      intervention = true;
    }
    else if (requested_angle > SAFE_MAX) {
      final_angle = SAFE_MAX;
      intervention = true;
    }
    
    // 3. ACTUATE (Drive the physics)
    myServo.write(final_angle);
    
    // 4. AUDIT (Log the action)
    Serial.print("Moving to: ");
    Serial.println(final_angle);
    
    if (intervention) {
      // In a real version, this logs to a separate secure audit channel
      // Serial.println("[ALERT] INVARIANT VIOLATION CLAMPED");
    }
    
    // Reset Buffer
    inputString = "";
    stringComplete = false;
  }
}

// Interrupt-style Serial Event Handler
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}
