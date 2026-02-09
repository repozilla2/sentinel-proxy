# Sentinel: The Physics Firewall (IGS)

![Status](https://img.shields.io/badge/Status-TRL--4_Bench_Prototype-orange)
![SSC](https://img.shields.io/badge/SSC-v1.1_(Draft)-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Target](https://img.shields.io/badge/Target-Teensy_4.1_%7C_FeeTech_STS3215-0ea5e9)

> **“The AI can hallucinate all it wants. The physics will not comply.”**

## What this is
Sentinel is an open-source **hardware safety interposer** for embodied AI.

It sits **between an untrusted upstream controller** (LLM agent, ROS 2 planner, teleop, etc.) and an **actuator interface**, enforcing deterministic safety limits at the signal boundary.

Sentinel does *not* try to make AI “aligned.”  
It constrains the AI’s **physical authority**.

## What Sentinel delivers (the GTM “one spine”)
Sentinel is not just a board. The product is the **standard + proof system**:

- **SSC (Sentinel Safety Contract) v1.1 (draft):** defines units, semantics, modes, stop behavior, and required evidence fields  
  - **V_CAP:** actuator ticks/sec  
  - **A_CAP:** actuator ticks/sec²  
  - **Field Mode default:** `REWRITE` (clamp to caps + log), not nuisance-tripping  
  - **Safe-stop default:** `HOLD` (effort-limited + latched), with slip monitoring & class-dependent escalation (roadmap)
- **Conformance Harness:** repeatable tests anyone can run to verify enforcement behavior
- **Evidence Packs:** machine-readable logs + measured performance distributions (P50/P95/P99), with integrity tooling (hash chain + verifier) as a gated milestone

This repo is the **reference implementation** of that spine.

## Architecture (MITM safety boundary)
Sentinel acts as a strict “man-in-the-middle” on the actuator bus. It does not originate motion intent; it **observes → validates → rewrites/denies → forwards**.

```mermaid
graph TD
    A[Untrusted AI / ROS 2 / Teleop] -->|Actuator Commands| B[Sentinel Interposer]
    B -->|Policy-Compliant Commands| C[Actuator Bus / Servo]
    B -->|Enforcement Events| D[Host Logs / Evidence Pack]
    subgraph "Trust Boundary"
      B
    end
