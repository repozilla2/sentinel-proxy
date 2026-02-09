// SPDX-License-Identifier: Apache-2.0
/*
 * Sentinel Firmware v0.1
 * Target: Teensy 4.1
 * Interface: USB Serial (Host) <-> UART1 (Actuator)
 * Invariant: MAX_VELOCITY_LIMIT
 */

#include <Arduino.h>

// --- Safety Invariants ---
const int MAX_VELOCITY_RPM = 500;
const int EMERGENCY_STOP_PIN = 2;

// --- Feetech STS Protocol Offsets ---
const uint8_t STS_INST_WRITE = 0x03;
const uint8_t STS_REG_GOAL_SPEED = 0x2E;

void setup() {
  // Host Interface (ROS 2)
  Serial.begin(1000000);
  
  // Actuator Interface (Feetech STS)
  Serial1.begin(1000000);
  
  // Hardware Interlock
  pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Hardware E-Stop Check (Physical Override)
  if (digitalRead(EMERGENCY_STOP_PIN) == LOW) {
    Serial1.end(); // Hard sever of actuator bus
    digitalWrite(LED_BUILTIN, HIGH); // Red alert
    return;
  }

  // Pass-through Logic with Inspection
  if (Serial.available()) {
    uint8_t byte = Serial.read();
    
    // TODO: Full packet parsing logic implemented here
    // For v0.1 demo: Blind pass-through with velocity check placeholder
    
    // Invariant Enforcement Logic would go here:
    // if (packet.instruction == STS_INST_WRITE && packet.velocity > MAX_VELOCITY_RPM) {
    //     packet.velocity = MAX_VELOCITY_RPM; // CLAMP
    // }
    
    Serial1.write(byte);
  }

  // Upstream Telemetry (Motor -> Host)
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
