# Sentinel — The Physics Firewall for Embodied AI

![Status](https://img.shields.io/badge/Status-v0.1.x%20(TRL--4%20bench)-orange)
![License](https://img.shields.io/badge/License-MIT-green)
![Target](https://img.shields.io/badge/Target-Teensy%204.1%20%7C%20FeeTech%20STS-blue)

> “The AI can hallucinate all it wants. The physics will not comply.”

Sentinel is an **open-source hardware safety interposer** for embodied AI — plus an **executable safety contract (SSC)** and **conformance/evidence tooling** that make safety behavior *testable and reproducible*.

It sits between an **untrusted upstream controller** (LLM agent, ROS2 planner, scripts, etc.) and an **actuator interface**, enforcing deterministic caps (starting with velocity/acceleration) and producing machine-readable evidence of enforcement.

---

## What Sentinel is (and is not)

### ✅ Sentinel is
- A **hardware interposer** on the actuator bus (trust boundary at the signal plane)
- A **policy enforcement point** (caps, mode behavior, safe-stop semantics)
- An **evidence engine** (logs + measured latency distributions, reproducible runs)

### ❌ Sentinel is not
- **Not “AI alignment”** (it does not interpret intent)
- **Not “robot certification”** (it helps generate evidence; it does not certify a robot)
- **Not a substitute** for mechanical safety design, workspace constraints, or application policies

See: `SAFETY.md` (recommended to add)

---

## Current status (v0.1.x)
- **TRL-4 (bench validated):** actuator-bus proxy + early enforcement demo artifacts
- Primary dev target: **Teensy 4.1 + FeeTech STS-series single-wire TTL**
- GTM direction: **standard-first adoption, evidence-first credibility**
  - publish spec → conformance harness → evidence packs → installs → partners

---

## Architecture (trust boundary)

```mermaid
graph TD
  A[Untrusted Controller<br/>LLM / ROS2 / Scripts] -->|Commands| B[Sentinel Interposer<br/>(Trust Boundary)]
  B -->|Allowed / Rewritten Commands| C[Actuator Bus<br/>(FeeTech STS)]
  B -->|Audit / Evidence Logs| D[Evidence Pack]
  style B fill:#ffcc99,stroke:#333,stroke-width:2px
