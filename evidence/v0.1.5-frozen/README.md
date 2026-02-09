# Sentinel v0.1.5-frozen — Evidence Manifest

This directory contains the authoritative evidence for the
`v0.1.5-frozen` release of Sentinel.

## Scope
- TRL: 4 (bench validated)
- Actuator class: FeeTech STS3215 (single-joint)
- Enforcement: Position clamp (safe-range containment)
- Safety mode: Rewrite/Clamp + Audit Log

## Evidence Contents
- Firmware build used for testing
- Host attack scripts
- Raw logs
- Derived metrics (latency distributions)
- Video reference

## Integrity Statement
This evidence is valid **only** for the code state tagged as
`v0.1.5-frozen`.

Any change to firmware, parser logic, or enforcement behavior
invalidates this evidence and requires re-running Gate 0–3.

## Linked Artifacts
- Firmware: `evidence/v0.1_latency_demo/firmware/sentinel_v0_1.ino`
- Host script: `evidence/v0.1_latency_demo/host/sentinel_attack.py`
- Video: https://www.youtube.com/watch?v=bjI_DN_1DXA

## Verification Gates Covered
- Gate 0 — MCU sanity
- Gate 1 — Actuator characterization (bench)
- Gate 3 — TRL-4 containment (default deny + rewrite)

## Claims Supported
- Out-of-range actuator commands are deterministically clamped
- Enforcement occurs before command reaches actuator registers
- Normal in-range motion is unaffected

No TRL-5 or TRL-6 claims are made or implied.
