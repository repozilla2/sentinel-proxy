# v0.1 Latency Demonstration (Teensy 4.1)

This folder contains the raw test artifacts used to generate the "Hard Clamp" proof-of-concept video featured on our Manifund proposal.

## Contents
* **`firmware/`**: The C++ firmware running on the Teensy 4.1 (Sentinel Device).
* **`host/`**: The Python attack script running on the Host PC (Mac/Linux).

## Test Methodology
1. **Sentinel** is configured with a hard invariant: `velocity <= 100%` (simulated as Servo Angle 10-170 for visual proof).
2. **Attacker** injects a raw serial command outside this envelope (e.g., `200` or `-50`).
3. **Sentinel** intercepts the packet, parses the integer, checks the invariant, and clamps the output to the nearest safe limit (10 or 170) before driving the PWM signal.
4. **Latency** is defined as the time between `RX_COMPLETE` and `PWM_WRITE`.

## Hardware Verified
* Microcontroller: Teensy 4.1 (ARM Cortex-M7 @ 600MHz)
* Actuator: SG90 Micro Servo
* Communication: USB Serial (Virtual UART) @ 9600 baud (simulated bottleneck)
