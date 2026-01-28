# sentinel-proxy
Sentinel: The Physics Firewall
Status: v1.5 (Frozen Master)
Hardware Target: Teensy 4.1 + STS3215 Servo
License: MIT
> "The AI can hallucinate all it wants. The physics will not comply."
> 
1. Project Objective
Sentinel is a hardware-based "Physics Firewall" designed to interpose between an untrusted AI "Brain" (LLM/Agent) and a physical actuator. It enforces non-negotiable safety invariants (velocity limits, torque limits, keep-out zones) at the firmware level.
Unlike software guardrails, which can be bypassed by jailbreaks or hallucinations, Sentinel is immutable. It listens to the serial bus, intercepts high-risk commands, and clamps them to safe values before they reach the motor.
2. Architecture
The system operates as a Man-in-the-Middle (MITM) proxy on the serial bus.
graph LR
    A[Untrusted AI] -- USB Serial --> B(Sentinel Interposer);
    B -- 1-Wire UART --> C[High-Torque Actuator];
    
    subgraph "The Danger Zone"
    A
    end
    
    subgraph "The Trusted Zone"
    B
    end
    
    subgraph "The Physical Plant"
    C
    end

 * Attacker: Raspberry Pi 4 (Python Script) simulating a rogue/hallucinating AI.
 * Sentinel: Teensy 4.1 (C++ Firmware) enforcing the velocity clamp.
 * Plant: Feetech STS3215 (12V) High-Torque Servo.
3. Hardware Bill of Materials (BOM)
| Component | Role | Spec |
|---|---|---|
| Teensy 4.1 | The Governor | 600MHz, 3.3V Logic |
| Level Shifter | Safety Valve | 3.3V \leftrightarrow 5V Logic Conversion |
| Feetech STS3215 | The Muscle | 12V, 30kg.cm Torque, 1-Wire TTL |
| Power Supply | The Juice | 12V DC, 5A+ |
Critical Wiring (1-Wire Half-Duplex)
 * Teensy Pin 1 (TX1): Wired to Level Shifter (Low Side).
 * Teensy Pin 0 (RX1): DISCONNECTED. (Teensy handles Half-Duplex internally).
 * Common Ground: Teensy + Level Shifter + PSU + Servo must share GND.
4. Software Stack
Firmware (/firmware)
 * Version: Iridium v1.5
 * Logic:
   * Listens for WRITE commands to Register 0x2A (Target Position).
   * Parses the Payload (Position, Time, Speed).
   * Checks if Speed > MAX_SPEED (500).
   * Violation: If unsafe, modifies the Speed byte to 500, re-calculates Checksum, flashes Red LED, and logs forensic event.
   * Pass: If safe, forwards packet immediately.
Attacker Script (/attacker)
 * Language: Python 3
 * Logic:
   * Generates valid STS Protocol packets.
   * Sends "Safe" moves (Speed 200).
   * Sends "Attack" moves (Speed 3000) to test the clamp.
5. Usage / Reproduction
Step 1: Flash the Sentinel
 * Open sentinel_firmware.ino in Arduino IDE.
 * Select Board: Teensy 4.1.
 * Upload.
 * Open Serial Monitor. You should see: [SENTINEL] ONLINE.
Step 2: Run the Attack
# On the Raspberry Pi / Host
python3 attack.py

Step 3: Verify Safety
 * Green Light: Servo moves smoothly.
 * Red Light: Servo attempts to move fast, but is audibly and visibly slowed down by the Sentinel.
6. Safety Protocol ("The Kill Chain")
 * Hard Mount: Servo must be clamped to the table. No handheld tests.
 * E-Stop: Power strip switch must be within reach at all times.
 * Zone of Exclusion: Keep hands 12" away from the arm during 12V operation.
