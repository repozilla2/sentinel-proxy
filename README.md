# Sentinel — The Physics Firewall for Embodied AI

![Status](https://img.shields.io/badge/Status-TRL--4%20Bench%20Validated-orange)
![Release](https://img.shields.io/badge/Release-v0.1.5-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green)
![Target](https://img.shields.io/badge/Target-Teensy%204.1%20%7C%20FeeTech%20STS-blue)

> **“The AI can hallucinate all it wants. The physics will not comply.”**

Sentinel is an open-source **hardware safety interposer** + **executable safety contract (SSC)** for embodied AI.
It sits between an untrusted controller (LLM agents, ROS 2 planners, custom stacks) and the actuator interface to enforce deterministic limits and generate reproducible safety evidence.

## What Sentinel is (and isn’t)

**It is:**
- A physical interposer on the actuator interface (observes → validates → rewrites/clamps → forwards)
- A spec-driven safety layer (SSC) with conformance tests (harness)
- An evidence engine (machine-readable logs; latency reported as distributions)

**It is NOT:**
- ❌ AI alignment
- ❌ “robot certification”
- ❌ a guarantee of “100% human safety” by itself

## Architecture (GitHub-friendly Mermaid + fallback)

```mermaid
flowchart LR
  U[Untrusted Controller<br/>(LLM / ROS / Policy Stack)] -->|commands| S[Sentinel Interposer]
  S -->|validated / rewritten| A[Actuator Interface]
  S -->|enforcement events| E[Evidence Pack Log]
