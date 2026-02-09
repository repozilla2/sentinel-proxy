# Sentinel v0.1.5-frozen — Evidence Manifest

This directory contains the authoritative evidence for the
`v0.1.5-frozen` release of Sentinel.

---

## Scope of Validation

- **TRL:** 4 (bench validated)
- **Hardware Platform:** Teensy 4.1
- **Actuator:** SG90 micro servo (single-joint, PWM-driven)
- **Control Class:** Position command containment
- **Safety Mode:** Rewrite/Clamp + Audit Log
- **Test Environment:** Bench, single-axis, no gravity load

This evidence demonstrates **deterministic containment at the actuator interface**.
It does **not** claim industrial performance, force limits, or human-safe operation.

---

## Safety Guarantee Demonstrated

The following guarantee is supported by this evidence:

- **Out-of-range actuator commands are deterministically clamped**
  before they reach the actuator.
- **In-range commands pass through unmodified.**
- Enforcement behavior is consistent and observable.
- Enforcement events are logged for post-test review.

No velocity, torque, current, or multi-axis claims are made.

---

## Evidence Contents

- Firmware build used for testing
- Host-side command/attack scripts
- Raw execution logs
- Video capture of bench test behavior
- Configuration used during testing

---

## Integrity Statement

This evidence is valid **only** for the code state tagged as
`v0.1.5-frozen`.

Any change to:
- firmware logic
- parser behavior
- enforcement semantics
- timing behavior
- actuator interface code

**invalidates this evidence** and requires re-running Gate 0–3.

---

## Linked Artifacts

- **Firmware:**  
  `evidence/v0.1_latency_demo/firmware/sentinel_v0_1.ino`

- **Host script:**  
  `evidence/v0.1_latency_demo/host/sentinel_attack.py`

- **Demo video:**  
  https://www.youtube.com/watch?v=bjI_DN_1DXA

---

## Verification Gates Covered

- **Gate 0 — MCU Sanity**  
  Continuous operation and deterministic control loop behavior.

- **Gate 1 — Actuator Characterization (bench)**  
  Basic range limits and response consistency for SG90 servo.

- **Gate 3 — TRL-4 Containment**  
  Default-deny + rewrite/clamp behavior verified under adversarial input.

---

## Claims Explicitly Not Covered

This evidence does **not** support claims about:

- Velocity or acceleration caps
- Torque or force limiting
- Current-based control
- Multi-axis coordination
- Gravity-loaded joints
- Independent witness validation
- Fieldable interlocks or tamper resistance
- TRL-5 or TRL-6 readiness

Those claims are **gate-locked** pending future evidence.

---

## Summary

This frozen evidence establishes a **minimal but critical fact**:

> Sentinel can act as a deterministic actuator boundary that prevents
> unsafe commands from reaching a physical actuator.

This is the foundation upon which higher-TRL safety claims will be built.
