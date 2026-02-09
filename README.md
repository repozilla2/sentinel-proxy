# Sentinel: The Physics Firewall for Embodied AI

![Status](https://img.shields.io/badge/Status-TRL--4%20Prototype-orange)
![Target](https://img.shields.io/badge/Target-Teensy%204.1%20%7C%20FeeTech%20STS-blue)
![Software%20License](https://img.shields.io/badge/Software%20License-Apache--2.0-blue)
![Hardware%20License](https://img.shields.io/badge/Hardware%20License-CERN--OHL--P--2.0-purple)

> **“The AI can hallucinate all it wants. The physics will not comply.”**

Sentinel is an open‑source **hardware safety interposer** for embodied AI — plus an **executable Safety Contract (SSC)** and **conformance tooling** that make safety claims **testable and reproducible**.

It sits between an **untrusted controller** (LLM agent, ROS 2 planner, custom stack) and the **actuator interface**, enforcing deterministic limits and producing machine‑readable evidence.

---

## What this repo is (and what it’s not)

### ✅ Sentinel is
- **A hardware interposer** (“physics firewall”) between upstream compute and actuator bus  
- **A safety contract (SSC)**: units, semantics, modes, stop behavior, and required evidence fields  
- **A conformance + evidence workflow**: tests + logs + distributions you can reproduce

### ❌ Sentinel is not
- Not “AI alignment” — it constrains *physical authority*, not intent  
- Not “software guardrails” — the enforcement runs on independent hardware  
- Not “robot certification” — it’s a safety layer + evidence engine that supports certification work

---

## Demo (TRL‑4): Safe-range clamp proof of concept

The current proof‑of‑concept demonstrates a simple, concrete safety guarantee:

- The servo moves freely within a configured safe range (example: **10° → 170°**)  
- When an out‑of‑range position is requested, **Sentinel clamps** it to the maximum safe limit  
- The enforcement event is logged for later review

📺 **Video:** https://www.youtube.com/embed/bjI_DN_1DXA

> **Simplified subtitle suggestion:**  
> *“Sentinel allows normal motion inside a safe range — and clamps any out‑of‑range command to the configured limit.”*

---

## Architecture

Sentinel proxies actuator commands, enforces SSC rules, and emits evidence artifacts.

```mermaid
graph TD
    A[Untrusted Controller<br/>(LLM / ROS 2 / Custom)] -->|Actuator Commands| B[Sentinel Safety Interposer]
    B -->|Validated / Rewritten Commands| C[Actuator Bus / Servo]
    B -->|Enforcement Events| D[Evidence Pack<br/>(Logs + Metrics)]
    subgraph "Trust Boundary"
    B
    end
    style B fill:#f96,stroke:#333,stroke-width:2px
