# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## ⚠️ Verification Invalidation Policy
**Critical:** This project is evidence-driven. Code changes invalidate previous safety evidence. Refer to these tags to know what must be re-verified:

* `[⚠️ RE-RUN: G2]`: Protocol parser changed. Re-run Fuzzing & MITM soak tests.
* `[⚠️ RE-RUN: G3]`: Policy logic changed. Re-run Conformance Suite.
* `[⚠️ RE-RUN: ALL]`: Core kernel or hardware change. Full system re-verification required.

---

## [Unreleased]

### Added
* `[⚠️ RE-RUN: ALL]` Initial public release of TRL-4 Firmware Kernel.
* Implemented "Rewrite/Clamp" enforcement strategy for FeeTech STS3215.
* Added Gate 0 (MCU Sanity) and Gate 1 (Plant Characterization) Python harness.
* Dual-license structure: Apache 2.0 (Software) + CERN-OHL-P-2.0 (Hardware).

### Security
* Established "Default Deny" command allowlist architecture.
