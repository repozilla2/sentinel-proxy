# Sentinel: The Physics Firewall (IGS)

![Status](https://img.shields.io/badge/Status-v0.1.5_Frozen_Master-orange) ![License](https://img.shields.io/badge/License-MIT-green) ![Target](https://img.shields.io/badge/Target-Teensy_4.1_|_Feetech_STS-blue)

> **“The AI can hallucinate all it wants. The physics will not comply.”**

## What this is
Sentinel is an open-source **Hardware Root-of-Trust** for embodied AI. 

It is a physical interposer that sits between an upstream controller (including LLM-based agents or ROS 2 planners) and the physical actuators. It enforces non-negotiable safety invariants in real-time, independent of the AI's logic state.

Sentinel does not try to make AI smarter. **It makes unsafe physical commands impossible.**

## Architecture
Sentinel acts as a strict "Man-in-the-Middle" on the actuator bus. It does not originate commands; it observes, validates, and conditionally clamps commands that violate safety contracts.

```mermaid
graph TD
    A[Untrusted AI / ROS 2] -->|Serial CMD| B(Sentinel Hardware)
    B -->|Verified CMD| C[Actuator / Feetech STS]
    B --x|Clamped CMD| D[Audit Log]
    subgraph "Trust Boundary"
    B
    end
    style B fill:#f96,stroke:#333,stroke-width:2px

## Capabilities (v0.1)
* **Bus Interception:** Transparently proxies the Feetech STS / TTL Serial protocol.
* **Invariant Enforcement:** Detects violations (e.g., Velocity > 500 RPM) in `<10µs`.
* **Active Clamping:** Modifies unsafe packets in-flight before they reach the motor registers.
* **Forensic Logging:** Emits a signed log of the intervention for post-incident auditing.

## What it is NOT
* ❌ **Not AI Alignment:** We do not align the model's intent; we constrain its physical authority.
* ❌ **Not Software Guardrails:** This runs on independent, bare-metal hardware, not inside the OS/Kernel.
* ❌ **Not a Certification Claim:** Sentinel is a tool to *enable* certification, not a replacement for ISO 10218.

## Verification Methodology (The "Golden Path")
Sentinel follows a **"Trust but Verify"** engineering philosophy. All releases are validated against the **IGS Torture Matrix**:
1.  **Latency Determinism:** End-to-end signal propagation must remain `<100µs` under 100% bus load.
2.  **Adversarial Fuzzing:** The system is tested against an "Adversarial Agent" specifically trained to generate malformed and dangerous control packets.
3.  **Fail-Safe Defaults:** In the event of power loss or watchdog timeout, the bus tri-states to a safe (Hi-Z) halt.

## Documentation
* [Invariant Contract (v0.1)](docs/01-invariant-contract-v0.1.md)
* [Test Matrix & Evidence](docs/02-test-matrix-v0.1.md)
* [Evidence Pack](docs/03-evidence-pack-v0.1.md)

## Repository Layout
```text
sentinel/
├─ firmware/      # Teensy 4.1 enforcement logic (C++)
├─ tools/         # Adversarial test harness (Python)
├─ hardware/      # PCB Schematics (KiCad)
└─ docs/          # Safety Contracts and Evidence Logs
