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
